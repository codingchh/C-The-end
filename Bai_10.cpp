#include<stdio.h>
#include<math.h>
#include<windows.h>
int main()
{
	int thang,nam;
	while(1){
		system("cls");
		lable:
		printf("Nhap 2 so la thang va nam : ");
		scanf("%d%d",&thang,&nam);
		if(thang<1||thang>12||nam<0){
			printf("\nSo lieu khong hop le !!\nNhap lai \n");
			goto lable;
		}
		else{
		switch(thang){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				printf("\nThang %d nam %d co 31 ngay.",thang,nam);
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				printf("\nThang %d nam %d co 30 ngay.",thang,nam);
				break;
			case 2:
				if(nam%4==0)
					printf("\nThang 2 nam %d co 28 ngay.",nam);
				else
					printf("\nThang 2 nam %d co 29 ngay.",nam);
				break;
		}
		printf("\nBan co muon tiep tuc ? (c/k)\n");
		fflush(stdin);
		char chon=getchar();
		if(chon=='k')
			exit(0);
		}
	}
}
//Hoang Huy
