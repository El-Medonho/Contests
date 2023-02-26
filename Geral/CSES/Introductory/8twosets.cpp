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

    int n; cin >> n;
    set<int> prim,seg;
    ll sum1 = 0, sum2 = 0;

    for(int i = n; i > 0; i--){
        if(sum1 > sum2){
            sum2 += i;
            seg.insert(i);
        }
        else{
            sum1 += i;
            prim.insert(i);
        }
    }

    // cout << sum1 << esp << sum2 << endl;

    if(sum1 != sum2){cout << "NO" << endl; return 0;}

    cout << "YES" << endl;
    cout << prim.size() << endl;
    for(int x: prim) cout << x << esp;
    cout << endl;
    cout << seg.size() << endl;
    for(int x: seg) cout << x << esp;
    cout << endl;

    return 0;
}