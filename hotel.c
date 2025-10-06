#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define N 200
#define Login "admin"//管理员用户名
#define MAX 1000//累计充值1000元升级为会员账号


typedef struct {//房间结构体 
	char ID[20];//房间号
	char type[20];//房间类型 
	float price;//价格
	char state[20];//是否入住
}Rooms;
Rooms room[N];
int room_num;//当前房间的总数（空闲房间+入住房间）

typedef struct {//顾客信息结构体 
	char Name[20];//用户名
	char state[20];//是否入住
	char identity[30];//会员账号和普通账号
	float price;//账户余额
	float Discounts;//折扣
	float price_num;//累计余额，达到某个数升级为会员账号
}Users;
Users user[N];
Users user2;//存储登录的客户信息
int  user_num;//当前记录在册的客户总数


//声明函数 
void main_1();//管理员登陆函数
void main_2();//顾客登录函数

void add_room();//增加房间信息
void del_room();//删除房间信息
void modify_room();//修改房间信息
void query_room();//查找房间信息
void All_room();//浏览房间信息

void add_User();//增加客户信息
void del_User();//删除客户信息
void modify_User();//修改客户信息
void query_User();//查找客户信息
void All_User();//浏览客户信息

void View_room();//查看空闲房间
void Opening_a_house();//开房
void check_out();//退房
void View_ID();//查看我的房卡
void Recharge();//充值

void read_room();//读取房间信息 
void save_room();//保存房间信息 
void read_User();//读取客户信息 
void save_User();//保存客户信息


int main()
{
	read_room();//读取房间信息
	read_User();//读取客户信息
	
	int i,choice=1,j=1;
	char name[10];
	
	while(choice != 0)
	{
		printf("***********欢迎使用旅店小帮手***********\n");
		printf("---------------- 1.登录 ----------------\n");
		printf("---------------- 2.注册 ----------------\n");
		printf("---------------- 0.退出 ----------------\n");
		printf("请输入操作数:>");
		scanf("%d",&choice);
		switch(choice)
		{
		    case 1:
			    printf("请输入用户名:>");
				scanf("%s", name);
				if( strcmp(name,Login) == 0 )
				{
					system("cls");
					main_1();//管理员登录函数
					break;//跳出switch选择
				}
				for (i=0;i<user_num;i++)
				{
					if( strcmp(name,user[i].Name) == 0 )
					{
						user2=user[i];
						system("cls");
						main_2();//顾客登录函数
						j=0;
						break;//打断循环 
					}
				}
				if(j==1)
				    printf("Oh,no~查无此号！");
				break;//跳出switch选择
			case 2:
				add_User();//增加客户信息
				break;//跳出switch选择
			case 0:
				return 0;
			default:
				printf("Oh,no~bug!");
				break;//跳出switch选择
		}
		save_room();//保存房间信息
		save_User();//保存客户信息
		system("pause");
		system("cls");
	}
	
	return 0;
}

void main_1()//管理员登录函数
{
	int choice=1;
	
	while(choice != 0)
	{
		printf("***********欢迎使用旅店小帮手***********\n");
		printf("      欢迎管理员：%s 当前房间数：%d\n", Login, room_num);
		printf("---------------- 1.增加房间信息 --------\n");
		printf("---------------- 2.删除房间信息 --------\n");
		printf("---------------- 3.修改房间信息 --------\n");
		printf("---------------- 4.查找房间信息 --------\n");
		printf("---------------- 5.浏览房间信息 --------\n");
		printf("---------------- 6.浏览顾客信息 --------\n");
		printf("---------------- 7.查找顾客信息 --------\n");
		printf("---------------- 8.修改顾客信息 --------\n");
		printf("---------------- 9.删除顾客信息 --------\n");
		printf("---------------- 0.退出登录 ------------\n");
		printf("请输入操作数:>");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				add_room();//增加房间信息
				break;
			case 2:
				del_room();//删除房间信息
				break;
			case 3:
				modify_room();//修改房间信息
				break;
			case 4:
				query_room();//查找房间信息
				break;
			case 5:
				All_room();//浏览房间信息
				break;
			case 6:
				All_User();//浏览客户信息
				break;
			case 7:
				query_User();//查找客户信息
				break;
			case 8:
				modify_User();//修改客户信息
				break;
			case 9:
				del_User();//删除客户信息
				break;
			case 0:
				return;
			default:
				printf("Oh,no~bug!");
				break;
		}
		save_room();//保存房间信息
		save_User();//保存客户信息
		system("pause");
		system("cls");
	}
	
	return;
}

