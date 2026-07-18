#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student
{
int rollno;
char name[20];
float marks;
struct student *next;
}sll;



int k;

void add_begin(sll **);
void print_data(sll *);
void add_middle(sll **);
int count_node(sll *);
void add_end(sll **);
void delete_node(sll **);
int add_rollno(sll *);
void save_data(sll *);
void delete_all_node(sll **);
void reverse_list(sll **);
void sort_roll(sll *);
void sort_name(sll *);
void sort_marks(sll *);
void sort_list(sll *);
void modify_data(sll *);


void main()
{
	sll *head=0;
	int op,c;
	while(1)
	{
		printf("My dear! Enter your choise:\n");
		printf("1) add_begin 2) add_middle 3) add_end 4) delete_Kth_node 5) save_data 6) delete_all_node 7) print_data 8) count_node 9) reverse_list 10) sort_list 11) modify_data 12) exit\n");
		scanf("%d",&op);
	
		switch(op)
		{
			case 1: add_begin(&head);
				break;
			case 2: add_middle(&head);
				break;
			case 3: add_end(&head);
				break;
			case 4: delete_node(&head);
				break;
			case 5: save_data(head);
				break;
			case 6: delete_all_node(&head);
				break;
			case 7: print_data(head);
				break;
			case 8: c=count_node(head);
				printf("count=%d\n",c);
				break;
			case 9: reverse_list(&head);
				break;
			case 10:sort_list(head);
				break;
			case 12: exit(0);
                         case 11:
        modify_data(head);
        break;
		}
	}
}









void sort_roll(sll *head)
{
    sll *p, *q;
    sll temp;

    for (p = head; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->rollno > q->rollno)
            {
                temp.rollno = p->rollno;
                strcpy(temp.name, p->name);
                temp.marks = p->marks;

                p->rollno = q->rollno;
                strcpy(p->name, q->name);
                p->marks = q->marks;

                q->rollno = temp.rollno;
                strcpy(q->name, temp.name);
                q->marks = temp.marks;
            }
        }
    }
}










void sort_list(sll *ptr)
{
	int op;
	printf("Select the what you want\n");
	printf("1) sort based on rolno 2) sort based on name 3) sort based on marks");
	scanf("%d",&op);

	switch(op)
	{
		case 1: sort_roll(ptr);
			break;
		case 2: sort_name(ptr);
			break;
		case 3: sort_marks(ptr);
			break;
defualt : printf("unknown choise\n");
	}
}












void sort_marks(sll *head)
{
    sll *p, *q;
    sll temp;

    for (p = head; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->marks < q->marks)
            {
                temp.rollno = p->rollno;
                strcpy(temp.name, p->name);
                temp.marks = p->marks;

                p->rollno = q->rollno;
                strcpy(p->name, q->name);
                p->marks = q->marks;

                q->rollno = temp.rollno;
                strcpy(q->name, temp.name);
                q->marks = temp.marks;
            }
        }
    }
}











void sort_name(sll *head)
{
    sll *p, *q;
    sll temp;
    for (p = head; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (strcmp(p->name, q->name) > 0)
            {
                temp.rollno = p->rollno;
                strcpy(temp.name, p->name);
                temp.marks = p->marks;

                p->rollno = q->rollno;
                strcpy(p->name, q->name);
                p->marks = q->marks;

                q->rollno = temp.rollno;
                strcpy(q->name, temp.name);
                q->marks = temp.marks;
            }
        }
    }
}














void delete_all_node(sll **ptr)
{
    sll *temp;

    while (*ptr)
    {
        temp = *ptr;
        *ptr = (*ptr)->next;
        free(temp);
    }
}















void reverse_list(sll **head)
{
    sll *prev = NULL;
    sll *curr = *head;
    sll *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;   
        curr->next = prev;  
        prev = curr;         
        curr = next;         
    }

    *head = prev;            
}











void add_begin(sll **ptr)
{
	sll *p=*ptr;
	sll *n=malloc(sizeof(sll));
	n->rollno=add_rollno(p);
	printf("Enter a name and marks\n");
	scanf("%s %f",n->name,&n->marks);
	if(ptr==0)
	{
		*ptr=n;
		n->next=0;
	}
	else
	{
		n->next=*ptr;
		*ptr=n;
	}

}










