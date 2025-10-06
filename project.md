# 1 项目简介

本项目开发了旅馆小帮手，线上帮助管理员“动态”记录旅馆入住情况，为顾客提供网上预订的方式等。优点是便利，提高旅馆运营的效率，提高客户满意度，也方便了会员管理和资料的统计等。

# 2 项目使用的语言——C语言

### 2.1 C的语法

+ 结构体

```c
typedef struct {//房间结构体 
	char ID[20];//房间号
	char type[20];//房间类型 
	float price;//价格
	char state[20];//是否入住
}Rooms;
```

实现对房间信息的封装。

```c
typedef struct {//顾客信息结构体 
	char Name[20];//用户名
	char state[20];//是否入住
	char identity[30];//会员账号和普通账号
	float price;//账户余额
	float Discounts;//折扣
	float price_num;//累计余额，达到某个数升级为会员账号
}Users;
```

实现对顾客信息的封装。

+ 函数

|函数名|	功能描述|
| :--------|---------: |
|void View_room()	|查看空闲房间|
|void Opening_a_house()	|开房|
|void check_out()	|退房|
|void View_ID()	|查看我的房卡|
|void Recharge()|充值|
|void add_room()|增加房间信息|
|void del_room()|	删除房间信息|
|void modify_room()|	修改房间信息|
|void query_room()|	查找房间信息|
|void All_room()|	浏览房间信息|
|void add_User()|	增加客户信息|
|void del_User()|	删除客户信息|
|void modify_User()	|修改客户信息|
|void query_User()	|查找客户信息|
|void All_User()	|浏览客户信息|
|void read_room()|	读取房间信息|
|void save_room()|	保存房间信息|
|void read_User()|	读取客户信息|
|void save_User()|	保存客户信息|
|void main_1()|	房间信息函数|
|void main_2()|	顾客登录函数|


函数模块，让代码可观、有条理。

+ 指针

```c
FILE *file = fopen("房间信息.txt", "r")
FILE *fp = fopen("房间信息.txt", "w+");
```

获得指向文件的指针，便可以读取与写入文件，将房间信息和顾客信息保存在磁盘中

### 2.2 C的特性

+ 效率高：C使用了低级别的语言结构，能够直接访问计算机的硬件资源。因此编写程序运行速度非常快。

+ 灵活度高：C提供了各种数据类型、操作符和控制结构，可以用来编写各种类型的程序——从简单的小工具到复杂的应用程序。

+ 可移植性高：C是一种标准化的语言，只需要进行一些简单的修改，便可在不同的操作系统和计算机上运行。

# 3 实现功能

![旅馆小帮手的结构图](image/%E6%80%9D%E7%BB%B4%E5%AF%BC%E5%9B%BE.jpg)

旅馆小帮手的结构图

![流程图](image/%E6%B5%81%E7%A8%8B%E5%9B%BE.png)

流程图

![界面演示图](image/%E7%95%8C%E9%9D%A2%E6%BC%94%E7%A4%BA%E5%9B%BE.png)

界面演示图

+ 房间信息的增删改查

+ 顾客信息的增删改查

![房间信息与顾客信息的增删改查](image/%E7%AE%A1%E7%90%86%E5%91%98%E6%BC%94%E7%A4%BA%E5%9B%BE.png)

+ 顾客操作

+ 会员与折扣

![顾客操作](image/%E9%A1%BE%E5%AE%A2%E6%BC%94%E7%A4%BA%E5%9B%BE.png)
