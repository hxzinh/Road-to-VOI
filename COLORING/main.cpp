#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define pii pair<int, int>
#define fi first
#define se second
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 1e3 + 10;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;
int cnt = 0;
int a[NM][NM];
bool cx[NM][NM];
pii color[NM][NM];

void dfs(int x, int y, int id){
    if(x < 0 || x > n || y < 0 || y > m) return;
    cx[x][y] = false;
    color[x][y] = {a[x][y], id};
    for(int i = 0; i < 4; i++){
        int u = x + dx[i];
        int v = y + dy[i];
        if(cx[u][v] && a[x][y] == a[u][v]) dfs(u, v, id);
    }
    return;
}
void xuli(){
    memset(cx, true, sizeof(cx));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) if(cx[i][j]) {
            ++cnt;
            dfs(i, j, cnt);
        }
    }

    cout << cnt;
}
void readfile(){
    freopen("COLORING.INP", "r", stdin);
    freopen("COLORING.OUT", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
