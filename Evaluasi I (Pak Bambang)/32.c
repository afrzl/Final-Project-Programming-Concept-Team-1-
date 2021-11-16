#include <stdio.h>
#include <string.h>

char input[100], newInput[100];
int palindromeCheck(), removeSpace();

int main(){
  printf("Masukkan kalimat: ");
  scanf(" %[^\n]", &input);

  removeSpace(input);
  
  if(palindromeCheck(newInput, 0, strlen(newInput)-1) == 1)
  {
      printf("Kalimat tersebut merupakan palindrome\n");
  } else
  {
      printf("Kalimat tersebut bukan merupakan palindrome\n");
  }
}

int removeSpace(char *input)
{
  int i = 0, j = 0;
    while(input[i] != '\0')
    {
        if(input[i] == ' ')
        {
            input[i] = '\0';
        }
        else if (input[i] != ' ')
        {
            newInput[j] = input[i];
            j++;
        }
        i++;
    }
}

int palindromeCheck(char *newInput, int start, int end)
{
  int i = end/2;
  if (end == i) {
    return 1;
  } else if (newInput[start] != newInput[end]) {
    return 0;
  } else {
    return palindromeCheck(newInput, start+1, end-1);
  }
}

