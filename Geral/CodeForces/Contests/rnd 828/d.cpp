#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int exp(int b, int e){
    int res = 1;
    while(e){
        if(e&1) res *= b;
        b*=b;
        e >>= 1;
    }
    return res;
}

int main(){
    fastio;
    int t = 0; cin >> t;

    for (int g = 0; g < t; g++){
        int n = 0; cin >> n;
        int facts = 0;
        for (int i = 0; i < n; i++){
            int u = 0; cin >> u;
            while (u % 2 == 0){
                facts++; u /= 2;
            }
        }
        if (facts >= n) { cout << 0 << endl; continue;}
        int factorofn = 0;
        int nterms = n;
        vector<int> factors;
        while (nterms != 1){
            factorofn++;
            nterms /= 2;
            factors.push_back(nterms);
        }
        int defans = INF;
        int ans = 0;
        for(int i = factorofn; i > 0; i--){
            int currans = ans;
            for(int j = 0; j < (factors[i-1]-currans); j++){
                ans++;
                facts += i;
                if (facts >= n) defans = min(defans, ans);
            }
        }
        if (facts < n) cout << -1 << endl;
        else cout << defans << endl;
    }

    return 0;
}