#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
typedef struct _goods//商品结构体
    {
       char name[20];//商品名称
       int category;//商品种类
       float prize;//商品价格
       int shelf_life;//商品的保质期(按月来记)
       char time[15];//商品的生产日期
    }goods;
    goods b[20];

int N;
int switch_num;
int return_num;
char password1[20];
int num_star;


    int input(goods b[],int N);//从系统中导入数据
    void display(goods b[],int N);//显示信息
    void change(goods b[],int N);//修改信息
    void _search(goods b[],int N);//查找信息
    int  _insert(goods b[],int N);//添加信息
    int  _delete(goods b[],int N);//删除信息
    void _sort(goods b[],int N);//排序信息
    void save(goods b[],int N);//保存信息
    void menu_customer();//顾客系统界面
    void menu_manager();//管理员系统界面
    void system_manager();//顾客系统
    void password();//密码函数
    void modify_password();//更改密码函数

    //导入函数已完善
    int input(goods b[],int N)
    {
        N=0;
        FILE *fp;//打开文件
        fp=fopen("data.txt","r+");
        if(fp==NULL)//判断文件是否为空
        {
              printf("can't open this file");
              exit(0);
        }
        while(!feof(fp))//导入
        {
             fscanf(fp,"%s%d%f%d%s",b[N].name,&b[N].category,&b[N].prize,&b[N].shelf_life,b[N].time);
             N++;

        }
        Sleep(100);
        printf("恭");
        Sleep(50);
        printf("喜");
        Sleep(50);
        printf("您");
        Sleep(50);
        printf("导");
        Sleep(50);
        printf("入");
        Sleep(50);
        printf("成");
        Sleep(50);
        printf("功");
        Sleep(50);
        fclose(fp);

        return N-1;//商品数目
     }

    //显示函数已完善
     void display(goods b[],int N)
     {
        int i;
        for(num_star=0;num_star<18;num_star++)//显示*符号
        {
            printf("*");
            Sleep(5);
        }
        printf("商");
        Sleep(50);
        printf("品");
        Sleep(50);
        printf("信");
        Sleep(50);
        printf("息");
        Sleep(50);
        printf("如");
        Sleep(50);
        printf("下");
        Sleep(50);
        for(num_star=0;num_star<18;num_star++){
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
        printf("商品名称          类别  价格    保质期  生产日期\n");
        for(i=0;i<N;i++){
        printf("%-8s\t%4d\t%.2f\t%4d\t%4s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);//显示信息
        }
        printf("\n【注；类别1.休闲食品    2.奶品水饮   3.生鲜水果】\n\n");
        for(num_star=0;num_star<48;num_star++)//显示*符号
        {
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
        printf("按1后回车返回");
        scanf("%d",&return_num);
        if(return_num==1)//返回主界面
        {
            system("cls");
            return;
        }


     }
     //修改函数已完善
     void change(goods b[],int N)
     {
        int i,n;
        char a[10];
        for(num_star=0;num_star<18;num_star++)
        {
            printf("*");
            Sleep(10);
        }
        printf("欢");
        Sleep(50);
        printf("迎");
        Sleep(50);
        printf("进");
        Sleep(50);
        printf("入");
        Sleep(50);
        printf("修");
        Sleep(50);
        printf("改");
        Sleep(50);
        printf("系");
        Sleep(50);
        printf("统");
        Sleep(50);
        for(num_star=0;num_star<18;num_star++){
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
        printf("-1-请输入需要修改的商品的名称\n   ");//需要修改的名称
        loop:
        scanf("%s",a);
        for(i=0;i<N;i++)//比较是哪个商品
        {
            if(!strcmp(b[i].name,a))
                break;
        }
        if(i==N)
        {
            printf("\n-1-对不起找不到该商品,请重新输入\n   ");
            goto loop;
        }
        else
            printf("\n-2-您需要的修改的商品信息如下：\n   (1)商品名称(2)类别 (3)价格  (4)保质期 (5)生产日期\n   %-9s\t%-3d\t%.2f\t%5d\t%10s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);//输出并左右对齐
            printf("\n-3-请输入需要修改的商品信息编号\n   ");
            loop2:
            scanf("%d",&n);
            switch(n)//选择修改什么信息
            {
            case 1:
                printf("\n-4-请输入该商品的名称\n   ");
                scanf("%s",b[i].name);
                break;
            case 2:
                printf("\n-4-请选择商品类别*1.休闲食品2.奶品水饮3.生鲜水果\n   ");
                scanf("%d",&b[i].category);
                break;
            case 3:
                printf("\n-4-请输入该商品的价格\n   ");
                scanf("%f",&b[i].prize);
                break;
            case 4:
                printf("\n-4-请输入该商品的保质期*按月计（即输入1-12之间的整数）\n   ");
                scanf("%d",&b[i].shelf_life);
                break;
            case 5:
                printf("\n-4-请输入该商品的生产日期*例如20170920\n   ");
                scanf("%s",b[i].time);
                break;
            default:
                printf("\n-3-你输入的信息有误请重新输入：\n   ");
                goto loop2;

            }
            printf("\n-5-修改成功\n\n");
            for(num_star=0;num_star<52;num_star++)
            {
                printf("*");
                Sleep(5);
            }
            printf("\n\n");
            printf("按1后回车返回");
            scanf("%d",&return_num);//返回主界面
            if(return_num==1)
            {
            system("cls");
            return;
            }
     }
     //搜索函数已完善
     void _search(goods b[],int N)
     {
        int i,n;
        for(num_star=0;num_star<17;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("欢");
        Sleep(50);
        printf("迎");
        Sleep(50);
        printf("进");
        Sleep(50);
        printf("入");
        Sleep(50);
        printf("搜");
        Sleep(50);
        printf("索");
        Sleep(50);
        printf("系");
        Sleep(50);
        printf("统");
        Sleep(50);
        for(num_star=0;num_star<17;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
           printf("-1-请输入需要查询的内容*1.按名称查询2.按类型查询\n   ");
           scanf("%d",&switch_num);
           switch(switch_num)//查询内容
           {
                case 1:
                    char a[10];
                    loop:
                    printf("\n-2-请输入需要查询的商品的名称:\n   ");
                    scanf("%s",a);
                    for(i=0;i<N;i++)//逐个比较商品名称
                    {
                        if(!strcmp(b[i].name,a))
                        {
                            break;
                        }

                    }
                    if(i==N)
                        {
                        printf("\n-2-对不起找不到该商品*1.返回主菜单2.继续查询\n   ");
                        scanf("%d",&switch_num);
                        if(switch_num==1)
                        {
                            goto loop7;
                        }
                        else goto loop;
                    }
                    else
                    {
                    printf("\n-3-您查询的商品信息如下：\n   商品名称       类别  价格    保质期  生产日期\n   %-7s\t%4d\t%.2f\t%4d\t%4s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);
                    break;
                    }
                case 2:
                    int kind,_count=0;
                    printf("\n-2-请输入商品的类别*1.休闲食品2.奶品水饮3.生鲜水果\n   ");
                    loop3:
                    scanf("%d",&kind);
                    printf("\n-3-您查询的商品信息如下：\n   商品名称       类别  价格    保质期  生产日期\n");
                    for(i=0;i<N;i++)
                        {
                        if(b[i].category==kind)
                        {
                            printf("   %-7s\t%4d\t%.2f\t%4d\t%4s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);
                            _count++;
                        }
                    }
                    if(_count==0)//记录类别商品的数量
                    {
                    Sleep(100);
                    printf("\n-3-对不起找不到该类别信息请重新输入\n   ");
                    goto loop3;
                    }

           }
                    loop7:
                    printf("\n");
                    for(num_star=0;num_star<50;num_star++)
                    {
                    printf("*");
                    Sleep(5);
                    }
                    printf("\n\n");
                    printf("按1后回车返回");
                    scanf("%d",&return_num);
                    if(return_num==1)
                    {
                    system("cls");
                    return;
                    }
     }
     //添加函数已完善
     int _insert(goods b[],int N)
     {
         int n,i=1,t;
        for(num_star=0;num_star<17;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("欢");
        Sleep(50);
        printf("迎");
        Sleep(50);
        printf("进");
        Sleep(50);
        printf("入");
        Sleep(50);
        printf("添");
        Sleep(50);
        printf("加");
        Sleep(50);
        printf("系");
        Sleep(50);
        printf("统");
        Sleep(50);
        for(num_star=0;num_star<17;num_star++)
        {
            printf("*");
            Sleep(5);
        }
         printf("\n\n-1-请输入需要添加的商品的个数：\n   ");
         scanf("%d",&n);
         t=n;
         while(n)
         {
            printf("\n-%d-输入第%d条商品信息:\n",i+1,i);
            printf("   1.名称:");scanf("%s",b[N+i-1].name);
            printf("\n   2.类别*1.休闲食品2.奶品水饮3.生鲜水果：");scanf("%d",&b[N+i-1].category);
            printf("\n   3.价格：");scanf("%f",&b[N+i-1].prize);
            printf("\n   4.保质期*按月计（即输入1-12之间的整数)：");scanf("%d",&b[N+i-1].shelf_life);
            printf("\n   5.生产日期*例如20170920：");scanf("%s",b[N+i-1].time);
            n--;
            i++;
         }
         printf("\n-%d-添加成功\n\n",i+1);
         for(num_star=0;num_star<50;num_star++)
                    {
                    printf("*");
                    Sleep(10);
                    }
        printf("\n\n");
        printf("按1后回车返回");
        scanf("%d",&return_num);
        if(return_num==1)
        {
            system("cls");
            return N+t;
        }
     }
     //删除函数已完善
     int _delete(goods b[],int N)
     {
        int i,q;
        char c[10];
        for(num_star=0;num_star<16;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("欢");
        Sleep(50);
        printf("迎");
        Sleep(50);
        printf("进");
        Sleep(50);
        printf("入");
        Sleep(50);
        printf("删");
        Sleep(50);
        printf("除");
        Sleep(50);
        printf("系");
        Sleep(50);
        printf("统");
        Sleep(50);
        for(num_star=0;num_star<16;num_star++)
        {
            printf("*");
            Sleep(10);
        }
        printf("\n\n-1-请输入需要删除的商品的名称\n   ");
        loop4:
        scanf("%s",c);
        for(i=0;i<N;i++)//寻找商品信息
        {
            if(!strcmp(b[i].name,c))
                break;
        }
        if(i==N)
        {
            printf("\n-1-对不起找不到该商品,请重新输入\n   ");
            goto loop4;
        }
        else
            printf("\n-1-您删除的商品信息如下：\n   商品名称       类别  价格    保质期  生产日期\n   %-7s\t%4d\t%.2f\t%4d\t%4s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);
            printf("\n-2-确认删除？*1.确认2.取消\n   ");
            loop5:
            scanf("%d",&q);
            if(q!=2&&q!=1)
            {
                printf("错误请重新输入");
                goto loop5;
            }
            else if(q==1)
            {
                while(i<N-1)
                {
                    b[i]=b[i+1];
                    i++;
                }
                printf("\n-3-删除成功\n\n");
            for(num_star=0;num_star<48;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("\n\n");
                printf("按1后回车返回");
                scanf("%d",&return_num);
                if(return_num==1)
        {
                system("cls");
                return N-1;
        }

            }
            else
            printf("\n");
            for(num_star=0;num_star<50;num_star++){
                printf("*");
                Sleep(5);
            }
            printf("\n\n\n");
            printf("按1后回车返回");
            scanf("%d",&return_num);
            if(return_num==1)
            {
            system("cls");
            return N;
            }


     }
     //保存信息已完善
     void save(goods b[],int N)
     {
            int i;
            FILE *point;
            point=fopen("data.txt","w");
            if(point==NULL)
            {
                printf("can't find the file");
                exit(0);
            }
            for(i=0;i<N;i++)
            fprintf(point,"%-8s\t%4d\t%.2f\t%4d\t%4s\n",b[i].name,b[i].category,b[i].prize,b[i].shelf_life,b[i].time);
            printf("恭");
            Sleep(50);
            printf("喜");
            Sleep(50);
            printf("您");
            Sleep(50);
            printf("导");
            Sleep(50);
            printf("出");
            Sleep(50);
            printf("成");
            Sleep(50);
            printf("功");
            Sleep(50);
            fclose(point);
     }
     //排序函数已完善
     void _sort(goods b[],int N)
     {
            goods temp;
            int n,i,j;
        for(num_star=0;num_star<16;num_star++)
        {
            printf("*");
            Sleep(5);
        }
        printf("欢");
        Sleep(50);
        printf("迎");
        Sleep(50);
        printf("进");
        Sleep(50);
        printf("入");
        Sleep(50);
        printf("排");
        Sleep(50);
        printf("序");
        Sleep(50);
        printf("系");
        Sleep(50);
        printf("统");
        Sleep(50);
        for(num_star=0;num_star<16;num_star++)
        {
            printf("*");
            Sleep(5);
        }
            printf("\n\n-1-请问您需要按什么排序【1价格        2生产日期】\n   ");//选择排序类型
            scanf("%d",&switch_num);
            switch(switch_num)
            {
            case 1:
                printf("\n-2-请选择排序类型【1.价格从高到低排序2.从低到高】\n   ");
                loop5:
                scanf("%d",&switch_num);
                if(switch_num==1)//降序排列
                    {
                    for(i=0;i<N-1;i++)
                    {
                        for(j=0;j<N-1-i;j++)
                        {
                            if(b[j].prize<b[j+1].prize)
                            {
                                    temp=b[j];
                                    b[j]=b[j+1];
                                    b[j+1]=temp;
                            }
                        }

                    }
                }
                else if(switch_num==2)//升序排列
                    {
                    for(i=0;i<N-1;i++)
                    {
                        for(j=0;j<N-1-i;j++)
                        {
                            if(b[j].prize>b[j+1].prize)
                            {
                                    temp=b[j];
                                    b[j]=b[j+1];
                                    b[j+1]=temp;
                            }
                        }
                    }
                }
                else{
                    printf("输入错误请重新输入：\n");
                    goto loop5;
                }
                break;


            case 2:
                {
                printf("\n-2-请选择排序类型【1.生产日期从早到晚2.从晚到早】\n   ");
                loop6:
                scanf("%d",&switch_num);
                if(switch_num==1)//升序排列
                    {
                    for(i=0;i<N-1;i++)
                    {
                        for(j=0;j<N-1-i;j++)
                        {
                            if(strcmp(b[j].time,b[j+1].time)>0)
                            {
                                    temp=b[j];
                                    b[j]=b[j+1];
                                    b[j+1]=temp;

                            }
                        }
                    }
                }


                else if(switch_num==2)//降序排列
                    {
                    for(i=0;i<N-1;i++)
                    {
                        for(j=0;j<N-1-i;j++)
                        {
                            if(strcmp(b[j].time,b[j+1].time)<0)
                            {
                                    temp=b[j];
                                    b[j]=b[j+1];
                                    b[j+1]=temp;

                            }
                        }
                    }
                }
                else{
                    printf("\n-2-输入错误请重新输入：\n   ");
                    goto loop6;
                }
                break;





            }
            default: return;
     }
     printf("\n-3-排序成功【欲显示结果返回主菜单并执行显示功能】\n\n");
     for(num_star=0;num_star<48;num_star++){
                    printf("*");
                    Sleep(5);
     }
     printf("\n\n");
     printf("按1后回车返回");
     scanf("%d",&return_num);
     if(return_num==1)
     {
            system("cls");
            return;
     }

     return;
     }



     void menu_customer()//顾客选择菜单
    {
       printf("\n                 欢迎进入顾客查询系统！                     \n");
       printf("*********************系统功能菜单************************\n");
       printf("|                ___1:商品信息导入___                   |\n");
       printf("|                ___2:商品信息显示___                   |\n");
       printf("|                ___3:商品信息查询___                   |\n");
       printf("|                ___4:商品信息排序___                   |\n");
       printf("|                ___0:退出管理系统___                   |\n");
       printf("---------------------------------------------------------\n");
	   printf("*********************************************************\n\n");
	   printf("请先导入文件再进行其他操作！\n输入以上序号使用其功能：\n");

    }
    void menu_manager()//管理员选择系统
{
    printf("\n                超市商品信息管理员系统                   \n\n");
	printf("*********************系统功能菜单************************\n");
	printf("---------------------------------------------------------\n");
	printf("|                ___1:商品信息导入___                   |\n");
	printf("|                ___2:商品信息显示___                   |\n");
	printf("|                ___3:商品信息添加___                   |\n");
	printf("|                ___4:商品信息删除___                   |\n");
	printf("|                ___5:商品信息修改___                   |\n");
	printf("|                ___6:商品信息查询___                   |\n");
	printf("|                ___7:商品信息排序___                   |\n");
	printf("|                ___8:商品信息导出___                   |\n");
	printf("|                ___9:修改登入密码___                   |\n");
    printf("|                ___0:退出管理系统___                   |\n");
	printf("---------------------------------------------------------\n");
	printf("*********************************************************\n\n");
	printf("请先导入文件再进行其他操作！\n输入以上序号使用其功能：\n");
}

void password()//验证密码
{
    int count=0;//计数器
    char a[20];
    FILE *fp;
    fp=fopen("password.txt","r+");
    if(fp==NULL)
        {
              printf("对不起找不到密码");
              exit(0);
        }
    fscanf(fp,"%s",password1);//读取文件中的密码
    printf("*************欢迎进入超市商品信息管理系统登录窗口*************\n\n\n");
    printf("请输入密码：");
    scanf("%s",a);
    while(count<2)
    {
        if(strcmp(password1,a))
            {
                printf("\n************密码错误,您还有%d次机会，请谨慎输入密码************\n\n",2-count);
                printf("请再次输入密码");
                scanf("%s",a);
                count++;
            }
        else goto loop;
    }
        if(!strcmp(password1,a))
            goto loop;
        printf("\n*****************密码错误次数过多,请稍后再试******************\n");
        exit(0);
        loop:
            system("cls");
            printf("*********************欢迎进入系统************************\n");
            system("cls");
    printf("请稍等.");
    Sleep(200);
    system("cls");
    printf("请稍等..");
    Sleep(200);
    system("cls");
    printf("请稍等...");
            Sleep(200);
        fclose(fp);
}

void modify_password()//修改密码
{
    FILE *fp;
    fp=fopen("password.txt","w+");//打开密码文件
    char new_password[20];
    char confirm_password[20];
    for(num_star=0;num_star<14;num_star++)
        {
            printf("*");
            Sleep(5);
        }
    printf("欢");
    Sleep(50);
    printf("迎");
    Sleep(50);
    printf("进");
    Sleep(50);
    printf("入");
    Sleep(50);
    printf("密");
    Sleep(50);
    printf("码");
    Sleep(50);
    printf("修");
    Sleep(50);
    printf("改");
    Sleep(50);
    printf("系");
    Sleep(50);
    printf("统");
    Sleep(50);
    for(num_star=0;num_star<14;num_star++)
    {
            printf("*");
            Sleep(5);
    }
    printf("\n\n-1-请输入新密码：\n   ");
    scanf("%s",new_password);
    printf("\n-2-请确认密码:\n   ");
    scanf("%s",confirm_password);
    if(!strcmp(new_password,confirm_password))
    {
        printf("\n-3-修改成功");
        fprintf(fp,"%s",new_password);//将新密码保存至文件
        fclose(fp);
    }
    else
        printf("\n-3-两次密码不相同修改失败");
    printf("\n\n");
    for(num_star=0;num_star<48;num_star++)
    {
            printf("*");
            Sleep(5);
    }
    printf("\n\n");
    printf("按1后回车返回");
    scanf("%d",&return_num);
    if(return_num==1)
     {
            system("cls");
            return;
     }


}




void system_manager()//顾客系统
{
    system("color f0");//控制背景和字体颜色：xx（前面是背景颜色，后面为字体颜色）
    system("cls");
    password();
    system("cls");
	int i=1;
	while(i)
	{
        menu_manager();
        scanf("%d",&i);
		switch (i)
		{
            case 1: system("cls");
                    N=input(b,N);break;//调用导入模块

            case 2: system("cls");
                    display(b,N);break;//调用输出信息模块

            case 3: system("cls");
                    N=_insert(b,N);break;//调用添加模块

			case 4: system("cls");
                    N=_delete(b,N);break;//调用删除模块

            case 5: system("cls");
                    change(b,N);break;//调用修改信息模块

            case 6: system("cls");
                    _search(b,N);break;//调用查找模块


            case 7: system("cls");
                    _sort(b,N);break;//调用排序模块

            case 8: system("cls");
                    save(b,N);break;//调用输出函数

            case 9: system("cls");
                    modify_password();break;


            case 0:printf("*********************感谢使用！**************************");
			break;//退出程序

            default:
			printf("项目不存在\n");
			break;
		}
	}
	return;
}


void system_customer()//顾客系统
{
    system("color f0");//界面颜、色
    system("cls");
    printf("请稍等.");
    Sleep(200);
    system("cls");
    printf("请稍等..");
    Sleep(200);
    system("cls");
    printf("请稍等...");
    Sleep(700);
    system("cls");
    int i=1;
    while(i)
	{
        menu_customer();
        scanf("%d",&i);
		switch (i)//顾客系统功能选择
		{
            case 1: system("cls");
                    N=input(b,N);break;//调用导入模块

            case 2: system("cls");
                    display(b,N);break;//调用输出信息模块


            case 3: system("cls");
                    _search(b,N);break;//调用查找模块


            case 4: system("cls");
                    _sort(b,N);break;//调用排序模块

            case 0:printf("*********************感谢使用！**************************");
			break;//退出程序

            default:
			printf("项目不存在\n");
			break;
		}
	}
	return;
}

int main()
{
    system("color f0");
    printf("*********************请选择进入顾客系统或管理员系统*********************\n");
    printf("    *********************1=顾客系统，2=管理员系统*********************\n");
    printf("                                  请选择：                    \n");
    loop7:
    scanf("%d",&switch_num);
    switch(switch_num)
    {
    case 1:
        system_customer();
        break;
    case 2:
        system_manager();
        break;
    default:
        printf("错误信息，请重新输入：");
        goto loop7;
    }
}
