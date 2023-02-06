#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int n = 0; vector<int> nums; vector<int> pos;

int main(){
    fastio;
    cin >> n;
    nums.resize(n); pos.resize(n);

    for(int i = 0; i < n; i++){
        int a = 0;
        cin >> a;
        nums[i] = a; 
        pos[a-1] = i;
    }

    if(n < 3) {cout << "NO" << endl; return 0;}

    for(int i = 1; i < n - 1; i++){
        int curr = nums[i];
        int k = min(curr-1, n-curr+1);
        int l = min(i, n-i);
        if(k > 20000 && l > 20000) continue;
        if(k < l){
            for(int j = 1; curr+j <= n && curr-j > 0; j++){     //vendo pelo numero
            int pos1 = pos[curr+j-1]; int pos2 = pos[curr-j-1];
            if((i < pos1 && i > pos2) || (i > pos1 && i < pos2)) {cout << "YES" << endl; return 0;}
        }
        }
        else{
            for(int j = 1; i + j < n && i - j >= 0; j++){
                int pos1 = i + j; int x = 2*curr - nums[pos1];
                if(x <= 0 || x > n) continue;
                int pos2 = pos[x-1];
                if((i < pos1 && i > pos2) || (i > pos1 && i < pos2)) {cout << "YES" << endl; return 0;}
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}