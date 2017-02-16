#define LENGTH 80
char ch[LENGTH],op[LENGTH];
int chptr=0;
int opptr=0;

void main()
{
	extern char push(),pop();
	extern void postfix();
	char expr[LENGTH];
	int i;

	printf("Expression=");
	scanf("%s",&expr);
	postfix(expr);
	for(i=1;i<=chptr;i++)
		printf("%c",ch[i]);
}

void postfix(char s[])
{
	int i=0;
	char temp;
	extern char op[],ch[];
	extern int opptr,chptr;
	while(s[i]!='\0')
	{
		switch(s[i])
		{
		case '(':
			push(op,&opptr,s[i]);
			break;
		case ')':
			do
			push(ch,&chptr,pop(op,&opptr));
			while(op[opptr]!='(' && opptr>=1);
			pop(op,&opptr);
			break;
		case '*':
		case '/':
			if(opptr>0)
				while(opptr>0 && (op[opptr]=='*'||op[opptr]=='/'))
					push(ch,&chptr,pop(op,&opptr);
				push(op,&opptr,s[i]);
				break;
		case '+':
			if(opptr>0)
				while(op[opptr]!='(' && opptr>0)
					push(ch,&opptr,s[i]);
				break;
		default:
			push(ch,&chptr,s[i]);
			break;
		}
		i++;
	}
	for(i=opptr;i>=1;i--)
		if((temp==pop(op,&opptr))!='(')
			push(ch,&chptr,temp);
}

char pop(char array[],int *index)
{
	char temp;
	temp=array[*index];
	(*index)--;
	return(temp);
}

char push(char array[],int *index,char ch)
{
	++(*index);
	array[*index]=ch;
}
