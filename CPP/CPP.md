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

一般class定义在头文件中，其函数实现在从cpp文件中（除inline外，inline还是在头文件中）。

memberwise initialization: 成员逐一初始化，copy constructor

类内部的函数实际上都有第一个默认的传入参数都是this。

但friend函数，没有此参数，但可以访问类中的私有变量。

function obj 是一种特殊的类，通过重载operator()，当建立之后，再次电泳class_name(...)时，会直接调用class_name.operator(...)

指向member function的指针：return_type (class_type::*ptr_name) (param); 定义了一个指向class_type中的函数。 ptr_name=&class_tpye::function;（初始化）

调用时，class_name a, \*b=&a; (a.\*ptr_name)(param); (b->*ptr_name)(param);

```c
#include <iostream>
#include <vector>
using namespace std;

class shape{
    public:
    	typedef tri_iterator iterator;
    	shape();
    	shape(int age, int weight);
    	shape(const Matrix &rhs); // copy constructor, 不定义copy constructor时，系统会调用默认的。会将rhs的直接复制过来，但是当class中有new或者malloc这种算符时，或者指针变量的时候，同样的，会将rhs指向的内容传入。此时如果rhs释放了相应内存，但本instance的指针类仍会指向该位置（被释放的位置）。
    	int get_area();
		const vector<int>* get_data() const; //声明const函数，当类作为const shape& 传入时，只能调用const函数或数据成员。const函数中也不可以修改除被声明为mutable之外的成员变量。
		vector<int>* get_data(); // 根据const重载get_data，函数调用时。若当前instance不是const类型，函数调用get_data会优先尝试非congst，但当不符合时，在尝试const
    	~shape(); //deconstructor
    
    	static int get_id(); // 声明静态函数，无论在类的内部还是外部，需要调用静态函数时都要加上类名：shape::get_id(); 函数内时不加类名也可以，但有时会玉non—static混淆
    
    protected:
    	int dimension;
    
    private:
    	int _area;
    	static int _common_id; // 此处是_common_id的声明，还需要再定义
    	static const int _common_id1 = 1; // static const 成员，此处为定义和初始化。不需要也不能再在别处定义。外部使用（public时），shape::_common_id1。
    	int _id;
    	mutable int _next; // 此成员被声明称mutable，可以在const函数中被改变。一般这种变量不是class状态属性，而是用来表示类似成员中数组元素的位置等信息.
    	vector<int> *_data;
}
shape::shape():dimension(2),area(0){
	_data = new int[10];
}

int get_id(){	// 静态函数定义
	return _common_id;
}

int shape::_id;

int main(){
    animal ian; //调用默认（无参数）初始化函数。 animal ian() 会被编译器认为函数函数。
}

shape::iterator; 
```



```c++
class tri_iterator {
    public:
    	tri_iterator(int idx);
    	// 运算符重载
    	inline bool operator==(const triangular& rhs);
    	inline bool operator!=(const triangular& rhs);
    	inline tri tri_iterator::operator*(); //dereference
    	inline tri_iterator++(); //前置++
    	inline tri_iterator++(int); //后置++，编译器对后置++强行加入int参数，但调用时不需要，编译器自动设为0.用户不用操心。
    	friend inline bool operator==(const triangular& lhs, const triangular& rhs);
    	friend inline bool shape::get_area(); //也可以将其他类中的函数作为自己的友元函数。此处只是声明，并没有定义。
    	friend class tri; //声明tri为友元类，tri中算有成员都能访问此类中成员。
    private:
    	int _index;
}

tri_iterator::tri_iterator(int idx):_index(idx){}

bool tri_iterator::operator==(const triangular& rhs){
    return _area == rhs.get_area();
}

bool tri_iterator::operator!=(const triangular& rhs){
    return !(*this==rhs);
}

tri tri_iterator::operator*(){
    return tri::data[index]; //tri
}

/* 重载运算符规则：
 * 若当前运算符和某运算符是相反的关系，则可借助其实现
 * 不可重载的运算符：., .*, ::, ?:
 * 运算符操作数不能变，优先级不能变，
 * 要被重载的运算符中至少有一个参数是class类型（例如指针就不是class）。
 */
```

```c++
//定义function object：
class less{
    public:
    	less(int val):_val(val){}
    	bool operator()(int value) const; //重载（）
    private:
    	int _val;
}
bool operator()(int value) const {
    return _val<value;
}

int main(){
    less lt(1); //定义并初始化lt，设置_val=1
    lt(2); //调用operator() 返回 2<1
}
```



