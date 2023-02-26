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

    int t; cin >> t;
    while(t--){
        vii a(4);
        for(int i = 0; i < 4; i++) cin >> a[i];
        if(a[0] < a[1] && a[2] < a[3] && a[0] < a[2] && a[1] < a[3]){cout << "YES" << endl; continue;}
        if(a[1] < a[3] && a[0] < a[2] && a[1] < a[0] && a[3] < a[2]){cout << "YES" << endl; continue;}
        if(a[3] < a[2] && a[1] < a[0] && a[2] < a[0] && a[3] < a[1]){cout << "YES" << endl; continue;}
        if(a[2] < a[0] && a[3] < a[1] && a[2] < a[3] && a[0] < a[1]){cout << "YES" << endl; continue;}
        cout << "NO" << endl;
    }

    return 0;
}