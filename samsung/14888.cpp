#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long big=-1000000000;
long long small=1000000000;

void dfs(long long result, vector<int> a, vector<int> op, int k){
    // cout << k << " "<<result << endl; 
    long long new_result;
    if(k == a.size()){
        if(result > big) big = result;
        if(result < small) small = result;
        return;
    }
    else{
        for(int i=0; i<4; i++){
            if(op[i] != 0){
                if(i==0){
                    // cout << 1 << " " << result << endl;
                    new_result = result + a[k];
                }
                else if (i==1){
                    // cout << 2 << " " << result <<endl;
                    new_result = result - a[k];
                }
                else if (i==2){
                    // cout << 3 << " " << result <<endl;
                    new_result = result * a[k];
                }
                else{
                    // cout << 4 << " " << result <<endl;
                    new_result = result / a[k];
                }
                vector<int> new_op = op;
                new_op[i]-=1;
                dfs(new_result, a, new_op, k+1);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> op(4);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }


    for(int i=0; i<4; i++){
        cin >> op[i];
    }
    dfs(a[0], a, op, 1);

    cout << big << '\n' << small << endl;
}