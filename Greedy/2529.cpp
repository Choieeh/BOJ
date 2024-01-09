#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int count1=9;
    int count2=0;

    cin >> n;

    vector<char> a(n);
    vector<int> ans1(n+1);
    vector<int> ans2(n+1);

    stack<char> bu;

    for(int i=0; i<n; i++){
        char k;
        cin >> k;
        a[i] = k;
    }

    // 가장 큰 수 
    int i;
    for(i=0; i<n; i++){
        if(a[i] == '>'){
            int k = i;
            ans1[k] = count1--;
            while(!bu.empty()){
                ans1[--k] = count1--;
                bu.pop();
            }
            // 마지막 수 채워주기
            if(i == (n-1)){
                ans1[n] = count1;
            }
        }
        else{
            bu.push(a[i]);
        }
    }
    // stack에 남아있는 애들 처리
    while(!bu.empty()){
        ans1[i--] = count1--;
        bu.pop();
    }
    // 마지막 하나 처리
    ans1[i--] = count1--;

    // 가장 작은 수
    for(i=0; i<n; i++){
        if(a[i] == '<'){
            int k = i;
            ans2[k] = count2++;
            while(!bu.empty()){
                ans2[--k] = count2++;
                bu.pop();
            }
            //마지막 수 채우기
            if(i == (n-1)){
                ans2[n] = count2;
            }
        }
        else{
            bu.push(a[i]);
        }
    }
    // stack에 남아있는 애들 처리
    while(!bu.empty()){
        ans2[i--] = count2++;
        bu.pop();
    }
    // 마지막 수 처리
    ans2[i--] = count2++;

    for (int i = 0; i<ans1.size(); i++){
        cout << ans1[i];
    }
    cout << '\n';
    for (int i = 0; i<ans2.size(); i++){
        cout << ans2[i];
    }
}