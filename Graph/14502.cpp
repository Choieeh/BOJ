#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<Point> virus;
int n, m, best=0;

void bfs(vector<vector<int> >map){
    queue<Point> q;
    for(const Point v : virus){
        q.push(v);
    }
    while(!q.empty()){
        Point cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(0<=nx && nx<n && 0<=ny && ny<m && map[nx][ny] == 0){
                map[nx][ny] = 2;
                Point new_v;
                new_v.x = nx;
                new_v.y = ny;
                q.push(new_v); 
            }
        }

    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += count(map[i].begin(), map[i].end(), 0);
    }

    if(ans > best) best = ans;
}

void make_wall(int cnt, vector<vector<int> >map){
    if(cnt == 3){
        bfs(map);
        return;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                make_wall(cnt+1, map);
                map[i][j] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> m;

    vector<vector<int> > map(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int k;
            cin >> k;
            map[i][j] = k;
            if(k == 2){
                Point new_virus;
                new_virus.x = i;
                new_virus.y = j;
                virus.push_back(new_virus);
            }
        }
    }
    make_wall(0, map);
    cout << best << '\n';
}