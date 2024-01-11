#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> dxy[4] = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};

int bfs(vector<vector<int> >& vmap, int x, int y) {
    int n = vmap.size();
    int cnt = 0;
    queue<pair<int, int> > q;
    vmap[x][y] = 2;
    q.push(make_pair(x, y));

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        cnt++;

        for(const pair<int, int>& xy: dxy) {
            int nextx = cur.first + xy.first;
            int nexty = cur.second + xy.second;

            if(nextx >= 0 && nextx < n && nexty >= 0 && nexty < n && vmap[nextx][nexty] == 1) {
                vmap[nextx][nexty] = 2;
                q.push(make_pair(nextx, nexty));
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> map_count;
    vector<vector<int> > vmap(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            vmap[i][j] = line[j] - '0';
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vmap[i][j] == 1) {
                map_count.push_back(bfs(vmap, i, j));
            }
        }
    }

    sort(map_count.begin(), map_count.end());

    cout << map_count.size() << '\n';
    for(int count : map_count) {
        cout << count << '\n';
    }

    return 0;
}
