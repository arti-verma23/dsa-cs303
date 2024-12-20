//Program Description: Implementation of Linked List using array. 
//Solution: 
#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 
#define MAX 10  
 
struct 
{ 
    int list[MAX]; 
    int element;      
    int pos;            
    int length;      
}; 
enum boolean 
{ 
    true, false 
}; 
typedef enum boolean boolean;         
 
int menu(void);          
 
 
void create(void);        
void insert(int, int);      
void delet(int);        
void find(int);         
void display(void);        
boolean islistfull(void);   
boolean islistempty(void);          
 
int menu() 
{ 
    int ch; 
    //clrscr(); 
    printf("1. Create\n2. Insert\n3. Delete\n4. Count\n5. Find\n6. 
Display\n7.Exit\n\n Enter your choice : "); 
    scanf("%d", &ch); 
    printf("\n\n"); 
    return ch; 
}       

void create(void) 
{ 
    int element; 
    int flag=1; 
    while(flag==1) 
    { 
        printf("Enter element : "); 
        scanf("%d", &element); 
        l.list[l.length] = element; 
        l.length++; 
        printf("To insert another element press '1' : "); 
        scanf("%d", &flag); 
    } 
}      
void display(void) 
{ 
    int i; 
    for (i=0; i<l.length; i++) 
        printf("Element %d : %d \n", i+1, l.list[i]); 
    printf("Press any key to continue..."); 
    getch(); 
}   
void insert(int element, int pos) 
{ 
    int i; 
    if (pos == 0) 
    { 
        printf("\nCannot insert an element at 0th position"); 
        getch(); 
        return; 
    } 
 
    if (pos-1 > l.length) 
    { 
        printf("\nOnly %d elements exit. Cannot insert at %d 
position", l.length, pos); 
        printf("\n Press any key to continue..."); 
        getch(); 
    } 
    else 
    { 
        for (i=l.length; i>=pos-1; i--) 
        { 
            l.list[i+1] = l.list[i]; 
        } 
        l.list[pos-1] = element; 
        l.length++; 
    } 
}      
void delet(int pos) 
{ 
    int i; 
    if(pos == 0) 
    { 
        printf("\nCannot delete at an element 0th position"); 
        getch(); 
        return; 
    } 
    if (pos > l.length) 
    { 
        printf("\n\n Only %d elements exit. Cannot delete", 
l.length, pos); 
        printf("\n Press any key to continue..."); 
        getch(); 
        return; 
    } 
    for (i=pos-1; i<l.length; i++) 
    { 
        l.list[i] = l.list[i+1]; 
    } 
    l.length--; 
}       
 
void find(int element) 
{ 
    int i; 
    int flag = 1; 
 
    for (i=0; i<l.length; i++) 
    { 
        if(l.list[i] == element) 
        { 
            printf ("%d exists at %d position",element, i+1); 
            flag = 0; 
            printf("\n Press any key to continue..."); 
            getch(); 
            break; 
        } 
    } 
    if(flag == 1) 
    { 
        printf("Element not found.\n Press any key to continue..."); 
        getch(); 
    } 
}   
boolean islistfull(void) 

{ 
    if (l.length == MAX) 
        return true; 
    else 
        return false; 
}    
boolean islistempty(void) 
{ 
    if (l.length == 0) 
        return true; 
    else 
        return false; 
} 
 
int main() 
{ 
    int ch; 
    int element; 
    int pos; 
    l.length = 0; 
    while(1) 
    { 
        ch = menu(); 
        switch (ch) 
        { 
             case 1:   l.length = 0; 
             create(); 
             break; 
             case 2: 
             if (islistfull() != true) 
             { 
                  printf("Enter New element: "); 
                  scanf("%d", &element); 
                  printf("Enter the Position : "); 
                  scanf("%d", &pos); 
                  insert(element, pos); 
             } 
             else 
             { 
                  printf("List is Full. Cannot insert the element"); 
                  printf("\n Press any key to continue..."); 
                  getch(); 
             } 
             break; 
             case 3: 
             if (islistempty() != true) 
             { 
                  printf("Enter the position of element to be 
deleted : "); 
                  scanf("%d", &pos); 
                  delet(pos); 
             } 
             else 
             { 
                  printf("List is Empty."); 
                  printf("\n Press any key to continue..."); 
                  getch(); 
             } 
             break; 
             case 4: 
             printf("No of elements in the list is %d", l.length); 
             printf("\n Press any key to continue..."); 
             getch(); 
             break; 
             case 5: 
             printf("Enter the element to be searched : "); 
             scanf("%d", &element); 
             find(element); 
             break; 
             case 6: 
             display(); 
             break; 
             case 7: 
             printf("Exit"); 
             exit(0); 
             break; 
             default:  printf("Invalid Choice"); 
             printf("\n Press any key to continue..."); 
             getch(); 
        } 
    } 
}        //function to display the list of elements 







//Practical No.: 2 
//Program Description: Implementation of Linked List using pointers. 
Solution: 
#include<stdio.h> 
#include<stdlib.h> 
struct Node; 
typedef struct Node * PtrToNode; 
typedef PtrToNode List; 
typedef PtrToNode Position; 
  
struct Node 
{ 
    int e; 
    Position next; 
}; 
  
void Insert(int x, List l, Position p) 
{ 
    Position TmpCell; 
    TmpCell = (struct Node*) malloc(sizeof(struct Node)); 
    if(TmpCell == NULL) 
        printf("Memory out of space\n"); 
    else 
    { 
        TmpCell->e = x; 
        TmpCell->next = p->next; 
        p->next = TmpCell; 
    } 
} 
  
int isLast(Position p) 
{ 
    return (p->next == NULL); 
} 
  
Position FindPrevious(int x, List l) 
{ 
    Position p = l; 
    while(p->next != NULL && p->next->e != x) 
        p = p->next; 
    return p; 
} 
  
void Delete(int x, List l) 
{ 
    Position p, TmpCell; 
    p = FindPrevious(x, l); 
  
    if(!isLast(p)) 
    { 
        TmpCell = p->next; 
        p->next = TmpCell->next; 
        free(TmpCell); 
    } 
    else 
        printf("Element does not exist!!!\n"); 
} 
  
void Display(List l) 
{ 
    printf("The list element are :: "); 
    Position p = l->next; 
    while(p != NULL) 
    { 
        printf("%d -> ", p->e); 
        p = p->next; 
    } 
} 
  
void Merge(List l, List l1) 
{ 
    int i, n, x, j; 
    Position p; 
    printf("Enter the number of elements to be merged :: "); 
    scanf("%d",&n); 
  
    for(i = 1; i <= n; i++) 
    { 
        p = l1; 
        scanf("%d", &x); 
        for(j = 1; j < i; j++) 
            p = p->next; 
        Insert(x, l1, p); 
    } 
    printf("The new List :: "); 
    Display(l1); 
    printf("The merged List ::"); 
    p = l; 
    while(p->next != NULL) 
    { 
        p = p->next; 
    } 
    p->next = l1->next; 
    Display(l); 

} 
  
  
int main() 
{ 
    int x, pos, ch, i; 
    List l, l1; 
    l = (struct Node *) malloc(sizeof(struct Node)); 
    l->next = NULL; 
    List p = l; 
    printf("LINKED LIST IMPLEMENTATION OF LIST ADT\n\n"); 
    do 
    { 
        printf("\n\n1. INSERT\t 2. DELETE\t 3. MERGE\t 4. PRINT\t 5. 
QUIT\n\nEnter the choice :: "); 
        scanf("%d", &ch); 
        switch(ch) 
        { 
        case 1: 
            p = l; 
            printf("Enter the element to be inserted :: "); 
            scanf("%d",&x); 
            printf("Enter the position of the element :: "); 
            scanf("%d",&pos); 
  
            for(i = 1; i < pos; i++) 
            { 
                p = p->next; 
            } 
            Insert(x,l,p); 
            break; 
  
        case 2: 
            p = l; 
            printf("Enter the element to be deleted :: "); 
            scanf("%d",&x); 
            Delete(x,p); 
            break; 
  
        case 3: 
            l1 = (struct Node *) malloc(sizeof(struct Node)); 
            l1->next = NULL; 
            Merge(l, l1); 
            break; 
  
        case 4: 
            Display(l); 
            break; 
} 
} 
while(ch<5); 
return 0; 
} 
 





//Practical No.: 3 
//Program Description: Implementation of Doubly Linked List using Pointers 
//Solution: 
#include<stdio.h>   
#include<stdlib.h>   
struct node   
{   
    struct node *prev;   
    struct node *next;   
    int data;   
};   
struct node *head;   
void insertionFirst();   
void insertionLast();   
void insertionLoc();   
void deleteFirst();   
void deleteLast();   
void deleteLoc();   
void printList();   
void searchList();   
int main()   
{   
    int choice =0;   
    while(choice != 9)   
    {   
        printf("\nDoubly Linked ListMenu\n");     
        printf("\n1.Insert at begining\n"); 
        printf("2.Insert at last\n"); 
        printf("3.Insert at any random location\n"); 
        printf("4.Delete from Beginning\n"); 
        printf("5.Delete from last\n"); 
        printf("6.Delete the node after the given data\n"); 
        printf("7.Search\n"); 
        printf("8.Show\n"); 
        printf("9.Exit\n");   
        printf("\nEnter your choice?\n");   
        scanf("\n%d",&choice);   
        switch(choice)   
        {   
            case 1:   
                insertionFirst();   
                break;   
            case 2:   
                insertionLast();   
                break;   
            case 3:   

                insertionLoc();   
                break;   
            case 4:   
                deleteFirst();   
                break;   
            case 5:   
                deleteLast();   
                break;   
            case 6:   
                deleteLoc();   
                break;   
            case 7:   
                searchList();   
                break;   
            case 8:   
                printList();   
                break;   
            case 9:   
                exit(0);   
                break;   
            default:   
                printf("Invalid Choice!!! Please try again....");   
        }   
    }   
    return 0; 
}   
void insertionFirst()   
{   
   struct node *ptr;    
   int item;   
   ptr = (struct node *)malloc(sizeof(struct node));   
   if(ptr == NULL)   
   {   
       printf("\nOVERFLOW!!!");   
   }   
   else   
   {   
    printf("\nEnter value to insert: ");   
    scanf("%d",&item);   
       
   if(head==NULL)   
   {   
       ptr->next = NULL;   
       ptr->prev=NULL;   
       ptr->data=item;   
       head=ptr;   
   }   
   else    
 
   {   
       ptr->data=item;   
       ptr->prev=NULL;   
       ptr->next = head;   
       head->prev=ptr;   
       head=ptr;   
   }   
   printf("\nNode inserted successfully....\n");   
}   
      
}   
void insertionLast()   
{   
   struct node *ptr,*temp;   
   int item;   
   ptr = (struct node *) malloc(sizeof(struct node));   
   if(ptr == NULL)   
   {   
       printf("\nOVERFLOW!!!");   
   }   
   else   
   {   
       printf("\nEnter value to insert: ");   
       scanf("%d",&item);   
        ptr->data=item;   
       if(head == NULL)   
       {   
           ptr->next = NULL;   
           ptr->prev = NULL;   
           head = ptr;   
       }   
       else   
       {   
          temp = head;   
          while(temp->next!=NULL)   
          {   
              temp = temp->next;   
          }   
          temp->next = ptr;   
          ptr ->prev=temp;   
          ptr->next = NULL;   
          }   
              
       }   
     printf("\nNode inserted successfully\n");   
    }   
void insertionLoc()   
{   
 
   struct node *ptr,*temp;   
   int item,loc,i;   
   ptr = (struct node *)malloc(sizeof(struct node));   
   if(ptr == NULL)   
   {   
       printf("\n OVERFLOW!!!");   
   }   
   else   
   {   
       temp=head;   
       printf("Enter the location: ");   
       scanf("%d",&loc);   
       for(i=0;i<loc;i++)   
       {   
           temp = temp->next;   
           if(temp == NULL)   
           {   
               printf("\nThere are less than %d elements\n", loc);   
               return;   
           }   
       }   
       printf("Enter value: ");   
       scanf("%d",&item);   
       ptr->data = item;   
       ptr->next = temp->next;   
       ptr -> prev = temp;   
       temp->next = ptr;   
       temp->next->prev=ptr;   
       printf("\nNode inserted successfully...\n");   
   }   
}   
void deleteFirst()   
{   
    struct node *ptr;   
    if(head == NULL)   
    {   
        printf("\nUNDERFLOW!!!");   
    }   
    else if(head->next == NULL)   
    {   
        head = NULL;    
        free(head);   
        printf("\nNode deleted successfully....\n");   
    }   
    else   
    {   
        ptr = head;   
        head = head -> next;   
        head -> prev = NULL;   
        free(ptr);   
        printf("\nNode deleted successfully....\n");   
    }   
   
}   
void deleteLast()   
{   
    struct node *ptr;   
    if(head == NULL)   
    {   
        printf("\nUNDERFLOW!!!");   
    }   
    else if(head->next == NULL)   
    {   
        head = NULL;    
        free(head);    
        printf("\nNode deleted successfully...\n");   
    }   
    else    
    {   
        ptr = head;    
        if(ptr->next != NULL)   
        {   
            ptr = ptr -> next;    
        }   
        ptr -> prev -> next = NULL;    
        free(ptr);   
        printf("\nNode deleted successfully...\n");   
    }   
}   
void deleteLoc()   
{   
    struct node *ptr, *temp;   
    int val;   
    printf("\nEnter the data after which the node is to be deleted : 
");   
    scanf("%d", &val);   
    ptr = head;   
    while(ptr -> data != val)   
    ptr = ptr -> next;   
    if(ptr -> next == NULL)   
    {   
        printf("\nCan't delete....\n");   
    }   
    else if(ptr -> next -> next == NULL)   
    {   
        ptr ->next = NULL;   

    }   
    else   
    {    
        temp = ptr -> next;   
        ptr -> next = temp -> next;   
        temp -> next -> prev = ptr;   
        free(temp);   
        printf("\nNode deleted successfully...\n");   
    }      
}   
void printList()   
{   
    struct node *ptr;   
    printf("\nThe Doubly Linked List is\nSTART %c ",29);   
    ptr = head;   
    while(ptr != NULL)   
    {   
        printf("%d %c ",ptr->data,29);   
        ptr=ptr->next;   
    }   
    printf("NULL\n\n"); 
}    
void searchList()   
{   
    struct node *ptr;   
    int item,i=0,flag;   
    ptr = head;    
    if(ptr == NULL)   
    {   
        printf("\nEmpty List\n");   
    }   
    else   
    {    
        printf("\nEnter item which you want to search?\n");    
        scanf("%d",&item);   
        while (ptr!=NULL)   
        {   
            if(ptr->data == item)   
            {   
                printf("\nItem %d found at location %d ",item, 
i+1);   
                flag=0;   
                break;   
            }    
            else   
            {   
                flag=1;   
            }   
            i++;   
            ptr = ptr -> next;   
        }   
        if(flag==1)   
        {   
            printf("\nItem %d not found\n",item);   
        }   
    }      
           
}   
 
 






//Practical No.: 4 
//Program Description: Implementation of Circular Single Linked List using Pointers. 
//Solution: 
#include<stdio.h> 
#include<stdlib.h> 
struct Node; 
typedef struct Node * PtrToNode; 
typedef PtrToNode List; 
typedef PtrToNode Position; 
  
struct Node 
{ 
    int e; 
    Position next; 
}; 
  
void Insert(int x, List l, Position p) 
{ 
    Position TmpCell; 
    TmpCell = (struct Node*) malloc(sizeof(struct Node)); 
    if(TmpCell == NULL) 
        printf("Memory out of space\n"); 
    else 
    { 
        TmpCell->e = x; 
        TmpCell->next = p->next; 
        p->next = TmpCell; 
    } 
} 
  
  
int isLast(Position p, List l) 
{ 
    return (p->next == l); 
} 
  
Position FindPrevious(int x, List l) 
{ 
    Position p = l; 
    while(p->next != l && p->next->e != x) 
        p = p->next; 
    return p; 
} 
  
Position Find(int x, List l) 
{ 

    Position p = l->next; 
    while(p != l && p->e != x) 
        p = p->next; 
    return p; 
} 
  
void Delete(int x, List l) 
{ 
    Position p, TmpCell; 
    p = FindPrevious(x, l); 
    if(!isLast(p, l)) 
    { 
        TmpCell = p->next; 
        p->next = TmpCell->next; 
        free(TmpCell); 
    } 
    else 
        printf("Element does not exist!!!\n"); 
} 
  
void Display(List l) 
{ 
    printf("The list element are :: "); 
    Position p = l->next; 
    while(p != l) 
    { 
        printf("%d -> ", p->e); 
        p = p->next; 
    } 
} 
  
int main() 
{ 
    int x, pos, ch, i; 
    List l, l1; 
    l = (struct Node *) malloc(sizeof(struct Node)); 
    l->next = l; 
    List p = l; 
    printf("CIRCULAR LINKED LIST IMPLEMENTATION OF LIST ADT\n\n"); 
    do 
    { 
        printf("\n\n1. INSERT\t 2. DELETE\t 3. FIND\t 4. PRINT\t 5. 
QUIT\n\nEnter the choice :: "); 
        scanf("%d", &ch); 
        switch(ch) 
        { 
            case 1: 
                p = l; 
                printf("Enter the element to be inserted :: "); 
                scanf("%d",&x); 
                printf("Enter the position of the element :: "); 
                scanf("%d",&pos); 
                for(i = 1; i < pos; i++) 
                { 
                    p = p->next; 
                } 
                Insert(x,l,p); 
                break; 
  
            case 2: 
                p = l; 
                printf("Enter the element to be deleted :: "); 
                scanf("%d",&x); 
                Delete(x,p); 
                break; 
  
            case 3: 
                p = l; 
                printf("Enter the element to be searched :: "); 
                scanf("%d",&x); 
                p = Find(x,p); 
                if(p == l) 
                    printf("Element does not exist!!!\n"); 
                else 
                    printf("Element exist!!!\n"); 
                break; 
  
            case 4: 
                Display(l); 
                break; 
        } 
    }while(ch<5); 
    return 0; 
} 








//Practical No.: 5 
//Program Description: Implementation of Circular Doubly Linked List using Pointers. 
//Solution: 
#include<stdio.h>   
#include<stdlib.h>   
struct node   
{   
    struct node *prev;   
    struct node *next;   
    int data;   
};   
struct node *head;   
void insertion_beginning();   
void insertion_last();   
void deletion_beginning();   
void deletion_last();   
void display();   
void search();   
int main ()   
{   
int choice =0;   
    while(choice != 9)   
    {   
        printf("\n*********Main Menu*********\n");   
        printf("\nChoose one option from the following list 
...\n");   
        printf("\n===============================================\n"
 );   
        printf("\n1.Insert in Beginning\n2.Insert at last\n3.Delete 
from Beginning\n4.Delete from last\n5.Search\n6.Show\n7.Exit\n");   
        printf("\nEnter your choice?\n");   
        scanf("\n%d",&choice);   
        switch(choice)   
        {   
            case 1:   
            insertion_beginning();   
            break;   
            case 2:   
                    insertion_last();   
            break;   
            case 3:   
            deletion_beginning();   
            break;   
            case 4:   
            deletion_last();   
            break;   
            case 5:   
            search();   
            break;   
            case 6:   
            display();   
            break;   
            case 7:   
            exit(0);   
            break;   
            default:   
            printf("Please enter valid choice..");   
        }   
    }   
}   
void insertion_beginning()   
{   
   struct node *ptr,*temp;    
   int item;   
   ptr = (struct node *)malloc(sizeof(struct node));   
   if(ptr == NULL)   
   {   
       printf("\nOVERFLOW");   
   }   
   else   
   {   
    printf("\nEnter Item value");   
    scanf("%d",&item);   
    ptr->data=item;   
   if(head==NULL)   
   {   
      head = ptr;   
      ptr -> next = head;    
      ptr -> prev = head;    
   }   
   else    
   {   
       temp = head;    
    while(temp -> next != head)   
    {   
        temp = temp -> next;    
    }   
    temp -> next = ptr;   
    ptr -> prev = temp;   
    head -> prev = ptr;   
    ptr -> next = head;   
    head = ptr;   
   }   
   printf("\nNode inserted\n");   
 
 
 
}   
      
}   
void insertion_last()   
{   
   struct node *ptr,*temp;   
   int item;   
   ptr = (struct node *) malloc(sizeof(struct node));   
   if(ptr == NULL)   
   {   
       printf("\nOVERFLOW");   
   }   
   else   
   {   
       printf("\nEnter value");   
       scanf("%d",&item);   
        ptr->data=item;   
       if(head == NULL)   
       {   
           head = ptr;   
           ptr -> next = head;    
           ptr -> prev = head;    
       }   
       else   
       {   
          temp = head;   
          while(temp->next !=head)   
          {   
              temp = temp->next;   
          }   
          temp->next = ptr;   
          ptr ->prev=temp;   
          head -> prev = ptr;   
      ptr -> next = head;   
        }   
   }   
     printf("\nnode inserted\n");   
}   
   
void deletion_beginning()   
{   
    struct node *temp;   
    if(head == NULL)   
    {   
        printf("\n UNDERFLOW");   
    }   
    else if(head->next == head)   
    {   
        head = NULL;    
        free(head);   
        printf("\nnode deleted\n");   
    }   
    else   
    {   
        temp = head;    
        while(temp -> next != head)   
        {   
            temp = temp -> next;   
        }   
        temp -> next = head -> next;   
        head -> next -> prev = temp;   
        free(head);   
        head = temp -> next;   
    }   
   
}   
void deletion_last()   
{   
    struct node *ptr;   
    if(head == NULL)   
    {   
        printf("\n UNDERFLOW");   
    }   
    else if(head->next == head)   
    {   
        head = NULL;    
        free(head);    
        printf("\nnode deleted\n");   
    }   
    else    
    {   
        ptr = head;    
        if(ptr->next != head)   
        {   
            ptr = ptr -> next;    
        }   
        ptr -> prev -> next = head;   
        head -> prev = ptr -> prev;     
        free(ptr);   
        printf("\nnode deleted\n");   
    }   
}   
   
void display()   
{   
    struct node *ptr;   
 
    ptr=head;   
    if(head == NULL)   
    {   
        printf("\nnothing to print");   
    }      
    else   
    {   
        printf("\n printing values ... \n");   
           
        while(ptr -> next != head)   
        {   
           
            printf("%d\n", ptr -> data);   
            ptr = ptr -> next;   
        }   
        printf("%d\n", ptr -> data);   
    }   
               
}   
   
void search()   
{   
    struct node *ptr;   
    int item,i=0,flag=1;   
    ptr = head;    
    if(ptr == NULL)   
    {   
        printf("\nEmpty List\n");   
    }   
    else   
    {    
        printf("\nEnter item which you want to search?\n");    
        scanf("%d",&item);   
        if(head ->data == item)   
        {   
        printf("item found at location %d",i+1);   
        flag=0;   
        }   
        else    
        {   
        while (ptr->next != head)   
        {   
            if(ptr->data == item)   
            {   
                printf("item found at location %d ",i+1);   
                flag=0;   
                break;   
            }    
 
 
 