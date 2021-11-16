// Fig. 10.18: fig10_18.c
// Using an enumeration
#include <stdio.h>

// enumeration constants represent months of the year            
enum months {                                                    
   JAN=0, FEB=8, MAR, APR, MAY, JUN, JUL=8, AUG, SEP, OCT, NOV, DEC
}; 

int main(void)
{ 
   // initialize array of pointers
   const char *monthName[] = { "", "January", "February", "March", 
      "April", "May", "June", "July", "August", "September", "October",
      "November", "December" };
   
   enum months month;

   printf("%2d\n", month=JAN);
   printf("%2d\n", month=FEB);
   printf("%2d\n", month=MAR);
   printf("%2d\n", month=APR);
   printf("%2d\n", month=MAY);
   printf("%2d\n", month=JUN);
   printf("%2d\n", month=JUL);
   printf("%2d\n", month=AUG);
   printf("%2d\n", month=SEP);
   printf("%2d\n", month=OCT);
   printf("%2d\n", month=NOV);
   printf("%2d\n", month=DEC);

   // loop through months
   /*
   for (enum months month = JAN; month <= DEC; ++month) {
      printf("%2d%11s\n", month, monthName[month]);
   } 
   */
} 



/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
