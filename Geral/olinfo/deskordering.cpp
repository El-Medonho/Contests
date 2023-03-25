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

    ll ans = INFL;

    int n,l; cin >> n >> l; l--;

    vll arr(n);
    for(ll &i: arr) cin >> i;

    deque<int> dq,dq2;


    for(int i = 0; i < l; i++){
        while(!dq.empty() && arr[dq.back()] <= arr[i]) {
            if(dq.back() >= i-l){
                while(!dq2.empty() && arr[dq2.back()] <= arr[dq.back()]) {
                    dq2.pop_back();
                }
                dq2.push_back(dq.back());
            }
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int i = l; i < n; i++){
        if(i-l > 0){
            while(!dq.empty() && dq.front() < i-l) dq.pop_front();
            while(!dq2.empty() && dq2.front() < i-l) dq2.pop_front();
        }

        while(!dq.empty() && arr[dq.back()] <= arr[i]) {
            if(dq.back() >= i-l){
                while(!dq2.empty() && arr[dq2.back()] <= arr[dq.back()]) {
                    dq2.pop_back();
                }
                dq2.push_back(dq.back());
            }
            dq.pop_back();
        }
        dq.push_back(i);

        if(dq.size() == 1){
            int curr = dq.front(), last = dq2.front();
            ans = min(ans, (arr[curr]-arr[last])/2);
        }else{
            int curr = dq.front(); dq.pop_front();
            
            while(!dq.empty() && dq.front() < i-l) dq.pop_front();

            int last = dq.front();
            if(!dq2.empty()) last = (arr[last] > arr[dq2.front()]) ? last : dq2.front();

            ans = min(ans, (arr[curr]-arr[last])/2);
            dq.push_front(curr);
        }
    }

    cout << ans << endl;

    return 0;
}