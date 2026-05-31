1class Solution {
2public:
3    int mod=1e9+7;
4    bool asteroidsDestroyed(int mass, vector<int>& a) {
5        sort(a.begin(),a.end());
6        long long b=mass;
7        for(int i:a){
8            if(b>=(long long)i){
9                b+=i;
10                if(b>=mod){
11                    return true;
12                }
13            }else{
14                return false;
15            }
16        }
17        return true;
18    }
19};