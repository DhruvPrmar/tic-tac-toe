#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void board(char *a);
int checkForWin(char *a);
void rules();

int main()
{
    char u1[50], u2[50];
    char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int choice, s, score = -1;
    char symbol;
    int player = 1;
    int play;
    time_t t;
    time(&t);
    FILE *p;

    system("color 03");
    rules();
    printf("Type 1 to start the game: \n");
    printf("Type 2 to view the leader board: \n");
    printf("Type 3 to reset the leader board: \n");
    scanf("%d", &s);

    switch (s)
    {
    case 1:
        do
        {
            p = fopen("leaderBoard.txt", "a+");
            fprintf(p, "\n%s", ctime(&t));

            printf("Enter name for Player1(X): ");
            scanf("%s", &u1);
            strupr(u1);
            fprintf(p, "\t%s", u1);
            printf("Enter name for Player2(0): ");
            scanf("%s", &u2);
            strupr(u2);
            fprintf(p, "\t%s", u2);
            fclose(p);
            !strcmp(u1, u2) ? printf("Enter different names: \n\n") : false;
        } while (!strcmp(u1, u2));
        board(a);

        do
        {

            system("color f3");
            player = ((player % 2) ? 1 : 2);

            if (player == 1)
                printf(" %s(X) type any number from 1-9 : ", u1);
            else
                printf(" %s(0) type any number from 1-9 : ", u2);
            scanf("%d", &choice);
            symbol = (player == 1) ? 'X' : '0';

            if (choice == 1 && a[0] == '1')
                a[0] = symbol;
            else if (choice == 2 && a[1] == '2')
                a[1] = symbol;
            else if (choice == 3 && a[2] == '3')
                a[2] = symbol;
            else if (choice == 4 && a[3] == '4')
                a[3] = symbol;
            else if (choice == 5 && a[4] == '5')
                a[4] = symbol;
            else if (choice == 6 && a[5] == '6')
                a[5] = symbol;
            else if (choice == 7 && a[6] == '7')
                a[6] = symbol;
            else if (choice == 8 && a[7] == '8')
                a[7] = symbol;
            else if (choice == 9 && a[8] == '9')
                a[8] = symbol;
            else
            {
                printf("Invalid Input");
                player--;
            }
            score = checkForWin(a);
            player++;
            board(a);
        } while (score == -1);
        fopen("leaderBoard.txt", "a+");
        if (score == 1)
        {
            if (player == 2)
            {
                printf("*****Congrats %s you win!!!*****", u1);
                fprintf(p, "\t%s WON", u1);
            }
            else
            {
                printf("*****Congrats %s you win!!!*****", u2);
                fprintf(p, "\t%s WON", u2);
            }
        }
        else
        {
            printf("\n\n*****Game Draws!*****\n\n");
            fprintf(p, "\tDraw");
        }
        fclose(p);
        break;
    case 2:
        system("leaderBoard.txt");
        break;
    case 3:
        system("del leaderBoard.txt");
        break;
    default:
        printf("Invalid Input\n");
        break;
    }

    return 0;
}

void board(char *a)
{
    printf("\t    |    |    \n");
    printf("\t %c  | %c  | %c  \n", a[0], a[1], a[2]);
    printf("\t----|----|----\n");
    printf("\t    |    |    \n");
    printf("\t %c  | %c  | %c  \n", a[3], a[4], a[5]);
    printf("\t----|----|----\n");
    printf("\t    |    |    \n");
    printf("\t %c  | %c  | %c  \n", a[6], a[7], a[8]);
    printf("\t    |    |    \n");
}

int checkForWin(char *a)
{
    if (a[0] == a[1] && a[1] == a[2])
        return 1;
    else if (a[3] == a[4] && a[4] == a[5])
        return 1;
    else if (a[6] == a[7] && a[7] == a[8])
        return 1;
    else if (a[0] == a[3] && a[3] == a[6])
        return 1;
    else if (a[1] == a[4] && a[4] == a[7])
        return 1;
    else if (a[2] == a[5] && a[5] == a[8])
        return 1;
    else if (a[0] == a[4] && a[4] == a[8])
        return 1;
    else if (a[2] == a[4] && a[4] == a[6])
        return 1;
    else if (a[0] != '1' && a[1] != '2' && a[2] != '3' && a[3] != '4' && a[4] != '5' && a[5] != '6' && a[6] != '7' && a[7] != '8' && a[8] != '9')
        return 0;
    else
        return -1;
}

void rules()
{
    char link;
    printf("\033[0;36m");
    printf("\tTic-Tac-Toe\n\n");
    printf("Welcome to the most played 2D game and a sort of fun using X and O\n\n");
    printf("Rules:-\n");
    printf("\n1:Each player will be entering the number to put respective X or O in the desired position");
    printf("\n2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner");
    printf("\033[0m");
    printf("\n\nEnjoy the game! Be a Winner!\n\n");
    printf("For more clarifications press Y else type any other character:- ");
    scanf("%c", &link);
    if (link == 'y' || link == 'Y')
    {
        system("start http://www.wikihow.com/Play-Tic-Tac-Toe");
    }
}