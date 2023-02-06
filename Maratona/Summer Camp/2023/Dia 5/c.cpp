#include <bits/stdc++.h>

#define mxn 1000005
#define mxm 100005
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
#define es " "
#define endl "\n"
#define pii pair<int, int>
#define INF 0x3f3f3f3f
typedef long long ll;

using namespace std;

int g[105][105], version, used[mxn];
pii v[mxn];

int mex(){
    for(int i=0; ; i++){
        if(used[i]!=version){
            return i;
        }
    }
}

void grundy(){
    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            if(i==j) continue;
            version++;
            for(int u=1; u<i; u++){
                used[g[i-u][j]]=version;
            }
            for(int u=1; u<j; u++){
                used[g[i][j-u]]=version;
            }
            for(int u=1; u<min(i, j); u++){
                used[g[i-u][j-u]]=version;
            }
            g[i][j]=mex();
        }
    }
}

int n;

int main(){
    cin >> n;
    grundy();
    for(int i=1; i<=n; i++){
        cin >> v[i].f >> v[i].s;
        if(v[i].f==v[i].s){
            cout << 'Y' << endl;
            return 0;
        }
    }

    int resp=0;
    for(int i=1; i<=n; i++){
        resp^=g[v[i].f][v[i].s];
    }
    if(resp==0){
        cout << 'N' << endl;
    }else{
        cout << 'Y' << endl;
    }
    return 0;
}