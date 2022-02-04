# PYTHON

## 字符串编码

unicode：2字节

utf-8：英文1字节，中文3字节，其他

ascii：1字节

python默认的字符串是unicode编码，转化为其他编码时使用abc.encode('utf-8') -> b'xxx'，转换为对应编码的二进制储存。从其他编码转化成unicode，b'xxx'.decode('utf-8') : b'xxx'-> 'abc'.

格式化输出：'xxx %s %d %f %xxxxx' % ('asd',1,2.0,0x1)

 

## BASIC ##

1. 定义函数如果带有初始化参数，参数的初始值不要设置为可变值，如[],{} list, dict 等。

2. 函数入参顺序：必选参数，默认参数，可变参数，命名关键字参数，关键字参数。

   ```python
   def my_f(a,b,c=1,*args,d=1,e,f，**argg) # 如果没有*args但需要命名参数，则将*args替换为*即可。list tuple dict传入my_f的args和argg时，在前面加入*和**即可，不用展开，会传入一个复制体。
   ```

3. ```python
   isinstance(a,C) # 判断a是不是C的类型或C的子类的类型
   type(a)==C # 判断a是不是C的类型，不会考虑子类
   from collections import Iterable
   isinstance(a,Iterable) # 判断a是不是可迭代
   ```

4. ```python
   #列表生成式
   [f(k,v) for k,v in range for...if...] # 返回list，成员为f(k,v)的值，k v 为符合条件的值，f中若有if则也必须有else，因为任何情况下必须返回值。后面的筛选条件中，不能有else，因为是筛选条件
   x=[1,2,3,4,5]
   y=[10,11,12,13,14]
   [int(k)+v for k in x for v in y if x!=1 and y!=10]
   将[]改为()则会变为生成器
   ```
```
   
5. 合并list l1+l2

6. 生成器，运行时没到达yield，返回值，return后再调用会抛出StopIteration异常。也可用next()调用。在使用next调用时，需要先生成实例，如f=ite(), next(f)...但for x in ite()不需要。

   生成器也可进行迭代，如x时生成器 x=x/2，x=x/3，或使用filter进行迭代，x=filter(f,x)，返回的生成器会将最初生成器的值继续计算，经过filter，直到最后可以返回一个可用值，记录该时刻原生成器的下一个值，等待下次计算。

7. iterator和iterable区别：

   Iterator全是Iterable的，可以使用next和for等

   Iterable不全是Iterator，如dict，list等，不能使用next但可以使用for，可以使用iter([..])将其变为iterator。

   Iterator是一个数据流，只有在next调用时才会计算返回下一个数据，且不知道数据长度。

8. map & reduce

   map(f, iterable)，f须有一个参数，map将返回一个将f作用域iterable的每一个参数的生成器。

   reduce(f, iterable),f须有两个参数，reduce首先作用域前两个元素，然后作用于其返回值和下一个元素。

9. filter(f, iterable):f需要接受一个参数，返回bool型，返回使f(iterable)==true的生成器。

10. sorted(iterable, key=f,reverse)

11. 闭包：在返回函数的函数中，子函数会引用上一级函数的入参和局部变量，这种现象称为闭包。闭包是介于全局变量和局部变量之间的一种作用域。

    global：当函数内要修改全局变量时，需要先对其声明。

    nonlocal：当函数内要修改闭包变量时，需要对其声明，会追溯到最近的定义位置。

12. 装饰器:装饰器是一个特殊的函数，他的入参为函数，返回一个函数。当使用它修饰函数时，该函数会被替换为以该函数为入参装饰器的返回函数。

  import functools
    def dec(func):
        @functools.wraps(func)
        def wrapper
        （*args, **kw){
            
        }
```

13. hasattr(instance/class, ' attr'):判断instance/class中是否有attr属性，返回bool。

14. super()函数:super函数并非调用父类，而是调用\__mro__中的下一个，当mro中下一个也调用super()时，会按照之前的mro继续进行，而不会调用当前类的mro。

    ```python
    class A:
    	def __init__(self):
    		print('A')
    
    class B(A):
    	def __init__(self):
    		print('B')
    		super().__init__()
    
    class C(A):
    	def __init__(self):
    		print('C')
    
    class D(B,C):
    	def __init__(self):
    		print('D')
    		super().__init__()
    
    d=D()
    
    # D B C A 并非 DBAC
    ```

    15. python是基于协议进行编程的，如上下文协议，向后绑定协议等。

    ## Type class object

