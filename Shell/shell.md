# Shell

ref: [Bash 简介 - Bash 脚本教程 - 网道](https://wangdoc.com/bash/intro)

## 简介

Shell 有很多种，只要能给用户提供命令行环境的程序，都可以看作是 Shell。

历史上，主要的 Shell 有下面这些。

- Bourne Shell（sh）
- Bourne Again shell（bash）
- C Shell（csh）
- TENEX C Shell（tcsh）
- Korn shell（ksh）
- Z Shell（zsh）
- Friendly Interactive Shell（fish）

Bash 是目前最常用的 Shell。

## 模式展开 globbing

shell接到命令后，会按照空格来将命令拆分为不通词元，然后对词元中的特殊字符进行拓展，然后进行执行。通配符（wildcard express）也是模式展开的一种。

使用shopt命令来调整bash的行为

关闭拓展 set -o noglob

### ~ 扩展

~ 会根据后面的用户名，返回用户的home目录，如果用户不存在，则不起作用

```shell
~root: /root
~jack: /home/jack
```

### 通配符

？： 代表单个字符

\*： 代表任意数量的字符，匹配目录时只匹配当前目录，ls \*.png, ls*/\*.png

\**：bash 4.0，用于匹配任意层子目录

\[...]： 代表中间的任意一个字符，[abc] 匹配abc中的一个，[a-z] 匹配a~z中的一个

[start-end]：匹配start-end中的一个

[^...]、 [!...]：匹配除[] 中的字符的一个，[^abc] [!a-z]

(abc|def)：匹配abc或def

注：以上若是对文件名的匹配，如果目录中没有匹配的文件，将不会展开

{}：中间的元素用","分割，命令作用时，会将{}展开为每个元素以" "分割的样式，然后传入命令。注：内部不能有" "

{star..end},{start..end..step}：{1..10}，for i in {1..19} do ... done

`[[:class:]]`表示一个字符类，扩展成某一类特定字符之中的一个。常用的字符类如下。(与\d \s相似)。取反为[![:class:]]

- `[[:alnum:]]`：匹配任意英文字母与数字
- `[[:alpha:]]`：匹配任意英文字母
- `[[:blank:]]`：空格和 Tab 键。
- `[[:cntrl:]]`：ASCII 码 0-31 的不可打印字符。
- `[[:digit:]]`：匹配任意数字 0-9。
- `[[:graph:]]`：A-Z、a-z、0-9 和标点符号。
- `[[:lower:]]`：匹配任意小写字母 a-z。
- `[[:print:]]`：ASCII 码 32-127 的可打印字符。
- `[[:punct:]]`：标点符号（除了 A-Z、a-z、0-9 的可打印字符）。
- `[[:space:]]`：空格、Tab、LF（10）、VT（11）、FF（12）、CR（13）。
- `[[:upper:]]`：匹配任意大写字母 A-Z。
- `[[:xdigit:]]`：16进制字符（A-F、a-f、0-9）。

匹配数量控制：例：ls abc?(.)txt  :  abc.txt, abctxt

- `?(pattern-list)`：模式匹配零次或一次。
- `*(pattern-list)`：模式匹配零次或多次。
- `+(pattern-list)`：模式匹配一次或多次。
- `@(pattern-list)`：只匹配一次模式。
- `!(pattern-list)`：匹配给定模式以外的任何内容。

### 变量拓展

\${}: \$a,\${a} ,代表a变量

\${!partner}：返匹配partner的所有变量名，echo \${P*}： PATH，PAGE，PWD ...

\${cmd}：返回cmd的返回值

### 算术展开

\$\((...))：echo \$((2+2))

## 基本命令

* type：显示命令来源，type ls

## 快捷键

- `Ctrl + L`：清除屏幕并将当前行移到页面顶部。
- `Ctrl + C`：中止当前正在执行的命令。
- `Shift + PageUp`：向上滚动。
- `Shift + PageDown`：向下滚动。
- `Ctrl + U`：从光标位置删除到行首。
- `Ctrl + K`：从光标位置删除到行尾。
- `Ctrl + W`：删除光标位置前一个单词。
- `Ctrl + D`：关闭 Shell 会话。
- `↑`，`↓`：浏览已执行命令的历史记录。

## 引号和转义

* 换行符：“\”，在特殊字符前加”\“表示将特殊字符转为文本字符。

* ' ' ：表示引用，将'  '中的内容原样打印，不进行拓展：echo '$USER'  ： \$USER

* " "：在" "中的内容，不会进行除 $，`，\ 的其他模式拓展

* here文档：

```shell
# 以 << token开始，以token结束，中间的部分是多行文本，按文本文件处理。
# 内部支持变量，但不支持通配符。here文档不是字符串，是相当于标准输入
cat << _EOF_
ajhjd
sjhfsd
sdh
_EOF_
```

* here字符串

```shell
# <<< string， 将string转化为标准输入
cat <<< 'my text'
a="my text"
cat <<< $a
```

## 变量

* 打印环境变量：env、printenv

* 输出变量：export，使当前shell及子shell都能读取export的变量

### 特殊变量

* \$?：上个命令的退出码，用来判断命令是否成功，0：成功，非0：不成功

* \$$：本shell的pid

* \$_：上个命令的最后一个参数

* \$!：最后一个后台执行的一部命令进程ID

### 变量默认值

* \${varname:-word}：如果varname不存在或为空，则返回word（常量或者变量），否则返回变量值

* \${varname:=word}：如果varname不存在或为空，则将他设为word，并返回值，否则返回变量值

* \${varname:+word}：如果varname存在且不为空，则返回word，否则返回空。常用于测试变量是否存在

* \${varname:?message}：如果varname不存在或为空，则打印message并终端脚本。否则返回值。

### declare

```shell
# declare 声明变量时可以加一些限制
declare option VARIABLE=value
# -a：声明数组变量。
# -f：输出所有函数定义。
# -F：输出所有函数名。
# -i：声明整数变量。
# -l：声明变量为小写字母。
# -p：查看变量信息。
# -r：声明只读变量。
# -u：声明变量为大写字母。
# -x：该变量输出为环境变量。
declare -F
declare -f
```

### let

let声明变量时可以进行算数表达计算

```shell
let foo=1+2
let v1=1+2, v2=2
let "v1 = 1", "v2  =  2" # 带空格时需要加引号
```

## 字符串操作

```shell
${#varname}: 返回字符串长度

# 截取字符串
${varname:offset:length}：提取子字符串，从offset开始，length长，
# 如果要从后向前，则offset改为负数，且前面加空格。
# offset也可为负值，表示要排除子字符串尾部的数量。
${var:1:19}, ${var: -1:20}，${var: -1:-2}，${var: 10:-2}
${varname:offset}：提取子字符串，从offset开始

# 搜索、替换字符串
${var#partner}：会从字符串头开始匹配，如果匹配则删除最短匹配的部分，返回删除后的串，本身不变
${var##partner}：会从字符串头开始匹配，如果匹配则删除最长匹配的部分（贪婪匹配），返回删除后的串，本身不变

${var%partner}：会从字符串末尾开始匹配，如果匹配则删除最短匹配的部分，返回删除后的串，本身不变
${var%%partner}：会从字符串末尾开始匹配，如果匹配则删除最长匹配的部分（贪婪匹配），返回删除后的串，本身不变

${var/partner/rep}：将var中匹配partner的部分替换为rep，贪婪匹配，仅1次
${var//partner/rep}：将var中匹配partner的部分替换为rep，贪婪匹配，所有都替换


${var/#partner/rep}：将var中从字符串头匹配partner的部分替换为rep，贪婪匹配
${var/%partner/rep}：将var中从字符串末尾匹配partner的部分替换为rep，贪婪匹配

# 改变大小写
${var^^} 返回大写
${var,,} 返回小写
```

## 算术操作

```shell
# ((...)) 中做算术运算，要读取运算结果，需要加$, $((...))
# 运算赋值，在算数运算中带入变量时不需要$
a=$((1+2))
((foo=1+2))
x=1
a=$((3+(foo=2+x)))


# 算数运算如果结果为0，则$?不为0，如果结果不为0，则$?为0
# 除法：/  结果取整
# 算数运算：+ - * / ++ -- %取余  **指数
# 位运算：>> << & | ^
# 逻辑运算：> < >= <= == != && || !  expr1?expr2:expr3，真返回1，假返回0
# 赋值运算：= += -= &= ... 只能在((...)) 起作用，外部会按照字符串拼接
$[1+2] # 老语法，不推荐
```

### expr命令

expr 3+2

expr \$foo+2

## 行操作

```shell
!! 执行上一条命令
...
```

## 脚本

```shell
#!/usr/bin/env bash # Shebang行，指定运行次脚本的程序，env node，返回node在env中的第一个路径

env -i /bin/bash 启动一个bash，不带任何环境参数

#脚本参数
$0：当前脚本名字
$1-9：第n个传入的参数
$#：命令中元组数量
$@：所有参数，以空格隔开
$*：所有参数，以$IFS中的第一个分隔符隔开，可自定义

shift：pop出$1，后面的参数向前移动一个，$2变为%1
shift n：pop前n个，后面命令向前平移

参数处理
while getopts 'abc:d:' OPTION; do
  case "$OPTION" in 
    a)
      echo "has -a"
      ;;
    b)
      echo "has -b"
      ;;
    c)
      echo "-c is $OPTARG"
      ;;
    d)
      echo "-d is $OPTARG"
      ;;
    ?)
      echo "wrong option"
      exit 1
      ;;
  esac
done
shift $((OPTIND-1))

getopts "options" var：用于处理传入参数，通常和while一起用。"options"中的每一个字符都是一个选项，后面带有":"的字符，说明此选项带有参数，会储存到$OPTARG中。
每个循环会找到一个以-或--开始的选项并将结果存到$OPTION中，进入case，如果返回的值不在options中，会返回"?"。OPTIND初始值位1，getopts每返回一次+1，最后shift是为了将主参数保存位$1 $2 ...
```

### source

```shell
source xxx：重新加载配置文件xxx
. xxx：source的简写版
```

### alias

```shell
alias name=cmd # 将命令cmd的别名设为name
unalias name # 取消别名
```

### read

```shell
# read [options] var: 默认从stdin读取信息，储存在var中，如果后面没有var，则会储存在环境变量$REPLY中
echo "type in something"
read t1 t2
echo "t1: $t1, t2: $t2"

# read 读取文件信息：
while read myline 
do
echo %myline
done < filepath

参数：
# -t 超时时间
if read -t 3 response;then
  echo $response
elif xxx; then
  echo 1
else
  echo timeout
fi

# -p 设置提示信息
read -p "enter something" response
echo $response

# -a 将参数赋值给数组，从0元素开始
read -a people
echo ${people[2])

# -n 取开始的n个字符作为参数
# ...
```

### IFS变量

\$IFS 中保存这读取参数的分隔符，一般只有第一个起作用

```shell
#!/bin/bash
# read-ifs: read fields from a file

FILE=/etc/passwd

read -p "Enter a username > " user_name
file_info="$(grep "^$user_name:" $FILE)"

if [ -n "$file_info" ]; then
  IFS=":" read user pw uid gid name home shell <<< "$file_info" # IFS改变只在当前行生效
  echo "User = '$user'"
  echo "UID = '$uid'"
  echo "GID = '$gid'"
  echo "Full Name = '$name'"
  echo "Home Dir. = '$home'"
  echo "Shell = '$shell'"
else
  echo "No such user '$user_name'" >&2
  exit 1
fi
```

## 条件判断

```shell
if condition ; then
  ...
elif xxx; then
  ...
else
  ...
fi
# condition：可以是true false,或是算数判断，也可以是一条命令，如果成功，$?是0，则执行then，否则else。
# 判断写法：
# 1. test expr
# 2. [expr]
# 3. [[expr]] 较前两种支持正则（str1=~str2），其他情况三种等价， test -f xxx <=>  [-f xxx]
# 详细选项查看man test
```

## case结构

```shell
case $char in 
  1) xxx 
    ;;
  2) xxx
    ;;
  *) echo "不符合要求的char"
    ;;
