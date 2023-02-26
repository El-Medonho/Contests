#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;

bool comparator(pair<pii,int> &a, pair<pii,int> &b){
    if(a.f.f != b.f.f) return a.f.f < b.f.f;
    return a.f.s > b.f.s;
}

int main(){
    fastio;

    map<int,set<int>, greater<int>> mp;

    int n; cin >> n;
    vector<pair<pii,int>> ranges(n); vector<int> osx(n);
    vector<int> contem(n,0), contido(n,0);
    for(int i = 0; i < n; i++) {int a,b; cin >> a >> b; ranges[i] = {{--a,--b},i};}

    sort(ranges.begin(), ranges.end(), comparator);

    for(pair<pii,int> x: ranges) {mp[x.f.s].insert(x.s); osx[x.s] = x.f.f;}

    for(pair<pii,int> curr: ranges){
        auto x = mp.lower_bound(curr.f.s);

        if(x->s.size() == 1){    //se o unico numero for ele
            mp.erase(x->f);
            x = mp.lower_bound(curr.f.s);
        }
        else x->s.erase(curr.s);

        if(x == mp.end()) continue;     //se ele for o maior y

        contem[curr.s] = 1;

        while(x != mp.end()){    //iterando pelos numeros que ainda nao sao contidos
            bool ended = false;
            for(auto k: x->s){
                if(x->f == curr.f.s && curr.f.f == osx[k]) {contido[curr.s] = 1; contem[k] = 1;}
                if(contido[k] == 1){ended = true; break;}
                contido[k] = 1;
            }
            if(ended) break;
            x++;
        }
    }

    for(int i = 0; i < contem.size()-1; i++) cout << contem[i] << esp;
    cout << *contem.rbegin() << endl;
    for(int i = 0; i < contido.size()-1; i++) cout << contido[i] << esp;            
    cout << *contido.rbegin() << endl;


    return 0;
}