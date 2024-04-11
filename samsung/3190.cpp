#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, l;
vector<pair<int ,int> > apple;
vector<pair<int, char> > direction;

vector<pair<int, int> > snake;
int second=0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool check(int nx, int ny){
    // pair<int, int> back = snake.back();
    // for(int i=0; i<snake.size(); i++){
    //     cout << snake[i].first << snake[i].second << endl;
    // }

    //     cout << back.first << back.second << endl;
    //     cout << "--------------------" << endl;
    if(nx >= 1 && nx <=n && ny >= 1 && ny <= n){
        pair<int, int> cur_xy = {nx, ny};
        if(find(snake.begin(), snake.end(), cur_xy) == snake.end())
            return true;
        else
            return false;
    }
    return false;
}

void simulation(){
    int cur_dir = 0;
    while(true){
        second++;
        pair<int, int> cur_head = snake.back();
        int nx = cur_head.first + dx[cur_dir];
        int ny = cur_head.second + dy[cur_dir];

        if(check(nx, ny) == false)
            return;
        pair<int, int> nxny = {nx, ny};

        if(find(apple.begin(), apple.end(), nxny) != apple.end()){
            int index = find(apple.begin(), apple.end(), nxny) - apple.begin();
            apple.erase(apple.begin() + index, apple.begin() + index + 1);
        }
        else{
            snake.erase(snake.begin(), snake.begin() + 1);
        }
        snake.push_back({nx, ny});
        if(second == direction.front().first){
            if(direction.front().second == 'D'){
                cur_dir++;
                if(cur_dir == 4){
                    cur_dir = 0;
                }
            }
            else{
                cur_dir--;
                if(cur_dir == - 1){
                    cur_dir = 3;
                }
            }
            direction.erase(direction.begin(), direction.begin() + 1);
        }
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> k;
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        apple.push_back({x, y});
    }
    cin >> l;
    for(int i=0; i<l; i++){
        int x;
        char c;
        cin >> x >> c;
        direction.push_back({x, c});
    }

    snake.push_back({1, 1});
    simulation();

    cout << second << endl;
}