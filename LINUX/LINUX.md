# Linux

## LINUX目录结构

### 基本目录

linux把所有设备均当成文件对待。

/: 根目录

/bin，/usr/bin：可执行二进制文件。

/boot：系统启动时需要的文件

/dev：存放设备，每个文件相当于一个设备

/lib，/usr/lib，/usr/local/lib：系统使用的函数库

/home：系统默认用户目录

/mnt，/media：外接储存设备挂载点

/etc：系统配置文件，

/usr：用户数据，/usr/include，头文件；/usr/bin：可执行文件。/usr/lib：共享库。

**NOTE：**/usr中的bin和lib与/bin、/lib的区别

### 文件类型和权限

查看文件属性时（ls -l），显示“xrwxrwx uezd g1 文件名”，x为-表示是文件，d时表示文件夹，c表示字符设备文件，l表示链接，b表示block设备文件，s表示管道文件。rwx表示读写执行，文件所有者权限/group/其他用户，uezd表示文件所有者，g1：组。

whoami：查看当前用户名。

cat：输出文件内容，cat /etc/password

/etc/password：用户信息文件，用户名：x： 用户编号：用户所在组编号

/etc/group：用户组信息文件，用户组名：x： 用户组编号

修改用户权限：chmod u/g/o/a +/-rwx（1/2/4）文件拥有者/group/otheruser/all

### 命令

man + 命令名字：命令手册，当一些命令没有--help时可以使用。man man 查询手册详解。

history：历史命令

\>, \>>：重定向

ls：显示文件目录

mkdir

|：管道

clear

cd

pwd

rm

rmdir

ln

cat：查看文件内容

grep [option]... [file]...：文本搜索

find：查找文件

cp

mv

file：获取文件类型

touch：更新一个文件的日期。

more 内容：将内容的信息分页打印。

tar：打包 -cvf tar xxx，-xvf tar， -C path，读到-C时，会切换到path目录。

gzip：gzip file 压缩file至file.gz，gzip -d a.gz：解压a.gz至a

bzip2: 同上, .bz2

tar -c**z**vf a.tar.gz file...：将文件打包成a.gz 。tar -x**z**vf a.tar.gz：解压gz

tar -c**j**vf a.tar.bz2 file...：将文件打包成a.bz2 。tar -x**j**vf a.tar.bz2：解压bz2

which：查看命令位置。

### 用户管理

/etc/password：用户信息文件，用户名：x： 用户编号：用户所在组编号

/etc/group：用户组信息文件，用户组名：x： 用户组编号

useradd [-d path -g group -G group1,group] \<username\>：创建用户，-d path，指定path为该用户的用户目录，没有的话默认创建一个。-g 指定组，-G 增加组

userdel \<username>

usermod -g -G... \<username>

passwd [username]：设置用户密码

su [-] username：切换与用户，- 表示切换时同时进入该用户家目录

sudo cmd：使用管理员权限执行cmd

chmod [-u/g/o/a +/- rwx|124] \<file\>：修改文件属性

chown \[username\[:group]] \<file> ：修改file文件的所属用户和组

groupadd \<group1>：创建组

groupdel \<groupname>：group中有人的时候不能删除

groupmod：修改组的信息

### 系统命令

date：当前时间

cal：日历

ps \<-aux>：进程查询，a：所有，u：详细，x：包括没有终端控制的，就是没有cmd窗口来控制的

**NOTE：**虚拟内存：虚拟内存是指在运行程序时，是程序认为自己有足够的内村，而在运行时只向物理内存中装入程序当前执行所在的内存叶，当程序需要执行的命令在其他内存叶时（访问虚拟内存，操作系统判断访问的虚拟内存不在已装入的内存叶中）则产生装入其他内存叶的请求。

top：动态显示进程情况。

kill \<pid>：结束pid进程

后台运行：在调用后加上&，或在cmd上ctrl+z。

jobs：显示后台运行的程序

fg 1/2/3/4...：切换后台运行的程序，1/2 为jobs显示的编号

切换tty/init：tty表示linux终端。不同的终端提供的服务不一样，如界面终端和字符命令终端。

init 0：关机，init 6 重启，init 3 字符终端，init 5图形终端。

df -h：查看硬盘使用情况 df后面加文件名时，会显示文件所在的硬盘的使用情况。

du：查看某个目录的使用情况

rpm：安装后缀为rpm的文件。rpm -ivh xxx.rpm

ifconfig

netstat