#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

const int INF = 0x3f3f3f3f;

const int mxn = (1<<20) + 5;

int n, bit[mxn];

void upd(int x, int val){
    for(; x<=n; x+=x&-x) bit[x] += val;
}

int sum(int x){
    int ans = 0;
    for(; x; x-=x&-x) ans += bit[x];
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;

    vector<ll> a(n);
    vector<ll> d(n);

    for(int i=0; i<n; i++){
        cin >> a[i] >> d[i];
    }

    ll lA, rA, lD, rD;
    cin >> lA >> lD >> rA >> rD;

    int mid = n/2;

    vector<pair<ll, ll> > v1, v2;
    vector<ll> allA, allD;

    allA.push_back(lA), allA.push_back(rA);
    allD.push_back(lD), allD.push_back(rD);

    for(int mask = 0; mask < (1<<mid); mask++){
        ll somaA = 0, somaD = 0;
        for(int i=0; i<mid; i++){
            if(mask & (1<<i)){
                somaA += a[i];
                somaD += d[i];
            }
        }
        allA.push_back(somaA);
        allD.push_back(somaD);
        v1.push_back({somaD, somaA});
    }

    int lastMid = mid;
    if(n&1) mid++;

    for(int mask = 0; mask < (1<<mid); mask++){
        ll somaA = 0, somaD = 0;
        for(int i=0; i<mid; i++){
            if(mask & (1<<i)){
                somaA += a[i+lastMid];
                somaD += d[i+lastMid];
            }
        }
        allA.push_back(somaA);
        allD.push_back(somaD);
        v2.push_back({somaD, somaA});
    }

    sort(allA.begin(), allA.end());
    sort(allD.begin(), allD.end());
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    allA.erase(unique(allA.begin(), allA.end()), allA.end());
    allD.erase(unique(allD.begin(), allD.end()), allD.end());

    n = allA.size();
    
    for(auto &[d, a]:v1){
        a = lower_bound(allA.begin(), allA.end(), a) - allA.begin();
        //d = lower_bound(allD.begin(), allD.end(), d) - allD.begin();
    }

    for(auto &[d, a]:v2){
        //a = lower_bound(allA.begin(), allA.end(), a) - allA.begin();
        //d = lower_bound(allD.begin(), allD.end(), d) - allD.begin();
    }

    int l = INF, r = -INF;
    ll resp = 0;
    for(auto [d, a]:v2){
        ll nL = lD - d;
        ll nR = rD - d;

        pair<ll, ll> temp1 = {nL, -INF}, temp2 = {nR, INF};

        auto it = lower_bound(v1.begin(), v1.end(), temp1);
        auto it2 = upper_bound(v1.begin(), v1.end(), temp2);

        if(it2 != v1.begin()){
            it2--;
            int posL = it - v1.begin();
            int posR = it2 - v1.begin();

            if(l == INF && r == -INF){
                for(int i = posL; i<=posR; i++){
                    upd(v1[i].second+1, 1);
                }
                l = posL, r = posR;
            } else {
                while(l > posL){
                    l--;
                    upd(v1[l].second+1, 1);
                }
                while(r > posR){
                    upd(v1[r].second+1, -1);
                    r--;
                }
            }

            ll limLA = lA - a;
            ll limRA = rA - a;

            auto it = lower_bound(allA.begin(), allA.end(), limLA);
            auto it2 = upper_bound(allA.begin(), allA.end(), limRA);

            if(it2 != allA.begin()){
                it2--;

                int posLA = it - allA.begin();
                int posRA = it2 - allA.begin();

                resp += sum(posRA+1);
                if(posLA) resp -= sum(posLA);
            }
        }
    }
    cout << resp << endl;
    return 0;
}