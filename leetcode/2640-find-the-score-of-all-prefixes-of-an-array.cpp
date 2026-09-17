1class Solution {
2public:
3    vector<long long> findPrefixScore(vector<int>& nums) {
4        vector<long long> ans;
5        ans.push_back(nums[0]+nums[0]);
6        int m=nums[0];
7        for(int i=1;i<nums.size();i++){
8            m=max(m,nums[i]);
9            ans.push_back(ans[i-1]+nums[i]+m);
10        }
11        return ans;
12    }
13};