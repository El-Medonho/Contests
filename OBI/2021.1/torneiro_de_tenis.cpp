#include <bits/stdc++.h>
using namespace std;

int main(){
    int cnt = 0;
    for(int i = 0; i<6; i++){
        char aux;
        cin >> aux;
        if (aux == 'V') cnt++;
    }
    if(cnt<1) cout << "-1\n";
    else if (cnt<3) cout << "3\n";
    else if (cnt<5) cout << "2\n";
    else cout << "1\n";
    return 0;
}
