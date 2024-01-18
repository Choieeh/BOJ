#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int> > a(n, vector<int>(n));
    vector<vector<int> > sum(n, vector<int>(n, -1));

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> a[i][j];
        }
    }

    sum[0][0] = a[0][0];

    for(int i=0; i<n-1; i++){
        for(int j=0; j<=i; j++){
            sum[i+1][j] = (sum[i][j] + a[i+1][j]) > sum[i+1][j] ? sum[i][j] + a[i+1][j] : sum[i+1][j];
            sum[i+1][j+1] = (sum[i][j] + a[i+1][j+1]) > sum[i+1][j+1] ? sum[i][j] + a[i+1][j+1] : sum[i+1][j+1];
        }
    }

    cout << *max_element(sum[n-1].begin(), sum[n-1].end()) << '\n';
}