#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int NM=1e6+5;
ll n,t;
ll a[NM],s[NM],k[NM];

ll tong(ll x)
{
    ll i;
    for(i=2;i<=sqrt(x);i++)
    {
        if(x%i==0) return 1+i;
    }
    return 1+x;
}
void readfile()
{
    ll i;
    freopen("SUMDIV.INP","r",stdin);
    freopen("SUMDIV.OUT","w",stdout);
    cin >> n >> t;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        s[i]=tong(a[i]);
    }
    memset(k,0,sizeof(k));
}
void xuli()
{
    ll i,u,v,kqua;
    for(i=1;i<=n;i++)
    {
        k[i]=k[i-1]+s[i];
    }
    for(i=1;i<=t;i++)
    {
        cin >> u >> v;
        kqua=k[v]-k[u-1];
        cout << kqua << '\n';
    }
}
int main()
{
    readfile();
    xuli();
    return 0;
}
