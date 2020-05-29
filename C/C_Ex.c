#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef unsigned int uint;
int count;
// https://www.runoob.com/cprogramming/c-100-examples.html
void ex3(){
    float i;
    float m, n;

    for(i=1;i<=168;i++){
        m = 0.5*(i-168/i);
        n = 0.5*(i+168/i);
        if(m==(int)m&&n==(int)n&&m>0&&n>0){
            printf("m is: %d.\nn is:%f.\n", m, n);
        }
    }
}

void ex4(){
    int yy, mm, dd, sum;

    printf("Type in your birthday:(ex: 1572,12,21)\n");
    scanf("%d,%d,%d", &yy, &mm, &dd);
    sum = 0;
    switch(mm){
        case 12:
            sum += 30;
        case 11:
            sum += 31;
        case 10:
            sum += 30;
        case 9:
            sum += 31;
        case 8:
            sum += 31;
        case 7:
            sum += 30;
        case 6:
            sum += 31;
        case 5:
            sum += 30;
        case 4:
            sum += 31;
        case 3:
            if(yy%4==0){
                sum += 29;
            }else{
                sum += 28;
            }
        case 2:
            sum += 31;
        case 1:
            break;
        default:
            printf("month invalid.\n");
            exit(-1);
            break;
    }
    sum += dd;
    printf("This is the %d day.\n", sum);
}

void ex5(){
    int len,i,j,tmp;
    // int x[3];
    // len = 3;
    //printf("type in 3 numbers:(1,2,3):\n");
    //scanf("%d,%d,%d", &x[0], &x[1], &x[2]);
    int x[20] = {1,2,7,9,2,76,8,2,76,1,3,45,8,4,1,35,7,87,22,33};
    len = 20;
    for(i=0;i<len;i++){
        for(j=0;j<(len-i-1);j++){
            if(x[j]>x[j+1]){
                tmp = x[j];
                x[j] = x[j+1];
                x[j+1] = tmp;
            }
        }
    }
    for(i=0;i<len;i++){
        printf("%d\n", x[i]);
    }
}

void ex8(){
    int i,j;
    for (i=1;i<=9;i++){
        for(j=1;j<=i;j++){
            printf("%d*%d=%-2d", i,j,i*j);
            if(i==j){
                printf("\n");
            }else{
                printf("  ");
            }
        }
    }
}

void ex11(){
    int month, cycle, pair;
    //printf("type in amount of rabbit:\n");
    //scanf("%d", &month);
    month = 40;
    cycle = 40/3;
    pair = pow(2, cycle);
    printf("At month %d, %d pairs.\n", month, pair);

}

void ex12(){
    int start = 101, end = 200, count = 0;
    int i, j;
    for(i=101;i<=200;i++){
        for(j=2;j<=i/2;j++) {
            if(i%j==0){
                break;
            }
        }
        if(j==(i/2+1)){
            count++;
            printf("%d\n", i);
        }
    }
    printf("total: %d\n", count);
}

void ex13(){
    int start = 100, end = 999, count = 0;
    int num, i, j, k;
    for(num=100;num<1000;num++){
        i = num/100;
        j = (num - 100*i)/10;
        k = (num - 100*i - 10*j);
        if(num==pow(i,3)+pow(j,3)+pow(k,3)){
            printf("%d\n", num);
            count++;
        }
    }
    printf("total number: %d.\n", count);
}

void ex14(){
    int num = 90;
    int i, r;
    r = num;
    while(r!=1){
        for(i=2;i<=r;i++){
            if(r%i==0){
                r=r/i;
                printf("%d", i);
                break;
            }
        }
        if (r!=1){
            printf("*");
        }
    }
    printf("=%d", num);
}

void ex15(){
    int score = 59;
    char rate;
    rate = (score>=90?'A':(score>=60?'B':'C'));
    printf("Rate is %c\n", rate);
}

void ex16(){
    int m = 16, n = 26;
    int r, v;
    int max = (m>n?m:n);
    int min = (m<n?m:n);
    do{
        r = max%min;
        max = min;
        min = r;
    }while(r!=0);
    v = m*n/max;
    printf("gcd is %d, other is %d.\n", max, v);
}

void ex17(){
    char c;
    int i, j, k;
    printf("input string:\n");

    while((c=getchar())!='\n'){
        if ((c>='a' && c<='z') || (c>='A'&&c<='Z')){
            i++;
        }else if(c==' '){
            j++;
        }else{
            k++;
        }
    }
    printf("letter: %d\nwhite space: %d\nothers:%d\n", i, j, k);
}

void ex18(){
    int x[] = {1,2,3};
    int i, j, k;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(i!=j){
                for(k=0;k<3;k++){
                    if(i!=k&&k!=j){
                        if(x[i]!=1&&x[k]!=1&&x[k]!=3){
                            printf("%d, %d, %d\n", x[0], x[1], x[2]);
                        }
                    }
                }
            }
        }
    }
}

void ex19(){
    int m, n;
    int i,j;
    m = 9;
    n = (m+1)/2;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if((j<=(m+1)/2-i) || (j>=(m+1)/2+i)){
                printf(" ");
            }else{
                printf("*");
            }
        }
        printf("\n");
    }
    for(i=1;i<=n-1;i++){
        for(j=1;j<=m;j++){
            if(j<=i||j>=m-i+1){
                printf(" ");
            }else{
                printf("*");
            }
        }
        printf("\n");
    }
}

