#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


// variabel struc untuk fungsi regis dan login
struct login
{
    char fnama[128];
    char lnama[128];
    char username[128];
    char password[128];
};

int f;
int arr[5];



// deklarasi fungsi karena fungsi ditaruh dibawah int main
void regis();
bool lomgin();
void biru();
void putih();
void hijau();
void merah();
void oldprog();
void struk(float sum_money, float kembalian, char nama[30], char kasir[128], const char tel[30], const char email[30], const char web[30]);
void receipt(float sum_money, float kembalian, char nama[30], char kasir[128], const char tel[30], const char email[30], const char web[30]);
void viewName();

// fungsi main
int main()
{
    int pilih;
    system("cls");
    putih();
salah:
    printf("1. untuk register\n2. untuk login\n3. Exit\n");
    scanf("%d", &pilih);

    switch (pilih)
    {
    case 1:
        system("cls");
        regis();
        
        break;
    case 2:
        system("cls");
        lomgin();
        break;
    case 3:
        system("cls");
        exit(0);
        break;
    default:
        system("cls");
        merah();
        printf("Menu tidak tersedia\n");
        putih();
        goto salah;
        break;
    }
    return 0; // return 0 means that the program will execute successfully and did what it was intended to do.
}

// fungsi registrasi akun
void regis()
{
    FILE *log;
    log = fopen("Username.bin", "wb");
    struct login user;

    printf("Masukan nama pertama anda : \n");
    scanf("%s", &user.fnama);
    printf("Masukan nama terakhir anda : \n");
    scanf("%s", &user.lnama);
    printf("username : \n");
    scanf("%s", &user.username);
    printf("password : \n");
    scanf("%s", &user.password);

    fwrite(&user, sizeof(user), 1, log); // write user pada varibel memory address user sebanyak size user 1x ke pointer log. Dengan kata lain data sebanyak sizeof user dikali 1

    fclose(log);

    printf("Ketik enter untuk login...............\n");
    getch();
    system("cls");
    lomgin();
}

// fungsi login
bool lomgin()
{
    char username[128], password[20];
    FILE *log;
    relog:
    log = fopen("Username.bin", "rb");
    struct login user;

    if (log == NULL)
    {
        merah();
        printf("Error file tidak ditemukan\n");
        exit(1);
        putih();
    }

    printf("Username : ");
    scanf("%s", &username);
    printf("Password : ");
    scanf("%s", &password);
    fflush(stdin);

    (fread(&user, sizeof(user), 1, log)); // read user pada pointer file log pada memory address user, membaca sebanyak sizeof 1x

    if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0)
    {
        hijau();
        printf("Login berhasil\n");
        printf("Selamat datang %s\n", user.username);
        putih();
        oldprog();
        return true;
    }
    else if (strcmp(username, "Rusdi") == 0 && strcmp(password, "admin") == 0)
    {
        printf("Login berhasil sebagai admin");
    }
    else
    {
        system("cls");
        merah();
        printf("Username atau password salah\n");
        putih();
        return false;
        goto relog;
    }

    fclose(log);
}

