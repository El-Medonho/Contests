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

int main(){
    fastio;
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;

        vector<int> occurl(26,0); vector<int> occurr(26,0);
        int cntr = 0, cntl = 1;
        int ans = 0, record = 0;
        // for(int i = 0; i < n; i++){
        //     occurl[s[i]-'a']++;
        // }
        for(int i = n-1; i > 0; i--){
            occurr[s[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(occurr[i] != 0) cntr++;
        }
        cntl = 1;
        record = cntl+cntr;
        occurl[s[0]-'a']++;
        for(int i = 1; i < n-1; i++){
            occurl[s[i]-'a']++;
            occurr[s[i]-'a']--;
            if(occurl[s[i]-'a'] == 1) cntl++;
            if(occurr[s[i]-'a'] == 0) cntr--;
            record = max(record, cntr+cntl);
        }
        cout << record << endl;
    }
    return 0;
}