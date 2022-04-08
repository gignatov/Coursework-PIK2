#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int N, M, K, i, j, count=0;
    //Деклариране променливите N, M, K, i, j, count.
    printf("Enter number of rows N: ");
    scanf("%d",&N);
    printf("\nEnter number of stairs in a row M: ");
    scanf("%d",&M);
    printf("\nEnter number for comparison K: ");
    scanf("%d",&K);
    //Четене на данни за стойностите на N, M, K.
    N++;
    //Увеличаване на N с 1.
    int arr[N][M];
    //Деклариране на двумерен масив arr[N][M].
    srand(time(NULL));
    //Задаване на условие за rand() чрез srand(), използвайки текущото време.
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            arr[i][j] = rand() % 500;
            arr[i][j]++;
        }
    }
    //Създаване на случайно число между 0 и 500 за всеки елемент на масива arr.
    for (j = 0; j < M; j++)
    {
        arr[0][j] = 0;
    }
    //Задаване на стойност 0 за всеки елемент от нулевия ред на масива arr.
    for(i = N - 1; i > 0; i--)
    {
        if (i < 10)
        {
            printf("\n %d: ",i);
        }
        else printf("\n%d: ",i);
        for(j = 0; j < M; j++)
        {
            if (arr[i][j] < 10)
            {
                printf("  %d ", arr[i][j]);
            }
            if (arr[i][j] < 100 && arr[i][j] > 9)
            {
                printf(" %d ", arr[i][j]);
            }
            if (arr[i][j] > 99)
            {
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n\n\n");
    //Показване на екрана стойностите на елементите от масива.
    for (i = N - 1; i > 0; i--)
    {
        if (i < 10)
        {
            printf("\n %d: ",i);
        }
        else printf("\n%d: ",i);
        for (j = 0; j < M; j++)
        {
            if (arr[i][j] - i - 1 <= K)
            {
                if (arr[i][j] < 10)
                {
                    printf("  %d ", arr[i][j]);
                }
                if (arr[i][j] < 100 && arr[i][j] > 9)
                {
                    printf(" %d ", arr[i][j]);
                }
                if (arr[i][j] > 99)
                {
                    printf("%d ", arr[i][j]);
                }
            }
            else printf ("___ ");
        }
    }
    //Показване на екрана на стойностите, които отговарят на условието на задачата.
    for (i = 1; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (arr[i][j] - i - 1 <= K)
            {
                count++;
                j = M - 1;
            }
            //Ако елементът отговаря на условието, добавяне на единица към брояч count и прескачане на останалите стойности от дадения ред на масива.
        }
        if (count != i)
        {
            printf("\n\nFailed at row %d\n", i);
            break;
        }
        //Ако стойността на брояча се различава от стойността на реда, изписване на екрана реда, на който няма подходяща стойност.
    }
    if (count == N - 1)
    {
        printf ("\n\nToday I'll eat honey\n");
    }
    //Ако стойността на брояча се равнява на броя на редовете (N - 1), изписване на екрана Today I'll eat honey.
    return 0;
}
