long long djikstra(vector<vector<pair<long long, long long>>> &graph){
    int n = graph.size();
    vector<long long> weight(n, 1e18); 
    vector<int> visited(n, 0);

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push(make_pair(0,0));
    weight[0] = 0;

    while(!pq.empty()){
        pair<long long, long long> curr = pq.top();
        pq.pop();

        // if(curr.second == n-1) return curr.first;

        if(visited[curr.second] == 1) continue;
        visited[curr.second] = 1;

        for(pair<long long, long long> j: graph[curr.second]){
            if(weight[j.second] > weight[curr.second] + j.first){
                weight[j.second] = weight[curr.second] + j.first;
                pq.push(make_pair(weight[j.second], j.second));
            }
        }
    }

    return weight[n-1]; 
}