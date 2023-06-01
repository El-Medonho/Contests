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

int main(){
    fastio;

    int n; cin >> n;

    // vector<ll> pos(n-1);

    // ll last = 0;
    // for(int i = 0; i < n; i++){
    //     ll a; cin >> a;
    //     if(i) pos[i-1] = a-last;
    //     last = a;
    // }

    vector<ll> pos(n);
    for(ll &i: pos) cin >> i;

    vector<ll> arr(n);
    for(ll &i: arr) cin >> i;

    if(n == 1){
        cout << arr[0] << '\n';
        return 0;
    }

    multiset<ll> mt;
    for(ll i: arr) mt.insert(i);

    vector<ll> ans(n,0);
    ll sum = 0, ind = 1;
    for(int i = 1; i < n; i++){
        if(i&1) {
            sum += pos[i]-pos[i-1];
            ans[i] = sum;
            if(ans[i] > ans[ind]) ind = i;
        }else{
            sum -= pos[i]-pos[i-1];
        }
    }

    bool done = true;

    vector<ll> alloc(n,0);
    alloc[ind] = (*mt.rbegin());
    mt.erase(mt.find(*mt.rbegin()));
    for(int i = ind+1; i < n; i++){
        ll dif = pos[i]-pos[i-1]-alloc[i-1];
        if(mt.find(dif) != mt.end()){
            alloc[i] = dif;
            mt.erase(mt.find(dif));
        }else{
            done = false;
            break;
        }
    }

    for(int i = ind-1; i > -1; i--){
        ll dif = pos[i+1]-pos[i]-alloc[i+1];
        if(mt.find(dif) != mt.end()){
            alloc[i] = dif;
            mt.erase(mt.find(dif));
        }else{
            done = false;
            break;
        }
    }

    if(done){
        for(ll i : alloc) cout << i << ' ';
        cout << '\n';
        return 0;
    }

    mt.clear();
    for(ll i: arr) mt.insert(i);
    sum = 0; ind = 0; ans[0] = pos[1]-pos[0];

    for(int i = 2; i < n; i++){
        if(!(i&1)){
            sum += pos[i]-pos[i-1];
            ans[i] = sum;
            if(ans[i] > ans[ind]) ind = i;
        }else{
            sum -= pos[i]-pos[i-1];
        }
    }

    done = true;

    alloc[ind] = (*mt.rbegin());
    mt.erase(mt.find(*mt.rbegin()));
    for(int i = ind+1; i < n; i++){
        ll dif = pos[i]-pos[i-1]-alloc[i-1];
        if(mt.find(dif) != mt.end()){
            alloc[i] = dif;
            mt.erase(mt.find(dif));
        }else{
            done = false;
            break;
        }
    }

    for(int i = ind-1; i > -1; i--){
        ll dif = pos[i+1]-pos[i]-alloc[i+1];
        if(mt.find(dif) != mt.end()){
            alloc[i] = dif;
            mt.erase(mt.find(dif));
        }else{
            done = false;
            break;
        }
    }

    if(done){
        for(ll i : alloc) cout << i << ' ';
        cout << '\n';
        return 0;
    }else{
        int k;
    }

    return 0;
}