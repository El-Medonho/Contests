#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int k; cin >> k;
    string s; cin >> s;

    int n = s.size();

    if(k == 1){
        s = "";
        while(s.size() < n) s += 'A';
        cout << s << '\n';
        return 0;
    }

    if(k == 2){
        int ans = 0;
        int last = -1;
        for(int i = 0; i < n; i++){
            if(last == -1 && s[i] == '.'){
                int pulo = i;
                for(int j = i; j < n; j++, pulo = j){
                    if(s[j] != '.'){
                        last = s[j]-'A';
                        pulo = j;
                        break;
                    }
                }

                for(int j = pulo-1; j >= i; j--){
                    s[j] = ((last+1)%2) + 'A';
                    last = (last+1)%2;
                }

                i = pulo-1;
                continue;
            }

            else if(s[i] == '.'){
                int pulo = i;

                for(int j = i; j < n; j++, pulo = j){
                    if(s[j] != '.') break;
                    s[j] = (last+1)%2+'A';
                    last = (last+1)%2;
                }

                i = pulo-1;
                continue;
            }

            else last = s[i]-'A';
        }

        cout << s << '\n';
        return 0;
    }

    int last = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '.'){
            int nxt = 0;
            int pos = i;

            for(int j = i; j < n; j++){
                if(s[j] != '.'){
                    nxt = s[j]-'A';
                    pos = j;
                    break;
                }
            }
            // cout << nxt << '\n';

            int c = 0;

            for(int h = 0; h < k; h++){
                if(h != last && h != nxt) {c = h; break;}
            }
            if(last == nxt){
                for(int h = 0; h < k; h++){
                    if(h != last && h != c){
                        last = h;
                        break;
                    }
                }
            }
            if( (pos-i) % 3 == 0 ) swap(nxt, last);



            vector<int> arr = {c,last,nxt}; 

            int pulo = i;

            for(int j = i; j < n; j++, pulo = j){
                if(s[j] != '.'){
                    break;
                }
                // cout << (j-i)%3 << ' ' << arr[(j-1)%3] << '\n';
                s[j] = arr[(j-i)%3] + 'A';
                last = arr[(j-i)%3];
            }

            i = pulo-1;

            continue;
        }

        last = s[i]-'A';
    }

    cout << s << '\n';

    return 0;
}