void oldprog()
{
    // data variable fungsi kasir
    int number, n;
    int total = 0;
    char ask;
    const int harga[5] = {5000, 7000, 9000, 11000, 13000}; // array harga
    int stock[5] = {50, 30, 20, 10, 5};
    char nama[30];
    const char web[30] = "www.jokikoding.com";
    const char tel[30] = "087755704083";
    const char email[30] = "rusdishop69@bluwin.ch";
    char tambah;
    int dynamicStock;
    float kembalian;
    int mKurang;
    int mInput[100];
    float sum_money;
    int i;

    char menu [5][100] = {
        "KOPI",
        "KEBAB",
        "MIE GORENG",
        "BATAGOR",
        "BURGER"
    };


    // printf("%s", menu[1]);
    struct login user;
    FILE *log;
    log = fopen("Username.bin", "rb");

user:
    printf("Pembelian atas nama : ");
    gets(nama);

    // loop apabila ingin tambah
    do
    {
    ulang:

        biru();
        printf("\n|----------------------------------------------------|\n");
        printf("|<<<<<<<<<<<< SELAMAT DATANG DI TOKO RUSDI >>>>>>>>>>|\n");
        printf("|----------------------------------------------------|\n");
        printf("|   JENIS PRODUK           ||  HARGA      || STOCK   |\n");
        printf("|1. %s                   ||   %d      ||  %d     |\n",menu[0], harga[0], stock[0]);
        printf("|2. %s                  ||   %d      ||  %d     |\n",menu[1], harga[1], stock[1]);
        printf("|3. %s             ||   %d      ||  %d     |\n",menu[2], harga[2], stock[2]);
        printf("|4. %s                ||   %d     ||  %d     |\n",menu[3], harga[3], stock[3]);
        printf("|5. %s                 ||   %d     ||  %d      |\n",menu[4], harga[4], stock[4]);
        printf("|6. view by name (a - z)                             |\n");
        printf("|----------------------------------------------------|\n");
    ascend:
        putih();
        printf("apa yang ingin anda beli : ");
        scanf("%d", &number);

        // pilihan masing - masing menu
        switch (number)
        {
        case 1:
            if (stock[0] == 0)
            {
                system("cls");
                merah();
                printf("Stock habis");
                putih();
                goto ulang;
            }

            printf("Berapa banyak anda ingin beli : ");
            scanf("%d", &n);
            if (n > stock[0])
            {
                system("cls");
                merah();
                printf("Quantitas yang dibeli melebihi stock yang tersedia\n");
                putih();
                goto ulang;
            }

            total += harga[0] * n; // total + harga[0 / 5000]*quantity
            dynamicStock = stock[0] - n;
            stock[0] = dynamicStock;
            break;
        case 2:
            if (stock[1] == 0)
            {
                system("cls");
                merah();
                printf("Stock habis");
                putih();
                goto ulang;
            }

            printf("Berapa banyak anda ingin beli : ");
            scanf("%d", &n);
            if (n > stock[1])
            {
                system("cls");
                merah();
                printf("Quantitas yang dibeli melebihi stock yang tersedia\n");
                putih();
                goto ulang;
            }
            total += harga[1] * n;
            dynamicStock = stock[1] - n;
            stock[1] = dynamicStock;
            break;
        case 3:
            if (stock[2] == 0)
            {
                system("cls");
                merah();
                printf("Stock habis");
                putih();
                goto ulang;
            }

            printf("Berapa banyak anda ingin beli : ");
            scanf("%d", &n);
            if (n > stock[2])
            {
                system("cls");
                merah();
                printf("Quantitas yang dibeli melebihi stock yang tersedia\n");
                putih();
                goto ulang;
            }
            total += harga[2] * n;
            dynamicStock = stock[2] - n;
            stock[2] = dynamicStock;
            break;
        case 4:
            if (stock[3] == 0)
            {
                system("cls");
                merah();
                printf("Stock habis");
                putih();
                goto ulang;
            }

            if (n > stock[3])
            {
                system("cls");
                merah();
                printf("Quantitas yang dibeli melebihi stock yang tersedia\n");
                putih();
                goto ulang;
            }

            printf("Berapa banyak anda ingin beli : ");
            scanf("%d", &n);
            total += harga[3] * n;
            dynamicStock = stock[3] - n;
            stock[3] = dynamicStock;
            break;
        case 5:
            if (stock[4] == 0)
            {
                system("cls");
                merah();
                printf("Stock habis");
                putih();
                goto ulang;
            }

            printf("Berapa banyak anda ingin beli : ");
            scanf("%d", &n);
            if (n > stock[4])
            {
                system("cls");
                merah();
                printf("Quantitas yang dibeli melebihi stock yang tersedia\n");
                putih();
                goto ascend;
            }
            total += harga[4] * n;
            dynamicStock = stock[4] - n;
            stock[4] = dynamicStock;
            break;
            {
        case 6:
        viewName();   
        goto ascend;
        break;   

        default:
                merah();
                system("cls");
                printf("Menu tidak tersedia\n");
                goto ulang;
                putih();
            }
            break;
        }

        printf("apakah anda ingin tambah ? (y/n) : ");
        tambah = getch();
        fflush(stdin);
        system("cls");
    } while (tambah == 'Y' || tambah == 'y');

    // looping pembayaran apabila kurang disuruh menginput uang yang kurang
    for (i = 0; i < 5; i++)
    {
    minputulang:
        printf("Maka total yang harus anda bayar adalah : %d\n", total);
        printf("Masukan uang anda : ");
        scanf("%d", &mInput[i]);
        sum_money += mInput[i];
        if (sum_money >= total)
        {

            if (total == sum_money)
            {
                goto struk;
            }
            else if (sum_money >= total)
            {
                kembalian = sum_money - total;
            }
            goto struk;
        }
        else
        {
            merah();
            system("cls");
            mKurang = total - sum_money;
            printf("Uang anda kurang = %d\n", mKurang);
            putih();
            goto minputulang;
        }
    }

struk:
    hijau();
    system("cls");
    (fread(&user, sizeof(user), 1, log));
    struk(sum_money, kembalian, nama, user.fnama, tel, email, web);
    receipt(sum_money, kembalian, nama, user.fnama, tel, email, web);
    putih();
    fclose(log);
}

