#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int var_global = 5;


double calcular(double a, double b, bool condicao){

    if(condicao){
        return (int) a / (int) b;
    }
    else{
        return a/b;
    }
}

int main(){
    fastio;

    int a = 0;  //aproximadamente 10^9
    char c = 'c';
    long long int b = 0; // aproximadamente 10^18

    // cin >> a;

    // cout << a << "\n\n\n";

    float h;
    double hh;
    long double hhh = 10.4;

    vector<int> arr = {1,2,3};

    // arr.push_back(10);

    // cout << arr[3] << '\n';
    // cout << "ababab\n" << arr[2];

    // for(int i = 0; i < 10; i++){
    //     cout << i << '\n';
    // }

    // cout << '\n';

    // for(int i: arr){
    //     cout << i << '\n';
    // }

    cout << calcular(5,2,1) << ' ' << calcular(5,2,0) << '\n';
    

    return 0;
}