class Solution(object):
    def spiralOrder(self, matrix):
        result = []
        top, bottom = 0, len(matrix)
        left, right = 0, len(matrix[0])

        while left < right and top < bottom:
            # Traverse from Left to Right
            i = left
            while i < right:
                result.append(matrix[top][i])
                i += 1
            top += 1

            # Traverse from Top to Bottom
            i = top
            while i < bottom:
                result.append(matrix[i][right - 1])
                i += 1
            right -= 1

            # Check if we still have rows and columns left
            if not (left < right and top < bottom):
                break

            # Traverse from Right to Left
            i = right - 1
            while i >= left:
                result.append(matrix[bottom - 1][i])
                i -= 1
            bottom -= 1

            # Traverse from Bottom to Top
            i = bottom - 1
            while i >= top:
                result.append(matrix[i][left])
                i -= 1
            left += 1

        return result
