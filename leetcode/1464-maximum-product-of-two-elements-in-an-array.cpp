1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int m=max(nums[0],nums[1]);
5        int m1=min(nums[1],nums[0]);
6        for(int i=2;i<nums.size();i++){
7            if(m<nums[i]){
8                m1=m;
9                m=nums[i];
10            }else{
11                m1=max(nums[i],m1);
12            }
13        }
14        return (m-1)*(m1-1);
15    }
16};