void main_2()//顾客登录函数
{
	int choice=1;
	
	while(choice != 0)
	{
		printf("***********欢迎使用旅店小帮手***********\n");
		printf("欢迎顾客：%s 当前余额：%.1f 享受折扣：%.1f\n", user2.Name, user2.price, user2.Discounts);
		printf("---------------- 1.查看空闲房间 --------\n");
		printf("---------------- 2.开房 ----------------\n");
		printf("---------------- 3.退房 ----------------\n");
		printf("---------------- 4.查看我的房卡 --------\n");
		printf("---------------- 5.充值 ----------------\n");
		printf("---------------- 0.退出登录 ------------\n");
		printf("请输入操作数:>");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				View_room();//查看空闲房间
				break;
			case 2:
				Opening_a_house();//开房
				break;
			case 3:
				check_out();//退房
				break;
			case 4:
				View_ID();//查看我的房卡
				break;
			case 5:
				Recharge();//充值
				break;
			case 0:
				return;
			default:
				printf("Oh,no~bug!");
				break;
		}
		save_room();//保存房间信息
		save_User();//保存客户信息
		system("pause");
		system("cls");
	}
	
	return;
}

//*******************************//
//******房间信息的增删改查*******//
//*******************************//

void add_room()//增加房间信息
{
	int i;
	printf("第%d个房间信息：\n", room_num+1);
	printf("请输入房间号:>");
	scanf("%s", room[room_num].ID);
	for(i=0;i<room_num;i++)
	{
		if( strcmp(room[room_num].ID,room[i].ID) == 0)
		{
			printf("Oh,no~已有此房间号，请重开！\n");
			return;
		}
	}
	printf("房间类型:\nhourroom\nnormalroom\nbigroom\nworthroom\ngreatroom\n");
	printf("请输入房间类型:");
	scanf("%s", room[room_num].type);
	printf("请输入价格:>");
	scanf("%f", &room[room_num].price);
	strcpy(room[room_num].state,"空闲");
	room_num++;
	printf("当当当~成功录入此房！\n");
}
void del_room()//删除房间信息
{
	int i,k;
	printf("请输入要查找的房间号：");
	scanf("%s", room[room_num].ID);
	for(i=0;i<room_num;i++)
	{
		if( strcmp(room[room_num].ID, room[i].ID) == 0)
		{
			printf("======================================\n");
			printf("%-10s%-10s%-10s%-10s%-10s\n", "序号", "房间号","房间类型","原价", "是否入住");
			printf("%-10d%-10s%-10s%-10.2f%-10s\n",i + 1,room[i].ID,room[i].type,room[i].price,room[i].state);
			printf("======================================\n");
			printf("找到喽~\n");
			if( strcmp(room[i].state, "空闲") != 0)
			{
				printf("sorry~此房间正在使用，暂时无法删除！\n");
				return;
			}
			printf("是否删除此房间（1是/0否）:>");
			scanf("%d", &k);
			if(k == 1)
			{
				for (;i<room_num-1;i++)
					room[i]=room[i + 1];
				room_num--;//删除后数量-1
				printf("删除成功！\n");
			}
			else
			{
				printf("删除取消！\n");
			}
			return;
		}
	}
	printf("Oh,no~查无此房！\n");
	return;
}
void modify_room()//修改房间信息
{
	int i,k;
	printf("请输入要查找的房间号：");
	scanf("%s", room[room_num].ID);
	for(i=0;i<room_num;i++)
	{
		if( strcmp(room[room_num].ID, room[i].ID) == 0)
		{
			printf("======================================\n");
			printf("%-10s%-10s%-10s%-10s%-10s\n", "序号", "房间号","房间类型","原价", "是否入住");
			printf("%-10d%-10s%-10s%-10.2f%-10s\n",i + 1,room[i].ID,room[i].type,room[i].price,room[i].state);
			printf("======================================\n");
			printf("找到喽~\n");
			printf("是否修改此房间信息（1是/0否）:>");
			scanf("%d", &k);
			if (k == 1)
			{
				printf("请修改房间类型：");
				scanf("%s", room[i].type);
				printf("请修改价格：");
				scanf("%f", &room[i].price);
				printf("修改成功！\n");
			}
			else
			{
				printf("修改取消！\n");
			}
			return;
		}
	}
	printf("Oh,no~查无此房！\n");
	return;
}
void query_room()//查找房间信息
{
	int i,k;
	printf("请输入要查找的房间号：");
	scanf("%s", room[room_num].ID);
	for(i=0;i<room_num;i++)
	{
		if( strcmp(room[room_num].ID, room[i].ID) == 0)
		{
			printf("======================================\n");
			printf("%-10s%-10s%-10s%-10s%-10s\n", "序号", "房间号","房间类型","原价", "是否入住");
			printf("%-10d%-10s%-10s%-10.2f%-10s\n",i + 1,room[i].ID,room[i].type,room[i].price,room[i].state);
			printf("======================================\n");
			printf("找到喽~\n");
			return;
		}
	}
	printf("Oh,no~查无此房！\n");
	return;
}
void All_room()//浏览房间信息
{
	int i;
	printf("======================================\n");
	printf("%-10s%-10s%-10s%-10s%-10s\n", "序号", "房间号","房间类型","原价", "是否入住");
	for(i=0;i<room_num;i++)
	{
		printf("%-10d%-10s%-10s%-10.2f%-10s\n",i + 1,room[i].ID,room[i].type,room[i].price,room[i].state);
	}
	printf("======================================\n");
	printf("浏览成功！\n");
}


