#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define mod(x, m) (((x%m)+m)%m)
#define mxn 10005
#define mxm 100
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
typedef pair<string, int> pii;
typedef pair<int, pii> pip;

int n, c, pos[mxn], ans=1, cont;
vector<string> v;
set<pii> sla;

int main(){
    fastio;
    cin >> n >> c;
    for(int i=0; i<n; i++){
        string a;
        cin >> a;
        for(int j=0; j<c; j++){
            if(a[j]=='*') pos[i]=j;
        }
        v.pb(a);
    }
    for(int i=0; i<n; i++){
        string a=v[i];
        for(char u='a'; u<='z'; u++){
            a[pos[i]]=u;
            auto it=sla.lower_bound({a, -INF});
            if(it!=sla.end() && (*it).f==a){
                pii agr=*it;
                ans=max(ans, agr.s+1);
                sla.erase(it);
                sla.insert({agr.f, agr.s+1});
            }else{
                sla.insert({a, 1});
            }
            
        }
    }
    for(pii i:sla){
        if(i.s==ans){
            cout << i.f << es << ans << endl;
            return 0;
        }
    }
    return 0;
}