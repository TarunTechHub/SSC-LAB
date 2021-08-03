#include<stdio.h>
int i,j,nop,pages[50],frame[10],nof,k,avail,counter=0;
int faults=0;
void FIFO();
void LRU();

int main()
{
int choice;
printf("\n ENTER THE NUMBER OF PAGES:\n");
scanf("%d",&nop);
printf("\n ENTER THE PAGE NUMBER :\n");
for(i=0;i<nop;i++)
    scanf("%d",&pages[i]);
printf("\n ENTER THE NUMBER OF FRAMES :");
    scanf("%d",&nof);
for(i=0;i<nof;i++)
    frame[i]= -1;
tryagain:
printf("Page Replacement Alogrithms:\n\n1) FIFO 2) LRU 3) Exit\n");
  scanf("%d",&choice);
  switch(choice)
  {
	  case 1:FIFO();
			 break;
	  case 2:LRU();
			 break;
	  case 3:return 0;
	  default:printf("wrong choice Try again!!!");
	          goto tryagain;
  }
}


void FIFO()
{
j=0;
printf("ref string\t page frames\n");
for(i=0;i<nop;i++)
{
    printf("%d\t\t",pages[i]);
    avail=0;
    for(k=0;k<nof;k++)
    if(frame[k]==pages[i])
        avail=1;
    if (avail==0)
    {
        frame[j]=pages[i];
        j=(j+1)%nof;
        faults++;
        for(k=0;k<nof;k++)
            printf("%d\t",frame[k]);
    }
    printf("\n");
}
printf("Page Fault Is %d",faults);
}


int findLRU(int time[], int n){
    int i, minimum = time[0], pos = 0;
 
    for(i = 1; i < n; ++i){
        if(time[i] < minimum){
            minimum = time[i];
            pos = i;
        }
    }
    
    return pos;
}


void LRU()
{
    int flag1,flag2;
    int time[15],pos;
    printf("ref string\t page frames\n");
    for(i = 0; i < nop; i++)
    {
        printf("%d\t\t",pages[i]);
        flag1 = flag2 = 0;
        avail=0;
        for(j = 0; j < nof; j++)
        {
            if(frame[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                   flag1 = flag2 = 1;
                   avail=1;
                   break;
            }
        }
        
        if(flag1 == 0)
        {
            for(j = 0; j < nof; j++)
            {
                if(frame[j] == -1)
                {
                    counter++;
                    faults++;
                    frame[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0)
        {
            pos = findLRU(time, nof);
            counter++;
            faults++;
            frame[pos] = pages[i];
            time[pos] = counter;
        }
        
        if(!avail)
        for(j = 0; j < nof; j++)
        {
            printf("%d\t", frame[j]);
        }
    printf("\n");
    }
    
    printf("\n\nTotal Page Faults = %d", faults);
}