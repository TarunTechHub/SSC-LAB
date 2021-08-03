/*program to count the numbers of comment lines in a given program. 
Also eliminate them and copy that program into seperate file.
Run program as ./a.out input.txt output.txt*/
%{
	#include<stdio.h>
	int slc=0,mlc=0,tcl=0;
	int flag=0;
%}
%%
"//".*[\n] {slc++;tcl++;}
"/*" {tcl++;flag=1;}
[\n] {if(flag)tcl++; else ECHO;}
"*/" {if(flag) {mlc++;flag=0;}}
. {if(!flag) ECHO;}
%%

main (int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("No files");
		exit(0);
	}
	yyin=fopen(argv[1],"r");
	yyout=fopen(argv[2],"w");
	yylex();
	printf("Single line comment count:%d\n",slc);
	printf("Multi line comment count:%d\n",mlc);
	printf("Total comment count:%d\n",tcl);
}

