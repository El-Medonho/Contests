#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define mod(x, m) (((x%m)+m)%m)
#define mxn 500005
#define mxm 1000005
#define f first
#define s second
#define pb push_back
#define es " "
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define sz(x) (int)x.size()
#define all(x) x.begin)(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

int n, resp;
multiset<int> sla;

int main(){
    fastio;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        auto it=sla.upper_bound(x);
        if(it!=sla.end() && *it==x+1){
            sla.erase(it);
            sla.insert(*it-1);
        }else{
            sla.insert(x);
            resp++;
        }
    }
    cout << resp << endl;
    return 0;
}