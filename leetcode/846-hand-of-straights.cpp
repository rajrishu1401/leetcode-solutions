1class Solution {
2public:
3    bool isNStraightHand(vector<int>& nums, int k) {
4        if(k==1){
5            return true;
6        }
7        unordered_map<int,int> m;
8        for(int i:nums){
9            m[i]++;
10        }
11        vector<pair<int,int>> v;
12        for(auto t:m){
13            v.push_back({t.first,t.second});
14        }
15        sort(v.begin(),v.end());
16        int u=0;
17        int c=0;
18        for(int i=0;i<v.size();i++){
19            u++;
20            if(c==0){
21                //cout<<"here if   ";
22                c=v[i].second;
23                u=1;
24            }else if((v[i-1].first+1)!=v[i].first||v[i].second<c){
25                return false;
26            }else{
27                if(u==k){
28                    //cout<<"here else if   ";
29                    v[i].second-=c;
30                    c-=v[i-k+1].second;
31                    c+=v[i].second;
32                    u--;
33                }else{
34                    //cout<<"  here else else   ";
35                    v[i].second-=c;
36                    //cout<<v[i].second<<" "<<c<<"  here else else   ";
37                    c=c+v[i].second;
38                    //cout<<v[i].second<<" "<<c<<"  here else else   ";
39                }
40            }
41            //cout<<v[i].first<<"->"<<c<<endl;
42        }
43        if(c==0) return true;
44        return false;
45    }
46};
47
48