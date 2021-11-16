#include<stdio.h>

int main()
{
   int angka, harga, i = 1 ;
   int ttl_beli=0 , dskn, ttl_byr, byr,kmbln;
   char kar = 'y';
   int j, s;

   printf("\t\t\t\t====================================================\n");
   printf("\t\t\t\t||        SELAMAT DATANG DI BURJO GALAK !!!       ||\n ");
   printf("\t\t\t\t||      SEDIA BERBAGAI MAKANAN DAN MINUMAN !!!    ||\n ");
   printf("\t\t\t\t||                                                ||\n ");
   printf("\t\t\t\t||      Jl. Antariksa II, Jebres, Surakarta       ||\n ");
   printf("\t\t\t\t====================================================\n\n");


   printf("\t---------------------------------------------------------------------------------------------------\n\n");

   printf("\tSedia : \n");
   printf("\t1. Indomie Goreng\n \t2. Indomie Rebus\n \t3. Omelet\n \t4. Nasi Ayam Gongso\n \t5. Nasi Orak Arik Telur\n \t6. Bubur Kacang Ijo\n \t7. Nasi Rica2 Ayam\n \t8. Nasi Balado Telur\n \t9. Nasi Goreng\n \t10. Magelangan\n \t11. Sosis Goreng\n \t12. Telur Dadar\n \t13. Nugget Goreng\n \t14. Mie Dok Dok\n \t15. Nasi sarden\n \t16. Nasi putih\n \t17. Nasi Balado Telur\n \t18. Es Teh / Panas\n \t19. Es Jeruk / Panas\n \t20. Es Milo\n \t21. Nutrisari\n \t22. Dancow\n \t23. Es Susu Syrup\n \t24. Cappucino\n \t25. Es Good Day\n \t26. Es Soda Gembira\n \t27. Es Fanta\n \t28. Es Joshua\n \t29. Kopi\n \t30. Energen\n \t31. Es Teh Tarik\n\n ");

   char h=64, nama [2][2][4]=
   {
       "magalangan", "nutrisari", "omelet", "capuccino"
   };

   printf ("\t   Menu Paketan:\n");

   for (j=0; j<2; j++)
   {
       ++h;
        printf ("\t\tPaket %c\n", h);
        for(s=0; s<2; s++)
        {
            printf("%d. %s\t\n", s+1, nama [j][s]);
        }
        printf("\t\n");
    }

   printf ("\n\tMasukan Angka Menu Yang Ingin Dipesan\n");

   while(kar=='y')
   {
       printf("\tPESANAN KE - %d : ", i);
       scanf ("%d",&angka);
       fflush(stdin);

       if (angka == 1)
       {
           harga = 5000;
           printf("\t Harga Indomie Goreng = Rp. %d\n\n", harga);
       }
       else if (angka == 2)
       {
           harga = 5000;
           printf("\t Harga Indomie Rebus = Rp. %d\n\n", harga);
       }
       else if (angka == 3)
       {
           harga = 7000;
           printf("\t Harga Omelet = Rp. %d\n\n", harga);
       }
        else if (angka == 4)
       {
           harga = 10000;
           printf("\t Harga Nasi Ayam Gongso = Rp. %d\n\n", harga);
       }
        else if (angka == 5)
       {
           harga = 90000;
           printf("\t Harga Nasi Orak Arik telur = Rp. %d\n\n", harga);
       }
        else if (angka == 6)
       {
           harga = 7000;
           printf("\t Harga Bubur Kacang IJo = Rp. %d\n\n", harga);
       }
        else if (angka == 7)
       {
           harga = 12000;
           printf("\t Harga Nasi Rica2 Ayam = Rp. %d\n\n", harga);
       }
        else if (angka == 8)
       {
           harga = 9000;
           printf("\t Harga Nasi Balado Telur = Rp. %d\n\n", harga);
       }
       else if (angka == 9)
       {
           harga = 12000;
           printf("\t Harga Nasi Goreng = Rp. %d\n\n", harga);
       }
       else if (angka == 10)
       {
           harga = 12000;
           printf("\t Harga Magelangan = Rp. %d\n\n", harga);
       }
       else if (angka == 11)
       {
           harga = 6000;
           printf("\t Harga Sosis Goreng = Rp. %d\n\n", harga);
       }
       else if (angka == 12)
       {
           harga = 9000;
           printf("\t Harga Telur Dadar = Rp. %d\n\n", harga);
       }
       else if (angka == 13)
       {
           harga = 6000;
           printf("\t Harga Nugget Goreng = Rp. %d\n\n", harga);
       }
       else if (angka == 14)
       {
           harga = 12000;
           printf("\t Harga Mie Dok Dok = Rp. %d\n\n", harga);
       }
       else if (angka == 15)
       {
           harga = 9000;
           printf("\t Harga Nasi Sarden = Rp. %d\n\n", harga);
       }
       else if (angka == 16)
       {
           harga = 3000;
           printf("\t Harga Nasi Putih = Rp. %d\n\n", harga);
       }
       else if (angka == 17)
       {
           harga = 9000;
           printf("\t Harga Nasi Balado Telur = Rp. %d\n\n", harga);
       }
       else if (angka == 18)
       {
           harga = 3000;
           printf("\t Harga Es Teh / panas = Rp. %d\n\n", harga);
       }
       else if (angka == 19)
       {
           harga = 4000;
           printf("\t Harga Es Jeruk / panas = Rp. %d\n\n", harga);
       }
       else if (angka == 20)
       {
           harga = 4000;
           printf("\t Harga Es Milo= Rp. %d\n\n", harga);
       }
       else if (angka == 21)
       {
           harga = 4000;
           printf("\t Harga Nutrisari = Rp. %d\n\n", harga);
       }
       else if (angka == 22)
       {
           harga = 4000;
           printf("\t Harga Dancow = Rp. %d\n\n", harga);
       }
       else if (angka == 23)
       {
           harga = 6000;
           printf("\t Harga Es Susu Syrup = Rp. %d\n\n", harga);
       }
       else if (angka == 24)
       {
           harga = 4000;
           printf("\t Harga Capuccino = Rp. %d\n\n", harga);
       }
       else if (angka == 25)
       {
           harga = 4000;
           printf("\t Harga Es Good Day = Rp. %d\n\n", harga);
       }
       else if (angka == 26)
       {
           harga = 8000;
           printf("\t Harga Es Soda Gembira = Rp. %d\n\n", harga);
       }
       else if (angka == 27)
       {
           harga = 6000;
           printf("\t Harga Es Fanta = Rp. %d\n\n", harga);
       }
       else if (angka == 28)
       {
           harga = 7000;
           printf("\t Harga Es Joshua = Rp. %d\n\n", harga);
       }
       else if (angka == 29)
       {
           harga = 3000;
           printf("\t Harga Kopi = Rp. %d\n\n", harga);
       }
       else if (angka == 30)
       {
           harga = 4000;
           printf("\t Harga Energen = Rp. %d\n\n", harga);
       }
       else if (angka == 31)
       {
           harga = 5000;
           printf("\t Harga Es Teh Tarik = Rp. %d\n\n", harga);
       }
       else
       {
           printf("\n");
           printf("\tMenu Tidak Tersedia !!!!\n");
       }

       ttl_beli=ttl_beli+harga;
       printf("\tPesanan Anda Sudah selesai? [y/t] = "); // y untuk iya t untuk tidak
       scanf("%c", &kar);
       printf("\n");
       i++;
   }

   printf("\t----------------------------------------------------------------------------\n");
   printf("\t----------------------------------------------------------------------------\n");
   printf("\n");
   printf("\t TOTAL HARGA MAKANAN & MINUMAN              = Rp. %d\n", ttl_beli);
   if (ttl_beli>50000)
   {
       dskn = 0.1*ttl_beli;
       printf ("\tANDA MENDAPATKAN POTONGAN SEBESAR           = Rp. %d\n", dskn);
       ttl_byr = ttl_beli-dskn;
   }
   else
   {
       ttl_byr= ttl_beli;
   }
   printf("\t TOTAL HARGA MENU YANG HARUS DI BAYAR       = Rp. %d\n",ttl_byr);
   printf("\t MASUKAN JUMLAH UANG ANDA                   = Rp. ", byr);
   scanf("%d", &byr);

   kmbln=byr-ttl_byr;
   if (byr>ttl_byr)
   {
       printf("\t UANG KEMBALIAN ANDA                        = Rp. %d\n",kmbln);
   }
   else
   {
       printf("\t UANG ANDA TIDAK CUKUP              = Rp. %d\n", ttl_byr-byr);
   }

   if (ttl_beli>75000)
   {
       printf("\t\t\t\tANDA MENDAPATKAN SOSIS GORENG GRATISSS !!! \n");
   }
   else
   {
       printf("\n");
   }

   printf("\t----------------------------------------------------------------------------\n\n");
   printf("\t\t\t\t TERIMA KASIH SUDAH MAKAN DI BURJO GALAK !!!\n");
   printf("\t\t\t\t         ANDA KENYANG KAMI SENANG \n");

   printf("\n\n");
   system("\tpause");
}