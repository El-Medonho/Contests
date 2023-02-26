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


ll n; 
vll arr(0);

int main(){
    fastio;

    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    int k = arr.size();
    if(k%2 == 0) k = (k/2);
    else k = k/2;

    int val = arr[k];
    ll sum = 0;
    for(int x: arr) sum += abs(x-val);
    cout << sum << endl;
    return 0;
}