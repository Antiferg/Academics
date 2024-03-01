#include<stdio.h>
#include<stdlib.h>
typedef struct Linked_list
{
    int data;
    struct Linked_list *link;
}node;

node* head=NULL;

node* create_node()
{
    node *temp =(node*)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return temp;
}

void values(int Data)
{
    node* newnode=create_node();
    node* temp;
    newnode->data=Data;
    newnode->link=NULL;
    temp=head;
    if(head==NULL)
    {
        head=newnode;
        return ;
    }
    else
    {
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=newnode;
    }
}

void insert(int pos)
{
    node *temp,*prev,*newnode=(node*)malloc(sizeof(node));
    int count=1,Data;
    
    printf("Enter data:");
    scanf("%d",&Data);
    newnode->data=Data;
    newnode->link=NULL;
    temp=head;
    if(pos==1)
    {
        newnode->link=head;
        head=newnode;
        return ;
    }
    else
    {
        while ((temp->link!=NULL) && (count<pos))
        {
            prev=temp;
            temp=temp->link;
            count++;
        }
        if(count+1==pos)
        {
            temp->link=newnode;
            return ;
        }
        else
        {
            printf("Segment error!!");
            return ;
        }
    }
    prev->link=newnode;
    newnode->link=temp;
}

void delete(int pos)
{
    node *temp,*prev;
    int count=1;
    temp=head;
    if(pos==1)
    {
        head=head->link;
        free(temp);
        return ;
    }
    else
    {
        while((temp->link!=NULL) && (count<pos))
        {
            prev=temp;
            temp=temp->link;
            count++;
        }
        if (temp->link == NULL)
        {
            prev->link = NULL;
            free(temp);
            return ;
        }
        prev->link=temp->link;
        free(temp);
    }
}

void display()
{
    node* temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}

int main()
{   
    int check=1,Data,insert_pos;  
    while(check)
    {
        printf("Enter data:");
        scanf("%d",&Data);
        values(Data);
        printf("Want to continue?:");
        scanf("%d",&check);
    }
    printf("delete in what postion:");
    scanf("%d",&insert_pos);
    //insert(insert_pos);
    delete(insert_pos);
    display();
    return 0;
}