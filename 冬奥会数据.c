#include <stdio.h>
#include <stdlib.h>
struct Olypic
{
	char name[100];
	int goldNum;
	int silverNum;
	int copperNum;
	int totalNum;
};
void bubbleSort(struct Olypic a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{

		for (int j = 0; j < n - 1; j++)
		{
			if (a[j].totalNum > a[j + 1].totalNum)
			{
				struct Olypic temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

main()
{
	FILE* fp = fopen("D:/demo2/file.txt", "r");
	if (fp == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	struct Olypic orm[8];
	for (int i = 0; i < 8; i++)
	{
		fscanf_s(fp, "%s\t%d\t%d\t%d\t%d\n", orm[i].name, 100, &orm[i].goldNum, &orm[i].silverNum, &orm[i].copperNum, &orm[i].totalNum);
	}

	fclose(fp);
	bubbleSort(orm, 8);
	FILE* outfp = fopen("D:/demo2/file_sorted.txt", "w");
	for (int i = 0; i < 8; i++)
	{
		fprintf(outfp, "%s\t%d\t%d\t%d\t%d\n", orm[i].name, orm[i].goldNum, orm[i].silverNum, orm[i].copperNum, orm[i].totalNum);
	}
	fclose(outfp);

	return 0;
}
