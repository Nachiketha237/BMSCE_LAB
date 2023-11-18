#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
  int n;
  float e[20],p[20];
  int i;
  float ut,u,x,y;
  printf("\n Enter Number of Processes :: ");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {
   printf("\n Enter Execution Time for P%d ::",(i+1));
   scanf("%f",&e[i]);
   printf("\n Enter Period for P%d ::",(i+1));
   scanf("%f",&p[i]);
   x=e[i]/p[i];
   ut+=x;
  }
  y=(float)n;
  y=y*((pow(2.0,1/y))-1);
  u=y;
  if(ut<u)
  {
 printf("\n As %f < %f ,",ut,u);
 printf("\n The System is surely Schedulable using Rate Monotonic scheduling");
  }
  else
 printf("\n The system is not schedulable using Rate Monotonic scheduling");
}
