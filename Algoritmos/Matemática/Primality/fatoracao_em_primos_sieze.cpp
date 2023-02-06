//O(logn)

// #include "bits/stdc++.h"
// using namespace std;

// #define MOD 1000000009
// #define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
// #define f first
// #define s second
// #define pb push_back
// #define pii pair<int,int>
// #define pll pair<long long,long long>
// #define vii vector<int>
// #define vll vector<long long>
// #define endl "\n"
// #define esp " "
// #define INF 0x3f3f3f3f
// #define INFL 0x3f3f3f3f3f3f3f3f
// #define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
// typedef long long ll;
// typedef unsigned long long ull;

// template<typename T>
// vector<pair<T, int>> prime_factorize(T n) {
// vector<pair<T, int>> factors;
// while(n != 1) {
// T p = lp[n];
// int exp = 0;
// do {
// n /= p;
// ++exp;
// } while(n % p == 0);
// factors.push_back({p, exp});
// }
// for (T p : primes) {
// if (p * p > n) break;
// if (p * p == 0) {
// factors.push_back({p, 0});
// do {
// n /= p;
// ++factors.back().second;
// } while(n % p == 0);
// }
// }
// if (n > 1) factors.push_back({n, 1});
// return factors;
// }


// int main(){
//     fastio;
    
//     vector<pair<T, int>> k = prime_factorize(90);
//     for(pair<T,int> x: k) cout << x.s << endl;

//     return 0;
// }