#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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
        else if (cmd == "get" || cmd == "getmax" || cmd == "get_max") {
            string maybe;
            if (cmd == "get") cin >> maybe; // skip "max" if two-word form
            if (arr.empty()) cout << "EMPTY\n";
            else {
                int mx = arr[0];
                for (int v : arr)
                    if (v > mx) mx = v;
                cout << mx << "\n";
            }
        } 
        else if (cmd == "extract" || cmd == "extractmax" || cmd == "extract_max") {
            string maybe;
            if (cmd == "extract") cin >> maybe; 
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
