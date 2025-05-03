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
    else{
    return create_matrix(0, 0);}
}

double det_matrix(Matrix a)
{
    if(a.rows==a.cols){
        double result=0;
        if(a.rows==1){
            return a.data[0][0];}
        if(a.rows==2){
            result=a.data[0][0]*a.data[1][1]-a.data[1][0]*a.data[0][1];
            return result;
        }
        else{
            for(int i=0;i<a.cols;i++){
                result+=(i % 2 == 0 ? 1 : -1)*a.data[0][i]*det_matrix(minor_matrix(a,0,i));
            }
            return result;
        }
      
    }
    else{
        printf("Error: The matrix must be a square matrix.\n");
        return 0;}
}

Matrix inv_matrix(Matrix a)
{
    if(a.rows==a.cols){
        if(det_matrix(a)!=0){
            Matrix c=create_matrix(a.rows,a.cols);
            int i,j;
            double d=det_matrix(a);
            for(i=0;i<a.rows;i++){
                for(j=0;j<a.cols;j++){
                    c.data[i][j]=1/d*((i+j) % 2 == 0 ? 1 : -1)*det_matrix(minor_matrix(a,j,i));
                }
            }
            return c;
        }
        else{
            printf("Error: The matrix is singular.\n");
            return create_matrix(0, 0);
        }
    }
    else{
        printf("Error: The matrix must be a square matrix.\n");
        return create_matrix(0, 0);}
}

int rank_matrix(Matrix a)
{
    int max_rank = (a.rows < a.cols) ? a.rows : a.cols;

    for (int r = max_rank; r >= 1; r--) {
        for (int i = 0; i <= a.rows - r; i++) {
            for (int j = 0; j <= a.cols - r; j++) {
                Matrix sub = create_matrix(r, r);
                for (int x = 0; x < r; x++) {
                    for (int y = 0; y < r; y++) {
                        sub.data[x][y] = a.data[i + x][j + y];
                    }
                }
                if (fabs(det_matrix(sub)) > 1e-8) {
                    return r;
                }
            }
        }
    }
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

Matrix minor_matrix(Matrix a,int x,int y){
    Matrix c=create_matrix(a.rows-1,a.cols-1);
    int i,j,r=0,s=0;
    for(i=0;i<a.rows;i++){
        if(i==x){continue;}
        s=0;
        for(j=0;j<a.cols;j++){
            if(j==y){continue;}
            c.data[r][s]=a.data[i][j];
            s++;
        }
        r++;
    }
    return c;
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