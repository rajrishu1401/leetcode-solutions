1class Solution {
2public:
3    int minOperations(vector<int>& nums, int x) {
4        vector<int> s;
5        s.push_back(nums[0]);
6        for(int i=1;i<nums.size();i++){
7            s.push_back(nums[i]+s[i-1]);
8        }
9        if(s.back()==x){
10            return nums.size();
11        }
12        int u=hlp(s,x,nums.size());
13        int ans=INT_MAX;
14        if(u!=-1){
15            ans=min(ans,u+1);
16        }
17        for(int i=nums.size()-1;i>=0;i--){
18            x-=nums[i];
19            if(x<0){
20                if(ans==INT_MAX){
21                    return -1;
22                }
23                return ans;
24            }
25            if(x==0){
26                ans=min(ans,(int)nums.size()-i);
27                return ans;
28            }
29            u=hlp(s,x,i);
30            if(u!=-1){
31                ans=min(ans,u+1+(int)nums.size()-i);
32            }
33        }
34        if(ans==INT_MAX){
35            return -1;
36        }
37        return ans;
38    }
39    int hlp(vector<int>& v,int t,int e){
40        int s=0;
41        while(s<e){
42            int m=(s+e)/2;
43            if(v[m]==t){
44                return m;
45            }else if(v[m]>t){
46                e=m;
47            }else{
48                s=m+1;
49            }
50        }
51        return -1;
52    }
53};