#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m,k;
vector<pair<int, int> > node[1002];
priority_queue<int> ans[1002];

void find(){
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, 1));

    while(!pq.empty()){
        int cur_dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(int i=0; i<node[cur].size(); i++){
            int next = node[cur][i].first;
            int next_dist = node[cur][i].second + cur_dist;

            if(ans[next].size() < k){
                ans[next].push(next_dist);
                pq.push(make_pair(-next_dist, next));
            }
            else if(ans[next].top() > next_dist){
                ans[next].pop();
                ans[next].push(next_dist);
                pq.push(make_pair(-next_dist, next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m>> k;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        node[a].push_back(make_pair(b, c));
    }
    ans[1].push(0);
    find();

    for(int i=0; i<n; i++){
        if(ans[i+1].size() != k) cout << -1 << '\n';
        else cout << ans[i+1].top() << '\n';
    }

}