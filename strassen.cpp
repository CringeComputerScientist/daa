#include <iostream>
#include <vector>
using namespace std;

#define ROW_1 4
#define COL_1 4

#define ROW_2 4
#define COL_2 4

void add_matrix(vector<vector<int>> matrix_A,vector<vector<int>> matrix_B,vector<vector<int>> &matrix_C,int index)
{
    for (auto i = 0; i < index; i++)
        for (auto j = 0; j < index; j++)
            matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
}

vector<vector<int>> matrix(vector<vector<int>> matrix_A,vector<vector<int>> matrix_B)
{
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    int row_2 = matrix_B.size();

    vector<int> result_matrix_row(col_2, 0);
    vector<vector<int>> result_matrix(row_1,result_matrix_row);

    if (col_1 == 1)
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    else
    {
        int index = col_1 / 2;

        vector<int> row_vector(index, 0);
        vector<vector<int>> result_matrix_00(index,row_vector);
        vector<vector<int>> result_matrix_01(index,row_vector);
        vector<vector<int>> result_matrix_10(index,row_vector);
        vector<vector<int>> result_matrix_11(index,row_vector);

        vector<vector<int>> a00(index, row_vector);
        vector<vector<int>> a01(index, row_vector);
        vector<vector<int>> a10(index, row_vector);
        vector<vector<int>> a11(index, row_vector);
        vector<vector<int>> b00(index, row_vector);
        vector<vector<int>> b01(index, row_vector);
        vector<vector<int>> b10(index, row_vector);
        vector<vector<int>> b11(index, row_vector);

        for (auto i = 0; i < index; i++)
            for (auto j = 0; j < index; j++)
            {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + index];
                a10[i][j] = matrix_A[index + i][j];
                a11[i][j] = matrix_A[i + index][j + index];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + index];
                b10[i][j] = matrix_B[index + i][j];
                b11[i][j] = matrix_B[i + index][j + index];
            }

        add_matrix(matrix(a00, b00),matrix(a01, b10),result_matrix_00, index);
        add_matrix(matrix(a00, b01),matrix(a01, b11),result_matrix_01, index);
        add_matrix(matrix(a10, b00),matrix(a11, b10),result_matrix_10, index);
        add_matrix(matrix(a10, b01),matrix(a11, b11),result_matrix_11, index);

        for (auto i = 0; i < index; i++)
            for (auto j = 0; j < index; j++)
            {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + index] = result_matrix_01[i][j];
                result_matrix[index + i][j] = result_matrix_10[i][j];
                result_matrix[i + index][j + index] = result_matrix_11[i][j];
            }

        result_matrix_00.clear();
        result_matrix_01.clear();
        result_matrix_10.clear();
        result_matrix_11.clear();
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
    }
    return result_matrix;
}

int main()
{
    vector<vector<int>> matrix_A = {{1, 1, 1, 1},{2, 2, 2, 2},{3, 3, 3, 3},{2, 2, 2, 2}};

    vector<vector<int>> matrix_B = {{1, 1, 1, 1},{2, 2, 2, 2},{3, 3, 3, 3},{2, 2, 2, 2}};

    vector<vector<int>> result_matrix(
        matrix(matrix_A, matrix_B));
}
