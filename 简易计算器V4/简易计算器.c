#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Dir(char c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-')return 1;
	else return 0;
}
void movedir(char* p)
{
	while (*p != '\0')
	{
		*p = *(p + 1);
		p++;
	}
}
void movecount(float* p, float* end)
{
	while (p != end)
	{
		*p = *(p + 1);
		p++;
	}
}
main()
{
	char str[] = "1-2.5*4+10.2/5.1";
	float strE[100];
	char dir[10] = "\0";
	int indexD = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (Dir(str[i]))
		{
			dir[indexD] = str[i];
			indexD++;
		}
	}//ÔËËã·û
	puts(dir);
	int indexE = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		char strM[100] = "\0";
		int indexM = 0;
		while (!Dir(str[i]))
		{
			strM[indexM] = str[i];
			i++;
			indexM++;
		}
		float Acon = atof(strM);
		strE[indexE++] = Acon;
	}


	char* dIr = dir;
	float* count = strE;
	while (*dIr != '\0')
	{
		if (*dIr == '*')
		{
			float left = *count;
			float right = *(count + 1);
			float sum = left * right;
			*count = sum;
			movedir(dIr);
			movecount(count + 1, &strE[indexE--]);
		}
		else if (*dIr == '/')
		{
			float left = *count;
			float right = *(count + 1);
			float sum = left / right;
			*count = sum;
			movedir(dIr);
			movecount(count + 1, &strE[indexE--]);
		}
		else
		{
			dIr++;
			count++;
		}
	}
	for (int i = 0; i < indexE; i++) 	printf("%.2lf\t\n", strE[i]);
	dIr = dir;
	count = strE;
	while (*dIr != '\0')
	{
		if (*dIr == '+')
		{
			float left = *count;
			float right = *(count + 1);
			float sum = left + right;
			*count = sum;
			movedir(dIr);
			movecount(count + 1, &strE[indexE--]);
		}
		else if (*dIr == '-')
		{
			float left = *count;
			float right = *(count + 1);
			float sum = left - right;
			*count = sum;
			movedir(dIr);
			movecount(count + 1, &strE[indexE--]);
		}

	}
	printf("%lf", strE[0]);
	return 0;
}