python中，万物皆对象，包括class和function，又class生成object时，系统自动调用type，type以class为模板，生成instance。

type(instance)返回class名称，type（class）返回type，可见object是所有class的基类，而所有class是type的实例化，所有instance是class的实例化。而type的基类又是object，object的基类是空

![image-20200812115527995](.\type_class_obj.png)

## 魔法函数

魔法函数是指python 为每个class已经添加好的方法:\__xx\__，如\_\_init\_\_, \__getitem__等。类似于C/C++中的重载特殊运算符。

```python
class T():
    def __init__(self, *s1)
    	self._data = s1
    def __getitem__(self, item) # __getitem__ 允许T成为迭代式，t = T([1,2]), t[1]会调用此函数
    	return self._data[item]
    def __str__（self): # print(t) 或 str(t) 时会调用此方法
        return str(self._data)
   	def __repr__(self): # 会输出
     	...
    #__add__ ...
    #__iter__ ... 使T变为生成器
        
```

note：repr vs str ：repr比str多返回参数的数据类型信息，更适合开发者调用。

## 类

```python
class X(Y):
    p1=0
    def __init__(self):
        self.p2=0
    @staticmethod
	def static_f1():
        p1 +=1
        print(p1)
	@classmethod
    def class_f2(cls):
        p1+=1
        print(p1)
    def f3(self):
        p1+=1
        print(p1)
# @staticmethod: 是类的静态方法，方法中只能使用类变量，不能使用实例变量，没有默认参数,不能调用isntance属性，但是可以通过显示调用class属性，如X.p1.static方法主要用到不需要传入类获实例信息的情况。
# @classmethod:第一个参数是class本身，可以调用class本身的属性，cls.p1
#  instance可以调用f1--f3，class只能调用 f1--f2
```

在调用实例或类属性时，解释器的查找顺序为instance>class>type，也就是如果instance和cls、type中有重名的属性，解释器优先选取的顺序。但是不能使用下一级来动态的修改上一级的内容，就如函数内部无法修改全局变量，试图修改时会创建一个临时局部变量将之覆盖一样（不考虑global）。每一级的属性只有加上自己这一级的名字.属性来修改。

当多继承时，会通过\__mro__中记录的顺序来查找，是通过C3算法给出的（类似广度优先WFS和深度优先DFS的结合）。

## 接口

接口是一种特殊类，其中只定义函数型，不能实例化，只能继承，继承它的类需要实现其中所有的函数。

```python
# method1: use NotImplementedError, then when running and calling these function, exception will be raised if they are not overrided
class A():
	def f1(self):
		raise NotImplementedError

	def f2(self):
		raise NotImplementedError

class B(A):
	pass

#method2: use abc module, error will raise when the instance is initiated
import abc
class A(metaclass=abc.ABCMeta):
	@abc.abstractmethod
	def f1(self):
		pass

	@abc.abstractmethod
	def f2(self):
		pass

class B(A):
	pass

b = B()
```



## 自省

通过一定机制查询对象的内部结构。

```python
class X():
    pass

x=X()
X.__dict__ # 属性__dict__中，以dict的形式记载着该对象作为实例时的属性，不包括被继承的属性。如X.__dict__，会显示class级的所有属性，但不会显示从type和其继承的属性，x.__dict__只会显示self绑定的属性。
X.__dict__[m]='aa' # 为X增加属性

dir(x) # 打印x的所有属性，包括继承的，和class的，但却没有type的
```

## mixin模式

在多重继承中，由于super()的变现难以预料，特别规定了mixin设计模式，即一种类的设计规则，有助于代码复用、合理组织代码：

1. Mixin的类功能单一
2. 不与基类关联，可与任意积累自由组合。
3. Mixin结构中不使用super（）

## 上线文管理

