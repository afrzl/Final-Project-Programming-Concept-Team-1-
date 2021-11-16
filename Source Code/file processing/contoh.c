#include <stdio.h>

int main()
{
    FILE *cfPtr; // clients.txt file pointer
    // fopen opens the file; exits program if file cannot be opened
    if ((cfPtr = fopen("clients.txt", "r")) == NULL)
    {
        puts("File could not be opened");
    }
    else
    {
        puts("\nLIST:\n");
        unsigned int account; // account number
        double balance;       // account balance
        char name[30];        // account name

        // read account, name and balance from file
        fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);
        // read file contents (until eof)
        while (!feof(cfPtr))
        {
            // output only if balance is greater than 0
            printf("%-10d%-13s%7.2f\n",
                   account, name, balance);
            // read account, name and balance from file
            fscanf(cfPtr, "%d%29s%lf",
                   &account, name, &balance);
        }
    }
    fclose(cfPtr); // fclose closes the file
}