## string

```c++
#include <string>
string str;
+, =, ==, !=
str.size();
str.empty(); //返回true/false，判断字符串是不是空
cin>>str; //从流中输入到str，以回车、空格等分隔符分割。
getline(stream, str); //从stream中输入到str，遇到换行符结束。
str[0],str[1],...;

/*string和char*：
C++中，char*可以直接当作string运算，但是string不能当作char*。
例如有些函数只接受char*，不接受string：getline(char*, int)
但给string赋值时可以直接str=char*。
string给char*赋值：char*=string.c_str()。
另外可以string+char*，但不可以char*+char*，需要用strcat，strcpy，strcmp等函数完成char*直接的操作。
```

## vector

```c++
#include <vector>
// 初始化
vector<type> vector_name;
vector<type> vector_name(size);
vector<type> vector_name(size, val);
vector<type> vector_name(InputIterator1, InputIterator2); // 将InputIterator1和InputIterator2之间的元素传入vector，不包括InputIterator2中的元素
/* 例子 */
int a[] = {1,2,3,4,5};
vector<int> v(a+1, a+4);

vector<type> vector_name(vector);


// 常用操作
vector_name.size(); //返回大小
vector_name.max_size(); //返回最大大小
vector_name.capacity(); //返回容量。vector在创建的时候会考虑到扩展的因素，会多分配一些资源，vector中的元素地址是连续的，为了做到这一点，当新的元素加入时，需要reallocate，但是reallocate很花时间，所以会多分配一些资源，当超过capacity时，会执行reallocate
vector_name.empty(); // vector是empty时返回true

vector_name.front(); // 返回第一个值
vector_name.back(); // 返回最后一个值

vector_name.push_back(); // 在最后插入值，size++
vector_name.pop_back(); // 删除最后一个元素，size--，不返回值

vector_name.insert(iterator positon, val); // 将val插入position，所有元素后移，size++
vector_name.insert(iterator positon, InputIterator1, InputIterator2); //将InputIterator1和InputIterator2之间的元素插入position，所有元素后移，size+，不包括InputIterator2中的元素
/* 例子 */
vector<int> v;
int a[] = {1,2,3,4,5}
...
v.insert(v.begin()+2, a+1, a+3);

vector_name.erase(iterator positon); //删除position，重新排序，size--
vector_name.erase(InputIterator1, InputIterator2); //将InputIterator1和InputIterator2之间的元素删除，重新排序，size-

vector_name.clear();//清空数组
vector_name.swap(vector1); //将vector_name与vector1完全交换。

```

## 文件读写

```c++
#include <fstream>

ifstream // 输入文件
ofstream // 输出文件
fstream  //继承以上二者

// 创建
ifstream in("text.txt"); //or
ifstream in;
in = open("text.txt"); //二者皆可，构造函数中包含了open，文件打开后会返回文件指针。若打开失败返回NULL
if (!in){
    cerr << "File open failed." <<endl;  //cerr 是标准错误输出
}
string a, b;
in>>a>>b; //从in中读取内容，遇到分隔符停止，先传入a，再读取，传入b。当出错时返回null（比如读到文件尾）
in.getline(char*, int); // 从in中取出一行置入char*中，int取出最大字节数，通常为char*的长度，当到达长度上限时，会将内置的failbit设置为1。返回this。
eof(in); //判断文件是否结束，结束返回true
in.close();

ofstream out("text.txt"); //or
ofstream out;
out = open("text.txt"); //二者皆可，构造函数中包含了open，文件打开后会返回文件指针。若打开失败返回NULL
if (!out){
    cerr << "File open failed." <<endl;  //cerr 是标准错误输出
}
string a, b;
//...
out<<a<<b; //将a b的内容传入out中
out.close();

fstream fio("filename", ios_base::in|io_base::out|ios_base::app|ios_base::binary);
fstream fio;
fio = open("filename", ios_base::in|io_base::out|ios_base::app|ios_base::binary); //fstream 继承了i/ofstream，打开时声明需要做的操作。
//in和out不会抹去文件内容，游标在最前面。in和app同时用时，游标也会在最前面。

//二进制文件
ios_base::binary;
foi.write(char* buffer, streamsize size);//从buffer向foi写入size个字节
foi.read(char* buffer, streamsize size);//从foi向buffer写入size个字节


//游标操作:游标分两个，get和put stream pointer
pos_type tellg();// 返回get pointer位置，基于文件开始。
pos_type tellp();// 返回put pointer位置，基于文件开始。

seekg(pos_type, seekdir); //设置get pointer位置，基于seekdir
seekp(pos_type, seekdir); //设置put pointer位置，基于seekdir
// seekdir:ios::beg, ios::cur, ios::end，文件开始，当前，结尾。在以文本格式下打开时不推荐用，可能会产生不可预知后果，由于某些特殊字符。pos_type可是负数。当至于结尾时，游标指向空。len=end-begin（不用+1）
// 游标的位置不会单独计算，而是根据读写一起计算，就算只执行读的操作，写的游标也会发生变化，二者其实是相同的游标。


/*缓存和同步
缓存：当我们在对文件读写时，os会创建一块中间内存（缓存区），将文件的一部分读入（in类型打开），读写时都会从缓存区读写，而不是直接对文件操作。
同步：缓存区的内容被flush或传入文件的操作，叫做同步。同步会在一下情况发生
1. 文件关闭时，in打开的会被flush，out打开的会被传入文件。
2. buffer满时：会同步到文件。
3. 遇到操作符flush和endl时。
4. 显示调用sync()，返回-1时表示失败。

//std in/out: cin读取完成后会将buffer中的分隔符舍弃掉。
```

