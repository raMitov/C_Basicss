#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{   
    char os;
    #ifdef _WIN32
        os = 'w';
    #elif __linux__
        os = 'l';
    #endif

    char* users = NULL;
    const char* userName = NULL;
    if(os == 'l')
    {
     userName = getenv("USER");
    }
    else if(os == 'w')
    {
    userName = getenv("USERNAME");
    }

     if(userName != NULL)
     {
         users = (char*)malloc(strlen(userName)+1);
         if(users != NULL)
         {
             strcpy(users, userName);
         }

     }
        
    printf("You are playing a number guessing game.\nYou have 5 tries to guess the random number.\nOtherwise you die. :D\nHappy guessing!\n__________________\n");
    printf("What's the range you want to play in?\n");
    printf("From 0 to... ");
    int range;
    scanf("%d", &range);
    printf("Alright the chances are looking be slim..\nGenerating....\n");
    time_t t;
    srand((unsigned) time(&t));
    int randomNumber = rand() % (range + 1);
    int tries = 5;
    while(tries > 0)
    {
        int guess;
        printf("Have a guess :)\n");
        scanf("%d", &guess);
        if(guess < 0 || guess > range)
        {
            printf("Are you stupid..The number must be above 0 and %d.\n", range);
            continue;
        }
        if(guess < randomNumber)
        {
            tries--;
            printf("The number is higher than that.\nTries left: %d\n", tries);
            continue;
        }
        else if(guess > randomNumber)
        {
            tries--;
            printf("The number is lower than that.\nTries left: %d\n", tries);
        }
        else
        {
            
            printf("Congratulations you won the game :D");
            char filepath[256];
        if(os == 'w' && users != NULL)
         {
                snprintf(filepath, sizeof(filepath), "C:\\Users\\%s\\Desktop\\GameWonPrize.txt", users);
         } 

        
        else if(os == 'l' && users != NULL)
        {
            snprintf(filepath, sizeof(filepath), "/home/%s/Desktop/GameWonPrize.txt", users);
        }
        else {
                strcpy(filepath, "GameWonPrize.txt");
            }
        FILE *file = fopen(filepath, "w");
            if (file != NULL) {
                fprintf(file, "You won the game!\n");
                fclose(file);
            }
        break;
     }
    }
    if (tries == 0) {
        printf("You ran out of tries. The number was %d. You die. :(\n", randomNumber);
    }

    free(users);
    return 0;
}
