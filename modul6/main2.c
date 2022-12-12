#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define LINEAR 1
#define FORM 0

#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 500
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100


#define DATAFILE "list.txt"

struct Item {
 double price;
 int sku;
 int isTaxed;
 int quantity;
 int minQuantity;
 char name[21];
};


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
void newprog();
void welcome(void); 
void printTitle(void);
void printFooter(double gTotal); 
void flushKeyboard(void); 
void pause(void); 
int getInt(void); 
int getIntLimited(int lowerLimit, int upperLimit); 
double getDouble(void);
double getDoubleLimited(double lowerLimit, double upperLimit); 
 
int yes(void);
int menu(void);
void GroceryInventorySystem(void);

double totalAfterTax(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item,int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item *itemptr);
void addItem(struct Item item[], int *NoOfRec , int sku);
void addOrUpdateItem(struct Item item[], int *NoOfRec);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

void saveItem(struct Item item, FILE *dataFile);
int loadItem(struct Item* item,FILE* dataFile);
int saveItems(const struct Item item[],char fileName[],int NoOfRecs);
int loadItems(struct Item item[], char fileName[], int *NoOfRecsPtr);

int main (){
    int pilih;
    printf("1. untuk register\n2. untuk login"); scanf("%d", &pilih);

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
    printf("Password : "); scanf("%s", &password); fflush(stdin);

    while (fread(&user, sizeof(user), 1, log))
    {
        if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0)
        {
            printf("Login berhasil\n");
            oldprog();
        } else if (strcmp(username, "Rusdi") == 0 && strcmp(password, "admin") == 0)
        {
            printf("Login berhasil sebagai admin\n");
            newprog();
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
    char username [20];
    char tambah;
    int dynamicStock;
    int kembalian, mKurang;
    int mInput [100];
    float sum_money;
    int i;
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

void newprog(void){
	GroceryInventorySystem();
	
}



void welcome(void){
	printf("---=== Grocery Inventory System ===---\n\n");
	
}

void printTitle(void){
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
	
}

void printFooter(double gTotal){
	printf("--------------------------------------------------------+----------------\n");
	if(gTotal>0){
		printf("                                           Grand Total: |%12.2lf\n",gTotal);
	}

}

void flushKeyboard(void){
	char clearKeyboard;
	do{
		scanf("%c",&clearKeyboard);
	}while(clearKeyboard!='\n');
	
}

void pause(void){
	printf("Press <ENTER> to continue...");
	flushKeyboard();

}

int getInt(void){
	int value;
	char NL = 'x';
	while(NL!='\n'){
		scanf("%d%c",&value,&NL);
		
		if(NL!='\n'){
			flushKeyboard();
			printf("Invalid integer, please try again: ");
		}
	}
	
	return value;
}

int getIntLimited(int lowerLimit, int upperLimit){
	int limit;
	do{

		limit = getInt();
		if(limit <lowerLimit || limit > upperLimit){
			printf("Invalid value, %d < value < %d: ",lowerLimit,upperLimit);
		}
	
	}while(limit<lowerLimit || limit>upperLimit);
	
	return limit;
}

double getDouble(void){
	double value;
	char NL = 'x';
	while(NL!='\n'){
		scanf("%lf%c",&value,&NL);
		
		if(NL!='\n'){
			flushKeyboard();
			printf("Invalid number, please try again: ");
		}
	}
	return value;
}


double getDoubleLimited(double lowerLimit, double upperLimit){
		double limit;
	do{

		limit = getDouble();
		if(limit <lowerLimit || limit > upperLimit){
			printf("Invalid value, %lf< value < %lf: ",lowerLimit,upperLimit);
		}
	
	}while(limit<lowerLimit || limit>upperLimit);
	
	return limit;   
}


int yes(void){
	char character;
	do{
		scanf("%c",&character);
		flushKeyboard();
		
		if(character!='y' && character!='Y' && character!= 'n' && character!='N'){
			printf("Only (Y)es or (N)o are acceptable: ");
		}
		
	}while(character!='y'&& character !='Y' &&character != 'n' &&character!='N');
	
	if(character=='y'||character =='Y'){
		return 1;
	}
      return 0;  
}

int menu(void){
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("0- Exit program\n");
	printf("> ");
	
	int option = getIntLimited(0,5);
	return option;
}

void 
GroceryInventorySystem(void){
	
	struct Item array[MAX_ITEM_NO];
	int recordsNo;
	int receiver;
	int receiver2;
	
	welcome();
	
	receiver = loadItems(array,DATAFILE,&recordsNo);
	
	if(receiver ==0){
		printf("Could not read from %s.\n",DATAFILE);
	}
	else{
	    
	int menuOption = 1;
	while(menuOption!=0){
	
	menuOption =menu();
	
	if(menuOption==1){
		listItems(array,recordsNo);
	}
	else if(menuOption==2){
		search(array,recordsNo);
	}
	else if(menuOption==3){
		adjustQuantity(array,recordsNo,CHECKOUT);
		receiver2 = saveItems(array,DATAFILE,recordsNo);
		if(receiver2==0){
			printf("could not update file %s\n",DATAFILE);
		}
	}
	else if(menuOption==4){
		adjustQuantity(array,recordsNo,STOCK);
		receiver2 = saveItems(array,DATAFILE,recordsNo);
		if(receiver2==0){
			printf("could not update file %s\n",DATAFILE);
		}
		
	}
	else if(menuOption==5){
		addOrUpdateItem(array,&recordsNo);
		receiver2= saveItems(array,DATAFILE,recordsNo);
		if(receiver2==0){
			printf("could not update data files %s\n",DATAFILE);
		}
	}
	
	

	if(menuOption ==0){
		printf("Exit the program? (Y)es/(N)o): ");
		int exitAnswer = yes();
		if(exitAnswer!=1){
			menuOption =1;
		}
		
	}
	else{
		pause();
	     }
	}  
      }
    }


const double TAX = 0.13;


double totalAfterTax(struct Item item){
	double total;
	if(item.isTaxed ==1){
	
		total = (item.price * item.quantity)+((item.price * item.quantity)*TAX);
	}
	else{
		total = (item.price * item.quantity);
	}
	return total;
}


int isLowQuantity(struct Item item){
	if(item.quantity<= item.minQuantity){
		return 1;
	}
	else{
		return 0;
	}
   
}


struct Item itemEntry(int sku){
	
	struct Item item;
	
	item.sku = sku;
	printf("        SKU: %d\n",sku);
 
    printf("       Name: ");
	scanf("%20[^\n]c",&*item.name);
	flushKeyboard();
   
	printf("      Price: ");
	item.price = getDoubleLimited(0.01,1000.00);

	printf("   Quantity: ");
	item.quantity = getIntLimited(1,MAX_QTY);

	printf("Minimum Qty: ");
	item.minQuantity = getIntLimited(0,100);

	printf("   Is Taxed: ");
	item.isTaxed = yes();
	
	return item;
		
}
void displayItem(struct Item item,int linear){
	int x;
	if(linear ==1){
	printf("|");
	printf("%3d",item.sku);
	printf("|");
	printf("%-20s",item.name);
	printf("|");
	printf("%8.2lf",item.price);
	printf("|  ");
	
	if(item.isTaxed==1){
		printf("Yes");

	}
	else if(item.isTaxed==0){
	printf(" No");
		
	}
	
	printf("| ");
	printf("%3d",item.quantity);
	printf(" | ");
	printf("%3d",item.minQuantity);
	printf(" |");
	double totalprice = totalAfterTax(item);
	printf("%12.2f",totalprice);
	printf("|");
		
	x = isLowQuantity(item);
	if(x==1){
		printf("***");
	}
	
		printf("\n");   
	}
	else{
	printf("        SKU: %d\n",item.sku);
	printf("       Name: %s\n",item.name);
	printf("      Price: %.2lf\n",item.price);
	printf("   Quantity: %d\n",item.quantity);
	printf("Minimum Qty: %d\n",item.minQuantity);
		if(item.isTaxed==1){
		printf("   Is Taxed: Yes\n");
	}
	else{
		printf("   Is Taxed: No\n");
	}
		if(item.quantity<=item.minQuantity){
		printf("WARNING: Quantity low, please order ASAP!!!\n");
	}       
	}
}


void listItems(const struct Item item[], int noOfItems){
	int i;
	double grandTotal =0;
	double totalprice;
	
	printTitle();
	
	for(i=0;i<noOfItems;i++){
	printf("%-4d",i+1);
	displayItem(item[i],LINEAR);
	totalprice = totalAfterTax(item[i]);
	
	grandTotal=grandTotal+totalprice;
	}
	printFooter(grandTotal);
}



int locateItem(const struct Item item[], int NoOfRecs, int sku, int *index){
	int i =0;
	for(i =0;i<NoOfRecs;i++){
		if(sku == item[i].sku){
			*index = i;
			return 1;
		}
	}       
	return 0;
}

void search(const struct Item item[], int NoOfRecs){
	int sku;
	printf("Please enter the SKU: ");
	scanf("%d",&sku);
	flushKeyboard();
	int i;
	int ans;
	ans = locateItem(item,NoOfRecs,sku,&i);
	
	if(ans ==1){
		
	displayItem(item[i],0);
	
		}else{
			printf("Item not found!\n");
		}
}

void updateItem(struct Item *itemptr){
	struct Item item;
	printf("Enter new data:\n");

	struct Item copy = *itemptr;

	item = itemEntry(copy.sku);
	int answer;
	printf("Overwrite old data? (Y)es/(N)o: ");
	answer = yes();
	
	if(answer ==1){ 
		*itemptr = item;
		printf("--== Updated! ==--\n");
	}
	else{
		printf("--== Aborted! ==--\n");
	}
	
}

void addItem(struct Item item[], int *NoOfRec , int sku){
	struct Item itm;
	if(*NoOfRec == MAX_ITEM_NO){
		printf("Can not add new item; Storage Full!\n");
	}
	else{
		itm = itemEntry(sku);
		int answer;
		printf("Add Item? (Y)es/(N)o: ");
		answer = yes();
		if(answer==1){
			item[*NoOfRec] = itm;
			*NoOfRec = *NoOfRec+1;
			printf("--== Added! ==--\n");
		}
		else{
			printf("--== Aborted! ==--\n");
		}
	}       
}
void addOrUpdateItem(struct Item item[], int *NoOfRec){
	printf("Please enter the SKU: ");
	int sku = getIntLimited(SKU_MIN,SKU_MAX);
	int i;
	int number;
	number =locateItem(item, *NoOfRec,sku,&i);
	
	if(number ==1){
		
		displayItem(item[i],0);
		int answer;
		printf("Item already exists, Update? (Y)es/(N)o: ");
		answer = yes();
		if(answer ==1){
			updateItem(&item[i]);
		}
		else{
			printf("--== Aborted! ==--\n");
		}
	
	}
	else{
		addItem(item,NoOfRec,sku);
	}
	
}

void adjustQuantity(struct Item item[], int NoOfRecs, int stock){
      printf("Please enter the SKU: ");
      int sku;
      sku = getIntLimited(SKU_MIN, SKU_MAX);
      int answer;
      int i;
      answer = locateItem(item, NoOfRecs,sku,&i);
      if(answer ==0){
	      printf("SKU not found in storage!\n");
      }
      else{
	     displayItem(item[i],0);
	      int number;
	      if(stock == STOCK){
		printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ","to stock" , MAX_QTY- item[i].quantity);
				number = getIntLimited(0,MAX_QTY-item[i].quantity);                      
			  }
			  else{
				printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ","to checkout",item[i].quantity);
				number = getIntLimited(0,item[i].quantity);     
			  }
			  
			  if(number ==0){
				printf("--== Aborted! ==--\n");
			  }
			  else{
				if(stock ==STOCK){
					item[i].quantity+= number;
					printf("--== Stocked! ==--\n");
				  }
				  else{
					item[i].quantity-= number;
					printf("--== Checked out! ==--\n");
				  }
				  if(item[i].quantity < item[i].minQuantity){             
				  printf("Quantity is low, please reorder ASAP!!!\n");
			  }
		}
	}

}




void saveItem(struct Item item, FILE *dataFile){
	fprintf(dataFile,"%d,%d,%d,%.2lf,%d,%s\n",item.sku,item.quantity,item.minQuantity,item.price,item.isTaxed,item.name);
}


int loadItem(struct Item* item,FILE* dataFile){
	int number;
	number =fscanf(dataFile,"%d,%d,%d,%lf,%d,%[^\n]\n",&(*item).sku,&(*item).quantity,&(*item).minQuantity,&(*item).price,&(*item).isTaxed,(*item).name);
	
	if(number ==6){
		return 1;
	}       
		return 0;
	
}



int saveItems(const struct Item item[],char fileName[],int NoOfRecs){
	FILE *fp;
	fp = fopen(fileName,"w");
	
	if(fp!=NULL){
		int i=0;
		for(i=0;i<NoOfRecs;i++){
			saveItem(item[i],fp);
		}
		fclose(fp);
		return 1;
	}
	
	return 0;
}


int loadItems(struct Item item[], char fileName[], int *NoOfRecsPtr){
	FILE *fp;
	fp = fopen(fileName,"r");
	int count =0;
	
	if(fp!=NULL){
	
		int i =0;
		while(loadItem(&item[i],fp)!=0){
		
	
		count ++;
		i++;
       
		}
	
		*NoOfRecsPtr = count;
		fclose(fp);
		return 1;
	}
	
} 



