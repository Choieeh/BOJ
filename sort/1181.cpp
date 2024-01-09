#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

bool compare(string i, string j){
    if(i.length() != j.length()){
        return i.length() < j.length();
    }
    else{
        return i < j;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<string> a;

    for(int i=0; i<n; i++){
        string k;
        cin >> k;
        a.insert(k);
    }
    
    vector<string> b(a.begin(), a.end());

    sort(b.begin(), b.end(), compare);

    for (int i = 0; i<b.size(); i++){
        cout << b[i] << '\n';
    }
}