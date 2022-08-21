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

const int NM = 1e4 + 10;
const int MAX = 1e6 + 10;
int n, k;
int result = INF, Max = -INF;
int a[MAX];
int f[NM][5005], dp[NM][5005];

void sub345(){
    memset(f, INF, sizeof f);
    memset(dp, INF, sizeof dp);

    f[0][0] = 0;
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            if(j + a[i + 1] <= k){
                if(minimize(f[i + 1][j + a[i + 1]], f[i][j])) dp[i + 1][j + a[i + 1]] = dp[i][j];
                else if(f[i + 1][j + a[i + 1]] == f[i][j]) minimize(dp[i + 1][j + a[i + 1]], dp[i][j]);
            } else {
                if(minimize(f[i + 1][a[i + 1]], f[i][j] + 1)) dp[i + 1][a[i + 1]] = dp[i][j];
                else if(f[i + 1][a[i + 1]] == f[i][j] + 1) minimize(dp[i + 1][a[i + 1]], dp[i][j]);
            }

            if(dp[i][j] + a[i + 1] <= k){
                if(minimize(f[i + 1][j], f[i][j])) dp[i + 1][j] = dp[i][j] + a[i + 1];
                else if(f[i + 1][j] == f[i][j]) minimize(dp[i + 1][j], dp[i][j] + a[i + 1]);
            } else {
                if(minimize(f[i + 1][j], f[i][j] + 1)) dp[i + 1][j] = a[i + 1];
                else if(f[i + 1][j] == f[i][j] + 1) minimize(dp[i + 1][j], a[i + 1]);
            }
        }
    }

    int res = INF;
    for(int i = 0; i <= k; i++) minimize(res, f[n][i] + (i > 0) + (dp[n][i] > 0));
    cout << res;
}
void backtrack(int x, int pack1, int pack2, int cntRes){
    if(x > n){
        minimize(result, cntRes);
        return;
    }
    if(pack1 + a[x] <= k) backtrack(x + 1, pack1 + a[x], pack2, cntRes);
    else backtrack(x + 1, a[x], pack2, cntRes + 1);
    if(pack2 + a[x] <= k) backtrack(x + 1, pack1, pack2 + a[x], cntRes);
    else backtrack(x + 1, pack1, a[x], cntRes + 1);
    return;
}
void sub1(){
    backtrack(1, 0, 0, 2);
    cout << result << '\n';
}
void sub2(){
    int sum = 0;
    for(int i = 1; i <= n; i++) sum += a[i];
    cout << sum / k + (sum % k != 0);
}
int32_t main()
{
    FastIO
    freopen("BINPACK.INP", "r", stdin);
    freopen("BINPACK.OUT", "w", stdout);
    cin >> k >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        maximize(Max, a[i]);
    }

    if(n <= 20) sub1();
    else if(Max <= 2) sub2();
    else sub345();
    return 0;
}

/* Author: hxzinh */
