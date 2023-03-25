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

    int t; cin >> t;
    while(t--){
        int n,q; cin >> n >> q;
        vii arr(n);
        set<int> active;;
        for(int i = 0; i < n;i++){
            cin >> arr[i];
            active.emplace(i);
        }
        while(q--){
            int k; cin >> k;
            if(k == 2){
                int x; cin >> x; x--;
                cout << arr[x] << endl;
            }
            else{
                int l,r; cin >> l >> r; l--; r--;
                // cout << "oi" << endl;
                while(true){
                    auto curr = active.lower_bound(l);
                    if(curr != active.end() && *curr <= r){
                        l = *curr + 1;
                        int newcurr = arr[*curr];
                        int ans = 0;
                        while(newcurr/10!=0){
                            ans += newcurr%10;
                            newcurr/=10;
                        }
                        newcurr += ans;
                        arr[*curr] = newcurr; 
                        if(newcurr/10 == 0) active.erase(*curr);
                    }
                    else break;
                }
            }
        }
    }

    return 0;
}