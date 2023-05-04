#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//统计文件字符数 
int getChar(FILE *fp)
{
	char ch;
	int num=0;
	while((ch=fgetc(fp))!=EOF)
	{
		num++;
	}
	rewind(fp);
	return num;
}

//统计文件单词数 
int getWord(FILE *fp)
{
	int num=0;
	int a=0,b=0;
	int flag=0;  
	char word;   

    word = fgetc(fp);  

	if(word == ' ' || word == ',')
	{
		     flag=1;
			 num--;
			 b--;
	}
	while(feof(fp)==0)
    {
        if(flag == 0 && (word == ' ' || word == ','))
		{
			 num++;
             flag = 1;
             a++;
        }
        else if( (word != 32 && word != 44) && flag==1) 
        {
            num++;
            flag = 0;
			b++;
        }
		else
		{
		    num=num;
		}
		word = fgetc(fp); 
    }
	
	if(flag==1)
	{
	    num=a;
	}
    rewind(fp);
	if(a==b)
	{
	num=num/2+1;
	}
    return num;
}


int main(int argc,char*argv[])
{
	FILE *fp;
	int num;
	char string;

    if(argc==3)
	{
    	
		fp = fopen(argv[2],"r");        //读取文件的内容
		 
		if(fp == NULL)
		{
			printf("错误：无法打开%s\n",argv[2]);
			exit(1);
		}    
		

           
	       if(!strcmp(argv[1],"-c"))	
			{
		        num = getChar(fp);
		     	printf("字符数为：%d\n",num);
		    }
		
		   else if(!strcmp(argv[1],"-w"))
			{
			    num = getWord(fp);
			    printf("单词数为：%d\n",num); 
			}
           else 
			{
                printf("参数错误 ！");
            }
	}
	else 
	{
		printf("错误：参数输入错误，请重新输入\n");
	}
} 
