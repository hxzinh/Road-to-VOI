#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int n, q;
int a[1000005];

int main()
{
    FastIO
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;

    while(q--){
        int u; cin >> u;
        int l = 1, r = n, res = 0;
        while(l <= r){
            int m = (l + r) >> 1;
            if(a[m] >= u){
                res = m;
                l = m + 1;
            } else r = m - 1;
        }
        if(a[res] == u) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
