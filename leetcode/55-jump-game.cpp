1class Solution {
2public:
3    bool canJump(vector<int>& nums) {
4        vector<bool> v(nums.size());
5        v[0]=true;
6        return hlp(nums,0,v);
7    }
8
9    bool hlp(vector<int>& nums,int i,vector<bool>& v){
10        int u=min(nums[i]+i,(int)nums.size()-1);
11        if(u==nums.size()-1){
12            return true;
13        }
14        for(int j=i+1;j<=u;j++){
15            if(nums[j]!=0&&!v[j]){
16                v[j]=true;
17                if(hlp(nums,j,v)){
18                    return true;
19                }
20            }
21        }
22        return false;
23
24    }
25};