//*******************************//
//******顾客信息的增删改查*******//
//*******************************//
void add_User()//增加客户信息
{
	int i;
	printf("顾客信息注册\n",user_num+1);
	printf("请输入您的名字：");
	scanf("%s", user[user_num].Name);
	if( strcmp(user[user_num].Name, Login) == 0)
	{
		printf("Sorry~您是用户，请不要使用管理员名字！\n");
		return;
	}
	for(i=0;i<user_num;i++)
	{
		if( strcmp(user[user_num].Name, user[i].Name) == 0)
		{
			printf("Oh,no~重名！\n");
			return;
		}
	}
	strcpy(user[user_num].state,"未入住");
	strcpy(user[user_num].identity,"普通账号");
	user[user_num].price = 0;//账户余额，初始值为0
	user[user_num].Discounts = 10.0;//折扣，初始值为10折
	user[user_num].price_num = 0;//累计余额，初始值为0
	user_num++;
	printf("当当当~注册成功，请您登录！\n");
}
void del_User()//删除客户信息
{
	int i,k;
	printf("请输入要查找的顾客姓名：");
	scanf("%s", user[user_num].Name);
	for(i=0;i<user_num;i++)
	{
		if( strcmp(user[user_num].Name, user[i].Name) == 0)
		{
			printf("======================================\n");
			printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "序号", "用户名", "是否入住", "身份", "账户余额", "折扣", "累计充值");
			printf("%-10d%-10s%-10s%-10s%-10.2f%-10.2f%-10.2f\n",i+1,user[i].Name,user[i].state,user[i].identity,user[i].price,user[i].Discounts,user[i].price_num);
			printf("======================================\n");
			printf("找到喽~\n");
			printf("是否删除此顾客（1是/0否）:>");
			scanf("%d", &k);
			if(k == 1)
			{
				for (;i<user_num-1;i++)
					user[i] = user[i + 1];
				user_num--;//删除后数量-1
				printf("删除成功！\n");
			}
			else
			{
				printf("删除取消！\n");
			}
			return;
		}
	}
	printf("Oh,no~查无此人！\n");
	return;
}
void modify_User()//修改客户信息
{
	int i,k;
	printf("请输入要查找的顾客姓名：");
	scanf("%s", user[user_num].Name);
	for(i=0;i<user_num;i++)
	{
		if( strcmp(user[user_num].Name, user[i].Name) == 0)
		{
			printf("======================================\n");
			printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "序号", "用户名", "是否入住", "身份", "账户余额", "折扣", "累计充值");
			printf("%-10d%-10s%-10s%-10s%-10.2f%-10.2f%-10.2f\n",i+1,user[i].Name,user[i].state,user[i].identity,user[i].price,user[i].Discounts,user[i].price_num);
			printf("======================================\n");
			printf("找到喽~\n");
			printf("是否修改此此顾客（1是/0否）:>");
			scanf("%d", &k);
			if(k == 1)
			{
				printf("请修改折扣：");
				scanf("%f", &user[i].Discounts);
				printf("修改成功！\n");
			}
			else
			{
				printf("修改取消！\n");
			}
			return;
		}
	}
	printf("Oh,no~查无此人！\n");
	return;
}
void query_User()//查找客户信息
{
	int i;
	printf("请输入要查找的顾客姓名：");
	scanf("%s", user[user_num].Name);
	for(i=0;i<user_num;i++)
	{
		if( strcmp(user[user_num].Name, user[i].Name) == 0)
		{
			printf("======================================\n");
			printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "序号", "用户名", "是否入住", "身份", "账户余额", "折扣", "累计充值");
			printf("%-10d%-10s%-10s%-10s%-10.2f%-10.2f%-10.2f\n",i+1,user[i].Name,user[i].state,user[i].identity,user[i].price,user[i].Discounts,user[i].price_num);
			printf("======================================\n");
			printf("找到喽~\n");
			return;
		}
	}
	printf("Oh,no~查无此人！\n");
	return;
}
void All_User()//浏览客户信息
{
	int i;
	printf("======================================\n");
	printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "序号", "用户名", "是否入住", "身份", "账户余额", "折扣", "累计充值");
	for(i=0;i<user_num;i++)
	{
		printf("%-10d%-10s%-10s%-10s%-10.2f%-10.2f%-10.2f\n",i+1,user[i].Name,user[i].state,user[i].identity,user[i].price,user[i].Discounts,user[i].price_num);
	}
	printf("======================================\n");
	printf("浏览成功！\n");
}


