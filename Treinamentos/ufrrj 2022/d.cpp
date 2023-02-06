#include "bits/stdc++.h"
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

int n = 0; vector<pair<int,int>> velocidades; priority_queue<pair<int,int>> pq; vector<pair<int,int>> desorganizado;
vector<int> ans;
int main(){
    fastio;
    vector<int> bestobest;
    cin >> n;
    desorganizado.resize(n);
    bestobest.resize(10050,-1);  //possivel rte
    for(int i = 0; i < n; i++){
        int a = 0; int b = 0;
        cin >> a >> b;
        pq.push({a,b});
        desorganizado[i] = {a,b};
    }

    while(!pq.empty()){
        velocidades.push_back(pq.top());
        pq.pop();
    }

    int curr = -1;
    int record = -1;
    for(int i = 0; i < n; i++){
        curr = velocidades[i].f;
        if(velocidades[i].s > record){
            record = velocidades[i].s;
            bestobest[curr] = record;
        }
    }    

    for(int i = 0; i < n; i++){
        if(desorganizado[i].s == bestobest[desorganizado[i].f]) ans.push_back(i+1);
    }

    for(int i: ans) cout << i << " ";
    cout << endl;

    return 0;
}