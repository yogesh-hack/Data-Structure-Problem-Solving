# problem : 566

# Input: mat = [[1,2],[3,4]], r = 1, c = 4
# Output: [[1,2,3,4]]

class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        # Check if it is possible to reshape the matrix
        m, n = len(mat), len(mat[0])
        if m * n != r * c:
            return mat
        
        # Create a new matrix of size r x c
        new_mat = [[0] * c for _ in range(r)]
        
        # Traverse the original matrix in row-major order
        index = 0
        for i in range(r):
            for j in range(c):
                # Fill in the values of the new matrix
                row, col = divmod(index, n)
                new_mat[i][j] = mat[row][col]
                index += 1
                
        return new_mat
