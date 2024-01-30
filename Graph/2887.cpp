#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int parent[1000001];
vector<tuple<int, int, int> > dist;

int find_root(int x){
    if(parent[x] == x) return x;

    return parent[x] = find_root(parent[x]);
}

bool union_root(int a, int b){
    a = find_root(a);
    b = find_root(b);

    if(a == b) return false;
    else{
        parent[a] = b;
        return true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i< n+1; i++){
        parent[i] = i;
    }

    int ans = 0;
    
    vector<pair<int, int> > x;
    vector<pair<int, int> > y;
    vector<pair<int, int> > z;

    for(int i=0; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        x.push_back(make_pair(a, i));
        y.push_back(make_pair(b, i));
        z.push_back(make_pair(c, i));
    }


    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for(int i=0; i<n-1; i++){
        dist.push_back({x[i+1].first - x[i].first, x[i].second, x[i+1].second});
        dist.push_back({y[i+1].first - y[i].first, y[i].second, y[i+1].second});
        dist.push_back({z[i+1].first - z[i].first, z[i].second, z[i+1].second});
    }

    sort(dist.begin(), dist.end());

    for(int i=0; i<dist.size(); i++){
        if(union_root(get<1>(dist[i]), get<2>(dist[i]))){
            ans += get<0>(dist[i]);
        }
    }

    cout << ans << '\n';
    
}