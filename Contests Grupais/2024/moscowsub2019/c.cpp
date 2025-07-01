#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mxn = 1e6+5;

int used[mxn], version;

int mex(){
    for(int i=0; ; i++) if(used[i]!=version) return i;
}

signed solve(){

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    int l = 0, r = k, resp = k;

    while(l<=r){
        int mid = (l+r)>>1;

        int cont = 1;

        used[v[0]]=++version;

        if(mex()>=mid){
            l = mid+1;
            continue;
        }

        for(int i=1; i<n; i++){
            used[v[i]]=version;
            if(mex()>=mid){
                cont++;
                used[v[i]] = ++version;

                if(mex()>=mid){
                    cont = k+1;
                    break;
                }
            }
        }
        if(cont<=k){
            resp = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << resp << endl;
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}