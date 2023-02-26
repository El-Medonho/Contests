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
vector<int> contem(0),contido(0);

bool comparator(pair<pii,int> &a, pair<pii,int> &b){
    if(a.f.f != b.f.f) return a.f.f < b.f.f;
    return a.f.s > b.f.s;
}

void upd(int x, int val, vector<int> &bit){   //O(logn)
    while(x<=bit.size()-1){
        bit[x]+=val;
        x+=x&-x;
    }
}
int sum(int x, vector<int> &bit){         //O(logn)
    int ans=0;
    while(x){
        ans+=bit[x];    
        x-=x&-x;    
    }
    return ans;
}

int main(){
    fastio;

    cin >> n;
    vector<pair<pii,int>> arr(n); vector<int> osy(n); set<int> osyexc;

    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b; 
        arr[i] = {{a,b},i}; 

        osy[i] = b;
        osyexc.insert(b);
    }

    contem.resize(osyexc.size()+1,0); contido.resize(osyexc.size()+1,0);

    map<int,int> ind;    //sorted do menor para maior; para fzr do maior para menor: k = (n+1)-indice[x];

    sort(osy.begin(), osy.end());

    int gg = 1;
    for(int x: osyexc){        
        ind[x] = gg;
        gg++;
    }
    for(int x: osy){
        upd(ind[x], 1, contem);
    }


    sort(arr.begin(), arr.end(), comparator);

    int g = 0;
    vii anscontem(n,0), anscontido(n,0);
    for(pair<pii,int> curr: arr){
        int curry = curr.f.s;
        // if(curry == 2) continue;
        int qu = 0;
        if(ind.find(curry) != ind.end()) qu = ind[curry];

        upd(qu, -1, contem);
        anscontem[curr.s] = sum(qu, contem);

        anscontido[curr.s] = sum((osyexc.size()+1)-qu, contido);
        upd((osyexc.size()+1)-qu, 1, contido);   
    }

    for(int i = 0; i < n-1; i++) cout << anscontem[i] << esp;
    cout << *anscontem.rbegin() << endl;
    for(int i = 0; i < n-1; i++) cout << anscontido[i] << esp;
    cout << *anscontido.rbegin() << endl;

    return 0;
}