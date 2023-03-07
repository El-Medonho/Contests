#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
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
typedef tree<int,null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multiordered_set;  //--set.lower_bound(value) ao inves de find

int solve(){

    string a,b;
    cin >> a >> b;

    string ans = "";

    int pnt = 0;

    int cnt = 0;

    if(a.size() < b.size()) swap(a,b);

    if(a[a.size()-1] == b[b.size()-1]){
        cout << "YES" << endl;
        cout << '*' << a[a.size()-1] << endl;
        return 0;
    }
    else if(a[0] == b[0]){
        cout << "YES" << endl;
        cout << a[0] << '*' << endl;
        return 0;
    }

    bool ast = false;

    for(int i = 0; i < b.size(); i++){
        for(int j = 0; j < a.size(); j++){
            if(a[j] == b[i]){
                if(j != a.size()-1 && i != b.size()-1 && b[i+1] == a[j+1]){
                    cout << "YES" << endl;
                    cout << '*' << a[j] << a[j+1] << '*' << endl;
                    return 0;
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}

int main(){
    fastio;

    int t = 0; cin >> t;
    while(t--){
        solve();
    }    

    return 0;
}