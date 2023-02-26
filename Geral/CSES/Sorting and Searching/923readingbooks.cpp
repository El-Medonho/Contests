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
    vii arr(n);
    for(int &x: arr) cin >> x;
    sort(arr.begin(), arr.end());

    if(arr.size() == 1) {cout << arr[0]*2 << endl; return 0;}

    ll maior = *arr.rbegin(), menores = 0;
    for(int i = 0; i < n-1; i++){
        menores += arr[i];
    }
    if(maior >= menores) cout << 2*maior << endl;
    else cout << menores+maior << endl;

    return 0;
}