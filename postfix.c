/*C PROGRAM TO EVALUATE A VALID POSTFIX EXPRESSION*/

#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define SIZE 20
struct stack
{
    float a[SIZE];
    int top;
};

void fn_push(struct stack *s,char ele)
{
    if(s->top == SIZE - 1)
        printf("Stack overflow\n");
    else 
        s->a[++s->top] = ele;
}

char fn_pop(struct stack *s)
{
    float ele;
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

float fn_compute(char ele,float op1,float op2)
{
    switch(ele)
    {
        case '+':return op1 + op2;
        case '-':return op1 - op2;
        case '*':return op1 * op2;
        case '/':return op1 / op2;
        case '^':return pow(op1,op2);
        default:printf("Invalid input\n");
                break;
    }
}

float fn_eval(struct stack *s,char postfix[])
{
    int i;
    char ele;
    float op1,op2,res;

    for(i = 0 ; (ele = postfix[i]) != '\0' ; i++)
    {
        if(isdigit(ele))
            fn_push(s,(float)(ele - '0'));
        else
        {
            op2 = fn_pop(s);
            op1 = fn_pop(s);
            res = fn_compute(ele,op1,op2);
            fn_push(s,res);
        }
    }
    res = fn_pop(s);

    return res;
}

int main()
{
    struct stack s;
    s.top = -1;
    char postfix[SIZE];
    float res;

    printf("Enter the string\n");
    scanf("%s",postfix);

    res = fn_eval(&s,postfix);

    printf("%f\n",res);

    return 0;
}