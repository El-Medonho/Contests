#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    int big = 1;

    vector<vector<int>> ass(n);
    vector<int> qtt(n, 0);

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x; x--;
        ass[x].push_back(i);
        a[i] = i;
    }

    for(int i = 0; i < n; i++){
        int x; cin >> x; x--;
        b[i] = ass[x][qtt[x]++];
        // cout << b[i] << ' ';
    }
    // cout << endl;

    stack<int> stk;
    string ans = "";
    int j = 0;
    for(int i = 0; i < n; i++){
        while(stk.empty() || stk.top() != b[i]){
            if(j == n) {j++; break;}
            ans += 'S';
            stk.push(j++);
        }
        if(j > n) {
            j++;
            break;
        }
        stk.pop();
        ans += 'C';
    }

    if(j > n){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << ans << '\n';

    return 0;
}