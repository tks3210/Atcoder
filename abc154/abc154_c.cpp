#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    int n;
    cin >> n;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}

    sort(a.begin(), a.end());
    bool ans = false;
    rep(i, n-1){
        if (a[i] == a[i+1]) {ans = true; break;}
    }
    if (ans) puts("NO");
    else puts("YES");
}

