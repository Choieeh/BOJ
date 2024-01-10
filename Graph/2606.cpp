#include <iostream>
#include <vector>

using namespace std;

bool *visited;
int com_count=0;

void dfs(vector<vector<int> > &line, int v){
    visited[v] = true;
    com_count++;

    for(int i=0; i<line[v].size(); i++){
        int next = line[v][i];

        if(!visited[next]){
            dfs(line, next);
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;

    cin >> n >> m;

    visited = new bool[n+1];
    vector<vector<int> > line(n+1);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        line[a].push_back(b);
        line[b].push_back(a);
    }

    dfs(line, 1);
    cout << com_count-1 << '\n';

    delete[] visited;

}