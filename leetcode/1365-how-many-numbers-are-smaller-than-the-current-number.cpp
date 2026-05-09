1class Solution {
2public:
3    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
4        unordered_map<int,vector<int>> m;
5        for(int i=0;i<nums.size();i++){
6            m[nums[i]].push_back(i);
7        }
8        sort(nums.begin(),nums.end());
9        int j=0;
10        vector<int> ans(nums.size());
11        for(int i=1;i<nums.size();i++){
12            j++;
13            if(nums[i]!=nums[i-1]){
14                for(int l:m[nums[i]]){
15                    ans[l]=j;
16                }
17            }
18        }
19        return ans;
20    }
21};