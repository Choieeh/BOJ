#include <iostream>
#include <vector>

int main() {
  int n, k;
  int count = 0;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for(int i=0; i<n; i++) {
    std::cin >> a[i];
  }

  for(int i=n-1; i>=0; i--){
    while(a[i] <= k) {
      count++;
      k -= a[i];
    }
  }

  std::cout << count << std::endl;
}