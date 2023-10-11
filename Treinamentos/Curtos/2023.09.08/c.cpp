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
    int x, y;
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

    vector<Angle> pontos;

    for(int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        if(x == 0 && y == 0) continue;
        pontos.push_back(Angle(x,y));
    }

    n = pontos.size();

    sort(pontos.begin(), pontos.end());

    for(int i = 0; i < n; i++) pontos.push_back(pontos[i]);

    int r = -1, l = -1;

    for(int i = 0; i < n; i++){
        int dotT = (pontos[0].x * pontos[i].x + pontos[0].y * pontos[i].y);

        if(dotT <= 0 ){
            r = i-1;
            break;
        }
    }

    if(r == -1){
        r = n-1;
        l = n;
    }else{
        for(int i = n-1; i > -1; i--){
            int dotT = (pontos[0].x * pontos[i].x + pontos[0].y * pontos[i].y);

            if(dotT <= 0 ){
                l = (i+1);
                break;
            }
        }
    }


    ll ans = 0;

    ll X = 0, Y = 0;
    for(int i = 0; i <= r; i++) {
        X += pontos[i].x; Y += pontos[i].y;
    }

    r+=n;

    for(int i = l; i < n; i++){
        X += pontos[i].x; Y += pontos[i].y;
    }

    // cout << l << ' ' << r << '\n';

    for(int i = n; i < 2*n; i++){ 
        for(int j = l; j < i; j++){ 
            int dotT = (pontos[i].x * pontos[j].x + pontos[i].y * pontos[j].y);
            
            // cout << "a\n";
            if(dotT <= 0 || i-j >= n){
                X -= pontos[j].x; Y -= pontos[j].y;
                l = (j+1);
            }
            else break;
        }

        for(int j = (r+1); j < l+n && j < 2*n; j++){
            int dotT = (pontos[i].x * pontos[j].x + pontos[i].y * pontos[j].y);
            
            if(dotT > 0){
                X += pontos[j].x; Y += pontos[j].y;
                r = j;
            }
            else break;
        }
        // cout << l << ' ' << r << '\n';
        ans = max(ans, X * X + Y * Y);
    }

    cout << ans << '\n';

    return 0;
}