#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const int mxn = 1e5+5;

ll expo(ll b, ll e, ll m){
    ll resp = 1;
    while(e){
        if(e&1) resp = resp*b%m;
        b = b*b%m;
        e>>=1;
    }
    return resp;
}

int main(){

    ll n,k; cin >> n >> k;

    string s; cin >> s;

    vector<vector<int>> bl(70, vector<int>(n, -1));

    ll pot = expo(2, k, n);

    ll sum = 0;

    string ans(n, 'a');

    for(int i = 0; i < n; i++){
        ans[i] = s[sum];
        sum += pot; sum %= n;
    }

    cout << ans << endl;



    return 0;
}