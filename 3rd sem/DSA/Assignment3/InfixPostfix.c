#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct stack{
    char *s;
    int size;
    int top;
};
struct stackforeval{
    int *s;
    int size;
    int top;
};
int outstack(char ch){
 if(ch=='+'||ch=='-')
        return 1;
 else if(ch=='*'||ch=='/')
    return 3;
 else if(ch=='^')
    return 6;
 else if(ch=='(')
    return 7;
 else if(ch==')')
    return 0;
}
int instack(char ch){
  if(ch=='+'||ch=='-')
        return 2;
 else if(ch=='*'||ch=='/')
    return 4;
 else if(ch=='^')
    return 5;
  else if(ch=='(')
    return 0;
}
int isoperand(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='('||ch==')' )
        return 0;
    else
        return 1;
}
void push(struct stack *p,int x){
    if(p->top==p->size-1)
    {
        printf("stack full\n");
    }
    else
    {
        p->top++;
        p->s[p->top]=x;
    }
}
int pop(struct stack *p){
    int x=-1;
    if(p->top==-1){
        printf("stack underflow\n");

    }
    else{
        x=p->s[p->top--];

    }
        return x;
}
void push1(struct stackforeval *p,int x){
    if(p->top==p->size-1){
        printf("stack full\n");
    }
    else{
        p->top++;
        p->s[p->top]=x;
    }
}
int pop1(struct stackforeval *p){
    int x=-1;
    if(p->top==-1){
        printf("stack underflow\n");

    }
    else{
        x=p->s[p->top--];
    }
        return x;
}
char* createpostfix(char *a){
    int i=0;
    int j=0;
    struct stack st;
    st.top=-1;
    st.size=strlen(a)+1;
    st.s=(char*)malloc(st.size*sizeof(char));
    char *ch=(char*)malloc(2*st.size*sizeof(char));
    while(a[i]!='\0')
    {
        if(isoperand(a[i]))
        {

               ch[j++]=a[i++];

        }


        else
        {
            ch[j++]=' ';
            if(st.top==-1||instack(st.s[st.top])<outstack(a[i]))
                push(&st,a[i++]);
            else
            {
                if(a[i]==')')
               {
                   while(st.s[st.top]!='(')
                  {
                    ch[j++]=pop(&st);
                  }
                   pop(&st);
                  i++;
               }
               else
                {

                while(st.top!=-1&&instack(st.s[st.top])>outstack(a[i]))
                    ch[j++]=pop(&st);
                push(&st,a[i++]);
                }

            }
        }
    }
    ch[j++]=' ';
    while(st.top!=-1)
        ch[j++]=pop(&st);
    ch[j]='\0';
    return ch;
}
int evalpostfix(char *a){
    int i=0;
     int x1,x2,r,n;
    struct stackforeval st;
    st.top=-1;
    st.size=strlen(a)+1;
    st.s=(int*)malloc(st.size*sizeof(int));
    while(a[i]!='\0')
    {
        if(isoperand(a[i]))
        {
            n=0;
            do
            {
              n=n*10+(a[i]-'0');
              i++;


            }while(a[i]!=' ');
            push1(&st,n);
            i++;
        }
        else
        {
          x1=pop1(&st);
          x2=pop1(&st);
          switch(a[i])
          {
          case '+':
            {
                r=x2+x1;
                push1(&st,r);
                i++;
                break;
            }
            case '-':
            {
                r=x2-x1;
                push1(&st,r);
                i++;
                break;
            }
            case '*':
            {
                r=x2*x1;
               push1(&st,r);
               i++;
               break;
            }
            case '/':
            {
                r=x2/x1;
               push1(&st,r);
               i++;
               break;
            }
            case '^':
            {
                r=pow(x2,x1);
               push1(&st,r);
               i++;
               break;
            }
          }
        }
    }
    return st.s[st.top];
}
int main(){
    char ch[20];
    char *p;
    printf("enter the expression\n");
    gets(ch);
    p=createpostfix(ch);
    printf("the postfix expression is:\n");
    puts(p);
    printf("\nthe value of postfix expression is %d",evalpostfix(p));
    return 0;
}
