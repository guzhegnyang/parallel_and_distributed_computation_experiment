#include <iostream>
inline float abs(float x)
{
    return x > 0 ? x : -x;
}
struct Mat
{
    float *arr;
    size_t row;
    size_t col;
};
struct CRS
{
    float *val;
    size_t *col_ind;
    size_t *row_ptr;
    size_t row_ptr_num;
};
float arr[] = {10, 0, 0, 0, -2, 0, 3, 9, 0, 0, 0, 3, 0, 7, 8, 7, 0, 0, 3, 0, 8, 7, 5, 0, 0, 8, 0, 9, 9, 13, 0, 4, 0, 0, 2, -1};
Mat mat;
CRS crs;
void Mat2CRS(CRS &crs, Mat &mat, float eps = 1e-6)
{
    size_t index = 0;
    crs.row_ptr_num = 0;
    for (size_t i = 0; i < mat.row; i++)
    {
        bool first = true;
        for (size_t j = 0; j < mat.col; j++)
        {
            if (abs(mat.arr[i * mat.col + j]) > eps)
            {
                if (first)
                {
                    first = false;
                    crs.row_ptr[crs.row_ptr_num++] = index;
                }
                crs.val[index++] = mat.arr[i * mat.col + j];
                crs.col_ind[index++] = j;
            }
        }
    }
}
int main()
{
    mat.arr = arr;
    mat.row = 6;
    mat.col = 6;
    Mat2CRS(crs, mat);
    return 0;
}