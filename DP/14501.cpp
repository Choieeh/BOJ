#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Work{
    int time;
    int money;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<Work> a(n);
    for(int i=0; i<n; i++){
        Work work;
        cin >> work.time >> work.money;
        a[i] = work;
    }

    vector<int> sum(n+1, 0);
    for(int i=0; i<n; i++){
        int current = i + a[i].time;
        if(current <= n)
            sum[current] = (sum[current] > sum[i] + a[i].money) ? sum[current] : sum[i] + a[i].money;
        
        sum[i+1] = sum[i+1] > sum[i] ? sum[i+1] : sum[i];

    }

    cout << sum[n] << '\n';
}