// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄

#include "bits/stdc++.h"

using namespace std;

#define f first
#define s second
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long double ld;

int n,m;
vector<pair<ld,ld>> arr(0),arr2(0);

int main(){
    fastio;

    cin >> n;
    for(int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        arr.push_back({x,y});
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int x,y; cin >> x >> y;
        arr2.push_back({x,y});
    }

    ld ans = 1e17;

    int i,j; i= 0; j = 0;
    pair<ld,ld> di = {0,0}, dj = {0,0};
    pair<ld,ld> Di, Dj;

    function<ld(ld, int, int)> calc;

    calc = [&](ld md, int i, int j){

        ld x = (arr[i].f + di.f + Di.f * md) - (arr2[j].f + dj.f + Dj.f * md);
        ld y = (arr[i].s + di.s + Di.s * md) - (arr2[j].s + dj.s + Dj.s * md);
        ld ans = sqrt( x*x + y*y );
        return ans;

    };

    while(i < n-1 && j < m-1){

        ld ti = sqrt( (arr[i+1].f - (arr[i].f + di.f)) * (arr[i+1].f - (arr[i].f + di.f)) + (arr[i+1].s - (arr[i].s + di.s)) * (arr[i+1].s - (arr[i].s + di.s)) );
        ld tj = sqrt( (arr2[j+1].f - (arr2[j].f + dj.f)) * (arr2[j+1].f - (arr2[j].f + dj.f)) + (arr2[j+1].s - (arr2[j].s + dj.s)) * (arr2[j+1].s - (arr2[j].s + dj.s)) );

        ld ta = min(ti,tj);

        Di = { (arr[i+1].f-(arr[i].f + di.f)) / ti, (arr[i+1].s-(arr[i].s + di.s)) / ti}; 
        Dj = { (arr2[j+1].f-(arr2[j].f + dj.f)) / tj, (arr2[j+1].s-(arr2[j].s + dj.s)) / tj};

        ld l = 0, r = max(ti, tj);

        int t = 300;
        while(t--){

            ld md1 = l + (r-l)/3, md2 = r - (r-l)/3;

            if(md2 > ti || md2 > tj){
                r = md2;
                continue;
            }

            ld f1 = calc(md1,i,j), f2 = calc(md2,i,j);

            if(f1 > f2){
                l = md1;
            }else{
                r = md2;
            }
        }

        ans = min(ans, calc(l, i, j));
        ld hh = calc(l, i, j);

        if(ti > tj){
            dj = {0,0};

            di.f += Di.f * tj;
            di.s += Di.s * tj;

            j++;
        }else{
            di = {0,0};

            dj.f += Dj.f * ti;
            dj.s += Dj.s * ti;

            i++;
        }
    }

    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}