#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LIST_GENRE          \
    printf("%s",            \
           "Genre Lists:\n" \
           "[1] Jazz\n"     \
           "[2] Pop\n")
#define TOT_GENRE 2

typedef struct dataMusic
{
    unsigned int id;
    char name[100];
    char singer[100];
    int genre;
} DataMusic;

typedef struct playMusic
{
    struct dataMusic value;
    struct playMusic *nextPtr;
} PlayMusic;
typedef PlayMusic *PlayMusicPtr;

unsigned int dataChoice(void);
int listMusic(), addMusic(), enqueue(const unsigned int play), isEmpty(PlayMusicPtr headPtr), playlist(PlayMusicPtr currentPtr), loadMusic(), saveMusic();

DataMusic data_music[100];

PlayMusicPtr headPtr = NULL;
PlayMusicPtr tailPtr = NULL;
unsigned int tot_music = 0;

typedef enum
{
    eJazz = 1,
    ePop,
} Genre;

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
            playlist(headPtr);
            break;
        case 3:
            addMusic();
            break;
        case 4:
            loadMusic();
            break;
        case 5:
            saveMusic();
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
           "[1] List Music\n"
           "[2] Open Playlists\n"
           "[3] Add Music\n"
           "[4] Load Music\n"
           "[5] Save Music\n"
           "[0] Exit program.\n\n");

    unsigned int choice;
    printf("%s", ">>>> Enter Menu: ");
    scanf("%u", &choice);
    return choice;
}

int addMusic()
{
    printf("%s", "Enter Music Name: ");
    scanf("%100s", data_music[tot_music + 1].name);
    printf("%s", "Enter the Name of the Music Singer: ");
    scanf("%100s", data_music[tot_music + 1].singer);
    LIST_GENRE;
    printf("%s", "Enter Genre Music: ");
    scanf("%u", &data_music[tot_music + 1].genre);
    while (data_music[tot_music + 1].genre > TOT_GENRE)
    {
        printf("%s", ">> (invalid choice)\n");
        printf("%s", "Enter Genre Music: ");
        scanf("%u", &data_music[tot_music + 1].genre);
    }
    data_music[tot_music + 1].id = tot_music + 1;
    tot_music++;

    return 0;
}

int enqueue(const unsigned int play)
{
    PlayMusicPtr newPtr = malloc(sizeof(PlayMusic));
    if (newPtr != NULL)
    {
        newPtr->value = data_music[play];
        newPtr->nextPtr = NULL;

        if (isEmpty(headPtr))
        {
            headPtr = newPtr;
        }
        else
        {
            tailPtr->nextPtr = newPtr;
        }
        tailPtr = newPtr;
    }
    else
    {
        printf("%s not inserted. No memory available.\n", data_music[play].name);
    }
    return 0;
}

int dequeue()
{
    PlayMusicPtr tempPtr = headPtr;
    headPtr = headPtr->nextPtr;

    if (headPtr == NULL)
    {
        tailPtr = NULL;
    }

    free(tempPtr);
    playlist(headPtr);
    return 0;
}

int listMusic()
{
    unsigned int play;
    if (tot_music != 0)
    {
        for (int i = 1; i <= tot_music; i++)
        {
            printf("%d. %s - %s\n", data_music[i].id, data_music[i].name, data_music[i].singer);
        }
        for (;;)
        {
            printf("%s", "Enter Music to be Added to Your Playlist (Enter 0 to play) : ");
            scanf("%u", &play);
            if (play != 0)
            {
                enqueue(play);
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        printf("Music List is Empty.");
    }

    return 0;
}

int listGenre()
{
    
}

int playlist(PlayMusicPtr currentPtr)
{
    printf("\n========================================================================================================================\n");
    unsigned int choice;
    if (currentPtr == NULL)
    {
        puts("No Music in Playlist.\n");
    }
    else
    {
        printf("%s", "Now Playing\n"
                     "0:00 ----------------------------------------- 4:23\n");
        printf("\t\t%s - %s\n\n", currentPtr->value.name, currentPtr->value.singer);
        printf("1. Next\n");
        scanf("%u", &choice);
        if (choice == 1)
        {
            dequeue();
        }
    }
    return 0;
}

int isEmpty(PlayMusicPtr headPtr)
{
    return headPtr == NULL;
}

int loadMusic()
{
    FILE *fPtr = fopen("datamusic.bin", "rb");

    if (fPtr != NULL)
    {
        for (int i = 0; !feof(fPtr); i++)
        {
            DataMusic temp = {0, "", "", 0};
            int result = fread(&temp, sizeof(DataMusic), 1, fPtr);

            if (result != 0 && temp.id != 0)
            {
                data_music[i].id = temp.id;
                strcpy(data_music[i].name, temp.name);
                strcpy(data_music[i].singer, temp.singer);
                data_music[i].genre = temp.genre;
                tot_music = temp.id;
            }
        }
    }
    fclose(fPtr);
    printf("Data loaded successfully!\n");
    return 0;
}

int saveMusic()
{
    FILE *fPtr = fopen("datamusic.bin", "wb");
    if (fPtr != NULL)
    {
        fwrite(data_music, sizeof(DataMusic), tot_music + 1, fPtr);
    }
    else
    {
        puts("Something went wrong.");
    }
    fclose(fPtr);
    printf("Your data has been saved in file!\n");
    return 0;
}