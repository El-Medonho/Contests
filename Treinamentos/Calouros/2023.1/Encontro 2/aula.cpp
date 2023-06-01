#include "bits/stdc++.h"

using namespace std;

// primeiro int do pair - resposta do fibonacci

//segundo int do pair - numero de calls

pair<int,int> fibo(int x){  

    if(x == 1){
        return {1 , 1};
    }
    if(x == 0){
        return {0 , 1};
    }

    // pair<int,int> fibo1 = fibo(x-1), fibo2 = fibo(x-2);

    pair<int,int> fibo1 = fibo(x-1);
    pair<int,int> fibo2 = fibo(x-2);

    int soma_fibonacci;

    soma_fibonacci = fibo1.first + fibo2.first; 

    int numero_calls;

    numero_calls = fibo1.second + fibo2.second + 1;

    return {soma_fibonacci , numero_calls};
}

// int fiboex(int x){
//     if(x > 1) return fibo(x-1) + fibo(x-2);

//     return x;
// }

int main(){

    int t; cin >> t;

    while(t > 0){
        int x; 
        cin >> x;

        pair<int,int> resposta = fibo(x);

        cout <<  "fib(" << x << ") = " << resposta.second - 1 <<  " calls = " << resposta.first << '\n';

        t--;
    }

    return 0;
}