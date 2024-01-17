#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int> house, int mid){
    int count = 0;
    int last = house[0];
    count++;

    for(int i=0; i<int(house.size()); i++){
        if(house[i] - last >= mid){
            count++;
            last = house[i];
        }
    }

    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    vector<int> house(n);

    for(int i=0; i<n; i++){
        cin >> house[i];
    }

    sort(house.begin(), house.end());

    int low = 1;
    int high = house[n-1] - house[0] + 1;

    while(low < high){
        int mid = (high + low) / 2;

        if(search(house, mid) < c){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    cout << (low - 1) << '\n';
}