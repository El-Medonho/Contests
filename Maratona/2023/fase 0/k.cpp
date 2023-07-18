#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define mxn (int) 1e5+5
#define mxm (int) 1e5+5
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
typedef pair<int, pii> pip;
typedef unsigned long long ull;

int q;

int main(){
    fastio;
    map<ll, pip> sla;

    for(ll i=0; i<=216; i++){
        for(ll j=i; j<=216; j++){
            for(ll k=j; k<=216; k++){
                ll is = i*i*i*i;
                ll js = j*j*j*j;
                ll ks = k*k*k*k;

                ll soma = is+js+ks;

                sla[soma]={i, {j, k}};
            }
        }
    }
    // cin >> q;
    // while(q--){
    //     int x;
    //     cin >> x;
    //     vector<array<int, 4> > resp;
    //     for(int i=0; i<=216; i++){
    //         ll is = i*i*i*i;
    //         if(x-is<0) continue;
    //         for(array<int, 3> j:sla[x-is]){
    //             resp.pb({i, j[0], j[1], j[2]});
    //         }
    //     }
    //     sort(all(resp));
    //     cout << sz(resp) << endl;
    //     for(array<int, 4> i:resp){
    //         cout << i[0] << es << i[1] << es << i[2] << es << i[3] << endl;
    //     }
    // }
    return 0;
}