1class Solution {
2public:
3    int leastInterval(vector<char>& tasks, int n) {
4        unordered_map<char,int> m;
5        auto cmp = [](const vector<int>& a, const vector<int>& b) {
6            if (a[0]==b[0]) return a[1]<b[1];
7            return a[0]>b[0];
8        };
9        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> q(cmp);
10        int u=0;
11        for(int i=0;i<tasks.size();i++){
12            m[tasks[i]]++;
13        }
14        vector<int> r;
15        for(auto t:m){
16            r.push_back(t.second);
17        }
18        sort(r.begin(),r.end(),greater<int>());
19        for(int i:r){
20            q.push({u,i});
21            u++;
22        }
23        int y=0;
24        while(!q.empty()){
25            //cout<<y<<"  "<<q.top()[0]<<" ->"<<q.top()[1]<<endl;
26            if(q.top()[0]<=y){
27                //cout<<"not idle"<<endl;
28                vector<int> u=q.top();
29                q.pop();
30                u[1]--;
31                if(u[1]!=0){
32                    u[0]+=(n+1);
33                    q.push(u);
34                }
35            }
36            y++;
37        }
38        return y;
39    }
40};