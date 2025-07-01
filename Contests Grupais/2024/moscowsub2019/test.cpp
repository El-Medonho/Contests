#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mxn = 3e5+5;

int n, bit[mxn][2]; // 0 abre e 1 fecha

void upd(int x, int val, int t){
    for(; x<=n; x+=x&-x) bit[x][t]+=val;
}

int sum(int x, int t){
    int ans = 0;
    for(; x; x-=x&-x) ans += bit[x][t];
    return ans;
}

int lower(int val, int t){
    int sum = 0, pos = 0;
    for(int i=19; i>=0; i--){
        int newpos = pos + (1<<i);
        if(newpos<=n && sum+bit[newpos][t]<val){
            sum += bit[newpos][t];
            pos = newpos;
        }
    }
    return pos + 1;
}

signed solve(){

    int q;
    cin >> n >> q;

    vector<char> v(n+1);

    for(int i=1; i<=n; i++){
        char x;
        cin >> x;
        v[i] = x;
        if(x=='('){
            upd(i, 1, 0);
        }else{
            upd(i, 1, 1);
        }
    }

    cout << lower(n+1, 0) << endl;

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