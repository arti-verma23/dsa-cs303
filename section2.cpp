//Practical No.: 1 
//Program Description: Implementation of stack using array. 
//Solution: 
#include<stdio.h> 
int stack[100],choice,n,top,x,i; 
void push(void); 
void pop(void); 
void display(void); 
 
void push() 
{ 
    if(top>=n-1) 
    { 
        printf("\n\tSTACK is over flow"); 
         
    } 
    else 
    { 
        printf(" Enter a value to be pushed:"); 
        scanf("%d",&x); 
        top++; 
        stack[top]=x; 
    } 
} 
void pop() 
{ 
    if(top<=-1) 
    { 
        printf("\n\t Stack is under flow"); 
    } 
    else 
    { 
        printf("\n\t The popped elements is %d",stack[top]); 
        top--; 
    } 
} 
void display() 
{ 
    if(top>=0) 
    { 
        printf("\n The elements in STACK \n"); 
        for(i=top; i>=0; i--) 
            printf("\n%d",stack[i]); 
        printf("\n Press Next Choice"); 
    } 
    else 
    { 
        printf("\n The STACK is empty"); 
    } 
    
} 
 
int main() 
{ 
     
    top=-1; 
    printf("\n Enter the size of STACK[MAX=100]:"); 
    scanf("%d",&n); 
    printf("\n\t STACK OPERATIONS USING ARRAY"); 
    printf("\n\t--------------------------------"); 
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT"); 
    do 
    { 
        printf("\n Enter the Choice:"); 
        scanf("%d",&choice); 
        switch(choice) 
        { 
            case 1: 
            { 
                push(); 
                break; 
            } 
            case 2: 
            { 
                pop(); 
                break; 
            } 
            case 3: 
            { 
                display(); 
                break; 
            } 
            case 4: 
            { 
                printf("\n\t EXIT POINT "); 
                break; 
            } 
            default: 
            { 
                printf ("\n\t Please Enter a Valid 
Choice(1/2/3/4)"); 
            } 
} 
} 
while(choice!=4); 
return 0; 
} 






//Practical No.: 2 
//Program Description: Implementation of Stack using Pointers. 
//Solution: 
#include<stdio.h> 
#include<stdlib.h> 
struct stackarr; 
typedef struct stackarr * Stack; 
 
struct stackarr 
{ 
    int Capacity; 
    int TopOfStack; 
    int *Array; 
}; 
 
void MakeEmpty(Stack s) 
{ 
    s->TopOfStack = -1; 
} 
 
Stack CreateStack(int MaxElements) 
{ 
    Stack s; 
    s = (struct stackarr*) malloc(sizeof(struct stackarr)); 
    s->Array = (int *)malloc(sizeof(int) * MaxElements); 
    s->Capacity = MaxElements; 
    MakeEmpty(s); 
    return s; 
} 
 
void DisposeStack(Stack s) 
{ 
    if(s != NULL) 
    { 
        free(s->Array); 
        free(s); 
    } 
} 
 
int isFull(Stack s) 
{ 
    return s->TopOfStack == s->Capacity - 1; 
} 
 
int isEmpty(Stack s) 
{ 
 
 
 Arti Verma(0902cs231023)  30 
    return s->TopOfStack == -1; 
} 
 
void Push(int x, Stack s) 
{ 
    if(isFull(s)) 
        printf("Full Stack\n\n"); 
    else 
        s->Array[++s->TopOfStack] = x; 
} 
 
void Pop(Stack s) 
{ 
    if(isEmpty(s)) 
        printf("Empty Stack\n\n"); 
    else 
        s->TopOfStack--; 
} 
 
int Top(Stack s) 
{ 
    if(isEmpty(s)) 
        printf("Empty Stack\n\n"); 
    else 
        return s->Array[s->TopOfStack]; 
} 
 
int TopAndPop(Stack s) 
{ 
    if(isEmpty(s)) 
        printf("Empty Stack\n\n"); 
    else 
        return s->Array[s->TopOfStack--]; 
} 
 
void Display(Stack s) 
{ 
    int i; 
    if(isEmpty(s)) 
        printf("Empty Stack\n\n"); 
    else 
    { 
        printf("The Stack Elements are :: "); 
        for(i=s->TopOfStack; i >= 0; i--) 
            printf("%d  ",s->Array[i]); 
        printf("\n\n"); 
    } 
} 

int main() 
{ 
    int n, x, ch, i; 
    Stack s; 
    printf("Enter the maximum number of elements in the stack :: "); 
    scanf("%d", &n); 
    s = CreateStack(n); 
    printf("ARRAY IMPLEMENTATION OF STACK ADT\n\n"); 
    do 
    { 
        printf("\n\n1. PUSH\t 2. POP\t 3.TOP \t 4. TOPANDPOP\t 5. 
PRINT\t 6. QUIT\n\nEnter the choice :: "); 
        scanf("%d", &ch); 
        switch(ch) 
        { 
            case 1: 
                printf("Enter the element to be pushed :: "); 
                scanf("%d",&x); 
                Push(x,s); 
                break; 
 
            case 2: 
                Pop(s); 
                break; 
 
            case 3: 
                printf("The Top element in the stack :: %d\n\n", 
Top(s)); 
                break; 
 
            case 4: 
                printf("The popped top element in the stack :: 
%d\n\n", TopAndPop(s)); 
                break; 
 
            case 5: 
                Display(s); 
                break; 
        } 
    }while(ch<6); 
    DisposeStack(s); 
    return 0; 
} 
 





 
//Practical No.: 3 
//Program Description: Program for Tower of Hanoi using recursion. 
//Solution: 
#include<stdio.h> 
int step=0; 
 
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)  
{  
    step++; 
    if (n == 1)  
    {  
        printf("\nStep-%d: Move disk 1 from rod %c to rod %c", 
step,from_rod, to_rod);  
        return;  
    }  
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);  
    printf("\nStep-%d: Move disk %d from rod %c to rod %c", step,n, 
from_rod, to_rod);  
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);  
}  
   
int main()  
{  
    int n;  
    printf("Enter the number of disks : "); 
    scanf("%d",&n); 
    towerOfHanoi(n, 'A', 'C', 'B');    
    return 0;  
}  
 

 
 
 
 



//Practical No.: 4 
//Program Description:   Program to find out factorial using recursion. Also find the various 
//state of stack during programs. 
#include <iostream> 
using namespace std; 
 
// Define a function to calculate factorial 
// recursively 
long long factorial(int n) 
{ 
    // Base case - If n is 0 or 1, return 1 
    if (n == 0 || n == 1) { 
        return 1; 
    } 
    // Recursive case - Return n multiplied by 
    // factorial of (n-1) 
 
    return n * factorial(n - 1); 
} 
 
int main() 
{ 
    int num = 5; 
    // printing the factorial 
    cout << "Factorial of " << num << " is ";
     << factorial(num) << endl; 
 
    return 0; 
} 
