# C语言

## 环境

* linux: GCC

* windows: mingw/mysys/mysys2: 提供linux系统的toolchain，但还是基于windows库进行编译和运行。

  https://www.gtk.org/download/windows.php，

  pacman -Syu --disable-download-timeout

  pacman -Su --disable-download-timeout

  pacman -S mingw32/mingw-w64-i686-gtk3

  pacman -S mingw32/mingw-w64-i686-glade

  pacman -S mingw32/mingw-w64-i686-python3-gobject

  pacman -S mingw32/mingw-w64-i686-python2-gobject

  pacman -S mingw-w64-i686-toolchain base-devel --disable-download-timeout

## 运算符

后缀++/--一般是最后执行，前缀++/--先执行。

## 函数

声明函数不需要extern

## 作用域

全局变量和static变量在进程的生命周期内都可以使用，储存在静态储存去内。

**NOTE:** 全局变量储存去分为DATA和BSS，DATA段储存被初始化的全局变量，BSS储存未初始化的全局变量。

局部变量和形参保存在栈中，使用对栈指针的相对地址，调用别的函数是，当前变量和返回地址被压入栈中（栈顶指针上移），函数返回时，释放（栈指针下移）。

static变量：只能在定义的文件或函数中使用。static方法和变量可以被非static方法和变量使用，但是反之不行，因为程序开始时，static成员就存在，但非static成员不存在，所以static成员不能以来实例。

malloc，alloc，new产生的数据被分配到堆的动态内存上。

## 数组

type var [size];

type var [size] = {x,x,x,x,x};

type var [] = {xx,x,x,x};

二维数组和多维数组作为形参时，除第一维度外，其他维度都要指明数字。

void a(int b[]);

void a(int b\[\]\[10\]);

void a(int b\[\]\[\]); **不合法**



```c
int a[10]; // a指数组本身，sizeof(a)为数组整个大小，同时a指向a[0]，*a = a[0]。数值上(int)a = (int)&a[0]，a本身时int *型指针。
int *p; // 指向int的指针，p=a，sizeof(a) 是指针大小
int (*q)[10]; //q是指向10元素数组的指针，q=&a，*q=a，(*q)[0] = a[0], **q = a[0], sizeof(q) = 4;sizeof(*q) = 10;
```



## 指针

* 指向函数的指针：

```c
int (*fc)(int, int);
void (*fb)();
int f (int i, int j){
	return (i+j);
}
int main(){
    int a;
    fc = f;
    a = (*fc)(1,2);
}
```

**NOTE:** fb, *fb, &fb 都指向fb函数的地址。

* ```c
  int a =[10];
  typedef struct st{
      int st1;
      int st2;
  }st;
  st stk;
  int *p1;
  st *p2;
  p1 = a;
  p2 = stk;
  
  
  ```

* 

* 多级指针

  

## 字符串

strcpy(str2, str1): str2 = str1

strcat(str2, str1): str2 = str1 + str2

strlen(str1)

**NOTE:**字符（char），它是一个常量，但是字符串是个指针。

```c
char a[10] = "abc";
char *b;
char c[] = "def";
b = a;
printf("%s", a); //"abc"
printf("%c", a); //错
printf("%s", *a); //错
printf("%c", *a); //"a"
```



## 结构体

```c
struct sA {
    int s1;
    char s2;
};

struct sB {
    int s1;
    char s2;
} sB1;

typedef struct sC {
    int s1;
    char s2;
    int b1:2;
    int b2:3;// 位域，占3bit，多个连续位域至少占32bit
} sC;

struct sA sA1 = {1, "n"};
sC sC1;
sC1 = {2, "N"};
```

* 结构体vs数组

  结构体是一种数据类型，数组是结构类型的队列。

  数组的头可以看成指针，sizeof()返回数组总大小，但+/-操作时会移动元素大小的步长。

  sizeof()普通指针，会返回指针的位数，32位返回4，64位返回8。

  结构体的变量，sizeof()返回结构体大小。需要加上&才能取到指针。

  指向结构体的指针步长为结构体大小。

  所有指针进行+/-时，都会以指向的变量类型的长度为步长。

* 多维数组 vs 指针数组 vs 数组指针
  

数组指针：指向数组的指针 int (*p)[]

指针数组：每个元素为指针的数组 int *p[]

多维数组中，除第一位之外，其他维数均视为一个元素

  int a\[x0\]\[x1\]\[x2\]...  均视为数组a[x0]，元素类型为int \[x1\]\[x2\]

  指向对为数组的指针：int (*p)\[x1\]\[x2\]... = a;

  多维数组展开时按第一维升序展开。

  

  

## union

union所占内存为所有成员最大内存。

```c
union uA{
    int u1;
    char s2;
};
union uA{
    int u1;
    char s2;
} uA1;
typedef union uA{
    int u1;
    char s2;
} uA;
```

## 头文件和extern，const等关键字

头文件中只能放extern（变量和函数声明）

变量和函数定义只能在c/cpp中，若在h中，则多个变量引用h时会产生多重定义错误。

为防止头文件被多次引用，在开头使用。

```c
#ifndef xxx
#def xxx
xxx
#endif
```

定义的const变量若希望让其他文件使用，则需要在定义是加上extern, extern const a = 1，其他文件使用时，extern const a。

## 错误处理

当程序执行出现问题时，errno.h库中，errno会记录error的id，每种error的id不同。

perror("str")：会打印"str: <error information>"

strerror(id)：打印相应id的字符串模式。

## 可变参数

* ```c
  int main(int argc, char* argv[]) // argc是指输入参数个数，argv是字符串指针，在程序开始时，入口为main，例如a.exe aaaa bbb cccc，此时argc=4，argv={"aaaa", "bbb", "cccc"}，以空格隔开。没提供参数，argc = 1，argv[0]为程序名称，第一个参数为argv[1]
  ```

* ```c
  #include <stdio.h>
  #include <stdarg.h>
  
  void check(char y, int i, ...) {
  	va_list var;
  	int x;
  	va_start(var, i);
  	for (x = 0; x < i; x++) {
  		printf("%d\n", va_arg(var, int));
  	}
  	printf("x:%c\n", y);
  }
  
  int main() {
  
  	check('y', 3, 1, 4, 2);
  	return 0;
  }
  ```

  **NOTE:**"..." 后面不能再加参数。

## 动态内存分配

```c
void *calloc(int num, int size): 分配num*size个字节的连续空间并初始化，给返回的指针。
void *malloc(int size): 分配size个字节的空间给指针。
void *realloc(void* ptr, int size): 为ptr重新分配size个字节的空间，并返回原指针。
//上述代码在返回指针后，编译器会记录指针地址对应的代码块长度，以便之后操作。
free(void* ptr)：释放指针指向的内存块。
```

## 浮点类型

***value of floating-point*** **= \*significand\* x \*base\* ^ exponent , with sign --- F.1**
译为中文表达即为：
**（浮点）数值 =   尾数  ×  底数 ^ 指数，（附加正负号）---------------- F.2** 

```c
float:
	bit31(1):正负
    bit30-23(8):指数, 第一位为指数的正负
    bit22-0(23):有效位
    有效位均为0.xxxxx,也就是说有效位储存的数值拿出来以后都要加上“0.”，永远小于1.底数是2.
    float取值范围-2^128--2^128.有效位为2^23(8388608),也就是说最大7位，6位保底。
double：
    指数位为11位
```

## 整形

int和long都是4byte，long long 是8byte

## 数组和指针传入函数作为形参

数组头和指针传入函数后，可以改变数组活指针指向的值，但不能改变数组头和指针本身。