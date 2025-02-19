/* Problem- https://cses.fi/problemset/task/1070 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1" << endl;
    } else if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
    } else {
        vector<int> even, odd;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0) {
                even.push_back(i);
            } else {
                odd.push_back(i);
            }
        }

        for (int i = 0; i < even.size(); ++i) {
            cout << even[i] << " ";
        }
        for (int i = 0; i < odd.size(); ++i) {
            cout << odd[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
