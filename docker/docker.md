# Docker

ref: https://www.runoob.com/docker/docker-hello-world.html

https://cloud.tencent.com/developer/article/1885678

## 名词

docker image：用于创建docker container的模板

docker container：docker运行的实例

docker host：docker运行依赖的物理机或虚拟机

docker respository：docker用来保存image的仓库，例如：https://hub.docker.com

docker registery：一个registery可以包含很多仓库。
## docker命令

### 创建docker

**docker run  [options] \<image\>:\<tag> \<cmd>** : docker run ubuntu:15.10 /bin/echo "hello world"，如果镜像不在本地，则会向docker registery中下载，默认dockerhub

**docker run -itd \<image>:\<tag> \<cmd>**: docker run -i -t ubuntu:15.10 /bin/bash, -t 在新容器内指定一个终端，-i 允许对容器进行标准输入，-d 启动后不进入容器，后台运行，--name \<name> 指定容器名字，-p [ip:]\<host ip>:\<container ip>[/udp] ip映射, -v \<host path>:\<container path>，-e <env_var>="value"，设置环境变量，--link \<other container name/ID>:\<symbol in container>，-P 将container内部使用的端口随即映射到host上

### 其他命令

**docker <cmd> --help**：查看命令帮助，docker stats --help，docker image --help

**exit / ctrl+D**：退出

**ctrl+P+Q**：切出（退回上层，但不停止当前container）

**docker attach <container ID/name>**：进入container

**docker exec [option] <ID/name> <cmd>**: 进入一个运行中的容器并运行cmd，docker exec -it xxx，进入xxx并启动一个新的终端

**docker ps [-a]**：查看所有docker container[包括已停止的]

**docker logs <docker ID/name>**：查看docker内的标准输出

**docker port <docker ID/name>**：查看docker内的标准输出

**docker stop <ID/name>**：停止容器

**docker rm <ID/name>**: 删除容器

**docker restart <ID/name>**：先停止容器，然后重启。如果已经停止则直接启动

**docker start \<name/ID> **：启动一个已经停止的容器

**docker version**

### 镜像操作

**docker pull centos**

**docker pull index.tenxcloud.com/tenxcloud/httpd**

**docker image list**

**docker image rm centos:latest**

**docker image inpect centos**: 查看镜像信息

**docker image save centos > docker-centos.tar.gz**：导出镜像

**docker image load -i docker-centos.tar.gz**：导出镜像

**docker export <container ID/name> > name.tar**：导出容器快照

**docker import name.tar**

**docker commit -m="comment" -a="author" <contatiner ID/name> <image_name>**: 将container提交为镜像

**docker tag \<image_id> \<image_name:tag>**

**docker push \<image_name>**: 推image到registery

**docker search <image name>**

### 配置文件

/etc/docker/daemon.json

```json
{
  "insecure-registries": [
    "10.0.0.0/8",
    "10.117.58.2:5000",
    "127.0.0.0/8",
    "192.0.0.0/8",
    "ampregistry:5000"
  ],
  "live-restore": true,
  "max-concurrent-downloads": 10,
  "max-concurrent-uploads": 10,
  "registry-mirrors": [
    "https://registry.docker-cn.com"
  ],
  "storage-driver": "overlay2"
}
```

## dockerfile

```dockerfile
FROM <base image>
MAINtainer <author, not necessary>
RUN <CMD> # 每执行一个RUN就会多一层docker，导致过多膨胀，所以尽量用“&&”链接
RUN <CMD1>
...
COPY [options] <source> <dest> #从宿主机中copy文件到docker
ADD [options] <source> <dest> # 与COPY相似，推荐使用COPY
WORKDIR <work dir, will cd to this dir for the actions below>
VOLUME <挂载卷>
EXPOSE <对外端口>
ENV key1=val1 key2=val2
ENTRYPOINT <cmd after started> # docker启动后运行，如果声明entrypoint，则cmd中的值均变为参数，即启动项为 ENTRYPOINT+CMD，如果docker run的时候设置--entrypoint会覆盖dockerfile中的entrypoint
CMD ["a","b", ...] 或 <cmd> # docker启动后运行
```

example:

```dockerfile
FROM centos:6.8
RUN yum install wget unzip php php-gd php-mbstring -y && yum clean all
# 设置工作目录，之后的操作都在这个目录中
WORKDIR /var/www/html/
RUN wget -c http://static.kodcloud.com/update/download/kodexplorer4.25.zip
RUN unzip kodexplorer4.25.zip && rm -f kodexplorer4.25.zip
RUN chown -R apache.apache .
CMD ["/usr/sbin/apachectl","-D","FOREGROUND"]
```

通过dockerfile构建docker

```shell
docker build -t yzd/helloworld:v2 ./
# -t: image名字， ./: dockerfile所在目录
```

## container link

```dockerfile
docker network create -d bridge test-net #创建Docker网络
docker run -itd --name test1 --network test-net ubuntu /bin/bash
docker run -itd --name test2 --network test-net ubuntu /bin/bash
```
