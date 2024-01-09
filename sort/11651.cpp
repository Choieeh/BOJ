#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point{
    int x;
    int y;
};

bool compare(point i, point j){
    if(i.y != j.y){
        return i.y < j.y;
    }
    else{
        return i.x < j.x;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<point> points(n);

    for(int i=0; i<n; i++){
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), compare);

    for(int i=0; i<n; i++){
        cout << points[i].x << ' ' << points[i].y << '\n';
    }

}