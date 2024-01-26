#include <iostream>
#include <vector>

using namespace std;

struct Point{
    int x;
    int y;
    int z;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    
    vector<Point> m(n);

    for(int i=0; i<n; i++){
        Point new_point;
        cin >> new_point.x << new_point.y << new_point.z;
        m[i] = new_point;
    }
}