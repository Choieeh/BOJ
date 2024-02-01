#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
vector<vector<char> > space;
vector<vector<bool> > visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
pair<int, int> swan1;
queue<pair<int, int> > water, nextWater, swan, nextSwan;

bool swan_bfs() {
    while(!swan.empty()){
        int x = swan.front().first;
        int y = swan.front().second;
        swan.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            if(space[nx][ny] == 'X') nextSwan.push(make_pair(nx, ny));
            else if (space[nx][ny] == '.') swan.push(make_pair(nx, ny));
            else if (space[nx][ny] == 'L'){
                return true;
            }
        }
    }
    return false;
}

void melt(){
    while(!water.empty()){
        int x = water.front().first;
        int y = water.front().second;

        water.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny]) continue;
            if(space[nx][ny] == 'X'){
                space[nx][ny] = '.';
                nextWater.push(make_pair(nx, ny));
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    space.resize(R, vector<char>(C));
    visited.resize(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char temp;
            cin >> temp;
            space[i][j] = temp;
            if (space[i][j] == 'L') {
                swan1.first = i;
                swan1.second = j;
            }
            if (space[i][j] != 'X') {
                water.push(make_pair(i, j));
            }
        }
    }

    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << space[i][j] << endl;
    //     }
    // }

    swan.push(swan1);
    visited[swan1.first][swan1.second] = true;

    int days = 0;
    while (true) {
        if (swan_bfs()) {
            cout << days << '\n';
            break;
        }

        melt();
        swan = nextSwan;
        water = nextWater;
        while (!nextSwan.empty()) nextSwan.pop();
        while (!nextWater.empty()) nextWater.pop();
        days++;
    }

    return 0;
}
