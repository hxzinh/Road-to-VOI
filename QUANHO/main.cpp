#include <bits/stdc++.h>
#define int long long
#define oo 2e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int, int>

using namespace std;
const int NM = 1e5 + 10;
int n, m;
int p[NM];
vector<ii> child[NM];

struct Cake{
    int cost, cake;
};
Cake s[NM];

struct Data{
    int u, cost, cake;

    bool inline operator < (Data A) const {
        return (cost > A.cost || cost == A.cost && cake < A.cake);
    }
};
priority_queue<Data> pq;

void readfile(){
    freopen("QUANHO.INP","r",stdin);
    freopen("QUANHO.OUT","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        child[u].push_back({v, w});
        child[v].push_back({u, w});
    }
    for(int i = 1; i <= n; i++){
        s[i].cost = oo;
        s[i].cake = 0;
    }
    s[1].cost = 0; s[1].cake = p[1];
}
void dijtra(){
    pq.push({1, 0, p[1]});
    while(!pq.empty()){
        int u = pq.top().u, cost = pq.top().cost, numCake = pq.top().cake;
        pq.pop();
        if(cost != s[u].cost) continue;
        for(auto v : child[u]){
            if(s[v.first].cost > s[u].cost + v.second){
                s[v.first].cost = s[u].cost + v.second;
                s[v.first].cake = numCake + p[v.first];
                pq.push({v.first, s[v.first].cost, s[v.first].cake});
            } else
                if(s[v.first].cost == s[u].cost + v.second && s[v.first].cake < numCake + p[v.first]) {
                    s[v.first].cake = numCake + p[v.first];
                    pq.push({v.first, s[v.first].cost, s[v.first].cake});
                }
        }
    }
}

void xuli(){
    dijtra();
    if(s[n].cost == oo) cout << "impossible";
    else cout << s[n].cost << " " << s[n].cake;
}
int32_t main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
