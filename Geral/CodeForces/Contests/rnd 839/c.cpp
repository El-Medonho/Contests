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

    int t; cin >> t;
    set<int> nums;
    // map<int, vector<pii>> mp;
    while(t--){
        int k,n; cin >> k >> n; k--;
        vii arr(0);
        int j = 1;
        arr.pb(1); nums.insert(1);

        int maior = 1;
        for(int i = 1; i + j < n && k > 0; i++){
            nums.insert(j+i);
            arr.pb(i+j);
            // mp[]
            j+=i;
            maior = j;
            k--;
        }
        j = n;
        while(k > 0 && j > maior){
            arr.pb(j); j--; k--;
        }
        j = maior;
        while(k > 0){
            j--;
            if(nums.find(j) != nums.end()) continue;
            k--;
            arr.pb(j);
        }
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size() - 1; i++) cout << arr[i] << esp;
        cout << *arr.rbegin() << endl;
    }    

    return 0;
}