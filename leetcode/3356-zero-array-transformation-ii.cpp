1class Solution {
2public:
3    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
4        vector<int> d(nums.size());
5        vector<int> p(nums.size());
6        int s=0;
7        int e=queries.size();
8        int k=-1;
9        int u=-1;
10        bool h=true;
11        
12        for(int r=0;r<nums.size();r++){
13            if(nums[r]!=0){
14                h=false;
15                break;
16            }
17        }
18        if(h){
19            return 0;
20        }
21        while(s<e){
22            int mid=(s+e)/2;
23            bool f=true;
24            //cout<<mid<<endl;
25            if(mid>k){
26                for(int i=k+1;i<=mid;i++){
27                    // if(queries[i][1]<r){
28                    //     continue;
29                    // }
30                    d[queries[i][0]]+=queries[i][2];
31                    if((queries[i][1]+1)<nums.size())d[queries[i][1]+1]-=queries[i][2];
32                }
33            }else{
34                for(int i=mid+1;i<=k;i++){
35                    // if(queries[i][1]<r){
36                    //     continue;
37                    // }
38                    d[queries[i][0]]-=queries[i][2];
39                    if((queries[i][1]+1)<nums.size())d[queries[i][1]+1]+=queries[i][2];
40                }
41            }
42            p[0]=d[0];
43            //cout<<p[0]<<" ";
44            if(p[0]<nums[0]){
45                f=false;
46            }else{
47                for(int i=1;i<nums.size();i++){
48                    p[i]=p[i-1]+d[i];
49                    //cout<<p[i]<<" ";
50                    if(p[i]<nums[i]){
51                        f=false;
52                        break;
53                    }
54                }
55            }
56            //cout<<endl;
57            if(f){
58                e=mid;
59                u=e;
60            }else{
61                s=mid+1;
62            }
63            k=mid;
64        }
65        if(u==-1){
66            return -1;
67        }
68        return u+1;
69    }
70};