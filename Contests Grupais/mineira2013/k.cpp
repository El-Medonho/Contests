#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
typedef long long ll;

void upd(int ind, ll val, vector<ll> &bit){   //O(logn)
    while(ind<=bit.size()-1){
        bit[ind]+=val;
        ind+=ind&-ind;
    }
}
ll sum(int ind, vector<ll> &bit){         //O(logn)
    ll ans=0;
    while(ind){
        ans+=bit[ind];    
        ind-=ind&-ind;    
    }
    return ans;
}

int main(){
    fastio;

    vector<ll> bit(1e6+50,0);

    while(true){
        int n;
        cin >> n;
        if(n == 0) break;

        queue<char> s;
        queue<pair<pair<int,int>,int>> kl; 
        while(n > 0){
            int op;
            cin >> op; n--;

            if(op == 18) {
                int a,b,k; n-=3;
                cin >> a >> b >> k;
                kl.push({{a,b},k});
                upd(a+1,k,bit);
                upd(b+2,-k,bit);
            }else if(op == 42) {
                int p; cin >> p; n--;
                int a = sum(p+1,bit);
                int b = sum(p,bit);
                if(a-b < 0) {
                    s.push(' ');
                }else {
                    char c = 'A'+((a-b)%26);
                    // cout << c << '\n';
                    s.push(c);
                }
            }
            else {
                cout << "MENSAGEM: [";
                while(!s.empty()) {
                    cout << s.front();
                    s.pop();
                }
                cout << "]\n";
                int x;
                while(n--) cin >> x;
            }
            // cout << s << '\n';
        }
        while(!kl.empty()){
            int a = kl.front().first.first, b = kl.front().first.second, c = kl.front().second;kl.pop();
            upd(a+1,-c,bit);
            upd(b+2,c,bit);
        }
    }

    // int cv; while(cin >> cv){}

    return 0;
}