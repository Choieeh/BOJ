#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(vector<vector<int> > ans, vector<int> &visited){
    queue<int> q;

    q.push(1);
    visited[1] = 0;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(const int a: ans[current]){
            if(visited[a] == -1){
                visited[a] = visited[current] + 1;
                q.push(a);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;
    vector<vector<int> > ans(n+1);

    for(int i=0; i<m; i++){
        int a, b;

        cin >> a >> b;
        ans[a].push_back(b);
        ans[b].push_back(a);
    }

    vector<int> visited(n+1, -1);

    bfs(ans, visited);

    int max_index = max_element(visited.begin(), visited.end()) - visited.begin();
    int max_count = *max_element(visited.begin(), visited.end());

    cout << max_index << " " << max_count << " " << count(visited.begin(), visited.end(), max_count) << '\n';
}