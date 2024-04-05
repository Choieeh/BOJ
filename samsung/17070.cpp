#include <iostream>
#include <vector>

using namespace std;

int house[17][17];
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};
int ans = 0;
int n;

void dfs(int x, int y, int pos){
    if(x == n && y == n){
        ans+=1;
        return;
    }
    for(int i=0; i<3; i++){
        if((pos==0 && i == 1) || (pos==1 && i == 0)) continue;
        
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x <= n && next_y <= n && house[next_x][next_y] == 0){
            if(i==2 && (house[x+1][y] == 1 || house[x][y+1] == 1)) continue;
            dfs(next_x, next_y, i);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cin >> house[i][j];
        }
    }
    dfs(1, 2, 0);

    cout << ans << endl;
}