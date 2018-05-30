#include <iostream>
#include <stdlib.h>
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
	cout<<"字符数目为：" <<sum<<endl;
	fclose(fp);
} 
void  Wordcount(FILE *fp)//单词计数
{
    int sum=0;
    char str;
    char temp[20]={0};
    int flag = 0;
    int j = 0;
    while(fscanf(fp,"%c",&str)!=EOF)
    {
        if (str == ' ' || str == '\n'){
            for (int i = 0; i < strlen(temp); i ++) {
                if((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= 'A' && temp[i] <= 'Z')){
                    flag = 1;
                    break;
                }
            }
        }
        else{
            temp[j] = str;
            j ++;
        }
        if(flag == 1){
            sum ++;
            flag = 0;
            j = 0;
            memset(temp, 0, sizeof(temp));
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
	cout<<"行数为："<<sum<<endl;
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
