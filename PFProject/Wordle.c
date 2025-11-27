#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

// Score depends on tries taken to guess the word

int main()
{

    system("color"); 
    
    struct Tile {
        int color; // 0 for grey, 1 for yellow, 2 for green
        char letter;
    };
    

    FILE* fptr;
	// The following line will work on DEV. In Visual Studio, please provide the full path of the file
    fptr = fopen("WordsList.txt", "r"); 
    srand(time(0)); // To prevent the same random number from being generated every time the program runs
    int userCh; // To ask user if they want to play again

    printf("\nWelcome to Wordle! You have 6 tries to guess a 5-letter word\n");

    do {
		/* Generate a random number between 1 and 500 to select a word from the file by using for loop
		We use same variable (RandomNumber) to generate a random position for hint letter 1-4    
        characterFlag is used to separate the condition of letter, +, and - in the display
        correctCount represents the amount of times a correct letter is entered in a single try(present in the file)
		found is used to check whether the entered word is present in the file or not
		guessCount is used to edit the display according to the number of tries
        */
        int RandomNumber = 1 + rand() % (5757);
        int characterFlag = 0, correctCount = 0, found = 0, guessCount = 0, correctletter = 0;
        char secret[100], guess[100], fileWord[100];
        struct Tile words[6][6];

		rewind(fptr); // File pointer (FPTR) is reset to the beginning of the file to select a new secret word
        for (int i = 0; i < RandomNumber; i++)
        {
            fgets(secret, sizeof(secret), fptr);
            secret[strcspn(secret, "\r\n")] = '\0';
        }
        RandomNumber = 1 + rand() % (4);
        printf("Hint: Letter '%c' is at the position %d.\n", secret[RandomNumber - 1], RandomNumber);
       
        
        do
        {
            found = 0;

            // The following section checks whether the word input is present in our file, to prevent gibberish inputs
            do {
				rewind(fptr); // File pointer (FPTR) is reset to the beginning of the file to check the next guess
                printf("\nEnter a correct five-letter word: ");
                scanf(" %s", guess);
                while (fgets(fileWord, sizeof(fileWord), fptr))
                {
                    fileWord[strcspn(fileWord, "\r\n")] = '\0';
                    if (strcmp(fileWord, guess) == 0)
                    {
                        found = 1;
                        break;
                    }
                }
                rewind(fptr);
                if (found == 0)
                {
                    printf("\nIncorrect word.\n");
                }

            } while (found == 0);
            

            correctCount = 0;
            
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    characterFlag = 0;
                    if (guess[i] == secret[i])
                    {
                        words[guessCount][i].letter = secret[i];
                        words[guessCount][i].color = 2;
                        characterFlag = 1;
                        correctCount++;
                     
                        break;
                    }
                    else if (guess[i] == secret[j])
                    {
                        words[guessCount][i].letter = secret[j];
                        words[guessCount][i].color = 1;
                        characterFlag = 1;
                        break;
                    }
                }
                if (characterFlag == 0)
                {
                    words[guessCount][i].letter = guess[i];
                    words[guessCount][i].color = 0;
                }
            }
            
            // The following section is for giving feedback to the player about their guesses
            system("cls");
            for (int i = 0; i < guessCount + 1; i++)
            {
                printf("+---+---+---+---+---+\n");
                for (int j = 0; j < 5; j++)
                {
                    if (words[i][j].color == 0) {
                        printf("| \033[1;90m%c\033[0m ", words[i][j].letter);
                    }
                    if (words[i][j].color == 1) {
                        printf("| \033[1;93m%c\033[0m ", words[i][j].letter);
                    }
                    if (words[i][j].color == 2) {
                        printf("| \033[1;92m%c\033[0m ", words[i][j].letter);
                    }
                }
                printf("|");
                printf("\n");
                
            }
            printf("+---+---+---+---+---+");
            if (5 - guessCount != 0) {
                printf("\nYour remaining tries are %d\n", 5 - guessCount);
            }
            if (correctCount == 5)
            {
                printf("\nYou won!\n");
            }
            guessCount++;


		} while (correctCount != 5 && guessCount != 6); //Game continues until all letters are correct or tries are exhausted
        
		// Basic score calculation. Minimum score is 40 and maximum is 100
        int score = 100;
        score -= 10 * (guessCount - 1);
        printf("\nThe secret word was %s", secret);
        printf("\nYour score is %d", score);
        
        do {
            printf("\nDo you want to play again? (1 = yes, 0 = no): ");
            scanf("%d", &userCh);
            system("cls");
            if (userCh != 1 && userCh != 0) {
                printf("\nInvalid input, please enter 1 or 0.");
            }
		} while (userCh != 1 && userCh != 0);

    } while (userCh != 0);

	fclose(fptr); //Close file to avoid memory leaks

    //getch();
    return 0;
}