```python
for ...:/while ...:
    pass
else:
    pass
# 如果正常退出for/while是，会运行else，如果遇到break，则不会
try:
    pass
except Exception as e:
    pass
else:
    pass
finally:
    pass
# 当try中抛出相应的Exception时会进入except，但如果抛出的exception不在Exception之中，则会进入else。没有exception，也会进入else。finally则在最后无论如何都会进入。
# 有种特殊情况时当finally之上的块中包含return，当执行到return时，会直接将结果压入栈中，然后跳转到finally，如果finally也包含return，则会将finally总的结果也压入栈中，返回函数栈顶元素（finally的元素）。

class Sample():
	def __enter__(self):
		print('in')
        return self

	def __exit__(self, exc_type, exc_val, exc_tb):
		print('out')

	def do(self):
		print('do')

with Sample() as s:
	print(1)
    
# 在程序进入with时，with xxx as f：会调用xxx的__enter__()，并将返回指存入f中,当程序离开with时，会调用xxx的__exit__()

import contextlib

@contextlib.contextmanager
def f_open(n):
	print("open n") # B1
	yield('a')
	print('close n') # B2

with f_open('aaa') as f:
	print(f)
    
# 使用contextlib中的装饰器，定义一个生成器，在with开始时，会调用此生成器，执行yield前的部分，并将返回值存入f（也可以不加as，如果不接受返回值），with结束后执行B2，释放资源
```

## 自定义序列类

在collection.abc模块中，第一了一系列的接口，选取接口继承并实现接口函数，实现接口后，会支持该类使用接口中定义的其他非虚函数，会使类变为序列类。

```python
import collections.abc

def call(func):
	def wrapper(*args, **aw):
		print(func.__name__)
		return func(*args,**aw)
	return wrapper

class A(collections.abc.Sequence):
	@call
	def __init__(self, name, data):  # 实现Sequnce及其基类的抽象方法
		self._name = name
		self._data = data

	@call
	def __getitem__(self, item):  # 使A可以被A[item]样式访问
		cls = type(self)
		if isinstance(item, int):
			return cls(self._name, [self._data[item]])
		elif isinstance(item, slice):
			return cls(self._name, self._data[item])
		else:
			raise TypeError

	@call
	def __setitem__(self, item, value):  # A[item] = value
		self._data[item] = value

	@call
	def __contains__(self, value):  # x in A
		return value in self._data

	@call
	def __iter__(self):  # iter(A)
		return iter(self._data)

	@call
	def __str__(self):
		return str(self._data)

	@call
	def __len__(self):
		return len(self._data)
    
    @call
    def __reverse__(self):
        return self._data.reverse()


a = [1,2]
b = [3,4]
c= a+b # c为[1,2,3,4], 但id变了，且+两边的类型必须相同，不能传入tuple
a+=b	# b需要为iterable，但不一定一致，会将b中所有元素append到a中，但不会改变a中地址。实际上调用了__iadd__方法。
a.extend(b) #与+=完全一致，+=（__iadd__)的实现就是调用extend

# 切片
a= [1,2,3,4,5]
a[1] # 2 , 当传入整数时，__getitem__(self,item), item类型为int
a[1:3] # [2,3]， 当传入切片时，item类型为slice，有些情况下两种需要区分开来。因为切片传入时，返回数组，整数传入时返回元素，返回类型不同。
```

使用bisect来维护已排序数列

```python
import bisect
a=[1,2,3,4,5]
bisect.bisect(a,3) # 3
bisect.bisect_right(a,3) # 3
bisect.bisect_left(a,3) # 2
# 当要插入的值和a中已有的值相同时，bisect_right返回新值在旧值后的位置，bisect_left返回新值在旧值前
```

使用array

```python
import array

a = array.array("i") # 定义一个元素类型为int的可变长array，‘i’ 格式可以通过文档来查询，array只能放入已定的类型。
a.append(1)
a.append('a') #报错
```

列表生成

```python
x = [i for i in range(5)] # 生成list
print(x)
x = (i for i in range(5)) # 生成y
a = {'a':1, 'b':2, 'c':3, 'd':1}
y = {j:i for i,j in a.items()}  # 生成dict
print(y)

z = {j for i,j in a.items()} # 生成set
print(z)
```

## 数据结构

list: 链表

array：可变序列

dict/set：散列

## 变量

python的变量相当于指针，再给变量赋值时，如果目标对象不存在，则先生成对象，再将变量指向对象，如果存在，则直接指向。变量是没有类型的，但是对象有。如a=1，b=1，a is b 返回true，而在静态语言中没变量是有类型，也就是有地址的和空间的。

在函数传递变量时，传递的是变量，而不是对象。就像c++中，传递的是变量而不是引用。变量的赋值是将变量指向其他对象，而不是修改指向的对象。

a is b，会判断id(a)和id(b)是否相同。

a == b 会调用a的\__eq__()

