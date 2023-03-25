#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;

int main(){
    fastio;

    int n; cin >> n;

    vii arr(n);
    for(int &i: arr) cin >> i;

    vii occur(1e6+5, 0);

    int ans = 1;
    for(int i = 0; i < n; i++){
        int curr = arr[i];

        int gg = int(sqrt(double(curr)));
        long double comp = sqrt(double(curr));
        for(int j = 1; j < comp; j++){
            if(curr%j == 0){
                int h = curr/j;
                if(occur[j]) ans = max(ans,j);
                else occur[j]++;
                if(occur[h]) {ans = max(ans,h); break;}
                else occur[h]++;
            }
        }
        if(gg*gg == curr){
            if(occur[gg]) ans = max(ans, gg);
            occur[gg]++;
        }
    }

    cout << ans << endl;

    return 0;
}