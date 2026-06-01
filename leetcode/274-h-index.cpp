1class Solution {
2public:
3    int hIndex(vector<int>& cit) {
4        int c=0;
5        sort(cit.begin(),cit.end(),greater<int>());
6        int i=0;
7        while(i<cit.size()){
8            if(c>cit[i]){
9                c--;
10                if(i>=c){
11                    return c;
12                }
13            }else{
14                c=cit[i];
15                i++;
16                if(i>=c){
17                    return c;
18                }
19            }
20            
21        }
22        return cit.size();
23    }
24};