#include <bits/stdc++.h> 

bool isSafe(int row, int col, vector<vector<int>>& board,int val){
    for(int i = 0;i < board.size(); i++){
        // check row
        if(board[row][i] == val){
            return false;
        }
        // check column
        if(board[i][col] == val){
            return false;
        }
        // check 3x3 matrix
        if(board[3*(row/3) + i/3][3*(col/3)+ i%3] == val){
            return false;
        }
    }
    return true;
}


bool solve(vector<vector<int>>& board){

    int n = board[0].size();

    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            if(board[row][col] == 0){
                // trying to put 1 to 9 in empty cell
                for(int val = 1; val <= 9; val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col] = val;

                        // recursive call
                        // if solution is possible
                        bool possible = solve(board);
                        if(possible){
                            return true;
                        }
                        else{
                            // backtrack
                            board[row][col] = 0;
                        }
                    }
                }
            // solution is not possible
            return false;
            }
        }
    }
    return true;
}


void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}
