#include "bits/stdc++.h"
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

int main(){
    fastio;

    int n,m,k; cin >> n >> m >> k;
    vector<int> pessoas(n), apes(m);
    for(int i = 0; i < n; i++) cin >> pessoas[i];
    for(int i = 0; i < m; i++) cin >> apes[i];
    
    sort(apes.begin(), apes.end());
    sort(pessoas.begin(), pessoas.end());

    int enum1 = 0, enum2 = 0;
    int ans = 0;

    while(enum1 != n && enum2 != m){
        if(abs(pessoas[enum1] - apes[enum2]) <= k){
            ans++;
            enum1++; enum2++;
        }
        else if(pessoas[enum1] > apes[enum2]) enum2++;
        else enum1++;
    }

    cout << ans << endl;

    return 0;
}