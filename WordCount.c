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
		printf("�ļ���ʧ�ܣ������ԣ�\n");
		exit(1);
	}
	if (strcmp(t[1], "-c") == 0 || strcmp(t[1], "-C") == 0)
    {
		num = 0;
		while ((c = getc(fp)) != EOF)
        {
			num++;
		}
		printf("�ַ����� %d\n", num);
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
		printf("�������� %d\n", num+1);
	}
	else
    {
		printf("����ȷ���룺��ִ���ļ��� -w(-c) ��Ҫ�����ı��ļ���");
	}
	fclose(fp);
	return 0;
}
