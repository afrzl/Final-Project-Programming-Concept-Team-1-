#include <stdio.h>

unsigned int dataChoice(void);

int main(void)
{
    unsigned int choice;

    while ((choice = dataChoice()) != 0)
    {
        switch (choice)
        {
        case 1:
            listMusic();
            break;
        case 2:
            playlist();
            break;
        case 3:
            addMusic();
            break;
        default:
            puts("Incorrect choice");
            break;
        }
    }
}

unsigned int dataChoice(void)
{
    printf("\n========================================================================================================================\n");
    printf("%s",
           "\nMenu Spoticy:\n"
           "[1] Play Music\n"
           "[2] Open Playlists\n"
           "[3] Add Music\n"
           "[0] Exit program.\n\n");

    unsigned int choice;
    printf("%s", ">>>> Enter Menu: ");
    scanf("%u", &choice);
    return choice;
}
