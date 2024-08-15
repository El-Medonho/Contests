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

#define endl '\n'

typedef long long ll;
typedef long double ld;


vector<vector<ld>> mult_matriz(vector<vector<ld>> &a, vector<vector<ld>> &b){
    vector<vector<ld>> z(a.size(), vector<ld>(b[0].size()));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            ld sum = 0;
            for(int k = 0; k < a[0].size(); k++){
                sum += a[i][k]*b[k][j];
            }
            z[i][j] = sum;
        }
    }
    return z;
}

ld A,B,C;

vector<vector<ld>> recorrencia_matriz(ll expo){
    vector<ld> digits(0);

    vector<vector<ld>> base = {{1},{C},{C+B},{1}};
    vector<vector<ld>> AA = {{0,1,0,0},{C*B,C,0,0},{B,1,0,0},{0,0,1,1}};
    int n = AA.size();

    vector<vector<ld>> id(n, vector<ld> (n,0));
    for(int i = 0; i < n; i++) id[i][i] = 1;

    while(expo){
        if(expo&1){
            id = mult_matriz(id,AA);
        }
        AA = mult_matriz(AA,AA);
        expo>>=1;
    }
    id = mult_matriz(id,base);

    return id;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,d,a,b; cin >> n >> d >> a >> b;

    if(a == b){
        cout << fixed << setprecision(15) << 1 << endl;
        return 0;
    }

    int k = n*d;

    vector<ld> dp(k+1, 0);

    for(int i = 1; i <= d; i++) dp[i] = 1/(ld)d;

    for(int i = 1; i < n; i++){
        vector<ld> ndp(k+1, 0);

        for(int j = 1; j <= d; j++){
            ld p = 1/(ld)d;

            for(int h = 1; h <= k-j; h++){
                ndp[h+j] += dp[h]*p;
            }
        }

        dp = ndp;
    }

    // ld ans = 0;
 
    A = dp[a], B = dp[b];
 
    ld PA = A + B*A;
    ld PB = B*B;
    ld PC = 1-(PA+PB);

    ld ans = PA/(PA+PB);

    cout << fixed << setprecision(15) << ans << endl;
    

    return 0;
}