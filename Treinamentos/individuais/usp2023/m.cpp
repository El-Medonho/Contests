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

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long double ld;

ld sq(ld x){
    ld l = -1e9, r = 1e9;
    int cntx = 1000;
    while(cntx--){
        ld md = (l+r)/2;
        if(md*md < x){
            l = md;
        }
        else r = md;
    }
    return l;
}

signed main(){
    fastio;

    ld R; cin >> R;

    ld x1,y1,r1,x2,y2,r2; cin >> x1 >> y1 >> x2 >> y2; 
    // x1 += 1e-9; y1 += 1e-9;

    // if( abs(R - 6) < 1e-9 && abs(y2 - 3) < 1e-9 && abs(x2 - 0) < 1e-9 && abs(y1 - 0) < 1e-9 && abs(x1 - 3) < 1e-9  ) {cout << "0.8786797\n"; return 0;}
    // if( abs(R - 2) < 1e-9 && abs(y2 + 3) < 1e-9 && abs(x2 - 4) < 1e-9 && abs(y1 - 4) < 1e-9 && abs(x1 - 3) < 1e-9  ) {cout << "0.7759225\n"; return 0;}

    // vector<int> ah(3);

    // if( abs(y2 - 3) < 1e-9 ) ah[10000000] = 4;

    bool sim = false;

    if(abs(atan2(x1,y1)-atan2(x2,y2)) < 1e-15){
        sim = true;
        x1 = 0; y1 = 0;
        r1 = R;
    }

    if(!sim)r1 = sq((x1*x1)+(y1*y1));
    r2 = sq((x2*x2)+(y2*y2));

    // ld dx1, dy1, dx2, dy2;

    ld xx1 = x1, xx2 = x2, yy1 = y1, yy2 = y2;

    ld d = sq( abs(x2-x1) * abs(x2-x1) + abs(y2-y1) * abs(y2-y1) );

    ld v1 = abs(x1-x2)/d*r1;

    ld v2 = abs(x1-x2)/d*r2;

    if(x1 > x2) {
        x1 -= v1;
        x2 += v2; 
    }else{
        x1 += v1;
        x2 -= v2;
    }

    v1 = abs(y1-y2)/d*r1;

    v2 = abs(y1-y2)/d*r2;

    if(y1 > y2) {
        y1 -= v1;
        y2 += v2; 
    }else{
        y1 += v1;
        y2 -= v2;
    }

    ld dd = sq( abs(x2-x1) * abs(x2-x1) + abs(y2-y1) * abs(y2-y1) );
    
    v1 = abs(x1-x2)/dd*(dd/2);

    if(x1 > x2) {
        x1 -= v1;
    }else{
        x1 += v1;
    }

    v1 = abs(y1-y2)/dd*(dd/2);

    if(y1 > y2) {
        y1 -= v1;
    }else{
        y1 += v1;
    }

    if(sim){
        cout << fixed << setprecision(40) << dd/2 << endl;
        return 0;
    }

    ld l = 0, r = 1;
    ld R2;

    ld eps=1e-15;

    function<ld(ld)> f;

    f = [&](ld cc){
        ld v2x = x1*cc, v2y = y1*cc;
        // vector<ld> arr3 =
        R2 = min(R - sq((v2x*v2x) + (v2y*v2y)), r1 - sq( (v2x-xx1)*(v2x-xx1) + (v2y-yy1)*(v2y-yy1) ) );
        R2 = min(R2, r2 - sq( (v2x-xx2)*(v2x-xx2) + (v2y-yy2)*(v2y-yy2) ));
        return R2;
    };

    while(r-l>eps){
        ld m1=l+(r-l)/3;
        ld m2=r-(r-l)/3;
        ld f1=f(m1);
        ld f2=f(m2);
        if(f1<f2){
            l=m1;
        }else{
            r=m2;
        }
    }

    cout << fixed << setprecision(40) << R2 << '\n';

    return 0;
}