//*******************************//
//********   顾客操作   *********//
//*******************************//
void View_room()//查看空闲房间
{
	int i;
	printf("======================================\n");
	printf("%-10s%-10s%-10s%-10s%-10s%-10s\n","序号","房间号","房间类型","原价","优惠价格","是否入住");
	for(i=0;i<room_num;i++)
	{
		if( strcmp(room[i].state,"空闲") == 0)
		{
			printf("%-10d%-10s%-10s%-10.2f%-10.2f%-10s\n",i + 1,room[i].ID,room[i].type,room[i].price,room[i].price * (user2.Discounts/10),room[i].state);
		}
	}
	printf("======================================\n");
	printf("浏览成功！\n");
	return;
}
void Opening_a_house()//开房
{
	int i;

	if( strcmp(user2.state,"未入住") != 0)
	{
		printf("Sorry~您已入住，不能再入住了！\n");
		return;
	}
	printf("请输入要开房的房间号：");
	scanf("%s", room[room_num].ID);
	for(i=0;i<room_num;i++)
	{
		if( ( strcmp(room[room_num].ID,room[i].ID) == 0 ) &&  ( strcmp("空闲", room[i].state) == 0 ) )//房间号和是否空闲
		{
			if( user2.price < (room[i].price * (user2.Discounts / 10)) )
			{
				printf("Sorry~您的余额不足，请充值！\n");
				return;
			}
			else
			{
				user2.price -= (room[i].price * (user2.Discounts / 10));
			}
			printf("======================================\n");
			printf("%-10s%-10s%-10s%-10s%-10s%-10s\n","序号","房间号","房间类型","原价","优惠价格","是否入住");
			printf("%-10d%-10s%-10s%-10.2f%-10.2f%-10s\n",i + 1,room[i].ID,room[i].type,room[i].price,room[i].price * (user2.Discounts/10),room[i].state);
			printf("======================================\n");
			strcpy(room[i].state, "已入住");//房间状态改成已入住
			strcpy(user2.state, room[i].ID);//把顾客入住状态改成房间号
			printf("当当当~开房成功！\n");
			return;
		}
	}
	printf("Sorry~查无此房or此房已有人入住！\n");
	return;
}
void check_out()//退房
{
	if( strcmp(user2.state,"未入住") == 0 )
	{
		printf("您还未入住，无法退房！\n");
		return;
	}
	int i;
	for(i=0;i<room_num;i++)
	{
		if( strcmp(user2.state, room[i].ID) == 0 )
		{
			strcpy(room[i].state, "空闲");//房间状态改成空闲
			strcpy(user2.state, "未入住");//把顾客入住状态改成未入住
			printf("退房成功！\n");
			return;
		}
	}
	printf("Oh,no~bug！\n");
}
void View_ID()//查看我的房卡
{
	if( strcmp(user2.state, "未入住") == 0 )
	{
		printf("Sorry~您还未入住!\n");
		return;
	}
	int i;
	for(i=0;i<room_num;i++)
	{
		if( strcmp(user2.state, room[i].ID) == 0 )
		{
			printf("======================================\n");
			printf("%-10s%-10s%-10s%-10s%-10s%-10s\n","序号","房间号","房间类型","原价","优惠价格","是否入住");
			printf("%-10d%-10s%-10s%-10.2f%-10.2f%-10s\n",i + 1,room[i].ID,room[i].type,room[i].price,room[i].price * (user2.Discounts/10),room[i].state);
			printf("======================================\n");
			printf("查看成功！\n");
			return;
		}
	}
	printf("Oh,no~bug！\n");
}
void Recharge()//充值
{
	int i = 0, j = 0, k = 0;
	printf("是否充值到账户（1是/0否）:>");
	scanf("%d",&k);
	if(k == 1)
	{
		printf("请您输入充值金额:>");
		scanf("%f", &user[user_num].price);
		user2.price += user[user_num].price;//账户余额增加
		user2.price_num += user[user_num].price;//累计余额增加
		printf("当当当~充值成功！\n");
		if( user2.price_num >= MAX && strcmp(user2.identity,"普通账号") == 0 )//判断是否累计到1000元和该顾客是否为普通账号
		{
			printf("同时恭喜您升级为VIP,每次消费享受打9折！\n");
			strcpy(user2.identity,"会员账号");
			user2.Discounts=9.0;
		}
	}
	else
	{
		printf("Oh~充值取消！\n");
	}
	return;
}


