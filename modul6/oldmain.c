#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


//fungsi tambahan
void biru ();
void putih ();
void hijau ();
void merah ();
void login (void);
void registration (void);


//main program
int main(){
    //data variable
    int number, n;
    int total = 0;
    char ask;
    const int harga [5] = {5000,7000,9000,11000,13000}; //array harga
    int stock [5] = {50, 30, 20, 10, 5};
    char nama[30];
    const char web [30] = "www.rusdishop.com"; 
    const char tel [30] = "087755704083";
    const char email [30] = "rusdishop69@bluwin.ch";
    char username [20];
    char tambah;
    int dynamicStock;
    int kembalian, mKurang;
    int mInput [100];
    float sum_money;
    int i;

    //variabel menu utama
    int menu;

    struct login                          
{
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
};
    
    printf("=========================================================\n");
    printf("\t\t\tMENU\n");
    printf("1. Admin mode\n");
    printf("1. Admin mode\n");    
    printf("=========================================================\n");
    printf("\n");

    printf("Silahkan pilih menu : "); scanf("%d", &menu); fflush(stdin);

    switch (menu)
    {
    case 1:
        printf("Admin mode\n");
        break;
    case 2:
        printf("User mode\n");
        goto user;
    default:
        break;
    }

    


    user :
    //inputan user
    printf("Pembelian atas nama : "); gets(nama);

   
    //looping tambah barang
   do{
    ulang : 
    biru();
    printf("\n|----------------------------------------------------|\n");
    printf("|<<<<<<<<<<<< SELAMAT DATANG DI TOKO RUSDI >>>>>>>>>>|\n");
    printf("|----------------------------------------------------|\n");
    printf("|   JENIS PRODUK           ||  HARGA      || STOCK   |\n");
    printf("|1. KOPI                   ||   %d      ||  %d     |\n", harga[0], stock[0]);
    printf("|2. KEBAB                  ||   %d      ||  %d     |\n", harga[1], stock[1]);
    printf("|3. MIE GORENG IRENG       ||   %d      ||  %d     |\n", harga[2], stock[2]);
    printf("|4. BATAGOR                ||   %d     ||  %d     |\n", harga[3], stock[3]);
    printf("|5. BURGER                 ||   %d     ||  %d      |\n",harga[4], stock[4]);
    printf("|----------------------------------------------------|\n");

    putih();
    printf("apa yang ingin anda beli : "); scanf("%d", &number);


    //code switch
    switch (number)
    {
    case 1:
        if (stock[0] == 0)
        {
            system ("cls");
            merah();
            printf("Stock habis");
            putih();
            goto ulang;
        }
        
        printf("Berapa banyak anda ingin beli : "); scanf("%d", &n);
        total+= harga[0]*n; // total + harga[0 / 5000]*quantity
        dynamicStock = stock[0] - n;
        stock[0] = dynamicStock;
        break;
    case 2:
        if (stock[1] == 0)
        {
            system ("cls");
            merah();
            printf("Stock habis");
            putih();
            goto ulang;
        }    
        printf("Berapa banyak anda ingin beli : "); scanf("%d", &n);
        total+= harga[1]*n;
        dynamicStock = stock[1] - n;
        stock[1] = dynamicStock;
        break;
    case 3:
        if (stock[2] == 0)
        {
            system ("cls");
            merah();
            printf("Stock habis");
            putih();
            goto ulang;
        }
        printf("Berapa banyak anda ingin beli : "); scanf("%d", &n);
        total+= harga[2]*n;
        dynamicStock = stock[2] - n;
        stock[2] = dynamicStock;
        break;
    case 4:
        if (stock[3] == 0)
        {
            system ("cls");
            merah();
            printf("Stock habis");
            putih();
            goto ulang;
        }
        printf("Berapa banyak anda ingin beli : "); scanf("%d", &n);
        total+= harga[3]*n;
        dynamicStock = stock[3] - n;
        stock[3] = dynamicStock;
        break;
    case 5:
        if (stock[4] == 0)
        {
            system ("cls");
            merah();
            printf("Stock habis");
            putih();
            goto ulang;
        }
        printf("Berapa banyak anda ingin beli : "); scanf("%d", &n);
        total+= harga[4]*n;
        dynamicStock = stock[4] - n;
        stock[4] = dynamicStock;
        break;
        {
    default:
        merah();
        system("cls");
        printf("Menu tidak tersedia\n");
        goto ulang;
        putih();
        }
        break;
    }

     printf("apakah anda ingin tambah ? (y/n) : "); tambah = getch(); fflush(stdin);
     system("cls");
    } while (tambah == 'Y' || tambah == 'y');



    
   

    // looping pembayaran
    for (i = 0; i < 5; i++)
    {
        minputulang :
        printf("Maka total yang harus anda bayar adalah : %d\n", total);
        printf("Masukan uang anda : ");
        scanf("%d", &mInput[i]);
        sum_money += mInput[i];  
        if (sum_money >= total )
        {
           
            if (total == sum_money)
            {
                goto struk;
            } else if (sum_money >= total)
            {
                kembalian = sum_money - total;

            }
            goto struk;
        } else {
            merah();
            system("cls");
            mKurang = total - sum_money;
            printf("Uang anda kurang = %d\n", mKurang);
            putih();
            goto minputulang;
        }
        
    }
    


    //lamjutan y
    struk :
    hijau(); system("cls");
    printf("\n\t----- RINCIAN PEMBELIAN -----\n");
    printf("Anda membayar dengan jumlah = %.2f", sum_money);
    printf("\nKembalian anda sebesar = %d", kembalian);
    printf("\nPembelian atas nama : %s\n", nama);
    printf("Dengan kasir : %s\n", username);
    printf("Nomor telepon : %s\n", tel);
    printf("Email : %s\n", email);
    printf("Jangan lupa kunjungi e-shop kami di %s\n", web);
    putih();

    return 0;
}

void biru (){
    printf("\033[0;36m");
}
void putih (){
    printf("\033[0;37m");
}
void hijau (){
    printf("\033[0;32m");
}
void merah (){
    printf("\033[0;31m");
}

// function : total, 



