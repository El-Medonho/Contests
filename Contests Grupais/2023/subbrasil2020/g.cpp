#include <bits/stdc++.h>

#define mxn 200005
#define mxm 100005
#define pb push_back
#define f first
#define s second
#define vii vector<int>
#define vll vector<long long>
#define sz(x) (int)x.size()
#define es " "
#define endl "\n"
#define pii pair<long double,long double>
#define pip pair<long double, pii>
#define INF 0x3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

using namespace std;

int main(){
    fastio;

    int c; cin >> c;
    vii arr(c);
    for(int &i: arr) cin >> i;
    int start  = 0;
    vii sum(c,0);
    int curr = 0;
    
    for(int i = 0; i < c; i++) { curr += arr[i]; sum[i] = curr;}
    sum.pb(0);
    
    sort(sum.begin(), sum.end());
    cout << *sum.rbegin() + 100 << endl;

    return 0;
}