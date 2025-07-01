#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

// #define endl '\n'

signed solve(){
    int n = 16, m = 16;
    cin >> n >> m;

    if(n == 2 && m == 2){
        int cnt = 0, x;

        cout << "DIG " << "1 1" << endl;
        cin >> x;
        cnt+=x;

        cout << "DIG " << "1 2" << endl;
        cin >> x;
        cnt+=x;
        if(cnt == 2) return 0;

        cout << "DIG " << "2 1" << endl;
        cin >> x;
        cnt+=x;
        if(cnt == 2) return 0;

        cout << "DIG " << "2 2" << endl;
        cin >> x;
        cnt+=x;
        if(cnt == 2) return 0;
    }


    vector<pair<int,int>> arr = {{0,0}};

    vector<int> def(0);

    for(int i = 0; i < arr.size(); i++){
        cout << "SCAN " << arr[i].first+1 << ' ' << arr[i].second+1 << endl;

        int x; cin >> x;
        def.push_back(x);
    }

    vector<pair<int,int>> resto(0);

    for(int i = 0; i < n*m; i++){
        vector<int> cc(arr.size(), 0);

        for(int k = 0; k < arr.size(); k++){
            cc[k] += abs(i/m - arr[k].first) + abs(i%m - arr[k].second);
        }

        for(int j = i; j < n*m; j++){
            for(int k = 0; k < arr.size(); k++){
                cc[k] += abs(j/m - arr[k].first) + abs(j%m - arr[k].second);
            }
            if(def == cc){
                resto.push_back({i,j});
                // cout << i << ' ' << j << endl;
            }
            for(int k = 0; k < arr.size(); k++){
                cc[k] -= abs(j/m - arr[k].first) + abs(j%m - arr[k].second);
            }
        }
    }

    // cout << resto.size() << endl;

    int cnt = 3;

    while(cnt--){
        pair<int,int> B = {0, -1};

        for(int i = 0; i < n*m; i++){
            set<int> st;
            
            
            for(auto[a,b]: resto){
                int cc = 0;
                cc += abs(a/m - i/m) + abs(a%m - i%m);
                cc += abs(b/m - i/m) + abs(b%m - i%m);
                st.insert(cc);
            }
            
            B = max(B, make_pair((int)st.size(), i));
        }
        
        cout << "SCAN " << B.second/m+1 << ' ' << B.second%m+1 << endl;
        
        vector<pair<int,int>> nresto(0);
        int x; cin >> x;

        for(auto[a,b]: resto){
            int cc = 0;
            int i = B.second;
            cc += abs(a/m - i/m) + abs(a%m - i%m);
            cc += abs(b/m - i/m) + abs(b%m - i%m);

            if(cc == x) {
                nresto.push_back({a, b});
            }
        }

        resto = nresto;
    }

    if(resto.size() == 2){
        // cout << def[1000000] << endl;
        int x;
        cout << "DIG " << resto[0].first/m+1 << ' ' << (resto[0].first%m)+1 << endl;
        cin >> x;

        if(x == 0){
            cout << "DIG " << resto[1].first/m+1 << ' ' << (resto[1].first%m)+1 << endl;
            cin >> x;
            cout << "DIG " << (resto[1].second/m)+1 << ' ' << (resto[1].second%m)+1 << endl;
            cin >> x;
        }
        else{
            cout << "DIG " << resto[0].second/m+1 << ' ' << (resto[0].second%m)+1 << endl;
            cin >> x;
        }
    }

    else{
        int x;
        cout << "DIG " << resto[0].first/m+1 << ' ' << (resto[0].first%m)+1 << endl;
        cin >> x;
        cout << "DIG " << (resto[0].second/m)+1 << ' ' << (resto[0].second%m)+1 << endl;
        cin >> x;
    }



    return 0;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t; cin >> t;

    while(t--){
        solve();
    }


    return 0;
}