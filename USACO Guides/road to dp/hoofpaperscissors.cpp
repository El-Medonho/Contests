#include "bits/stdc++.h"
#include "cstdio"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int n, k;
vector<int> plays;              //armazena as jogadas
vector<vector<vector<int>>> best;       //armazena a melhor continuação de uma casa dado numero de trocas realizadas       

int cover(int curr, int changed,int play){  //curr eh o numero da jogada atual, changed eh a quantidade de vezes q trocou e play eh a jogada atual
    if (changed > k) return 0;

    int bestplay = 0;
    if (plays[curr] == play) {bestplay = 1;}  //checar se a jogada atual eh vencedora
    else {bestplay = 0;}

    if (best[curr][changed][play] != 0) return bestplay + best[curr][changed][play];


    if (curr == n-1) return bestplay;

    vector<int> kplays;
    kplays = {changed+1, changed+1, changed+1};

    kplays[play] = changed;     //não aumentar o changed caso a minha proxima jogada seja a mesma da atual

    int a,b,c;

    a = cover(curr+1, kplays[0], 0);
    b = cover(curr+1, kplays[1], 1);
    c = cover(curr+1, kplays[2], 2);

    best[curr][changed][play] = max({a,b,c});

    return (bestplay + best[curr][changed][play]);
}

int main(){
    fastio;
    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);


    cin >> n >> k;

    plays.resize(n, 0);
    best.resize(n);


    for(int i = 0; i < n; i++){

        best[i].resize(k+1, {0,0,0});

        int j; char k;
        cin >> k;
        if (k == 'H') j = 0;    //H = 0
        if (k == 'P') j = 1;    //P = 1
        if (k == 'S') j = 2;    //S = 2

        plays[i] = j;
    }

    int a,b,c;
    a = cover(0,0,0); //for (int i = 0; i < n; i++) for (int j = 0; j < k+1; j++) best[i][j] = {0,0,0};   //tres passadas por cover com valores iniciais diferentes
    b = cover(0,0,1); //for (int i = 0; i < n; i++) for (int j = 0; j < k+1; j++) best[i][j] = 0;
    c = cover(0,0,2);
    int ans = max({a,b,c});

    cout << ans << endl;


    return 0;
}