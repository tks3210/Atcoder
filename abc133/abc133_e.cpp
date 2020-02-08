#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;
long mod = 1000000007;
/* C++の構造体 メンバがpublicなclass */
typedef struct mint
{
    ll x;
    mint(ll x = 0) : x(x % mod) {} //コンストラクタ
    /* 演算子オーバーロード */
    mint &operator+=(const mint a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator-=(const mint a)
    {
        if ((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator*=(const mint a)
    {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const
    {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const
    {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const
    {
        mint res(*this);
        return res *= a;
    }
    mint pow(ll t) const
    {
        if (!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const
    {
        return pow(mod - 2);
    }
    mint &operator/=(const mint a)
    {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const
    {
        mint res(*this);
        return res /= a;
    }
} mint_t;

mint ans = 0;
int k;
void dfs(const vector<vector<int>>&graph, int now, int from){
    if (graph[now].size() == 1 && from != -1) return;

    int color_var;
    int child_num;
    if(from == -1){
        color_var = k - 1;
        child_num = graph[now].size();
    } else {
        color_var = k - 2;
        child_num = graph[now].size() - 1;
    }
    if (graph[now].size() >= k){
        ans = 0;
        return;
    }
    rep(i, child_num){
        ans *= color_var-i;
        //cout << ans.x << " "<< now << endl;
    }
    for (auto next: graph[now])
    {
        if (next == from) continue;
        dfs(graph, next, now);
    }
    
}

int main()
{
    int n;cin >> n >> k;
    vector<vector<int>> graph(n);
    rep(i, n - 1){ 
        int a, b; cin>>a>>b;a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ans = k;    
    dfs(graph, 0, -1);
    cout << ans.x << endl;
}

