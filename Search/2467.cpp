#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> liq(n);
    int min=-1;
    int a[2];

    for(int i=0; i<n; i++){
        cin >> liq[i];
    }


    for(int i=0; i<n; i++){
        int left = i+1;
        int right = n-1;

        while (left <= right){
            int mid = (left + right) / 2;

            int sum = liq[i] + liq[mid];
            int new_sum = (sum>=0) ? sum : sum * -1;
            if(min == -1 || new_sum < min){
                min = new_sum;
                a[0] = liq[i];
                a[1] = liq[mid];
            }

            if(sum == 0) break;
            
            if(sum <0){
                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }
    }

    cout << a[0] << ' ' << a[1] << '\n';
}
