1class Solution {
2public:
3    vector<int> sortArrayByParity(vector<int>& nums) {
4        int i=0;
5        int j=nums.size()-1;
6        while(i<j){
7            if((nums[i]&1)&&!(nums[j]&1)){
8                int u=nums[i];
9                nums[i]=nums[j];
10                nums[j]=u;
11            }
12            if(!(nums[i]&1)){
13                i++;
14            }
15            if(nums[j]&1){
16                j--;
17            }
18        }
19        return nums;
20    }
21};