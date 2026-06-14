1class Solution {
2public:
3    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
4        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
5        for(int i=0;i<nums1.size();i++){
6            q.push({nums1[i]+nums2[0],{i,0}});
7        }
8        vector<vector<int>> ans;
9        while(k){
10            pair<int,pair<int,int>> u=q.top();
11            q.pop();
12            ans.push_back({nums1[u.second.first],nums2[u.second.second]});
13            if((u.second.second+1)<nums2.size())q.push({nums1[u.second.first]+nums2[u.second.second+1],{u.second.first,u.second.second+1}});
14            k--;
15        }
16        return ans;
17    }
18};