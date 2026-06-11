1class Solution {
2public:
3    int m;
4    int n;
5    //vector<vector<vector<bool>>> vi;
6    vector<pair<int,int>> d={{1,0},{0,1},{-1,0},{0,-1}};
7    bool exist(vector<vector<char>>& board, string word) {
8        m=board.size();
9        n=board[0].size();
10        //vi.resize(m,vector<vector<bool>>(n,vector<bool>(word.size())));
11        vector<vector<bool>> v(m,vector<bool>(n));
12        for(int i=0;i<m;i++){
13            for(int j=0;j<n;j++){
14                if(board[i][j]==word[0]){
15                    v[i][j]=true;
16                    if(hlp(board,word,i,j,0,v)){
17                        return true;
18                    }
19                    v[i][j]=false;
20                }
21            }
22        }
23        return false;
24    }
25
26    bool hlp(vector<vector<char>>& board, string word,int i,int j,int w,vector<vector<bool>>& v){
27        if(word[w]!=board[i][j]){
28            return false;
29        }
30        w++;
31        if(w==word.size()){
32            return true;
33        }
34        for(pair<int,int> r:d){
35            int i1=i+r.first;
36            int j1=j+r.second;
37            if(i1<m&&i1>=0&&j1<n&&j1>=0&&!v[i1][j1]){
38                v[i][j]=true;
39                if(hlp(board,word,i1,j1,w,v)){
40                    return true;
41                }
42                v[i][j]=false;
43            }
44        }
45        return false;
46    }
47};