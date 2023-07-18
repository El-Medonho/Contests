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
typedef pair<pii, int> pip;
typedef unsigned long long ull;

int q;

int main(){
    fastio;
    unordered_map<ll, vector<pii> > sla;

    int t = 1000;

    while(t--){
        for(int i=0; i<=216; i++){
            for(int j=i; j<=216; j++){
                ll is = i*i*i*i;
                ll js = j*j*j*j;

                ll soma = is+js;

                sla[soma] = {make_pair(1,2)};
            }
        }
    }
    

    // cin >> q;

    // while(q--){
    //     ll x;
    //     cin >> x;

    //     vector<array<int, 4> > resp;

    //     for(int i=0; i<=216; i++){
    //         for(int j=i; j<=216; j++){
    //             ll is = i*i*i*i;
    //             ll js = j*j*j*j;

    //             ll soma = is+js;

    //             if(x-soma<0 || sla.find(x-soma) == sla.end()) continue;

    //             for(pii k:sla[x-soma]){
    //                 if(j<=k.f){
    //                     resp.pb({i, j, k.f, k.s});
    //                 }
    //             }
    //         }
    //     }
    //     cout << sz(resp) << endl;
    //     for(array<int, 4> i:resp){
    //         cout << i[0] << es << i[1] << es << i[2] << es << i[3] << endl;
    //     }
    // }
    return 0;
}