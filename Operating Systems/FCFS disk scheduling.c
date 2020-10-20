#include<stdio.h>
int main()
{
int queue[100], n, head, i, seek = 0, diff;
float avg;
printf("Request Size: ");
scanf("%d", &n);
printf("Enter tracks: ");
for(i = 1; i <= n; i++)
{
scanf("%d", &queue[i]);
}
printf("Initial head pos: ");
scanf("%d", &head);
queue[0] = head;
for(i = 0; i < n; i++)
{
diff = queue[i + 1] - queue[i];
if(diff < 0)
diff *= -1;
seek += diff;
printf("%d ---> %d, Time: %d\n", queue[i], queue[i + 1], diff);
}
printf("\nTotal Seek Time is %d\t", seek);
avg = seek / (float)n;
printf("\nAverage Seek Time is %f\t", avg);
return 0;
}