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

void lomgin();
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
    printf("Password : "); scanf("%s", &password);

    fread(&user, sizeof(user), 1, log);
    {
        if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0)
        {
            printf("Login berhasil");
        } else {
            printf("Username atau password salah");
        }
        
    }
    fclose(log);
}


void regis();
void lomgin();

int main (){
    int pilih;
    printf("1. untuk register\n 2. untuk login"); scanf("%d", &pilih);

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