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

    int n,k; cin >> n >> k;
    vii arr(n,0);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(i>=k) arr[i-k] = a;
    }

    for(int i = 0; i < n-1; i++) cout << arr[i] << esp;
    cout << arr[n-1] << endl;

    return 0;
}