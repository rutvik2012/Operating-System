#include<stdio.h>
#include<conio.h>
int main()
{
	printf("*------Welcome to multilevel Queue-------*\n");
	printf("1. Shortest Time Remaining First\n");
	printf("2. Round Robin\n");
	int xc=0;
	printf("Enter your choice:\n");
	scanf("%d",&xc);
	if(xc==1)
	{
		int a[10],b[10],x[10];
 		int waiting[10],turnaround[10],completion[10];
 		int i,j,smallest,count=0,time,n;
 		double avg=0,tt=0,end;
 		printf("\nEnter the number of Processes: ");
 		scanf("%d",&n);
 		for(i=0;i<n;i++)
 		{
   		printf("\nEnter arrival time of process %d : ",i+1);
   		scanf("%d",&a[i]);
   		printf("\nEnter burst time of process %d : ",i+1);
   		scanf("%d",&b[i]);
 		}
 		for(i=0;i<n;i++)
 		x[i]=b[i];
  		b[9]=9999;
 //printf("time => process number");
 		for(time=0;count!=n;time++)
 		{
 	  	smallest=9;
  		for(i=0;i<n;i++)
  		{
   		if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
   		smallest=i;
  		}
  		b[smallest]--;
  //printf("\n%d => p%d",time+1,smallest);
  		if(b[smallest]==0)
  		{
   		count++;
   		end=time+1;
   		completion[smallest] = end;
   		waiting[smallest] = end - a[smallest] - x[smallest];
   		turnaround[smallest] = end - a[smallest];
   // printf("\n %d  %d   %d",smallest,wt[smallest],ttp[smallest]);
		}
 		}
 		printf("pid \t burst \t arrival \twaiting \tturnaround \tcompletion");
		 for(i=0;i<n;i++)
 		{
   		printf("\n %d \t   %d \t %d\t\t%d   \t\t%d\t\t%d",i+1,x[i],a[i],waiting[i],turnaround[i],completion[i]);
   		avg = avg + waiting[i];
   		tt = tt + turnaround[i];
 		}
 		printf("\n  %If   %If",avg,tt);
		 printf("\n\nAverage waiting time = %lf\n",avg/n);
 		printf("Average Turnaround time = %lf",tt/n);
 		getch();
	}
 		
	else if(xc==2){
	
      	 int i, limit, total = 0, x, counter = 0, time_quantum;
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
      float average_wait_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &limit);
      x = limit;
      for(i = 0; i < limit; i++)
      {
            printf("nEnter Details of Process[%d]\n", i + 1);
 
            printf("Arrival Time:\t");
 
            scanf("%d", &arrival_time[i]);
 
            printf("Burst Time:\t");
 
            scanf("%d", &burst_time[i]);
 
            temp[i] = burst_time[i];
      }
 
      printf("nEnter Time Quantum:\t");
      scanf("%d", &time_quantum);
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  turnaround_time = turnaround_time + total - arrival_time[i];
                  counter = 0;
            }
            if(i == limit - 1)
            {
                  i = 0;
            }
            else if(arrival_time[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
      printf("\nAvg Turnaround Time:\t%fn", average_turnaround_time);
      return 0;
      }
      else{
      	printf("wromg choice");
      	
      }
  }

