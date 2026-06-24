1class Solution {
2public:
3    int countDigitOccurrences(vector<int>& nums, int digit) {
4        int ans=0;
5        for(int i:nums){
6            while(i){
7                if((i%10)==digit){
8                    ans++;
9                }
10                i/=10;
11            }
12        }
13        return ans;
14    }
15};