class Solution:
    def setZeroes(self, matrix: [[]]) -> [[]]:
        row, col = len(matrix), len(matrix[0])
        for i in range(row):
            for j in range(col):
                if matrix[i][j] == 0:
                    self.markCoords(i, j, matrix)

        for i in range(row):
            for j in range(col):
                if matrix[i][j] == -1:
                    matrix[i][j] = 0

        return matrix

    def markCoords(self, i, j, matrix):
        row, col = len(matrix), len(matrix[0])
        for k in range(row):
            if matrix[k][j] != 0:
                matrix[k][j] = -1
        for k in range(col):
            if matrix[i][k] != 0:
                matrix[i][k] = -1
        return matrix


if __name__ == "__main__":
    solution: Solution = Solution()
    print(solution.setZeroes([[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]))
    # print(solution.markCoords(1, 1, [[1, 1, 1], [1, 0, 1], [1, 1, 1]]))
