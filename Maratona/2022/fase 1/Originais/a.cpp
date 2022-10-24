#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define mod(x, m) (((x%m)+m)%m)
#define mxn 100
#define mxm 100
#define f first
#define s second
#define pb push_back
#define es " "
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define sz(x) (int)x.size()
#define all(x) x.begin)(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

int main(){
    fastio;
    int n ;
    cin >> n;
    string str;
    cin >> str;
    bool reset = true;
    int reoccur = 0;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        if (str[i] == 'b') {
            reset = true;
            reoccur = 0;
        }
        if(str[i] == 'a') {
            if(reoccur > 1) ans += 1;
            else if(reoccur == 1) {
                ans += 2;
                reoccur += 1;
            }else {
                reoccur += 1;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}