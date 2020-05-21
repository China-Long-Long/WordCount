#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma warning(disable:4996)；
int main(int argc, char* argv[])   //命令行传参，argc代表传入参数个数，argv表示传入的参数
{
	
	char* a_in;  //用于保存从文件中读入的数据
	char c;
	int i;
	int count = 0;  //统计文件中字符个数
	int Word = 0;  //统计单词个数
	FILE* in1;  //用于指向文件地址



	if (argc < 3)   //判断输入参数个数，如果不为3个就报错
	{
		printf("参数个数错误");
		exit(1);
	}
	if (strcmp(argv[1], "-c") != 0 && strcmp(argv[1], "-w") != 0)   //判断输入参数个数
	{
		printf("参数错误");
		return -1;
	}

	in1 = fopen(argv[2], "r");   //打开文件，只读
	if (in1 == NULL)  //无法打开文件
	{
		printf("File cannot open! ");
		//exit;  
		return 0;
	}

	a_in = (char*)malloc(sizeof(char) * 100);  //动态内存分配
	if (!a_in)  //分配内存失败
	{
		printf("内存分配失败");
		return-1;
	}
	if (strcmp(argv[1], "-c") == 0)
	{

		while ((*(a_in) = fgetc(in1)) != EOF)  //只要未到文件末尾就继续读
		{

			count++;  //统计字符有多少个数
		}
		fclose(in1);  //关闭文件指针

		free(a_in);//释放第一维指针 

		//
		printf("字符个数为:%d\n", count);  //打印计数结果
		return 0;
	}
	else if (strcmp(argv[1], "-w") == 0)
	{
		while ((*(a_in) = fgetc(in1)) != EOF)  //只要未到文件末尾就继续
		{
			if (*(a_in) == '\n' || *(a_in) == ' ' || *(a_in) == ',')    //判断不是空格或换行就计数
			{
				Word++;
			}
		}
		fclose(in1);  //关闭文件指针

		free(a_in);//释放第一维指针 
		printf("单词个数为:%d\n", Word);  //打印计数结果
	}


	return 0;

}