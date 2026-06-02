1class Solution {
2public:
3    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
4        int gs=0;
5        int cs=0;
6        for(int i=0;i<gas.size();i++){
7            cs+=cost[i];
8            gs+=gas[i];
9        }
10        if(cs>gs){
11            return -1;
12        }
13        int i=0;
14        bool got=false;
15        int c=0;
16        int ans=-1;
17        for(;i<gas.size();i++){
18            if(got){
19                c+=(gas[i]-cost[i]);
20                if(c<0){
21                    got=false;
22                    c=0;
23                }
24            }else{
25                if(gas[i]>=cost[i]){
26                    c=(gas[i]-cost[i]);
27                    got=true;
28                    ans=i;
29                }
30            }
31            
32        }
33        return ans;
34    }
35};