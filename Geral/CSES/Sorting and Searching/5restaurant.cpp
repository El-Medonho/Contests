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
    vii in(n), out(n);
    for(int i = 0; i < n; i++) cin >> in[i] >> out[i];
    sort(in.begin(), in.end());
    sort(out.begin(), out.end());

    int pnt1 = 0, pnt2 = 0;
    int maxi = 0;
    int curr = 0;
    while(pnt1 != n && pnt2 != n){
        if(in[pnt1] < out[pnt2]) {curr++; pnt1++;}
        else {curr--; pnt2++;}
        maxi = max(maxi, curr);
    }
    cout << maxi << endl;

    return 0;
}