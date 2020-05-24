# GIT

参照[ https://www.liaoxuefeng.com/wiki/896043488029600/896202780297248 ]

## 集中式 vs 分布式

* 集中式：将文件储存在某个服务器上，当需要修改文件时，需要确认其他人没有同时修改该文件（lock），传输到本地后修改提交回服务器。效率受到网络条件和修改人数限制。

* 分布式：将完整的版本库储存在电脑上，支持离线工作。可以同时修改一个文件，修改后提交到一起尽兴merge。性能高，但是耗费空间。

## GIT基本

GIT工作目录有3个区域组成：

* working tree（工作区）：即文件夹中的当前状态。
* repository（仓库）：储存所有提交的版本。（cache/repository area）
* index（缓冲区）：即储存临时文件的区域，处于repository和working tree中间一层。（stage/index area）

### 新建仓库

* git init：在当前文件夹新建git仓库，输入后，会生成.git文件夹，该文件用以储存git的基本设置和逻辑等。

**Note：** word等二进制格式文件，虽然可以保存在git中，但是无法正常追踪器修改历史等信息，git支持utf-8 （without BOM）。windows自带记事本在保存文件时会在文件头添加0xefbbbf，一会导致很多问题。

### 添加文件

* git add filename1 file2：将文件filename加入**缓冲区**

* git commit -m ”comment“：将**缓冲区**的更改提交到仓库，每次commit会返回操作号（AR）。

### 修改文件

* git status：查看当前缓冲区状态，会显示文件夹中，文件修改、添加和删除的状态。

* git diff file1：查看file1在**工作区**和**缓冲区**中文件的区别。

* git diff --cached file1：查看file1在当前**缓冲区**和**仓库**中文件的区别。

* 修改文件后，使用git add 将需要修改的文件传入缓冲区，然后git commit提交。

### 版本控制

git中，当前工作版本是HEAD指针指向的版本。版本回溯就是操作HEAD指针更换当前版本。

* git log （--pretty=oneline ...）：查看更新历史和版本号。

* git reflog：查看在git中输入过的命令。
* git reset [--soft|--hard|--mixed] [HEAD\^|<commit>]：移动HEAD到相应的commit位置，HEAD\^表示上一个commit。不加选项，将index中文件移除。--soft：只移动HEAD，不对index或working tree中文件操作。--mixed：将index修改为commit内容，不修改working tree。--hard：同时修改index和working tree。

### 删除/恢复文件

* git rm file1：从仓库中移除file1
* git checkout file1：将文件从仓库中复制并替换到工作区。

### 分支管理

git项目创建后，自动生成master分支，其他从master或其他分支创建。分支之间修改时相互不影响，比如需要开发新功能，在完全开发完之前，为保证master分支不被频繁修改，则新建一个分支，阶段性更新，全部更新完成后，将两分支merge，来保证master分支不会因为多次修改而被打乱。分支和版本一样，都是对修改的管理。

每个分支相当于一个指针，创建分支就是创建一个新的指针，例如master本身就是一个指针，新一个dev branch，就又多了一个dev指针。HEAD指针负责选取当前的仓库版本。

* git branch dev：创建一个名为dev的branch。
* git branch --list/-l：列出全部分支
* git branch --delete/-d dev：删除dev分支，未融合的分支无法删除。
* git branch -D dev：强制删除分支
* git switch/checkout dev：将HEAD指向dev，推荐switch。切换分支时，工作区也会随之切换，当工作区存在没有commit的变动时，无法切换。
* git merge dev：将dev融合到当前分支。两分支当前指针指向相同节点。当被融合分支节点与当前分支节点在一条分支线上，且被融合节点更新时，会fast forward，将当前节点指向被融合节点。如两个分支不在同一份直线时，则会产生conflict，git会将个分支信息更新至工作区文件中，用户根据信息对相应的文件进行修改，之后add & merge进当前分支。
* git branch -d dev：删除dev分支。

### BUG分支

当在当前分支的工作区有未完成的工作，但是现在需要切换到其它分支去临时修改文件，可以保存当前工作区，然后进行切换等。

* git stash：保存当前工作区。
* git stash list：查看被保存的工作区。
* git stash apply <stash名字>：恢复工作区，但不从list中删除。
* git stash drop <stash名字>：从list中删除。
* git stash pop <stash名字>：恢复工作区，并从list中删除。

* git cherry-pick <AR>：当两个分支出现同样的变更需求，且所需文件版本相同时，在该分支使用此命令，进行一次相同的变更。<AR>为提交时返回的编号。

**Note：**新建分支的同时也会将master分支的log复制到新分支。git log只会打印当前分支的log。


### 远程仓库

使用github当作仓库时：

* ssh-keygen -t rsa -C ”email.com"：生成自己的SSH key，包含公钥和私钥，将公钥添加至github账户，就可以从github仓库中下载上传。只有拥有私钥的人才能上传修改，有公钥的人可以下载。公钥保存在主目录下（/c/Users/Ye Ziduo/.ssh）。
* 在github中新建repository。极路repository的地址
* git clone git@github.com:michaelliao/gitskills.git：将远程仓库下载到本地，并保存到以当前项目名字命名的文件夹中。（本地没有仓库时使用）
* git remote：查询当前保存的远程仓库。
* git remote add origin git@github.com:michaelliao/learngit.git: 向git中添加远程仓库路径，“origin”为远程仓库名字，可以修改，相当于为远程仓库路径创建一个名字。
* git push -u origin master：把master分支从本地向origin的master分支中推送，并把两分支关联起来。第一次推送需要“-u”来输入github用户信息，之后可以省略。
* git branch dev origin/dev：将origin的dev分支checkout到本地，本地不能有dev分支，否则无效。
* git pull origin dev：从origin中将与本地关联的dev pull到本地，若产生冲突，则先解决冲突的文件，在add&commit到当前branch。
*  git branch --set-upstream-to=origin/<branch> dev：将origin中的dev分支和本地的dev关联。

* rebase：

### TAG

为代码的某一阶段打上baseline，来方便记忆和使用。

* git tag <tagname> [AR] -m "comment"：切换到需要打标签的分支，然后使用。会将当前分支仓库中对应AR的commit的文件打上标签。没有AR时是指最新版本。

* git tag：查询所有标签。

* git tag -d t1：删除t1

* git push origin <tagname>：将t1推送到origin

* git push origin --tags：推送全部tag

* git checkout t1：将HEAD指向t1，并t1中文件放到工作区，但后续log全部消失。

  **NOTE：**checkout也可以移动HEAD，git checkout <id>。

## 后续问题

1. SSH KEY的工作原理。
2. 从远程仓库中拿文件

