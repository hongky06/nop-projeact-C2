#include <stdio.h>
#include"datatypes.h"
#include <stdlib.h>
struct danhsach list[200];


int main(int argc, char *argv[]) {
int i,vitri;
int a,k;
do{
	
	printf("\n***Bank Management System Using C***\n");
	printf("\n        CHOOSE YOUR RULE\n");
	printf(" ==============================\n");
	printf(" [1] Admin.\n");
	printf(" [2] User.\n");
	printf(" [0] Exit the Program.\n");
	printf(" ==============================\n");
	printf("\nban la: ");	
	scanf("%d",&vitri);
	
	switch(vitri){
		case 1:  //xong
		system("clear || cls"); 
		account(&a); 
    	if (a == 1) {
       	printf("chao mung quan ly da toi");
       	menuchoadmin();
    	}
		break;
		case 2: 
		system("clear || cls"); 
	 	dangnhap(&k);
		if (k == 1) {
        menuchokhachhang();
    } 
		break;
		case 0://xong
		printf("+------------------------------------------------+\n");
    	printf("|  xin hen gap lai . chuc ban mot ngay tot lamh  |\n");
    	printf("+------------------------------------------------+\n");
			break;
        
		
}
}while(&vitri==0);
	return 0;
}
