#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef unsigned int uint;
typedef struct myst{
    int val;
    struct myst* Next;
} myst;

typedef enum bool{
    false, true
} bool;

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

int Next(int i, int k){
    return i%k;
}

int Prev(int i, int k){
    if (i==0){
        i = k-1;
    }else{
        i = i-1;
    }
    return i;
}

void C_Ex5(){
    int i = 0, n, k = 3, count = 0, f, t;
    int *p;
    printf("Type in total num:\n");
    scanf("%d", &n);
    p = (int*)malloc(4*n);
    memset((void*)p, 0, 4*n);
    for(i=0;i<n;i++){
        *(p+i) = i+1;
    }
    t = n;
    while(t!=1){
        if(*(p+i) != 0){
            count=Next(count,k);
            if(count == 0){
                *(p+i) = 0;
                t--;
            }
        }
        i = Next(i, n);
        t--;
    }
    f = Prev(i,n);
    printf("last element is %d\n", f);
}



void C_Ex5_2(){

    int i, n, k=3, count=0;
    myst *p, *q;
    printf("Type in num:\n");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        if(i==0){
            p = (myst*)malloc(sizeof(myst));
            q = p;
            p->val = i+1;
            p->Next = p;
        }else{
            q->Next = (myst*)malloc(sizeof(myst));
            q = q->Next;
            q->val = i+1;
            q->Next = p;
        }
    }

    while(p->Next!=p){
        count++;
        if((count%(k-1))==0){
            q = p->Next;
            p->Next = q->Next;
            free(q);
        }
        p = p->Next;
    }

    printf("last item is %d\n", p->val);

}

void C_Ex6(){
    char a[50], *p;
    int i;
    p = a;
    printf("Type in string:\n");
    scanf("%s", a);
    i = 0;
    while(*p!='\0'){
        i++;
        p++;
    }
    printf("String length is:%d\n", i);
}

void C_Ex7(){
    char a[50], b[50], *p, *q;
    int m, len, i;

    p=a;
    q=b;
    printf("Type in string1:\n");
    scanf("%s", a);
    printf("Type in string2:\n");
    scanf("%s", b);
    printf("which position to start:\n");
    scanf("%d", &m);

    len = strlen(a);
    if(m>len){
        printf("m is larger than length of string1.\n");
    }else{
        p = a+m;
        while(*q!='\0'){
            //*(p++) = *(q++);
            *p = *q;
            p++;
            q++;
        }
        *p='\0';
    }
    printf("New string is: %s", a);
}

void C_Ex8(){
    char a;
    int upper= 0, lower=0, space=0, other=0;

    printf("type in\n");
    do{
        a= getchar();
        if((a>='A')&&(a<='Z')){
            upper++;
        }else if((a>='a')&&(a<='z')){
            lower++;
        }else if(a==' '){
            space++;
        }else if(a!='\n'){
            other++;
        }
    }while(a!='\n');
    printf("upper case is %d\nlower case is %d\nspace is %d\nother is %d", upper,lower, space, other);

}

