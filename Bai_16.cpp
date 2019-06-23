#include <stdio.h>
#include <windows.h>
#include<string.h>
#include<conio.h>
#include <stdlib.h>
#define MAX 50
int a[MAX],b[MAX],c[MAX];
int n1,n2;
void NhapDaySo();
void Ghep2Day();
void In();
int main()
{
    while(1){
        system("cls");
        printf("%20s\n", "MENU");
        printf("1. Nhap 2 day nguyen theo chieu tang dan\n2. Ghep hai day \n3. In 3 day so\n4. Ket thuc\n");
        char chon=getch();
        switch(chon){
            case '1':
                NhapDaySo();
                break;
            case '2':
                Ghep2Day();
                break;
            case '3':
                In();
                break;
            case '4':
                exit(0);
        }
    }
}
void NhapDaySo(){
    system("cls");
    printf("%s\n", "Nhap hai day nguyen theo chieu tang dan");
    printf("%s\n", "Nhap so phan tu day thu nhat :");
    scanf("%d",&n1);
    printf("%s\n", "Nhap cac phan tu day thu nhat theo chieu tang dan :");
    for(int i=0;i<n1;i++)
        scanf("%d",&a[i]);
    printf("%s\n", "Nhap so phan tu day thu hai :");
    scanf("%d",&n2);
    printf("%s\n", "Nhap cac phan tu day thu hai theo chieu tang dan :");
    for(int i=0;i<n2;i++)
        scanf("%d",&b[i]);
}
void Ghep2Day(){
    system("cls");
    if(a[n1-1]<b[n2-1])
        c[n1+n2-1]=b[n2-1];
    else
        c[n1+n2-1]=a[n1-1];
    // đoạn if này là do nếu để phần tử cuối cùng so sánh thì i 
    // của a hoặc j của b sẽ vượt quá n1 hoặc n2 làm cho c[n1+n2]= giá trị k xđịnh
    // nên dòng if(a[i]<b[j]) dưới này sẽ k so sánh đúng :>
    int i,j,k;
    i=j=k=0;
    while(k<n1+n2-1){
        if(a[i]<b[j]){
            c[k]=a[i]; 
            i++;
        }
        else{
            c[k]=b[j]; 
            j++;
        }
        k++;
    	if(i==n1){
    		a[n1]=b[n2-1];
    	}//nếu i vượt quá số ptử của arr a thì cho a[n1]=b[max]
    	else if(j==n2){
    		b[n2]=a[n1-1];
    	}//nếu j vượt quá số ptử của arr b thì cho b[n2]=a[max]
    }
    printf("%s\n", "Da ghep hai day thanh cong ");
    system("pause");
}
void In(){
    system("cls");
    printf("%s\n", "Day thu nhat :");
    for(int i=0;i<n1;i++){
        printf("%5d",a[i] );
    }
    printf("\n%s\n", "Day thu hai :");
    for(int i=0;i<n2;i++){
        printf("%5d",b[i] );
    }
    printf("\n%s\n", "Day ket hop :");
    for(int i=0;i<n1+n2;i++){
        printf("%5d",c[i] );
    }
    printf("\n");
    system("pause");
}
// Hoang Huy

