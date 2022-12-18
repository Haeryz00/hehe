#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


struct login
{
    char fnama[128];
    char lnama[128];
    char username[128];
    char password[128];
};



void regis();
void lomgin();
void biru ();
void putih ();
void hijau ();
void merah ();
void oldprog();
void struk(float sum_money, int kembalian, char nama [30], const char tel[30], const char email[30], const char web [30]);

int main (){
    int pilih;
    printf("1. untuk register\n2. untuk login"); scanf("%d\n", &pilih); fflush(stdin);

    switch (pilih)
    {
    case 1:
        system("cls");
        regis();
        break;
    case 2:
        system("cls");
        lomgin();
    default:
        break;
    }
    
}

void regis(){
    FILE *log;
    log = fopen("Username.txt", "w");
    struct login user;

    printf("Masukan nama pertama anda : \n"); scanf("%s", &user.fnama);
    printf("Masukan nama terakhir anda : \n"); scanf("%s", &user.lnama);
    printf("username : \n"); scanf("%s", &user.username);
    printf("password : \n"); scanf("%s", &user.password);

    fwrite(&user, sizeof(user), 1, log);

    fclose(log);

    printf("Ketik enter untuk login...............\n");
    getch();
    system("cls");
    lomgin();
}

void lomgin(){
    char username[128], password[20];

    FILE *log;
    log = fopen("Username.txt", "r");
    struct login user;
    printf("Username : "); scanf("%s", &username);
    printf("Password : "); scanf("%s", &password); fflush(stdin);

    while (fread(&user, sizeof(user), 1, log))
    {
        if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0)
        {
            printf("Login berhasil\n");
            oldprog();
        } else if (strcmp(username, "Rusdi") == 0 && strcmp(password, "admin") == 0)
        {
            printf("Login berhasil sebagai admin");
        } else {
            printf("Username atau password salah");
        }
        
    }
    fclose(log);
}

void oldprog(){
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
    char tambah;
    int dynamicStock;
    int kembalian, mKurang;
    int mInput [100];
    float sum_money;
    int i;

    //variabel menu utama
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
    struk(sum_money, kembalian, nama, tel, email, web);
    putih(); 

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

void struk(float sum_money, int kembalian, char nama [30], const char tel[30], const char email[30], const char web [30]){
    printf("\n\t----- RINCIAN PEMBELIAN -----\n");
    printf("Anda membayar dengan jumlah = %.2f", sum_money);
    printf("\nKembalian anda sebesar = %d", kembalian);
    printf("\nPembelian atas nama : %s\n", nama);
    
    printf("Nomor telepon : %s\n", tel);
    printf("Email : %s\n", email);
    printf("Jangan lupa kunjungi e-shop kami di %s\n", web);
}



