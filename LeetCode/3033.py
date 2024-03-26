class Solution:
    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        max_in_columns = [max(column) for column in zip(*matrix)]
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == -1:
                    matrix[i][j] = max_in_columns[j]
        return matrix
