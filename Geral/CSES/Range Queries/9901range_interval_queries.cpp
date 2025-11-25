// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄
 
#include "bits/stdc++.h"
 
using namespace std;
 
#define endl '\n'

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

set<int> st;
 
 
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
    int n; cin >> n;
    int q; cin >> q;
 
    vector<int> arr(n);
    for(int &i: arr) cin >> i;

    vector<pair<int,int>> sarr(n);

    for(int i = 0; i < n; i++){
        sarr[i] = {arr[i], i};
    }
    sort(sarr.begin(), sarr.end());

    vector<pair<int,int>> qu(2*q);
    vector<int> ans(q, -1);
    map<int, vector<int>> indices;
 
    for(int i = 0; i < q; i++){
        int a,b; cin >> a >> b;
        int c,d; cin >> c >> d; c--;
        
        qu[2*i] = {a, b};
        qu[2*i+1] = {c, d};
        st.insert(c); st.insert(d);
        indices[c].push_back(i);
        indices[d].push_back(i);
    }

    queue<int> qw; for(int x: st) qw.push(x);

    vector<ll> bit(n+5, 0);

    for(auto[a, b]: sarr){
        while(!qw.empty() && qw.front() < a){
            int cc = qw.front(); qw.pop();
            for(int i: indices[cc]){
                auto[a, b] = qu[i*2];
                int s1 = sum(a-1, bit);
                int s2 = sum(b, bit);
                int s = s2-s1;

                if(ans[i] == -1) ans[i] = s;
                else ans[i] = abs(ans[i]-s);
            }
        }

        upd(b+1, 1, bit);
    }

    while(!qw.empty()){
            int cc = qw.front(); qw.pop();
            for(int i: indices[cc]){
                auto[a, b] = qu[i*2];
                int s1 = sum(a-1, bit);
                int s2 = sum(b, bit);
                int s = s2-s1;

                if(ans[i] == -1) ans[i] = s;
                else ans[i] = abs(ans[i]-s);
            }
        }

    for(int x: ans) cout << x << endl;
 
    return 0;
}