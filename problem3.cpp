#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;
    vector<int> arr;

    for (int k = 0; k < q; k++) {
        string cmd;
        cin >> cmd;

        if (cmd == "insert") {
            int x;
            cin >> x;
            arr.push_back(x);
        } 
        else if (cmd == "get") {
            string next;
            cin >> next; // expecting "max"
            if (arr.empty()) cout << "EMPTY\n";
            else {
                int mx = arr[0];
                for (int v : arr) mx = max(mx, v);
                cout << mx << "\n";
            }
        } 
        else if (cmd == "extract") {
            string next;
            cin >> next; // expecting "max"
            if (arr.empty()) cout << "EMPTY\n";
            else {
                int idx = 0;
                for (int i = 1; i < (int)arr.size(); i++)
                    if (arr[i] > arr[idx]) idx = i;
                cout << arr[idx] << "\n";
                arr.erase(arr.begin() + idx);
            }
        } 
        else if (cmd == "size") {
            cout << arr.size() << "\n";
        }
    }

    return 0;
}
