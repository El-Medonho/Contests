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

int solve(){

    string str; cin >> str;
    int k; cin >> k;

    string ans = "";
    char last = 'a'; string cnt = ""; int total = 0;
    for(char c: str){
        if(c - 'a' >= 0 && c - 'a' <= 25){
            int nums = 0;
            if(last - 'a' >= 0 && last - 'a' <= 25){
                nums = 1;
                total++;
                if(total > k){
                    cout << "unfeasible" << endl;
                    return 0;
                }
            }else{
                nums = stoi(cnt);
                total += stoi(cnt);
                cnt = "";
            }

            while(nums){
                ans += c;
                nums--;
            }
            last = c;
        }else{
            cnt += c;
            if(total + stoi(cnt) > k){
                cout << "unfeasible" << endl;
                return 0;
            }
            last = c;
        }
    }

    cout << ans << endl;

    return 0;
}

int main(){
    fastio;

    int t; cin >> t;

    while(t--){
        solve();
    }

    return 0;
}