void transit(int a[][4], int xlen, int ylen){
    int i, j;
    int b[ylen][xlen];
    for(i=0;i<xlen;i++){
        for(j=0;j<ylen;j++){
            printf("%3d  ", a[i][j]);
            b[j][i] = a[i][j];
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<ylen;i++){
        for(j=0;j<xlen;j++){
            printf("%3d  ", b[i][j]);
        }
        printf("\n");
    }
}

void C_Ex9(){
    int a[][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    transit(a, 3,4);

}

void C_Ex10(){
    int xlen = 5, ylen =5;
    int a[xlen][ylen];
    int i, j, k, l, tmp, wasted=0;
    int (*p)[5], *max, *min[4], *q[4];
    
    //srand((unsigned int) time(NULL));
    // a = {{rand()%100, rand()%100, rand()%100, rand()%100, rand()%100},
    // {rand()%100, rand()%100, rand()%100, rand()%100, rand()%100},
    // {rand()%100, rand()%100, rand()%100, rand()%100, rand()%100},
    // {rand()%100, rand()%100, rand()%100, rand()%100, rand()%100},
    // {rand()%100, rand()%100, rand()%100, rand()%100, rand()%100}};
    p = a;
    max = *p;
    for(i=0;i<4;i++){
        min[i] = *p+i;
    }
    q[0] = *p;
    q[1] = *p+4;
    q[2] = *(p+4);    
    q[3] = *(p+4)+4;

    for(i=0;i<xlen;i++){
        for(j=0;j<ylen;j++){
            //a[i][j] = rand()%100;
            a[i][j] = 10*i+j;
            printf("%2d  ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n%d %d %d %d %d\n", *max, *min[0], *min[1], *min[2], *min[3]);

    for(i=0;i<xlen;i++){
        for(j=0;j<ylen;j++){
            if(*max<*(*(p+i)+j)){
                max = *(p+i)+j;
            }
        }
    }

    tmp = a[2][2];
    a[2][2] = *max;
    *max = tmp;

    printf("\n%d", *max);

    for(k=0;k<4;k++){
        for(i=0;i<xlen;i++){
            for(j=0;j<ylen;j++){
                wasted = 0;
                for(l=0;l<4;l++){
                    if(*(p+i)+j == q[l]){
                        wasted = 1;
                        break;
                    }
                }
                if (wasted == 0){
                    if(*min[k]>*(*(p+i)+j)){
                        min[k] = *(p+i)+j;
                    }
                }
            }
        }
        printf("  %d", *min[k]);
        tmp = *q[k];
        *q[k] = *min[k];
        *min[k] = tmp;

    }

    printf("\n\n");
    for(i=0;i<xlen;i++){
        for(j=0;j<ylen;j++){
            printf("%2d  ", a[i][j]);
        }
        printf("\n");
    }
}

void C_Ex13(){
    float start, end, i, steplen, sum;
    start = 0;
    end = 1;
    steplen = 0.001;
    
    i = start;
    sum = 0;
    while(i<end){
        sum+=sin(i)*steplen;
        i+=steplen;
    }
    printf("res1 is %f\n", sum);

    i = start;
    sum = 0;
    while(i<end){
        sum+=cos(i)*steplen;
        i+=steplen;
    }
    printf("res2 is %f\n", sum);

    i = start;
    sum = 0;
    while(i<end){
        sum+=exp(i)*steplen;
        i+=steplen;
    }
    printf("res3 is %f\n", sum);
}

void tyin(){
    char c;
    c = getchar();
    if(c!='\n'){
        tyin();
        printf("%c", c);
    }
    return;
}

void C_Ex14(){
    printf("type in chars:\n");
    tyin();
}

void C_Ex16(){
    char str[50], *p;
    int num[25];
    int sum , last, total, i;
    bool isNum = false;
    printf("Type in strings:\n");
    scanf("%s", str);
    p = str;
    total = 0;
    sum = 0;
    while(*p!='\0'){
        switch(*p){
            case '0':
                last = 0;
                sum = 10*sum+last;
                isNum = true;
                break;
            case '1':
                last = 1;
                sum = 10*sum+last;
                isNum = true;
                break;
            case '2':
                last = 2;
                sum = 10*sum+last;
                isNum = true;
                break;
            case '3':
                last = 3;
                sum = 10*sum+last;
                isNum = true;
                break;
            case '4':
                last = 4;
                sum = 10*sum+last;
                isNum = true;
                break;
            case '5':
                last = 5;
                sum = 10*sum+last;
                isNum = true;
                break;
            case '6':
                last = 6;
                sum = 10*sum+last;
                isNum = true;
                break;
            case '7':
                last = 7;
                sum = 10*sum+last;
                isNum = true;
                break;
            case '8':
                last = 8;
                sum = 10*sum+last;
                isNum = true;
                break;
            case '9':
                last = 9;
                sum = 10*sum+last;
                isNum = true;
                break;
            default:
                if(isNum == true){
                    num[total] = sum;
                    total++;
                    sum = 0;
                    isNum = false;
                }
                break;
        }
        p++;
    }
    if(isNum == true){
        num[total] = sum;
        total++;
    }
    printf("total num:%d\n", total);
    for(i=0; i<total; i++){
        printf("%d  ", num[i]);
    }
}

int my_strcmp(char* str1, char* str2){
    while(*str1!='\0'&&*str2!='\0'){
        if(*str1==*str2){
            str1++;
            str2++;
        }else{
            return(str1-str2);
        }
    }
    if(*str1=='\0'){
        return *str2;
    }else if(*str2=='\0'){
        return *str1;
    }else{
        return 0;
    }

}

typedef struct ptrlist {
    void* ptr;
    int size;
    struct ptrlist* Next;
} ptrlist;

typedef struct date{
    int year;
    int month;
    int day;
}Date;

int days(Date dat){
    int sum = 0;
    switch(dat.month){
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
            sum += 28;
            if(dat.year%4==0){
                sum += 1;
            }
        case 2:
            sum += 31;
        case 1:
            break;
        default:
            printf("invalid month");
            return -1;
            break;
    }
    sum += dat.day;

    return sum;
}

void st_ex1(){
    Date dat;

    // printf("tpye in year:\n");
    // scanf("%d", &dat.year);
    // printf("tpye in month:\n");
    // scanf("%d", &dat.month);
    // printf("tpye in day:\n");
    // scanf("%d", &dat.day);

    dat.year = 2011;
    dat.month = 2;
    dat.day = 23;

    printf("This is the %dth day.\n", days(dat));
}

typedef struct student {
    int num;
    char name[10];
    int score[3];
    struct student *Next;
}Student;

void print(Student stu){
    printf("Student num: %d\nName: %s\nScore1: %d\nScore2: %d\nScore3: %d\n\n", \
        stu.num, stu.name, stu.score[0], stu.score[1], stu.score[2]);
}

Student* input(){
    int len = sizeof(Student);
    Student* stu = (Student*)malloc(len);
    printf("Enter student number:\n");
    scanf("%d", stu->num);
    if(stu->num!=0)
    {
        printf("Enter student name:\n");
        scanf("%s", stu->name);
        printf("Enter student score1:\n");
        scanf("%d", stu->score[0]);
        printf("Enter student score2:\n");
        scanf("%d", stu->score[1]);
        printf("Enter student score3:\n");
        scanf("%d", stu->score[2]);
        stu->Next = NULL;
    }

    return stu;
}

Student* create(){
    Student* head = NULL;
    Student* p1, *p2;
    p1 = p2 = head;
    do{
        p1 = input();
        if(p1->num!=0){
            if(head == NULL){
                head = p1;
                p1 = p2 = head;
            }else{
                p2->Next = p1;
                p2 = p1;
            }
        }
    }while(p1->num!=0);
    free(p1);
}

void insert(Student* stu, Student* new_stu){
    Student *next_stu = stu->Next;
    stu->Next = new_stu;
    new_stu->Next = new_stu;
}

void del(Student* head, Student* stu){
    Student* next_stu;
    while(head->Next!=stu){
        head = head->Next;
    }
    head->Next = stu->Next;
    free(stu);
}

void pick(Student* head, Student* stu){
    Student* next_stu;
    while(head->Next!=stu){
        if(head->Next==NULL || head==NULL){
            printf("not found\n");
            return -1;
        }
        head = head->Next;
    }
    head->Next = stu->Next;
    stu->Next = NULL;
}

Student* sort(Student* head){
    Student* new_head = NULL, *p, *p_walk, *new_p;
    p_walk = p = head;
    new_p = new_head;
    while(head->Next!=NULL){
        while(p_walk!=NULL){
            if(p_walk->num < p->num){
                p = p_walk;
            }
            p_walk = p_walk->Next;
        }
        if(p==NULL){
            printf("not found\n");
            return NULL;
        }else{
            pick(head, p);
            if(new_head == NULL){
                new_p = new_head = p;
            }else{
                new_p->Next = p;
                new_p = new_p->Next;
            }
        }
    }
    new_p->Next = head;
    return new_head;
}

void st_ex3(){
    Student* st1 = input();
    print(*st1);
}

void File_Ex3(){
    int diff;
    char c;
    FILE *fp;
    diff = 'A'-'a';
    if ((fp = fopen("File_Ex3.txt", "w")) == NULL){
        printf("File not opened.\n");
        exit(0);
    }
    printf("Type in information:\n");
    do{
        c = getchar();
        if (c>='a'&&c<='z'){
            c += diff;
        }
        fputc(c, fp);
    }while(c!='!');
    fclose(fp);
}

void File_Ex4(){
    char c;
    FILE *fp1, *fp2;
    if((fp1=fopen("File_Ex3.txt", "r")) == NULL){
        printf("File 1 not found.\n");
        exit(0);
    }
    if((fp2=fopen("File_Ex4.txt", "w")) == NULL){
        printf("File 2 not found.\n");
        exit(0);
    }
    c = fgetc(fp1);
    while(c!=EOF){
        fputc(c, fp2);
        c = fgetc(fp1); 
    }
    fclose(fp1);
    fclose(fp2);
}


void File_Ex5(){

}


int main(){
    char c;
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
    //C_Ex5_2();
    //C_Ex6();
    //C_Ex7();
    //C_Ex8();
    //C_Ex9();
    //C_Ex10();
    //C_Ex13();
    //C_Ex16();
    //st_ex1();
    //st_ex3();
    //File_Ex3();
    File_Ex4();
    


    return 0;
}