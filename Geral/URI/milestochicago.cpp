#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main(){
    vector<double> ans;
    std::cout << std::setprecision(6) << std::fixed;

    

    while(true){
        int n,m;
        vector<vector<pair<int, int>>> streets;
        vector<bool> visited;
        vector<double> best;
        cin >> n;
        if (n == 0) break;
        cin >> m;
        
        streets.resize(n);
        visited.resize(n, false);
        best.resize(n, 0);
        best[0] = 1;

        for(int i = 0; i<m; i++){
            int a,b,p;
            cin >> a >> b >> p;
            a-=1; b-=1;
            streets[a].push_back({p,b});
            streets[b].push_back({p,a});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1,0});

        while(!pq.empty()){
            pair<double, int> current;
            current = pq.top();
            pq.pop();

            if(current.second == n-1){
                ans.push_back(round(current.first* 100000000)/1000000);
                break;
            }

            if (!visited[current.second]){
                for(pair<int,int>& street : streets[current.second]){
                    if(!visited[street.second] && best[street.second] < current.first * double(street.first)/100){
                        pq.push({current.first * double(street.first)/100, street.second});
                        best[street.second] = current.first * double(street.first)/100;
                    }
                }
            }
            visited[current.second] = true;
        }

    }

    for(double i: ans){
        cout << i << " percent\n";
    }

}