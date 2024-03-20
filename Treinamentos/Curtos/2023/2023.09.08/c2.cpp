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

typedef long long ll;

struct Angle {
    ll x, y;
    int t;
    Angle(int x, int y, int t=0) : x(x), y(y), t(t) {}
    Angle operator-(Angle b) const { return {x-b.x, y-b.y, t}; }
    int half() const {
        assert(x || y);
        return y < 0 || (y == 0 && x < 0);
    }
    Angle t90() const { return {-y, x, t + (half() && x >= 0)}; }
    Angle t180() const { return {-x, -y, t + half()}; }
    Angle t360() const { return {x, y, t + 1}; }
    };
bool operator<(Angle a, Angle b) {
    // add a . dist2 () and b . dist2 () to also compare distances
    return make_tuple(a.t, a.half(), a.y * (ll)b.x) <
    make_tuple(b.t, b.half(), a.x * (ll)b.y);
}
// Given two points , t h i s calculates the smallest angle between
// them, i . e . , the angle that covers the defined l i n e segment .
pair<Angle, Angle> segmentAngles(Angle a, Angle b) {
    if (b < a) swap(a, b);
    return (b < a.t180() ?
    make_pair(a, b) : make_pair(b, a.t360()));
}
Angle operator+(Angle a, Angle b) { // point a + vector b
    Angle r(a.x + b.x, a.y + b.y, a.t);
    if (a.t180() < r) r.t--;
    return r.t180() < a ? r.t360() : r;
}
Angle angleDiff(Angle a, Angle b) { // angle b = angle a
    int tu = b.t - a.t; a.t = b.t;
    return {a.x*b.x + a.y*b.y, a.x*b.y - a.y*b.x, tu - (b < a)};
}

signed main(){
    // ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    vector<Angle> pontos, pontos2;
    // map<pair<int,int>, ll> qtt;

    for(int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        if(x == 0 && y == 0) continue;

        pontos2.push_back(Angle(x,y));
    }


    sort(pontos2.begin(), pontos2.end());

    for(int i = 0; i < pontos2.size(); i++){    //juntando os iguais
        ll xi = 0, yi = 0;
        for(int j = i; j < pontos2.size(); j++){
            ll dotT = (pontos2[j].x * pontos2[i].x + pontos2[j].y * pontos2[i].y);
            ll crossT = (pontos2[i].x * pontos2[j].y - pontos2[i].y * pontos2[j].x);
            
            if(crossT == 0 && dotT > 0){
                i = j;
                xi += pontos2[i].x; yi += pontos2[i].y;
            }
            else break;
        }
        pontos.push_back(Angle(xi, yi));
    }
    
    n = pontos.size();

    for(int i = 0; i < n; i++) pontos.push_back(pontos[i]);     //settando o ponteiro da direita r

    int r = -1;

    ll X = 0, Y = 0;

    ll ans = 0;

    for(int i = 0; i < n; i++){     //andando com os ponteiros
        if(r < i) {
            X += pontos[i].x; Y += pontos[i].y;
            r = i;
        }
        for(int j = (r+1); j < i+n && j < 2*n; j++){
            ll Xi = X, Yi = Y;
            
            Xi += pontos[j].x; Yi += pontos[j].y;
            if(Xi*Xi + Yi*Yi >= X*X + Y*Y){
                r = j;
                X = Xi; Y = Yi;
            }
            else break;
        }

        ans = max(ans, X * X + Y * Y);

        X -= pontos[i].x; Y -= pontos[i].y;
    }

    cout << ans << '\n';

    return 0;
}