#include<string.h>
#include<stdio.h>
#include<stdlib.h>
# define size 100
int count[50],x=0,y;
char n[50];
char b[50];
int i,c;

struct node
{
    char name[size];
    int seats;
    int wt;  //waiting time
    struct node *next;

};
struct node *temp6,*temp5,*temp4,*temp2,*temp,*temp1,*newnode,*start=NULL;
void createnode()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the name with which you want to book\n");
    scanf("%s",&newnode->name);
    printf("Enter the number of seats you want to book\n");
    scanf("%d",&newnode->seats);
    newnode->wt=0;
    newnode->next=NULL;
}
void insert()
{
    createnode();
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        for(temp=start;temp->next!=NULL;temp=temp->next);
        temp->next=newnode;
    }
    y=newnode->seats;
    ++count[y];
    if(count[y]>1)
    {
        newnode->wt=newnode->wt+(count[y]-1)*15;
    }

}
void rem()
{
    printf("Enter the name\n");
    scanf("%s",&b);
    for(temp2=start;strcmp(temp2->name,b)!=0;temp2=temp2->next);
    c=temp2->seats;
    for(temp4=start;strcmp(temp4->next->name,b)!=0;temp4=temp4->next);
    temp4->next=temp2->next;
    temp2->next=NULL;
    free(temp2);
    for(temp5=temp4->next;temp5!=NULL;temp5=temp5->next)
    {
        if(temp5->seats==c)
        {
            temp5->wt=temp5->wt-15;
        }
    }

}
void display()
{
    printf("LIST OF PERSONS\n");
    for(temp1=start;temp1!=NULL;temp1=temp1->next)
    {
        printf("Name: %s\n",temp1->name);
        printf("Total number of seats booked: %d\n",temp1->seats);
        if(temp1->wt==0)
        {
            printf("you can go in now\n");
        }
        else
        {
            printf("Waiting time: %d\n",temp1->wt);
        }
    }

}
void query()
{
    printf("Enter the name you want to search for\n");
    scanf("%s",&n);
    for(temp6=start;strcmp(temp6->name,n);temp6=temp6->next);
    printf("Name: %s\n",temp6->name);
    printf("Total number of seats booked : %d\n",temp6->seats);
    printf("Waiting time : %d\n",temp6->wt);

}
int main()
{
    for(i=0;i<50;i++)
    {
        count[i]=0;
    }
    do
    {
        printf("*****THE jetking******\n");
        printf("Enter 1 to book a ticket\n");
        printf("Enter 2 to cancel a ticket\n");
        printf("Enter 3 for the query\n");
        printf("Enter 4 to display\n");
        printf("Enter 5 to exit\n");

        scanf("%d",&x);
        switch(x)
        {
            case 1:
                insert();
                break;
            case 2:
                rem();
                break;
            case 3:
                query();
                break;
            case 4:
                display();
                break;
        }
    }while(x!=5);
}
