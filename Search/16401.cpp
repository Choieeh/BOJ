#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<int> g(m);

    for(int i=0; i<m; i++){
        cin >> g[i];
    }

    sort(g.begin(), g.end());

    int low = 1;
    int high = g[m-1];
    int ans = 0;

    while(low <= high){
        int cnt = 0;
        int mid = (low+high) / 2;

        for(int i=0; i<m; i++){
            cnt += (g[i] / mid);
        }

        if(cnt == n && mid > ans){
            ans = mid;
        }

        if(cnt < n){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout << ans << "\n";
}