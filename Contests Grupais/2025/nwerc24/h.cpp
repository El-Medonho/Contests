#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'
typedef long long ll;
const int mxn = 1e5+5;

const int interval = 430;

int main(){
    int n; cin >> n;

    vector<int> pos(n+3, -1);
    vector<int> vis(n+2, -1);
    
    int size = -1;

    cout << "? " << n << ' ' << 1 << endl;
    int cc; cin >> cc;
    cout << "? " << 1 << ' ' << cc << endl;
    cin >> cc;
    int cpos = 0;
    vis[cc] = 0;
    pos[cpos++] = cc;

    while(cpos < interval){
        cout << "? " << 1 << ' ' << cc << endl;
        cin >> cc;

        if(vis[cc] > -1){
            size = cpos;
            break;
        }

        vis[cc] = cpos;
        pos[cpos++] = cc;
    }

    if(size == -1){
        cpos--;
        cpos += interval;
        while(cpos < n+1000){
            cout << "? " << interval << ' ' << cc << endl;

            cin >> cc;

            if(vis[cc] > -1){
                size = cpos - vis[cc];
                break;
            }

            vis[cc] = cpos;
            pos[cpos] = cc;
            cpos += interval;
        }
    }

    if(size == -1){
        assert(1 == 0);
    }

    // cout << size << endl;

    cc = pos[0];
    int h = cc%size;
    int np = -h;
    if(np < 0) np += size;

    int hc = cc;

    if(np != 0){
        cout << "? " << np << ' ' << pos[0] << endl;
        cin >> hc;
    }
    

    cout << "! " << pos[0] << ' ' << hc << endl;


    return 0;
}