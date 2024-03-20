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

    int a,b,c; cin >> a >> b >> c; vii op(3,0);

    if(a >= 500) {a-=100; op[0]++;}
    if(b >= 500) {b-=100; op[1]++;}
    if(c >= 500) {c-=100; op[2]++;}

    if(!op[0] && !op[1] && a+b >= 500) {a-=100; op[0]++; op[1]++;}
    if(!op[0] && !op[2] && a+c >= 500) {a-=100; op[0]++; op[2]++;}
    if(!op[2] && !op[1] && c+b >= 500) {b-=100; op[2]++; op[1]++;}

    if(!op[0] && !op[1] && !op[2] && a+b+c >= 500) {a-=100; op[0]++; op[1]++;}

    cout << a + b + c << endl;

    return 0;
}