#include <iostream>
#include <new>
#include <math.h>
#include <unordered_set>
#include <vector>


//EX4.a)!!EX4.a)
int sumDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return n % 10 + sumDigits(n / 10);
}
//************************************
//************************************

//EX3!!EX3
bool isValidSudoku(int** board, int boardSize) {
    int size = boardSize * boardSize;
    for (int i = 0; i < size; i++) {
        std::unordered_set<int> rowSet, colSet;
        for (int j = 0; j < size; j++) {
            int rowVal = board[i][j];
            int colVal = board[j][i];
            if (rowSet.count(rowVal) || colSet.count(colVal)) {
                return false;
            }
            rowSet.insert(rowVal);
            colSet.insert(colVal);
        }
    }
    for (int row = 0; row < size; row += boardSize) {
        for (int col = 0; col < size; col += boardSize) {
            std::unordered_set<int> boxSet;
            for (int i = 0; i < boardSize; i++) {
                for (int j = 0; j < boardSize; j++) {
                    int val = board[row + i][col + j];
                    if (boxSet.count(val)) {
                        return false;
                    }
                    boxSet.insert(val);
                }
            }
        }
    }
    return true;
}
//EX1!!EX1
//creating matrix
std::vector<std::vector<float>> createMatrix(int rows, int cols) {
    std::vector<std::vector<float>> matrix(rows, std::vector<float>(cols, 0));

    std::cout << "enter " << rows * cols << "floating point numbers";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }
    return matrix;
}
//printing vector matrix
void printVectorMatrix(const std::vector<std::vector<float>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
    }
}
//adding two matrices
void sumMatrices (const std::vector<std::vector<float>> &matrix1,
    const std::vector<std::vector<float>> &matrix2, std::vector<std::vector<float>> &result) {
    if (matrix1.size() != matrix2.size() && matrix1[0].size() != matrix2[0].size()) {
        return;
    }
    if (matrix1.size() != result.size() && matrix1[0].size() != result[0].size()) {
        return;
    }
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1[0].size(); j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}
//subtracting two matrices
void subtractMatrices(std::vector<std::vector<float>> &matrix1, const std::vector<std::vector<float>> &matrix2) {
    if (matrix1.size() != matrix2.size() && matrix1[0].size() != matrix2[0].size()) {
        return;
    }
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix1[0].size(); j++) {
            matrix1[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
//matrix multiplication
void multiplyMatrices(const std::vector<std::vector<float>> &matrix1,
                      const std::vector<std::vector<float>> &matrix2,
                      std::vector<std::vector<float>> &result) {
    if (matrix1[0].size() != matrix2.size()) {
        return; // Matrix multiplication is not possible
    }

    int rows = matrix1.size();
    int cols = matrix2[0].size();
    int common_dim = matrix1[0].size();

    result.assign(rows, std::vector<float>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < common_dim; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
//transponating matrix
void transponateMatrix(const std::vector<std::vector<float>> &matrix) {
    std::vector<std::vector<float>> result(matrix[0].size(), std::vector<float>(matrix.size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            result[j][i] = matrix[i][j];
        }
    }
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            std::cout << result[i][j] << " ";
        }
    }
}



int main() {
    // int n4a = -123456789;
    // std::cout << sumDigits(n4a) << std::endl;
    //EX3
    // int n3;
    // std::cin >> n3;
    //
    // int n3MatSize = n3 * n3;
    //
    // int** board = new int*[n3MatSize];
    // for (int i = 0; i < n3MatSize; i++) {
    //     board[i] = new int[n3MatSize];
    // }
    //
    // for (int i = 0; i < n3MatSize; i++) {
    //     for (int j = 0; j < n3MatSize; j++) {
    //         std::cin >> board[i][j];
    //     }
    // }
    //
    // if (isValidSudoku(board, n3)) {
    //     std::cout << "YES" << std::endl;
    // }else std::cout << "NO" << std::endl;
    //
    // for (int i = 0; i < n3MatSize; i++) {
    //     delete[] board[i];
    // }
    //
    // delete[] board;
    //END OF EX3

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.