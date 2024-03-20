#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mxn = 1e5+5;

mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1004669333;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    uniform_int_distribution<int> uid(70, mod-4);

    int p = uid(rng);

    int nn; cin >> nn;

    vector<vector<int>> graph(1);
    vector<int> pai(1, 0);

    graph.reserve(1e6+5);
    pai.reserve(1e6+5);

    vector<map<int,int>> rel(1);

    rel.reserve(1e6+5);

    int n = 1;

    for(int i = 0; i < nn; i++){
        string s; cin >> s;

        string cc = "";
        int node = 0;

        for(int j = 1; j < s.size(); j++){
            char c = s[j];


            if(c == '/'){
                ll ppow = p;
                ll hash = 0;

                for(char f: cc){
                    ll h = f-'a' * ppow;
                    hash = (hash + h) % mod;

                    ppow = ppow * p % mod;
                }

                cc = "";

                int nxt = rel[node][hash];

                if(rel[node][hash] == 0){
                    rel[node][hash] = n++;
                    graph.resize(n);
                    rel.resize(n);

                    nxt = n-1;
                    graph[node].push_back(nxt);

                    pai[nxt] = node;
                }


                node = nxt;
            }

            else cc += c;
        }

        n++;
        graph.resize(n);
        rel.resize(n);

        int nxt = n-1;

        graph[node].push_back(nxt);

        pai[nxt] = node;
    }

    // for(int i = 0; i < n; i++){
    //     cout << i << ": ";
    //     for(int j: graph[i]) cout << j << ' ';
    //     cout << endl;
    // }

    queue<int> qw;

    vector<int> ch(n, 0);

    vector<ll> dist(n, 0);
    vector<int> qtt(n, 0);

    for(int i = 0; i < n; i++){
        ch[i] = graph[i].size();

        if(ch[i] == 0) {qw.push(i); qtt[i]++;}
    }

    while(!qw.empty()){
        int cc = qw.front(); qw.pop();

        if(cc == 0) break;

        int nxt = pai[cc];

        qtt[nxt] += qtt[cc];
        dist[nxt] += dist[cc] + qtt[cc];

        ch[nxt]--;

        if(ch[nxt] == 0) qw.push(nxt);
    }

    ll ans = 1e17;

    function<void(int)> dfs;

    dfs = [&](int cc){
        ll x = dist[cc];

        ans = min(ans, x);

        ll ac = 0;

        for(int j: graph[cc]){
            if(graph[j].size() == 0) continue;

            dist[j] = dist[cc] - qtt[j] + (qtt[cc] - qtt[j]);

            qtt[j] = qtt[cc];

            dfs(j);
        }
    };

    dfs(0);

    cout << ans << endl;

    return 0;
}