## 内存

处于静态区分配区的变量（static或全局变量），在main执行前会被初始化为0。动态区（堆栈区）的变量不会被初始化，初始值取决于上一次该段地址的遗留，所以动态变量一定要初始化。

new/delete：new 返回指针。声明数组：type a = new type\[len](), delete a：只删除a。

new xxx[]/delete[]：定义和删除数组。delete[]会将整个数组删除，delete只会删除第一个元素。

## 函数模板

```c++
// 函数模板不是函数实例，需要在编译时根据传入参数类型进行实例化并调用。
template <typename varType1, typename varType2, ...> return_type function_name(para_list...) //varTypeX必须都在paralist中使用，一遍编译器知道要传入的类型，从而根据传入的类型生成函数实例并调用。
//函数模板也可以根据不同的para_list进行重载。
```

## 头文件

在头文件中不要定义函数和变量，否则一旦两个文件用到同一个在头文件中定义的参数并链接到一起，则会产生重复定义错误。

头文件中可以定义一些结构体、class、union等类型，但不要定义实例。

**NOTE：**有两种例外情况：inline函数和const object，这两者可以在头文件中定义，编译器只会定义一次

" " vs <>：#include "head"：表示head是用户提供的头文件，链接时先在当前目录下查找，再去编译器指定的位置查找。#include \<head>：表示head是标准或项目指定的头文件，编译器直接去编译器指定的位置查找。

对于有默认参数的函数，默认参数写在头文件除。

## 泛型容器Generic Container & 泛型算法 & 迭代器Iterator

泛型容器是指可以适用于不同类型的容器，泛型算法指适用于不同容器不同类型的算法。

迭代器是每种容器中内置的一个类，begin()和end()返回容器两端元素的指针，并且迭代器中重载了指针的+,-,==,!=运算。

vector：将元素保存于连续线性空间，对随机访问效率很高，但是随机插入/删除效率低，因为删除和插入后后面的元素要重新排列。后插和后删不影响。定义时会赋予vector一个capacity，使用时如果超过capacity，重新分配更大的空间。但&vector的值不变（所有变量的地址一旦定义都不会改变）。

list：双向链表实现，对随机访问效率低，需要遍历。但对于随即插入/删除效率高。

deque：与vector储存方式相似，但是对于前端的插入/删除效率也很高。

**new ojb()：返回&obj。**

**delete []：会将容器中的元素也释放。**

### 容器

#### list

list\<type> li;

front(), back()

push_back(), push_front()

pop_back(), pop_front()

insert(), erase()

#### map

map<key, value>: 储存一对值,常用于字典等. 对于map而言,key必须是不重复的.

