#include <bits/stdc++.h>

#define mxn 100005
#define mxm 100005
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
#define vii vector<int>
#define es " "
#define endl "\n"
#define pii pair<int, int>
#define INF 0x3f3f3f3f
typedef long long ll;

using namespace std;

int main(){

    int t; cin >> t;        //considerar vetores repetidos
    vii answ;
    while(t--){
        int n; cin >> n;
        int ans = 0;
        vector<pii> p1(n); vector<pii> p2(n);
        vii x(n),y(n);
        map<double,int> rel1;   //se nao funcionar, trocar o map.
        for(int i = 0; i < n; i++){
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            p1[i].f = x1; p1[i].s = y1; p2[i].f = x2; p2[i].s = y2;
            x[i] = x1-x2; y[i] = y1-y2;
        }
        int zero1,zero2;
        zero1 = 0; zero2 = 0;
        for(int i = 0; i < n; i++){
            if(x[i] == 0 && y[i]!=0) zero1++;
            if(y[i] == 0 && x[i]!=0) zero2++;
        }
        ans+=zero1*zero2;
        for(int i = 0; i < n; i++){
            if(x[i] != 0 && y[i] != 0) rel1[x[i]/y[1]]++;
        }
        for(int i = 0; i < n; i++){
            double rel2 = 0;
            if(x[i] != 0 && y[i] != 0){
                rel2 = -(y[i]/x[i]);
                if(rel1.find(rel2) != rel1.end()) ans+= rel1[rel2];
            }
        }
        answ.push_back(ans);
    }
    for(auto x: answ) cout << x << endl;
    return 0;
}