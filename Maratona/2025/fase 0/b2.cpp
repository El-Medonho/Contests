#include <bits/stdc++.h>
 
using namespace std;

#define f first
#define s second
#define pb push_back
#define endl '\n'
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> pip;
typedef unsigned long long ull;
const int mxn = 1e5+5;
const int mxm = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

// Returns -1 if a < b, 0 if a = b and 1 if a > b.
int cmp_double(double a, double b = 0, double eps = 1e-9) {
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}

vector<int> kmp(string &s){
    int n = (int)s.size();
    vector<int> pi(n);
    for(int i=1; i<n; i++){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi;
}

vector<pair<int, char> > vec[mxn];

string atual = "";
vector<int> pi;
int resp = 0;

void dfs(int x, int p){
    //cout << x << ' ' << atual << endl;
    if(pi[sz(atual)-1] == sz(atual)/2) resp = max(resp, sz(atual)/2);
    for(auto [i, c]:vec[x]){
        atual.push_back(c);
        int cont = sz(atual)-1;
        if(cont>=1){
            int j = pi[cont-1];
            while(j>0 && atual[cont]!=atual[j]) j = pi[j-1];
            if(atual[cont] == atual[j]) j++;
            pi[cont] = j;
        }
        dfs(i, x);
        pi[cont] = 0;
        atual.pop_back();
    }
}

signed cases(){
    int n;
    cin >> n;

    vector<pair<int, char >> edges;
    for(int i = 1; i<n; i++){
        int x;
        cin >> x;
        edges.push_back({x, 'a'});
    }
    for(int i = 2; i<=n; i++){
        char c;
        cin >> c;
        edges[i-2].second = c;

        //cout << edges[i-1].first << ' ' << edges[i-1].second << "  ";
        
        vec[edges[i-2].first].push_back({i, edges[i-2].second});
        //cout << edges[i-2].first << ' ' << i << ' ' << edges[i-2].second << endl;
    }
    //cout << endl;

    pi.resize(n);

    dfs(1, 0);

    cout << resp << endl;

    // string s = "baabaa";
    // auto resp = kmp(s);
    // for(int i:resp) cout << i << ' ';
    // cout << endl;  
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int t=1;

    //cin >> t;

    for(int i=1; i<=t; i++){
        //cout << "Case #" << i << ": ";
        cases();
    }
    return 0;
}