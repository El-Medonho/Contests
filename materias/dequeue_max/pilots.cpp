//https://szkopul.edu.pl/problemset/problem/lcU5m2RAICwNHsdzydb8JTQw/site/?key=statement

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

    ll t,n; cin >> t >> n;
    vll arr(n);

    for(ll &i: arr) cin >> i;

    deque<ll> dqu, dql;
    int ans = 0;

    for(int i = 0, j = 0; i < n; i++){
        
        while(!dqu.empty() && dqu.front() < j) dqu.pop_front();
        while(!dql.empty() && dql.front() < j) dql.pop_front();

        while(!dqu.empty() && arr[dqu.back()] <= arr[i]) dqu.pop_back();
        while(!dql.empty() && arr[dql.back()] >= arr[i]) dql.pop_back();
        dqu.push_back(i);
        dql.push_back(i);

        while(arr[dqu.front()] - arr[dql.front()] > t){
            if(dqu.front() < dql.front()){
                j = dqu.front()+1; dqu.pop_front();
            }else{
                j = dql.front()+1; dql.pop_front();
            }
        }

        ans = max(ans,(i-j)+1);

    }

    cout << ans << endl;

    return 0;
}