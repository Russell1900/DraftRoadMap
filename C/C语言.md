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

**b 和 &b的int值相同**

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

  int a\[x0\]\[x1\]\[x2\]... : a+k = &(a[k]), \*(a+k)+i = &(a\[k\]\[i\]),...., *(a+k) = a[k] = &a\[k\]\[0\]=a+k



  

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

## 文件 

用户需要时就将数据从磁盘文件输入到内存中，编辑之后再保存回磁盘中。操作系统把各种设备同意按照磁盘文件来处理。读取文件均由操作系统来处理。C语言将文件看作成一个字符的序列。读写文件时，数据通过流（stream），在程序和磁盘间相互传输。

**NOTE：**平时我们的变量时在对内存操作，像内存保存信息，对文件操作实际上是对计算击的外部储存设备（I/O）进行操作，需要通过通道（流）与IO相连。

文件分为**二进制文件**和**文本文件**，文本文件（txt）保存时将数据从二进制转化问ASCII或utf-8等编码格式。二进制（bin）文件则直接将内存中的数据保存至文件。文本文件方式保存时，所占空间较大，转换时间较长。

ANSI C中，提供文件缓冲区，在读取文件时，从相应的文件中将读取数据到缓冲区直到占满，写文件时，先从内存写道文件缓冲区，写满后再向磁盘储存。提高效率，节省时间。

在打开文件时，先创建文件类型的结构体，再将文件内容读入缓冲区，在根据打开方式设置指针位置。关闭文件是释放缓冲区和结构体。

### 读写操作

console/keyboard：putchar()，getchar()，向console输出一个char，从键盘输入一个char。printf，scanf。puts，gets。

文件：fputc('a', fp)，向fp的stream中写入一个byte('a')，ch=fgetc(fp)。feof(fp)，返回bool判断文件是否结束，EOF定义为-1，feof(in)等价于ch\==-1,ch\==EOF。

fputs(str,fp)：向fp写入字符串str，成功返回0

fgets(str, len, fp)：从fp读取len长的字符串存到str中，成功返回str地址，失败返回值NULL

fscanf(fp，“ %d xxxx”，&i，xxx)：从fp中读取“%dxxx”样式的字符串，写入i xxx中。

fprintf（fp，“%d xxx”，i）：向fp中输出。

fread(buffer, size, count, fp): 从fp（二进制打开）中，读取size*count的字节数，储存到buffer中。

fwrite(buffer, size, count, fp): 向fp（二进制打开）中，从buffer输入size*count的字计数。

fp = fopen(file, mode):打开文件将文件内容录入缓冲区

fclose(fp):将缓冲区保存至文件，关闭文件，清除缓冲区。

rewind(fp): 将fp的位置标记返回至文件头。

fseek(fp, len, start): 将位置标记从start除后移len字符（可以为负）。start = {SEEK_SET（起始）, SEEK_CUR（当前）, SEEK_END（终止）}

ftell(fp)：返回fp文件位置标记的当前位置。出错时返回-1.

ferror(fp)：在执行文件操作时，除了执行的语句会返回成功/报错的信息，fp也会储存当前语句的结果信息，ferror用于读取这个信息，0的时候表示无错误。

clearerr(fp)：清楚文件当前错误.

**NOTE:**putchar，getchar都是从std in/out put。putc，getc，fputc，fgetc都是对文件，f表示function，没有f的是以宏实现的。

## 变量声明

变量声明时，先看括号里面的，然后从右向左读

```c
int* (*(*p)[])(void) // p是指针，*p是数组，数组的元素是指针，指向函数，函数的形参是void，返回值是int*
```

## 多线程 pthread

### 基本

