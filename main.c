#include <stdio.h>
#include <stdlib.h>

const int m=2, n=3;
int main()
{
    int i,j;


    int mas [m] [n];
    printf("\nvvedi massiv\n");

    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            scanf("%d",&mas[i][j]);

    for (i=0; i<m; i++, printf("\n"))
        for (j=0; j<n; j++)
            printf("%d ", mas[i][j]);

    int b[m*n];


    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
        {
            b[i*n+j]=mas[i][j];

        }

    printf("\n");

    for (i=0; i<m*n; i++)
        printf("%d ", b[i]);

    printf("\n");

    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            mas[i][j]=0;


    for (i=0; i<m*n; i++)

        {
              mas[i/n][i%n]= b[i];

        }

    for (i=0; i<m; i++, printf("\n"))
        for (j=0; j<n; j++)
            printf("%d ", mas[i][j]);



    return 0;
}
