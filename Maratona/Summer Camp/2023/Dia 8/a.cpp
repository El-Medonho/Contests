#include <bits/stdc++.h>

#define mxn 500005
#define mxm 100005
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
#define es " "
#define endl "\n"
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

using namespace std;

int n, q, sub[mxn], nivel[mxn];
vector<int> vec[mxn], stl[mxn];
vector<pii> query[mxn];
int letras[mxn][26];
string com;

string resp[mxn];

void dfs(int x, int p){
    sub[x]=1;
    for(int i:vec[x]){
        if(i==p) continue;
        nivel[i]=nivel[x]+1;
        dfs(i, x);
        sub[x]+=sub[i];
    }
}

void large(int x, int p, int ok){
    int mx=-1, big=-1;
    for(int i:vec[x]){
        if(i!=p && sub[i]>mx){
            mx=sub[i];
            big=i;
        }
    }
    for(int i:vec[x]){
        if(i!=p && i!=big){
            large(i, x, 0);
        }
    }
    if(big!=-1){
        large(big, x, 1);
        swap(stl[x], stl[big]);
    }
    stl[x].pb(x);
    letras[nivel[x]][com[x-1]-'a']++;
    
    for(int i:vec[x]){
        if(i!=p && i!=big){
            for(int j:stl[i]){
                letras[nivel[j]][com[j-1]-'a']++;
                stl[x].pb(j);
            }
        }
    }
    for(pii i:query[x]){
        int impar=0, par=0;
        for(char j=0; j<26; j++){
            int atual = letras[i.f][j];
            if(atual){
                if(atual&1) impar++;
                else par++;
            }
        }
        if(impar<=1) resp[i.s]="Yes";
        else resp[i.s]="No";
    }
    if(!ok){
        for(int i:stl[x]){
            letras[nivel[i]][com[i-1]-'a']--;
        }
    }
}

int main(){
    fastio;
    cin >> n >> q;
    for(int i=2; i<=n; i++){
        int x;
        cin >> x;
        vec[x].pb(i);
    }
    cin >> com;
    for(int i=1; i<=q; i++){
        int a, b;
        cin >> a >> b;
        query[a].pb({b, i});
    }
    nivel[1]=1;
    dfs(1, 0);
    large(1, 0, 0);
    for(int i=1; i<=q; i++){
        cout << resp[i] << endl;
    }
    return 0;
}