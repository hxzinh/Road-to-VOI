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

const int NM = 2e3 + 10;
int n;
int result = INF;
int a[NM], val[NM];
bool cx[21];
vector<int> V;

void backtrack(int x){
    if(x > n){
        int cnt = 0;
        for(int i = 1; i <= n; i++) if(cx[val[a[x]]]) cnt++;
        minimize(result, n - cnt);
        return;
    }
    if(!cx[val[a[x]] + 1] && !cx[a[x] + 8] && !cx[a[x] + 9]){
        cx[a[x]] = true;
        backtrack(x + 1);
        cx[a[x]] = false;
    } else backtrack(x + 1);
}
void sub1(){
    backtrack(1);
    cout << result;
}
int main()
{
    FastIO
    freopen("SEQ98.INP", "r", stdin);
    freopen("SEQ98.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) V.push_back(a[i]);
    sort(ALL(V));
    V.resize(unique(ALL(V)) - V.begin());
    for(int i = 1; i <= n; i++){
        int pos = lower_bound(ALL(V), a[i]) - V.begin() + 1;
        val[pos] = a[i];
        a[i] = pos;
    }

    return 0;
}
