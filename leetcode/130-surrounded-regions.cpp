1class Solution {
2public:
3    void solve(vector<vector<char>>& board) {
4        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size()));
5        int h=board[0].size()-1;
6        for(int i=0;i<board.size();i++){
7            if(board[i][0]=='O'&&!vis[i][0]){
8                vis[i][0]=true;
9                hlp(board,vis,i,0);
10            }
11            if(board[i][h]=='O'&&!vis[i][h]){
12                vis[i][h]=true;
13                hlp(board,vis,i,h);
14            }
15        }
16        h=board.size()-1;
17        for(int i=1;i<(board[0].size()-1);i++){
18            if(board[0][i]=='O'&&!vis[0][i]){
19                vis[0][i]=true;
20                hlp(board,vis,0,i);
21            }
22            if(board[h][i]=='O'&&!vis[h][i]){
23                vis[h][i]=true;
24                hlp(board,vis,h,i);
25            }
26        }
27        for(int i=0;i<board.size();i++){
28            for(int j=0;j<board[0].size();j++){
29                if(board[i][j]=='O'&&!vis[i][j]){
30                    board[i][j]='X';
31                }
32            }
33        }
34    }
35    void hlp(vector<vector<char>>& mat,vector<vector<bool>>& vis,int i,int j){
36        queue<pair<int,int>> a;
37        a.push({i,j});
38        while(!a.empty()){
39            pair<int,int> p=a.front();
40            a.pop();
41            if((p.first+1)<mat.size()&&!vis[p.first+1][p.second]&&mat[p.first+1][p.second]=='O'){
42                vis[p.first+1][p.second]=true;
43                a.push({p.first+1,p.second});
44            }
45            if((p.second+1)<mat[0].size()&&!vis[p.first][p.second+1]&&mat[p.first][p.second+1]=='O'){
46                vis[p.first][p.second+1]=true;
47                a.push({p.first,p.second+1});
48            }
49            if((p.second-1)>=0&&!vis[p.first][p.second-1]&&mat[p.first][p.second-1]=='O'){
50                vis[p.first][p.second-1]=true;
51                a.push({p.first,p.second-1});
52            }
53            if((p.first-1)>=0&&!vis[p.first-1][p.second]&&mat[p.first-1][p.second]=='O'){
54                vis[p.first-1][p.second]=true;
55                a.push({p.first-1,p.second});
56            }
57        }
58    }
59};