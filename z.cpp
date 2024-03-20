#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    vector <int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    for(int i=0; i<Q; i++) {
        long long l=0, r=N-1;
        long long targot;
        cin >> targot;
        while (l<=r){
            int mid = (l+r)/2;
            if(v[mid]==targot) {
                cout << mid << '\n';
                break;
            }
            else if (v[mid] < targot){
                l = mid+1;
            }
            else if (v[mid] > targot){
                r = mid-1;
            }   
        }

        if(l>r){
            cout << "-1" << '\n';
        }
    }


    return 0;
}