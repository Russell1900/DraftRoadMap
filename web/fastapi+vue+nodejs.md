网站学习记录

# nvm、npm、nodejs

## nvm

ref:[Node 版本管理器 NVM 安装指南](https://www.freecodecamp.org/chinese/news/node-version-manager-nvm-install-guide/)

nvm：node version manager

用来管理是用的node版本

linux安装：

```bash
# 将
nvm安装在~/.nvm中
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.1/install.sh | bash
# or
wget -qO- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.1/install.sh | bash
# 配置：在~/.zshrc或~/.bashrc中添加
export NVM_DIR="$([ -z "${XDG_CONFIG_HOME-}" ] && printf %s "${HOME}/.nvm" || printf %s "${XDG_CONFIG_HOME}/nvm")"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"

source ~/.zshrc 
# or
source ~/.bashrc

nvm -v #检查版本

# 安装node
nvm install latest / vX.Y.Z # 安装最新版本或vX.Y.Z
nvm alias default vX.Y.Z # 将default设置为vX.Y.Z
nvm use default / vX.Y.Z # 是用特定npm的版本
nvm ls # 查看已安装的node


```

## NodeJS、NPM

ref:[全网最全的npm小白教程 - 掘金](https://juejin.cn/post/7091142503478329358)

nodejs：js模块化。情况下在js中的成员不能被其他js直接引用，需要被引入到同一个html下。

npm是nodejs提供的管理第三方模块的工具,在NVM中安装并设置完成npm后，执行npm -v查看版本。

### CommonJS规范

CommonJS规定：

1. 导入其他模块时统一是用require()函数；

2. 每个.js文件都是一个独立模块，成员都是私有；

3. 在.js中，是用module.exports向外提供共享成员；

```js
// A.js：
const user = "ABC";
function show() {
    console.log(user);
}

module.exports = {
    show
};
// or
module.user = user;

// B.js
const my_user = require("A.js")
my_user.show();
console.log(my_user.user);
```

变量exports和变量module.exports初始时会指向同一个对象，如果进行赋值操作那么指向的对象就会变成不同对象，require时会引入module.exports；

### npm和package

npm：node package manager。

npm是指npm命令行工具，也可以指工具对应npm网站，类似git repo，包含jQuery、BootStrap等包。

NodeJS中，模块（module）就是指一个单独的js文件；包是指多个模块的集合，多个模块组合在一起，会在一个出口模块中require其他模块的共享成员进行包装，然后输出出口模块的共享成员。

npm管理的单位时包。

https://www/npmjs.com：包搜索网站。

```bash
npm init [-y]# 初始化项目
npm install <package> # 安装包到本地（当前项目的module），安装信息保存在dependencies中
npm install <package> -g # 安装到系统
npm install <package> ---save-dev # 作为开发安装包，开发安装包在生产环境中不会安装，会保存在package.json中的devDependencies中


# 检查和设置镜像源
npm config get registry
npm config set registry=https://registry.npm.taobao.org/


```

#### nrm

用来切换安装包的来源

```bash
npm install nrm -g # 安装nrm
nrm ls # 列出所有源信息
nrm use taobao # 是用taobao源
```

# VUE

ref:[Quick Start | Vue.js](https://vuejs.org/guide/quick-start.html)

## 创建vue项目

```bash
npm create vue@latest
cd <project>
npm install # 安装package.json中的dependencies
npm run dev #以开发模式运行
npm run serve # 

npm run build # build项目，into ./dist
```

1. tag中的attribute，如果以v-开头，那么是vue提供的指令；如
   
   ```html
   <div v-bind:id="a"></div> // a实际上是变量，不是字符串，以":"开头的属性，后面接的都是变量名称
   <div :id="a"></div> // a实际上是变量，不是字符串
   <a v-on:click="doSomething"> ... </a> // 事件以@开头，后面绑定的是function名字
   <a @click="doSomething"> ... </a>
   ```

2. {{ exp }} 不能在tag的属性中，只能用在tag内容中，exp需要是一个表达式，返回一个确定值，渲染后的最终是会随exp动态更新；
   
   ```html
   <div> {{ message }} </div>
   <div> {{ f() }} </div>
   ```





# TYPESCRIPT

ref： [Using Vue with TypeScript | Vue.js](https://vuejs.org/guide/typescript/overview.html)


