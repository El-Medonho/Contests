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

    string str; cin >> str; int n = str.size();

    vii arr(9,0);

    for(int &i: arr) cin >> i;
    vii pos(n,0);

    vii mins(n,0);
    vii alf(9,0);
    for(int i = n-1; i >=0; i--){
        int gg = str[i]-'0';

        if(arr[gg-1]){
            mins[i] = ++alf[gg-1];
        }

    }

    for(int i = 0; i < n; i++){
        if(pos[i] == 1) continue;
        int best = str[i] - '0';
        vii curr = arr;
        
        for(int j = i; j < n; j++){
            if(pos[j]) continue;
            int gg = str[j] - '0';
            if(mins[j] == curr[gg-1]){
                if(curr[gg-1]){
                    arr[gg-1]--;
                    curr[gg-1]--;
                    pos[j] = 1; 
                    continue;
                }
            }
            best = max(gg, best);
            if(best == 9) break;

            if(curr[gg-1]){
                curr[gg-1]--;
            }else{
                break;
            }
        }

        if(best == str[i] - '0') continue;

        for(int j = i; j < n; j++){
            if(pos[j]) continue;
            int gg = str[j] - '0';
            if(gg == best) break;
            arr[gg-1]--;
            pos[j] = 1;
        }
    }

    vii ans(0);
    for(int i = 0; i < n; i++){
        if(!pos[i]) cout << str[i];
    }
    cout << endl;

    return 0;
}