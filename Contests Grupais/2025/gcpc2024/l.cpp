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

signed solve(){
    ll k; cin >> k;
    ll a,b,c; cin >> a >> b >> c;
    ll ab, bc, ac; cin >> ab >> bc >> ac;
    ll abc; cin >> abc;

    vector<int> perm = {0,1,2};

    ll best = 1e18;

    do{
        for(int m = 0; m < 8; m++){
            ll A = a, B = b, C = c;
            ll ABC = abc;

            for(int i = 0; i < 3; i++){
                if(perm[i] == 0){
                    if(m & 1){
                        ll AB = ab;
                        if(A%k){
                            ll d = min(AB, k-(A%k));
                            A += d;
                            AB -= d;
                        }
                        B += AB;
                    }
                    else{
                        ll AB = ab;
                        if(B%k){
                            ll d = min(AB, k-(B%k));
                            B += d;
                            AB -= d;
                        }
                        A += AB;
                    }
                }
                if(perm[i] == 1){
                    if(m & 2){
                        ll AC = ac;
                        if(A%k){
                            ll d = min(AC, k-(A%k));
                            A += d;
                            AC -= d;
                        }
                        C += AC;
                    }
                    else{
                        ll AC = ac;
                        if(C%k){
                            ll d = min(AC, k-(C%k));
                            C += d;
                            AC -= d;
                        }
                        A += AC;
                    }
                }
                if(perm[i] == 2){
                    if(m & 4){
                        ll BC = bc;
                        if(B%k){
                            ll d = min(BC, k-(B%k));
                            B += d;
                            BC -= d;
                        }
                        C += BC;
                    }
                    else{
                        ll BC = bc;
                        if(C%k){
                            ll d = min(BC, k-(C%k));
                            C += d;
                            BC -= d;
                        }
                        B += BC;
                    }
                }
            }

            if(A%k){
                ll d = min(ABC, k-(A%k));
                A += d;
                ABC -= d;
            }
            if(B%k){
                ll d = min(ABC, k-(B%k));
                B += d;
                ABC -= d;
            }
            
            C += ABC;

            ll cans = 0;
            cans += (A+k-1)/k; cans += (B+k-1)/k; cans += (C+k-1)/k;
            best = min(best, cans);
        }
    }

    while(next_permutation(perm.begin(), perm.end()));

    cout << best << '\n';

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}