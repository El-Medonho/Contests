#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
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

void upd(int x, int y, int val, vector<vector<int>> &bit){   //O(log²n)
    int ogy = y;
    while(x<=bit.size()-1){
        y = ogy;
        while(y<=bit[0].size()-1){
            bit[x][y]+=val;
            y+=y&-y;
        }
        x+=x&-x;
    }
}

int sum(int x, int y, vector<vector<int>> &bit){         //O(log²n)
    int ans=0;
    int ogy = y;
    while(x){
        y = ogy;
        while(y){
            ans+=bit[x][y];    
            y-=y&-y;
        }
        x-=x&-x;    
    }
    return ans;
}


int main(){
    fastio;

    int n,q; cin >> n >> q;
    vector<string> grid(n);
    vector<vii> bit(n+1, vii(n+1, 0));
    
    for(string &s: grid) cin >> s;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '*') upd(i+1, j+1, 1, bit);
        }
    }

    while(q--){
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == 1 && y1 == 1) {cout << sum(x2, y2, bit) << endl; continue;}
        if(x1 == 1){cout << sum(x2, y2, bit) - sum(x2, y1-1, bit) << endl; continue;}
        if(y1 == 1){cout << sum(x2, y2, bit) - sum(x1-1, y2, bit) << endl; continue;}
        cout << sum(x2, y2, bit) - sum(x2, y1-1, bit) - sum(x1-1, y2, bit) + sum(x1-1, y1-1, bit) << endl; continue;
    }

    return 0;
}