```c++
map<string, int> words; // 建立字典,统计sitrng出现的次数.
words["we"]++; // int值初始为0,建立"we"元素,并++ words["we"] == 1;若已存在we,则只执行++.(先查询,在操作)
map<string, int>::iterator ite1 = words.begin();
map<string, int>::iterator ite2 = words.end();
ite->firtst; //取出key值
ite->second; //取出value值
// 在字典中查找摸个key值,由于一旦调用words[key], key元组则会被建立并初始化,所以不能直接查询.
words.find(key); //找到则返回iterator,否则返回end()
words.count(words[key]); //统计words[key]出现的个数,也不会建立key元素
for(ite=ite1;ite!=ite2;ite++){
	if(ite->first==key) return ite;
} // iterator查找

// map 排序???
```

#### set

set中的元素不可重复,添加元素时会先查看元素是否在set中,存在的话便舍弃. set中元素默认排序使用less_than.

```c
set<string> iset;
iset.count("a"); // 搜索a在set中是否出现,0则不存在
iset.insert("a"); //将a插入iset中.
```



### Iterator

Iterator：vector\<int>::Iterator，泛型容器中的嵌套类；Iterator.begin(), Iterator.end()返回元素序列起始和元素序列终止地址(下一个将要使用的元素但还未使用,这是因为很多泛型算法要求的界限时[begin, end), 不匹配时通常返回end)。可对int做+ - 运算. ==/!=.*ite为元素的值,ite++为下一个元素.

```c++
Iterator ite;
// 通用操作
ite++;
++ite;
ite--;
---ite;
*ite;
ite1 == ite2;
ite1 != ite2;
ite->...;

//只对queue和vector等连续iterator有效
ite+=n; //后面的第n个元素
ite1+=ite2; // ???
ite1-ite2; // 计算两者直接距离
<,>,<=.>=;
```



#### Iterator Inserter (inserter adapter)

inserter(container,...): 以容器为传入函数, 返回一个inserter_iterator(可当成iterator的子类处理),当返回的iterator被赋值时,容器会自动向后扩展, 并执行inserter_iterator++(插入值位置会向下延深,二位继续在之前位置插入).

```c++
#include <iterator>
vector<int> v(4,0);
ite1 = back_inserter(v); // 返回end() [back/front_]inserter_iterator<vector<int>>
ite2 = front_inserter(v); // 返回begin() ite, 只对deque和list有效,其他无效.
ite3 = inserter(v, v.begin()+i); // 返回begin()+i的ite
*ite1 = ...; //赋值
```

#### iostream iterator

将io设备当成iterator来处理:

```c++
#include <iterator>
#include <fstream>
fstream f1("f1.txt", ios_base::in);
fstream f2("f2.txt", ios_base::out);
istream_iterator istr(cin); // 将istr 绑定之cin,也可以绑定为ifstream
istream_iterator eof; // 将eof绑定为NULL,可以当作品输入的终止iterator
ostream_iterator ostr(cout, " "); // 将istr 绑定之cout,也可以绑定为ofstream, 第二个参数为什么见分隔符,默认没有.""
vector<string> v;
copy(istr, eof, back_inserter(v));
sort(v.begin(), v.end());
copy(v.begin(), v.end(), ostr);
f1.close();
f2.close();
```



### 泛型算法

通用方法：==, !=, =, empty(), size(), clear()

泛型算法：find, count, merge, sort...

```c++
#include <algorithm>
Iterator find(Iterator begin, Iterator last, val); // 无序搜索,搜索[begin, last)之间,返回与val相同的Iterator,否则返回last.
binary_search(); // 有序搜索,搜索到返回true,否则返回false,效率比find高,但需对输入的一对iterator进行排序(sort)
count();// 返回与元素相同的个数.
search(); // 搜索一个子列,搜到返回主列起始位置的Iterator
sort(begin, end); // 排序,并将值返回到[begin,end)指向的地址之间.默认使用less_than算符.
copy(begin, end, target); //将[begin, end) 返回到target起始的位置.
find_if(begin, end, filter); // filter为一元算符,返回true/false,顺序作用于[begin, end)返回true时返回对应的iterator
```

#### function object

function object是函数类, 通过将函数定义成类,完成重载等操作.

标准库中的fo:

```c++
#include <functional>
plus<type>;
minus<type>;
negate<type>;
multiplies<type>;
divides<type>;
modules<type>;

less<type>;
less_equal<type>;
greater<type>;
greater_equal<type>;
equal_to<type>;
not_equal_to<type>;

logical_and<type>;
logical_or<type>;
logical_not<type>;

//example
plus<int>(); // 返回一个int + 的fo实例

//function object bind adapter, 可以将二元算符转化为一元算符:
plus<int> pl;
const int val = 2;
binder2nd<plus<int>> pl2 = bind2nd(pl, val);//plus是二元算符,v1+v2, 此时相当于将v2绑定为val,之传入v1即可. pl2(x) = pl(x, val)
```

