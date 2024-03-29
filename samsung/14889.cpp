#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>

using namespace std;

int n;
int stat[21][21];
int ans=10000000;

void bfs(vector<int> teama, vector<int> teamb, int k, int acount, int bcount){
    if(teama.size() == n/2 && teamb.size() == n/2){
        int t = abs(acount - bcount);
        if(t < ans) {
            ans = t;
        }
        return;
    }

    if(teama.size() < n/2){
        vector<int> temp = teama;
        temp.push_back(k);
        int new_acount = acount;
        for(auto i : teama){
            new_acount += stat[i][k] + stat[k][i];
        }
        bfs(temp, teamb, k+1, new_acount, bcount);
    }
    if(teamb.size() < n/2){
        vector<int> temp = teamb;
        temp.push_back(k);
        int new_bcount = bcount;
        for(auto i : teamb){
            new_bcount += stat[i][k] + stat[k][i];
        }
        // cout << "bcount" << bcount << endl;
        bfs(teama, temp, k+1, acount, new_bcount);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n;

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cin >> stat[i][j];
        }
    }

    vector<int> teama;
    vector<int> teamb;
    bfs(teama, teamb, 1, 0, 0);
    cout << ans << endl;
}