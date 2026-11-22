class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<unordered_map<int, int>> adj(n);
        for(const auto& e : edges){
            int u = e[0], v=e[1], d=e[2];
            if(!adj[u].count(v) || d<adj[u][v]){
                adj[u][v] =d;
            }
        }
        vector<long long> ans(n,-1);
        priority_queue<pair<long long, int> , vector<pair<long long , int>>,greater<>>pq;
        auto activate = [&](int u, long long t){
            ans[u]=t;
            for (const auto& [v,d]: adj [u]){
                if (ans[v]==-1){
                    pq.push({t+d ,v});
                }
            }
        };
        activate(0,0);
        for(int i = 1;i<n;++i){
            if(requiredSignals[i]<= 0){
                activate(i,0);
            }
        }
        while(!pq.empty()){
            auto [t,v]=pq.top();
            pq.pop();
            if(ans[v]!= -1) continue;
            requiredSignals[v]--;
            if(requiredSignals[v]==0){
                activate(v,t);
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna