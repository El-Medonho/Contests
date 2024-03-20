#include <bits/stdc++.h>

#define mxn 200005
#define mxm 100005
#define pb push_back
#define f first
#define s second
#define vii vector<int>
#define vll vector<long long>
#define sz(x) (int)x.size()
#define es " "
#define endl "\n"
#define pii pair<long double,long double>
#define pip pair<long double, pii>
#define INF 0x3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
    int n, a ,b; cin >> n >> a >> b;
    ld l = 1/ld(b-a+1);
    ld rt = ld(b-a+1)/ld(b-a);
    int aog = a;
    if(a == 0) {l = 1/ld(b-a); a = 1;}

    int pntl = 0+a-b-1, pntr = 0, curr = a;
    vector<long double> dp(n+1,0);

    for(int i = 1; i < min(a,n+1); i++) dp[i] = 1;


    ld sum = 0;
    while(curr <= n){
        dp[curr] = 1 + sum*l;
        if(aog == 0) dp[curr] = rt + sum*l;
        pntl++; pntr++; curr++;
        sum += dp[pntr];
        if(pntl > -1) sum-= dp[pntl];
    }

    cout << setprecision(10) << dp[n] << endl;
}