#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void main()
{   
 int n;
 int sub[n];
 printf("Enter the no. of processes\n");
 scanf("%d",&n);
 int arrival[n],process[n],priority[n];
 printf("Enter the process time of each processes\n");
 for(int i=0;i<n;i++)
 {
    scanf("%d",&process[i]);
 }
  printf("Enter the arrival time of each processes\n");
 for(int i=0;i<n;i++)
 {
    scanf("%d",&arrival[i]);
 }
 printf("Enter the priority of each processes\n");
 for(int i=0;i<n;i++)
 {
    scanf("%d",&priority[i]);
     sub[i]=i+1;
 }

 
   for(int i=0;i<n;i++)
   {
     int temp=priority[i],index=i;
    
     
     for(int j=i;j<n;j++)
     {
        if(temp>priority[j])
        {
            temp=priority[j];
            index=j;
        }
     }
     swap(&priority[index],&priority[i]);
     swap(&arrival[index],&arrival[i]);
     swap(&process[index],&process[i]);
     swap(&sub[index],&sub[i]);
   }
   
   int s=arrival[0],avg=s,avg2=0;
   for(int i=0;i<n;i++)
   {
   printf("Waiting time of P%d is %d\n",sub[i],s-arrival[i]);
   printf("turn arround time of P%d is %d\n\n",sub[i],s-arrival[i]+process[i]);
   avg+=s-arrival[i];
   avg2=avg+process[i];
   s+=process[i];
   }
   printf("Average Waiting time is %d\n",avg);
    printf("Average turn around time is %d\n",avg2);
}


