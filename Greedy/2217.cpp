#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> rope(n);
  for(int i =0; i<n; i++){
    cin >> rope[i];
  }
  int answer = 0;
  
  sort(rope.begin(), rope.end());

  for(int i=0; i<n; i++){
    int weight = rope[i] * (n-i);

    if(weight > answer)
      answer = weight;
  }
  cout << answer << endl;
}