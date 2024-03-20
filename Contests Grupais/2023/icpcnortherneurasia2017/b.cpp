#include <bits/stdc++.h>
 
using namespace std;

#define f first
#define s second
#define pb push_back
#define es " "
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> pip;
typedef unsigned long long ull;
const int mxn = 1e5+5;
const int mxm = 1e5+5;
const int MOD = 1e9+7;

ll a, b, c, w, h;

int main(){
    fastio;
    cin >> a >> b >> c >> w >> h;

    vector<ll> perm;
    perm.pb(a);
    perm.pb(b);
    perm.pb(c);

    sort(all(perm));

    do{
        a = perm[0], b=perm[1], c=perm[2];
        if((h>=c+2*a && w>=2*a + 2*b) || (h>=2*a && w>=2*a + 2*b+c)){
            cout << "Yes" << endl;
            return 0;
        }
        swap(w,h);
        if((h>=c+2*a && w>=2*a + 2*b) || (h>=2*a && w>=2*a + 2*b+c)){
            cout << "Yes" << endl;
            return 0;
        }
        swap(w,h);
    }while(next_permutation(all(perm)));

    cout << "No" << endl;
    return 0;
}