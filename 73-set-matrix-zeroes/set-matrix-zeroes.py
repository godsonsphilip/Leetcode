class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n1, n2 = len(matrix), len(matrix[0])
        row = [1]*n2
        col = [1]*n1
        for i in range(0, n1):
            for j in range(0, n2):
                if matrix[i][j]==0:
                    row[j] = 0
                    col[i] = 0
        
        for i in range(0, n1):
            for j in range(0, n2):
                if(not row[j] or not col[i]):
                    matrix[i][j] = 0