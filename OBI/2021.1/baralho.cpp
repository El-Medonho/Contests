#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s; cin >> s;
    int n = s.size();

    vector<bool> condicional(4, false);
    vector<vector<int>> arr(4, vector<int> (13,0));
    for(int i = 0; i < n; i+=3){
        int x = 0;

        // x += stoi(s.substr(i,2));

        //ou

        x += (s[i]-'0')*10;
        x += (s[i+1]-'0');

        //---------

        x--;

        int ind = -1;
        if(s[i+2] == 'C') ind  = 0;
        if(s[i+2] == 'E') ind  = 1;
        if(s[i+2] == 'U') ind  = 2;
        if(s[i+2] == 'P') ind  = 3;

        if(arr[ind][x]) condicional[ind] = true;
        arr[ind][x] = 1;
    }

    for(int i = 0; i < 4; i++){
        if(condicional[i]) cout << "erro\n";
        else{
            int soma = 0;
            for(int j = 0; j < 13; j++){
                if(arr[i][j] == 0) soma++;
            }
            cout << soma << '\n';
        }
    }

    return 0;
}