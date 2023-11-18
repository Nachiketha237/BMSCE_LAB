#include <stdio.h>
#include <stdlib.h>
void MatrixAdd(int m1, int m2, int n1, int n2, int **a, int **b)
{
    if (m1 == m2 && n1 == n2)
    {
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n1; j++)
            {    printf("%d ", a[i][j] );
             printf("%d ", b[i][j]);
                printf("%d ", a[i][j] + b[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else
        printf("matrix addition is Incompatable");
}
void MatrixSub(int m1, int m2, int n1, int n2, int **a, int **b)
{
    if (m1 == m2 && n1 == n2)
    {
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                printf("%d ", a[i][j] - b[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else
        printf("matrix substraction is Incompatable");
}
void MatrixMultiply(int m1, int m2, int n1, int n2, int **a, int **b)
{
    if (m1 == n2 && n1 == m2)
    {
        int k;
        int sum = 0;
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                sum += a[i][j] * b[j][i];
            }
            printf("%d ", sum);
            sum = 0;
        }
        printf("\n");
    }
    else
        printf("matrix multiplication is Incompatable");
}
void MatrixTranspose(int m1, int n1, int **a,int m2, int n2, int **b)
{

    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void MatrixRowAdd(int m, int n, int **a)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
        printf("%d ", sum);
        sum = 0;
    }
    printf("\n");
}
void MatrixColAdd(int m, int n, int **a)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
        printf("%d ", sum);
        sum = 0;
    }
    printf("\n");
}
int main()
{
    int n1, m1, n2, m2;
    printf("Enter the order of the first matrix:\n");
    scanf("%d%d", &m1, &n1);
    int **a = (int **)malloc(m1 * n1 * sizeof(int));
    printf("Enter the order of the second matrix:\n");
    scanf("%d%d", &m2, &n2);
    int **b = (int **)malloc(m2 * n2 * sizeof(int));

    printf("Enter the elements into the first matrix:\n");
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements into the second matrix:\n");
    for (int i = 0; i < m2; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    int choice;
    while (1)
    {
        printf("Choose the matrix operation:\n\n 1.Matrix addition\n 2.Matrix Substraction\n 3.Matrix multiplication\n 4.Transpose of Matrix\n 5.Row Addition\n 6.Column Addition\n 7.Exit\n\n");
        printf("Enter your choice:  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            MatrixAdd(m1, m2, n1, n2, a, b);
            break;
        case 2:
            MatrixSub(m1, m2, n1, n2, a, b);
            break;
        case 3:
            MatrixMultiply(m1, m2, n1, n2, a, b);
            break;
        case 4:
            MatrixTranspose(m1, n1, a, m2,n2,b);
            break;
        case 5:
            MatrixRowAdd(m1, n1, a);
            break;
        case 6:
            MatrixColAdd(m2, n2, b);
            break;
        case 7:
            exit(0);
        }
    }
    return 0;
}
