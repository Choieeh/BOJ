#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool *visited;

void dfs(vector<vector<int> > &line, int v){
    visited[v] = true;
    cout << v << ' ';

    for(int i =0; i<line[v].size(); i++){
        int next = line[v][i];
        if(visited[next] == false){
            dfs(line, next);
        }
    }
}

void bfs(vector<vector<int> > &line, int v){
    queue<int> q;

    q.push(v);
    visited[v] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for(int i=0; i<line[cur].size(); i++){
            int next = line[cur][i];
            if(visited[next] == false){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, v;
    int n;

    cin >> n >> m >> v;

    visited = new bool[n+1];

    vector<vector<int> > line(n+1);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        line[a].push_back(b);
        line[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(line[i].begin(), line[i].end()); // sort안하면 답 이상하게 나옴
    }

    dfs(line, v);
    cout << '\n';
    
    fill(visited, visited + n + 1, false);  // 배열 재설정

    bfs(line, v);
    cout << '\n';

    delete[] visited;
}