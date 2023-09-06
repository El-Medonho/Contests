
//———————————No bitches?———————————
//⠀⣞⢽⢪⢣⢣⢣⢫⡺⡵⣝⡮⣗⢷⢽⢽⢽⣮⡷⡽⣜⣜⢮⢺⣜⢷⢽⢝⡽⣝
//⠸⡸⠜⠕⠕⠁⢁⢇⢏⢽⢺⣪⡳⡝⣎⣏⢯⢞⡿⣟⣷⣳⢯⡷⣽⢽⢯⣳⣫⠇
//⠀⠀⢀⢀⢄⢬⢪⡪⡎⣆⡈⠚⠜⠕⠇⠗⠝⢕⢯⢫⣞⣯⣿⣻⡽⣏⢗⣗⠏⠀
//⠀⠪⡪⡪⣪⢪⢺⢸⢢⢓⢆⢤⢀⠀⠀⠀⠀⠈⢊⢞⡾⣿⡯⣏⢮⠷⠁⠀⠀
//⠀⠀⠀⠈⠊⠆⡃⠕⢕⢇⢇⢇⢇⢇⢏⢎⢎⢆⢄⠀⢑⣽⣿⢝⠲⠉⠀⠀⠀⠀
//⠀⠀⠀⠀⠀⡿⠂⠠⠀⡇⢇⠕⢈⣀⠀⠁⠡⠣⡣⡫⣂⣿⠯⢪⠰⠂⠀⠀⠀⠀
//⠀⠀⠀⠀⡦⡙⡂⢀⢤⢣⠣⡈⣾⡃⠠⠄⠀⡄⢱⣌⣶⢏⢊⠂⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⢝⡲⣜⡮⡏⢎⢌⢂⠙⠢⠐⢀⢘⢵⣽⣿⡿⠁⠁⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠨⣺⡺⡕⡕⡱⡑⡆⡕⡅⡕⡜⡼⢽⡻⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⣼⣳⣫⣾⣵⣗⡵⡱⡡⢣⢑⢕⢜⢕⡝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⣴⣿⣾⣿⣿⣿⡿⡽⡑⢌⠪⡢⡣⣣⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⡟⡾⣿⢿⢿⢵⣽⣾⣼⣘⢸⢸⣞⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//⠀⠀⠀⠀⠁⠇⠡⠩⡫⢿⣝⡻⡮⣒⢽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//—————————————————————————————

#include "bits/stdc++.h"
#include "iostream"
#include "string"
#include "vector"

#define fastio ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define fr front()
#define xx empty()
#define sz size()
#define bg begin()
#define nd end() 
#define mk make_pair
#define sb substr
#define lb lower_bound // ponteiro do primeiro valor menor ou igual 
#define up upper_bound // ponteiro do primeiro valor maior 
#define fs first
#define sc second
#define is insert 
#define ps push
#define pb push_back

// comandos uteis
// sort( lista.begin() , lista.end() , ( função de comparação opcional ) ) // crescente
// sort( lista.rbegin() , lista.rend() ) // decrescente
// set<int>::iterator nome_do_ponteiro = nome_do_set.bg // cria um ponteiro para um set que começa no inicio do set // nome_do_ponteiro pra andar com o ponteiro
// auto nome_do_ponteiro // tbm serve pra criar ponteiros  
// distance(nome_do_set.begin(), nome_do_ponteiro) // transforma o ponteiro em indice 
// reverse( lista.begin() , lista.end() ) // inverte a lista // funciona pra strings
// randomInt() // numero inteiro aleatorio

const int imax = 2147483647 ; // 2 . 10^9 

using namespace std;

typedef string str ;
typedef vector<int> lista ;
typedef vector<vector<int>> matriz ;
typedef pair<int,int> pii ;
typedef long long ll ;

int main(){
    
    fastio

    int t; cin >> t;
    
    while(t--){
        ll n , c ; cin >> n >> c ;
        vector<ll> s(n) ;
        for( int i = 0 ; i < n ; i++ ) cin >> s[i] ;
        ll w , cfalso ;
        ll l = 0 , r = c ;
        while( l <= r ){
            w = (l+r)/2 ;
            cfalso = 0 ;
            for( int i = 0 ; i < n ; i++ ) cfalso += ( s[i] + (w*2ll) ) * ( s[i] + (w*2ll) ) ;
            if( cfalso == c ){
                cout << w << "\n" ;
                break ;
            }
            else if( cfalso < 0 ){
                r = w - 1 ;
                l = 0 ;
            }
            else if( cfalso > c ){
                r = w - 1 ;
            }
            else{ // cfalso < c
                l = w + 1 ;
            }
        }
        //cout << cfalso << " " << c << "\n" ;
        //cout << -1 << "\n" ;
    } 

}

//1
//2
//4
//5
//7654321
//126040443
//79356352
//124321725
//113385729
//110961227

//aaa