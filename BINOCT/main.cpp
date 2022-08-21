#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define MASK(x) (1LL << (x))
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

string n;
unsigned long long s = 0;

int main()
{
    FastIO
    int T;
    freopen("inp", "r", stdin);
    freopen("out", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n;
        s = 0;
        int cnt = 0;
        for(int i = n.size() - 1; i >= 0; i--){
            if(n[i] == '1') s |= MASK(cnt);
            cnt++;
        }
        cout << s << '\n';
    }
    return 0;
}
