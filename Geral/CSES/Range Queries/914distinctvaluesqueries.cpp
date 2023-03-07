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

vector<map<int,int>> tree(0); vll arr(0);
map<int,int> ans;

void build(int node, int l, int r){
    if(l == r){
        tree[node][arr[l]]++;
        return;
    }
    int mid = (l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    for(int x: tree[2*node]){
        tree[node][x] += tree[2*node][x];
    }
    
    for(int x: tree[2*node+1]){
        tree[node][x] += tree[2*node+1][x];
    }
}

void initialize(){
    int iterador = 1;
    while(iterador < arr.size()) iterador *= 2;
    iterador*=2;
    tree.resize(iterador);     //value of every node should be neutral value of op when itilializing
    build(1, 0, arr.size() - 1);
}

void upd(int node, int l, int r, int id, int val){
    if(l == r){
        tree[node].erase(arr[l]);
        tree[node][val]++;
        arr[l] = val;
        return;
    }

    tree[node][arr[l]]--;
    if(tree[node][arr[l]] == 0) tree[node].erase(arr[l]);
    tree[node][val]++;

    int mid = (l+r)>>1;
    if(l <= id && id <= mid){
        upd(2*node, l, mid, id, val);
    } else{
        upd(2*node+1, mid+1, r, id, val);
    }
}

ll query(int node, int l, int r, int a, int b){     //call it like query(1, 0, arr.size()-1, a, b)
    if(b < l || a > r) return 0;        //return neutral value of op
    if(l >= a && r <= b) {
        for(int x: tree[node]){
            ans[x]++;
            return 0;
        }
    }
    int mid = (l+r)>>1;
    return query(2*node, l , mid, a, b) + query(2*node+1, mid+1, r, a, b);  //change op
}

int main(){
    fastio;

    int n,q; cin >> n >> q;

    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    while(q--){
        ans.clear();
    }

    return 0;
}