```c
int pthread_create (pthread_t* __restrict __newthread, // 返回的线程指针，用来辨识线程id
                    const pthread_attr_t *__restrict __attr, // 线程属性
                    void *(*__start_routine) （void*), // 调用的函数 要为void * f（void*）型
					void *__restrict __arg); // 传给函数的参数，要转化为 void*
//创建成功后返回0，否则失败

void pthread_join(pthread_t pId, // 挂起当前线程，等待pId线程结束
                  void** status); // 

// 线程的attrubute
pthread_att_t*， 创建时可写NULL， 表明线程调度策略，栈堆，join detach等信息;
pthread_attr_init: 创建pthread_att_t;
pthread_attr_destroy: 销毁pthread_att_t;

/* 结束
1. 线程调用函数return时，线程结束。
2. void pthread_exit(void *retval), 退出当前线程.retval使用户指定的线程结束后返回的参数。
3. int pthread_cancel(pthread_t pId)：结束pId线程。成功返回0.
4. 进程调用exec()或exit()退出时，子线程也会结束。
5. main()函数结束时，如果main没有调用pthread_exit结束，所有线程也会结束。

僵尸线程：如果一个线程为joinable的话，线程退出后会保留自己的pId、退出信息等，直到有人join该线程才会释放。此时若没有线程去join它，则该线程变为僵尸线程。
设置成detachable状态则会不保留。方法
1. 开始时设置属性为detachable
2. pthread_detach()

*/
int pthread_join(pthread_t pId, void **value_ptr); //阻塞当前线程，知道pId返回。 一般的，一个可以被阻塞的线程只能被一个线程join，多个线程join一个线程，结果未知。自己不能join自己。
/*一般线程被创建是默认是joinable的，建议显式的创建joinable属性。

*/

pthread_detach(pId); // 设置pId为detachable
pthread_attr_setdetachstate(&attr, detachstate); // 设置pId为detachable
pthread_attr_getdetachstate(&attr, detachstate); // 查询pId的detachable属性

// 实例
pthread_t pId; // 声明线程id
pthread_attr_t attr; // 声明线程属性
pthread_attr_init(&attr); // 初始化属性，如分配栈堆地址和空间等。
pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); //设置属性joinable
pthread_create(&pId, &attr, func, param); // 创建线程
pthread_attr_destroy(&attr); // 销毁属性，在创建完线程后就可以销毁。

/* 线程的栈堆管理：手动设置线程栈堆的大小可以有助于代码移植

*/
pthread_attr_setstacksize(&attr, stacksize);
pthread_attr_getstacksize(&attr, &stacksize);

pthread_attr_setstackaddr(&attr, stackaddr);
pthread_attr_getstackaddr(&attr, &stackaddr);

//detach  ????




// 其他
pthread_t pthreadself(); // 返回当前线程id
int pthread_equal(pId1, pId2); //比较两个线程id，不同返回0，相同返回非0
```

### Mutex 互斥锁

当多个线程同时操作一个地址或其他操作时，有些情况下会造成混乱，所以需要创建mutex并在程序中相应的位置申请/释放mutex，老保证通过是只有一段代码在执行。

```c++
pthread_mutex_t mutex;
pthread_mutex_init(pthread_mutex_t *mutex, pthread_mutex_attr_t *attr);//初始化mutex
mutex = PTHREAD_MUTEX_INITIALIZER; //另一种初始化方法
pthread_mutex_destroy(pthread_mutex_t *mutex);//销毁mutex
pthread_mutex_init(pthread_mutex_attr_t *attr);//初始化mutex attr
pthread_mutex_destroy(pthread_mutex_attr_t *attr);//初始化mutex attr
pthread_mutex_lock（pthread_mutex_t *mutexId); //申请mutexId, 如果当前锁没有释放，则线程阻塞，等待锁释放，若有多个线程同时等待，则在解锁后相互竞争。
pthread_mutex_trylock(pthread_mutex_t *mutexId); //尝试申请所，若失败则返回错误???
pthread_mutex_unlock(pthread_mutex_t *mutexId); //释放锁
```

### 条件变量

条件变量允许线程等待其他线程信号，然后开始尝试唤醒锁进行操作。

```C++
// 初始化条件锁
pthread_cond_t myConvar = PTHREAD_COND_INITIALIZER; //or
pthread_cond_t myConvar;
pthread_cond_init(&myConvar, &attr);

// wait
pthread_cond_wait(&condition, &mutex); // 调用时，需要确保mutex在锁定状态，通常需要在当前线程的上文锁定mutex，然后调用次函数。调用后，当前线程进入阻塞状态，并释放mutex，并开始等待condition信号。在收到condition信号后，对mutex进行监视，当mutex解锁后，锁定mutex继续当前线程。

// 发送信号cond，来激活被当前锁阻塞的cond_wait。
pthread_cond_signal(&cond);

//向所有被cond阻塞的锁发送信号
pthread_broadcast(&cond);

//销毁cond
pthread_cond_destroy(&cond);
```

问题：pthread_cond_wait和pthread_mutex_lock, 如果有多个线程通过这两个函数在争夺同一个mutex, mutex的申请顺序。

## 函数调用过程

调用函数时：主调函数先将被调函数传入的参数压入栈顶（一般是从右向左），然后保留call的下一步地址并跳转到call的目标地址。

函数开始执行时：先分配当前函数栈：此时，EBP和ESP仍处于上一个主调函数的位置。先将EBP（栈底指针）压入栈中，再将ESP（栈顶指针）传入EBP，然后分配当前函数的占空间，并向上移动栈顶指针至栈顶。（栈的生长方向时从大地址向小地址，所以向上移动指针实际上是向小地址移动）。然后在栈顶保存寄存器的值（保存哪些寄存器和顺序由编译器预定而定）。然后开始执行函数。

函数返回时：先保存返回指，然后恢复寄存器的值，然后移动栈帧恢复主调函数的栈区，然后跳转到返回地址，舍弃形参。继续执行主调函数。

## 运算符顺序

*  https://blog.csdn.net/yuliying/article/details/72898132 

自身运算符>单目运算符>双目运算符>三目运算

数值运算>比较运算>逻辑运算>赋值运算

