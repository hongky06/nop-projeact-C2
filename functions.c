#include <stdio.h>
#include <string.h> 
#include"functions.h"
extern struct danhsach list[200];
int a,i,j,mokhoa,k=5; 
int doi;					// doi trang thai
int size = 0;
int length = 0;         // kiem tra sdt va gmail
char taikhoan[100];  
char matkhau[100];


void account(int *a){  					// nhap tai khoan 
int stk,mk;
int m=2006;
 do {
		printf("Tai khoan(2006): ");
		scanf("%d",&stk);
		getchar();
		printf("mk(2006): ");
		scanf("%d",&mk);
		getchar();
        if (stk==m && mk==m) {
        printf("dang nhap thanh cong\n");
        *a = 1; 
        break;   
        } else {
        printf("Tai khoan hoac mat khau khong dung. Vui long thu lai.\n");
        *a = 0;  
        continue;
	}
    } while (*a == 0); 
}

void hienthi(){	                        //hien thi 
	printf("\nkhach hang:\n");
    printf("+----+----------------+----------------------+-----------------+---------+\n");
    printf("| ID | Name           | Gmail                | Phone           | Status  |\n");
    printf("+----+----------------+----------------------+-----------------+---------+\n");
        for ( i = 0; i < size; i++) {
        	printf("| %-2d | %-14s | %-20s | %-15s | %-7s |\n",
               list[i].id, list[i].name, list[i].gmail,
               list[i].sdt, list[i].khoa);
            printf("+----+----------------+----------------------+-----------------+---------+\n");
        }
	}	

		
void timkiem() {  
    int thongtin;
	hienthi();  
    printf("id ban muon xem: ");
    scanf("%d", &thongtin);
    for ( i = 0; i < size; i++) {
        if (thongtin == list[i].id) {  
            printf("thong tin khach hang\n");
            printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
            printf("| ID | Name           | CCCD              | Birthday           | Gmail                | Phone           | Status  |\n");
            printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
            printf("| %-2d | %-14s | %-17s | %02d/%02d/%-12d | %-20s | %-15s | %-7s |\n",
                   list[i].id, list[i].name, list[i].socancuoc,
                   list[i].ngay, list[i].thang, list[i].nam,
                   list[i].gmail, list[i].sdt, list[i].khoa);
            printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
            return;  
        }
    }
    printf("khog tim thay\n");
}

int kiemtrasdt(const char* phone){      		// da xong
 int length = strlen(phone);
     if (length != 10) {
        return 0;
    }
    for (i = 0; i < length; i++) {
        if (phone[i] < '0' || phone[i] > '9') {
            return 0;
        }
    }
    return 1;
} 



int kiemtragmail(const char*ten , const char*gmail){
     
         if (strcmp(ten, gmail) == 0) {
            return 0; 
        }
    return 1;
}

int kiemtraten(const char*ten ){
int length = strlen(ten);
	for(i=0 ; i<length;i++){
		if(ten[i] >= 'A' && ten[i] <= 'z' ){
			return 1;
		}
	} 
	return 0;
}
int kiemtracancuoc(const char*cm ){
int length = strlen(cm);
	if(length >= 12 ){
		return 1;
	}
	return 0;
}






