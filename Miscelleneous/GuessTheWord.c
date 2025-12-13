#include <stdio.h>
#include <string.h>
int main()
{
    char board[6][6]= {
        "catod",
        "banxo",
        "alnug",
        "tsunq",
        "honey",
    };
    char guess[6];
    int correct=0, length;
    do
    {
        printf("\n\n");
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                printf(" %c ", board[i][j]);
            }
            printf("\n");
        }
        
        printf("\n");
        printf("Enter your word.\n");
        scanf(" %s", guess);
        length = strlen(guess);
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j <= 6-length; j++)
            {
                correct=0;
                for (int k = j; k < length+j; k++)
                {
                    if (guess[k-j]==board[i][k])
                    {
                        correct++;
                    }
                }
                if (correct==length)
                {
                    printf("The word was found in the %d row of the board.\n", i+1);
                }
            }
        }
        for (int j = 0; j < 5; j++)
        {
            for (int i = 0; i <= 6-length; i++)
            {
                correct=0;
                for (int k = i; k < length+i; k++)
                {
                    if (guess[k-i]==board[k][j])
                    {
                        correct++;
                    }
                }
                if (correct==length)
                {
                    printf("The word was found in the %d column of the board.\n", j+1);
                }
            }
        }
    } while (1);
return 0;
}