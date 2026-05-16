1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int end=nums.size()-1;
5        int last=nums[end];
6        int start=0;
7        while(start<end){
8            int mid=(start+end)/2;
9            if(last<nums[mid]){
10                start=mid+1;
11            }else if(last==nums[mid]){
12                while(start<end&&nums[start]==last){
13                    start++;
14                }
15                if(nums[start]>last){
16                    start++;
17                }else{
18                    end=mid;
19                }
20                
21            }else{
22                end=mid;
23            }
24        }
25        return nums[start];
26    }
27    
28};