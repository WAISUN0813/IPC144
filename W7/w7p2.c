/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  :WaiSunLam
Student ID#:146691225
Email      :wslam4@myseneca.ca
Section    :E
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define max_Size 70 
struct playerConfigurations
{
    int player_Lives;
    int moves;
    char history[max_Size];
    int moving;
    int treasure_Own;
    char player_Symbol;
}player;

struct gameConfigurations
{

    int max_Moves;
    int path;
    int bomb[max_Size];
    int treasure[max_Size];

}game;

int main(void)
{
    int i, j, c = 0;
    struct playerConfigurations player;
    struct gameConfigurations game;
    player.moving = 0;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\nPLAYER Configuration\n--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.player_Symbol);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.player_Lives);

        if (player.player_Lives < 1 || player.player_Lives > 10)
        {
            printf("     Must be between 1 and 10!\n");
        }

    } while (player.player_Lives < 1 || player.player_Lives > 10);

    printf("Player configuration set-up is complete\n\n");


    printf("GAME Configuration\n------------------\n");
    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf(" %d", &game.path);

        if (game.path < 10 || game.path > max_Size || game.path % 5 != 0)
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (game.path < 10 || game.path > max_Size || game.path % 5 != 0);

    game.max_Moves = game.path * 0.75;

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &player.moves);
        if (player.moves < 3 || player.moves > game.max_Moves)
        {
            printf("    Value must be between 3 and %d\n", game.max_Moves);
        }
    } while (player.moves < 3 || player.moves > game.max_Moves);

    printf("\nBOMB Placement\n--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");
    for (i = 0; i < game.path / 5; i++)
    {
        printf("   Positions [%2d-%2d]: ", 5 * i + 1, 5 * i + 5);
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &game.bomb[(5 * i) + j]);
        }
    }
    printf("BOMB placement set\n");

    printf("\nTREASURE Placement\n------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");
    for (i = 0; i < game.path / 5; i++)
    {
        printf("   Positions [%2d-%2d]: ", 5 * i + 1, 5 * i + 5);
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &game.treasure[(5 * i) + j]);
        }
    }

    printf("TREASURE placement set\n");

    printf("\nGAME configuration set-up is complete...\n");
    printf("\n------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.player_Symbol);
    printf("   Lives      : %d\n", player.player_Lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");

    printf("\nGame:");
    printf("\n   Path Length: %d", game.path);
    printf("\n   Bombs      : ");
    for (i = 0; i < game.path; i++)
    {
        printf("%d", game.bomb[i]);
    }
    printf("\n");

    printf("   Treasure   : ");
    for (i = 0; i < game.path; i++)
    {
        printf("%d", game.treasure[i]);
    }
    printf("\n");
    printf("\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    player.treasure_Own = 0;
    do
    {

        if (player.moving > 0)
        {
            for (i = 0; i < player.moving + 1; i++)
            {
                printf(" ");
            }
            printf("%c", player.player_Symbol);
        }
        printf("\n");
        printf("  ");
        if (c == 0)
        {
            for (i = 0; i < game.path; i++)
            {
                player.history[i] = '-';
                printf("%c", player.history[i]);
            }
            c = 1;
        }
        else {
            for (i = 0; i < game.path; i++) {
                printf("%c", player.history[i]);
            }

        }
        printf("\n  ");
        for (i = 1; i <= game.path; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n  ");

        for (i = 1; i <= game.path; i++)
        {
            printf("%d", i % 10);
        }
        printf("\n+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.player_Lives, player.treasure_Own, player.moves);
        printf("+---------------------------------------------------+\n");
        
        do
        {
            printf("Next Move [1-%d]: ", game.path);
            scanf("%d", &player.moving);

            if (player.moving < 1 || player.moving > game.path)
            {
                printf("  Out of Range!!!\n");
            }
            else if (player.moving >= 1 && player.moving <= game.path)
            {
                if (game.bomb[player.moving - 1] == 1 && game.treasure[player.moving - 1] == 1)
                {
                    printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                    printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                    player.player_Lives -= 1;
                    player.moves -= 1;
                    player.treasure_Own += 1;
                    player.history[player.moving - 1] = '&';
                }

                else if (game.bomb[player.moving - 1] == 1 && game.treasure[player.moving - 1] == 0)
                {
                    printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
                    player.player_Lives -= 1;
                    player.moves -= 1;
                    player.history[player.moving - 1] = '!';
                }

                else if (game.bomb[player.moving - 1] == 0 && game.treasure[player.moving - 1] == 1)
                {
                    printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                    player.moves -= 1;
                    player.treasure_Own += 1;
                    player.history[player.moving - 1] = '$';
                }
                else if (player.history[player.moving] != '-')
                {
                    printf("\n===============> Dope! You've been here before!\n\n");
                }
                else if (game.bomb[player.moving - 1] == 0 && game.treasure[player.moving - 1] == 0)
                {
                    if (player.history[player.moving - 1] == '-')
                    {
                        printf("\n===============> [.] ...Nothing found here... [.]\n\n");
                        player.moves -= 1;
                        player.history[player.moving - 1] = '.';
                    }
                    else
                    {
                        printf("\n===============> Dope! You've been here before!\n\n");
                    }

                }
            }


        } while (player.moving < 1 || player.moving > game.path);


    } while (player.player_Lives != 0 && player.moves != 0);

    printf("No more LIVES remaining!\n\n");



    for (i = 0; i < player.moving - 1; i++)
    {
        printf(" ");
    }
    if (player.moving > 0)
    {
        printf("  %c", player.player_Symbol);
    }

    printf("\n");

    printf("  ");
    if (c == 0)
    {
        for (i = 0; i < game.path; i++)
        {
            player.history[i] = '-';
            printf("%c", player.history[i]);

        }
        c = 1;
    }
    else {
        for (i = 0; i < game.path; i++) {
            printf("%c", player.history[i]);
        }

    }
    printf("\n  ");
    for (i = 1; i <= game.path; i++)
    {
        if (i % 10 == 0)
        {
            printf("%d", i / 10);
        }

        else
        {
            printf("|");
        }
    }
    printf("\n  ");

    for (i = 1; i <= game.path; i++)
    {
        printf("%d", i % 10);
    }

    if (game.bomb[player.moving - 1] == 1 && game.treasure[player.moving - 1] == 1)
    {
        player.history[player.moving - 1] = '&';
    }

    else if (game.bomb[player.moving - 1] == 1 && game.treasure[player.moving - 1] == 0)
    {
        player.history[player.moving - 1] = '!';
    }

    else if (game.bomb[player.moving - 1] == 0 && game.treasure[player.moving - 1] == 1)
    {
        player.history[player.moving - 1] = '$';
    }
    else if (player.history[player.moving] != '-')
    {
    }

    else if (game.bomb[player.moving - 1] == 0 && game.treasure[player.moving - 1] == 0)
    {
        if (player.history[player.moving - 1] == '-')
        {
            player.history[player.moving - 1] = '.';
        }
    }

    printf("\n+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.player_Lives, player.treasure_Own, player.moves);
    printf("+---------------------------------------------------+\n");

    printf("\n##################\n#   Game over!   #\n##################\n\n");
    printf("You should play again and try to beat your score!\n\n");

    return 0;
}
