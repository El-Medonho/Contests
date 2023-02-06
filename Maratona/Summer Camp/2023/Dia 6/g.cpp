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
typedef tree<int, null_type, less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    fastio;

    int n; cin >> n;
    vii arr(n);
    ll ans = 0;
    for(int i = 0; i < n; i++) cin >> arr[i];
    map<int,set<int>> positions;
    set<int> nums; ordered_set newarr;
    for(int i = 0; i < n; i++){
        positions[arr[i]].insert(i); nums.insert(arr[i]);
    }
    int last = -1;
    for(auto it = nums.rbegin(); it != nums.rend(); it++){
        int curr = -1;
        for(int i = 0; i < positions[*it].size(); i++){
            if(positions[*it].size() == 1){
                for(int x: positions[*it]) {
                    curr = x; newarr.insert(x);
                    int nn = newarr.size();
                    if(last == -1) {last = curr; continue;}
                    if(last >= curr) ans += (newarr.order_of_key(last) - newarr.order_of_key(curr)); 
                    else ans += (nn) - newarr.order_of_key(curr) + newarr.order_of_key(last);
                    // cout << (newarr.order_of_key(last) - newarr.order_of_key(curr)) << esp;
                    // cout << (nn) - newarr.order_of_key(curr) + newarr.order_of_key(last) << esp;
                    last = curr; 
                }
            }
            else{               //algo errado na logica de loopar quando repetido babaca
                auto currit = positions[*it].lower_bound(last);
                if(currit == positions[*it].begin()) {
                    curr = *positions[*it].rbegin();  //possível remover itens
                    newarr.insert(curr);
                    if(last == -1) {last = curr; continue;}
                    int nn = newarr.size();
                    ans += (nn) - newarr.order_of_key(curr) + newarr.order_of_key(last);
                }
                else{
                    currit--;
                    curr = *currit;
                    newarr.insert(curr);
                    if(last == -1) {last = curr; continue;}
                    ans += (newarr.order_of_key(last) - newarr.order_of_key(curr));
                }
                last = curr;
            }
        } 
    }
    // cout << endl;
    ans += last + 1;    //add o ultimo;

    cout << ans << endl;


    return 0;
}



//criar altnewarr pra quando for repetido, nao contar cara que ja pegou(repetidos posso pegar em qqr ordem)