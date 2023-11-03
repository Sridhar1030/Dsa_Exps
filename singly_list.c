

#include<stdio.h>
#include<stdlib.h>
struct node* create(int);
void display(struct node*);
struct node* insertatbeg(struct node*);
struct node* insertatmid(struct node*);
struct node* insertatend(struct node*);
struct node* delatbeg(struct node*);
struct node* delatmid(struct node*);
struct node* delatend(struct node*);
struct node
{
    int data;
    struct node *next;
};
int main() {
    struct node *Head = NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    Head = create(n);
    display(Head);

    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Middle\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at Middle\n");
        printf("6. Delete at End\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Head = insertatbeg(Head);
                display(Head);
                break;
            case 2:
                insertatmid(Head);
                display(Head);
                break;
            case 3:
                insertatend(Head);
                display(Head);
                break;
            case 4:
                Head = delatbeg(Head);
                display(Head);
                break;
            case 5:
                delatmid(Head);
                display(Head);
                break;
            case 6:
                delatend(Head);
                display(Head);
                break;
            case 7:
                display(Head);
                break;
            case 8:
               
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
struct node* create(int n)
{
    struct node *Head,*p; //address of next node
    int i;//data
    Head=(struct node *)malloc(sizeof(struct node));  //struct node* is explicit type caster  
    if (Head==NULL)
    {
        printf("Memory cannot be allocated");
    }
    else
    {
        printf("input data for node 1:");
        scanf("%d",&(Head->data));
        Head->next=NULL;
        p=Head;
        for(i=2;i<=n;i++)
        {
            p->next=(struct node *)malloc(sizeof(struct node)); //linking happens where the the address of new node gets stored in next field of linked list
            if( p->next==NULL)
            {
                printf("the memory cannot be allocated");
                break;
            }
            else
            {
           p=p->next;//p pointer shifts to new node 
            printf("Input data for node %d:",i);
            scanf("%d",&(p->data));
            } 
        }
        p->next=NULL;
    }
    return Head;
}
void display(struct node *Head)

{
    struct node *p;
    p=Head;
    printf("data stored in linked list are:\n");
    while (p!=NULL)
    {
        printf("\t %d\n",p->data);
        p=p->next;
    }
}
struct node* insertatbeg(struct node *Head)  
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter the element :\n");
    scanf("%d",&(p->data));
    p->next=Head;
    Head=p;
    return(Head);
}
struct node* insertatmid(struct node *Head)

  {
      struct node *Temp,*P;
      int key;
      P =(struct node*)malloc(sizeof(struct node));
      printf("enter the data and key : \n");
      scanf("%d%d",&(P->data),&key);
      Temp=Head;
      while((Temp !=NULL)&&key!=(Temp->data))
      {
        Temp=Temp->next;
      }
      if(Temp != NULL)
      {
        P->next=Temp->next;
        Temp->next=P;
      }
      
  }
struct node* insertatend(struct node *Head)
{
    struct node *Temp,*P;
    P=(struct node *)malloc(sizeof(struct node));
    printf("enter the data: \n");
    scanf("%d",&(P->data));
    Temp=Head;
    while(Temp->next !=NULL)
    {
        Temp=Temp->next;
    }
    Temp->next=P;
    P->next=NULL;
  
}
struct node* delatbeg(struct node *Head)

{
    struct node *Temp;
    Temp=Head;
    Head=Head->next;
    free(Temp);
    return(Head);

}
struct node* delatmid(struct node *Head)
{
    struct node *prev=Head,*target;
    int x;
    printf("enter the elemnt to be deleted");
    scanf("%d",&x);
    while(x!=((prev->next)->data)&&(prev->next)!=NULL)
    prev=prev->next;
    if(prev->next!=NULL)
    {
        target = prev->next;
        prev->next=prev->next->next;
    }
    free(target);
}
struct node* delatend(struct node *Head) {
    if (Head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (Head->next == NULL) {
        free(Head);
        return NULL;
    }

    struct node *temp = Head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return Head;
}
