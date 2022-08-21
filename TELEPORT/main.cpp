#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f
#define ALL(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(x) (1LL << (x))
#define BIT(i, x) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e5 + 10;
int n;
int result = INF;
int f[NM], g[NM], p[NM];
vector<int> a, b;


void xuli(){
    int res = 0;
    for(int i = 1; i <= a.size(); i++){
        res += i;
        if((a.size() - i) % 2 != 0){
            int m = (a.size() + i) / 2;
            int tmp = res + g[b.size()] + (m - i - 1) * f[m - 1] + (a.size() - m - 1) * (f[n] - f[m]);
            minimize(result, tmp);
        } else {
            int pos = (a[(a.size() + i) / 2 - 1] + a[(a.size() + i + 1) / 2 - 1]) / 2;
            cout << pos << '\n';
        }
    }
}
void sub1() {
    int res = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int d = 0, m = (p[i] + p[j]) / 2;
            for (int k = 1; k <= n; k++) {
                d += min(abs(m - p[k]), 1LL * abs(p[k]));
            }
            res = min(res, d);
        }
    }
    cout << res;
}
int32_t main()
{
    FastIO
    freopen("TELEPORT.INP", "r", stdin);
    freopen("TELEPORT.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u; cin >> u;
        if(u < 0) a.push_back(-u);
        else if (u > 0) b.push_back(u);
        p[i] = u;
    }
    sort(ALL(a)); sort(ALL(b));
    for(int i = 1; i <= a.size(); i++) f[i] = f[i - 1] + a[i - 1];
    for(int i = 1; i <= b.size(); i++) g[i] = g[i - 1] + b[i - 1];


    xuli();
    return 0;
}
