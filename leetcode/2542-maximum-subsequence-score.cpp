1class Solution {
2public:
3    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
4        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q2;
5        for(int i=0;i<nums2.size();i++){
6            q2.push({nums2[i],i});
7        }
8        priority_queue<pair<int,int>> q1;
9        for(int i=0;i<nums2.size();i++){
10            q1.push({nums1[i],i});
11        }
12        long long s=0;
13        unordered_set<int> m;
14        unordered_set<int> st;
15        //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q3;
16        int p=k;
17        k--;
18        while(k){
19            k--;
20            s+=q1.top().first;
21            m.insert(q1.top().second);
22            //q3.push(q1.top());
23            q1.pop();
24        }
25        //cout<<s<<endl;
26        long long ans=0;
27        while(q2.size()>=p){
28            if(!m.count(q2.top().second)){
29                ans=max(ans,q2.top().first*(nums1[q2.top().second]+s));
30            }else{
31                while(st.count(q1.top().second)){
32                    q1.pop();
33                }
34                s=q1.top().first+s;
35                ans=max(ans,q2.top().first*s);
36                m.insert(q1.top().second);
37                s-=nums1[q2.top().second];
38                q1.pop();
39            }
40            //cout<<q2.top().first<<endl;
41            //cout<<s<<"  "<<ans<<endl;
42            st.insert(q2.top().second);
43            q2.pop();
44            
45        }
46        return ans;
47    }
48};