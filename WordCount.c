#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int a, char* t[])
{
	int c = 0;
	int num = 1;
	FILE* fp;
	if ((fp = fopen(t[2], "r")) == NULL)
    {
		printf("文件打开失败，请重试！\n");
		exit(1);
	}
	if (strcmp(t[1], "-c") == 0 || strcmp(t[1], "-C") == 0)
    {
		num = 0;
		while ((c = getc(fp)) != EOF)
        {
			num++;
		}
		printf("字符数： %d\n", num);
	}
	else if (strcmp(t[1], "-w") == 0 || strcmp(t[1], "-W") == 0)
    {
		while ((c = getc(fp)) != EOF)
        {
			if ((c == ' ') || (c == ','))
            {
				num++;
			}
		}
		printf("单词数： %d\n", num+1);
	}
	else
    {
		printf("请正确输入：可执行文件名 -w(-c) 需要处理文本文件名");
	}
	fclose(fp);
	return 0;
}
