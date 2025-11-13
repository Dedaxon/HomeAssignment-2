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
        else if (l < n && A[l] == A[smallest] && smallest == i)
            smallest = l; 

        if (r < n && A[r] < A[smallest])
            smallest = r;

        if (smallest != i) {
            swap(A[i], A[smallest]);
            i = smallest;
        } else break;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    int i;
    cin >> i;

    heapDown(A, n, i);

    for (int j = 0; j < n; j++)
        cout << A[j] << (j == n - 1 ? '\n' : ' ');
}
