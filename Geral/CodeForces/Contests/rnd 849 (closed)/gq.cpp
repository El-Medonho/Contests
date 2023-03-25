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

int main(){
    fastio;

    int t; cin >> t;
    while(t--){
        int n,c; cin >> n >> c;
        vii arr(n,0);
        for(int i = 0; i < n ; i++){
            cin >> arr[i];
            arr[i]+=i+1;
        }
        sort(arr.begin(), arr.end());
        int cnt = 0;
        int ans = 0;
        while(c > 0 && cnt < n){
            c -= arr[cnt++];
            ans++;
        }
        if(c < 0) ans--;
        cout << ans << endl;
    }

    return 0;
}