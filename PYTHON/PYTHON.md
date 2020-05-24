# PYTHON 编程

[TOC]

## 一. 前言

### 编程语言分类
* 编译性：

  将程序全部编译并执行，运行速度快，但开发速度慢。如C、JAVA。

* 解释型：

  逐行编译执行，运行速度慢，但开发快。如PYTHON。

### Python解释器种类

* CPython:

  将python转化为C识别的字节码

* JPython:
  将python转化为Java能识别的字节码

* IPython：

  交互式解释器

> 使用不同的解释器，可以让python和其他语言交互使用

* Pypy:

  将Python一次性编译，转化为编译性语言，执行效率高。

### Python2 和 Python3 区别
参照[Python2 and Python3](https://www.runoob.com/python/python-2x-3x.html)

## 二.Python基础
### Python变量、常量和关键字

#### 变量

变量声明格式：只能用字母，_, 数字组成，但不能使用已有关键字。

* 驼峰体：AgeOfBoy

* 下划线：age_of_Boy (推荐)

  **Note:** 变量只指向数据，和指针不同。

#### 常量
Python中没有const关键字，但约定将全部大写的名字定为常量。
NAME = 18

#### 关键字


``` python
['and', 'as', 'assert', 'break', 'class', 'continue', 'def', 'del', 'elif', 'else', 'except', 'exec', 'finally', 'for', 'from', 'global', 'if', 'import', 'in', 'is', 'lambda', 'not', 'or', 'pass', 'print', 'raise', 'return', 'try', 'while', 'with', 'yield']
```

### 注释

单行注释：#

多行注释：'''xxxxx''', """xxxxx""" 内容可换行

解释器会读取注释，但不会运行

### 数据类型

数据类型决定了变量的值在内存中存储和读取的方式，如占多少byte。以及在程序编写和运行中可以使用的function

int，str，bool，float

32位：int占32bit，-2^31^ -- 2^31^-1

64位：int占64bit

**Note：** 

* 负数：若数据类型中可能出现负数，在读取时，若第一个bit位1，则取补码（反码+1）。如储存一个负数，则储存绝对值的补码。

* 字符串赋值："  ",' '用于单行赋值，'''   ''' 用于多行复制，如：

  ```python
  a = '''shjsh
  sajhdsjh
  kshdjh'''
  ```

  str + str 为字符串的拼接；str*int：将str重复int次。

* 使用type(变量)或isinstance(变量)输出变量类型。type不判断继承，及子类不是父类。isinstance判断继承，子类是父类。

* 1byte=8bit

### 流程控制语句

* if 

  ```python
  if a:
      xxx
  elif b:
      xxx
  elif c:
      xxx
  else:
      xxx
  ```

* while

  ```python
  while condition:
      statement1
  # optional
  else:
      statement2
  ```

  如果while中，statement1有break语句，且执行break，则不会执行else，否则会在循环结束时执行else。

* break：中断并跳出当前循环

* continue：终端当前循环，进入下一循环

### 格式化输出

```python
name = 'Ye Ziduo'
age = '30'
job = 'SW Engieeer'
hobbie = 'BAD'
msg = '''------ infor of %s ------
Name   : %s
Age    : %s
Job    : %s
Hobbie : %s
----- end -----''' % (name, name, age, job, hobbie)
print(msg)
```

基本占位符：%d，%s，%f，%-10.2s：左对齐，占位10，取%s前两位，字符串。也可用strxxx.format()来对生成模板。

**Note:**‘%’ 转义为‘%%’。

参照https://www.cnblogs.com/fat39/p/7159881.html。

### 文字编码

编码是指二进制数组和人类语言的对应。每个字母、汉字、字符需要对应不同的bin串，且需要规定翻译方式使这些bin串连续使用时不互相混淆。

#### ASCII
最早的编码表，规定了引文字符和特殊符号和bin串的关系，只需要2^8^ （1 byte）个串。实际上只需要128个字符，但是考虑到可能有拓展的可能，填充到了256个，所以ASCII中第一位bit都是0。

#### GBK

中国国家标准编码，包含英文字母、数字、特殊字符和汉字。

1个英文：1 byte（和ASCII一致）

1个汉字：2字节

#### Unicode

国际标准，开始时，只有2字节，后来为了包含所有国家的语言，扩展到4字节。2^32^。实际用到了不到2^21^。浪费很多空间，所以升级到了utf-8

#### UTF-8

至少用1byte表示一个字符。

英文、数字：1byte

欧洲：2byte

亚洲：3byte

例如：‘中过12ha’：UTF-8，10byte。GBK：8byte。

**Note:** 

* 1byte = 8bit

* 1TB = 1024GB

  1GB = 1024MB

  1MB = 1024KB

  1KB = 1024B

  1B = 8bit

  以2^10^来换算。