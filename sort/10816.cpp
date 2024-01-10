#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int k;
        int c;
        cin >> k;
        cout << distance(lower_bound(a.begin(), a.end(), k), upper_bound(a.begin(), a.end(), k)) << ' ';
    }
}
