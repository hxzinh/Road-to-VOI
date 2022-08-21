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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, q;
char a[55][55];
ii b[55];

void readfile(){
    freopen("KEYBOARD.INP", "r", stdin);
    freopen("KEYBOARD.OUT", "w", stdout);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    for(int i = 1; i <= q; i++) cin >> b[i].fi >> b[i].se;
}
void dfs(int x, int y, char k){
    if(x > n || y > m ) return;
    a[x][y] = k;
    for(int i = 0; i < 4; i++){
        int u = x + dx[i];
        int v = y + dy[i];
        if(a[u][v] == '.') dfs(u, v, k);
    }
    return;
}
void xuli(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) if(a[i][j] != 'X' && a[i][j] != '.') dfs(i, j, a[i][j]);

    bool ok = false;
    for(int i = 1; i <= q; i++){
        int u = b[i].fi;
        int v = b[i].se;
        if(a[u][v] != 'X' && a[u][v] != '.') ok = true;
        if(a[u][v] != 'X' && a[u][v] != '.') cout << a[u][v];
    }
    if(!ok) cout << "Empty";
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
