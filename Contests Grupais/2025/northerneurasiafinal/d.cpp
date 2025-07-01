#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    while(n--){
        string a, b;
        cin >> a >> b;

        int n = (int)a.size(), m = (int)b.size();

        vector<int> fica(n+1);

        vector<int> freq(26);

        for(char i : b){
            freq[i-'A']++;
        }


        for(int i = n-1; i>=0; i--){
            //cout << a[i] << ' ' << freq[a[i] - 'A'] << endl;
            if(freq[a[i]-'A']){
                fica[i] = 1, freq[a[i]-'A']--;
            }
        }

        string agr = "";
        for(int i=0; i<n; i++){
            if(fica[i]) agr.push_back(a[i]);
        }
        if(agr == b){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}