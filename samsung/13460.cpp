#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
char board[10][10];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Ball{
    int x;
    int y;
};

Ball blue;
Ball red;
Ball hole;

bool OOB(Ball a){
    if(board[a.x][a.y] == 'B' || board[a.x][a.y] == 'R')
        return true;
    if (a.x < 1 || a.x >= n-1 || a.y <1 || a.y >=m-1 || board[a.x][a.y] == '#')
        return true;
    return false;
}

int bfs(){
    queue<pair<Ball, Ball> > q;
    pair<Ball, Ball> last;

    int count = 0;

    q.push({red, blue});

    while(!q.empty()){
        Ball cur_red = q.front().first;
        Ball cur_blue = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            pair<Ball, Ball> next_ball;
            Ball next_red, next_blue;
            next_red.x = cur_red.x + nx[i];
            next_red.y = cur_red.y + ny[i];
            next_blue.x = cur_blue.x + nx[i];
            next_blue.y = cur_blue.y + ny[i];

            next_ball.first = OOB(next_red) ? cur_red : next_red;
            next_ball.second = OOB(next_blue) ? cur_blue : next_blue;

            q.push(next_ball);
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == 'B'){
                blue.x = i;
                blue.y = j;
            }
            else if(board[i][j] == 'R'){
                red.x = i;
                red.y = j;
            }
            else if(board[i][j] == '0'){
                hole.x = i;
                hole.y = j;
            }
        }
    }
}