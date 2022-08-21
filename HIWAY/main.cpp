#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 105;
int n, m, s, f;
int a[NM][NM], g[NM];

struct Data {
    int u, cost;
    vector<int> trace;

    bool inline operator < (const Data &A) const {
        return cost > A.cost;
    }
};

void Dijkstra(){
    priority_queue<Data> pq;
    memset(g, INF, sizeof g);
    g[s] = 0;
    vector<int> t();
    pq.push(Data(s, 0, t));
}
void xuli(){

}
int32_t main()
{
    FastIO
    freopen("HIWAY.INP", "r", stdin);
    freopen("HIWAY.OUT", "w", stdout);
    cin >> n >> m >> s >> f;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = a[v][u] = w;
    }

    xuli();
    return 0;
}

/* Author: hxzinh */

/*
-----code ko bug-----code ko bug-----code ko bug--------------

          _.-/`)
         // / / )
      .=// / / / )
     //`/ / / / /
    // /     ` /
   ||         /
    \\       /
     ))    .'
    //    /
         /
*/
