/******************************************************************************

      This code is developed by Dr R. K. SELVAKUMAR, PROFESSOR/CSE   
    CVR COLLEGE OF ENGINEERING, HYDERABAD
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node {
    int data;
    struct Node* next;
}*Ptr;

Ptr Create()
{
    /* It creeates the dummy node and return the address is head node address */
    Ptr head =  malloc(sizeof(struct Node));
    head->next=NULL;
    return head;
}

int Length(Ptr p)
{
    /* This function return the length of the linked list which is the number
       of elements in the singly linked list */
    
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
    /* Find function locate the position of search element and return the prev node address. If the data 
       is not present it return NULL address*/
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

void Insert(Ptr p, int pos,int elt)
{
    /* This function insert a data in a specific valid position in the available linked list */
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



Ptr Reverse(Ptr p)
{
    /* This function create a reverse linked list without affecting orginal list and return the new pointer  */
    Ptr Temp,RPointer;
    int pos=1;
    RPointer = Create();
    
    Temp=p->next;
    while (Temp!=NULL)
    {
        Insert(RPointer, 1, Temp->data);
        Temp = Temp->next;
    }
    return RPointer;
    
}



void Remove(Ptr p, int elt)
{
    /* This function find the specific data in the linked list and remove the element in the list*/
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



void Display(Ptr p)
{
    /* This function print the data in the linked list*/
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
   Ptr Pointer,ptr1,ptr2;
   int opt=1, elt,pos;
   while (opt<7)
   {   
       Menu();
       printf("\n Select the option<1...6> :");
       scanf("%d",&opt);
       switch (opt)
       {
         case 1: 
                    Pointer=Create();
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
                    ptr2=Reverse(Pointer);
                    Display(ptr2);
                    getchar();
                    break;
         case 6: 
                    Display(Pointer);
                    getchar();
                    break; 
         default :
                    printf("\n Exit");
                    break;
          
       }
   }
   
    return(0);
}
