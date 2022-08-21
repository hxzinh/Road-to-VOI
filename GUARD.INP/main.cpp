#include <bits/stdc++.h>
#define ll long long
#define int long long
#define oo 1e18
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e6+10;
ll T,P;
ll n,q,k,cost=oo;
ll s[NM],f[NM],dem[NM],range[NM];
bool mark[NM];
vector <int> place[NM];

void xuli(ll n,ll k,ll q){
    ll numDiff=0;
    for(int i=1;i<=q;i++) f[i]=oo;
    memset(dem,0,(n+5)*sizeof(int));
    memset(range,0,(q+5)*sizeof(int));
    memset(f,0,(q+5)*sizeof(int));
    ll u=1;
    for(int i=2;i<=q+1;i++){
        for(int t : place[i-1]) if(++dem[t]==1) numDiff++;
        while(numDiff>k){
            for(int t : place[u]) if(--dem[t]==0) numDiff--;
            u++;
        }
        range[i]=u;
    }
    deque <int> dq;
    dq.push_back(1);
    for(int j = 2; j <= q; j++){
            while(!dq.empty() && dq.front() < range[j])
                dq.pop_front();
            int k = dq.front();
            f[j] = f[k] + s[j];
            while(!dq.empty() && f[dq.back()] >= f[j])
                dq.pop_back();
            dq.push_back(j);
        }
    ll ans = oo;
    for(int i=1;i<=q;i++)
        if(i >= range[q+1]) ans = min(ans,f[i]);
    cout << ans << " ";
    ///cout << f[q] << " ";
    ///cout << dp(1) << " ";
    return;
}
void readfile(){
    freopen("GUARD.INP","r",stdin);
    freopen("GUARD.OUT","w",stdout);
    cin >> T >> P;
    for(int i=1;i<=P;i++){
        cin >> n >> k >> q;
        for(int j=1;j<=q;j++){
            cin >> s[j];
            place[j].clear();
        }
        for(int j=1;j<=q;j++){
            ll u; cin >> u;
            for(int k=1;k<=u;k++){
                ll v; cin >> v;
                place[j].push_back(v);
            }
        }
        xuli(n,k,q);
    }
}
int32_t main()
{
    FastIO
    readfile();
    return 0;
}