esac
```

## 循环

```shell
while condition; do
   xxx
done
```

```shell
until condition
do
  xx
done
```

```shell
for i in list; do
  xxx
done


for ((init;end;iter)); do 
  xxx
done

for ((i=0;i<5;i++)); do
  xxx
done
```

break, continue 与其他语言一致

## 函数

```shell
hello() {
    foo=123
    echo "msg"
    return xxx
}

function hello {
    local foo=123
    echo "msg"
    return
}
# 函数体内声明的变量，体外也能访问，修改也是相同的，local可以避免这一现象
```

## 数组

```shell
ARR=(v1 v2 v3 v4)
ARR=([2]=v1 [100]=v3)
ARR=(*.jpg) # 通配符生成数组
declare -a arr
arr[0]=1 # 赋值时不用{}
arr[1]=2
echo ${arr[1]} # 调用时一定要{}
echo ${arr[@]}

for i in "${arr[@]}"; # $arr[@] 最好放在双引号中，否则如果某个元素包含“ ”，遍历时会导致错误
do
 xxx
done

${arr[*]}：和${arr[@]} 相同
"${arr[*]}"：会将元素拼接为一个字符串输出

# ${foo} 等价于 ${foo[0]}
echo ${foo} == echo ${foo[0]}
foo=1 == foo[0]=1

