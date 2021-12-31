#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct poly
{
    int coeff;
    int power;
    struct poly *next;

};

void create(struct poly *p,int m)//m is number of non zero terms of any polynomial
{

  int i=1;
  if(m==0)
  {
  p->coeff=0;
  p->power=0;
  p->next=NULL;
  }
  else if(m==1)
  {
    p->next=NULL;
  }
  else
  {
  do
       {
        struct poly *t=(struct poly *)malloc(sizeof(struct poly));
        t->next=NULL;
        p->next=t;
        p=p->next;
        i+=1;
        }while(i<m);
    }
}
void input(struct poly *p)
{
  while(p)
  {
      scanf("%d%d",&p->coeff,&p->power);
      p=p->next;
  }
}
void display(struct poly *p)
{
    while(p!= NULL)//p->next!=NULL glat h
    {
        printf("(%d,%d) ",p->coeff,p->power);
        p=p->next;
    }
}
void add(struct poly *p1,struct poly *p2,struct poly *p3)
{
    struct poly *q;
  while(p1 && p2)
  {

      if(p1->power==p2->power)
      {
           p3->power=p1->power;
          p3->coeff=p1->coeff+p2->coeff;
          p1=p1->next;
          p2=p2->next;
          q=p3;
          p3=p3->next;
      }
      else if(p1->power>p2->power)
      {
          p3->power=p1->power;
           p3->coeff=p1->coeff;
          p1=p1->next;
          q=p3;
          p3=p3->next;
      }
      else
      {
        p3->power=p2->power;
         p3->coeff=p2->coeff;
          p2=p2->next;
          q=p3;
          p3=p3->next;
      }
  }
  while(p1)
  {
      p3->power=p1->power;
      p3->coeff=p1->coeff;
      p1=p1->next;
      q=p3;
      p3=p3->next;

  }
  while(p2)
  {
      p3->power=p2->power;
      p3->coeff=p2->coeff;
      p2=p2->next;
      q=p3;
      p3=p3->next;

  }
  p3=q;
  p3->next=NULL;

}
void sub(struct poly *p1,struct poly *p2,struct poly *p3)
{
    struct poly *q;
  while(p1 && p2)
  {
      if(p1->power==p2->power)
      {
          p3->power=p1->power;
          p3->coeff=p1->coeff-p2->coeff;
          p1=p1->next;
          p2=p2->next;
          q=p3;
          p3=p3->next;
      }
      else if(p1->power>p2->power)
      {
          p3->power=p1->power;
           p3->coeff=p1->coeff;
          p1=p1->next;
          q=p3;
          p3=p3->next;
      }
      else
      {
        p3->power=p2->power;
         p3->coeff=p2->coeff;
          p2=p2->next;
          q=p3;
          p3=p3->next;
      }
  }
  while(p1)
  {
      p3->power=p1->power;
      p3->coeff=p1->coeff;
      p1=p1->next;
      q=p3;
      p3=p3->next;

  }
  while(p2)
  {
      p3->power=p2->power;
      p3->coeff=p2->coeff;
      p2=p2->next;
      q=p3;
      p3=p3->next;

  }
  p3=q;
  p3->next=NULL;

}

int sum(struct poly *p,int x)
{
    if(p==NULL)
        return 0;
    return sum(p->next,x) +(p->coeff * pow(x,p->power));
}


int main()
{
    struct poly *p1=(struct poly *)malloc(sizeof(struct poly));
    struct poly *p2=(struct poly *)malloc(sizeof(struct poly));
    struct poly *p3=(struct poly *)malloc(sizeof(struct poly));
    struct poly *p4=(struct poly *)malloc(sizeof(struct poly));
    int m,n,i,x;

    //printf("enter the number of polynomials\n");
    printf("enter the number of non-zero terms of 1st and 2nd poly\n");
    scanf("%d%d",&m,&n);

    create(p1,m);
    create(p2,n);
    create(p3,m+n);
    create(p4,m+n);
    if(m)
    {
      printf("enter the coeff and powers of 1st poly(Term wise)\n");
      input(p1);
    }
    if(n)
    {
    printf("enter the coeff and powers of 2nd poly(Term wise)\n");
    input(p2);
    }
    if(m!=0)
    {
    printf("(coeffficient,power) of 1st polynomials are\n");
    display(p1);
    printf("\n");
    }
    if(n!=0)
    {
    printf("(coeffficient,power) of 2nd polynomials are\n");
    display(p2);
    printf("\n");
    }
    add(p1,p2,p3);


    printf("\n");
    printf("(coeffficient,power) of added polynomial are\n");

   display(p3);
   sub(p1,p2,p4);
   printf("\n");
   printf("(coeffficient,power) of subtracted polynomial are\n");

   display(p4);

   printf("\n");

   printf("enter the value of x for 1st poly \n");
   scanf("%d",&x);
   printf("the sum is %d",sum(p1,x));

    return 0;
}