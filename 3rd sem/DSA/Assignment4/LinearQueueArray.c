#include<Stdio.h>
#include<stdlib.h>
typedef struct node
{
    int limit;
    int front;
    int rear;
    int *pointer;
}queue;
void enqueue(queue *temp, int num){
 if(temp->rear==temp->limit-1)
        printf("\nOverflow\n");
 else
  temp->pointer[++temp->rear] = num;
}
int dequeue(queue *temp){
    if(temp->front==temp->rear)
    {
        printf("\nUnderflow\n");
        return -1;
    }
    else
        return temp->pointer[++temp->front];

}
int peek(queue temp){
    if(temp.front==temp.rear)
    {
      printf("\nUnderflow\n");
        return -1;
    }
    else
        return temp.pointer[++temp.front];
}
void display(queue temp){
  if(temp.front==temp.rear)

      printf("\nUnderflow\n");
  else
  {
      while(temp.front!=temp.rear)
      {

        printf("%d\n",temp.pointer[++temp.front]);
      }
  }
}
int isfull(queue temp){
   if(temp.rear==temp.limit-1)
        return 1;
   else
    return 0;
}
int isempty(queue temp){
   if(temp.rear==temp.front)
        return 1;
   else
        return 0;
}
int main(){

    int ch,n;
    queue temp;
    temp.front=temp.rear=-1;
    printf("Enter the size: ");
    scanf("%d", &temp.limit);
    temp.pointer=(int*)malloc(temp.limit*sizeof(int));
    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.isfull\n6.isempty\n7.Exit\nYour Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\neEnter Data\n");
            scanf("%d",&n);
            enqueue(&temp,n);
            break;
        case 2:
            n = dequeue(&temp);
            if(n!=-1)
            printf("\nDequeued the number %d\n",n);
            break;
        case 3:
            n=peek(temp);
            if(n!=-1)
                printf("\nTop: %d\n",n);
            break;
        case 4:
            display(temp);
            break;
        case 5:
            printf("\nFULL= %d\n",isfull(temp));
            break;
        case 6:
            printf("\nEMPTY= %d\n",isempty(temp));
            break;
        case 7: 
            exit(0);
            break;
        default: 
            printf("Try again\n");
        }
    }while(ch!=7);
}