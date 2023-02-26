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

    int h,m; cin >> h >> m;
    while(h%10>=6) {h++; m = 0;}
    if(m > 39 && h/10 == 2) {m = 0; h = mod(h+1, 24);}
    m%=60;
    while(h%10>=6) {h++; m = 0;}
    cout << h << esp << m << endl;

    return 0;
}