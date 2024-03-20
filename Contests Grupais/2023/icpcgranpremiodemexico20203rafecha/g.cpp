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

int n;
vll gold;
vector<pii> bound;

vll tree(0); vll arr(0);
int sti = 0;

void initialize(){
    arr = gold;
    int iterador = 1;
    while(iterador < arr.size()) iterador *= 2;
    sti = iterador;
    iterador*=2;
    tree.resize(iterador, 0);     //value of every node should be neutral value of op when itilializing

    for(int i = sti; i < sti*2; i++){
        int l = (i-sti);
        if(l < arr.size()) tree[i] = arr[l];
    }
 
    for(int i = sti/2; i > 0; i/=2){
        for(int j = i; j < i*2; j++){
            tree[j] = max(tree[2*j], tree[2*j+1]);      //op
        }
    }
}

void upd(int id, ll val){
    arr[id] += val;
    id += sti;
    tree[id] += val;
    for(int i = id/2; i > 0; i/=2) tree[i] = max(tree[2*i], tree[2*i+1]);       //op
}

ll query(int lo, int hi) {
	ll ra = -INFL, rb = -INFL;      //value
	for (lo += sti, hi += sti + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1) ra = max(ra, tree[lo++]);       //op
		if (hi & 1) rb = max(rb, tree[--hi]);       //op
	}
	return max(ra, rb);     //op
}


int main(){
    fastio;

    cin >> n;
    
    gold.resize(n); bound.resize(n);
    for(int i = 0; i < n; i++){
        ll g,a,b; cin >> g >> a >> b;
        gold[i] = g;
        bound[i] = {a,b};
    }

    initialize();

    ll ans = 0;

    for(int i = n-1; i >=0; i--){
        int a = bound[i].f+i, b = bound[i].s+i;
        if(a >= n) continue;
        else{
            upd(i, query(a, min(b,n-1)));
        }
    }

    for(ll i: arr) ans = max(ans,i);

    cout << ans << endl;


    return 0;
}