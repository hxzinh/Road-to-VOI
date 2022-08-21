#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define popcount(x) __builtin_popcount(x)
#define set(x) setprecision(x)
#define MASK(x) (1LL << (x))
#define BIT(x, i) ((x) >> (i) & 1)
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 5e4 + 10;
int n, m, T;
pii a[NM];
int s[NM], cntBus[NM];
bool cx[NM];
vector<int> idBus[NM];

struct Data {
    int u, cnt;

    bool inline operator < (const Data &A) const {
        return cnt > A.cnt;
    }
};

priority_queue<Data> pq;

void sub12(){
    for(int i = 1; i <= m; i++)
        for(int j = a[i].fi; j <= a[i].se; j++) idBus[j].push_back(i);

    for(int i = 1; i <= m; i++){
        s[a[i].fi]++;
        s[a[i].se + 1]--;
    }

    memset(cntBus, INF, sizeof cntBus);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += s[i];
        for(int u : idBus[i]) minimize(cntBus[u], sum);
    }

    for(int i = 1; i <= m; i++) pq.push({i, cntBus[i]});
    cout << 2 << '\n';
}
bool cmp3(const pii &A, const pii &B){
    return A.se > B.se;
}
void sub3(){
    sort(a + 1, a + m + 1, cmp3);

    int res = 0;
    for(int i = 1; i <= m; i++){
        for(int j = a[i].se; j > 0; j--) if(!cx[j]){
            cx[j] = true;
            res++;
            break;
        }
    }
    cout << res << '\n';
}
void xuli(){
    bool ok = true;
    for(int i = 1; i <= m; i++) if(a[i].fi > 1) {
        ok = false;
        break;
    }

    if(ok) sub3();
    else sub12();
}
int main()
{
    FastIO
    freopen("QUEUE.INP", "r", stdin);
    freopen("QUEUE.OUT", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1; i <= m; i++) cin >> a[i].fi >> a[i].se;

        xuli();
    }
    return 0;
}
