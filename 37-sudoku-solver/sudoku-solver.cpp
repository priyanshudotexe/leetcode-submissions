class Solution {
public:
    vector<vector<int>> row;
    vector<vector<int>> col;
    vector<vector<int>> block;

     inline int blk(int i, int j) {
        return (i / 3) * 3 + (j / 3);
    }
    bool sudoku(vector<vector<char>>&board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(int put=1; put<10; put++){
                        if(row[i][put] || col[j][put] || block[blk(i,j)][put]) continue;
                        board[i][j]=put+'0';
                        row[i][put]=1;
                        col[j][put]=1;
                        block[blk(i,j)][put]=1;
                        if(sudoku(board)) return true;
                        board[i][j]='.';
                        row[i][put]=0;
                        col[j][put]=0;
                        block[blk(i,j)][put]=0;

                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        row.resize(9,vector<int>(10,0));
        col.resize(9,vector<int>(10,0));
        block.resize(9,vector<int>(10,0));
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    int x=board[i][j]-'0';
                    row[i][x]=1;
                    col[j][x]=1;
                    block[blk(i,j)][x]=1;
                }
            }
        }
        sudoku(board);
    }
};
