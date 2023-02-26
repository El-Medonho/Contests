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
    int ans=-1;
    while(x){
        ans = max(bit[x], ans);    
        x-=x&-x;    
    }
    return ans;
}

int main(){
    fastio;

    int n; cin >> n;
    vii arr(n); vii bit(n+1, -1);
    set<int> st; map<int,int> ind;
    for(int &x: arr) {cin >> x; st.insert(x);}

    int jjj = 1;
    for(int i: st){
        ind[i] = jjj;
        jjj++;
    }

    for(int i = 0; i < n-1; i++){
        upd(ind[arr[i]]+1, i, bit);
        cout << sum(ind[arr[i]], bit)+1 << esp;
    }
    cout << sum(ind[arr[n-1]], bit)+1 << endl;

    return 0;
}