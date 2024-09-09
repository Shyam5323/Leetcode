class Solution {
public:
    vector<vector<pair<int,double>>>adj;
    vector<int>vis;

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        adj.resize(n);
        vis.resize(n,0);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        priority_queue<pair<double,int>>pq; 
        pq.push({1,start});

        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int s=p.second;
            double sum=p.first;

            if(s==end)
                return sum;

            vis[s]=1;
            for(int i=0;i<(adj[s]).size();i++){
              if(vis[(adj[s][i]).first]==0){
                pq.push({sum*(adj[s][i]).second,(adj[s][i]).first});
            }
         }
     }
        return 0;
  }
};