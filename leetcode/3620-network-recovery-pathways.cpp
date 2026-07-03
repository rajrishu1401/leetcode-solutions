1class Solution {
2public:
3    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
4        // if(edges.size()==1){
5        //     if(edges[0][0]==0&&edges[0][2]<=k&&)
6        //     return edges[0][2];
7        //     return -1;
8        // }
9        vector<vector<pair<int,int>>> node(online.size());
10        int e=0;
11        for(vector<int> r:edges){
12            if(!online[r[1]]||!online[r[0]]){
13                continue;
14            }
15            node[r[1]].push_back({r[0],r[2]});
16            e=max(e,r[2]);
17        }
18        int s=0;
19        while(s<=e){
20            int mid=(s+e)/2;
21            if(hlp(node,k,mid)){
22                s=mid+1;
23            }else{
24                e=mid-1;
25            }
26        }
27        return s-1;
28    }
29    bool hlp(vector<vector<pair<int,int>>>& node,long long k,int mid){
30        vector<long long> v(node.size(),LLONG_MAX);
31        v[node.size()-1]=0;
32        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
33        q.push({0,node.size()-1});
34        while(!q.empty()){
35            long long u=q.top().first;
36            int c=q.top().second;
37            q.pop();
38            if(u>v[c]){
39                continue;
40            }
41            for(pair<int,int> t:node[c]){
42                long long o=(u+t.second);
43                if(t.second<mid||o>k||v[t.first]<=o){
44                    continue;
45                }
46                if(t.first==0){
47                    return true;
48                }
49                v[t.first]=o;
50                q.push({o,t.first});
51            }
52        }
53        return false;
54    }
55};