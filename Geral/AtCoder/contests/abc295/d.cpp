//MEDONHO APENAS

#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
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

int main(){
    fastio;

    string s; cin >> s;

    int sz = 1;

    {
        int gg = 10;
        while(gg){
            gg--;
            sz<<=1;
        }
    }

    int mask = 0;
    vii memo(sz, 0);
    memo[0] = 1;

    ll ans = 0;

    for(char c: s){
        int curr = c-'0';
        mask ^= (1<<curr);

        ans += memo[mask];
        memo[mask]++;
    }

    cout << ans << endl;

    return 0;
}