1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        vector<int> ans;
6        int j=nums[0];
7        for(int i=0;i<nums.size();i++){
8            while(j!=nums[i]){
9                ans.push_back(j);
10                j++;
11            }
12            j++;
13        }
14        return ans;
15    }
16};