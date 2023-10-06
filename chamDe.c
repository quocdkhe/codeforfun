#include <stdio.h>
#include <string.h>
#include <ctype.h>
void nhap(char dapAn[][40], int maDe, int soCau) {
    int i, j;
    
    for (i = 0; i < maDe; i++) {
        printf("Vui long nhap dap an cho ma de so %d. Luu y: bo so thu tu cau: \n", i + 1);
        char input[100];
        int k = 0;
        gets(input);
        
        for(j = 0; input[j] != '\0'; j++){
        	if (isalpha(input[j]))
        		dapAn[i][k++] = input[j];
		}
		
		dapAn[i][k] = '\0';
		
        fflush(stdin);
    }
}

void xuatDA(char traLoi[], int soCau){
	int i;
	for(i = 0; i < soCau; i++){
		printf("%c ",traLoi[i]);
	}
}

void nhapDACuaTS(char traLoi[], int soCau){
	int i;
	printf("\n");
	for(i = 0; i < soCau; i++){
		fflush(stdin);
		printf("%d. ",i + 1);
		scanf("%c",&traLoi[i]);
	}
}

void chamBai(char traLoi[],char dapAn[], int maDe, int soCau){
	int sai = 0;
	int i;
	for(i = 0; i < soCau; i++){
		if(traLoi[i] != dapAn[i]){
			sai++;
		}
	}
	printf("\nThi sinh nay sai %d cau; So cau dung : %d/%d \n",sai,soCau - sai, soCau);
}

int main(){
	// Phan 1 : Nhap database
	char dapAn[8][40];
	const int maDe;
	const int soCau;
	int baiThi;
	printf("Nhap so luong ma de : "); scanf("%d",&maDe);
	printf("Moi de thi gom so cau hoi la : "); scanf("%d",&soCau);
	fflush(stdin);
	nhap(dapAn,maDe,soCau);
	
	
	// Phan 2 cham bai thi
	
	printf("\n");
	printf("Vui long nhap so bai thi : "); scanf("%d",&baiThi);
	while(baiThi--){
		int maDeCham;
		char traLoi[soCau];
		printf("Nhap so ma de can cham : ");
		scanf("%d",&maDeCham);
		maDeCham -= 1;
		printf("Nhap dap an cua thi sinh: ");
		nhapDACuaTS(traLoi,soCau);
		
		printf("Dap an : \t\t"); xuatDA(dapAn[maDeCham],soCau);
		
		printf("\nDap an cua thi sinh : \t"); xuatDA(traLoi,soCau);
		chamBai(traLoi,dapAn[maDeCham],maDeCham,soCau);
		printf("\n");
	}
		
		
	return 0;
}
