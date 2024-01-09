#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Times{
  int start;
  int end;
};

bool compare(Times a, Times b){
  if(a.end == b.end){
    return a.start < b.start;
  }
  return a.end < b.end;
}

int main() {
  int n, count=0;
  cin >> n;
  vector <Times> a(n);

  int current_time=0;
  
  for(int i=0; i<n; i++) {
    cin >> a[i].start >> a[i].end;
  }

  sort(a.begin(), a.end(), compare);
  
  for(int i=0; i<n; i++){
    if(a[i].start >= current_time){
      current_time = a[i].end;
      count++;
    }
  }
  

  cout << count << endl;
}