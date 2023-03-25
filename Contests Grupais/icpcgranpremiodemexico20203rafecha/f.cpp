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

ll mask = 0;
int up = 0;

int main(){
    fastio;

    int w,h; cin >> w >> h;
    int area = w*h;
    up = min(w,h);

    {   
        int sum = 0, curr = 0;
        for(int i = 1; i <= 30 && sum+i*i <= area; i++){
            sum += i*i;
            curr = i;
        }

        up = min(up, curr);
    }

    // cout << up << endl;

    for(;up > 0; up--){
        mask = 0;

        priority_queue<pair<int,pii>> pq;
        pq.push({min(h,w), {h,w}});

        while(!pq.empty()){
            int hh = pq.top().s.f; int ww = pq.top().s.s; pq.pop();

            int best = up;
    
            while(mask & (1<<best)) best--;
            if(best == 0) continue;

            mask ^= (1<<best);
            if(ww == best && hh == best){
                continue;
            }
            if(ww == best){
                pq.push({min(ww,hh-best),{ww, hh-best}});
                continue;
            }
            if(h == best){
                pq.push({min(ww-best,hh),{ww-best, hh}});
                continue;
            }
            else{
                pq.push({min(ww,hh-best),{ww, hh-best}});
                pq.push({min(ww-best,hh),{ww-best, hh}});
                // pq.push({min(ww-best,hh-best),{ww-best, hh-best}});
                continue;
            }
        }

        int done = true;
        for(int i = 1; i <= up; i++){
            if(mask & (1<<i)) continue;
            done = false;
            break;
        }
        if(done) break;
    }

    cout << up << endl;

    return 0;
}