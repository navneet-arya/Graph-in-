#include<stdio.h>
#include<stdlib.h>

struct Node{
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
 
struct Node *start=NULL;

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
 if(start==NULL){
  new_node->value=n;
  new_node->next=NULL;
  new_node->adj=NULL;
  start=new_node;
  printf("Created.... \n");
 }
 else{
 p=start;
  while(p->next!=NULL)
   p=p->next;
  p->next=new_node;
  new_node->value=n;
  new_node->adj=NULL;
  new_node->next=NULL;
  printf("Created.... \n");
 }/*
 p=start;
 printf("---------nodes are --------------\n");
 while(p->next!=NULL){
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
 if(found_source==0)
  printf("\n------- Source doesn't exits.-------\n");
  else{
  
   found_destination=search(destination);
   if(found_destination==0)
    printf("\n----- Destination doesn't exits.------\n");
    
   else{
    new_edge=(struct Edge *)malloc(sizeof(struct Edge));
    
    if(found_source->adj==NULL){
     found_source->adj=new_edge;
     new_edge->weight=cost;
     new_edge->dest=found_destination;
     new_edge->link=NULL;
     printf("Edge created....\n");//,new_edge->dest->value);
    }
    else{
     p=found_source->adj;
     if(p->link==NULL){
      p->link=new_edge;
      new_edge->weight=cost;
      new_edge->dest=found_destination;
      new_edge->link=NULL;
      printf("Edge created....\n");//,new_edge->dest->value);
     }
     while(p->link!=NULL)
      p=p->link;

     p->link=new_edge;
     new_edge->weight=cost;
     new_edge->dest=found_destination;
     new_edge->link=NULL;
     printf("Edge created....\n");//,new_edge->dest->value);
    }
   }
 }
}

//---------------------Search --------------------------------------------
struct Node *search(int data){
 struct Node *p;
 //printf("inside the search\n");
 p=start;
 while(p->next!=NULL){
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

if(start==NULL){
 printf("---- Graph is Empty ----\n");
 return;
}

printf("-----------------------------------\n");
 q=start;
 while(q->next!=NULL){
  printf("%d\t",q->value);
  if(q->adj!=NULL){
   p_edge=q->adj;
   while(p_edge->link!=NULL){
    printf("%d ",p_edge->dest->value);
    p_edge=p_edge->link;
   }
   printf("%d ",p_edge->dest->value);
   printf("\n");
  }
  else
   printf("** No Connection Present **\n");
  q=q->next;
 }
 printf("%d\t",q->value);
 if(q->adj!=NULL){
   p_edge=q->adj;
   while(p_edge->link!=NULL){
    printf("%d ",p_edge->dest->value);
    p_edge=p_edge->link;
   }
   printf("%d ",p_edge->dest->value);
   printf("\n");
  }
  else
   printf("** No Connection Present **\n");
 printf("-------------------------------------\n");
}
