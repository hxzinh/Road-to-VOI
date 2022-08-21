#include <bits/stdc++.h>
#define int long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

const int NM = 2e6 + 10;
int n, m, k, T;
int fibo[NM], s[NM];

int32_t main()
{
    FastIO
    freopen("FIBSEQ.INP", "r", stdin);
    freopen("FIBSEQ.OUT", "w", stdout);
    cin >> T;

    while(T--){
        cin >> n >> m >> k;

        fibo[1] = 1; fibo[2] = 1;
        for(int i = 3; i <= n + m; i++) fibo[i] = (fibo[i - 1] + fibo[i - 2]) % k;

        for(int i = 1; i <= n + m; i++){
            s[i] = s[i - 1] + fibo[i];
        }

        int res = 0, pos = 0;
        for(int i = m; i <= n + m; i++){
            for(int j = i + 1; j <= n + m; j++) if((s[j] - s[i - 1]) % k == 0){
                if(maximize(res, j - i + 1)){
                    pos = i;
                    break;
                }
                if(pos) break;
            }
            if(pos) break;
        }
        cout << res << " ";
        if(res) for(int i = pos; i <= pos + res - 1; i++) cout << i << " ";
    }
    return 0;
}
