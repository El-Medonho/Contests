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

int main(){
    fastio;

    int n,k; cin >> n >> k;
    
    set<int> currnums;
    map<int,int> relation;
    set<pii> positions;

    ll currseq = 0, ans = 0;

    vii arr(n);
    for(int &x: arr)cin >> x;

    int pnt1 = 0, pnt2 = 0;

    while(pnt2 != n){
        int num = arr[pnt2];
        if(currnums.find(num) != currnums.end()){
            ans += (pnt2-pnt1)+1;

            int last = relation[num];
            positions.erase({last, num});

            relation[num] = pnt2;
            positions.insert({pnt2, num});
        }

        else{
            currseq++;

            currnums.insert(num);
            relation[num] = pnt2;
            positions.insert({pnt2,num});

            if(currseq > k){
                int totake = (*positions.begin()).s;
                pnt1 = (*positions.begin()).f+1;
                
                positions.erase(positions.begin());
                currnums.erase(totake);
                relation.erase(totake);
            }

            ans += (pnt2-pnt1)+1;
        }
        pnt2++;
    }   

    cout << ans << endl;

    return 0;
}