注意：

C++的变量有自己的类型和空间，自己的地址和类型是不变的，python的变量没有实际地址和类型。

## 垃圾回收

python的垃圾回收采用引用计数器方法，当对象付给变量时，对象的计数器++，当引用的变量被删除（del）或引用其他对象后，计数器--。

注意：

1. del a 并不会删除a指向的对象，但会让该对象的计数器-1，并删除a。当某对象被解释器删除时，会调用该对象\__del__()
2. 在声明函数的默认函数时，如 f(a, b=[]): b=[] 或是其他可变对象，时要避免的，否则当b传入默认值时，默认值会随着b在函数中的操作而改变，再次调用时，默认值已变成上一次修改之后的默认值了。

## 元类编程

```python
# property
class X():
    def __init__(self, birth):
        self._birthday = birth
        self._age = 0
    
    @property
    def age(self):
        return datetime.now().year - self._birthday
   
	@age.setter
    def age(self, value):
        self.age = value
        
x = X()
x.age  # 调用age() property会将age函数转变为属性调用方式.
x.age = 1 # 调用setter

# __getattribute__, __getattr__  当访问类中没有的属性时，解释器会调用类的__getattr__

x.birth # 调用__getattribute__, 如果查找到则返回,否则在调用__getattr__,默认报错.

# 属性描述符
class IntField():
	# 实现 __get__, __set__, __del__ 任一的类叫做属性描述符, 属性描述符会在复制和调用时进行额外的自定义操作。
	@call
	def __get__(self, instance, owner):	# 属性描述符类型在赋值,调用时会调用set和get, instance指类的类,如a.x=1, x是intfiled,x是self,a是instance
		return self.age

	@call
	def __set__(self, instance, value):
		if isinstance(value, int):
			self.age = value
		else:
			raise ValueError('int value needed')
	def __delete__(self, instance):
		pass

class X():

	_age = IntField()  # 在class中将一个名字声明为属性描述符,在instance中定义相同的名字的变量,则会转变成属性描述符类型.

	def __init__(self):
		self._age = 0

	@property
	@call
	def age(self):
		return self._age

	@age.setter
	@call
	def age(self, value):
		self._age = value

x = X()
x.age = 12
print(x.age)
x._age = 12
print(x._age)

```

\__new\_\_ 和\_\_init__ 的区别,new是在类的实例创建之前被调用的,需要return一个实例给init的self,然后才会调用init

动态创建类:

```python
def create_cls():
    class A:
        pass
    return A

X = create_cls()
x = x()

# 使用type 创建类
class ba:
    pass
def say(self):
    print('Im ' + self.name)
    
X = type('Usr',(ba,), {'name':'name','say':say}) #x= type('class_name', (parents,), {attr:value})
x= X()
x.say()
```

元类: 创建类的类,如type, 在main之前,解释器会创建class,创建class时,会寻找该class的metaclass来创建class,如果某class自身没有metaclass,但其基类有metaclass,则会去查找基类的metaclass来常见当前class,再找不到时,才会使用type.

例子:abc模块中的abstractclass的metaclass,可以在子类创建时,检查子类有没有实现基类(抽象类)的所有虚函数.

```python
class MetaCls(type):
	@call
	def __new__(cls, *args, **kwargs): # 这个new就相当于mycls的__new__, args前三个参数为类名,父类,属性,可对后两者进行修改.
		return super().__new__(cls, *args, *kwargs)
    
    # 可以自定义生成类的方法，多数为修改其attrs来为要生成的类创建规范。attrs中包含了已定义的class中的所有属性，可向其中添加/删除/修改属性，这样在创建实例之前，会调用__new__来修改class属性，然后再创建实例，进入init。当调用类本身时，也会先调用metaclass来创建class模板。
    def __new__(cls, name, base, attrs, *args, *kwargs):
        attrs[xxx] ...
        return super().__new__(cls, name, base, attrs, *args, *kwargs)

class mycls(metaclass=MetaCls):
	def __init__(self,name):
		print(name)

m = mycls()
```

元类编程多用于写框架 

## 迭代协议

