#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//语文，数学，英语，总分

struct student        //结构体的定义
{
    char num[200];
    char name[100];
    char sex[60];
    float score;
}stu[100];





void menu()           //菜单
{
    printf("        ====================================\n");
    printf("|                  学生成绩管理系统                     |\n");
    printf("|               1    输入学生成绩                   |\n");
    printf("|               2    输出学生成绩                   |\n");
    printf("|               3    得出学生最大成绩                |\n");
    printf("|               4    得出学生平均成绩                |\n");
    printf("|               5    学生成绩排序                   |\n");
    printf("|               6    删除学生数据                   |\n");
    printf("|               7    插入学生数据                   |\n");
    printf("|               8    选择学生数据                   |\n");
    printf("|               0    退出管理系统                   |\n");
    printf("        ====================================\n");
}


void input(int len)           //输入函数
{
    int i=len-1;
    do
    {
        printf("请输入第%d个学生的 学号 姓名 性别 成绩\n",i+1);
        scanf("%s %s %s %f",stu[i].num,stu[i].name,stu[i].sex,&stu[i].score);
        i--;
    }
    while(i>=0);
}


void output(int len)          //输出函数
{
    int i=0;
    printf("学号\t姓名\t性别\t成绩\n");
    for(i=0;i<len;i++)
        printf("%s %s %s %f\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].score);
}


void max(int len)             //最大值
{
    int i=0;
    int max=0;
    for(i=0;i<len;i++)
    {
        if(stu[i].score>max)
            max=stu[i].score;
    }
    printf("最高成绩为:%d\n",max);
}


void ave(int len)           //求平均值
{
    int i=0;
    float ave;
    float sum=0;
    for(i=0;i<10;i++)
        sum+=stu[i].score;
    ave=sum/len;
    printf("平均成绩为:%f\n",ave);
}


void sort(int len)         //排序函数
{
    int i,j;
    struct student temp;
    for(i=0;i<len-1;i++)
        for(j=0;j<=len-i-1;j++)
        {
            if(stu[j].score<=stu[j+1].score)
            {
                temp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=temp;
            }
        }
    output(len);
}


void delete1(int *len)      //删除函数
{
    int i = 0;
    int j;
    char wanted[10];

    printf("输入你想删除的学生学号:");
    scanf("%s",wanted);

    while(strcmp(stu[i].num,wanted)!=0&&i<*len)
        i++;
    if(i==*len)
    { printf("不存在此人!\n");
    return; /*返回失败信息*/
    }
    for(j=i;j<*len-1;j++) /*删除操作*/
    {
        strcpy(stu[j].num,stu[j+1].num);
        strcpy(stu[j].name,stu[j+1].name);
        strcpy(stu[j].sex,stu[j+1].sex);
        stu[j].score=stu[j+1].score;
    }
    (*len)--;
    printf("\t\tcongratulations Successed!\n"); /*返回成功信息*/
    output(*len);
}


void insert1(int *len)
{
    struct student stu2;
    int j;

    int weizhi;

    printf("请依次输入你想插入的学生的 学号 姓名 性别 成绩\n");
        scanf("%s %s %s %f",stu2.num,stu2.name,stu2.sex,&stu2.score);

    printf("输入你想插入的位置:");
        scanf("%d",&weizhi);

    if((weizhi-1<0) || (weizhi-1>(*len)))
        printf("位置输入错误:");
    else
    {
        for( j=*len;j>=weizhi;j--)
        {
            strcpy(stu[j].num,stu[j-1].num);
            strcpy(stu[j].name,stu[j-1].name);
            strcpy(stu[j].sex,stu[j-1].sex);
            stu[j].score=stu[j-1].score;
        }
        *len=*len+1;
        strcpy(stu[weizhi-1].num,stu2.num);
        strcpy(stu[weizhi-1].name,stu2.name);
        strcpy(stu[weizhi-1].sex,stu2.sex);
        stu[weizhi-1].score=stu2.score;
        printf("现在的数组为:");
        output(*len);
        printf("\n");
    }
}



/*
    for(i=0;;i++)
    {
        if(stu[i].num==wanted)
        {
            j=i;
            for(k=j;k<len;k++)
                {
                    stu[k]=stu[k+1];
                }
            len--;
            printf("删除成功!\n");
            printf("现在的学生信息为:");
            output(len);
            break;
        }

        if(i==len-1)
        {
            printf("不存在此人!");
            break;
        }
        else
            continue;

    }
 */



void select1(int len)
{
    int i = 0;
    char wanted[10];

    printf("输入你想查找的学生学号:");
    scanf("%s",wanted);

    while(strcmp(stu[i].name,wanted)!=0&&i<len)
        i++;
    if(i==len)
    {
        printf("不存在此人!\n"); /*返回失败信息*/
    }
    else
    {
        printf("Congratulations!查找成功\n");
        printf("%s %s %s %f\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].score);
    }
}


int main()
{
    int choose;
    int len;


    while(1)
    {
        menu();
        printf("请选择0--6:  ");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                {
                    printf("首先请输入学生人数:");
                    scanf("%d",&len);
                    input(len);
                    break;
                }
            case 2:  output(len); break;
            case 3:  max(len);    break;
            case 4:  ave(len);    break;
            case 5:  sort(len);   break;
            case 6:  delete1(&len); break;
            case 7:  insert1(&len); break;
            case 8:  select1(len); break;
            case 0:  exit(0);  break;
            default: printf("错误的输入，请重新输入：");
        }
    }

    return 0;
}
