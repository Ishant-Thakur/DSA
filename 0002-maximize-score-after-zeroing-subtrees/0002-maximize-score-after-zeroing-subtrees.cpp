class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n =parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i<n ; ++i){
            adj[parent[i]].push_back(i);
        }
        auto dfs = [&](auto& self, int u) -> long long{
            if(adj[u].empty()){
                return score[u];
            }
            long long childrensum = 0;
            long long minchilddp = LLONG_MAX;
            for(int v : adj[u]){
                long long val = self(self,v);
                childrensum += val;
                minchilddp = min(minchilddp ,val);
            }
            if(op[u]==0){
                return score[u]+childrensum - min(0LL,minchilddp);
            }
            else{
                return score[u]+ childrensum - minchilddp;
            }
        };
        return dfs(dfs,0);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna