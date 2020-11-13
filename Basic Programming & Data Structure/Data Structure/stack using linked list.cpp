#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
 int value ;
 struct node* next ;
} node ;
typedef struct stack {
 node* start ;
} stack ;
void inserts( stack* , int);
int deletes( stack* );
void displays( stack);
void initialize( stack* );
void peeks( stack );
node* getnewnode();
int main()
{
 stack s ;
 int ch , n ;
 initialize(&s);
 printf("1. Push \n");
 printf("2. Pop \n");
 printf("3. Display \n");
 printf("4. Peek \n");
 printf("5. End \n");
 do{
 printf("Enter the choice : ");
 scanf("%d" , &ch );
 switch(ch) {
 case 1 :
 printf("Enter Value to Insert : ");
 scanf("%d" , &n);
 inserts(&s , n);
 break;
 case 2 :
 n = deletes(&s);
 if(n == -1) break;
 printf("Deleted Value : %d\n" , n );
 break;
 case 3 :
 displays(s);
 break;
 case 4 :
 peeks(s);
 break;
 }
 } while ( ch != 5) ;
}
void initialize(stack *S){
 S->start = NULL ;
}
node* getnewnode(){
 node* new = malloc(sizeof( node ) );
 return new;
}
void inserts( stack *S , int x ){
 node* q = getnewnode() ;
 if( q == NULL ){
 printf("Memory is Full \n ");
 return;
 }
 q->value = x ;
 q->next = S->start ;
 S->start = q ;
}
int deletes( stack *S )
{
 int x ;
 node* q ;
 if( S->start == NULL ){
 printf("Stack is Empty \n");
 return(-1);
 }
 x = S->start->value ;
 q = S->start ;
 S->start = q->next ;
 return(x);
}
void peeks(stack S){
 if( S.start == NULL ){
 printf("Stack is Empty \n");
 return;
 }
 printf("Peek : %d \n" , S.start->value);
}
void displays( stack S ){
 while(S.start != NULL){
 printf("%d " , S.start->value );
 S.start = S.start->next ;
 }
 printf("\n");
}
