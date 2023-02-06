#include <bits/stdc++.h>

#define mxn 200005
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

int q;

int main(){
    fastio;
    cin >> q;
    cin.ignore();
    while(q--){
        string t, p;
        int cont=0;
        getline(cin, t);
        getline(cin, p);
        int pos1=0, pos2=0;
        while(pos1<sz(t)){
            if(t[pos1]!=p[pos2]){
                pos1++;
            }else{
                pos1++; pos2++;
            }
            if(pos2==sz(p)){
                cont++;
                pos2=0;
            }
        }
        cout << sz(t)-cont*sz(p) << endl;
    }
    return 0;
}