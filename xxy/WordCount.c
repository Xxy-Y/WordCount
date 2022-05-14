#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//拆分字符串 
int split(char str[])
{    //使用strtok()实现分割
	int n = 0;
	//char str[] = "hello,world hello";
	char* str1 = strtok(str, " ,");
	
	while (str1 != NULL)
	{
         str1 = strtok(NULL, " ,");
		 n++;
	}
	return n;
}
//统计字符数 
int getCountChar(char *name){
	FILE *fp;
	int count = 0;
	char ch[1024];
	fp = fopen(name, "r");
	while(fgets(ch,1024,fp) != NULL)//逐行读取fp所指向文件中的内容
	{
		count +=split(ch);

	}
	fclose(fp);
	return count;
}
//统计单词数 
int getCount(char *name){
	FILE *fp;
	int count_char = 0;
	char ch;
	fp = fopen(name, "r");
	while((ch=fgetc(fp)) != EOF){
		count_char++;
	}
	fclose(fp);
	return count_char;
}



int main(int argc, char *argv[]){

	int count,char_count;
	//判断控制参数是否相等 
	if(strcmp(argv[1],"-c") == 0){
		count = getCount(argv[2]);
		printf("字符数：%d",count);
	}
	else if(strcmp(argv[1],"-w") == 0){
		count = getCountChar(argv[2]);
		printf("单词数：%d",count);
	}
	return 0;
}