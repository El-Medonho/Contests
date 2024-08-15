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

vector<int> lp(1e7+2, 0);

vector<int> crivo(int n){
    vector<int> primes;
    for(int i = 2; i * i <= n; i++){
        if(!lp[i]){
            lp[i]=i;
            primes.push_back(i);
        }
        for(int p: primes){
            if(i > n / p) break;
            lp[i * p] = p;
            if(i % p == 0) break;
        }
    }
    return primes;
}

vector<int> primes;
vector<int> freqa(1e7+2, 0);

signed solve(){

    int a,b; cin >> a >> b;

    if(a < b) swap(a,b);

    if(b == 0){

        if(a == 0){
            cout << 0 << endl;
            return 0;
        }


        vector<int> p(0);

        for(int i: primes){
            if(i*i > a) break;
            if(a%i == 0) p.push_back(i);
            while(a%i == 0) {freqa[i]++; a /= i;}
        }

        if(a > 1){freqa[a]++; p.push_back(a);}
        
        ll h = 1, ans = 0;

        for(int j = p.size()-1; j > -1; j--){
            if(p[j] == 2) break;
            h *= (freqa[p[j]]+1);
        }

        ans += h;

        cout << ans << endl;

        for(int i: p) freqa[i] = 0;

        return 0;
    }

    if(a == b){
        cout << 0 << endl;
        return 0;
    }

    vector<int> p(0);

    while(a%2 == 0 && b%2 == 0) {a/=2; b/=2;}

    if(a%2 == b%2){
        cout << 0 << endl;
        return 0;
    }
    
    for(int i: primes){
        if(i*i > a && i*i > b) break;
        if(a%i == 0 && b%i == 0) p.push_back(i);
        while(a%i == 0 && b%i == 0) {freqa[i]++; a /= i; b/= i;}
        while(a%i == 0) a/= i;
        while(b%i == 0) b/= i;
    }

    if(a == b && a > 1){
        p.push_back(a);
        freqa[a]++;
    }

    ll h = 1, ans = 0;

    for(int j = p.size()-1; j > -1; j--){
        if(p[j] == 2) break;
        h *= (freqa[p[j]]+1);
    }

    ans = h;

    cout << ans << endl;


    for(int i: p) freqa[i] = 0;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    primes = crivo(1e7);

    int t; cin >> t;
    while(t--) solve();


    return 0;
}