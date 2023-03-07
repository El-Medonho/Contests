#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000009
#define mod(x,mvvm) (((x%mvvm)+mvvm)%mvvm)
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vii vector<int>
#define vll vector<long long>
#define endl "\n"
#define esp " "
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;
typedef unsigned long long ull;

int main(){
    fastio;

    int n; cin >> n;
    
    vii children(n,0), parent(n,-1), occur(n,0);

    for(int i = 1; i < n; i++){
        int a; cin >> a; a--;
        parent[i] = a;
        occur[a]++;
    }

    queue<int> q;

    for(int i = 0; i < n; i++){
        if(occur[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int i = q.front();
        q.pop();
        
        
        children[parent[i]] += children[i]+1;
        occur[parent[i]]--;
        if(parent[parent[i]] != -1 && occur[parent[i]] == 0){
            q.push(parent[i]);
        }
    }

    for(int i = 0; i < n; i++) cout << children[i] << esp;
    cout << endl;

    return 0;
}