#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,m) (((x%m)+m)%m)
#define f first
#define s second
#define endl "\n"
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

int main(){
    fastio;
    int t = 0;
    cin >> t;

    for(int g = 0; g< t; g++){
        int n = 0; char c;
        cin >> n >> c;

        int currentcount = 0; int record = 0; int inicio = 0; int tanoinicio = true;

        string sequence; cin >> sequence;

        if (c == 'g') {cout << 0 << endl; continue;}

        for (int i = 0; i < sequence.size(); i++){
            if(sequence[i] == 'g') {
                record = max(record, currentcount);
                currentcount = 0; 
                tanoinicio = false;
                continue;
            }
            if(currentcount == 0) {if (sequence[i] == c) currentcount += 1;}
            else currentcount += 1;
            if (tanoinicio) inicio++;
            record = max(record, currentcount);
        }
        if (currentcount != 0) record = max(currentcount + inicio, record);
        cout << record << endl;
    }

    return 0;
}