// fungsi warna ANSI 8, akses menggunakan escape dan kode warna. \033 adalah escape dan [0;31m adalah kode warna
void biru()
{
    printf("\033[0;36m");
}
void putih()
{
    printf("\033[0;37m");
}
void hijau()
{
    printf("\033[0;32m");
}
void merah()
{
    printf("\033[0;31m");
}

// fungsi struk belanja, parameter tidak harus sama dengan yang ada di int main, namun harus memiliki tipe datau yang sama
void struk(float sum_money, float kembalian, char nama[30], char kasir[128], const char tel[30], const char email[30], const char web[30])
{
    time_t now = time(NULL);
    FILE *his;
    his = fopen("History.txt", "a+");
    char *string_now = ctime(&now);
    fprintf(his,"\n\t----- RINCIAN PEMBELIAN -----\n");
    fprintf(his,"Anda membayar dengan jumlah = %.2f", sum_money);
    fprintf(his,"\nKembalian anda sebesar = %.2f", kembalian);
    fprintf(his,"\nPembelian atas nama : %s\n", nama);
    fprintf(his,"Dengan kasir : %s\n", kasir);
    fprintf(his,"Nomor telepon : %s\n", tel);
    fprintf(his,"Email : %s\n", email);
    fprintf(his,"Jangan lupa kunjungi e-shop kami di %s\n", web);
    fprintf(his, "pada waktu : %s\n", string_now);
}

void receipt(float sum_money, float kembalian, char nama[30], char kasir[128], const char tel[30], const char email[30], const char web[30])
{
    time_t now = time(NULL);
    char *string_now = ctime(&now);
    printf("\n\t----- RINCIAN PEMBELIAN -----\n");
    printf("Anda membayar dengan jumlah = %.2f", sum_money);
    printf("\nKembalian anda sebesar = %.2f", kembalian);
    printf("\nPembelian atas nama : %s\n", nama);
    printf("Dengan kasir : %s\n", kasir);
    printf("Nomor telepon : %s\n", tel);
    printf("Email : %s\n", email);
    printf("Jangan lupa kunjungi e-shop kami di %s\n", web);
    printf("Pada waktu : %s\n", string_now);
}

void viewName (){
        char menu [5][100] = {
        " KOPI                   ||  5000       ||   50",
        " KEBAB                  ||  7000       ||   30",
        " MIE GORENG             ||  9000       ||   20",
        " BATAGOR                || 11000       ||   10",
        " BURGER                 || 13000       ||   5"
    };


    int length = 5; //panjang array
    char temp [100]; //variabel temporary untuk membantu swap 

    //selection sort
    for (int i = 0; i < (length - 1); i++) //i merupakan inisialisasi sesuai index [0 - 5] pada array menu, -1 karena tidak perlu mengurutkan string paling bawah A-Z 
  {
    // find the position of the minimum string (alphabetically minimum)
    int j_min = i;
    for (int j = i + 1; j < length; j++)
      if (strcmp(menu[j], menu[j_min]) < 0) // <0 artinya apabila s1 memiliki nilai lebih kecil daripada s20 (sesuai huruf dibawah 0)
        j_min = j;
    
    // if necessary, swap the minimum string with the string at index i
    if (j_min != i)
    {
      strcpy(temp, menu[i]);
      strcpy(menu[i], menu[j_min]);
      strcpy(menu[j_min], temp);
    }
  }
  
    biru();
    printf("\n|----------------------------------------------------|\n");
    printf("|<<<<<<<<<<<< SELAMAT DATANG DI TOKO RUSDI >>>>>>>>>>|\n");
    printf("|----------------------------------------------------|\n");
    printf("|   JENIS PRODUK           ||  HARGA      || STOCK   |\n");

    for (int i = 0; i < length; i++){
    printf("| %10s     |\n", menu[i]);
    }
    printf("|----------------------------------------------------|\n");
    putih();
}


