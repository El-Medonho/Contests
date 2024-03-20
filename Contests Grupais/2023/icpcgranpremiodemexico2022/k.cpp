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

int main(){
    fastio;

    int n,q; cin >> n >> q;

    map<ll,int> mp;

    while(n--){
        string s; cin >> s;
        
        ll sum = 0, cnt = 1;
        for(int i = 0; i < s.size()-1; i++){
            cnt*=10;
        } 

        for(char c: s){
            ll l;
            if(c == 'a' || c == 'b' || c == 'c') l = 2;
            if(c == 'd' || c == 'e' || c == 'f') l = 3;
            if(c == 'g' || c == 'h' || c == 'i') l = 4;
            if(c == 'j' || c == 'k' || c == 'l') l = 5;
            if(c == 'm' || c == 'n' || c == 'o') l = 6;
            if(c == 'p' || c == 'q' || c == 'r' || c == 's') l = 7;
            if(c == 't' || c == 'u' || c == 'v') l = 8;
            if(c == 'w' || c == 'x' || c == 'y' || c == 'z') l = 9;

            sum += l*cnt;
            cnt/=10;
        }
        mp[sum]++;
    }

    while(q--){
        ll num; cin >> num;
        if(mp.find(num) == mp.end()) cout << 0 << endl;
        else cout << mp[num] << endl;
    }

    return 0;
}