#include "bits/stdc++.h"

#define endl '\n'
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ull sumsq(ull to) { return to / 2 * ((to-1) | 1); }
ull divsum(ull to, ull c, ull k, ull m) {
    ull res = k / m * sumsq(to) + c / m * to;
    k %= m; c %= m;
    if(k){
        ull to2 = (to * k + c) / m;
        res += to * to2;
        res -= divsum(to2, m-1 - c, m, k) + to2;
    }
    return res;
}

ll modsum(ull to, ll c, ll k, ll m){
    c = ((c%m)+m) % m; k = ((k%m)+m)%m;
    return to * c + k * sumsq(to) - m * divsum(to, c, k, m);
}

ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for(; e; b = modmul(b,b,mod), e/=2){
        if(e&1) ans = modmul(ans,b,mod);
    }
    return ans;
}

bool isPrime(ull n){
    if(n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    vector<ull> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ull s = __builtin_ctzll(n-1), d = n >> s;
    for(ull a: A){
        ull p = modpow(a % n, d, n), i = s;
        while(p != 1 && p != n - 1 && a % n && i--){
            p = modmul(p, p, n);
        }
        if(p != n-1 && i != s) return 0;
    }
    return 1;
}

ull pollard(ull n){
    auto f = [n](ull x, ull k) {return modmul(x,x,n) + k; };
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while(t++ % 40 || gcd(prd, n) == 1) {
        if(x == y) x = ++i, y = f(x, i);
        if((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
        x = f(x, i), y = f(f(y, i), i);
    }
    return gcd(prd, n);
}

vector<ull> factor(ull n) {
    if(n == 1) return { };
    if(isPrime(n)) return {n};
    ull x = pollard(n); auto l = factor(x), r = factor(n/x);
    l.insert(l.end(), r.begin(), r.end());
    return l;
}


signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    vector<ull> arr(n); 

    // for(ull x: factor(n)) cout << x << endl;

    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    set<ull> divs;
    map<ull,ll> mp;
    for(ull x: arr) divs.insert(x);

    if(n == 1){
        if(arr[0] == 1) cout << '*' << endl;
        else cout << arr[0] << ' ' << 1 << endl;
        return 0;
    }

    if(arr[0] != 1){
        cout << arr[n-1] << ' ' << 1 << endl;
        return 0;
    }

    ll bg = arr[n-1];

    auto p = factor(bg);

    for(ull x: p){
        mp[x]++;
    }

    vector<ull> arr2(mp.size());

    int i = 0;
    for(auto it = mp.begin(); it != mp.end(); it++, i++) arr2[i] = (*it).first;

    ll missing = -1;
    ll count = 0;
    function<ll(int, ull)> dfs = [&](int ind, ull num){
        if(ind >= arr2.size()){
            // cout << num << endl;
            if(divs.find(num) == divs.end()) {
                // assert(missing == -1);
                count++;
                missing = num;
                return 0;
            }
            divs.erase(num);
            return 0;
        }

        int mx = mp[arr2[ind]];

        ll b = 0;
        do{
            dfs(ind+1, num);
            num *= arr2[ind];
            b++;
        } while(b <= mx);

        return 0;
    };

    dfs(0, 1);

    // assert(!(divs.size() > 0 && count == 1));

    // if(count == 0){
    //     assert(mp.size() == 1);
    //     cout << arr[n-1] * arr[1] << ' ' << arr[n-1] * arr[1] << endl;
    //     return 0;
    // }

    if(count == 1){
        cout << arr[n-1] << ' ' << missing << endl;
        return 0;
    }

    if(divs.size() > 0 || count == 0){
        cout << arr[n-1] * arr[1] << ' ' << arr[n-1] * arr[1] << endl;
        return 0;
    }





    return 0;
}