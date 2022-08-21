#include <bits/stdc++.h>
#define oo 20000000000000
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FOD(i,a,b) for(int i = b; i >= a; i--)
#define REP(i,a) for(int i = 0; i < a; i++)
#define MASK(i) (1LL << (i))
using namespace std;
#define MAX 50050
int pw[NMOD][MAX];
using ii = pair <int, int>;
using ll = long long;
using ld = long double;
const int Nmax = 1e6 + 5;
int n, k, q, cnt[Nmax], s[Nmax], F[Nmax];
int numDiff;
int range[Nmax];
vector <int> places[Nmax];
deque <int> dq;
 
/// -------------------------- SEGMENT TREE -----------------------------///
/// ------------------------------- END ---------------------------------///
void readfile(){
    FASTIO
    freopen("GUARD.INP", "r", stdin);
    freopen("GUARD.OUT", "w", stdout);
    int SUB, T; cin >> SUB >> T;
    while(T--){
        while(!dq.empty()) dq.pop_back();
        numDiff = 0;
        cin >> n >> k >> q;
        FOR(i,1,q) places[i].clear();
        FOR(i,1,q) cin >> s[i];
        FOR(i,1,q){
        range[i] = 0;
        int x; cin >> x;
            FOR(j,1,x){
                int p; cin >> p;
                places[i].push_back(p);
            }
        }
        int i = 1;
        FOR(j,2,q+1){
            for(int
 
                t : places[j-1])
                if(++cnt[t] == 1) numDiff++;
            while(numDiff > k){
                for(int t : places[i]) if(--cnt[t] == 0) numDiff--;
                i++;
            }
            range[j] = i;
        }
        memset(F, 0, (q+1) * sizeof(int));
        dq.push_back(1);
        for(int j = 2; j <= q; j++){
            while(!dq.empty() && dq.front() < range[j])
                dq.pop_front();
            int k = dq.front();
            F[j] = F[k] + s[j];
            while(!dq.empty() && F[dq.back()] >= F[j])
                dq.pop_back();
            dq.push_back(j);
        }
        int ans = oo;
        FOR(i,1,q) if(i >= range[q+1]) ans = min(ans, F[i]);
        cout << ans << " ";
        memset(cnt, 0, (n+1) * sizeof(int));
    }
 
}
int32_t main(){
    readfile();
    return 0;
}