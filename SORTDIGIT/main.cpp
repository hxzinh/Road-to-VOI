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

vector<pii> a;

bool cmp(const pii A, const pii B){
    return (A.se == B.se ? A.fi < B.fi : A.se < B.se);
}
int32_t main()
{
    FastIO
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        pii o = {u, 0};

        while(u != 0){
            o.se += u % 10;
            u /= 10;
        }
        a.push_back(o);
    }

    sort(ALL(a));
    int res = INF;
    for(int i = 1; i < a.size(); i++) minimize(res, abs(a[i].fi - a[i - 1].fi));
    cout << res;
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
