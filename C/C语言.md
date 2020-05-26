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

## 指针

指向函数的指针：

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

## 字符串

strcpy(str2, str1): str2 = str1

strcat(str2, str1): str2 = str1 + str2

strlen(str1)

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


