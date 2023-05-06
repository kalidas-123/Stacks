/*C PROGRAM TO CONVERT GIVEN INFIX TO POSTFIX EXPRESSION*/

#include<stdio.h>
#define SIZE 20

struct stack 
{
    int top;
    char a[SIZE];
};

void fn_push(struct stack *s,char ele)
{
    if(s->top == SIZE - 1)
        printf("Stack overflow\n");
    else 
        s->a[++s->top] = ele;
}

int fn_pop(struct stack *s)
{
    char ele;

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

int precedence(char op)
{
    switch(op)
    {
        case '(':return 1;
                 break;
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 3;
        case '^':return 4;
    }
}

void fun(struct stack *s,char p[])
{
    int i,j = 0;
    char postfix[SIZE],ch,x;

    for(i = 0 ; p[i] != '\0' ; i++)
    {
        if(p[i] == '(')
            fn_push(s,p[i]);
        else if(p[i] >= '0' && p[i] <= '9')
            postfix[j++] = p[i];
        else if(p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/')
        {
            if(s->top == -1)
                fn_push(s,p[i]);
            else
            {
                if(precedence(p[i]) > precedence(s->a[s->top]))
                    fn_push(s,p[i]);
                else 
                {
                    postfix[j++] = fn_pop(s);
                    fn_push(s,p[i]);
                }
            }
        }

        if(p[i] == ')')
        {
            while((ch = fn_pop(s)) != '(')
                postfix[j++] = ch;
        }
    }

    while(s->top != -1)
    {
        postfix[j++] = fn_pop(s);
    }
    postfix[j] = '\0';
    printf("%s",postfix);
    
}

int main()
{
    struct stack s;
    s.top = -1;
    char p[SIZE];

    printf("Enter the string\n");
    scanf("%s",p);

    fun(&s,p);

    return 0;
}