#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct employee
{
char name[100];
char salary[100];
char contact_no[11];
char ID[100];
struct employee *p;
};
struct employee *head=NULL;
struct employee *new1,*t1,*left;


void insertlast()
{
int x=1;
char contact_no[11];
t1=head;
new1=(struct employee*)malloc(sizeof(struct employee));
printf("Enter your ID\n");
scanf("%s",&new1->ID);
printf("enter the name of employee\n");
scanf("%s",&new1->name);
printf("enter the salary\n");
scanf("%s",&new1->salary);
fflush(stdin);
while(1)
{
	printf("\nEnter the contact number\n");
	gets(contact_no);
	x=strlen(contact_no);
	if(x!=10)
	{
		printf("Invalid number. Please enter again.");
	}
	else
	{
		strcpy(new1->contact_no,contact_no);
		break;
	}
}
new1->p=NULL;
if(head==NULL)
{
head=new1;
}
else
{
while(t1->p != NULL)
{
t1=t1->p;
}
t1->p=new1;
}
}

void deleteb()
{
char spnode[10];
t1=head;
printf("Enter the ID for deletion\n");
scanf("%s",&spnode);
if(strcmp(spnode,t1->ID)==0)
{
head=head->p;
free(t1);
}
else
{
left=t1;
t1=t1->p;
while(t1!=NULL)
{
if(strcmp(spnode,t1->ID)==0)
{
left->p=t1->p;
free(t1);
}
}
}
}

void count()
{
int count=0;
t1=head;
while(t1 != NULL)
{
t1=t1->p;
count++;
}
printf("No of employee is %d",count);
}


void search()
{
char spnode[100];
printf("Enter the ID to be searched\n");
scanf("%s",&spnode);
t1=head;
while(t1 != NULL)
{
t1=t1->p;
if(strcmp(t1->ID,spnode)==0);
{
printf("%s %s %s %s ",t1->ID,t1->name,t1->salary,t1->contact_no);
break;
}

}
}


void display()
{
t1=head;
printf(" ID\t Name \t salary \t Contact no.  \n");
printf("_________________________________________________________________\n");
if(t1->p==NULL)
{
printf(" %s \t  %s \t  %s \t %s \t \n",t1->ID,t1->name,t1->salary,t1->contact_no);
}
else
{
while(t1 != NULL)
{
printf(" %s  %s  %s  ",t1->ID,t1->name, t1->salary);
puts(t1->contact_no);
t1=t1->p;
}
}
}


void main()
{
int ch;
char c;
clrscr();
printf("****DS MINI PROJECT****\n");
printf("*****EMPLOYEE DATABASE*****\n");
do
{
printf("****MENU****\n 1.INSERT \n 2.DELETE  \n 3.COUNT \n 4.SEARCH \n 5.DISPLAY \n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{

case 1:
insertlast();
break;

case 2:
deleteb();
break;

case 3:
count();
break;

case 4:
search();
break;

case 5:
display();
break;

default:
printf("invalid choice\n");
}
printf("Do you want to continue Y/N ? \n");
c=getche();
}while(c=='y' || c=='Y');
getch();
}