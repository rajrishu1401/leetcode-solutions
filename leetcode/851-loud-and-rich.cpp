1class Solution {
2public:
3    vector<int> ans;
4    unordered_set<int> s;
5    vector<bool> vis;
6    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
7        vector<vector<int>> ad(quiet.size());
8        vis.resize(quiet.size());
9        for(int i=0;i<quiet.size();i++){
10            s.insert(i);
11            ans.push_back(i);
12        }
13        for(vector<int> i:richer){
14            ad[i[0]].push_back(i[1]);
15            s.erase(i[1]);
16        }
17        for(int i:s){
18            //cout<<i<<endl;
19            ans[i]=i;
20            hlp(ad,quiet,i,i);
21        }
22        for(int i=0;i<vis.size();i++){
23            if(!vis[i]){
24                hlp(ad,quiet,i,ans[i]);
25            }
26        }
27        return ans;
28    }
29
30    void hlp(vector<vector<int>>& ad,vector<int>& quiet,int i,int k){
31        vis[i]=true;
32        //cout<<"hlp: "<<i<<endl;
33        for(int j:ad[i]){
34            //cout<<"fun: "<<j<<endl;
35            if(quiet[ans[j]]>quiet[k]){
36                ans[j]=k;
37                hlp(ad,quiet,j,k);
38            }
39        }
40    }
41};