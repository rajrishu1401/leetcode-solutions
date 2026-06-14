1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& t) {
4        stack<pair<int,int>> s;
5        vector<int> ans(t.size());
6        for(int i=t.size()-1;i>=0;i--){
7            while(!s.empty()&&s.top().first<=t[i]){
8                s.pop();
9            }
10            if(!s.empty()){
11                ans[i]=s.top().second-i;
12            }
13            s.push({t[i],i});
14        }
15        return ans;
16    }
17};