#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> vis(n, 0);

    if(n==1){
        cout << "POSSIBLE" << endl;
        cout << 1 << ' ' << 1 << endl;
    } else if(n<=5){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << "POSSIBLE" << endl;

        int x = 1, y = 1;
        cout << x << ' ' << y << endl;
        while(1){
            while(x<n && y<n){
                x+=3, y+=1;
                vis[x]++;
                cout << x << ' ' << y << endl;
            }
            while(x<n && y<n){
                x++, y+=3;
                vis[x]++;
            }
            while(x>1){
                
            }
        }

    }


    return 0;
}