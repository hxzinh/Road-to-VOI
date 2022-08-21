#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<class X, class Y>
	inline bool maximize(X &x, const Y &y) {return (x < y ? x = y, 1 : 0);}
template<class X, class Y>
	inline bool minimize(X &x, const Y &y) {return (x > y ? x = y, 1 : 0);}

string a, s;

void xuli(){
    bool ok = false;
    queue<string> q;
    q.push(s);

    while(q.size()){
        string u = q.front();
        q.pop();
        if(u == a){
            ok = true;
            cout << "Yes" << '\n';
            break;
        }
        if(u.size() <= a.size()) continue;
        string v;
        if(u[0] == 'B'){
            v = u.substr(1);
            reverse(ALL(v));
            q.push(v);
        }
        if(u.back() == 'A'){
            u.pop_back();
            q.push(u);
        }
    }
    if(!ok) cout << "No" << '\n';
}
int main()
{
    FastIO
    freopen("ABBA.INP", "r", stdin);
    freopen("ABBA.OUT", "w", stdout);
    while(cin >> a >> s){
        xuli();
    }
    return 0;
}