//*******************************//
//********读取与写入文件*********//
//*******************************//
void read_room()//读取房间信息
{
	FILE *file = fopen("房间信息.txt", "r");//以只读方式打开文件
	if(file == NULL)
	{
		return;
	}
	room_num = 0;
	while( fgetc(file) != EOF )//当下一个字符不为空时
	{
		fseek(file, -1, 1);//每一次循环， 定位在当前行的-1位置，也就是最左边的位置
		int rat = fscanf(file, "%s %s %f %s\n", room[room_num].ID, room[room_num].type, &room[room_num].price, room[room_num].state);
		if(rat == 0)
		{
			break;//没数据就跳出
		}
		room_num++;
	}
	fclose(file);//关闭
}
void save_room()//保存房间信息
{
	int i;
	FILE* fp = fopen("房间信息.txt", "w+");//打开文件+清除文件内信息
	for(i=0;i<room_num;i++)
	{
		fprintf(fp, "%s %s %.2f %s\n", room[i].ID, room[i].type, room[i].price, room[i].state);
	}
	fclose(fp);//关闭文件
}
void read_User()//读取客户信息
{
	FILE* file = fopen("客户信息.txt", "r");//以只读方式打开文件
	if(file == NULL)
	{
		return;
	}
	user_num = 0;//Num为当前系统的录入客户信息的总数， 读入文件前将总数置为0，以防有残留数据
	while( fgetc(file) != EOF )//当下一个字符不为空时
	{
		fseek(file, -1, 1);//每一次循环， 定位在当前行的-1位置，也就是最左边的位置
		int rat = fscanf(file, "%s %s %s %f %f %f\n", user[user_num].Name, user[user_num].state, user[user_num].identity, &user[user_num].price, &user[user_num].Discounts, &user[user_num].price_num);
		if(rat == 0)
		{
			break;//没数据就跳出
		}
		user_num++;
	}
	fclose(file);//关闭
}
void save_User()//保存客户信息
{
	int i;
	for(i=0;i<user_num;i++)
	{
		if( strcmp(user2.Name, user[i].Name) == 0)//把临时结构体数据存储到系统里
		{
			user[i] = user2;
		}
	}
	FILE *fp = fopen("客户信息.txt", "w+");//打开文件+清除文件内信息
	for(i=0;i<user_num;i++)//从1循环到Num， 将客户数据逐个录入 "客户信息数据.txt" 文本内
	{
		fprintf(fp, "%s %s %s %.2f %.2f %.2f\n", user[i].Name, user[i].state, user[i].identity, user[i].price, user[i].Discounts, user[i].price_num);
	}
	fclose(fp);//关闭文件
}
