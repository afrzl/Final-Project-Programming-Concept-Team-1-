/*

NAMA : MUHAMMAD AZZAM HILMY
NIM  : M0521048

*/

#include <stdio.h>
#include <stdlib.h>

int main();
int keluar();
int lihatmenu();
int lihatharga();
int lihatmenudisk();

struct data
{
	char nama[20];
	unsigned int harga;
};

struct data datalist[5] = {
	{"Mie Ayam", 10000},
	{"Bakso", 11000},
	{"Mie Ayam Bakso", 13000},
	{"Teh Panas/Dingin", 2000},
	{"Jeruk Panas/Dingin", 3000}};

enum tipe
{
	diskon,
	nodiskon,
};

void tampildata(const struct data *chr)
{
	int pilih;

	printf("Nama\t: %s\n", chr->nama);
	printf("Harga\t: %u\n", chr->harga);

pilihstep:
	printf("\n1. Melihat Harga Makanan Lagi");
	printf("\n2. Kembali Ke Awal\n");
	printf("3. Keluar\n");
	printf("Pilih (1/2): ");
	scanf("%i", &pilih);
	system("cls");
	if (pilih == 1)
	{
		system("cls");
		lihatharga();
	}
	else if (pilih == 2)
	{
		main();
	}
	else if (pilih == 3)
	{
		keluar();
	}
	else
	{
		printf("Tolong Dipilih!");
		goto pilihstep;
	}
}

int lihatharga()
{
	enum tipe status;
	int pilihannya;
	struct data datalist[5] = {
		{"Mie Ayam", 10000},
		{"Bakso", 11000},
		{"Mie Ayam Bakso", 13000},
		{"Teh Panas/Dingin", 2000},
		{"Jeruk Panas/Dingin", 3000}};

	lihatmenu();
ini:
	printf("\nPilih Makanan Yang Ingin Dilihat: ");
	scanf("%i", &pilihannya);
	switch (pilihannya)
	{
	case 1:
	case 2:
	case 3:
		status = diskon;
		break;
	case 4:
	case 5:
		status = nodiskon;
		break;
	}
	if (status == diskon)
	{
		printf("\nStatus\t: Sedang Diskon [Gunakan Voucher]!\n");
	}
	else if (status == nodiskon)
	{
		printf("\nStatus\t: Tidak Diskon!\n");
	}
	if (pilihannya <= 5)
	{
		tampildata(&datalist[pilihannya - 1]);
	}
	else if (pilihannya >= 6)
	{
		printf("\nPilihan Anda Tidak Ada!\n");
		goto ini;
	}
	else
	{
		goto ini;
	}
	return 0;
}

int lihatmenu()
{
	int i;

	char data[5][50] = {
		"Mie Ayam", "Mie Ayam Bakso", "Bakso", "Teh Panas/Dingin", "Jeruk Panas/Dingin"};
	for (i = 0; i < 5; i++)
	{
		printf("%d. %s\n", i + 1, data[i]);
	}

	return 0;
}

int lihatmenudisk()
{
	int i;

	char data[3][50] = {
		"Mie Ayam", "Mie Ayam Bakso", "Bakso"};
	for (i = 0; i < 3; i++)
	{
		printf("%d. %s\n", i + 1, data[i]);
	}

	return 0;
}

int lihatmenumakanan()
{
	int i, pilih;
	printf("Daftar Makanan dan Minuman Yang Tersedia: \n\n");
	char data[5][50] = {
		"Mie Ayam", "Mie Ayam Bakso", "Bakso", "Teh Panas/Dingin", "Jeruk Panas/Dingin"};
	for (i = 0; i < 5; i++)
	{
		printf("%d. %s\n", i + 1, data[i]);
	}
pilihstep:
	printf("\n1. Kembali Ke Awal\n");
	printf("2. Keluar\n");
	printf("Pilih (1/2): ");
	scanf("%i", &pilih);
	system("cls");
	if (pilih == 1)
	{
		main();
	}
	else if (pilih == 2)
	{
		keluar();
	}
	else
	{
		printf("Tolong Dipilih!");
		goto pilihstep;
	}
	return 0;
}

int keluar()
{
	char menukeluar;
menukeluar:
	printf("Apakah Anda Yakin Ingin Keluar Program?\n");
	printf("(Y = Keluar | T = Tidak)");
	printf("\n=> ");
	scanf("%s", &menukeluar);
	switch (menukeluar)
	{
	case 'y':
		system("cls");
		printf("Anda Telah Program!\n");
		break;
	case 't':
		system("cls");
		main();
		break;
	case 'Y':
		system("cls");
		printf("Anda Telah Program!\n");
		break;
	case 'T':
		system("cls");
		main();
		break;
	default:
		system("cls");
		goto menukeluar;
		break;
	}
	return 0;
}

void tampildatavoc(const struct data *chr)
{

	printf("Nama\t: %s\n", chr->nama);
	printf("Harga\t: %u\n", chr->harga);
}

int voucherin(struct data *chr)
{
	chr->harga = chr->harga - chr->harga * 1 / 10;
	return 0;
}

int inputvoucher()
{
	int vocinput, pilih;
	printf("Voucher Otomatis Digunakan!\n\n");

	lihatmenudisk();

	printf("\nPilih Makanan Yang Ingin Didiskon : ");

	scanf("%i", &vocinput);

	printf("\nHarga Sebelum Didiskon\n");

	tampildatavoc(&datalist[vocinput - 1]);

	printf("\nHarga Setelah Didiskon\n");

	voucherin(&datalist[vocinput - 1]);

	tampildatavoc(&datalist[vocinput - 1]);

	printf("\nSelamat Menikmati Diskon!\n");
pilihstep:
	printf("\n1. Kembali Ke Awal\n");
	printf("2. Keluar\n");
	printf("Pilih (1/2): ");
	scanf("%i", &pilih);
	system("cls");
	if (pilih == 1)
	{
		main();
	}
	else if (pilih == 2)
	{
		keluar();
	}
	else
	{
		printf("Tolong Dipilih!");
		goto pilihstep;
	}
	return 0;
}

int main()
{
	int opsi;
main:
	printf("===================================\n");
	printf("Selamat Datang Di Aplikasi Restoran\n");
	printf("===================================\n");
	printf("\n1. Lihat Menu Makanan/Minuman\n");
	printf("2. Lihat Harga Makanan/Minuman\n");
	printf("3. Menggunakan Voucher\n");
	printf("4. Keluar\n");
	printf("\nPilihan : ");
	scanf("%i", &opsi);
	switch (opsi)
	{
	case 1:
		system("cls");
		lihatmenumakanan();
		break;
	case 2:
		system("cls");
		lihatharga();
		break;
	case 3:
		system("cls");
		inputvoucher();
		break;
	case 4:
		system("cls");
		keluar();
		break;
	default:
		system("cls");
		goto main;
		break;
	}
}