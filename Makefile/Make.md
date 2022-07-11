# Makefile

## 基本语法

```makefile
# 基本规则
target : dependence1 dependence2 ...
	command1
	command2

# 执行： make -f xxx.mk

# 变量: 除了$()的变量都是字符串类型，即是说用通配符时，*.o，不会展开。但$(wildcard *.o)，会展开
VAR = xxx
xxx ${VAR}

# 特殊变量
VPATH=src:..headers:... # VPATH定义了make搜索文件时，搜索文件夹的顺序，src->../header->...

# 关键字
# VPATH只是指定了所有文件的搜索路径，vpath（小写）更加灵活，不再是变量，是命令
vpath {pattern} {dirs} # 为符合pattern的文件添加dirs
vpath %.h ../header:../foo:...
vpath % mypath
# 以上，对.h的搜索路径为 ../header -> ../foo -> mypath

# 特殊函数：
$(wildcard pattern)：搜索并展开通配符文件
$(subst pattern, replacement,string)：将string的pattern替换问replacement,用于字符串替换
$(var:pattern=repl)：将var中的pattern替换为repl，返回，支持集合替换，会替换集合中的每个元素
$(filter pattern, files)：files是a.c b.o c.c这种集合模式，filter将符合pattern的file过滤出来重新组成集合
objs=a.c b.o c.xx asd.sadasd e.o g.o
$(filter %.o $(objs)) 相当于 b.o e.o g.o

	
include x.mk *.mk $(mk) # 在执行target前，将x.mk等make文件展开到当前位置
-include xx.mk # make在执行include的时候，如果没有xx.mk的时候，make不会报错，只会弹出一条警告信息

.PHONY clean # 伪目标
clean:
	rm target ...
	
# 隐式规则1：如果target是%.o,那么会自动找%.c/cpp/cxx，调用gcc/g++/cc -c -o %.o %.c 进行编译
hello: hello.o greeting.o
	g++ -o hello hello.o greeting.o
#hello.o: greeting.h   即使注释掉此行，也可以正常make，make会自动找hello的依赖的.o，并通过隐式规则生成
#greeting.o: greeting.h

# 隐式规则2：
# 通配符，“*”表示所有，*.c，表示所有.c文件
clean:
 rm -f *.o
# 通配符“%”，表示匹配任意，*和%的区别，就在于，规则会根据%展开，每次规则中的%都是一个值
 
#隐式规则3：自动化变量
a_out.o b_out.o : xx.h
	g++ -c $(subst _out,,$@) -o $@ # $@表示target的集合，会将$@依次替换为target的一个元素，展开成多个规则
#以上相当于
a_out.o: xx.h
	g++ -c a.o -o a_out.o
b_out.o: xx.h
	g++ -c b.o -o b_out.o
	
# $< 表示所有dependence集合，会对规则进行迭代
a.out: a.o b.o c.o d.o
	g++ $< -o $@
# 相当于
a.out: a.o
	g++ a.o -o a.out
a.out: b.o
	g++ b.o -o a.out
a.out: c.o
	g++ c.o -o a.out
	
# $^ 表示所有dependence集合，不会对规则进行迭代，会在位置展开
a.out: a.o b.o c.o d.o
	g++ $^ -o $@
# 相当于
a.out: a.o b.o c.o d.o
	g++ a.o b.o c.o d.o -o a.out
	
#静态模式，targets t1 t1: target_pattern: dependent_pattern:
$(objs):%.o:%.c  # 从objs中选取和%.o匹配的依次作为target，进行展开规则，依赖为%.c（%和target中选中的值相同）
	$(CC) -c $(CFLAGS) $< -o $@ 
	
# 编译器提取依赖头文件
g++/gcc/cc -M/-MM [CPPFLAGS] xxx.cpp/c/cc ...# -M会将库文件头也提取出来，-MM不会提取库文件
# 输出格式为，一般会输出到xxx.d文件中
xxx.o : xxx.cpp a.h b.h ...
xxx1.o : xxx1.cpp a.h b.h ...
# 配合include 
# make 会在每条命令返回后都检查错误码，非零时则终止，在命令前面加上“-”会使make忽略错误码

#调用其他其他make
subsys:
	cd subdir && $(MAKE)  # $(MAKE) 是指调用make
# or
subsys:
	$(MAKE) -C subdir
```

make的工作步骤：

1. 读取makefile
2. 展开所有include的makefile
3. 初始化变量
4. 推到隐式规则，并展开所有规则
5. 为所有目标文件创建依赖链
6. 根据依赖链决定哪些目标要重新生成
7. 执行生成命令



https://blog.csdn.net/weixin_38391755/article/details/80380786
