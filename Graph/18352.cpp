#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> bfs(vector<vector<int> > map, int n, int k, int x){
    queue<int> bfs_q;
    vector<int> visited(n+1, -1);
    vector<int> answer;

    bfs_q.push(x);
    visited[x] = 0;

    while(!bfs_q.empty()){
        int cur = bfs_q.front();
        bfs_q.pop();

        if(visited[cur] == k){
            answer.push_back(cur);
        }

        else{
            for(const int next : map[cur]){
                if(visited[next] == -1){
                    bfs_q.push(next);
                    visited[next] = visited[cur] + 1;
                }
            }
        }
    }

    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, x;
    vector<int> answer;

    cin >> n >> m >> k >> x;

    vector<vector<int> > map(n+1);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
    }

    answer = bfs(map, n, k, x);
    
    sort(answer.begin(), answer.end());

    if(answer.size()){
        for(const int ans: answer){
            cout << ans << '\n';
        } 
    }
    else{
        cout << -1 << '\n';
    }
    
}