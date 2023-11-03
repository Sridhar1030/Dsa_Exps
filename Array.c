
#include<conio.h>
#include<stdio.h>
int insert(int arr[]);
int dele(int arr[]) ;
int search(int arr[]);
int display(int arr[]);
int main()
{
int arr[50];
int k,i;
int u=0;
printf("Enter the elements");
for(i=0;i<5;i++)
{
    scanf("%d",&arr[i]);
}
while(u<=5)
{
printf(" 1->insertion \n 2-> deletion \n 3-> searching\n 4-> display\n 5-> exit \n");
scanf("%d",&k);
switch(k)
{
case 1: insert(arr);
break;
case 2: dele(arr)    ;
break;
case 3: search( arr)   ;
break;
case 4: display( arr)   ;
break;
case 5:
return 0;
break;
default :
printf("error");
break;
}
u++;
}
getch();
return 0;
}
int insert(int arr[])
{
  int a,k,j;
  printf("enter the position");
  scanf("%d",&a);
  printf("enter element");
  scanf("%d",&k);
  for(j=5;j>a;j--)
  {
  arr[j+1]=arr[j];
  }
  arr[a]=k;
  display(arr);
  return 0;
  }
int dele(int arr[])
{
 int pos,i;
 printf("Enter the position:");
 scanf("%d",&pos);
 for( i=pos;i<5;i++)
 {
     arr[i]=arr[i+1];
 }
 display(arr);
 return 0;
}


int display(int arr[])
{
int i;
for(i=0;i<5;i++)
{
 printf("%d",arr[i]);
 printf("\n");
}
return 0;
}
int search(int arr[])
{
int i,j;
printf("enter number to search");
scanf("%d",&i);
for (j=0;j<=5;j++)
{
   if( arr[j]=i)
   {
   printf("found");
   }
   else
   {
   printf("not found");
   }

return 0;
}

}