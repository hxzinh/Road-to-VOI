#include <bits/stdc++.h>
#define ll long long
#define oo 99999999999
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int NM=1e3+10;
ll n,m,l,q;
ll s[NM],c[NM],t[NM];
bool cx[NM],ok;
struct level
{
    ll v,w;
};
vector <level> a[NM],r[NM];

struct Data
{
    ll u,cost;
};
bool operator < (const Data &A,const Data &B)
{
    return A.cost < B.cost;
}

void readfile()
{
    freopen("ROADRAIL.INP","r",stdin);
    freopen("ROADRAIL.OUT","w",stdout);
    cin >> n >> m >> l >> q;
    for(int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
    }
    for(int i=1;i<=l;i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
    }
    for(int i=1;i<=q;i++)
    {
        cin >> c[i] >> t[i];
        ///if(c[i]==0) ok=true;
    }
    for(int i=0;i<n;i++) s[i]=oo;
}
void distraRoad()
{
    priority_queue <Data> pq;
    s[0]=0;
    cx[0]=true;
    pq.push({0,0});
    while(pq.size()>0)
    {
        ll u=pq.top().u;
        ll w=pq.top().cost;
        pq.pop();
        for(int i=0;i<a[u].size();i++)
        {
            ll v=a[u][i].v;
            ll cost=a[u][i].w;
            if(s[v] > w+cost)
            {
                cx[v]=true;
                s[v]=w+cost;
                pq.push({v,s[v]});
            }
        }
    }
}
/** void Rail(ll c)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<r[i].size();j++)
        {
            ll v=r[i][j].v;
            ll w=r[i][j].w;
            if(s[i]+c<s[v])
            {
                s[v]=s[i]+c;
            }
        }
    }
} **/
void xuli()
{
    distraRoad();
    for(int i=1;i<=q;i++)
    {
        if(!cx[t[i]]) cout << -1;
        else cout << s[t[i]] << '\n';
    }
}
int main()
{
    FastIO
    readfile();
    xuli();
    return 0;
}
