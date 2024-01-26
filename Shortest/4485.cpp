#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ans;
    int n=1;
    while(true){
        cin >> n;
        if(n == 0) break;
        vector<vector<int> > m(n, vector<int>(n));
        vector<vector<int> > cost(n, vector<int>(n));

        priority_queue<pair<int, pair<int, int> > > pq;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> m[i][j];
                cost[i][j] = 10000000;
            }
        }

        cost[0][0] = m[0][0];
        pq.push(make_pair(-m[0][0], make_pair(0 ,0)));

        while(!pq.empty()){
            pair<int, pair<int, int> > cur = pq.top();
            pq.pop();

            int cur_cost = -cur.first;
            pair<int, int> cur_xy = cur.second;

            if(cur_cost > cost[cur_xy.first][cur_xy.second]) continue;

            for(int i=0; i<4; i++){
                int nx = cur_xy.first + dx[i];
                int ny = cur_xy.second + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny<n){
                    int next_cost = m[nx][ny];

                    if(cur_cost + next_cost < cost[nx][ny]){
                        cost[nx][ny] = cur_cost + next_cost;
                        pq.push(make_pair(-cost[nx][ny], make_pair(nx, ny)));
                    }
                }
            }
        }
        ans.push_back(cost[n-1][n-1]);
    }

    for(int i=0; i<ans.size(); i++){
        cout << "Problem " << i+1 <<": "<< ans[i] << "\n";

    }
}