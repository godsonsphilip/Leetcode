class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        
        m = len(matrix)
        n = len(matrix[0])
        row0 = 1
        for i in range(0, m):
            for j in range(0, n):
                if i==0:
                    if matrix[0][j]==0:
                        row0 = 0
                        continue

                if matrix[i][j]==0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0
        
        for i in range(1, m):
            for j in range(1,n):
                if matrix[0][j]==0 or matrix[i][0]==0:
                    matrix[i][j] = 0
        if matrix[0][0]==0:
            for i in range(1,m):
                matrix[i][0] = 0
        
        if row0 == 0:
            for i in range(0, n):
                matrix[0][i] = 0