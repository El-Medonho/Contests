#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const int mxn = 1e5+5;

int n, q;
ll bit[mxn];

void upd(int x, int val){
    for(; x<=n; x+=x&-x){
        bit[x]+=val;
    }
}

ll sum(int x){
    ll ans = 0;
    for(; x; x-=x&-x) ans += bit[x];
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr); 
    cin >> n >> q;
    vector<int> v(n+1), resp(n+1);
    vector<ll> prefix(n+1);
    set<int> nnfoi;
    for(int i=1; i<=n; i++){
        cin >> v[i];
        nnfoi.insert(i);
        prefix[i] = prefix[i-1] + v[i];
    }
    while(q--){
        char t;
        cin >> t;
        if(t == '+'){
            int i, x;
            cin >> i >> x;
            int l = i, r = n, ans = i;
            ll antes = sum(i-1);
            while(l<=r){
                int mid = (l+r)>>1;
                ll foi = sum(mid) - antes;
               // cout << foi << ' ' << mid << ' ' << l << ' ' << r << endl;
                if(prefix[mid] - prefix[i-1] - foi >= x){
                    ans = mid;
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
            ll resta = max(0LL, prefix[ans] - prefix[i-1] - sum(ans) - antes - x);
            cout << i << ' ' << ans << ' ' << resta << endl;

            auto it1 = nnfoi.lower_bound(i);
            auto it2 = nnfoi.lower_bound(ans);
            if(it2 != nnfoi.begin()){
                it2--;
                cout << *it1 << ' ' << *it2 << endl;
                vector<int> tira;
                for(auto it = it1; it!=it2; it++){
                    //cout << *it << endl;
                    upd(*it, v[*it]);
                    tira.push_back(*it);
                }
                for(int j:tira) nnfoi.erase(j);
            }
            upd(ans, -resp[ans]);
            resp[ans] = v[ans] - resta;
            upd(ans, resp[ans]);
        }else{
            int i;
            cin >> i;
            if(!nnfoi.count(i)){
                cout << v[i] << endl;
            }else{
                cout << resp[i] << endl;
            }
        }
    }
    
    return 0;
}