#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007
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
typedef unsigned long long ull;

int main(){
    fastio;

    for(int i = -4; i <= 4; i++){
        for(int j = i; j <= 4; j++){
            for(int k = j; k <= 4; k++){
                for(int l = k; l <= 4; l++){
                    for(int m = -4; m <= 4; m++){
                        for(int n = m; n <= 4; n++){
                            for(int o = n; o <= 4; o++){
                                for(int l = k; l <= 4; l++){
                                    if(i*j == k+l && i*k == j+l && i*l == j+k && j*k == i+l && j*l == i+k && k*l == i+j){
                                        cout << i << esp << j << esp << k << esp << l << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}