${foo[@]}代表整个数组
${#foo[@]}：元素个数
foo[100]=1000
echo ${#foo[@]} #结果：1，和index大小无关

# 提取数组序号
arr=([5]=a [9]=b [23]=c)
echo ${!arr[@]} # 结果：5 9 23

# 提取数组成员
arr=( apples bananas cucumbers dates eggs fajitas grapes )
echo ${arr[@]:3:2} # ${arr[@]:start_pos:length}, length可以省略，则输出后续所有成员，结果：dates eggs

# 删除数组及元素
unset arr # 删除整个数组
unset arr[2] # 删除2号元素，不用$,数组的index不会重新排列
```

## set命令

bash在执行脚本的时候，会为脚本创建一个子环境，并设置这个环境的各种参数，set就是用来改变运行环境参数的命令

```shell
set # 显示所有环境变量和shell函数

set -u # 执行脚本时，如果遇到未定义的变量，会按照空来处理，并不会报错。调用此变量会使脚本遇到未定义变量时报错并退出

set -x # 执行脚本时，先打印执行的命令，在打印命令结果

# 脚本错误处理：
# 1. cmd || exit 1 # 如果cmd失败则调用exit
# 2. if ! cmd; then fail_handle; exit 1;fi
# 3. cmd
#    if[ "$?" -ne 0 ] ; then fail_handle; exit 1; fi
# 4. set -e # 每个命令执行后会查看$?，如果!=0 则报错并终止

set +e # 暂时关闭 set -e
cmd1
cmd2
set -e 

# set -e 存在漏洞，
# 1. 当使用| 进行管道命令时，只要最后一个命令成功，就不会报错
# 解决办法：set -eo pipefail，此时管道命令中如果一个命令报错就会报错并返回
# 2. 函数内部的报错不会被trap捕获，需要加上set -E

综上，设置 set -Eeuo pipefail 是比较保险的

set -n # 不运行命令，只检查语法
set -f # 不对通配符进行拓展
set -v # 打印shell接受的每一行输入

# 除了在脚本中设置set，还可以运行时设置
bash -euxo pipefail script.sh
```

## shopt命令

与set相似，但是是bash特有的。略

## mktemp

在/tmp创建只有自己可读写的临时文件，文件名为/tmp/tmp.xxxxxxxx，退出时需要手动清除

```shell
trap 'rm -f "$TMPFILE' EXIT

tmpfile=$(mktemp)

mktemp -p /home # /home/tmp.xxxxx 指定创建临时文件的目录
mktemp -d # 创建临时目录 /tmp
mktemp -t mytemp.xxx # 创建临时文件名字模板，xxx个数表示后面随机字符，建议至少6个
```

## trap

捕获并相应系统信号，

```shell
trap 'cmd' sig1 sig2 ...
trap 'rm -f "$TMPFILE"' EXIT

# 处理需要多条语句时，引入函数

function egress {
cmd1
cmd2
}

function sint {
cmd1
cmd2
}

trap sint INT
trap egress EXIT

trap -l # 查看信号列表
```

信号表：

* HUP：编号1，脚本与所在的终端脱离联系。

* INT：编号2，用户按下 Ctrl + C，意图让脚本终止运行。

* QUIT：编号3，用户按下 Ctrl + 斜杠，意图退出脚本。

* KILL：编号9，该信号用于杀死进程。

* TERM：编号15，这是kill命令发出的默认信号。

* EXIT：编号0，这不是系统信号，而是 Bash 脚本特有的信号，不管什么情况，只要退出脚本就会产生。常用于脚本清理

除清理EXIT信号时，其他信号若需要终止脚本 须增加exit，否则会卡在脚本中。

## 启动环境

略

## 命令提示符

略
