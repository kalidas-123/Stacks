/*C PROGRAM TO PERFORM PUSH AND POP OPERATIONS USING STACKS*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
struct stack 
{
    int a[SIZE],top;
};

void fn_push(struct stack *s,int ele)
{
    if(s->top == SIZE - 1)
        printf("Stack overflow\n");
    else
        s->a[++s->top] = ele;
}

int fn_pop(struct stack *s)
{
    int ele;
    if(s->top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        ele = s->a[s->top--];
        return ele;
    }
}

void fn_display(struct stack s)
{
    int i;
    if(s.top == -1)
        printf("Stack is empty\n");
    else
    {
        for(i = 0 ; i <= s.top ; i++)
            printf("%d\n",s.a[i]);
    }
}

int main()
{
    struct stack s;
    s.top = -1;
    int ele,choice;

    printf("The choices are as follows\n");
    printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");

    while(1)
    {
        printf("Enter the choice of operation\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the element to be pushed\n");
                    scanf("%d",&ele);
                    fn_push(&s,ele);
                    break;
            
            case 2: ele = fn_pop(&s);
                    if(ele != -1)
                        printf("Element popped is %d\n",ele);
                    break;

            case 3: printf("Elements of the stack are\n");
                    fn_display(s);
                    break;

            case 4:exit(0);

            default:printf("Enter valid input\n");
        }
    }

    return 0;
}