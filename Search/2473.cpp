#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    // cout << a[0] <<endl;
    
    long long min = -1;
    vector<int> ans(3);

    for(int i=0; i<n-2;i++){
        for(int j=i+1; j<n-1; j++){
            int low = j+1;
            int high = n-1;

            while(low <= high){
                int mid = (low+high) / 2;
                // cout << i << j << mid <<endl;

                long long sum = (long long)a[i] + a[j] + a[mid];

                long long new_sum = abs(sum);
                if(min == -1 || new_sum < min){
                    min = new_sum;
                    ans[0] = a[i];
                    ans[1] = a[j];
                    ans[2] = a[mid];
                }

                if (sum == 0) break;
                else if(sum < 0){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans[0] << ' '<<ans[1]<<' '<<ans[2]<<'\n';
}