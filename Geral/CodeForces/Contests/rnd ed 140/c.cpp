#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define MOD 998244353
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
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

int solve(){

    int n; cin >> n;

    vector<vii> res(n, vii(n,0));

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int a; cin >> a; res[i][j] = a;
        }
    }

    for(int i = 0; i < n; i++){
        if(res[i][i] == 2){     //retorna 0
            cout << 0 << endl;
            return 0;
        }
    }

    for(int i = 0; i < n; i++){
        bool hastwo = false;
        for(int j = i; j < n; j++){
            if(res[i][j] == 2) hastwo = true;
            if(hastwo && res[i][j] == 1){       //retorna 0
                cout << 0 << endl;
                return 0;
            }
        }
    }

    vii str(n,0);
    int cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(res[j][i] == 1){
                int atual = 0;
                set<int> ad;
                for(int k = j; k <= i; k++){
                    if(str[k] != 0) ad.insert(str[k]);
                    atual = max(str[k], atual);
                }

                if(atual == 0) atual = ++cnt;

                for(int k = 0; k <= i; k++){
                    if(ad.find(str[k]) != ad.end()) str[k] = atual;
                }

                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(str[i] == 0) str[i] = ++cnt;
    }

    vll dp(n,0);
    pii interval;

    int beg = -1, fin = -1;
    for(int i = 0; i < n; i = interval.s+1){
        
        int gh = str[i];
        interval = {i,0};
        for(int j = i; j < n; j++) if(str[j] == gh) interval.s = j;

        for(int j = i; j <= interval.s; j++){
            for(int k = j; k <= interval.s; k++) if(res[j][k] == 2){
                cout << 0 << endl;
                return 0;
            }
        }

        for(int j = i-1; j >= beg+1 && fin != interval.s; j--){
            for(int k = i; k <= inetrval.s; k++){
                if(res[j][k] != 2) continue;

                int ll = 0, count = 0;
                for(int l = max(j, fin+1); l <= k; l++){
                    if(str[l] != ll) count++; 
                    ll = str[l];
                }

                fin = interval.s;


            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = i; j < n; j++){
    //         if(res[i][j] == 2){

    //             for(int k = i; k <= j; k++){
    //                 for(int l = k; l <= j; l++){
    //                     if(k == i && l == j) continue;
    //                     if(res[k][l] == 2) res[i][j] = 0;
    //                 }
    //             }
    //             if(res[i][j] == 0) continue;

    //             int last = 0, qtt = 0;
    //             for(int k = i; k <= j; k++){
    //                 if(str[k] != last) qtt++;
    //                 last = str[k];
    //             }

    //             if(qtt == 1){
    //                 cout << 0 << endl;
    //                 return 0;
    //             }

    //             ll hh = 1;
    //             for(int i = 0; i < cnt - qtt; i++) hh = mod(ans*2, MOD);
    //             ans = mod(ans-(2*(hh)), MOD);
    //         }
    //         else continue;
    //     }
    // }

    // cout << ans << endl;

    return 0;
}

int main(){
    fastio;

    int t = 1;
    while(t--){
        solve();
    }    

    return 0;
}