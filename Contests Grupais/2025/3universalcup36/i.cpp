#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        string a, b;
        cin >> a >> b;
        
        int ans = 0;
        
        while(!a.empty()) {
            int i = find(a.begin(), a.end(), '.') - a.begin();
            int j = find(b.begin(), b.end(), '.') - b.begin();

            int a_num = stoi(a.substr(0,i));
            int b_num = stoi(b.substr(0,j));
            
            if(a_num < b_num) {
                ans = -1;
                break;
            }else if(a_num > b_num) {
                ans = 1;
                break;
            }
            
            a.erase(a.begin(), a.begin()+i);
            b.erase(b.begin(), b.begin()+j);

            if(!a.empty()) {
                a.erase(a.begin());
                b.erase(b.begin());
            }
        }

        if(ans == 0) cout << "Equal\n";
        else if(ans == -1) cout << "B\n";
        else cout << "A\n";
    }

    return 0;
}