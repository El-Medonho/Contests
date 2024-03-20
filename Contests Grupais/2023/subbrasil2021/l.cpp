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
typedef long long ll;

int ff(int x, vector<int> &pai){
    if(pai[x]==x) return x;
    return pai[x]=ff(pai[x], pai);
}

void uu(int x, int y, vector<int> &peso, vector<int> &pai){
    x=ff(x, pai), y=ff(y, pai);
    if(x==y) return;
    if(peso[y]>peso[x]) swap(x, y);
    pai[y]=x;
    peso[x]+=peso[y];
}

signed main(){
    fastio;

    ll ans = 1;
    ll md = 1e9+7;

    int n,m; cin >> n >> m;
    int N = 2*n;

    string s; cin >> s;

    string h = s;
    reverse(h.rbegin(), h.rend());

    s += h;

    vector<pair<int,int>> per(m);

    for(int i = 0; i < m; i++){
        cin >> per[i].first >> per[i].second; 
        per[i].first--; per[i].second--;
    }

    vector<vector<int>> pais(0), pesos(0);
    vector<int> paiz(N, 0), pesoz(N, 1);

    for(int i = 0; i < N; i++) paiz[i] = i;

    {
        int hh = N;
        while(hh){
            pais.push_back(vector<int>(N, -1));
            pesos.push_back(vector<int>(N, 1));
            for(int i=0; i<N; i++){
                pais.back()[i]=i;
                pesos.back()[i]=1;
            }
            hh>>=1;
        }
    }


    for(int i = 0; i < m; i++){
        int sz = per[i].second - per[i].first + 1; 

        int h2 = 0, ind = per[i].first, nind = N - 1 - per[i].second;
        while(sz){
            if(sz & 1){
                uu(ind, nind, pesos[h2], pais[h2]);

                ind += (1LL<<h2);
                nind += (1LL<< h2);
            }
            h2++;
            sz>>=1;
        }
    }

    for(int i = pais.size()-1; i > 0; i--){
        for(int j = 0; j + (1LL << i) <= N; j++){
            if(pais[i][j] == j) continue;

            int k = pais[i][j];

            uu(j, k, pesos[i-1], pais[i-1]);
            uu(j + (1LL << (i-1)), k + (1LL << (i-1)), pesos[i-1], pais[i-1]);
        }
    }

    for(int i = 0; i < N; i++) uu(pais[0][i], i, pesoz, paiz);

    for(int i = 0; i < n; i++){
        uu(i, N-1-i, pesoz, paiz);
    }

    map<int, int> mp;

    for(int i = 0; i < N; i++){
        mp[ff(i, paiz)] = -1;
    }

    for(int i = 0; i < N; i++){
        if(s[i] != '?'){
            if(mp[paiz[i]] == -1){
                mp[paiz[i]] = s[i]-'0';
            }
            else if(s[i] - '0' != mp[paiz[i]]) mp[paiz[i]] = 2;
        }
    }

    for(pair<int,int> a: mp){
        int b = a.second;

        if(b == -1){
            ans = (ans * 2LL)%md;
        }
        else if(b == 2) ans = 0;
    }

    cout << ans%md << '\n';


    return 0;
}