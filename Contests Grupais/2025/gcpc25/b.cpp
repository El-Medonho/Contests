#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(500, 1e8);

void upd(int x, ll val, vector<ll>&bit){
    for(; x < bit.size(); x+=x&-x) bit[x] += val;
}

ll sum(int x, vector<ll>&bit){
    ll ans =0;
    for(; x; x-=x&-x) ans += bit[x];
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll n,b,arrival,w; cin >> n >> b >> arrival >> w;
    
    vector<ll> dist(b, 0);
    
    for(int i = 0; i < b; i++){
        cin >> dist[i];
        if(i) dist[i] += dist[i-1];
    }
    
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i]; arr[i]--;
    }
    
    ll l = 0, r = 2e18;
    ll ans = 2e18+5;
    
    while(l <= r){
        ll md = (l+r)/2;
        
        vector<ll> guys(1e6+50, 0), stops(1e6+50, 0);
        vector<int> freq(1e6+50, 0);
        bool ok = true;
        ll cost = 0, cnt = 0;
        ll base = 0;
        ll ini = 0, mx = 0;
        for(int i = 0; i < n; i++){
            ll x = arr[i]; x++;
            if(freq[x] == 0) {
                cost += (sum(1e6+5, guys)-sum(x, guys)) * 2;   // adiciona caras que vao parar em mim
                upd(x, 1, stops);
            }
            freq[x] = 1;
            cost += sum(x-1, stops) * 2 + 2;  // adiciona lugares onde vou parar
            upd(x, 1, guys);
            mx = max(mx, x);
            // cout << cost * w + dist[mx-1] + base << endl;
            if(cost*w + dist[mx-1] + base <= md) {
                continue;
            }

            // se eu não couber, reseto o array
            cnt++;
            cost = 0; base = cnt * arrival;
            for(int j = ini; j <= i; j++){
                x = arr[j]; x++;
                if(freq[x]) upd(x, -1, stops);
                freq[x] = 0;
                upd(x, -1, guys);
            }
            ini = i; mx = 0;

            // atualizo eu entrando
            x = arr[i]; x++;
            if(freq[x] == 0) {
                cost += (sum(1e6+5, guys)-sum(x, guys)) * 2;   // adiciona caras que vao parar em mim
                upd(x, 1, stops);
            }
            freq[x] = 1;
            cost += sum(x-1, stops) * 2 + 2;  // adiciona lugares onde vou parar
            upd(x, 1, guys);
            mx = max(mx, x);

            // testo se eu sozinho consigo entrar, senao nao consigo formar resposta
            if(cost*w + dist[mx-1] + base > md) {
                ok = false;
                break;
            }
        }

        if(!ok){
            l = md+1;
        }
        else {
            r = md-1;
            ans = md;
        }
    }

    cout << ans << '\n';

    return 0;
}