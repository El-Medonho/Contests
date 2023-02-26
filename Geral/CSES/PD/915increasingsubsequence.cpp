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

void upd(int x, int val, vii &bit){   //O(logn)
    while(x<=bit.size()-1){
        bit[x] = max(val, bit[x]);
        x+=x&-x;
    }
}
int sum(int x, vii &bit){         //O(logn)
    int ans=0;
    while(x){
        ans = max(bit[x], ans);    
        x-=x&-x;    
    }
    return ans;
}

int main(){
    fastio;

    map<int,int> coor;

    int n; cin >> n;
    vii arr(n);
    for(int &i: arr) cin >> i;

    set<int> arrs;
    for(int i: arr) arrs.insert(i);

    int ggg = 1;
    for(int i : arrs) coor[i] = ggg++;

    vii bit(ggg, 0);

    int ans = 0;

    for(int i: arr){
        int best = sum(coor[i]-1, bit); best++;   //coor[i]-1
        upd(coor[i], best, bit);
        ans = max(ans, best);
    }

    cout << ans << endl;

    

    return 0;
}