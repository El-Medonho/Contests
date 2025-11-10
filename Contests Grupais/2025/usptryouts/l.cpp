#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

struct Matrix : vector<vector<int>> {
    using vector<vector<int>>::vector;
    using vector<vector<int>>::size;
    int h() const { return int(size()); }
    int w() const { return int((*this)[0].size()); }
    Matrix operator* (const Matrix& r) const {
        assert(w() == r.h()); Matrix res(h(), vector<int>(r.w()));
        for(int i = 0; i < h(); i++) for(int j = 0; j < r.w(); j++)
            for(int k = 0; k < w(); k++)
                res[i][j] ^= (*this)[i][k] & r[k][j];
        return res;
    }

    friend auto operator*(const Matrix& A, const vector<int>& b){
        int N = int(A.size()), M = int(A[0].size());
        vector<int> y(N);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++) y[i] ^= A[i][j] & b[j];
        return y;
    }
    Matrix& operator*=(const Matrix& r) {return *this= *this * r;}
    Matrix pow(ll n) const {
        assert(h() == w()); assert(n >= 0);
        Matrix x = *this, r(h(), vector<int>(w()));
        for(int i = 0; i < h(); i++) r[i][i] = 1;
        while(n) { if(n & 1) r *= x; x *= x; n>>=1;}
        return r;
    }
};

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,k; cin >> n >> k;

    vector<string> arr(n);

    vector<int> s(n*n, 0);
    vector<int> ini(n*n, 0);

    Matrix v(n*n, vector<int>(n*n, 0));
    vector<int> ans(n*n, 0);

    vector<pair<int,int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        for(int j = 0; j < n; j++){
            char c = arr[i][j];
            int num = i*n+j;
            if(c == '#'){
                s[num] = 1;
                continue;
            }
            ini[num] = c-'0';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c = arr[i][j];
            int num = i*n+j;
            if(c == '#'){
                continue;
            }

            v[num][num] = 1;

            for(auto[xn, yn]: dir){
                int x = i+xn, y = j+yn;
                if(x == n || x == -1 || y == n || y == -1 || s[x*n+y] == 1) continue;
                v[num][x*n+y] = 1;
            }
        }
    }

    v = v.pow(k);
    ans = v * ini;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c = arr[i][j];
            int num = i*n+j;
            if(c == '#'){
                cout << c;
            }
            else cout << ans[num];

        }
        cout << endl;
    }

    return 0;
}