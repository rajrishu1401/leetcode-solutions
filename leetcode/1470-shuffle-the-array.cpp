class Solution {
public:
   vector<int> shuffle(vector<int>& nums, int n) {
       int max_val = INT_MIN;
       for(int val: nums) 
           max_val = max(max_val, val);
       max_val++;
       for(int i=0; i<(2*n); i++) {
           int val = (i&1) ? nums[n+(i/2)] : nums[i/2];
           nums[i] += (val%max_val) * max_val;
       }
       for(int i=0; i<(2*n); i++)
           nums[i] /= max_val;
       return nums;
    }
};