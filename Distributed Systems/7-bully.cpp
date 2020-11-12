#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct process
{
 int no;
 int priority;
 int active;
 struct process *next;
};
typedef struct process proc;
struct priority
{
 int pri;
 struct priority *next;
 proc *pp;
};
typedef struct priority pri;
pri* find_priority(proc *head, pri *head1)
{
 proc *p1;
 pri *p2, *p3;
 p1 = head;
 while (p1->next != head)
 {
 if (p1->active == 1)
 {
 if (head1 == NULL)
 {
 head1 = (pri*) malloc(sizeof(pri));
 head1->pri = p1->priority;
 head1->next = NULL;
 head1->pp = p1;
 p2 = head1;
 }
 else
 {
 p3 = (pri*) malloc(sizeof(pri));
 p3->pri = p1->priority;
 p3->pp = p1;
 p3->next = NULL;
 p2->next = p3;
 p2 = p2->next;
 }
 p1 = p1->next;
 }
 else
 p1 = p1->next;
 }
 p3 = (pri*) malloc(sizeof(pri));
 p3->pri = p1->priority;
 p3->pp = p1;
 p3->next = NULL;
 p2->next = p3;
 p2 = p2->next;
 p3 = head1;
 return head1;
}
int find_max_priority(pri *head)
{
 pri *p1;
 int max = -1;
 int i = 0;
 p1 = head;
 while (p1 != NULL)
 {
 if (max < p1->pri && p1->pp->active == 1)
 {
 max = p1->pri;
 i = p1->pp->no;
 }
 p1 = p1->next;
 }
 return i;
}
void bully()
{
 proc *head;
 proc *p1;
 proc *p2;
 int n, i, pr, maxpri, a, pid, max, o;
 char ch;
 head = p1 = p2 = NULL;
 printf("Enter how many process: ");
 scanf("%d", &n);
 for (i = 0; i < n; i++)
 {
if(i!=0)
    printf("\n");
 printf("Enter priority of process %d: ", i + 1);
 scanf("%d", &pr);
 printf("Is process with id %d is active ?(0/1) :", i + 1);
 scanf("%d", &a);
 if (head == NULL)
 {
 head = (proc*) malloc(sizeof(proc));
 if (head == NULL)
 {
 printf("\nMemory cannot be allocated");
 exit(0);
 }
 head->no = i + 1;
 head->priority = pr;
 head->active = a;
 head->next = head;
 p1 = head;
 }
 else
 {
 p2 = (proc*) malloc(sizeof(proc));
 if (p2 == NULL)
 {
 printf("\nMemory cannot be allocated");
 exit(0);
 }
 p2->no = i + 1;
 p2->priority = pr;
 p2->active = a;
 p1->next = p2;
 p2->next = head;
 p1 = p2;
 }
 }
 printf("Enter the process id that invokes election algorithm: ");
 scanf("%d", &pid);
 p2 = head;
 while (p2->next != head)
 {
 if (p2->no == pid)
 {
 p2 = p2->next;
 break;
 }
 p2 = p2->next;
 }
 printf("\nProcess with id %d has invoked election algorithm", pid);
 printf("\t\nElection message is sent to processes : ");
 while (p2->next != head)
 {
 if (p2->no > pid)
 printf("%d, ", p2->no);
 p2 = p2->next;
 }
 printf("%d", p2->no);
 p2 = head;
 max = 0;
 while (1)
 {
 if (p2->priority > max && p2->active == 1)
 max = p2->no;
 p2 = p2->next;
 if (p2 == head)
 break;
 }
 printf("\nProcess with the id %d is the co-ordinator\n", max);
}
int main()
{
 bully();
 return 0;
}