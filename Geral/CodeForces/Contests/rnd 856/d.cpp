#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define MOD 1000000009
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

ull modmul(ull a, ull b, ull M) {
ll ret = a * b - M * ull(1.L / M * a * b);
return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
ull ans = 1;
for (; e; b = modmul(b, b, mod), e /= 2)
if (e & 1) ans = modmul(ans, b, mod);
return ans;
}

//Deterministic Miller-Rabin primality test. Guaranteed to
// work for numbers up to 264 ; for larger numbers, extend A randomly.
//O(logn)

bool isPrime(ull n) {
if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
vector<ull> A = {2, 325, 9375, 28178, 450775, 9780504,
1795265022};
ull s = __builtin_ctzll(n-1), d = n >> s;
for(ull a : A) {
    // ^ count t r a i l i n g zeroes
    ull p = modpow(a % n, d, n), i = s;
    while (p != 1 && p != n - 1 && a % n && i--)
    p = modmul(p, p, n);
    if (p != n-1 && i != s) return 0;
}
return 1;
}

int main(){
    fastio;

    int n; cin >> n; n*=2;
    vii arr(n);
    vii occur(1000006,0);

    vector<vll> pascal(4050, vll(4050, 0));
    pascal[0][0]=1;
    for(int i=1; i<=n; i++){
        pascal[i][0]=pascal[i][i]=1;
        for(int j=1; j<i; j++){
            pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
        }
    }

    for(int &i: arr) cin >> i;

    set<int> nums;

    int primes = 0,notprimes = 0;

    for(int i = 0; i < n; i++){
        occur[arr[i]]++;
    }

    for(int i = 0; i < n; i++){
        bool k = isPrime(arr[i]);
        if(k)primes++;
        else notprimes++;
    }

    if(notprimes > primes) {
        cout << 0 << endl;
        return 0;
    }

    return 0;
}