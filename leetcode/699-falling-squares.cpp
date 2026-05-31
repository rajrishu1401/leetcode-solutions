1class Solution {
2public:
3    int ma=0;
4    vector<int> ans;
5    map<pair<int,int>,int> m;
6    vector<int> fallingSquares(vector<vector<int>>& pos) {
7        for(vector<int> i:pos){
8            hlp(i[0],i[1]);
9            // for(auto p:m){
10            //     cout<<p.first.first<<" - "<<p.first.second<<" : "<<p.second<<endl;
11            // }
12            // cout<<endl;
13        }
14        return ans;
15    }
16    void hlp(int i,int s){
17        int j=i+s;
18        auto it=m.lower_bound({i,j});
19        int mx=0;
20        vector<pair<pair<int,int>,int>> a;
21        while(it!=m.end()&&(it->first.second)<j){
22            mx=max(mx,it->second);
23            if(it->first.second>=i&&it->first.first<=j){
24                it=m.erase(it);
25            }else if(it->first.second<i&&it->first.first>j){
26                a.push_back({{i,it->first.second},it->second});
27                a.push_back({{it->first.first,j},it->second});
28                it=m.erase(it);
29            }else if(it->first.second<i){
30                a.push_back({{i,it->first.second},it->second});
31                it=m.erase(it);
32            }else{
33                a.push_back({{it->first.first,j},it->second});
34                it=m.erase(it);
35            }
36        }
37        mx+=s;
38        m[{j,i}]=mx;
39        for(auto h:a){
40            m[h.first]=h.second;
41        }
42        ma=max(ma,mx);
43        ans.push_back(ma);
44    }
45};