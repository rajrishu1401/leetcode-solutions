1class Twitter {
2public:
3    unordered_map<int,pair<unordered_set<int>,vector<pair<int,int>>>> m;
4    int t=0;
5    Twitter() {
6        
7    }
8    
9    void postTweet(int userId, int tweetId) {
10        m[userId].first.insert(userId);
11        m[userId].second.push_back({t,tweetId});
12        t++;
13    }
14    
15    vector<int> getNewsFeed(int userId) {
16        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
17        for(int i:m[userId].first){
18            //cout<<i<<endl;
19            int u=min(10,(int)m[i].second.size());
20            for(pair<int,int> k:m[i].second){
21                //cout<<k.second<< "  ";
22                if(q.size()<10){
23                    q.push(k);
24                }else if(q.top().first<k.first){
25                    q.pop();
26                    q.push(k);
27                }
28            }
29            cout<<endl;
30        }
31        vector<int> ans(q.size());
32        for(int i=ans.size()-1;i>=0;i--){
33            ans[i]=q.top().second;
34            q.pop();
35        }
36        return ans;
37
38    }
39    
40    void follow(int followerId, int followeeId) {
41        m[followerId].first.insert(followeeId);
42    }
43    
44    void unfollow(int followerId, int followeeId) {
45        m[followerId].first.erase(followeeId);
46    }
47};
48
49/**
50 * Your Twitter object will be instantiated and called as such:
51 * Twitter* obj = new Twitter();
52 * obj->postTweet(userId,tweetId);
53 * vector<int> param_2 = obj->getNewsFeed(userId);
54 * obj->follow(followerId,followeeId);
55 * obj->unfollow(followerId,followeeId);
56 */