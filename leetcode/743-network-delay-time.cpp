1class Solution {
2public:
3    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
4        vector<int> d(n,INT_MAX);
5        vector<vector<pair<int,int>>> nodes(n);
6        for(int i=0;i<times.size();i++){
7            nodes[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
8        }
9        d[k-1]=0;
10        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> p;
11        p.push({0,k-1});
12        while(!p.empty()){
13            int sr=p.top()[1];
14            int ds=p.top()[0];
15            p.pop();
16            for(pair<int,int> i:nodes[sr]){
17                if((ds+i.second)<d[i.first]){
18                    d[i.first]=ds+i.second;
19                    p.push({d[i.first],i.first});
20                    //cout<<i.first<<" : "<<d[i.first]<<endl;
21                }
22            }
23            //cout<<endl;
24        }
25        int ans=0;
26        for(int i:d){
27            
28            ans=max(ans,i);
29        }
30        if(ans==INT_MAX){
31            return -1;
32        }
33        return ans;
34    }
35};