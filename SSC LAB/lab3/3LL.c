/* 3. Design, develop and implement YACC/C program to construct Predictive / LL(1)
Parsing Table for the grammar rules: A ®aBa , B ®bB | e. Use this table to parse
the sentence: abba$*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ip[20],stack[20];
int main()
{
char m[2][3][10]={ {"aBa","E","E"},
{"n","bB","E"} };
int size[2][3]= {3,1,1,1,2,1};
int i,j,k,n,row,col;
printf("\n Enter the input string: ");
scanf("%s",ip);
strcat(ip,"$");
n=strlen(ip);
stack[0]='$';
stack[1]='A';
i=1;
j=0;
printf("A$\t\t%s\n",ip);
while((stack[i]!='$')&&(ip[j]!='$')) /* to check stack and input both contains $ */
{
if(stack[i]==ip[j]) /* input and stack matches, discard stack and move to next input symbol */
{
i--;
j++;
goto print;
}
switch(stack[i])
{
case 'A': row=0;
break;
case 'B': row=1;
break;
}

switch(ip[j])
{
case 'a': col=0;
	  if(stack[i]=='$')
	 {printf("error");
	  exit(0);
	  }
break;
case 'b': col=1;
	 if(stack[i]=='$')
	 {printf("error");
	 exit(0);
	 }
break;
case '$': col=2;
	if(stack[i]=='$')
	 { printf("SUCCESS");
	 exit(0);
	 }
break;
default: printf("Unrecognized Terminal\nERROR\n");
	 exit(0);

}

if(m[row][col][0]=='E') 
{
printf("\nERROR");
exit(0);
}
else if(m[row][col][0]=='n')
{
printf("ACTION:Using Production %c-->%s\n",stack[i],m[row][col]);
i--;
}
else 
{
printf("ACTION:Using Production %c-->%s\n",stack[i],m[row][col]);
for(k=size[row][col]-1;k>=0;k--) 
{
stack[i]=m[row][col][k];
i++;
}
i--; /* points to top of stack*/
}
print:
for(k=i;k>=0;k--)
printf("%c",stack[k]); /* update stack*/
printf("\t\t");
for(k=j;k<=n;k++)
printf("%c",ip[k]); /* update input*/
printf("\n");
}
//printf("ERROR\n");
if(stack[i]=='$' && ip[j]=='$')
printf("\nSUCCESS\n");
else
	printf("ERROR\n");
}
