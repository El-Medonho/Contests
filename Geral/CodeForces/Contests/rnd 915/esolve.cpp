#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
struct Mint
{
    int val;
    Mint(long long x = 0)
    {
        val = x % mod;
    }
    Mint operator+(Mint oth)
    {
        return val + oth.val;
    }
    Mint operator-(Mint oth)
    {
        return val - oth.val + mod;
    }
    Mint operator*(Mint oth)
    {
        return val * oth.val;
    }
};
Mint powmod(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b % 2 == 1)
    {
        return powmod(a, b - 1) * a;
    }
    Mint P = powmod(a, b / 2);
    return P * P;
}
map<int, vector<vector<tuple<int, int, int>>>> memo;
vector<vector<tuple<int, int, int>>> find_ranges(int lg) // log^2
{
    if (memo.find(lg) != memo.end())
    {
        return memo[lg];
    }
    if (lg == 1)
    {
        return {{{1, 1, 1}}};
    }
    vector<vector<tuple<int, int, int>>> l = find_ranges((lg + 1) / 2);
    vector<vector<tuple<int, int, int>>> r = find_ranges(lg / 2);
    vector<vector<tuple<int, int, int>>> ans(max(l.size(), r.size()) + 1);
    Mint x = (powmod(2, (lg + 1) / 2) - 1) * (powmod(2, lg / 2) - 1);
    ans[0].push_back({lg, 1, x.val});
     for (int i = 0; i < (int)l.size(); ++i)
    {
        for (auto j : l[i])
        {
            ans[i + 1].push_back(j);
        }
    }
    for (int i = 0; i < (int)r.size(); ++i)
    {
        for (auto j : r[i])
        {
            bool ok = false;
            for (auto &[size, cnt, ways] : ans[i + 1])
            {
                if (size == get<0>(j))
                {
                    ok = true;
                    cnt += get<1>(j);
                }
            }
            if (!ok)
            {
                ans[i + 1].push_back(j);
            }
        }
    }
    return memo[lg] = ans;
}
Mint count(int lg, int coef)
{
    vector<vector<tuple<int, int, int>>> adam = find_ranges(lg);
    Mint ans = 0;
    Mint pow_2 = 1;
    for (int i = 0; i < (int)adam.size(); ++i)
    {
        for (auto [size, cnt, ways] : adam[i])
        {
            ans = ans + pow_2 * coef * cnt * ways;
        }
        pow_2 = pow_2 * 2;
    }
    return ans;
}
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<vector<tuple<int, int, int>>> adam = find_ranges(n);
        Mint ans = count(n, 1);
        for (int i = 1; i < (int)adam.size(); ++i)
        {
            for (auto [size, cnt, ways] : adam[i - 1])
            {
                int lsize = (size + 1) / 2;
                int rsize = size / 2;
                if (rsize)
                {
                    ans = ans + count(rsize, cnt);
                }
            }
        }
        cout << ans.val << '\n';
        memo.clear();
    }
}