#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <string.h> 
using namespace std;
void Charcount(FILE *fp)//�ַ�����
{
	int sum=0;
	char str;
	while(fscanf(fp,"%c",&str)!=EOF)
	{
		sum++;
	}
	cout<<"�ַ���ĿΪ��" <<sum<<endl;
	fclose(fp);
} 
void  Wordcount(FILE *fp)//���ʼ���
{
	int sum=0;
	char str;
	char ch[]={ ' ', '\n', '{', '}', '(', ')', '=', '+', '_', '*', '%' }; 
	int i,len=strlen(ch);
	while(fscanf(fp,"%c",&str)!=EOF)
	{
		for(i=0;i<len;i++)
		{
			if(str==ch[i])
			   sum++;
		}
	}
	cout<<"������ĿΪ��"<<sum<<endl;
	fclose(fp);
}
void Linecount(FILE *fp)//�м��� 
{
	int sum=0;
	char str;
	while(fscanf(fp,"%c",&str)!=EOF)
	{
		if(str=='\n')
		   sum++;
	}
	cout<<"����Ϊ��"<<sum<<endl;
	fclose(fp);
} 
void Count(FILE *fp)//������������������ע��������ͳ��
{
	char str;
	int esum=0,csum=0,nsum=0;
	while(fscanf(fp,"%c",&str)!=EOF)
	{
		if(str=='{'||str=='}')
		   esum++;
		else if(str=='\n')
		{
			fscanf(fp,"%c",&str);
			while(str=='\n')
			{
				esum++;
	            fsacnf=(fp,"%c",&str);
			}
		}
		else if(ch=='/')
	}
}
int main(int argc, char *argv[])
{
     FILE *fp;
	if(strcmp("-c",argv[1])==0)
	{
		fp=fopen(argv[2],"r");
		Charcount(fp);
	}
	if(strcmp("-w",argv[1])==0)
	{
		fp=fopen(argv[2],"r");
		Wordcount(fp);
	}
	if(strcmp("-l",argv[1])==0)
	{
		fp=fopen(argv[2],"r");
		Linecount(fp);
	}
	else if(strcmp("-a",argv[1])==0)
	{
		fp=fopen(argv[2],"r");
		Count(fp);
	}
}