## 继承/多态

* 抽象类：abstract class，抽象类是无法产生实例的类，但是其中声明了一些方法，在其子类中实现，可借助抽象类做传入参数类型，在函数内调用其声明的方法。 

* 多态polymorphism：允许基类的pointer或者reference指向任何一个派生类derived class（因为派生类中包含基类的所有成员）。

* 静态绑定static bind：在编译的时候，编译器就知道需要调取的函数，比如重载overload等。

* 动态绑定dynamic bind：在多态的情况下，传入抽象类参数调用函数，编译器在编译时无法知道传入的具体派生类的类型和其所掉函数，只能在执行时实时决定。

  virtural returntype func (paralist) [=0];声明函数为动态绑定，默认为静态绑定, =0 时为纯虚函数。纯虚函数不能用于产生实例，只能用作派生类的子对象，并且其派生类必须提供纯虚函数的实现。派生类中实现基类的虚函数时，定义样式必须完全对应，否则不会被视为override（但关键字virtual不是一定要加的）。（但当基函数定义的虚函数返回某个类的类型时，子类中的实现可以返回其子类）。

* 接口类：类中不含具体数据成员，只定义和声明函数成员。

* 另一类抽象类：抽象类中包含具体的data member等，但是构造函数被声明为protected，故不能显示定义此类类型，只能当作抽象基类使用。

* copy constructor vs copy assignment operator：

  在子类调用copy constructor的时候，也会默认调用基类的。

  在子类调用opertor=是，需要显示的调用基类的:

  ```c++
  class fibonacci:public num_sequece{
      //...
      fibonacci& operator=(fibonacci &rhs){
          if(this!=&rhs){
              num_sequence::operator=(rhs);
          }
          //...
          _data = rhs._data;
          return *this;
      }
      //...
  }
  ```

* 如果在基类的constructor/deconstructor中调用了虚函数，那么当执行的时候，基类的constructor中只会调用自己声明的虚函数，而非派生类中的。

  但若在其他函数中调用本类中的虚函数，则会被重载为派生类的，除非调用时显式声明base::func。

**NOTE**：在使用抽象类做传入参数时，如果想实现多态，一定要加上&来将入参变为引用， 或者使用指针，并搭配virtual使用，若不加&，则编译器会将传入参数按照入参类型进行备份，并将备份传入，不会有多态发生。

按照约定，如果类中含有虚函数，其声明destructor是必要的，并且要声明为virtural（但不要声明为纯虚函数），即使destructor中什么都不做。这是由于当delete instance时，会默认调用当前类型的destructor，如果是按照派生类的思想， 它会调用派生类的destructor而不是我们想的类的实例的destructor（如果不加virtual）。

static function member不能声明为virtual

基类一般可定义为两种：一种为纯虚类，制作接口用，其中指明需要定义的函数。另一种是包含所有子类共有属性（function，data）的基类。




## 其他

* 引用(&): 数组不能被直接引用,但是指针可以:

  ```c
  int a[10];
  int *p = a;
  int* &c = a; //错误
  int* &c = p; // 正确
  ```

* 数组元素不能是引用

* exit(int) 终止当前进程,返回int给父进程或操作系统. return 返回上一个函数.

* string 是一个指针类型,总是4byte或者8byte,其指向的字符串常量保存在程序内存的文字常量区

* 内存分为栈,堆,全局区(静态区),文字常量区,代码区.

* 编译器的maximal munch规则：每个符号序列在读入时都按照最长的处理:

  ```c++
  vector<vector<int>> a; //编译不过，引文编译器会读入'>>'.
  vector<vector<int> > a; //正确
  ```
  
* ```c++
  #include <typeinfo>
  type_info a= typeid(class_name); //返回type_info类型。为每个类都标明唯一id。
  a.name(); //返回 const char*
  ```

* static_cast\<type>(instance): 编译时进行检查，可转换指针及其他类型，，没有运行时检查，不能用于非多态转化。可用于基类和派生类的转换，上行是安全的，下行是不安全的。

  dynamic_cast\<type>(instance): 会进行检查，如果不能将instance转换为type，返回0。
  
  C cast: 主要用于基础数据类型的强制转换。