1class Solution {
2public:
3    int countMajoritySubarrays(vector<int>& nums, int target) {
4        vector<int> v;
5        for(int i=0;i<nums.size();i++){
6            if(nums[i]==target){
7                v.push_back(i);
8            }
9        }
10        int ans=v.size();
11        //cout<<ans<<endl;
12        for(int i=0;i<v.size();i++){
13            for(int j=i+1;j<v.size();j++){
14                ans+=hlp(nums,v[i],v[j],target,j-i+1);
15            }
16        }
17        return ans;
18    }
19
20    int hlp(vector<int>& nums,int s,int e,int t,int c){
21        //cout<<s<<" "<<e<<" start"<<endl;
22        int tc=e-s+1;
23        if((c*2)<=tc){
24            return 0;
25        }
26        int ct=(2*c)-tc-1;
27        if(ct==0){
28            return 1;
29        }
30        int lc=0;
31        while(s>0&&nums[s-1]!=t&&lc<ct){
32            lc++;
33            s--;
34        }
35        int rc=0;
36        while((e+1)<nums.size()&&nums[e+1]!=t&&rc<ct){
37            rc++;
38            e++;
39        }
40        int ans=0;
41        //cout<<lc<<"  "<<rc<<endl;
42        for(int i=0;i<=lc;i++){
43            for(int j=0;j<=rc;j++){
44                if((i+j)>ct){
45                    break;
46                }
47                ans++;
48            }
49        }
50        return ans;
51    }
52
53};