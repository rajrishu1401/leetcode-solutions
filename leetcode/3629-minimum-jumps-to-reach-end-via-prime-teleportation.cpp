1class Solution {
2public:
3    int minJumps(vector<int>& nums) {
4        if(nums.size()==1){
5            return 0;
6        }
7        unordered_map<int,vector<int>> k;
8        for(int i=0;i<nums.size();i++){
9            k[nums[i]].push_back(i);
10        } 
11        k.erase(1);
12        for(int i=0;i<nums.size();i++){
13            if(nums[i]==1){
14                continue;
15            }
16            bool v=true;
17            for(int j=2;(j*j)<=nums[i];j++){
18                if(nums[i]%j==0){
19                    if(k.count(j)){
20                        k[j].push_back(i);
21                    }
22                    int o=nums[i]/j;
23                    if(k.count(o)){
24                        k[o].push_back(i);
25                    }
26                    v=false;
27                }
28            }
29            if(!v){
30                k.erase(nums[i]);
31            }
32        }
33        queue<int> q;
34        q.push(0);
35        vector<bool> v(nums.size());
36        v[0]=true;
37        int ans=1;
38        while(!q.empty()){
39            queue<int> p;
40            while(!q.empty()){
41                int u=q.front();
42                q.pop();
43                if((u+1)==nums.size()-1){
44                    return ans;
45                }
46                if((u+1)<nums.size()&&!v[u+1]){
47                    v[u+1]=true;
48                    p.push(u+1);
49                }
50                if((u-1)>=0&&!v[u-1]){
51                    v[u-1]=true;
52                    p.push(u-1);
53                }
54                for(int s:k[nums[u]]){
55                    if(!v[s]){
56                        if(s==nums.size()-1){
57                            return ans;
58                        }
59                        v[s]=true;
60                        p.push(s);
61                    }
62                    
63                }
64                k.erase(nums[u]);
65            }
66            ans++;
67            q=move(p);
68        }
69        return -1;
70    }
71};