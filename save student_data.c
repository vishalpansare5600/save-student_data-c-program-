#include<stdio.h>
#include<conio.h>
struct student
{
	char name[50];
	int roll ;
	int marks;
	
};
void main()
{
	struct student s[10];
	int i;
	
	
	printf("enter the info student=\n");
	for(i=0;i<=10;++i)
	{
		s[i].roll=i+1;
		printf("\nroll no%d\n ",s[i].roll);
		printf("enter the name");
		scanf("%d",s[i].name);
		printf("enter the marks");
		scanf("%d.s[i].marks");
		printf("\n");
	}
	printf("display information of student:\n\n");
	for(i=0;i<10;++i)
	{
		printf("information of roll no %d\n",i+1);
		printf("name"); 
		puts(s[i].name);
		printf("marks:%d",s[i].marks);
		
	}
	getch();
	
		
	}

