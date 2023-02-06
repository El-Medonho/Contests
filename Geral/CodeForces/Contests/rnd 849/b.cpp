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
        int n; cin >> n;
        string s; cin >> s;
        pii point = {0,0};
        string ans = "NO";
        for(char x : s){
            if(x == 'U') point.s++;
            if(x == 'D') point.s--;
            if(x == 'L') point.f--;
            if(x == 'R') point.f++;
            if(point.f == 1 && point.s == 1) {ans = "Yes"; break;}
        }
        cout << ans << endl;
    }

    return 0;
}