int last_ancestor[26];
class Solution {
public:
    void dfs(int i, int par,vector<int>&res,vector<int>& parent,const string&s,const vector<vector<int>>&adj){
        int la=last_ancestor[s[i]-'a'];
        last_ancestor[s[i]-'a']=i;
        for(auto&j:adj[i]){
            if(j==par) continue;
            dfs(j,i,res,parent,s,adj);
            if(i==parent[j]) res[i]+=res[j];
        }
        if(la!=-1 && la!=parent[i]) res[la]+=res[i],parent[i]=la;
        last_ancestor[s[i]-'a']=la;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>>adj(n);
        vector<int>res(n,1);
        memset(last_ancestor,-1,sizeof(last_ancestor));
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        dfs(0,-1,res,parent,s,adj);
        return res;
    }
};