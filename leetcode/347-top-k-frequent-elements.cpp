1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        unordered_map<int,int> m;
5        for(int i:nums){
6            m[i]++;
7        }
8        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
9        for(auto i:m){
10          if(k){
11            q.push({i.second,i.first});
12            k--;
13          }else if(q.top().first<i.second){
14            q.pop();
15            q.push({i.second,i.first});
16          }
17        }
18        vector<int> ans;
19        while(!q.empty()){
20            ans.push_back(q.top().second);
21            q.pop();
22        }
23        return ans;
24    }
25};