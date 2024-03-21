#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int b, c;

    cin >> n;
    vector<int> a(n);
    long long answer=0;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> b >> c;

    for(int i : a){
        answer += 1;
        i -= b;
        
        if(i > 0){
            long long k = i / c;
            answer += k;
            if(i % c != 0)
                answer += 1;
        }
    }
 
    cout << answer << endl;
}