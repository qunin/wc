#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
using namespace std;
void Charcount(FILE *fp)//字符计数
{
    if(fp==NULL)
		{
			cout<<"打开文件失败！"<<endl;
			return ;
		}
	int sum=0;
    char str;
    int flag = 0;
    char temp = ' ';
    while(fscanf(fp,"%c",&str)!=EOF)
    {
        sum++;
        if (!(str >= 0 && str <= 127) && !(temp >= 0 && temp <= 127) && flag < 2) {
            sum = sum - 1;
            flag ++;
        }
        if(flag == 1){
            flag = 0;
            temp = ' ';
        }
        else temp = str;
    }
    cout<<"The num of char is：" <<sum<<endl;
    fclose(fp);
}
void  Wordcount(FILE *fp)//单词计数，只记英文单词，中文不算
{
	if(fp==NULL)
		{
			cout<<"打开文件失败！"<<endl;
			return ;
		}
    int sum=0;
    char str;
    char temp[20]={0};
    int flag = 0;
    int j = 0;
    while(fscanf(fp,"%c",&str)!=EOF)
    {
        if(!(str >= 'a' && str <= 'z') && !(str >= 'A' && str <= 'Z')){
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
	if(fp==NULL)
		{
			cout<<"打开文件失败！"<<endl;
			return ;
		}
	int sum=0;
	char str;
	while(fscanf(fp,"%c",&str)!=EOF)
	{
		if(str=='\n')
		   sum++;
	}
	cout<<"The num of line is："<<sum<<endl;
	fclose(fp);
} 
void Count(FILE *fp)//空行、注释行、代码行
{
	if(fp==NULL)
		{
			cout<<"打开文件失败！"<<endl;
			return ;
		}
	int i=0,esum=0,csum=0,nsum=0;
    char str;
    do{
        if(feof(fp))
            break;
        fscanf(fp,"%c",&str); 
        if((feof(fp)))   
            break;
        while(str=='\t'||str==' ')
           fscanf(fp,"%c",&str);
        if(str=='\n')
        {
            fscanf(fp,"%c",&str);
            i=1;
            while(str=='\t'||str==' ')
                fscanf(fp,"%c",&str);
            if(str=='\n')
            {
                esum++;
                i=0;
            }
            else if(str=='}'||str=='{')
            {
                fscanf(fp,"%c",&str);
                while(str=='\t'||str==' ')
                {
                    fscanf(fp,"%c",&str);
                    i++;
                }
                if(str=='\n')
                {
                    esum++;
                    i=0;
                }
                else if((feof(fp)))
                    esum++;
                else
                {
                    fseek(fp,-i,1);
                    i=0;
                }
            }
            else
                fseek(fp,-1,1);   
        }
        else if(str=='}'||str=='/')
        {
            fscanf(fp,"%c",&str);
            while(str==' '||str=='\t')
                fscanf(fp,"%c",&str);
            if(str=='/'||str=='*')
            {
                nsum++;
                while(str!='\n')
                {
                    fscanf(fp,"%c",&str);
                    if(feof(fp))
                        break;
                }
                if(!(feof(fp)))
                    fseek(fp,-1,1);
            }
        }
        else
        {
            csum++;
            while(str!='\n')
                fscanf(fp,"%c",&str);
            fseek(fp,-1,1);
        }

    }
    while(1);
    cout<<"the num of empty-line is:"<<esum<<endl;
    cout<<"the num of code-line is:"<<csum<<endl;
    cout<<"the num of node-line is:"<<nsum<<endl;
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
	if(strcmp("-s",argv[1])==0)
	{
		char str[30][100];
		int i=0;
		system("dir /B >log.txt");
        fp=fopen("log.txt","r");
        while(!feof(fp))
       {
	      char ch2[100];
	      fgets(ch2,100,fp);
	      int len=strlen(ch2);
	      if(ch2[len-2]=='c'&&ch2[len-3]=='.'&&len>3)
	     {
		      strcpy(str[i],ch2);
		      str[i][len-1]='\0';
		      i++;
	     }
       }
       int n=i;
       for(i=0;i<n;i++)
       {
	       FILE *f1=fopen(str[i],"r");
	       printf("%s:\n",str[i]);
	       Charcount(f1);
	       f1=fopen(str[i],"r");
	       Linecount(f1);
	       f1=fopen(str[i],"r");
	       Wordcount(f1);
	       f1=fopen(str[i],"r");
	       Count(f1);
	
       }
	} 
	if(strcmp("-a",argv[1])==0)
	{
		fp=fopen(argv[2],"r");
		Count(fp);
		fclose(fp);
	}
}
