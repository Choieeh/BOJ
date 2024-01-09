#include <iostream>

int main() {
  std::string s;
  std::cin >> s;

  int onetozero = 0;
  int zerotoone = 0;

  if(s[0] == '0')
// 0집단 개수
    onetozero++;
  else
// 1집단 개수
    zerotoone++;

  for(int i = 1; i < s.size(); i++) {
    if(s[i-1] != s[i]){
      if(s[i-1] == '0'){
        zerotoone++;
      }
      else{
        onetozero++;
      }
    }
  }
  
  std::cout << std::min(zerotoone, onetozero);
}