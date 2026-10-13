class Solution {
public:
    vector<int>toposort(vector<vector<int>> &adj, vector<int>&present,
    vector<int>&indegree,int cnt){
        for(int i=0;i<26;i++){
            if(present[i]){
                for(auto &it: adj[i]){
                    indegree[it]++;
                }
            }
        }

        vector<int>topo;
        queue<int>q;

        for(int i=0;i<26;i++){
            if(present[i] && indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto &it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        return topo;

    }
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>>adj(26);
        vector<int>present(26,false);
        vector<int>indegree(26,0);
        int cnt=0;
        for(auto &word: words){
            for(char &c: word){
                if(!present[c-'a']){
                    present[c-'a']=true;
                    cnt++;
                }
            }
        }
        
        for(int i=0;i<words.size()-1;i++){
            bool found=false;
            string str1=words[i];
            string str2=words[i+1];
            int len=min(str1.size(),str2.size());
            for(int j=0;j<len;j++){
                if(str1[j]!=str2[j]){
                    found=true;
                    adj[str1[j]-'a'].push_back(str2[j]-'a');
                    break;
                }
            }
            if(!found && str2.size()<str1.size()) return "";
        }
        
        vector<int>topo=toposort(adj,present,indegree,cnt);
        if(cnt!=topo.size()) return "";

        string ans="";
        
        for(int i=0;i<topo.size();i++){
            ans.push_back(char(topo[i]+'a'));
        }
        return ans;
    }
};
