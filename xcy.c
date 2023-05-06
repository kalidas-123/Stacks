/*C PROGRAM TO CHECK WHETHER INPUT STRING IS OF THE TYPE XCY OR NOT
WHERE X IS STRING CONSISTING OF LETTERS A AND B SND Y IS REVERSE OF X.
EXAMPLE : ABBCBBA , ABBACABBA ARE SOME STRINGS OF THE FORM XCY. */

#include<stdio.h>
#define SIZE 20
struct stack
{
    char a[SIZE];
    int top;
};

void fn_push(struct stack *s,char ele)
{
    if(s->top == SIZE -1)
        printf("Stack overflow\n");
    else 
    {
        s->a[++s->top] = ele;
    }
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

int fn_empty(struct stack *s)
{
    if(s->top == -1)
        return -1;
    else
    {
        return 0;
    }
}

int fn_check(struct stack *s,char str[])
{
    int i,j;

    for ( i = 0; str[i] != 'C'; i++)
    {
        if(str[i] == 'A' || str[i] == 'B')
        {
            fn_push(s,str[i]);
        }
        else
        {
            return 0;
        }
    }

    for (j = i + 1 ; str[j] != '\0' ; j++)
    {
        if(str[j] == fn_pop(s))
            continue;
        else
        {
            return 0;
        }
    }

    if(fn_empty(s))
        return 1;
    else
    {
        return 0;
    }
    
}

int main()
{
    struct stack s;
    s.top = -1;
    char str[SIZE];
    int res;

    printf("Enter a string\n");
    scanf("%s",str);

    res = fn_check(&s,str);

    if(res == 1)
        printf("String %s is of the type XCY\n",str);
    else 
    {
        printf("String %s is not of the type XCY\n",str);
    }

    return 0;

}