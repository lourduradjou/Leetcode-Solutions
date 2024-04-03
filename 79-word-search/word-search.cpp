class Solution {
public:
    bool findWord(vector<vector<char>> &board, string word, int row, int col, int n, int m, int index) {
        if(index == word.size()) 
            return true;
        
        if( row < 0 || col < 0 || row >= n || col >= m || board[row][col] != word[index]) 
            return false;
        
        char temp = board[row][col];
        board[row][col] = '@';//my wish letter to avoid repetition during recursion or backtracting
        bool ans1 = findWord(board, word, row+1, col, n, m, index+1);
        bool ans2 = findWord(board, word, row, col+1, n, m, index+1);
        bool ans3 = findWord(board, word, row-1, col, n, m, index+1);
        bool ans4 = findWord(board, word, row, col-1, n, m, index+1);

        board[row][col] = temp;
        return ans1 || ans2 || ans3 || ans4;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(findWord(board, word, i, j, n, m, 0))
                    return true;
            }
        }
        return false;
    }
};