void themphantu(){		//tham phan tu vao ham 
int b; 
//FILE *ptr =fopen("khachhang.dat","wb");
printf("\nso luong khanh hang muon nhap: ");

	scanf("%d",&b);
	getchar(); 
for ( i = 0 ; i < b ; i++){
	printf("Nhap thong tin khach hang moi:\n");
	list[size].id = size + 1; 
    printf("ID: %d\n", list[size].id);
while(1){ 																						//ten  
	printf("Name: ");
	
    fgets(list[size].name, sizeof(list[size].name), stdin);
    list[size].name[strcspn(list[size].name, "\n")] = 0; 
	fflush(stdin);		
	   if (kiemtraten(list[size].name)) {
	   	break;
    }else{
    	printf("khong hop le . vui long thu lai\n ");		
   }
}	
while(1){																						// so can cuoc 

		printf("So can cuoc: ");
    	fgets(list[size].socancuoc, sizeof(list[size].socancuoc), stdin);
    	list[size].socancuoc[strcspn(list[size].socancuoc, "\n")] = 0; 
		fflush(stdin);
	
	if (kiemtracancuoc(list[size].socancuoc)) {
		break;
   	} else {
    	printf("so can cuoc khong hop le\n");
}
}	
	printf("Enter date (day month year): ");
    scanf("%d %d %d",&list[size].ngay, &list[size].thang, &list[size].nam);
	fflush(stdin);
	while(1){
		printf("gmail: ");
    	fgets(list[size].gmail, sizeof(list[size].gmail), stdin);
    	list[size].gmail[strcspn(list[size].gmail, "\n")] = 0;
		fflush(stdin);
    	if (kiemtragmail(list[size].name, list[size].gmail) == 0) {
    	printf("Khong hop le.xin vui long thu lai\n");
    } else {
    	break;
         
    }
}
   
    while (1) { 																			 // da xong khong doong vao 
            printf("SDT: ");
            fgets(list[size].sdt, sizeof(list[size].sdt), stdin);
            list[size].sdt[strcspn(list[size].sdt, "\n")] = 0;
			fflush(stdin);
            if (kiemtrasdt(list[size].sdt)) {
                break; 
            } else {
                printf("khong hop le.\n");
            }
        } 
    printf("so du: ");
    scanf("%d" ,&list[size].sodu);
    fflush(stdin);
    
    strcpy(list[size].username, list[size].gmail);
    strcpy(list[size].password, list[size].sdt);
	strcpy(list[size].khoa, "open");
    size++;
  
 }      
printf("\nKhach hang da duoc them thanh cong!\n");
}
	

void sapxep(){
int sapxep;					//sap xep theo chuwx cai giam dan 
do{
	printf("\n1.sap xep A => Z");
	printf("\n2.sap xep Z => A ");
	 printf("\n3.Thoat\n");
	printf("\nlua chon: ");
	scanf("%d",&sapxep);
	
				
switch (sapxep) {
	case 1:	
	for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) { 
        if (strcmp(list[j].name, list[j + 1].name) > 0) {
            struct danhsach temp = list[j]; 
            list[j] = list[j + 1];      
            list[j + 1] = temp;           
        }
    }
}
   	printf("da sap xep thanh cong\n");
    printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
	printf("| ID | Name           | CCCD              | Year of Birth      | Gmail                | Phone           | Status  |\n");
	printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");	
	for (i = 0; i < size; i++) {
    printf("| %-2d | %-14s | %-17s | %-4d                | %-20s | %-15s | %-7s |\n",
           list[i].id, list[i].name, list[i].socancuoc,
           list[i].nam,
           list[i].gmail, list[i].sdt, list[i].khoa);
	}
    break;
	case 2:
	for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) { 
        if (strcmp(list[j].name, list[j + 1].name) < 0) {
            struct danhsach temp = list[j]; 
            list[j] = list[j + 1];      
            list[j + 1] = temp;           
        }
    }
}
    printf("da sap xep thanh cong\n");
    printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
	printf("| ID | Name           | CCCD              | Year of Birth      | Gmail                | Phone           | Status  |\n");
	printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");	
	for (i = 0; i < size; i++) {
    printf("| %-2d | %-14s | %-17s | %-4d                | %-20s | %-15s | %-7s |\n",
           list[i].id, list[i].name, list[i].socancuoc,
           list[i].nam,
           list[i].gmail, list[i].sdt, list[i].khoa);
	}
    break; 
        case 3:
            printf("Thoat khoi menu sap xep.\n");
            break;

        default:
           printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
	}

 }while(sapxep != 3); 
  
}


void trangthai(){						// trang thai mowr / khoa
int x=0;
	hienthi();
	printf("nhap id muon thay doi la: ");
	scanf("%d",&doi);
	for(i=0 ; i < size ;i++){
		if(doi == list[i].id){
		printf("da tim thay khach hang");
		if(strcmp(list[i].khoa, "open") == 0){
		strcpy(list[i].khoa, "close");	
		printf("da khoa khach hang");
		} else if (strcmp(list[i].khoa, "close") == 0){
		strcpy(list[i].khoa, "open");
		printf("da mo khoa khach hang");
	}
		printf("\nda thay doi thanh cong");
		printf("\ntai khoan: %s",list[i].sdt);
    	printf("\nmatkhau: %s\n",list[i].sdt);
		printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
    	printf("| ID | Name           | CCCD              | Birthday           | Gmail                | Phone           | Status  |\n");
    	printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
             printf("| %-2d | %-14s | %-17s | %02d/%02d/%-12d | %-20s | %-15s | %-7s |\n",
               list[i].id, list[i].name, list[i].socancuoc,
               list[i].ngay, list[i].thang, list[i].nam,
               list[i].gmail, list[i].sdt, list[i].khoa);
    	printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
		x=1;
		}
	}
		if (x == 0) {
        printf("Khong tim thay ID.\n");
    }
}

