#include <iostream>
#include <vector>

using namespace std;

int n;
int num[11];
int graph[11][11];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<n+1; i++){
        cin >> num[i];
    }

    for(int i=1; i<n+1; i++){
        int k;
        cin >> k;
        for(int i=0; i<k; i++){
            cin >> graph[k][i];
        }
    }