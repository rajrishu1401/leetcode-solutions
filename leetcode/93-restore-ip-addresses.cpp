1class Solution {
2public:
3    vector<string> ans;
4    vector<string> restoreIpAddresses(string s) {
5        if(s.size()>12||s.size()<4){
6            return {};
7        }
8        hlp(s,0,4,"");
9        return ans;
10    }
11    void hlp(string& s,int i,int u,string n){
12        //cout<<i<<"  "<<u<<endl;
13        if(u*3<(s.size()-i)||i>=s.size()){
14            return;
15        }
16        if(u==1){
17            if(i!=(s.size()-1)&&s[i]=='0'){
18                return;
19            }
20            string y=s.substr(i,s.size()-i);
21            if(stoi(y)>255){
22                return;
23            }
24            n+=y;
25            ans.push_back(n);
26            return;
27        }
28        if(s[i]=='0'){
29            hlp(s,i+1,u-1,n+"0.");
30            return;
31        }
32        int st=min(i+2,(int)s.size()-1);
33        string l="";
34        for(int v=i;v<st;v++){
35            l+=s[v];
36            hlp(s,v+1,u-1,n+l+".");
37        }
38        if((i+3)<s.size()){
39            l+=s[i+2];
40            if(stoi(l)<=255){
41                hlp(s,i+3,u-1,n+l+".");
42            }
43        }
44    }
45};