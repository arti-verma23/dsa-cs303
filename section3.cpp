//Practical No.: 1 
//Program Description: Implementation of Queue using Array. 
//Solution: 
#include<stdio.h> 
#define n 5 
int main() 
{ 
    int queue[n],ch=1,front=0,rear=0,i,j=1,x=n; 
    printf("Queue using Array"); 
    printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit"); 
    while(ch) 
    { 
        printf("\nEnter the Choice:"); 
        scanf("%d",&ch); 
        switch(ch) 
        { 
        case 1: 
            if(rear==x) 
                printf("\n Queue is Full"); 
            else 
            { 
                printf("\n Enter no %d:",j++); 
                scanf("%d",&queue[rear++]); 
            } 
            break; 
        case 2: 
            if(front==rear) 
            { 
                printf("\n Queue is empty"); 
            } 
            else 
            { 
                printf("\n Deleted Element is %d",queue[front++]); 
                x++; 
            } 
            break; 
        case 3: 
            printf("\nQueue Elements are:\n "); 
            if(front==rear) 
                printf("\n Queue is Empty"); 
            else 
            { 
                for(i=front; i<rear; i++) 
                { 
                    printf("%d",queue[i]); 
                    printf("\n"); 
                } 
                break; 
            case 4: 
                exit(0); 
            default: 
                printf("Wrong Choice: please see the options"); 
            } 
        } 
    } 
    return 0; 
} 
 
 
 




//Practical No.: 2 
//Program Description: Implementation of queue using pointers. 
//Solution: 
#include<stdio.h> 
#include<malloc.h> 
typedef struct queue 
{  
    int data; 
    struct queue *next; 
}NODE; 
      
NODE * insert(NODE *rear,int data) 
{    
    NODE *temp; 
    temp=(NODE*)malloc(sizeof(NODE)); 
    temp->data=data; 
    temp->next=NULL; 
    if(rear==NULL) 
    {  
       rear=temp; 
    }  
    else 
    {  
       rear->next=temp; 
       rear=temp;    
         
    } 
}    
          
NODE* delete(NODE*front) 
{    
    NODE *temp; 
    if(front==NULL) 
    {  
        printf("Queue is empty\n"); 
    } 
    else 
    {  
        temp=front; 
        front=front->next; 
        free(temp); 
    }  
    return(front);   
} 
          
void display(NODE *front) 
 
 
 Arti Verma(0902cs231023)  38 
{  
    NODE *t; 
    if(front==NULL) 
   { 
        printf("Queue is empty\n"); 
   } 
   else 
    {  
        t=front; 
        while(t) 
        { 
            printf("%d,",t->data); 
            t=t->next; 
        } 
    } 
}             
          
void main()       
{   
    NODE *front=NULL,*rear=NULL; 
    int ch,data; 
    do{ 
      printf("\nMain Menu\n1] Insert\n2] Display\n3] Delete\n4] 
Exit\n"); 
      printf("Enter Ur Choice?"); 
      scanf("%d",&ch); 
      switch(ch) 
      { 
        case 1: 
            printf("Enter Data:"); 
            scanf("%d",&data); 
            rear=insert(rear,data); 
            if(front==NULL) 
            { front=rear; 
            } 
            break; 
        case 2: 
            display(front);  
            break;       
        case 3: 
            front=delete(front); 
            if(front==NULL) 
            { rear=NULL; 
            } 
            break;   
        case 4: 
            printf("Exit"); 
            break; 
default: 
printf("Wrong Option"); 
} 
printf("\n"); 
}while(ch!=4); 
}         





//Practical No.: 3 
//Program Description: Implementation of Circular Queue using Array. 
//Solution: 
# include<stdio.h> 
# define MAX 5 
 
int cqueue_arr[MAX]; 
int front = -1; 
int rear = -1; 
 
void insert(int item) 
{ 
    if((front == 0 && rear == MAX-1) || (front == rear+1)) 
    { 
        printf("Queue Overflow \n"); 
        return; 
    } 
    if (front == -1 
    { 
        front = 0; 
        rear = 0; 
    } 
    else 
    { 
        if(rear == MAX-1 
            rear = 0; 
        else 
            rear = rear+1; 
    } 
    cqueue_arr[rear] = item ; 
} 
 
void del() 
{ 
    if (front == -1) 
    { 
        printf("Queue Underflow\n"); 
        return ; 
    } 
    printf("Element deleted from queue is : 
%d\n",cqueue_arr[front]); 
    if(front == rear)  
    { 
        front = -1; 
        rear=-1; 
    } 
    else 
    {    
        if(front == MAX-1) 
            front = 0; 
        else 
            front = front+1; 
    } 
} 
 
void display() 
{ 
    int front_pos = front,rear_pos = rear; 
    if(front == -1) 
    { 
        printf("Queue is empty\n"); 
        return; 
    } 
    printf("Queue elements :\n"); 
    if( front_pos <= rear_pos ) 
        while(front_pos <= rear_pos) 
        { 
            printf("%d ",cqueue_arr[front_pos]); 
            front_pos++; 
        } 
    else 
    { 
        while(front_pos <= MAX-1) 
        { 
            printf("%d ",cqueue_arr[front_pos]); 
            front_pos++; 
        } 
        front_pos = 0; 
        while(front_pos <= rear_pos) 
        { 
            printf("%d ",cqueue_arr[front_pos]); 
            front_pos++; 
        } 
    } 
    printf("\n"); 
} 
 
 int main() 
{ 
    int choice,item; 
    do 
    { 
        printf("1.Insert\n"); 
        printf("2.Delete\n"); 
 
 
 Arti Verma(0902cs231023)  42 
        printf("3.Display\n"); 
        printf("4.Quit\n"); 
 
        printf("Enter your choice : "); 
        scanf("%d",&choice); 
 
        switch(choice) 
        { 
            case 1 : 
                printf("Input the element for insertion in queue : 
"); 
                scanf("%d", &item); 
 
                insert(item); 
                break; 
            case 2 : 
                del(); 
                break; 
            case 3: 
                display(); 
                break; 
            case 4: 
                break; 
                default: 
                printf("Wrong choice\n"); 
        } 
    }while(choice!=4); 
     
    return 0; 
} 

