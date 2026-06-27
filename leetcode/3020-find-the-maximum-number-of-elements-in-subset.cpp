1class Solution {
2public:
3    int maximumLength(vector<int>& nums) {
4        unordered_map<int,pair<int,int>> m;
5        for(int i:nums){
6            m[i].first++;
7        }
8        int ans=1;
9        for(auto t:m){
10            if(t.second.second==-1){
11                continue;
12            }
13            long long i=t.first;
14            if(i==1){
15                int u=t.second.first;
16                if((u&1)==0){
17                    u--;
18                }
19                ans=max(ans,u);
20                continue;
21            }
22            if(i*i>INT_MAX){
23                continue;
24            }
25            int c=1;
26            while(m.count(i*i)){
27                m[i].second=-1;
28                if(m[i].first>1){
29                    c++;
30                }else{
31                    break;
32                }
33                i*=i;
34                if(m[i].second>0){
35                    c+=m[i].second;
36                    break;
37                }else{
38                    c++;
39                }
40                if(i*i>INT_MAX){
41                    break;
42                }
43            }
44            m[i].second=-1;
45            if(c>1)t.second.second=c;
46            //cout<<t.first<<"  "<<c<<endl;
47            ans=max(ans,c);
48        }
49        return ans;
50    }
51};