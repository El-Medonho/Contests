// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄

#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define vll vector<long long>

vll tree(0); vll arrg(0); vll lazy(0);

void unlazy(int node, int l, int r){
    if(lazy[node]){
        tree[node]=max(lazy[node], tree[node]);   //change op
        if(l!=r){
            lazy[2*node]=(lazy[node]);
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=0;
    }
}

void build(int node, int l, int r){
    if(l==r){
        tree[node]=arrg[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tree[node]=max(tree[2*node],tree[2*node+1]);     //change op
}

void initialize(){
    int iterador = 1;
    while(iterador < arrg.size()) iterador *= 2;
    iterador*=2;
    tree.resize(iterador, 0);     //value of every node should be neutral value of op when itilializing
    lazy.resize(iterador, 0);
    build(1, 0, arrg.size() - 1);
}

void upd(int node, int l, int r, int a, int b, int val){
    unlazy(node, l, r);
    if(a>r || b<l) return;
    if(l>=a && r<=b){
        lazy[node]=val;
        unlazy(node, l, r);
        return;
    }
    int mid=(l+r)>>1;
    upd(2*node, l, mid, a, b, val);
    upd(2*node+1, mid+1, r, a, b, val);
    tree[node]=max(tree[2*node],tree[2*node+1]);   //change op
}

int query(int node, int l, int r, int a, int b){
    unlazy(node, l, r);
    if(a>r || b<l) return 0;    //change value
    if(a<=l && b>=r){
        return tree[node];
    }
    int mid=(l+r)>>1;
    return max(query(2*node, l, mid, a, b), query(2*node+1, mid+1, r, a, b));   // change op
}

int consult(int node, int l, int r, int id){
    unlazy(node,l,r);
    if(l == r){
        return tree[node];
    }
    int mid=(l+r)>>1;
    if(l<=id && mid>=id){
        return consult(2*node,l,mid,id);
    }else{
        return consult(2*node+1, mid+1, r, id);
    }
}

int solve(){

    int n,m; cin >> n >> m;

    tree.resize(0); arrg.resize(0); lazy.resize(0);

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int &x: arr[i]) cin >> x;
    }

    vector<vector<int>> arro = arr;

    arrg.resize(n,0);
    initialize();

    sort(arro.begin(), arro.end());

    for(int i = 0; i < n; i++){
        int hl = 0, hr = n-1;
        bool pass = true;
        for(int j = 1; j <= m && pass; j++){
            for(int k = 0; k < m; k++){
                if(arr[i][k] == j){
                    k++;
                    int l = hl, r = hr;
                    int nhl = 1e9, nhr = 1e9;
                    while(l <= r){
                        int md = (l+r)>>1;
                        
                        if(arro[md][j-1] >= k){
                            if(arro[md][j-1] == k) nhl = md;
                            r = md-1;
                        }else{
                            l = md+1;
                        }
                    }
                    l = hl, r = hr;
                    while(l <= r){
                        int md = (l+r)>>1;
                        
                        if(arro[md][j-1] <= k){
                            if(arro[md][j-1] == k) nhr = md;
                            l = md+1;
                        }else{
                            r = md-1;
                        }
                    }

                    if(nhl == 1e9){
                        pass = false;
                        break;
                    }

                    upd(1, 0, n-1, nhl, nhr, j);
                    hl = nhl; hr = nhr;

                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << consult(1, 0, n-1, i) << ' ';
    }
    cout << '\n';

    return 0;
}

int main(){
    fastio;

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}