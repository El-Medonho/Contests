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

    while(n--){
        int x; cin >> x;
        int ans = 0;
        int h = sqrt(double(x));

        for(int i = 1; i < sqrt(double(x)); i++){
            if(x%i == 0) ans++;
        }
        ans*=2;
        if(h*h == x) ans++;
        cout << ans << endl;
    }

    return 0;
}