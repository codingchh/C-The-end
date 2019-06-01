#include <stdio.h>
#include <windows.h>
#include<string.h>
#include<conio.h>
#include <stdlib.h>
#define MAX 50
int n;
int mt[MAX][MAX];
void NhapN();
void XuLi();
void HienThi();
int main()
{
    while(1){
        system("cls");
        printf("%20s\n","MENU" );
        printf("1. Nhap n\n2. Tinh ma tran xoay\n3. Hien thi ma tran xoay\n4. Ket thuc\n");
        printf("%15s","Ban chon :" );
        char chon=getch();
        switch(chon){
            case '1':
                NhapN();
                break;
            case '2':
                XuLi();
                break;
            case '3':
                HienThi();
                break;
            case '4':
                exit(0);
        }
    }
}
void NhapN(){
    system("cls");
    printf("Nhap gia tri n : ");
    scanf("%d",&n);
}
//gán giá tr? t? 1->n*n cho m?ng 2 chi?u 
void XuLi(){
    system("cls");
    int chanTangCot,chanTangHang,chanGiamCot,chanGiamHang,cot,hang;
    chanTangHang=chanTangCot=n-1;
    chanGiamHang=chanGiamCot=0;
    cot=hang=0;
    int chuyen=1;
    int i=0;
    while(i<n*n){
        i++;
        mt[hang][cot]=i;
        switch(chuyen){
            case 1:
                if(cot<chanTangCot)
                    cot++;
                else{
                    hang++;
                    chanGiamHang++;
                    chuyen++;
                }
                break;
            case 2:
                if(hang<chanTangHang)
                    hang++;
                else{
                    cot--;
                    chanTangCot--;
                    chuyen++;
                }
                break;
            case 3:
                if(cot>chanGiamCot)
                    cot--;
                else{
                    hang--;
                    chanTangHang--;
                    chuyen++;
                }
                break;
            case 4:
                if(hang>chanGiamHang)
                    hang--;
                else{
                    cot++;
                    chanGiamCot++;
                    chuyen=1;
                }
                break;
        }
    }
    printf("%s\n", "Da tinh xong ma tran xoay !");
    system("pause");
}
void HienThi(){
    // system("cls");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%3d",mt[i][j] );
        }
        printf("\n");
    }
    system("pause");
}

