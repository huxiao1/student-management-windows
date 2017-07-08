#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//���ģ���ѧ��Ӣ��ܷ�

struct student        //�ṹ��Ķ���
{
    char num[200];
    char name[100];
    char sex[60];
    float score;
}stu[100];





void menu()           //�˵�
{
    printf("        ====================================\n");
    printf("|                  ѧ���ɼ�����ϵͳ                     |\n");
    printf("|               1    ����ѧ���ɼ�                   |\n");
    printf("|               2    ���ѧ���ɼ�                   |\n");
    printf("|               3    �ó�ѧ�����ɼ�                |\n");
    printf("|               4    �ó�ѧ��ƽ���ɼ�                |\n");
    printf("|               5    ѧ���ɼ�����                   |\n");
    printf("|               6    ɾ��ѧ������                   |\n");
    printf("|               7    ����ѧ������                   |\n");
    printf("|               8    ѡ��ѧ������                   |\n");
    printf("|               0    �˳�����ϵͳ                   |\n");
    printf("        ====================================\n");
}


void input(int len)           //���뺯��
{
    int i=len-1;
    do
    {
        printf("�������%d��ѧ���� ѧ�� ���� �Ա� �ɼ�\n",i+1);
        scanf("%s %s %s %f",stu[i].num,stu[i].name,stu[i].sex,&stu[i].score);
        i--;
    }
    while(i>=0);
}


void output(int len)          //�������
{
    int i=0;
    printf("ѧ��\t����\t�Ա�\t�ɼ�\n");
    for(i=0;i<len;i++)
        printf("%s %s %s %f\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].score);
}


void max(int len)             //���ֵ
{
    int i=0;
    int max=0;
    for(i=0;i<len;i++)
    {
        if(stu[i].score>max)
            max=stu[i].score;
    }
    printf("��߳ɼ�Ϊ:%d\n",max);
}


void ave(int len)           //��ƽ��ֵ
{
    int i=0;
    float ave;
    float sum=0;
    for(i=0;i<10;i++)
        sum+=stu[i].score;
    ave=sum/len;
    printf("ƽ���ɼ�Ϊ:%f\n",ave);
}


void sort(int len)         //������
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


void delete1(int *len)      //ɾ������
{
    int i = 0;
    int j;
    char wanted[10];

    printf("��������ɾ����ѧ��ѧ��:");
    scanf("%s",wanted);

    while(strcmp(stu[i].num,wanted)!=0&&i<*len)
        i++;
    if(i==*len)
    { printf("�����ڴ���!\n");
    return; /*����ʧ����Ϣ*/
    }
    for(j=i;j<*len-1;j++) /*ɾ������*/
    {
        strcpy(stu[j].num,stu[j+1].num);
        strcpy(stu[j].name,stu[j+1].name);
        strcpy(stu[j].sex,stu[j+1].sex);
        stu[j].score=stu[j+1].score;
    }
    (*len)--;
    printf("\t\tcongratulations Successed!\n"); /*���سɹ���Ϣ*/
    output(*len);
}


void insert1(int *len)
{
    struct student stu2;
    int j;

    int weizhi;

    printf("������������������ѧ���� ѧ�� ���� �Ա� �ɼ�\n");
        scanf("%s %s %s %f",stu2.num,stu2.name,stu2.sex,&stu2.score);

    printf("������������λ��:");
        scanf("%d",&weizhi);

    if((weizhi-1<0) || (weizhi-1>(*len)))
        printf("λ���������:");
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
        printf("���ڵ�����Ϊ:");
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
            printf("ɾ���ɹ�!\n");
            printf("���ڵ�ѧ����ϢΪ:");
            output(len);
            break;
        }

        if(i==len-1)
        {
            printf("�����ڴ���!");
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

    printf("����������ҵ�ѧ��ѧ��:");
    scanf("%s",wanted);

    while(strcmp(stu[i].name,wanted)!=0&&i<len)
        i++;
    if(i==len)
    {
        printf("�����ڴ���!\n"); /*����ʧ����Ϣ*/
    }
    else
    {
        printf("Congratulations!���ҳɹ�\n");
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
        printf("��ѡ��0--6:  ");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                {
                    printf("����������ѧ������:");
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
            default: printf("��������룬���������룺");
        }
    }

    return 0;
}
