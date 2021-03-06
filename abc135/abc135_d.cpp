#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

long mod = 1000000007;
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


mint dp[100001][13] = {0};

int main()
{
    string s;
    cin >> s;

    int num = s.size();
    mint ans(0);
    int mul = 1;
    dp[0][0] = 1;

    rep(i, num){
        char x = s[num-1-i];
        //cout << x << endl;
        if (x == '?'){
            rep(k, 10){
                rep(j, 13){
                    dp[i+1][(j + mul * k)%13] += dp[i][j];
                }
            }
        } else {
            int k = x - '0';
            rep(j, 13){
                dp[i+1][(j + mul * k)%13] = dp[i][j];
            }
        }
        mul *= 10;
        mul %= 13;
    }

    // rep(i, num+1){
    //     rep(j, 13){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[num][5].x << endl;
}

