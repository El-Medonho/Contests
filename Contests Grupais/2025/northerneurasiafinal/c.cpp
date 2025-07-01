#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'

struct P {
    int x,y;
    P(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    vector<P> arr(3);

    int n = 3;

    for(int i = 0; i < n; i++){
        cin >> arr[i].x >> arr[i].y;
    }

    vector<int> o = {0,1,2};

    ll b = 1e18;
    vector<P> ans(0);

    do{
        for(int i = 0; i < 4; i++){
            vector<P> cc(0);
            ll sum = 0;
            int l = 0, r = 0;
            P mid;
            if(i & 1){
                if(arr[o[0]].x != arr[o[1]].x){
                    cc.emplace_back(arr[o[0]].x, arr[o[0]].y);
                    cc.emplace_back(arr[o[1]].x, arr[o[0]].y);
                    sum += abs(arr[o[0]].x - arr[o[1]].x);
                }

                if(arr[o[0]].y != arr[o[1]].y){
                    cc.emplace_back(arr[o[1]].x, arr[o[0]].y);
                    cc.emplace_back(arr[o[1]].x, arr[o[1]].y);
                    sum += abs(arr[o[0]].y - arr[o[1]].y);
                }
                l = min(arr[o[0]].y, arr[o[1]].y), r = max(arr[o[0]].y, arr[o[1]].y);

                if(arr[o[2]].y <= l){
                    mid = P(arr[o[1]].x, l);
                }
                else if(arr[o[2]].y > l && arr[o[2]].y < r){
                    mid = P(arr[o[1]].x, arr[o[2]].y);
                }
                else{
                    mid = P(arr[o[1]].x, r);
                }
            }
            else{
                if(arr[o[0]].y != arr[o[1]].y){
                    cc.emplace_back(arr[o[0]].x, arr[o[0]].y);
                    cc.emplace_back(arr[o[0]].x, arr[o[1]].y);
                    sum += abs(arr[o[0]].y - arr[o[1]].y);
                }
                
                if(arr[o[0]].x != arr[o[1]].x){
                    cc.emplace_back(arr[o[0]].x, arr[o[1]].y);
                    cc.emplace_back(arr[o[1]].x, arr[o[1]].y);
                    sum += abs(arr[o[0]].x - arr[o[1]].x);
                }
                l = min(arr[o[0]].x, arr[o[1]].x), r = max(arr[o[0]].x, arr[o[1]].x);

                if(arr[o[2]].x <= l){
                    mid = P(l, arr[o[1]].y);
                }
                else if(arr[o[2]].x > l && arr[o[2]].x < r){
                    mid = P(arr[o[2]].x, arr[o[1]].y);
                }
                else{
                    mid = P(r, arr[o[1]].y);
                }
            }

            //......

            if(i & 2){
                if(mid.x != arr[o[2]].x){
                    cc.emplace_back(mid.x, mid.y);
                    cc.emplace_back(arr[o[2]].x, mid.y);
                    sum += abs(mid.x - arr[o[2]].x);
                }

                if(mid.y != arr[o[2]].y){
                    cc.emplace_back(arr[o[2]].x, mid.y);
                    cc.emplace_back(arr[o[2]].x, arr[o[2]].y);
                    sum += abs(mid.y - arr[o[2]].y);
                }
            }
            else{
                if(mid.y != arr[o[2]].y){
                    cc.emplace_back(mid.x, mid.y);
                    cc.emplace_back(mid.x, arr[o[2]].y);
                    sum += abs(mid.y - arr[o[2]].y);
                }
                
                if(mid.x != arr[o[2]].x){
                    cc.emplace_back(mid.x, arr[o[2]].y);
                    cc.emplace_back(arr[o[2]].x, arr[o[2]].y);
                    sum += abs(mid.x - arr[o[2]].x);
                }
            }

            if(sum < b){
                b = sum;
                ans = cc;
            }
        }
    }

    while(next_permutation(o.begin(), o.end()));

    cout << ans.size()/2 << endl;

    for(int i = 0; i < ans.size(); i+=2){
        cout << ans[i].x << ' ' << ans[i].y << ' ' << ans[i+1].x << ' ' << ans[i+1].y << endl;
    }

    return 0;
}