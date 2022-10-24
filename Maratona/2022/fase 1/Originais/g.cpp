#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define mod(x, m) (((x%m)+m)%m)
#define mxn 100
#define mxm 100
#define f first
#define s second
#define pb push_back
#define es " "
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define sz(x) (int)x.size()
#define all(x) x.begin)(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

int n, joao, maria, soma, freq[15], pont[15];

int main(){
    fastio;
    for(int i=1; i<=13; i++){
        if(i>10){
            pont[i]=10;
        }else{
            pont[i]=i;
        }
    }
    cin >> n;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    freq[a]++;
    freq[b]++;
    freq[c]++;
    freq[d]++;
    joao=pont[a]+pont[b];
    maria=pont[c]+pont[d];
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        freq[x]++;
        soma+=pont[x];
    }
    joao+=soma;
    maria+=soma;
    for(int i=1; i<=13; i++){
        if(maria+pont[i]<=23 && joao+pont[i]>23 && freq[i]<=3){
            cout << i << endl;
            return 0;
        }
        if(maria+pont[i]==23 && freq[i]<=3){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}