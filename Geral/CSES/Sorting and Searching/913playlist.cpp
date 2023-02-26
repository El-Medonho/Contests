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

    int n; cin >> n;
    vii arr(n);
    map<int,int> loc;

    for(int i = 0; i < n; i++) cin >> arr[i];

    int seq = 1,pnt = 0, record = 1; 
    loc[arr[0]] = 1;
    for(int i = 1; i < n; i++){
        int curr = arr[i];
        if(loc.find(curr) != loc.end() && loc[curr] >= pnt){
            seq -= (loc[curr] - pnt);
            pnt = loc[curr];
        }
        loc[curr] = i+1;
        seq++;
        // cout << loc[curr] << esp << seq << endl;
        record = max(seq, record);
    }
    cout << record << endl;

    return 0;
}