#include "bits/stdc++.h"
using namespace std;
 
#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define vii vector<int>
#define vss vector<string>
#define vll vector<long long>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
 
vector<int> z_function(string s) {          
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
 
int main(){
    fastio;
 
    string n,m, str, pattern;
 
    cin >> str >> pattern;
    string junction = pattern+str;
    int tamanho = pattern.size();
    vii z = z_function(junction);
    int ans = 0;
    for(int i = pattern.size(); i < junction.size(); i++) if(z[i] >= pattern.size()) ans++;
    cout << ans << endl;
 
 
    return 0;
}