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

    int n; cin >> n;

    vll pd(n+1,0);
    for(int i = 1; i < 7; i++) pd[i] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            pd[i] += pd[i-j];
            if(i-j == 0)break;
        }
        pd[i] = mod(pd[i], MOD);
    }

    cout << pd[n] << endl;
    return 0;
}