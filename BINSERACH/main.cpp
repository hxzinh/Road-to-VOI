#include <bits/stdc++.h>
#define ll int
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define setp(x) setprecision(x)
#define MASK(x) (1 << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 8e3 + 10;
const int MAX = 8001;
const int MOD = 998244353;
const int LOG = 14;
int n, k = 0;
int a[NM], high[NM];
ll g[NM][15], frac[NM], finv[NM], f[NM][LOG + 1], cac[NM];

void add(ll &a, ll b){
    if(a + b >= MOD) a += b - MOD;
    else a += b;
}
ll pw(int x, int t){
    if(t == 0) return 1;
    if(t == 1) return x;
    ll w = pw(x, t >> 1) % MOD;
    if(t % 2 == 0) return (1LL * w * w) % MOD;
    else return (1LL * w * w % MOD) * 1LL * x % MOD;
}
ll comb(int k, int n) {
	return k > n ? 0 : (1LL * frac[n] * finv[k] % MOD) * finv[n - k] % MOD;
}
void sub1(){
    for(int i = 1; i <= n; i++) while(MASK(high[i]) <= i) high[i]++;
    int k = high[i];

    for(int i = 1; i <= LOG; i++)
}
void full(){
    for(int i = 1; i <= n; i++) while(MASK(high[i]) <= i) high[i]++;
    int k = high[n];

    f[2][2] = 2; f[3][2] = 2;
    for(int i = 1; i <= LOG; i++) f[1][i] = 1;

    for(int j = 3; j <= LOG; j++){
        for(int i = 2; i <= min(MASK(j) - 1, n); i++) {
            f[i][j] = 2 * f[i - 1][j - 1] % MOD;
            for(int t = 1; t <= n - 2; t++){
                f[i][j] = (f[i][j] + 1LL * f[t][j - 1] * f[i - t - 1][j - 1] % MOD * comb(t, i - 1)) % MOD;
            }
        }
    }

    cac[1] = 1; cac[2] = 2; cac[3] = 2;
    for(int i = 4; i <= n; i++){
        int h = high[i] - 1;
        int L = MASK(h - 1) - 1, R = MASK(h) - 1;
        for(int j = max(L, i - 1 - R); j <= min(R, i - 1 - L); j++)
            cac[i] = (cac[i] + 1LL * cac[j] * cac[i - j - 1] % MOD * comb(j, i - 1)) % MOD;
    }

    //cout << cac[n] << " " << f[n][k] << " " << comb(15, n) << '\n';
    cout << (f[n][k] - cac[n] + MOD) % MOD << " " << 0;
}
int32_t main()
{
    FastIO
    freopen("BST.INP", "r", stdin);
    freopen("BST.OUT", "w", stdout);
    cin >> n;

    frac[0] = 1;
    for(int i = 1; i <= MAX; i++) frac[i] = (1LL * frac[i - 1] * i) % MOD;
    finv[MAX] = pw(frac[MAX], MOD - 2) % MOD;
    for (int i = MAX; i >= 1; i--) finv[i - 1] = (1LL * finv[i] * i) % MOD;

    full();
    return 0;
}


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
