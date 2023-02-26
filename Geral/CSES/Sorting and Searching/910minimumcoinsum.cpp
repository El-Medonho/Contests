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
    vll sum(n); 
    ll sums = 0;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++){
        sums += arr[i];
        sum[i] = sums;
    }

    if(arr[0] != 1) { cout << 1 << endl; return 0;}

    int last = arr[0];

    for(int i = 0; i < n; i++){
        int curr = arr[i];
        if(last != curr){
            if(sum[i-1] < curr-1) {cout << sum[i-1]+1 << endl; return 0;}
        }
    }

    cout << sum[n-1]+1 << endl;

    return 0;
}