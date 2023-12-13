class Solution {
public:
    int checkRow(vector<vector<int>>& mat, int row) {
        //we have to check that row completely so iterate
        int index = -1;

        for(int column = 0; column < mat[0].size(); column++) {
            if(mat[row][column] == 1) {
                if(index >= 0) 
                    return -1;
                else
                    index = column;
            }
        }
        return index;//finally return the found index of the column;
    }

    int checkColumn(vector<vector<int>>& mat, int columnIndex, int matchedRow) {
        int index = -1;
        for(int row = 0; row < mat.size(); row++) {
            if(mat[row][columnIndex] == 1 && row != matchedRow)
                return false;//we found another one so return false
        }
        return true;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int countSpecials = 0;

        for(int row = 0; row < mat.size(); row++) {
            int columnIndex = checkRow(mat, row);

            if(columnIndex >= 0 && checkColumn(mat, columnIndex, row)) 
                countSpecials++;
        }

        return countSpecials;
    }
};