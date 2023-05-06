/*C PROGRAM TO CHECK STRING PALINDROME USING STACKS*/

#include<stdio.h>
#include<string.h>
#define SIZE 20
struct stack
{
    int a[SIZE],top;
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

int fn_check(struct stack *s,char str[])
{
    char rev[SIZE];
    int i;

    for(i = 0 ; str[i] != '\0' ; i++)
    {
        fn_push(s,str[i]);
    }

    i = 0;
    while(s->top != -1)
    {
        rev[i] = fn_pop(s);
        i++;
    }

    rev[i] = '\0';
    printf("Reversed string is %s\n",rev);

    if(strcmp(str , rev) == 0)
        return 1;
    else
        return 0;

}

int main()
{
    struct stack s;
    s.top = -1;
    char str[SIZE];

    printf("Enter the string\n");
    scanf("%s",str);

    int x = fn_check(&s,str);

    if(x == 1)
        printf("String %s is palindrome\n",str);
    else
    {
        printf("String %s is not palindrome\n",str);
    }
    
    return 0;

}