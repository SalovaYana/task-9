#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void print_menu()
{
    printf("\nWhat do you want to watch?\n");
    printf("0. exit\n");
    printf("1. 9.1\n");
    printf("2. 9.2\n");
    printf("3. 9.3\n");
    printf("4. 9.4\n");
}

void program91 ()
{
    int i,j,n,m, **mas;

    printf("¬ведите размерность матрицы m*n:\n");
    scanf("%d %d", &m, &n);

    mas = (int**) malloc(m*sizeof(int*));

    for (i = 0; i < m; i++)
    {
        mas[i] = (int*) malloc(n*sizeof(int));
    }

    printf("\n¬веди матрицу\n");

    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            scanf("%d",&mas[i][j]);

    printf("исходна€ матрица:\n");

    for (i=0; i<m; i++, printf("\n"))
        for (j=0; j<n; j++)
            printf("%d ", mas[i][j]);

    int b[m*n];


    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
        {
            b[i*n+j]=mas[i][j];

        }


    printf("новый одномерный массив:\n");

    for (i=0; i<m*n; i++)
        printf("%d ", b[i]);

    printf("\n");

    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            mas[i][j]=0;
    printf("записываем элементы обратно в двумерный массив:\n");

    for (i=0; i<m*n; i++)

    {
        mas[i/n][i%n]= b[i];

    }

    for (i=0; i<m; i++, printf("\n"))
        for (j=0; j<n; j++)
            printf("%d ", mas[i][j]);

}

void program92()
{

    int n, m;

    int up = 0, down = 0, right = 0, left = 0;

    int j = 0,i = 0;

    int count = 1;

    int **a;

    printf("¬ведите размерность матрицы m*n\n");
    scanf("%d%d", &m, &n);

    a = (int**) malloc(m*sizeof(int*));

    for (i = 0; i < m; i++)
      a[i] = (int*) malloc(n*sizeof(int));

    printf ("\nѕервый вариант:\n");

    for (i=0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = abs(i-j) + 1;
            printf("%3d", a[i][j]);
        }

        printf("\n");
    }
    i = j = 0;

    while (count <= m * n)
    {
        a[i][j] = count;
        if (i == up && j < n - right - 1)
            j++;


        else if (j == n - right - 1 && i < m - down - 1)
            i++;


        else if (i == m - down - 1 && j > left)
            j--;

        else
           i--;

        if ((i == up + 1) && (j == left) && (left != n - right - 1))
        {
            up++;
            down++;
            left++;
            right++;
        }
        count++;
    }

    printf ("\n¬торой вариант:\n");
    for (i = 0; i < m; i++)
    {

        for (j = 0; j < n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }

}
void program93 ()

{
    int i,j, n, **mas, sum=0;
    printf("введи размерность квадратной матрицы n= ");
    scanf("%d", &n);

    mas = (int**) malloc(n*sizeof(int*));

    for (i = 0; i < n; i++)
    {
        mas[i] = (int*) malloc(n*sizeof(int));
    }


    printf("¬ведите элементы квадратной матрицы %d на %d\n", n,n);

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &mas[i][j]);


    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if((j>=i && j<=n-1-i) || (j<=i && j>=n-1-i))
            {
                sum = sum + mas[i][j];
                printf("%d   ", mas[i][j]);
            }

        }
    }

    printf("\n —умма элементов 1 варианта задани€ (<<песочные часы>>) = %d", sum);

}

void quicksort(int n, int k,  int *sum, int **matr)
{

    int i = 0;
    int j = n - 1;

    int temp;
    int mid = sum[(i + j) / 2];

    do
    {

        while(sum[i] < mid)
            i++;

        while(sum[j] > mid)
            j--;


        if(i <= j)
        {
            int *t = (int *) malloc(sizeof(int) * k);
            t = matr[i];
            matr[i] = matr[j];
            matr[j] = t;

            temp = sum[i];
            sum[i] = sum[j];
            sum[j] = temp;
            i++;
            j--;
        }

    }
    while(i <= j);


    if(j > 0)
        quicksort(j, k, sum, matr);

    if(n > i)
        quicksort(n - i, k, sum + i, matr + i);

}

void program94()
{
    int m, n,i,j;

    printf("¬ведите размерность матрицы m*n:\n");
    scanf("%d %d", &m, &n);

    printf("¬ведите элементы матрицы:\n");

    int **matr = (int**) malloc(sizeof(int*)* m);
    int *row_sum = (int*) malloc(sizeof(int*)* m);

    for(int i = 0; i < m; ++i)
    {
        matr[i] = (int*) malloc(sizeof(int)*n);
        row_sum[i] = 0;
        for(int j = 0; j < n; ++j)
        {
            scanf("%d", &matr[i][j]);
            row_sum[i] += matr[i][j];
        }
    }

    printf("исходна€ матрица:\n");

    for (i=0; i<m; i++, printf("\n"))
        for (j=0; j<n; j++)
            printf("%d ", matr[i][j]);

    quicksort(m, n, row_sum, matr);

    printf("\n");
    printf("ќтсортированна€ матрица\n");

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }


}



int main()
{
    setlocale(LC_ALL,"Rus");
    int k=1, variant;

    while (k)
    {
        print_menu();
        printf("\nchoose the number = ");
        scanf("%d", &variant);

        switch (variant)
        {
        case 0:
            k=0;
            break;
        case 1:
            program91();
            break;

        case 2:
            program92();
            break;
        case 3:
            program93();
            break;

        case 4:
            program94();
            break;

        }

        variant=0;
    }


    return 0;
}
