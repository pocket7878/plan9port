
typedef union 
{
	Node	node;
	Var*	var;
	int	numb;
	double	val;
}	YYSTYPE;
extern	YYSTYPE	yylval;
#define	VAL	57346
#define	VAR	57347
#define	SUP	57348