void timkiemkhachhang() {					// tim kiem bang ten
  char name[100]; 
    int g = 0;
    printf("\nnhap ten:\n");
    scanf(" %[^\n]", name);               //cho phep nhap chuoi cos dau cach
		for (i = 0; i < size; i++) {
        if (strstr(list[i].name, name) != NULL) { 
            g = 1; 
	printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
    printf("| ID | Name           | CCCD              | Birthday           | Gmail                | Phone           | Status  |\n");
    printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
             printf("| %-2d | %-14s | %-17s | %02d/%02d/%-12d | %-20s | %-15s | %-7s |\n",
               list[i].id, list[i].name, list[i].socancuoc,
               list[i].ngay, list[i].thang, list[i].nam,
               list[i].gmail, list[i].sdt, list[i].khoa);
    printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+---------+\n");
    }
  }    
    if (g == 0) {
        printf("khong tim thay khach hang.\n");
    }
}
void Exit() {
    char choice;
    do {
        printf("nenu [m]  // exit[n] : ");
        scanf(" %c", &choice); 

        if (choice == 'm' || choice == 'M') {
            return;  
        } else if (choice == 'n') {
            printf("da thoat chung trinh \n");
        } else {
            printf("ban nhap khong dung\n");
        }
    } while (1); 
}


void menu(){
printf("\n+---------------------------------------------+\n");
printf("|                 MENU CHINH                  |\n");
printf("+---------------------------------------------+\n");
printf("| 1. Them khach hang                          |\n");
printf("| 2. Hien thi tat ca khach hang               |\n");
printf("| 3. Hien thi chi tiet khach hang             |\n");
printf("| 4. Khoa / Mo khoa khach hang                |\n");
printf("| 5. Sap xep khach hang                       |\n");
printf("| 6. Luu thong tin khach hang                 |\n");
printf("| 7. tim kiem khach hang                      |\n");
printf("| 8. Thoat                                    |\n");
printf("+---------------------------------------------+\n");	
}



void menuchoadmin(){				// menu cho quan ly	
loadFile();
	do{
	menu();
    printf("\nlua chon cua ban: ");
	scanf("%d",&a);
	switch(a){	
	case 1:// da xong 
	system("clear || cls");
	themphantu();
 		break;
	case 2 :// da xong 
	system("clear || cls");
	hienthi();
	 Exit();
		break;
	case 3: //da xong 
	system("clear || cls");
	timkiem();
   		break;
   	case 4: //da xong 
   	system("clear || cls");
   	trangthai();
   		break;
	case 5 ://da xong 
	system("clear || cls");
 	sapxep();
 	Exit();
		break;
	case 6: // luu vao tep
	luuFile(); 
		break;
	case 7:
	system("clear || cls");
	timkiemkhachhang();
		break;
	case 8:// da xong 
	system("clear || cls");
	printf("\n+---------------------------------+\n");
    printf("|          PAI PAI                |\n");
    printf("|        TAM BIET QUAN LY         |\n");
    printf("+---------------------------------+\n");
	break;
}
	}while(a!= 8);				
}



void loadFile() {
    FILE *file = fopen("kaka.dat", "rb");
    if (file == NULL) {
        printf("Khong tim thay du lieu.\n");
        return;
    }

    size = fread(list, sizeof(struct danhsach), 200, file);
    if (size <= 0) {
        printf("Khong co du lieu duoc tai.\n");
    } else {
        printf("Du lieu tai thanh cong.\n");
    }
    fclose(file);
}



void luuFile() {
    FILE *file = fopen("kaka.dat", "wb"); 
    if (file == NULL) {
        return;
    }

    fwrite(list, sizeof(struct danhsach), size, file);

	printf("luu du lieu thanh cong\n");
    fclose(file);
}
 
 

 
 
