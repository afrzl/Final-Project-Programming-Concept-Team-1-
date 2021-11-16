#include <stdio.h>

struct Character
{
    char name[100];
    int maxHealth;
    int experience;
};

void upgradeCharacter(struct Character *);

int main()
{
    struct Character ch = {"Rudy", 100, 25};
    upgradeCharacter(&ch);
}

void upgradeCharacter(struct Character *chr)
{
    chr->maxHealth += 25;
    printf("Character upgraded!\n");
}
