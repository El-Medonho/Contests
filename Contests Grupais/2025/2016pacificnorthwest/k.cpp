#include "bits/stdc++.h"

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int k; cin >> k;
    int r; cin >> r;

    vector<int> p2(k+2,1);
    int qnt_pessoas = 1;
    for(int i=1;i<=k;i++)
    {
        qnt_pessoas*=2;
        p2[i] = qnt_pessoas;
    } 
    double zeros = qnt_pessoas - r;
    int uns = qnt_pessoas - zeros -1;
    //cout << zeros << ' ' << uns << '\n';

    vector<double> minx(qnt_pessoas+2,0);
    minx[0] = 1;
    for(int i=1;i<qnt_pessoas;i++)
    {
        if(zeros-(i-1) <= 0)
        {
            minx[i] = 0;
            continue;
        }
        minx[i] = minx[i-1] * ((zeros-(i-1))/(qnt_pessoas-i));
        //cout << (zeros-(i-1)) << ' ' << qnt_pessoas-i << '\n';
    }
    for(int i=0;i<qnt_pessoas+1;i++)
    {
        //cout << minx[i] << ' ';
    }
    //cout << '\n';

    double resp = 0;

    for(int i=1;i<=k;i++)
    {
        if(minx[p2[i]-1] == 0) break;
        double tmp = minx[p2[i]-1]*i* ((double)1 - (minx[p2[i+1]-1]/minx[p2[i]-1]));
        resp += tmp;
    }

    cout << fixed << setprecision(5) <<  resp << '\n';

    return 0;
}
