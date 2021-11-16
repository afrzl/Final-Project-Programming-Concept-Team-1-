// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
// self - referential structure
struct listNode
{
    int nim; // each listNode contains a character
    char *name;
    struct listNode *nextPtr; // pointer to next node
};

typedef struct listNode ListNode; // synonym for struct listNode
typedef ListNode *ListNodePtr;    // synonym for ListNode*

// prototypes
void insert(ListNodePtr *sPtr, int nim, char *name);
char delete (ListNodePtr *sPtr, int nim);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);

int main(void)
{
    ListNodePtr startPtr = NULL; // initially there are no nodes
    int nim;                     // char entered by user
    char name[100];              // char entered by user

    instructions(); // display the menu
    printf("%s", "? ");
    unsigned int choice; // user's choice
    scanf("%u", &choice);

    // loop while user does not choose 3
    while (choice != 3)
    {

        switch (choice)
        {
        case 1:
            printf("%s", "Masukkan NIM: ");
            scanf("\n%d", &nim);
            printf("%s", "Masukkan Nama: ");
            scanf("\n%s", &name);
            insert(&startPtr, nim, name); // insert
            printList(startPtr);
            break;
        case 2: // delete an element
            // if list is not empty
            if (!isEmpty(startPtr))
            {
                printf("%s", "Enter character to be deleted: ");
                scanf("\n%d", &nim);
                // if character is found, remove it
                if (delete (&startPtr, nim))
                { // remove item
                    printf("%d deleted.\n", nim);
                    printList(startPtr);
                }
                else
                {
                    printf("%d not found.\n\n", nim);
                }
            }
            else
            {
                puts("List is empty.\n");
            }

            break;
        default:
            puts("Invalid choice.\n");
            instructions();
            break;
        }

        printf("%s", "? ");
        scanf("%u", &choice);
    }

    puts("End of run.");
}

// display program instructions to user
void instructions(void)
{
    puts("Enter your choice:\n"
         " 1 to insert an element into the list.\n"
         " 2 to delete an element from the list.\n"
         " 3 to end.");
}

// insert a new value into the list in sorted order
void insert(ListNodePtr *sPtr, int nim, char *name)
{
    ListNodePtr newPtr = malloc(sizeof(ListNode)); // create node

    if (newPtr != NULL)
    {                           // is space available?
        newPtr->nim = nim;      // place value in node
        newPtr->name = name;    // place value in node
        newPtr->nextPtr = NULL; // node does not link to another node

        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;

        // loop to find the correct location in the list
        while (currentPtr != NULL && nim > currentPtr->nim)
        {
            previousPtr = currentPtr;         // walk to ...
            currentPtr = currentPtr->nextPtr; // ... next node
        }

        // insert new node at beginning of list
        if (previousPtr == NULL)
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else
        { // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
    {
        printf("%d not inserted. No memory available.\n", nim);
    }
}

// delete a list element
char delete (ListNodePtr *sPtr, int nim)
{
    // delete first node if a match is found
    if (nim == (*sPtr)->nim)
    {
        ListNodePtr tempPtr = *sPtr; // hold onto node being removed
        *sPtr = (*sPtr)->nextPtr;    // de-thread the node
        free(tempPtr);               // free the de-threaded node
        return nim;
    }
    else
    {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = (*sPtr)->nextPtr;

        // loop to find the correct location in the list
        while (currentPtr != NULL && currentPtr->nim != nim)
        {
            previousPtr = currentPtr;         // walk to ...
            currentPtr = currentPtr->nextPtr; // ... next node
        }

        // delete node at currentPtr
        if (currentPtr != NULL)
        {
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return nim;
        }
    }

    return '\0';
}

// return 1 if the list is empty, 0 otherwise
int isEmpty(ListNodePtr sPtr)
{
    return sPtr == NULL;
}

// print the list
void printList(ListNodePtr currentPtr)
{
    // if list is empty
    if (isEmpty(currentPtr))
    {
        puts("List is empty.\n");
    }
    else
    {
        puts("The list is:");

        // while not the end of the list
        while (currentPtr != NULL)
        {
            printf("%d (%s) --> ", currentPtr->nim, currentPtr->name);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL\n");
    }
}