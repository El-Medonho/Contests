#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mxn = 1e5+5;

int month[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool leap_year(int y){
    return (y % 4 == 0 && y % 100 !=0) || y % 400 == 0;
}

int dateToInt(int y, int m, int d){
    return 1461 * (y+4800 + (m-14) / 12) / 4 + 367 * (m - 2 - (m - 14)/12 * 12) / 12 - 3 * ((y + 4900 + (m-14)/12)/100) / 4 + d - 32075;
}



signed solve(){

    int dc, mc, yc, dn, mn, yn;

    cin >> dc >> mc >> yc >> dn >> mn >> yn;

    if(dn>month[leap_year(yn)][mn]){
        cout << "Unspecified Server Error" << endl;
        return 0;
    }

    if(yc != yn){
        if(yc > yn){
            cout << "u:" << yc - yn << ' ';
        }else{
            cout << "d:" << yn - yc << ' ';
        }
    }

    if(mc != mn){
        if(mc > mn){
            cout << "l:" << mc - mn << ' ';
        }else{
            cout << "r:" << mn - mc << ' ';
        }
    }

    vector<vector<int> > cal(6, vector<int>(7));

    int row = 0, column = (dateToInt(yn, mn, 1)+1)%7;
    cal[row][column] = 1;

    for(int i=2; i<=month[leap_year(yn)][mn]; i++){
        column++;
        if(column == 7){
            column = 0;
            row++;
        }
        cal[row][column] = i;
    }
    int x, y;
    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            if(cal[i][j] == dn) x = i, y = j;
        }
    }
    cout << '[' << x+1 << ']' << '[' << y+1 << ']' << endl;
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}