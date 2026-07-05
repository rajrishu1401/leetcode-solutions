1class Solution {
2public:
3    int minimumDifference(vector<int>& nums) {
4        int goal=0;
5        for(int i=0;i<nums.size();i++){
6            goal+=nums[i];
7        }
8        int t=goal;
9        goal/=2;
10        int mid=nums.size()/2;
11        int u=pow(2,mid);
12        vector<set<int>> s(mid+2);
13        for(int i=0;i<u;i++){
14            int y=i;
15            int su=0;
16            int j=0;
17            while(y){
18                if(y&1){
19                    su+=nums[j];
20                }
21                j++;
22                y=y>>1;
23            }
24            //cout<<"p: "<<su<<endl;
25            int h=__builtin_popcount(i);
26            s[h].insert(su);
27        }
28        u=pow(2,mid);
29        int ans=INT_MAX;
30        for(int i=0;i<u;i++){
31            int y=i;
32            int su=0;
33            int j=mid;
34            while(y){
35                if(y&1){
36                    su+=nums[j];
37                }
38                j++;
39                y=y>>1;
40            }
41            int h=__builtin_popcount(i);
42            h=mid-h;
43            y=goal-su;
44            //cout<<su<<endl;
45            if(s[h].count(y)){
46                if(t&1) return 1;
47                return 0;
48            }
49            auto t=s[h].lower_bound(y);
50            if(t!=s[h].end())ans=min(ans,abs(y-(*t)));
51            //cout<<*t<<endl;
52            if(t!=s[h].begin()){
53                t=prev(t);
54                //cout<<*t<<endl;
55                ans=min(ans,abs(y-(*t)));
56            }
57            //cout<<"next :  "<<endl;
58        }
59        ans*=2;
60        if(t&1){
61            return ans+1; 
62        }
63        return ans;
64    }
65};