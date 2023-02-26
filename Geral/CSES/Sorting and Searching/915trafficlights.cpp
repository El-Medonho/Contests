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

    int x,n; cin >> x >> n;
    set<int> line;
    multiset<int> dist; 
    dist.insert(x);
    line.insert(x); line.insert(0);

    for(int i; i < n; i++){
        int a; cin >> a;
        auto x = line.lower_bound(a);
        auto k = x;
        auto y = --k;
        // cout << *x << esp << a << esp << *y << endl;
        auto c = dist.lower_bound((*x) - (*y));
        dist.erase(c);
        line.insert(a);
        dist.insert((*x)-a); dist.insert(a-(*y));
        cout << *dist.rbegin() << endl;
    }

    return 0;
}