#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mxn = 1e5+5;

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n = 10000;

    int tg = n*n;

    vector<int> arr(tg);

    for(int i = 0; i < tg; i++) arr[i] = i;

    shuffle(arr.begin(), arr.end(), rng);

    // set<int> st;

    int mx = -1;

    int i = 0;

    for(;i < tg; i++){
        int h = arr[i];

        // cout << "? " << (h/n) + 1 << ' ' << (h%n) + 1 << endl;
        // cout.flush();



        // int x = (h == 19);

        if(h == 19) break;
    }

    cout << tg << "! " << i << endl;

    return 0;
}