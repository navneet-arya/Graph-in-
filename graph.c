#include<stdio.h>
#include<stdlib.h>
#define null NULL

typedef struct Node{
 int value;
 int *next;
 struct Node *adj;
};

struct Edge{
 int weight;
 struct Node *dest;
 struct Edge *link;
};


void addnode(int);
void addEdge(int,int,int);
struct Node *search(int);
void display();
 
struct Node *start=null;

int main(){
 int choice,cost,i;
 int n,source,destination;
 
 for(;;){
  printf("1001. To create the node.\n");
  printf("1002. To add Edge.\n");
  printf("1003. Display.\n");
  printf("1004. Exit.\n");
  
  scanf("%d",&choice);
  
  if(choice==1001){
   printf("Enter the node you want. \n");
   scanf("%d",&n);
   addnode(n);

  }
  else if(choice==1002){
   printf("Enter the source and destination with cost.\n");
   scanf("%d %d %d", &source, &destination, &cost);
   addEdge(source,destination,cost);
  }
  else if(choice==1003)
   display();
   
  else if(choice==1004)
   break;
  else
   printf("Please enter the valid choice.\n");
 }
 return 0;
}

//-------------------------------------------------------------------------
void addnode(int n){
 struct Node *new_node,*p;
// printf("%u",start);
 new_node=(struct Node *)malloc(sizeof(struct Node));
 if(start==null){
  new_node->value=n;
  new_node->next=null;
  new_node->adj=null;
  start=new_node;
  printf("\n Created.... \n");
 }
 else{
 p=start;
  while(p->next!=null)
   p=p->next;
  p->next=new_node;
  new_node->value=n;
  new_node->adj=null;
  new_node->next=null;
  printf("\n Created.... \n");
 }/*
 p=start;
 printf("---------nodes are --------------\n");
 while(p->next!=null){
  printf("%d ",p->node);
  p=p->next;
 }
 printf("\n---------------------------------\n");*/
}

//-------------------------------------------------------------------------
void addEdge(int source,int destination,int cost){
 struct Node *found_source, *found_destination;
 struct Edge *new_edge,*p;
 
 found_source=search(source);
 //printf("pointer value of source %d \n",found_source);
 if(found_source==0)
  printf("\n------- Source doesn't exits.-------\n");
  else{
  
   found_destination=search(destination);
   if(found_destination==0)
    printf("\n----- Destination doesn't exits.------\n");
    
   else{
    new_edge=(struct Edge *)malloc(sizeof(struct Edge));
    
    if(found_source->adj==null){
     found_source->adj=new_edge;
     new_edge->weight=cost;
     new_edge->dest=found_destination;
     new_edge->link=null;
     printf("%d Edge created....\n",new_edge->dest->value);
    }
    else{
     p=found_source->adj;
     if(p->link==null){
      p->link=new_edge;
      new_edge->weight=cost;
      new_edge->dest=found_destination;
      new_edge->link=null;
      printf("%d Edge created....\n",new_edge->dest->value);
     }
     while(p->link!=null)
      p=p->link;

     p->link=new_edge;
     new_edge->weight=cost;
     new_edge->dest=found_destination;
     new_edge->link=null;
     printf("%d Edge created....\n",new_edge->dest->value);
    }
   }
 }
}

//---------------------Search --------------------------------------------
struct Node *search(int data){
 struct Node *p;
 //printf("inside the search\n");
 p=start;
 while(p->next!=null){
  //printf("inside the while\n");
  if(p->value==data)
   return p;
  p=p->next; 
 }
 if(p->value==data)
  return p;
 return 0;
}

//---------------- Display -----------------------------------------
void display(){
struct Node *q;
struct Edge *p_edge;

printf("-------- Node --------\n");
q=start;
 while(q->next!=null){
  printf("%d  ",q->value);
  q=q->next;
  }
  printf("%d",q->value);
printf("\n--------------------------\n");

printf("-----------------------------------\n");
 q=start;
 while(q->next!=null){
  printf("%d\t",q->value);
  if(q->adj!=null){
   p_edge=q->adj;
   while(p_edge->link!=null){
    printf("%d ",p_edge->dest->value);
    p_edge=p_edge->link;
   }
   printf("%d ",p_edge->dest->value);
   printf("\n");
  }
  q=q->next;
 }
 printf("%d\t",q->value);
 if(q->adj!=null){
   p_edge=q->adj;
   while(p_edge->link!=null){
    printf("%d ",p_edge->dest->value);
    p_edge=p_edge->link;
   }
   printf("%d ",p_edge->dest->value);
   printf("\n");
  }
 printf("\n-------------------------------------\n");
}
