class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        n = len(matrix[0])
        for j in range(0,n):
            for i in range(0,(m+1)//2):
                matrix[i][j], matrix[m-i-1][j] =  matrix[m-i-1][j], matrix[i][j]
        
        #Transpose:
        for i in range(0, m):
            for j in range(i+1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]