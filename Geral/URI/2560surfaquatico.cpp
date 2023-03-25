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

int main(){
    fastio;

    int n;

    while(cin >> n){
        int b; cin >> b;
        
        vii arr(n); 
        for(int &i: arr) cin >> i;

        deque<int> dqu,dql,qw;
        ll sum = 0, ans = 0;

        b--;
        for(int i = 0; i < n; i++){
            if(i-b > 0){
                while(!dql.empty() && dql.front() < i-b) dql.pop_front();
                while(!dqu.empty() && dqu.front() < i-b) dqu.pop_front();
                sum -= arr[i-b-1];
            }

            while(!dql.empty() && arr[dql.back()] >= arr[i]) dql.pop_back();
            dql.push_back(i);

            while(!dqu.empty() && arr[dqu.back()] <= arr[i]) dqu.pop_back();
            dqu.push_back(i);

            sum += arr[i];

            if(i-b > -1){
                int hh = dqu.front();
                ans += sum - (arr[dqu.front()] + arr[dql.front()]);
            }
        }

        cout << ans << endl;
    }

    return 0;
}