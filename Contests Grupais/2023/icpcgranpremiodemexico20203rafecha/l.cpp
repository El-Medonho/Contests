#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
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

    int ans = 0;
    int n; cin >> n;

    vector<string> arr(n);

    for(string &s: arr) cin >> s;

    ans++;
    vector<string> gen(0); gen.pb(arr[0]);

    for(int i = 0; i < n; i++){
        bool create = true;
        string str = arr[i];
        for(string j: gen){

            if(str.size() != j.size()) continue;
            int sz = str.size();

            for(int pnt = 0; pnt < sz; pnt++){
                if(j[pnt] == str[0]){
                    int cnt = 0;
                    for(int k = mod(pnt,sz); cnt != sz; k = mod(k+1, sz)){
                        cnt++;
                        if(j[k] != str[mod(k-pnt, sz)]) break;
                        if(k == mod(pnt-1,sz)) create = false;

                    }
                }
                if(!create) break;
            }
            if(!create) break;
        }
        if(create){
            ans++;
            gen.pb(str);
        }
    }

    cout << ans << endl;

    return 0;
}