void ex24(){
    int i, num;
    float x, y, sum, tmp;
    num = 20;
    sum = 0;
    x = 1;
    y = 1;
    for(i=0;i<num;i++){
        tmp = y;
        y = x;
        x = x+tmp;
        printf("%d/%d\n", (int)x, (int)y);
        sum = sum + x/y;
    }
    printf("sum is: %f", sum);
}

void ex25(){
    unsigned int i, j, mul;
    unsigned long sum, num;
    num = 20;
    sum = 0;
    if (num == 0){
        printf("sum is: %d\n", 1);
        return;
    }
    for(i=1;i<=num;i++){
        mul = 1;
        for(j=1;j<=i;j++){
            mul *= j;
        }
        sum += mul;
    }
    printf("sum is %d\n", sum);
    printf("%d\n", sizeof(long));
    printf("%d\n", sizeof(int));
}

unsigned int fact(unsigned int i){
    if(i<=1){
        return 1;
    }else{
        return i*fact(i-1);
    }
}

void ex26(){
    uint k;
    k = 5;
    printf("%d", fact(5));
}

void ex_getchar(){
    char c;
    c = getchar();
    if(c!='\n'){
        ex_getchar();
        printf("%c", c);
    }
}

void ex27(){
    printf("Type in chars.\n");
    ex_getchar();
}

void proNum(int num){
    if (num<10){
        printf("%d", num);
    }else{
        printf("%d", num%10);
        proNum(num/10);
    }
    count ++;
}

void ex28(){
    int num = 126372;
    proNum(num);
    printf("\ntotal digit: %d\n", count);
}

/* pointer */

void C_Ex1(){
    int a[3], i, j, *p, tmp;
    p = a;
    printf("type in 3 nums:\n");
    for(i=0;i<3;i++){
        scanf("%d", p+i);
    }
    for (i=0;i<3;i++){
        for(j=i+1;j<3;j++){
            if(*(p+j)>*(p+i)){
                tmp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = tmp;
            }
        }
    }

    for(i=0;i<3;i++){
        printf("%d\n", a[i]);
    }
}

void C_Ex2(){
    int i, j;

    char c[3][10];
    char *p[3], *tmp;

    printf("type in 3 string:\n");
    for(i=0;i<3;i++){
        p[i] = c[i];
        scanf("%s", p[i]);
        printf("%d\n", strlen(p[i]));
    }
    for (i=0;i<3;i++){
        for(j=i+1;j<3;j++){
            if(strlen(p[j])>strlen(p[i])){
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }

    for(i=0;i<3;i++){
        printf("%s\n", p[i]);
    }
    
}

void C_Ex3(){
    int i, m, n;
    int *p, *q, *o;

    printf("type in n:\n");
    scanf("%d", &n);
    printf("type in m:\n");
    scanf("%d", &m);
    p = (int*)malloc(4*n);
    o = (int*)malloc(4*m);
    q = p;
    for(i=0;i<n;i++){
        *(p+i) = i;
    }
    memcpy((void*)o, (void*)p, 4*m);
    memcpy((void*)p, (void*)(p+m), 4*(n-m));
    memcpy((void*)(p+n-m), (void*)o, 4*m);
    for(i=0;i<n;i++){
        printf("%d\n",*(p+i));
    }
    free(p);
    free(o);
}

void C_Ex4(){
    int len = 10, i, tmp;
    int a[10] = {1,65,23,554,31,3,7,586,123,75};
    int *p, *q;
    p = a;
    q = a;
    for(i=1;i<len;i++){
        if(a[i]>*p){
            p = &a[i];
        }
        if(a[i]<*q){
            q = &a[i];
        }
    }

    tmp = a[0];
    a[0] = *q;
    *q = tmp;
    tmp = a[len-1];
    a[len-1] = *p;
    *p = tmp;
    for(i=0;i<len;i++){
        printf("%d\n", a[i]);
    }
}

void C_Ex5(){
    int i = 0, n, k = 3, count = 0, f, t;
    int *p;
    printf("Type in total num:\n");
    scanf("%d", &n);
    p = (int*)malloc(4*n);
    memset((void*)p, 0, 4*n);
    for(i=0;i<n;i++){
        *(p+i) = i;
    }
    t = n;
    while(t!=1){
        if(*(p+i%n) != 0){
            count++;
            if(count%k == 0){
                *(p+i%n) = 0;
                t--;
            }
        }
        i++;
    }
    f = (i-1)%n;
    printf("last element is %d\n", f);
}

void C_Ex6(){
    printf("%d", 1+3%2);
}

int main(){
    //ex3();
    //ex4();
    //ex5();
    //ex8();
    //ex11();
    //ex12();
    //ex13();
    //ex14();
    //ex15();
    //ex16();
    //ex17();
    //ex19();
    //ex24();
    //ex25();
    //ex26();
    //ex27();
    //ex28();
    //C_Ex1();
    //C_Ex2();
    //C_Ex3();
    //C_Ex4();
    //C_Ex5();
    C_Ex6();

    return 0;
}