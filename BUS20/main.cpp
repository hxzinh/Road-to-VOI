#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e4 + 10;
int n, m, start, fin;
int d[NM], g[NM];
pii dist[NM];

struct Data {
    int type, u, v, cost;
} a[NM];

struct Road {
    int v, cost;
};
vector<Road> edges[NM], road[NM];

struct Bus {
    int u, costA, costB;

    bool inline operator < (const Bus &A) const {
        return (costA + costB) > (A.costA + A.costB);
    }
};

bool operator == (const pii &A, const pii &B) {
    return (A.fi == B.fi) && (A.se == B.se);
}
int sumCost(pii A){
    return A.fi + A.se;
}
void dijktra(int st, int d[], vector<Road> bridge[]){
    priority_queue<Bus> pq;
    for(int i = 1; i <= n; i++) d[i] = INF;
    d[st] = 0;
    pq.push({st, 0, 0});

    while(!pq.empty()){
        int u = pq.top().u, cost = pq.top().costA;
        pq.pop();
        if(cost != d[u]) continue;
        for(auto v : bridge[u]){
            if(minimize(d[v.v], max(v.cost, d[u])))
                pq.push({v.v, d[v.v], 0});
        }
    }
}
void sub1(){
    dijktra(start, d, edges);
    cout << d[fin];
}
void sub2(){
    priority_queue<Bus> pq;
    for(int i = 1; i <= n; i++) dist[i] = {INF, INF};
    dist[start] = {0, 0};
    pq.push({start, 0, 0});

    while(!pq.empty()){
        int u = pq.top().u, costA = pq.top().costA, costB = pq.top().costB;
        pq.pop();
        if(u == fin) {
            cout << dist[fin].fi + dist[fin].se;
            break;
        }
        if(costA != dist[u].fi || costB != dist[u].se) continue;
        for(auto v : edges[u]){
            int newMax = max(v.cost, dist[u].fi);
            if(sumCost(dist[v.v]) > newMax + dist[u].se){
                dist[v.v] = {newMax, dist[u].se};
                pq.push({v.v, newMax, dist[v.v].se});
            }
        }

        for(auto v : road[u]){
            int newMax = max(v.cost, dist[u].se);
            if(sumCost(dist[v.v]) > dist[u].se + newMax){
                dist[v.v] = {dist[u].fi, newMax};
                pq.push({v.v, dist[u].fi, newMax});
            }
        }
    }
}
void sub3(){
    dijktra(start, d, edges);
    dijktra(fin, g, edges);

    int res = min(d[fin], g[start]);
    for(int i = 1; i <= m; i++) if(a[i].type == 2){
        int u = a[i].u, v = a[i].v, cost = a[i].cost;
        if(d[u] < INF && g[v] < INF) minimize(res, max(d[u], g[v]) + cost);
        if(d[v] < INF && g[u] < INF) minimize(res, max(d[v], g[u]) + cost);
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("BUS.INP", "r", stdin);
    freopen("BUS.OUT", "w", stdout);
    cin >> n >> m >> start >> fin;
    bool ok = true;
    for(int i = 1; i <= m; i++){
        int type, u, v, w;
        cin >> type >> u >> v >> w;
        a[i] = {type ,u, v, w};
        if(type == 1) {
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
        } else {
            road[u].push_back({v, w});
            road[v].push_back({u, w});
        }
        if(type != 1) ok = false;
    }

    if(ok) sub1();
    else if(n <= 5000 && m <= 5000) sub2();
    else sub3();

    return 0;
}
