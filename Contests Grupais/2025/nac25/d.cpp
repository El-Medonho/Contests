#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

struct Point {
    int x;
    int y;
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, w, h;
    cin >> n >> m >> w >> h;

    vector<Point> upper(n), lower(m);

    for(auto& [x,y] : upper) cin >> x >> y;
    for(auto& [x,y] : lower) cin >> x >> y; 

    vector<int> c1(w+1, 1e9), c2(w+1, -1e9);

    Point last = {0,h};
    c1[0] = h;
    for(int i = 0, x = 0; i < n; i++) {
        while(x < upper[i].x) {
            x++;
            double a = double(upper[i].y-last.y) / (upper[i].x-last.x);
            double b = last.y - a*last.x;
            c1[x] = a*x + b;
            if(c1[x] == int(a*x+b)) c1[x]--;
        }
        c1[x] = upper[i].y - 1;
        last = {x, upper[i].y};
    }

    
    last = {0,-h};
    c2[0] = -h;
    for(int i = 0, x = 0; i < m; i++) {
        while(x < lower[i].x) {
            x++;
            double a = double(lower[i].y-last.y) / (lower[i].x-last.x);
            double b = last.y - a*last.x;
            c2[x] = a*x + b;
            if(c2[x] == int(a*x+b)) c2[x]++;
        }
        c2[x] = lower[i].y+1;
        last = {x, lower[i].y};
    }
    
    vector<int> mx(w+1, -1e9), mn(w+1, 1e9);
    mx[0] = mn[0] = 0;
    
    bool yes = true;
    
    for(int i = 1; i <= w; i++) {
        mx[i] = min(mx[i-1]+1, c1[i] - (abs(c1[i] % 2) != i % 2));
        mn[i] = max(mn[i-1]-1, c2[i] + (abs(c2[i] % 2) != i % 2));
        if(mn[i] > mx[i]) yes = false;
    }

    if(yes) cout << mn[w] << ' ' << mx[w] << '\n';
    else cout << "impossible\n";

    return 0;
}