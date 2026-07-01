1class Solution {
2public:
3    vector<int> getConcatenation(vector<int>& nums) {
4        int n=nums.size();
5        for(int i=0;i<n;i++){
6            nums.push_back(nums[i]);
7        }
8        return nums;
9    }
10};