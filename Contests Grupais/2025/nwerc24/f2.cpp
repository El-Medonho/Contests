#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const int mxn = 1e5+5;

int n, q;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    cin >> n >> q;
    vector<ll> v(n+1), resp(n+1), nxt(n+1), real(n+1);
    for(int i=1; i<=n; i++){
        real[i] = i;
        cin >> v[i];
    }
    vector<pair<ll, int> > stack;
    for(int i=n; i>=1; i--){
        while(!stack.empty() && stack.back().first<v[i]){
            stack.pop_back();
        }
        if(stack.empty()) nxt[i] = -1;
        else nxt[i] = stack.back().second;
        stack.push_back({v[i], i});
    }
    while(q--){
        char t;
        cin >> t;
        if(t == '+'){
            ll i, x;
            cin >> i >> x;
            while(x && i!=-1){
                if(v[i] - resp[i]>0){
                    ll tira = min(v[i] - resp[i], x);
                    resp[i]+=tira;
                    x-=tira;
                }
                if(v[i] == resp[i]){
                    real[i] = nxt[i];
                    i = real[nxt[i]];
                }
            }
        }else{
            int i;
            cin >> i;
            cout << resp[i] << endl;
        }
    }
    
    return 0;
}