void add_middle(sll **ptr)
{
	sll *d=*ptr;
	sll *q=*ptr;
	sll *p=*ptr;
	sll *n=malloc(sizeof(sll));
	n->rollno=add_rollno(d);
	printf("Enter a name and marks\n");
	scanf("%s %f",n->name,&n->marks);
	int c=count_node(d);
	c=c/2;
	while(--c)
	{
		q=q->next;
	}
	n->next=q->next;
	q->next=n;
}











void add_end(sll **ptr)
{
	sll *last=*ptr;
	sll *p=*ptr;
	sll *n=malloc(sizeof(sll));
	n->rollno=add_rollno(last);
	printf("Enter a name and marks\n");
	scanf("%s %f",n->name,&n->marks);
	while(last->next)
	{
		last=last->next;
	}
	last->next=n;
	n->next=0;
}











void delete_node(sll **ptr)
{
	int k;
	sll *n=*ptr;
	sll *p=*ptr;
	printf("Enter rollno\n");
	scanf("%d",&k);
	while(p)
	{
		if(p->rollno==k)
		{
			sll *del=p;
			if(p==*ptr)
			{
				*ptr=p->next;
				free(del);
				return;
			}
			else if(p->next==0)
			{
				n->next=0;
				free(del);
				return;
			}
			else
			{
				n->next=p->next;
				free(del);
				return;
			}
		}
		n=p;
		p=p->next;
	}
}











int add_rollno(sll *ptr)
{

	int l=1;
	sll *o=ptr;
	if(ptr==0)
		return l;

	while(1)
	{
		int f=0;
		ptr=o;
		while(ptr)
		{
			if(ptr->rollno==l)
			{
				f=1;
				break;
			}
			ptr=ptr->next;
		}
		if(f==0)
			return l;
		l++;
	}
}











void save_data(sll *ptr)
{
	if(ptr==0)
	{
		printf("no record present\n");
		return;
	}
	FILE *fp;
	fp=fopen("student.data","r+");
	while(ptr)
	{
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	printf("Data save in file\n");
	fclose(fp);
}











void print_data(sll *ptr)
{
	sll *p=ptr;
	while(p)
	{
		printf("%d %s %f\n",p->rollno,p->name,p->marks);
		p=p->next;
	}
}












int count_node(sll *ptr)
{
	int c=0;
	sll *n=ptr;
	while(n)
	{
		c++;
		n=n->next;
	}
	return c;
}

void modify_data(sll *head)
{
    if(head==NULL)
    {
        printf("No records found\n");
        return;
    }

    int choice;
    int roll;
    float marks;
    char name[20];
    int found=0;

    printf("\nModify Search By\n");
    printf("1. Name\n");
    printf("2. Marks\n");
    printf("Enter choice : ");
    scanf("%d",&choice);

    if(choice==1)
    {
        printf("Enter Name : ");
        scanf("%s",name);

        printf("\nMatching Records\n");
        printf("-----------------------------\n");

        sll *p=head;

        while(p)
        {
            if(strcmp(p->name,name)==0)
            {
                printf("Roll=%d  Name=%s  Marks=%.2f\n",
                        p->rollno,p->name,p->marks);
                found=1;
            }
            p=p->next;
        }

        if(found==0)
        {
            printf("No student found.\n");
            return;
        }
    }
    else if(choice==2)
    {
        printf("Enter Marks : ");
        scanf("%f",&marks);

        printf("\nMatching Records\n");
        printf("-----------------------------\n");

        sll *p=head;

        while(p)
        {
            if(p->marks==marks)
            {
                printf("Roll=%d  Name=%s  Marks=%.2f\n",
                        p->rollno,p->name,p->marks);
                found=1;
            }
            p=p->next;
        }

        if(found==0)
        {
            printf("No student found.\n");
            return;
        }
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }

    printf("\nEnter Roll Number to Modify : ");
    scanf("%d",&roll);

    sll *p=head;

    while(p)
    {
        if(p->rollno==roll)
        {
            printf("Current Data\n");
            printf("Roll=%d Name=%s Marks=%.2f\n",
                    p->rollno,p->name,p->marks);

            printf("Enter New Name and Marks : ");
            scanf("%s%f",p->name,&p->marks);

            printf("Record Modified Successfully.\n");
            return;
        }

        p=p->next;
    }

    printf("Roll Number not found.\n");
}

















