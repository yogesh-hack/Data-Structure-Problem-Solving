# problem : 36

# Input: board = 
# [["5","3",".",".","7",".",".",".","."]
# ,["6",".",".","1","9","5",".",".","."]
# ,[".","9","8",".",".",".",".","6","."]
# ,["8",".",".",".","6",".",".",".","3"]
# ,["4",".",".","8",".","3",".",".","1"]
# ,["7",".",".",".","2",".",".",".","6"]
# ,[".","6",".",".",".",".","2","8","."]
# ,[".",".",".","4","1","9",".",".","5"]
# ,[".",".",".",".","8",".",".","7","9"]]
# Output: true

class Solution:

    def check_arr_valid(self, arr):
        num_set = set()
        for num in arr:
            if num == '.':
                continue
            if int(num) > 9 or int(num) < 1:
                return False
            if num in num_set:
                return False
            num_set.add(num)
        return True

    def create_col_list(self,board):
        cols = []
        for col in range(0,len(board)):
            col_list = []
            for row in range(0,len(board)):
                col_list.append(board[row][col])
            cols.append(col_list)
        return cols

    def create_boxes_list(self,board):
        start_rows = [0,3,6]
        start_cols = [0,3,6]

        boxes = []
        for start_col in start_cols:
            for start_row in start_rows:
                box=[]
                for i in range(start_col,start_col+3):
                    for j in range(start_row,start_row+3):
                        box.append(board[i][j])
                boxes.append(box)
        return boxes


    def isValidSudoku(self, board: List[List[str]]) -> bool:
        cols = self.create_col_list(board)
        boxes = self.create_boxes_list(board)

        for row in board:
            if not self.check_arr_valid(row):
                return False

        for col in cols:
            if not self.check_arr_valid(col):
                return False

        for box in boxes:
            if not self.check_arr_valid(box):
                return False
        
        return True
        
        