void dangnhap(int *k) {
loadFile();
do{

	printf("Nhap tai khoan (Email): ");
    scanf(" %[^\n]", taikhoan);   
	getchar(); 
    printf("Nhap mat khau: ");
    scanf(" %[^\n]", matkhau);  	
    getchar(); 
for (i = 0; i < size; i++) {
    if (strcmp(list[i].gmail, taikhoan) == 0) {
        if (strcmp(list[i].password, matkhau) == 0) {  
            printf("Dang nhap thanh cong! Chao mung, %s.\n", list[i].name);
            *k = 1; 
            break; 
        } else {
            printf("Mat khau sai. Vui long thu lai.\n");
            *k = 0; 
    		continue; 
        }
    }
} 
		if (!*k) {
            printf("Tai khoan khong ton tai. Vui long kiem tra lai.\n");
        }
}while(*k != 1);
}






























void doimk() {
    loadFile(); 
    char mkm [100];  
    char mkc [100];  
    int t = 0;  

   
    for ( i = 0; i < 5; i++) {
        printf("\nMoi ban ghi mat khau cu: ");
        scanf(" %[^\n]", mkc);
        getchar();
        for (j = 0; j < size; j++) {
            if (strcmp(list[j].password, mkc) == 0) {
                printf("Mat khau cu dung.\n");
                t = 1;
                break;  
            }
        }
        if (t) {
            break; 
        } else {
            printf("Mat khau cu sai. Vui long thu lai.\n");
        }
    }
    if (t==0) {
        printf("Ban da nhap sai mat khau cu qua 5 lan. Chuong trinh ket thuc.\n");
        return;  
    }
    printf("\nMoi ban ghi mat khau moi: ");
    scanf(" %[^\n]", mkm);
    getchar();

    for (i = 0; i < size; i++) {
        if (strcmp(list[i].gmail, taikhoan) == 0) {  
            strcpy(list[i].password, mkm); 
            printf("Mat khau moi da duoc cap nhat.\n");
            break;  
        }
    }
}


















void suaten(){
loadFile();	
	char namemoi[100];
		for (i = 0; i < size; i++) {
        if (strcmp(list[i].gmail, taikhoan) == 0) {  
          printf("ten cu: %s\n",list[i].name);        
        }
    }	
	printf("nhap ten moi: ");
	scanf(" %[^\n]", namemoi);
	getchar();
	for (i = 0; i < size; i++) {
        if (strcmp(list[i].gmail, taikhoan) == 0) {  
            strcpy(list[i].name, namemoi); 
            printf("ten moi da duoc cap nhat.\n");
            break;  
        }
    }
    thongtinnguoidung();
} 



void suascc(){
	loadFile();	
	char sccmoi[100];
		for (i = 0; i < size; i++) {
        if (strcmp(list[i].gmail, taikhoan) == 0) {  
          printf("so can cuoc cu: %s\n",list[i].socancuoc);        
        }
    }	
	printf("nhap so can cuoc moi: ");
	scanf(" %[^\n]", sccmoi);
	getchar();
	for (i = 0; i < size; i++) {
        if (strcmp(list[i].gmail, taikhoan) == 0) {  
            strcpy(list[i].socancuoc, sccmoi); 
            printf("can cuoc moi da duoc cap nhat.\n");
            break;  
        }
    }
    thongtinnguoidung();
}




void suangaythangnam(){
	loadFile();	 
	int ngaymoi;
	int thangmoi;
	int nammoi;
	for (i = 0; i < size; i++) {
        if (strcmp(list[i].gmail, taikhoan) == 0) {  
          printf("ngay thang nam cu: %d %d %d\n",list[i].ngay,list[i].thang,list[i].nam);        
        }
    }	
	printf("nhap ngay thang nam moi: ");
	scanf("%d %d %d", &ngaymoi, &thangmoi, &nammoi);
	getchar();
	for (i = 0; i < size; i++) {
        if (strcmp(list[i].gmail, taikhoan) == 0) {  
         	list[i].ngay = ngaymoi;
			list[i].thang = thangmoi;
			list[i].nam = nammoi;
            printf("ngay thang nam moi da duoc cap nhat.\n");
            break;  
        }
    }
    thongtinnguoidung();
}