```python
实现了__iter__(或继承collections.abc.Iterable)的类为可迭代对象,__iter__需要返回iterator,iter(a)会调用a.__iter__(),当出现for x in a时,会首先调用a.__iter__,然后对返回的迭代器进行迭代（调用__next__),若a没有实现iter,则会创建从0开始的迭代器,并调用__getitem__(self,item)来进行循环.

实现了__next__(或继承collections.abc.Iterator)的类为迭代器Iterator

在iter返回iterator时,构造iterator的方法不要在本类内部实现,而是新建一个类,将本类中需要跌打的属性传入,将该类设计为iterator,返回该类的实例.


生成器：包含yield的函数，调用函数会返回一个可迭代对象，对其进行迭代。

for循环调用iterable时会在接收到stop iteration异常时结束

```

## 多线程

### GIL

GIL锁：cpython环境下的特殊产物，由于cpython下不是线程安全的所以需要GIL锁（global interrupt lock），但是GIL锁对于多线程有很大限制，不支持多核CPU上的多线程操作，即，每一个进程都有一个GIL锁，线程要执行必须获得gil锁，所以多核的情况乱改下，只能有一个线程和其核心初一激活状态，其他核心处于竞争状态（GIL会经过一定的代码行数（汇编行）后进行释放和争夺）。所以多核心时只能使用多进程，mutiprocessing。



### 守护线程

多线程编程时，主线程一定要等待子线程结束自己才能结束，也可用join来显示等待。但是将线程设置成分离线程（detach），主进程不会管分离线程是否结束。

守护线程是指为其它线程服务的线程，一般分离线程是为了创建守护线程。可以从主线程开始到停止。守护线程不允许任何需要被关闭的资源，因为不知何时退出。通过setDaemon（True）或detach来实现。

```python
import threading

def th():
    print('this is thread 1')

print('start')

t = threading.Thread(target=th)
t.setDaemon(True)
t.start()
# t.join()
print('end')
```

### 线程类

```python
import threading

class my_thread(threading.Thread):
    def __init__(self, name):
        super().__init__(name=name)

    def run(self):		# 重载run方法
        print(self.name, ' start')

m = my_thread('x')
m.start()	# 线程启动，调用run方法， 注意：不要重载start方法
```

### 线程间通信

1. 共享变量：通过全局变量来通信，但是在操作全局变量时要加锁。
2. QUEUE: queue是线程安全的，事实上，python的queue只是将共享变量和锁封装到一起的一个共享变量通信的实践。

线程安全的意思是：在进程和线程交替执行时，结果始终一直，不需要额外的同步机制。

```python
import queue
import time
import threading

def pu(q):
    len = 1024
    for i in range(len):
        q.put(i)	# 向queue中添加，如果queue满了，阻塞
        time.sleep(0.2)

def ge(q):
    len = 1024
    for i in range(len):
        print(q.get())	# 从queue中读取，queue为空时，阻塞
        time.sleep(1)


if __name__ == '__main__':
    que = queue.Queue(maxsize=1000)	# 声明queue的最大size，先进先出
    t1 = threading.Thread(target=pu, args=(que,))
    t2 = threading.Thread(target=ge, args=(que,))
    t2.start()
    time.sleep(2)
    t1.start()
    
    
que.task_done() 
que.join()  # 遇到join时会阻塞进程，知道某个线程调用task_done
```

### 线程同步

1. mutex: 锁，只有在acquire之后才能继续进程，否则阻塞进程直到对应锁release。

```python
import threading
import time
i=0
l=threading.Lock()
def inc():
    global i, l
    for k in range(10000):
        l.acquire()
        i+=1
        l.release()

def dec():
    global i, l
    for k in range(10000):
        l.acquire()
        i-=1
        l.release()

t1 = threading.Thread(target=inc)
t2 = threading.Thread(target=dec)

t1.start()
t2.start()
t1.join()
t2.join()
print(i)

'''threading.Rlock: 可重入锁
可重入锁可在一个线程内多次acquire和release，但是数量要一致。
情景：某个需要所的函数又调用了另一个需要所的函数，若使用Lock，则造成死锁，Rlock不会，但只会在同一个线程中可以。
'''
```

死锁：互相等待，两个进程，每个都在等另一个持有的锁释放以继续。

2. 条件变量：condition。

