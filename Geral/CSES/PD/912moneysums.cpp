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
    vii dp(1e5+1, 0);
    vii arr(n);

    for(int &i: arr) {cin >> i;}
    dp[0] = 1;

    for(int j: arr){
        for(int i = 1e5; i >= 0; i--){
            if(dp[i] == 1) dp[i+j] = 1;
        }
    }

    set<int> nums;
    for(int i = 1; i < 1e5+1; i++) if(dp[i] == 1) nums.insert(i);

    cout << nums.size() << endl;
    for(int x: nums) cout << x << esp;
    cout << endl;


    return 0;
}