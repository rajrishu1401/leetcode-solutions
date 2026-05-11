1class Solution {
2public:
3    vector<int> separateDigits(vector<int>& nums) {
4        vector<int> ans;
5        for(int i=nums.size()-1;i>=0;i--){
6            int u=nums[i];
7            while(u){
8                ans.push_back(u%10);
9                u/=10;
10            }
11        }
12        reverse(ans.begin(),ans.end());
13        return ans;
14    }
15};