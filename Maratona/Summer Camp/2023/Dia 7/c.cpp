#include "bits/stdc++.h"
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

using namespace std;
using ll = long long;

int main() {
    fastio;

    ll t;
    cin >> t;

    while(t--) {
        ll n, k, x, y;
        cin >> n >> k >> x >> y;

        priority_queue<ll> A, B;

        for(ll i = 0, fi; i < n; i++) {
            char ti;
            cin >> ti >> fi;
            if(ti == 'A') A.push(fi);
            else B.push(fi);
        }

        vector<ll> TA, TB;

        while(!A.empty() && TA.size() < k) {
            TA.push_back(A.top());
            A.pop();
        }

        while(!B.empty() && TB.size() < k) {
            TB.push_back(B.top());
            B.pop();
        }

        while(TA.size() < k) {
            TA.push_back(B.top()-y);
            B.pop();
        }

        while(TB.size() < k) {
            TB.push_back(A.top()-x);
            A.pop();
        }


        sort(TA.begin(), TA.end());
        sort(TB.begin(), TB.end());

        ll i = 0;

        while(!B.empty() && i < k) {
            if(B.top() - y > TA[i]) {
                TA[i] = B.top()- y;
                B.pop();
            }else {
                break;
            }

            i++;
        }

        i = 0;

        while(!A.empty() && i < k) {

            if(A.top() - x > TB[i]) {
                TB[i] = A.top() - x;
                A.pop();
            }else {
                break;
            }

            i++;
        }

        ll ans = 0;

        for(ll wow : TA) ans += wow;
        for(ll wow : TB) ans += wow;
        
        cout << ans << '\n';
    }
}