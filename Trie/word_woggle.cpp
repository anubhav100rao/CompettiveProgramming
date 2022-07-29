#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

class Solution {
public:

    struct TrieNode {
        map<char, TrieNode*>children;
        bool flag = false;
    };

    TrieNode* root;
    vector<vector<char>>board;
    vector<int>dx = {-1 , -1 , -1, 0 , 0 , 1 , 1 , 1};
    vector<int>dy = {-1 , 0 , 1 , -1, 1 , -1, 0, 1};
    set<string>res;
    vector<vector<bool>>visited;

    void insertNode(string &str) {
        TrieNode* temp = root;
        for(char c: str) {
            if(!temp->children.count(c)) {
                temp->children[c] = new TrieNode();
            }
            temp = temp->children[c];
        }
        temp->flag = true;
    }

    void dfs(TrieNode* root, int x, int y, string &running) {
        running.push_back(board[x][y]);
        visited[x][y] = true;
        if(root->flag) {
            res.insert(running);
        }
        for(int i = 0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visited[nx][ny]) {
                dfs(root->children[board[nx][ny]], nx, ny, running);
            }
        }
        visited[x][y] = false;
        running.pop_back();
    }

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
        root = new TrieNode();
        this->board = board;

        for(string &str: dictionary) {
            insertNode(str);
        }

        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

        for(int i = 0; i<board.size(); i++) {
            for(int j = 0; j<board[0].size(); j++) {
                if(root->children.count(board[i][j])) {
                    string running= "";
                    dfs(root->children[board[i][j]], i, j, running);
                }
            }
        }

        return vector<string>(res.begin(), res.end());


	}
};


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt", "w", stderr);
    #endif
 
    return 0;
}