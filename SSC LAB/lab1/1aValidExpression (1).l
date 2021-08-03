/* Lex program to recognize valid arithmetic expression 
		and identify the identifiers and operators */
/*Section 1*/
%{ 
#include <stdio.h> 
#include <string.h> 
	int operators_count = 0, operands_count = 0, valid = 1, top = -1, i = 0, j = 0; 
	char operands[10][10], operators[10][10], stack[100]; 
%}

/*Section 2*/ 
%% 
"("
{ 
	top++; 
	stack[top] = '('; 
} 

")"
{ 
	if (stack[top] != '(') 
 { 
		valid = 0;	 
} 
	else if(operands_count>0 && (operands_count-operators_count)!=1){ 
		valid=0; 
	} 
	else{ 
		top--; 
		operands_count=1; 
		operators_count=0; 
	} 
} 

"+"|"-"|"*"|"/" { 
	operators_count++; 
	strcpy(operators[i], yytext); 
	i++; 
} 
[0-9]+|[a-zA-Z][a-zA-Z0-9_]* { 
	operands_count++; 
	strcpy(operands[j], yytext); 
	j++; 
} 

\n {return 0;}
%%


/*Section 3*/ 
int yywrap() 
{ 
	return 1; 
} 



/*Section 4*/
int main() 
{ 
	int k; 
	printf("Enter the arithmetic expression: "); 
	yylex(); 

	if (valid == 1 && top == -1 && operands_count>0 && (operands_count-operators_count)==1) { 
		printf("Valid Expression\n");
		printf("Operators List\n");
		for(k=0;k<=i;k++)
			printf("%s\t",operators[k]);
		printf("\nOperands List\n");
		for(k=0;k<=j;k++)
			printf("%s\t",operands[k]);
	} 
	else
		printf("\nInvalid Expression\n"); 

	return 0; 
} 

