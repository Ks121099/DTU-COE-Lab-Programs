#include<stdio.h>
#include<math.h>
int queue[100], n, head, currentPos = 0;
void sort()
{
int i, j, temp;
for(i = currentPos; i < n + 1; i++)
{
for(j = currentPos; j < n; j++)
{
if((abs(queue[j + 1] - head)) < (abs(queue[j] - head)))
{
temp = queue[j];
queue[j] = queue[j + 1];
queue[j + 1] = temp;
}
}
}
}
int main()
{
int i, k, seek = 0, diff;
float avg;
51printf("Request Size: ");
scanf("%d", &n);
printf("Enter tracks: ");
for(i = 1; i <= n; i++)
{
scanf("%d", &queue[i]);
}
printf("Initial head pos: ");
scanf("%d", &head);
queue[0] = head;
currentPos = 1;
sort();
for(i = 0; i < n; i++)
{
diff = abs(queue[i + 1] - queue[i]);
seek += diff;
printf("%d ---> %d, Time: %d\n", queue[i], queue[i + 1], diff);
}
currentPos++;
head = queue[i + 1];
sort();
printf("\nTotal Seek Time is %d\t", seek);
avg = seek / (float)n;
printf("\nAverage Seek Time is %f\t", avg);
return 0;
}