```python
# 条件锁在需要先获取锁（with condition或者 lock.acquire）开始，在获得锁，以后，调用wait会使当前condition向等待队列中创建一把新锁，并释放condition外层的锁，并再次尝试获取该新锁，即进入阻塞状态，在等待池的锁释放后，开始竞争外层锁。在condition调用notify时，会从等待队列中释放一把锁，这样对应的上层所解开，对应的线程得以继续参加竞争底层锁。此时调用wait释放底层锁。

import threading

con = threading.Condition()

class T1(threading.Thread):
    def __init__(self, name, con):
        super().__init__()
        self._name = name
        self._con = con
        self.t = 0

    def run(self):
        con = self._con
        with con:
            print('t1 start')
            while self.t<100:
                print('t1:', self.t)
                self.t+=2
                con.notify()
                con.wait()
            try:
                con.notify()
            except Exception as e:
                pass
            print('t1 end')
        print('t1 release')


class T2(threading.Thread):
    def __init__(self, name, con):
        super().__init__()
        self._name = name
        self._con = con
        self.t = 1

    def run(self):
        con = self._con
        with con:
            print('t2 start')
            con.wait()
            while self.t<100:
                print('t2:', self.t)
                self.t+=2
                con.notify()
                con.wait()
            try:
                con.notify()
            except Exception as e:
                pass
            print('t2 end')
        print('t2 release')

con = threading.Condition()
t1 = T1('t1', con)
t2 = T2('t2', con)
t2.start()
t1.start()
# 0，1，2，3，4，5 ... 99
```

3. 信号量

   与lock相似，但是规定了最大的并发数，每一次acquire成功，num都会-1，直到为0时，再次acquire会进入阻塞状态。一把对某个资源写只允许一个线程，读可以多个线程。

```python
import threading

sem = threading.Semaphore(num)

sem.acquire()
sem.release()
```

4. 线程池：线程池是一个包，封装了线程方法，是现成的调用更简单

```python
from concurrent import futures
import time

def myt(name):
    time.sleep(name)
    #print("I'm t", name)
    return 't'+str(name)

executor = futures.ThreadPoolExecutor(max_workers=2)
executor = futures.ProcessPoolExecutor(max_workers=2)

tasks = [executor.submit(myt, i) for i in [8,2,5,8,1,4,7,9]] # submit后会返回futures.Future对象

#print('task3 canceled: ', tasks[3].cancel())  # 非阻塞，尝试取消task，成功返回True

print('task1 done: ', tasks[1].done())    # 非阻塞，查询task状态
print('task1 done: ', tasks[2].done())

print('task1 result: ',tasks[1].result())   # 阻塞，获得task返回值。

fut = futures.as_completed(tasks)  # 返回生成器，生成器每次被调用会返回一个完成的task对象，若没有则会阻塞，直到所有线程完成
for f in fut:
    print("I'm ", f.result())

futures.wait(tasks) # 等待所有线程完成
```

## 进程vs线程

多进程用于耗CPU多的情况，多线程用于IO多的情况。线程得切换快于进程切换。

## 进程

```python
import Multiprocessing

proc = multiprocessing.Process(target=kp, args=(1,))
proc.start()
print(proc.pid)
proc.join()
print('end')
```

进程间通信：pipe，共享内存，消息队列（queue），信号

进程同步：锁，条件锁，信号量



concurrent.futrues中，thread可以使用queue.Queue通信，但process不可以，也不可以用Multiprocessing中的库。



## 协程 coroutine

生成器的调用方式：

```python
def get_func():
    url = "123"
    n = yield url
    url = "456"
    print(n)
    n = yield url

gen = get_func()
print(next(gen))  # 调用执行到第一个yield
print(gen.send(1)) # 调用gen，将1传入到变量n中，继续执行，返回下个值。
# 生成器开始执行时，可以用next执行，如果用send执行，只能传递None，否则会报错。
gen.close() # 关闭生成器，如果再次调用会产生stopiteration异常。

x = yield from iterable # 调用iterable并返回一个值（携程也是iterable）
# 若yield from generator，则在生成器return时，值会保存在x中。而每次调用父生成其的send时，会将send的值直接传入子生成器。

# yield 和 yield from的区别：yield返回值，x=yield时，x保存传入值
# yield from是调用另一个生成器，当父生成器继续执行进入子生成器时，调用程序相当于直接调用子生成器。子生成器return时，值保留在x中，父生成器继续使用。且yield from会自动处理StopIteration一场。
```

当生成器调用return时，同时也会抛出异常stopIteration e, e.value 保存返回的值。

此时，一个生成器可以当作一个协程来看待，使用yield from来调用协程。在更高的版本中为了更利于维护，使用async和await来定义携程

