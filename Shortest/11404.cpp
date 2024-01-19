#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<vector<int> > ans(n+1, vector<int>(n+1, 10000000));

    for(int i=1; i<n+1; i++){
        ans[i][i] = 0;
    }

    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        ans[a][b] = min(ans[a][b], c);
    }   


    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            for(int k=1; k<n+1; k++){
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if( ans[i][j] == 10000000){
                cout << 0 << ' ';
            }
            else cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}