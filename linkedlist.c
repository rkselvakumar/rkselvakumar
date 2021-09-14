
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



typedef struct Node {
    int data;
    struct Node* next;
}*Ptr;

int Length(Ptr p)
{
    Ptr Temp;
   
     int count=0;
     Temp=p->next;
    while (Temp!=NULL)
    {
        count++;
        Temp = Temp->next;
    }
    return count;
    
}

Ptr Find(Ptr p, int elt)
{
    Ptr Temp,Prev;
    int pos=1;
     Prev=p;
     Temp=p->next;
    while (Temp!=NULL)
    {
        if (Temp->data==elt)
        {
            printf("Search data is located at %d position",pos);
            return Prev;
        }
        Prev=Temp;
        Temp = Temp->next;
        pos++;
    }
    return NULL;
    
}

void Remove(Ptr p, int elt)
{
    Ptr Prev=Find(p,elt);
    Ptr Temp;
    if (Prev==NULL)
        printf("\nYour data is not present in the list");
        else
        {
           Temp=Prev->next;
           Prev->next=Temp->next;
           free(Temp);
           printf("\nYour data is successfully removed in the list"); 
        }
}

void Insert(Ptr p, int pos,int elt)
{
    Ptr T = malloc(sizeof(struct Node));
    Ptr S,Temp;
    int count=0;
    
   if (pos<1 || pos > Length(p)+1)
   {
       printf("\n Insertion position is not valid");
       getch();
   }
   else
   {
       T->data =elt;
       Temp=p->next;
       S=p;
       while (count<pos-1 && Temp!=NULL)
       {
          count++;
          S=Temp;
          Temp = Temp->next; 
       }
       T->next=Temp;
       S->next=T;
   }
   
}

Ptr Create()
{
    Ptr head =  malloc(sizeof(struct Node));
    head->next=NULL;
    return head;
}

void Display(Ptr p)
{
    Ptr Temp;
    Temp=p->next;
    while (Temp!=NULL)
    {
        printf("%d\t",Temp->data);
        Temp = Temp->next;
    } 
}

void Menu()
{
    printf("\n MAIN MENU");
    printf("\n 1. Create");
    printf("\n 2. Insert");
    printf("\n 3. Remove");
    printf("\n 4. Find");
    printf("\n 5. Reverse");
    printf("\n 6. Print");
    printf("\n 7. Quit");
    
}

int main()
{
   Ptr Pointer,ptr1;
   int opt=1, elt,pos;
   while (opt<7)
   {   
       getch();
       Menu();
       printf("\n Select the option<1...6> :");
       scanf("%d",&opt);
       switch (opt)
       {
         case 1: Pointer=Create();
             break;
         case 2:
             printf("\n Enter the position and data :");
             scanf("%d%d",&pos,&elt);
             Insert(Pointer,pos,elt);
             break;
         case 3:
              printf("\n Enter the data to remove :");
              scanf("%d",&elt);
              Remove(Pointer, elt);
              break;
         case 4: 
              printf("\n Enter the data to find :");
              scanf("%d",&elt);
              ptr1=Find(Pointer, elt);
             break;
         case 5:
                 
                 break;
         case 6: Display(Pointer);
                 getch();
                 break; 
         default :
            break;
          
       }
   }
   
    return(0);
}
