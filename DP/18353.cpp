#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<int> ans(n, 1);
    for(int i=1; i<n ; i++){
        for(int j=0; j<i; j++){
            if(a[j] > a[i]){
                ans[i] = (ans[i] > (ans[j] + 1)) ? ans[i] : (ans[j] + 1);
            }
        }
    }
    cout << n - *max_element(ans.begin(), ans.end()) << '\n';
}