# C++

## C++ vs C

```c
/*g++ = gcc -lstdc++

using namespace std；

thread_local: thread_local int x; // 在当前线程副本下创建变量，只能供当前线程访问，每个线程都有自己的变量副本。

函数定义时支持默认值变量。void f(int a, int b=2), 默认值变量需要在必须变量后。

lambda：// don't know
//#include <string> 提供string这个类，不必声明长度等。
引用：引用和指针类似，都是指向一块内存，区别是：引用定义时必须指向一块内存，一旦定义不能更改，必须在创建时初始化，修改引用和修改原变量一样。
void f(int &a); 传入参数时，a必须是int型，且会被当成引用处理，即在函数中修改a的值，函数返回时a的值也会改变。
int a;
int& n = a;

*/
```

## 类

```c
#include <iostream>
using namespace std;

class animal{
    public:
    	animal(int age, int weight);
    
    protected:
    	int age;
    	int weight;
    
    private:
    	int a;
    	
}
animal::animal(int age, int weight){
    ...;
    ...;
}
```

## string

```c++
#include <string>
string str;
str.size();
str.empty(); //返回true/false，判断字符串是不是空
cin>>str; //从流中输入到str，以回车、空格等分隔符分割。
getline(stream, str); //从stream中输入到str，遇到换行符结束。
str[0],str[1],...;
```





