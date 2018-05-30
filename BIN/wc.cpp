#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <string.h> 
using namespace std;
void Charcount(FILE *fp)//字符计数
{
	int sum=0;
	char str;
	while(fscanf(fp,"%c",&str)!=EOF)
	{
		sum++;
	}
	cout<<"the num of char is：" <<sum<<endl;
	fclose(fp);
} 
void  Wordcount(FILE *fp)//单词计数
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
	cout<<"the num of word is："<<sum<<endl;
	fclose(fp);
}
void Linecount(FILE *fp)//行计数 
{
	int sum=0;
	char str;
	while(fscanf(fp,"%c",&str)!=EOF)
	{
		if(str=='\n')
		   sum++;
	}
	cout<<"the num of line is："<<sum<<endl;
	fclose(fp);
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
}
