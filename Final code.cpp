#include<stdio.h>
#include<conio.h>
int main()
{
	int i, x,limit, total = 0, z, counters = 0, tq=4;
      int wait_time=0, turnaround_time=0, arrival_time[10], burst_time[10], temp[10];
      float average_wait_time, average_turnaround_time;
	printf("\t\t\t\t\t\t**------Welcome to multilevel Queue Scheduling-------**\n");
	printf("\t\t\t\t\t\t 1. Shortest Time Remaining First(SRTF)\n");
	printf("\t\t\t\t\t\t 2. Round Robin(RR)\n");
	int in=0;
	printf("\t\t\t\t\t\t User enter your choice:\n");
	scanf("%d",&in);
	if(in==1)
	{
		int a[20],b[20],z[20],mini; //mini=smallest
 		int wt_time[20],ta_time[20],complete_time[20];
 		double avg=0,tt=0,end;
 		int j,i,counter=0,t,n; //time = t
 		
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
 		{
 		z[i]=b[i];
  		b[9]=9999;
        }
 		for(t=0;counter!=n;t++)
 		{
 	  	mini=9;
  		for(i=0;i<n;i++)
  		{
   		if(a[i]<=t && b[i]<b[mini] && b[i]>0 )
   		mini=i;
  		}
  		b[mini]--;

  		if(b[mini]==0)
  		{
   		counter++;
   		end=t+1;
   		complete_time[mini] = end;
   		wt_time[mini] = end - a[mini] - z[mini];
   		ta_time[mini] = end - a[mini];

		}
 		}
 		printf("processes \t burst_time \t arrival_time \twaiting_time \tturnaround_time \tcompletion_time");
		 for(i=0;i<n;i++)
 		{
   		printf("\n %d \t\t   %d \t\t %d\t\t\t%d  \t \t\t%d\t\t\t%d",i+1,z[i],a[i],wt_time[i],ta_time[i],complete_time[i]);
   		avg = avg + wt_time[i];
   		tt = tt + ta_time[i];
 		}
 		printf("\n  \t\t\t\t\t%lf \t %lf",avg,tt);
		 printf("\n\nAverage waiting time = %lf\n",avg/n);
 		printf("Average Turnaround time = %lf",tt/n);
 		getch();
	}
 		
	else if(in==2)
	{
	
    	int i, x,limit, total = 0, z, counters = 0, tq=2;
      int wait_time=0, turnaround_time=0, arrival_time[10], burst_time[10], temp[10];
      float average_wait_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &limit);
      x = limit;
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
 
            printf("Arrival Time:\t");
 
            scanf("%d", &arrival_time[i]);
 
            printf("Burst Time:\t");
 
            scanf("%d", &burst_time[i]);
 
            temp[i] = burst_time[i];
      }
 
      //printf("nEnter Time Quantum:\t");  //for user to enter different time quantums 
      //scanf("%d", &tq); //tq=Time qunataum
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i=0; x != 0;)
      {
            if(temp[i] <= tq && temp[i] > 0)
            {
            	
                  total = total + temp[i];
                  temp[i] = 0;
                  counters = 1;
                  wait_time=total-temp[i];
                  
            }
            else if(temp[i]>0)
            { 
			if(temp[i]){
				total = total + tq;
			
				temp[i] = temp[i] - tq; 
                  
          }
            }
        
            if(temp[i] == 0 && counters == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total-arrival_time[i]-burst_time[i]);
                  //wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  turnaround_time = turnaround_time + total - arrival_time[i];
                  counters = 0;
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
      printf("\n\nAverage Turnaround Time:\t%fn", average_turnaround_time);
      return 0;
      }
      else{
      	if(in!=1||2)  // it will by default implement SRTF as it has the higher priority 
      	{
      		int a[10],b[10],z[10];
 		int wt_time[10],ta_time[10],complete_time[10]; //wt_time=waiting time  ta_time=turn around time
 		int i,j,mini,counter=0,t,n;
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
		{
		z[i]=b[i];
  		b[9]=9999;
  		}
 
 		for(t=0;counter!=n;t++)
 		{
 	  	mini=9;
  		for(i=0;i<n;i++)
  		{
   		if(a[i]<=t && b[i]<b[mini] && b[i]>0 )
   		mini=i;
  		}
  		b[mini]--;

  		if(b[mini]==0)
  		{
   		counter++;
   		end=t+1;
   		complete_time[mini] = end;
   		wt_time[mini] = end - a[mini] - z[mini];
   		ta_time[mini] = end - a[mini];

		}
 		}
 		printf("pid \t burst \t arrival \twaiting \tturnaround \tcompletion");
		 for(i=0;i<n;i++)
 		{
   		printf("\n %d \t   %d \t %d\t\t%d   \t\t%d\t\t%d",i+1,z[i],a[i],wt_time[i],ta_time[i],complete_time[i]);
   		avg = avg + wt_time[i];
   		tt = tt + ta_time[i];
 		}
 		printf("\n  \t\t\t\t\t%lf \t %lf",avg,tt);
		 printf("\n\nAverage waiting time = %lf\n",avg/n);
 		printf("Average Turnaround time = %lf",tt/n);
 		getch();
      		
		  }
      }
      	//printf("wrong choice");
      	
      }
  
