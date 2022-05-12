class Solution { //nice solution with union find!
    int find(vector<int> &union_find, int ind) {
        while(union_find[ind] != ind)
            ind = union_find[ind];
        return ind;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> m;
        vector<int> union_find(accounts.size(), 0);
        unordered_map<int, vector<string>> res_map;
        for (int i = 0; i < accounts.size(); i++) {
            union_find[i] = i; //initiallize
            for (int j = 1; j < accounts[i].size(); j++) {
                if (m.find(accounts[i][j]) != m.end()) {
                    int root1 = find(union_find, i);
                    int root2 = find(union_find, m[accounts[i][j]]);
                    union_find[root1] = root2;
                }
                else
                    m[accounts[i][j]] = union_find[i];
            }
        }
        for (auto it : m) {
            int ind = find(union_find, it.second);
            res_map[ind].push_back(it.first);
        }
        vector<vector<string>> res;
        for (auto it : res_map) {
            vector<string> email = it.second;
            sort(email.begin(), email.end());
            email.insert(email.begin(), accounts[it.first][0]);
            res.push_back(email);
        }
        return res;
    }
};

class Solution { //with dfs, connected component
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<int> > acMap;
        vector<vector<string>> result;
        vector<vector<int>> adj(accounts.size(), vector<int>());
      
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                vector<int> adjEmail={};
                if(acMap.find(accounts[i][j])!=acMap.end()){
                    adjEmail=acMap[accounts[i][j]];
                }
                for(int a:adjEmail){
                    adj[a].push_back(i);
                    adj[i].push_back(a);

                }
                acMap[accounts[i][j]].push_back(i);
            }                   
        }
        
        int cnt=0;
        vector<vector<int>> samePerson;
        vector<bool> vis(accounts.size(), false); 
        for(int i=0;i<accounts.size();i++){
            if(vis[i]) continue;
            vector<int> temp;
            stack<int> S;
            S.push(i);
            temp.push_back(i);
            while(!S.empty()){
                int t=S.top();
                S.pop();
                if(vis[t]) continue;
                vis[t]=true;
                for(int a: adj[t]){
                    temp.push_back(a);
                    S.push(a);
                }
            }
            samePerson.push_back(temp);
        }
        
        unordered_map<string, bool> dupMap;
        for(auto idxs: samePerson){
            vector<string> temp;
            temp.push_back(accounts[idxs[0]][0]);
            for(int idx: idxs){
                for(int i=1;i<accounts[idx].size();i++){
                    string email=accounts[idx][i];
                    if(dupMap[email]) continue;
                    temp.push_back(email);
                    dupMap[email]=true;
                }
            }
            sort(temp.begin()+1, temp.end());
            result.push_back(temp);
        }
        return result;
    }
};




class Solution { //TLE
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      unordered_map<string,  vector<set<string>> > accountMap;
      vector<int> movedMap(accounts.size(), -1);
      vector<vector<string>> result;
      
      for(int i=0;i<accounts.size();i++){
        int moveTarget=-1;

        for(int j=1;j<accounts[i].size();j++){
          if(accountMap.find(accounts[i][j])!=accountMap.end()){
            isDuplicated=true;
            // destroy subarray
            moveTarget=accountMap[accounts[i][j]];

            while(movedMap[moveTarget]!=-1){
              moveTarget=movedMap[moveTarget];
            }
            
            if(accountMap[accounts[i][j]]!=moveTarget)
              accounts[moveTarget].push_back(accounts[i][j]); 
            
            movedMap[i]=moveTarget;
          }else{
              accountMap[accounts[i][j]]=i;
              cout << accounts[i][j] << ' ' << moveTarget << '\n';
              if(moveTarget!=-1) accounts[moveTarget].push_back(accounts[i][j]); 
          }
        }

      for(int i=0;i<accounts.size();i++){
          if(movedMap[i]==-1){
              result.push_back(accounts[i]);
          }
      }  
      for(int i=0;i<result.size();i++){
        sort(result[i].begin(), result[i].end());
      }
        return result;
      
    }
};