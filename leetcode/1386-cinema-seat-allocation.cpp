1class Solution {
2public:
3    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
4        unordered_map<int,int> m;
5        for(vector<int>& l:reservedSeats){
6            if(!m.count(l[0])){
7                m[l[0]]=7;
8            }
9            if(l[1]==2||l[1]==3){
10                m[l[0]]&=3;
11            }else if(l[1]==4||l[1]==5){
12                m[l[0]]&=3;
13                m[l[0]]&=5;
14            }else if(l[1]==6||l[1]==7){
15                m[l[0]]&=5;
16                m[l[0]]&=6;
17            }else if(l[1]==8||l[1]==9){
18                m[l[0]]&=6;
19            }
20        }
21        int mx=n*2;
22        for(auto& t:m){
23            if(t.second==0){
24                mx-=2;
25            }else if(!(t.second&4)){
26                mx--;
27            }else if(!(t.second&1)){
28                mx--;
29            }
30        }
31        return mx;
32        
33    }
34};