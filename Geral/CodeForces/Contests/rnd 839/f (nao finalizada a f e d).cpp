// #include "bits/stdc++.h"
// using namespace std;

// #define MOD 1000000009
// #define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
// #define f first
// #define s second
// #define pb push_back
// #define pii pair<int,int>
// #define pll pair<long long,long long>
// #define vii vector<int>
// #define vll vector<long long>
// #define endl "\n"
// #define esp " "
// #define INF 0x3f3f3f3f
// #define INFL 0x3f3f3f3f3f3f3f3f
// #define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
// typedef long long ll;
// typedef unsigned long long ull;

// int main(){
//     fastio;

//     int n,m,k; cin >> n >> m >> k;
//     vector<vii> picture(0);
//     map<pii, int> mp; 
//     set<pii, greater<pii>> pics; 

//     for(int g = 0; g < k+1; g++){
//         picture.resize(0);
//         picture.resize(n);

//         for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {int a; cin >> a; picture[i].pb(a);}
//         int curr = 0;
//         for(int i = 1; i < n-1; i++){
//             for(int j = 0; j < m-1; j++){
//                 if(picture[i][j] != picture[i-1][j] && picture[i][j] != picture[i+1][j] && picture[i][j] != picture[i][j-1] && picture[i][j] != picture[i][j+1]){
//                     curr++; mp[make_pair(i,j)]++;
//                 }
//             }
//         }
//         pics.emplace(make_pair(curr,g));

//     }

//     cout << *pics.begin().s+1 << endl;

//     cout << k + mp.size() << endl;

//     vector<pii> pixels(k);

//     for(auto &x: mp){
//         pixels[x.s-1].pb(x.first);
//     }

//     auto y = pics.begin(); auto b = y; y++;

//     while(y != pics.end()){

//         if(*b.f != *y.f){
//             for(int i = 0; i < pixels[*b.f-1].size(); i++) cout << 1 << esp << pixels[i].f << esp << pixels[i].s << endl;
//         }

//         b = y; y++;
//         cout << 2 << *b.s << endl;
//         while(*b.f == *y.f){
//             b = y; y++;
//             cout << 2 << *b.s << endl;
//         }
//     }

//     return 0;
// }