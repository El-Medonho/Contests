// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
// ⣿⠟⠫⢻⣿⣿⣿⣿⢟⣩⡍⣙⠛⢛⣿⣿⣿⠛⠛⠛⠛⠻⣿⣿⣿⣿⣿⡿⢿⣿
// ⣿⠤⠄⠄⠙⢿⣿⣿⣿⡿⠿⠛⠛⢛⣧⣿⠇⠄⠂⠄⠄⠄⠘⣿⣿⣿⣿⠁⠄⢻
// ⣿⣿⣿⣿⣶⣄⣾⣿⢟⣼⠒⢲⡔⣺⣿⣧⠄⠄⣠⠤⢤⡀⠄⠟⠉⣠⣤⣤⣤⣾
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣀⣬⣵⣿⣿⣿⣶⡤⠙⠄⠘⠃⠄⣴⣾⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢻⠿⢿⣿⣿⠿⠋⠁⠄⠂⠉⠒⢘⣿⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⣿⡿⣡⣷⣶⣤⣤⣀⡀⠄⠄⠄⠄⠄⠄⠄⣾⣿⣿⣿⣿⣿⣿
// ⣿⣿⣿⣿⣿⣿⣿⡿⣸⣿⣿⣿⣿⣿⣿⣿⣷⣦⣰⠄⠄⠄⠄⢾⠿⢿⣿⣿⣿⣿
// ⣿⡿⠋⣡⣾⣿⣿⣿⡟⠉⠉⠈⠉⠉⠉⠉⠉⠄⠄⠄⠑⠄⠄⠐⡇⠄⠈⠙⠛⠋
// ⠋⠄⣾⣿⣿⣿⣿⡿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢠⡇⠄⠄⠄⠄⠄
// ⠄⢸⣿⣿⣿⣿⣿⣯⠄⢠⡀⠄⠄⠄⠄⠄⠄⠄⠄⣀⠄⠄⠄⠄⠁⠄⠄⠄⠄⠄
// ⠁⢸⣿⣿⣿⣿⣿⣯⣧⣬⣿⣤⣐⣂⣄⣀⣠⡴⠖⠈⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
// ⠈⠈⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣽⣉⡉⠉⠈⠁⠄⠁⠄⠄⠄⠄⡂⠄⠄⠄⠄⠄
// ⠄⠄⠙⣿⣿⠿⣿⣿⣿⣿⣷⡤⠈⠉⠉⠁⠄⠄⠄⠄⠄⠄⠄⠠⠔⠄⠄⠄⠄⠄
// ⠄⠄⠄⡈⢿⣷⣿⣿⢿⣿⣿⣷⡦⢤⡀⠄⠄⠄⠄⠄⠄⢐⣠⡿⠁⠄⠄⠄⠄⠄


#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n,m; cin >> n >> m; // n - numero de vertices, m - numero de arestas

    vector<vector<int>> graph(n);

    while(m--){
        int a,b; cin >> a >> b; a--; b--;  // 1 3
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> fila;

    fila.push(0); //coloco o vértice x na fila

    while(!fila.empty()){
        int v = fila.front();   
        fila.pop();

        for(int i:graph[v]){
            
            //se o vizinho ainda não foi visitado, o visito
            if(vis[i]==0){
                vis[i] = 1;
                fila.push(i);
            }
        }
    }

    return 0;
}