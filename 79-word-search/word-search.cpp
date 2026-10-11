class Solution {
public:
    bool helper(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if(idx == word.size()) return true;
        int row = board.size();
        int col = board[0].size();
        if(i < 0 || j < 0 || i >= row || j >= col ||
           board[i][j] != word[idx]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool found =
            helper(board, word, i+1, j, idx+1) ||
            helper(board, word, i-1, j, idx+1) ||
            helper(board, word, i, j+1, idx+1) ||
            helper(board, word, i, j-1, idx+1);
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(helper(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};