#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<double> l(n), r(n);

    for(int i=0; i<n; i++) cin >> l[i];
    for(int i=0; i<n; i++) cin >> r[i];

    vector<double> a(n);

    double last = 0;
    a[0] = r[0];
    for(int i=1; i<n-1; i++){
        double menor = max(l[i], last);
        if(menor>r[i]){
            cout << "No" << endl;
            return 0;
        }
        if(2*menor - a[i-1] < l[i+1]){
            menor = (l[i+1] + a[i-1]) / 2;
            menor = min(menor, r[i]);
        }
        last = 2*menor - a[i-1];
        a[i] = menor;
    }
    if(max(l[n-1], last)>r[n-1]){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    return 0;
}