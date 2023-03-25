#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
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

int sz = 1, n;
set<string> st;
string s; 

void create(int mask, int str){
    if(mask == sz-1){
        string hh = "";
        for(int i = 0; i < n; i++){
            hh += s[(str%10) -1];
            str/=10;
        }
        st.emplace(hh);
        return;
    }

    int gg = 1;
    for(int i = 0; i < n; i++){
        if(mask & (1<<i)) gg*=10;
    }

    for(int i = 0; i < n; i++){
        if(!(mask & (1<<i))) {
            create(mask ^ (1<<i), str + (gg*(i+1)));
        }
    }
}

int main(){
    fastio;

    cin >> s;
    
    n = s.size();
    while(n > 0){
        sz <<= 1;
        n--;
    }

    n = s.size();

    for(int i = 0; i < n; i++){
        create((1<<i), i+1);
    }

    cout << st.size() << endl;

    for(string h: st) cout << h << endl;

    return 0;
}