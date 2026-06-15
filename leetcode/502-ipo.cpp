1class Solution {
2public:
3    int findMaximizedCapital(int k, int ans, vector<int>& profits, vector<int>& capital) {
4        vector<vector<int>> v;
5        for(int i=0;i<profits.size();i++){
6            v.push_back({capital[i],profits[i]});
7        }
8        sort(v.begin(),v.end());
9        priority_queue<int> q;
10        int i=0;
11        while(k){
12            while(i<v.size()&&v[i][0]<=ans){
13                q.push(v[i][1]);
14                i++;
15            }
16            if(q.empty()){
17                return ans;
18            }
19            ans+=q.top();
20            q.pop();
21            k--;
22        }
23        return ans;
24    }
25};