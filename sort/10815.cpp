#include <algorithm>
#include <iostream>
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
    cin >> k;
    cout << binary_search(a.begin(), a.end(), k) << "\n";
  }
}