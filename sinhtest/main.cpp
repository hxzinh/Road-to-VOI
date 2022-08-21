#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

int main()
{
    FastIO
    freopen("OUT","w",stdout);
    srand(time(0));
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) cout << rand() % 2;
        cout << '\n';
    }


    return 0;
}
