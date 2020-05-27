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

* 数据类型决定了变量的值在内存中存储和读取的方式，如占多少byte。以及在程序编写和运行中可以使用的function

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

* 字符串 string：

  * 选取char和切片

    ```python
    s = 'abcdefgh'
    s[0], s[1:4], s[2:-1], s[:2], s[2:]
    s[2:-1:2] 第三位为取值步长，默认是1
    s[-1:1:-1] 反向切片，步长必须为负值
    ```

    **Note：**在所有类的切片操作中，都是左闭右开的形式，要去到最左或最右的元素，可以将该位置省略。

  * string.upper(), string.lower(), string.strip() 若不输入任何参数，则去除两端的**空白字符**（包括换行等），若有输入，怎去除两端的所有在输入之内的字符。string.split(a) 使用a对字符串进行分割，返回list，若最左或最右是分隔符，则出现''。string.join(string/list)：将输入的list中每个元素以string连接起来。string.count(a),计算a在string中出现的次数。string.replace(old, new, max)：若不写max则全部替换。

  * 字符串也是list。

### 容器

#### list

* 创建：l1=[xx,xxc], l1 = list(l2) 将l2转化为list并赋给l1.
* 插入：l1.insert(i,x), l1.append(x), l1.extend(x) x需要为list，将x展开append到l1后。
* 删除：list.pop(i)：删除第i元素，并返回值，默认删除最后一个。del list(:::):删除第i个元素,可以按切片删除。list.remove(x)：删除值为x的元素,只移除第一个.
* 修改: list[i:j:] = x, x必须为list, 步长为1时x长度无限制,会将当前切片整体替换为x,不为1时,x长度要和切片配合.使用list[i:i] = x,可以在i位置插入x (list),  使用list[i:j] = [],可以删除i到j.
* reverse,sort,sorted,切片.

#### turple

* 元组无法修改,只能查看,但是元组中的list的元素是可以修改的, 是因为每个list其实是一个指针,指针在元组中时,可以修改指针指向的内容,但不可修改指针.
* 一般元组多用于返回值时多个要进行拆包时,不用list.


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

* continue：终端当前循环，进入下一判断+循环

* for：

  ```python
  for a in set:
      xxxx
  ```

  

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

### 运算符

* 算术运算符：+, -, *, /, **, %, // （除后取整数部分）
* 比较运算符：==, !=, >, >=, <, <=。
* 赋值运算符：=, +=, -=, *=, /=, %=, //=, **=。
* 按位运算符：&, |, ^ (异或，相同为0，不同为1), ~, <<, >>。
* 逻辑运算符：and, or , not，逻辑运算只适用于bool量，结果只是表示true false，具体值没有意义。
* 运算优先级：

| 运算符                   | 描述                                                   |
| :----------------------- | :----------------------------------------------------- |
| **                       | 指数 (最高优先级)                                      |
| ~ + -                    | 按位翻转, 一元加号和减号 (最后两个的方法名为 +@ 和 -@) |
| * / % //                 | 乘，除，取模和取整除                                   |
| + -                      | 加法减法                                               |
| >> <<                    | 右移，左移运算符                                       |
| &                        | 位 'AND'                                               |
| ^ \|                     | 位运算符                                               |
| <= < > >=                | 比较运算符                                             |
| <> == !=                 | 等于运算符                                             |
| = %= /= //= -= += *= **= | 赋值运算符                                             |
| is is not                | 身份运算符                                             |
| in not in                | 成员运算符                                             |
| not and or               | 逻辑运算符                                             |

## Pycharm常用快捷键

* ctrl+左键：跳到定义
* ctrl+d：复制当前行
* ctrl+？：注释选中部分

# #常用函数

len()：返回string和list的长度。

range(): 产生数字迭代器.