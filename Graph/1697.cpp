#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int max_cnt=1000000;

void bfs(int n, int k){
    int cnt=0;
    vector<int> visited(100001, -1);
    queue<int> dfs_queue;
    dfs_queue.push(n);
    visited[n] = 0;

    while (!dfs_queue.empty()){
        int next = dfs_queue.front();
        dfs_queue.pop();
        if(next == k){
            cout << visited[next] << endl;
            return;
        }

        vector<int> next_positions;
        next_positions.push_back(next - 1);
        next_positions.push_back(next + 1);
        next_positions.push_back(next * 2);
        for(int new_next : next_positions){
            if(new_next >= 0 && new_next <= 100000 && visited[new_next] == -1){
                visited[new_next] = visited[next] + 1;
                dfs_queue.push(new_next);
            }

        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    
    cin >> n >> k;

    bfs(n, k);

}