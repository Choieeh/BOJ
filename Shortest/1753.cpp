#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct s {
    int end;
    int cost;
};

struct cmp {
    bool operator()(s& a, s& b) {
        return a.cost > b.cost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    int start;
    cin >> start;

    int value[20001];
    vector<s> node[20001];
    priority_queue<s, vector<s>, cmp> q;

    for (int i = 1; i <= v; i++) {
        value[i] = 10000000;
    }
    value[start] = 0;

    for (int i = 0; i < e; i++) {
        int a;
        s new_s;
        cin >> a >> new_s.end >> new_s.cost;
        node[a].push_back(new_s);
    }

    s new_s;
    new_s.end = start;
    new_s.cost = 0;
    q.push(new_s);

    while (!q.empty()) {
        int end = q.top().end;
        int cost = q.top().cost;
        q.pop();

        if (value[end] < cost) continue;

        for (int i = 0; i < node[end].size(); i++) {
            int n_end = node[end][i].end;
            int n_cost = node[end][i].cost;

            if (cost + n_cost < value[n_end]) {
                value[n_end] = cost + n_cost;
                s new_s;
                new_s.end = n_end;
                new_s.cost = value[n_end];
                q.push(new_s);
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (value[i] == 10000000) {
            cout << "INF" << '\n';
        } else {
            cout << value[i] << '\n';
        }
    }
}
