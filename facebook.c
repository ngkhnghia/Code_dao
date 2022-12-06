#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

/*
hàm lựa chọn công việc
1) giải phương trình bậc 1 ax + b = 0
2) kiểm tra một số nguyên có là số hoàn thiện không?
3) liệt kê các số hoàn thiện trong phạm vi từ 1..n
4) tìm ước chung lớn nhất của hai số nguyên a, b nhập từ bàn phím
5) thoát khỏi phương trình
*/


// hàm 1:
void sloveEquation(){
    double a, b;
    printf("Nhap he so a, b cua phuong trinh: ");
    scanf("%lf %lf", &a, &b);
    if (a == 0){
        if (b != 0){
            printf("Phuong trinh vo nghiem\n");
        }
        else{
            printf("Phuong trinh vo so nghiem\n");
        }
    }
    else{
        printf("Nghiem cua phuong trinh la: x = %.5lf", (-b) / a);
    }
}

// hàm 2:
// số hoàn thiện là số có tổng các ước bé hơn nó bằng tổng chính số đó
// vd: 6 là số hoàn thiện vì 6 có các ước 1, 2, 3, 6 nhưng 1 + 2 + 3 = 6
void checkPerfectNumber(){
    int n;
    printf("Nhap so can kiem tra: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i < n; i++){
        if (n % i == 0 && i < n){
            sum += i;
        }
    }
    if (sum == n){
        printf("%d la so hoan thien\n", n);
    }
    else{
        printf("%d khong la so hoan thien\n", n);
    }
}

// hàm 3:
void enumeratePerfectNumber(){
    int n;
    printf("Moi nhap so gioi han de kiem tra: ");
    scanf("%d", &n);
    printf("Danh sach cac so hoan hao: (neu khong co so nao thi danh sach trong)\n");
    for (int i = 1; i <=n ; i++){
        int sum = 0;
        for (int j = 1; j < i; j++){
            if (i % j == 0 && j < i){
                sum += j;
            }
        }
        if (sum == i){
            printf("%d ", i);
        }
    }
}

// hàm 4:
// có thể sử dụng thuật toán Euclid để giảm thời gian xử lý của máy tính
void GCD(){
    int a, b;
    printf("Moi nhap 2 so can tim uoc chung lon nhat: ");
    scanf("%d %d", &a, &b);
    if (a == 0){
        printf("Uoc chung lon nhat cua %d va %d la: %d\n", a, b, b);
        return;
    }
    if (b == 0){
        printf("Uoc chung lon nhat cua %d va %d la: %d\n", a, b, a);
        return;
    }
    int indexMax = 0;
    for (int i = 1; i <= a; i++){
        if (i > b){
            break;
        }
        if (a % i == 0 && b % i == 0){
            indexMax = i;
        }
    }
    printf("Uoc chung lon nhat cua %d va %d la: %d\n", a, b, indexMax);
}

// hàm 5:
void exitMain(){

}
int main(){
    printf("Moi lua chon ham cong viec: ");
    int c = getch() ;
    printf("%c\n", c);
    int key = (int)c - 48;
    switch (key){
        case 1:
            printf("Ham cong viec %d da duoc chon.\n", key);
            sloveEquation();
            break;
        case 2:
            printf("Ham cong viec %d da duoc chon.\n", key);
            checkPerfectNumber();
            break;
        case 3:
            printf("Ham cong viec %d da duoc chon.\n", key);
            enumeratePerfectNumber();
            break;
        case 4:
            printf("Ham cong viec %d da duoc chon.\n", key);
            GCD();
            break;
        case 5:
            printf("Ham cong viec %d da duoc chon.\n", key);
            printf("Chuong trinh se thoat sau 2 giay\n");
            Sleep(2000);
            return 0;
        default:
            printf("\nHam cong viec khong hop le\n");
    }
    return 0;
}