#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
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

const int NM = 1e5 + 10;
int n, m;
int a[NM], s[NM];

void xuli(){

}
int32_t main()
{
    FastIO
    freopen("CUTSEQS.INP", "r", stdin);
    freopen("CUTSEQS.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

    xuli();
    return 0;
}

/* Author: hxzinh */
