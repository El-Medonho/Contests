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
        string s; cin >> s;
        if(s == "c" || s == "o" || s == "d"|| s == "e"|| s == "f"|| s == "r"|| s == "s") cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}