#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define mxn (int) 1e4+5
#define mxm (int) 1e5+5
#define f first
#define s second
#define pb push_back
#define es " "
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> pip;
typedef unsigned long long ull;

int n, pal[mxn], erro[mxn];

int main(){
    fastio;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> pal[i];
    }
    for(int i=1; i<=n; i++){
        cin >> erro[i];
    }

    set<int> resp;
    unordered_map<int, int> sla1, sla2;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            sla1[erro[j]]=0;
            sla2[erro[j]]=0;
        }

        for(int j=1; j<=n; j++){
            sla1[erro[j]]++;
            sla2[erro[j]]++;
        }

        int atual = erro[i];

        sla1[atual]--;
        sla2[atual]--;

        int pri = pal[1]+atual;
        int seg = pal[1]-atual;

        int pode1 = 1, pode2 = 1;

        for(int j=2; j<=n; j++){
            int quero1 = abs(pal[j]-pri);
            int quero2 = abs(pal[j]-seg);

            if(sla1[quero1]>0){
                sla1[quero1]--;
            }else{
                pode1=0;
            }

            if(sla2[quero2]>0){
                sla2[quero2]--;
            }else{
                pode2=0;
            }

            if(!pode1 && !pode2) break;
        }
        if(pode1) resp.insert(pri);
        if(pode2) resp.insert(seg);

    }
    for(int i:resp) cout << i << endl;
    return 0;
}