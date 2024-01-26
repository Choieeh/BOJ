#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, L, R;

bool bfs(vector<vector<int> > &map, vector<vector<bool> > &visited, int x, int y){
    visited[x][y] = true;
    int sum = 0;
    vector<pair<int, int> > uni;

    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    uni.push_back(make_pair(x, y));

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        int cur_x = cur.first;
        int cur_y = cur.second;
        sum += map[cur_x][cur_y];

        for(int i=0; i<4; i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if(nx >=0 && nx < N && ny >= 0 && ny < N && visited[nx][ny] == false){
                if(abs(map[cur_x][cur_y] - map[nx][ny]) >= L && abs(map[cur_x][cur_y] - map[nx][ny]) <= R){
                    
                    visited[nx][ny] = true;
                    uni.push_back(make_pair(nx, ny));
                    q.push(make_pair(nx, ny));
                }
            }
        }

    }

    if(uni.size() == 1) return false;

    for(int i=0; i<uni.size(); i++){
        pair<int, int> temp = uni[i];
        map[temp.first][temp.second] = sum / uni.size();
    }
    return true;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;

    vector<vector<int> > map(N, vector<int>(N));
    vector<vector<bool> > visited(N, vector<bool>(N));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }

    int count = 0;
    while(true){
        bool flag = false;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i][j] == 0){
                    bool result;
                    result = bfs(map, visited, i, j);
                    flag=flag ? flag : result;
                }
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                visited[i][j] = false;
            }
        }
        if( flag == false){
            cout << count << "\n";
            break;
        }
        count ++;
    }

}