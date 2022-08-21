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

const int NM = 1e6 + 10;
int n, x;
int a[NM];
pii p[NM];

int32_t main()
{
    FastIO
    cin >> n >> x;
    for(int i = 0; i <= 1000000; i++) p[i] = {-1, -1};
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(p[a[i]].fi == -1) p[a[i]].fi = i;
        p[a[i]].se = i;
    }

    cout << p[x].fi << '\n';
    cout << p[x].se << '\n';
    int u = lower_bound(a, a + n, x) - a;
    if(u < n && a[n - 1] >= x) cout << u << '\n';
    else cout << -1 << '\n';
    int v = upper_bound(a, a + n, x) - a;
    if(v < n && a[n - 1] > x) cout << v << '\n';
    else cout << -1 << '\n';
    cout << (p[x].fi > -1 ? p[x].se - p[x].fi + 1 : 0) << '\n';
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
