#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM = 1e5 + 10;
int n, m, k, l;
int dA[NM], dB[NM];
int num[NM], low[NM], sA[NM], sB[NM];
int cnt = 0, numCnt = 0;
int numEdges = 0;
vector<int> edges[NM], newEdges[NM];
stack<int> st;
bool Node[NM];

void readfile(){
    freopen("NET.INP", "r", stdin);
    freopen("NET.OUT", "w", stdout);
    cin >> n >> m >> k >> l;
    for(int i = 1; i <= k; i++){
        int u; cin >> u;
        sA[u] = 1;
    }
    for(int i = 1; i <= l; i++){
        int u; cin >> u;
        sB[u] = 1;
    }
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

}
void dfs(int u, int p){
    low[u] = num[u] = ++cnt;
    for(int v : edges[u]){
        if(v != p){
            if(num[v] != 0){
                low[u] = min(low[u], num[v]);
            } else {
                dfs(v, u);
                sA[u] += sA[v];
                sB[u] += sB[v];
                low[u] = min(low[u], low[v]);
                if(low[v] >= num[v]){
                    if(sA[v] == 0 || sB[v] == 0 || sA[v] == k || sB[v] == l) numEdges++;
                }
            }
        }
    }
}
void xuli(){
    for(int i = 1; i <= n; i++) if(!num[i]) {
        dfs(i, i);
    }
    cout << numEdges << '\n';
    for(int i = 1; i <= n; i++){
        cout << sA[i] << " " << sB[i] << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
