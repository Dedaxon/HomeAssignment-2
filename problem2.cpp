#include <iostream>
#include <vector>
using namespace std;

void heapDown(vector<int>& A, int n, int i) {
    while (true) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < n && A[l] < A[smallest])
            smallest = l;
        if (r < n && A[r] < A[smallest])
            smallest = r;

        if (smallest != i) {
            swap(A[i], A[smallest]);
            i = smallest;
        } else break;
    }
}

void buildMinHeap(vector<int>& A, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapDown(A, n, i);
}

int extractMin(vector<int>& A, int& n) {
    if (n == 0) return -1; 
    int minVal = A[0];
    A[0] = A[n - 1];
    n--;
    heapDown(A, n, 0);
    return minVal;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    buildMinHeap(A, n);

    vector<int> sorted;
    int size = n;
    while (size > 0) {
        sorted.push_back(extractMin(A, size));
    }

    for (int i = 0; i < (int)sorted.size(); i++)
        cout << sorted[i] << (i + 1 == (int)sorted.size() ? '\n' : ' ');
}
