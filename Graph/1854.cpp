#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m,k;
vector<pair<int, int> > node[1001];

void find(){
    
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
}