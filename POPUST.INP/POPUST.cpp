#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e5 + 10;
int n;
int f[NM][2];
ii a[NM];
bool cx[NM];

void readfile(){
    freopen("POPUST.INP", "r", stdin);
    freopen("POPUST.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
}
void xuli(){
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) f[i][1] = f[i][0] = INF;
    f[1][1] = a[1].fi;
    f[1][0] = a[1].se;

    for(int i = 1; i < n; i++){
        for(int ok = 0; ok < 2; ok++) if(f[i][ok]) {
            if(ok) minimize(f[i + 1][ok], f[i][ok] + a[i + 1].se);
            else {
                minimize(f[i + 1][ok], f[i][ok] + a[i + 1].se);
                minimize(f[i + 1][true], f[i][ok] + a[i + 1].fi);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << f[i][1] << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