```python
async def download_url(url):
    #dosomething
    html = await downloader(url)
    return html

async def downloader(url):
    return "myhttp"

coro = download_url(1)
try:
    coro.send(None)
except StopIteration as e:  # downloader 抛出StopIteration异常给download_url，download_url继续向上抛出。
    print(e.value)
```



## 异步IO asyncio

异步运行

通过loop来调用。一个线程只有唯一一个event_loop, 无论如何创建都获取的使唯一得loop。

协程得操作原理是：从evet_loop处开始执行携程，当遇到await调用时，暂停当前协程，跳入子协程，然后继续执行，当进入异步IO调用时，协程陷入等待异步IO返回。而执行权限直接交给loop，loop会查看其他携程是否从IO处返回或者调用新的协程。

```python
import asyncio
from aiohttp import web
async def download_url(url):
    print('doing pre-processing')
    resp = await downloader(url)  # 模拟异步io，实际上应该调用异步io函数，在asyncio库或者aiohttp中
    print('doing end-processing')
    return resp

async def downloader(url):  # 模拟异步io程序
    await asyncio.sleep(url) #
    return "sleep"+str(url)

if __name__ == "__main__":
    loop = asyncio.get_event_loop()
    # loop.run_until_complete(download_url(3)) # 执行一个协程，一般没什么意义，除非这个协程中调用了协程组比如 await asyncio.gather(*tasks)。事实上run_until_complete也是在调用协程。gather和wait都是要等待所有协程结束。

    # tasks = [asyncio.ensure_future(download_url(i)) for i in range(1,10)]
    tasks = [loop.create_task(download_url(i)) for i in range(1,10)] # emsure_future 返回future类型得协程, loop.create_task返回task类型携程，task是future子类
    start_time = time.perf_counter()
    try:
        loop.run_until_complete(asyncio.gather(*tasks))
    finally:
        loop.close()

    end_time = time.perf_counter()
    print("process take %d" % (end_time-start_time))
    for task in tasks:
        print(task.result())


import asyncio
from aiohttp import web
import time

async def download_url(url):
    print('doing pre-processing')
    resp = await downloader(url)  # 模拟异步io，实际上应该调用异步io函数，在asyncio库或者aiohttp中
    print('doing end-processing')
    return resp

async def downloader(url):  # 模拟异步io程序
    await asyncio.sleep(url) #
    return "sleep"+str(url)


def call_back1(task):
    print("I'm 1 done with: ", task.result())

def call_back2(task):
    print("I'm 2 done with: ", task.result())

if __name__ == "__main__":
    loop = asyncio.get_event_loop()
    # loop.run_until_complete(download_url(3)) # 执行一个协程，一般没什么意义，除非这个协程中调用了协程组比如函数中有await asyncio.gather(*tasks)。事实上run_until_complete也是在调用协程。gather和wait都是要等待所有协程结束。

    # tasks = [asyncio.ensure_future(download_url(i)) for i in range(1,10)]
    tasks1 = [loop.create_task(download_url(i)) for i in range(1, 11)]
    tasks2 = [loop.create_task(download_url(i)) for i in range(11, 20)]  # ensure_future 返回future类型得协程, loop.create_task返回task类型携程，task是future子类
    for task in tasks1: # 向task中添加回调函数，当task结束时调用。
        task.add_done_callback(call_back1)

    for task in tasks2:
        task.add_done_callback(call_back2)

    start_time = time.perf_counter()
    try:
        # gather和wait都表示等待所有调用得task结束时返回
        loop.run_until_complete(asyncio.gather(*tasks1, *tasks2)) # gather接受的是*args，可以接受多组tasks，更加灵活一些
        # loop.run_until_complete(asyncio.wait(tasks1)) 
    finally:
        loop.close()

    end_time = time.perf_counter()
    print("process take %d" % (end_time-start_time))
    # for task in tasks:
    #     print(task.result())
```

### 协程同步

当两个协程都要访问一个变量得时候，且在其中都有asyncio，需要等待，而我们只希望执行其中一个函数。此时我们需要同步机制，当一个协程在运行时，阻止另一个运行。

```python
from asyncio import Lock

lock = Lock()

async def a1(i):
    await lock.acquire()
    #do something
    await asyncio.sleep(i)
    await lock.release()

async def a2(i):
    with await lock:
        # do something
        await asyncio.sleep(i)
```

