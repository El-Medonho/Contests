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

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

struct Hashing{
    ll n;
    ll m = 1e9+7;
    ll p = 31;
    string str;
    vector<ll> hh;
    vector<ll> pow;

    Hashing(string s){
        str = s;
        n = s.size();
        hh.resize(n+1,0);

        pow.resize(n+1,1);
        for(int i = 1; i <= n; i++){
            pow[i] = (pow[i-1]*p)%m;
        }

        for(int i = 1; i <= n; i++){
            hh[i] = (hh[i-1]*p)%m + (str[i-1]-'a'+1);
            hh[i] %= m;
        }
    }

    ll range(int l, int r){
        r++;
        return ((hh[r] - (hh[l]*pow[r-l]%m)) + m) % m;
    }
};

int main(){
    fastio;

    string bin, str; cin >> bin >> str;

    int zero = 0,one = 0;

    for(char c: bin){
        if(c == '1') one++;
        else zero++;
    }

    Hashing hs(str);

    int n = str.size();

    int ans = 0;

    for(int i = 1; i < n; i++){
        if(zero*i >= n) break;
        if((n-zero*i)%one != 0) continue;
        int j = (n-zero*i)/one;

        ll h0 = -1, h1 = -1;
        int pnt = 0;
        bool did = true;
        for(int k = 0; k < n;){
            if(bin[pnt] == '0'){
                if(h0 == -1){
                    h0 = hs.range(k,k+i-1);
                    k+=i;
                }
                else{
                    if(hs.range(k,k+i-1) != h0){
                        did = false;
                        break;
                    }
                    k+=i;
                }
            }
            else{
                if(h1 == -1){
                    h1 = hs.range(k,k+j-1);
                    k+=j;
                }
                else{
                    if(hs.range(k,k+j-1) != h1){
                        did = false;
                        break;
                    }
                    k+=j;
                }
            }
            pnt++;
        }
        if(did && !(i == j && h0 == h1)) ans++;

    }

    cout << ans << '\n';

    return 0;
}