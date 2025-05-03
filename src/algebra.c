#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    if(a.rows==b.rows&&a.cols==b.cols){
    int i,j;
    Matrix c=create_matrix(a.rows,a.cols);
    for(i=0;i<a.rows;i++){
        for(j=0;j<a.cols;j++){
            c.data[i][j]=a.data[i][j]+b.data[i][j];
        }
    }
    return c;
    }
    else{
        printf("Error: Matrix a and b must have the same rows and cols.\n");
    return create_matrix(0, 0);}
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    if(a.rows==b.rows&&a.cols==b.cols){
        int i,j;
        Matrix c=create_matrix(a.rows,a.cols);
        for(i=0;i<a.rows;i++){
            for(j=0;j<a.cols;j++){
                c.data[i][j]=a.data[i][j]-b.data[i][j];
            }
        }
        return c;
        }
        else{
            printf("Error: Matrix a and b must have the same rows and cols.\n");
            return create_matrix(0, 0);}
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    if(a.cols==b.rows){
        int i,j,k;
        Matrix c=create_matrix(a.rows,b.cols);
        for(i=0;i<a.rows;i++){
            for(j=0;j<b.cols;j++){
                c.data[i][j] = 0;
                for(k=0;k<a.cols;k++){
                    c.data[i][j]+=a.data[i][k]*b.data[k][j];
                }
            }
        }
        return c;
    }
    else{
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.\n");
        return create_matrix(0, 0);}
}

Matrix scale_matrix(Matrix a, double k)
{
    if(a.cols!=0&&a.rows!=0){
    int i,j;
    Matrix c=create_matrix(a.rows,a.cols);
    for(i=0;i<a.rows;i++){
        for(j=0;j<a.cols;j++){
            c.data[i][j]=a.data[i][j]*k;
        }
    }
    return c;
}
    else
    return create_matrix(0, 0);
}

Matrix transpose_matrix(Matrix a)
{
    if(a.cols!=0&&a.rows!=0){
        Matrix c=create_matrix(a.cols,a.rows);
        int i,j;
        for(i=0;i<a.rows;i++){
            for(j=0;j<a.cols;j++){
                c.data[j][i]=a.data[i][j];
            }
        }
        return c;
    }
    else
    return create_matrix(0, 0);
}

double det_matrix(Matrix a)
{
    if(a.rows==a.cols){
        if(a.rows==1){
            return a.data[0][0];}
//TODO
        
    }
    else{
        printf("Error: The matrix must be a square matrix.\n");
        return 0;}
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    if(a.rows==a.cols){
        double result=0;
        int i;
        for(i=0;i<a.rows;i++){
            result+=a.data[i][i];
        }
        return result;
    }
    else{
        printf("Error: The matrix must be a square matrix.\n");
        return 0;}
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}