void gmailcc(){
	loadFile();	
	char gmailmoi[100];
		for (i = 0; i < size; i++) {
        if (strcmp(list[i].gmail, taikhoan) == 0) {  
          printf("gmail cu: %s\n",list[i].gmail);        
        }
    }	
	printf("nhap gmail moi: ");
	scanf(" %[^\n]", gmailmoi);
	getchar();
	for (i = 0; i < size; i++) {
        if (strcmp(list[i].gmail, taikhoan) == 0) {  
            strcpy(list[i].gmail, gmailmoi); 
            printf("gmail moi da duoc cap nhat.\n");
            break;  
        }
    }
    thongtinnguoidung();
}
void sdtcc(){
	loadFile();	
	char sdtmoi[100];
		for (i = 0; i < size; i++) {
        if (strcmp(list[i].gmail, taikhoan) == 0) {  
          printf("so dien thoai cu: %s\n",list[i].sdt);        
        }
    }	
	printf("nhap so dien thoai moi: ");
	scanf(" %[^\n]", sdtmoi);
	getchar();
	for (i = 0; i < size; i++) {
        if (strcmp(list[i].gmail, taikhoan) == 0) {  
            strcpy(list[i].sdt,sdtmoi); 
            printf("so dien thoai moi da duoc cap nhat.\n");
            break;  
        }
    }
    thongtinnguoidung();
}

void chinhsua(){
int cansua;
	do {
printf("+---------------------------------+\n");
    printf("|           MENU TUY CHON        |\n");
    printf("+---------------------------------+\n");
    printf("| 1. Ten                         |\n");
    printf("| 2. So can cuoc                 |\n");
    printf("| 3. Ngay thang nam sinh         |\n");
    printf("| 4. Gmail                       |\n");
    printf("| 5. So dien thoai               |\n");
    printf("| 6. Quay lai                    |\n");
    printf("+---------------------------------+\n");
    printf("Hay nhap lua chon cua ban: ");
		scanf("%d",&cansua);
	switch(cansua){
		case 1:
			system("clear || cls");
			suaten();
			luuFile();
			break;
		case 2:
			system("clear || cls");
			suascc();
			luuFile();
			break;
		case 3:
			system("clear || cls");
			suangaythangnam();
			luuFile();
			break;
		case 4:
			system("clear || cls");
			gmailcc();
			luuFile();
			break;
		case 5:
			system("clear || cls");
			sdtcc();
			luuFile();
			break;
		case 6:
			system("clear || cls");
			menuchokhachhang();
		break;
		default:
           printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
	 }	
	}while(cansua!= 6);
} 











void thongtinnguoidung() {    // xong  
       for (i = 0; i < size; i++) {
        if (strcmp(list[i].gmail,taikhoan) == 0) {  
printf("thong tin cua ban\n");
printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+-----------------+--------------------+-----------------+\n");
printf("| ID | tem            | CCCD              | ngay sinh          | Gmail                | so dien thoai   | Uses            | password           | trang thai      |\n");
printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+-----------------+--------------------+-----------------+\n");
printf("| %-2d | %-14s | %-17s | %02d/%02d/%-12d | %-20s | %-15s | %-15s | %-18s | %-15s |\n",
       list[i].id, list[i].name, list[i].socancuoc,
       list[i].ngay, list[i].thang, list[i].nam,
       list[i].gmail, list[i].sdt, list[i].username, list[i].password, list[i].khoa);
printf("+----+----------------+-------------------+--------------------+----------------------+-----------------+-----------------+--------------------+-----------------+\n");


        }
    }
      
}

 
 
 
 
 
  



void menuchokhachhang(){
int lc;
   do{
	printf("+----------------------------------+\n");
    printf("|         MENU TUY CHON            |\n");
    printf("+----------------------------------+\n");
    printf("| 1. Thong tin                     |\n");
    printf("| 2. Doi mat khau                  |\n");
    printf("| 3. Chinh sua thong tin ca nhan   |\n");
    printf("+----------------------------------+\n");
    printf("Lua chon: ");
	 	scanf("%d",&lc);
	 	getchar();
	switch(lc){
		case 1:
			system("clear || cls");
			loadFile();
			thongtinnguoidung();
			break;
			case 2:
			system("clear || cls");
			doimk();
 			luuFile(); 
			break;
		case 3:
			system("clear || cls");
			chinhsua();
			break;
	}
   }while(lc!=3);
}
	
