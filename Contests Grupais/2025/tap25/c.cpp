#include "bits/stdc++.h"

#define endl '\n'

using namespace std;

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> v(n), p(n);
    map<int, int> um, dois, tres, quatro, equal1, equal2;

    ll resp = 0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        v[i]--;

        //if(i-v[i]) resp += um[i-v[i]];
        resp += dois[i+v[i]];

        resp += tres[i+v[i]];
        //resp += quatro[i-v[i]];

        //cout << i << ' ' << resp << endl;

        //resp -= equal1[i-v[i]];
        
        //equal1[i-v[i]]++;

        um[i-v[i]]++;
        dois[i+v[i]+n]++;

        tres[i+v[i]]++;
        quatro[i-v[i]+n]++;
    }
    cout << 2*resp + n << endl;
    return 0;
}