typedef unsigned char Uchar;
# include <stdio.h>
# define U(x) x
# define NLSTATE yyprevious=YYNEWLINE
# define BEGIN yybgin = yysvec + 1 +
# define INITIAL 0
# define YYLERR yysvec
# define YYSTATE (yyestate-yysvec-1)
# define YYOPTIM 1
# define YYLMAX 200
# define unput(c) {yytchar= (c);if(yytchar=='\n')yylineno--;*yysptr++=yytchar;}
# define yymore() (yymorfg=1)
# define ECHO fprintf(yyout, "%s",yytext)
# define REJECT { nstr = yyreject(); goto yyfussy;}
int yyleng; extern char yytext[];
int yymorfg;
extern Uchar *yysptr, yysbuf[];
int yytchar;
FILE *yyin, *yyout;
extern int yylineno;
struct yysvf { 
	struct yywork *yystoff;
	struct yysvf *yyother;
	int *yystops;};
struct yysvf *yyestate;
extern struct yysvf yysvec[], *yybgin;
int yylook(void), yywrap(void), yyback(int *, int);
# define output(c) putc(c,yyout)
# define input() (((yytchar=yysptr>yysbuf?U(*--yysptr):getc(yyin))==10?(yylineno++,yytchar):yytchar)==EOF?0:yytchar)
#define Display 2
#define Math 4
#define Normal 6
#define Tag 8
#define VerbPlus 10
#define Bracket 12
#define YYNEWLINE 10
int
yylex(void){
int nstr; extern int yyprevious;
if(yyprevious){}
while((nstr = yylook()) >= 0){
goto yyfussy; yyfussy: switch(nstr){
case 0:
if(yywrap()) return(0); break;
case 1:
{yyleng--; yymore(); /* ignore apostrophes */}
break;
case 2:
{yyleng-=2; yymore(); /* ignore hyphens */}
break;
case 3:
;
break;
case 4:
;
break;
case 5:
;
break;
case 6:
{printf("%s\n",yytext); /* any other letter seq is a word */}
break;
case 7:
;
break;
case 8:
;
break;
case 9:
BEGIN Tag;
break;
case 10:
BEGIN Tag;
break;
case 11:
BEGIN Tag;
break;
case 12:
BEGIN Tag;
break;
case 13:
BEGIN Tag;
break;
case 14:
	BEGIN Tag;
break;
case 15:
BEGIN Tag;
break;
case 16:
BEGIN Tag;
break;
case 17:
BEGIN Tag;
break;
case 18:
BEGIN Tag;
break;
case 19:
BEGIN Tag;
break;
case 20:
	BEGIN Tag;
break;
case 21:
BEGIN VerbPlus;
break;
case 22:
BEGIN Bracket;
break;
case 23:
BEGIN Tag;
break;
case 24:
BEGIN Bracket;
break;
case 25:
BEGIN Tag;
break;
case 26:
;
break;
case 27:
;
break;
case 28:
BEGIN Tag;
break;
case 29:
BEGIN Normal;
break;
case 30:
	;
break;
case 31:
	BEGIN Normal;
break;
case 32:
;
break;
case 33:
BEGIN Normal;
break;
case 34:
;
break;
case 35:
	BEGIN Math;
break;
case 36:
	BEGIN Normal;
break;
case 37:
;
break;
case 38:
	BEGIN Display;
break;
case 39:
;
break;
case 40:
BEGIN Normal;
break;
case 41:
;
break;
case 42:
;
break;
case 43:
;
break;
case -1:
break;
default:
fprintf(yyout,"bad switch yylook %d",nstr);
}} return(0); }
/* end of yylex */
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
	int i;
	
	if (argc==1) {
	    yyin = stdin;
	    BEGIN Normal; /* Starts yylex off in the right state */
	    yylex();
	    }
	else for (i=1; i<argc; i++) {
	    yyin = fopen(argv[i],"r");
	    if (yyin==NULL) {
		fprintf(stderr,"can't open %s\n",argv[i]);
		exit(1);
		}
	    BEGIN Normal; /* Starts yylex off in the right state */
	    yylex();
	    }
	exit(0);
}
int
yywrap(void)
{
	return 1;
}
int yyvstop[] = {
0,

39,
0,

39,
0,

37,
0,

37,
0,

43,
0,

7,
43,
0,

1,
43,
0,

34,
43,
0,

5,
43,
0,

43,
0,

43,
0,

43,
-4,
0,

30,
0,

31,
0,

32,
0,

33,
0,

26,
0,

29,
0,

40,
0,

36,
0,

7,
0,

34,
0,

5,
6,
0,

6,
0,

41,
0,

42,
0,

35,
41,
0,

8,
41,
0,

38,
41,
0,

8,
41,
0,

8,
41,
0,

8,
41,
0,

8,
41,
0,

8,
41,
0,

8,
41,
0,

8,
41,
0,

8,
41,
0,

8,
41,
0,

8,
41,
0,

4,
0,

4,
0,

4,
0,

4,
0,

4,
0,

27,
0,

28,
0,

3,
0,

6,
0,

2,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

14,
0,

8,
0,

8,
0,

8,
0,

8,
0,

20,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

13,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

21,
0,

9,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

17,
0,

18,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

10,
0,

8,
0,

8,
0,

8,
0,

8,
0,

15,
0,

19,
0,

8,
0,

8,
0,

12,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

8,
0,

24,
0,

25,
0,

8,
0,

8,
0,

16,
0,

11,
0,

8,
0,

22,
0,

23,
0,
0};
# define YYTYPE Uchar
struct yywork { YYTYPE verify, advance; } yycrank[] = {
0,0,	0,0,	3,15,	0,0,	
0,0,	0,0,	0,0,	0,0,	
5,17,	0,0,	0,0,	3,15,	
35,0,	0,0,	0,0,	0,0,	
7,19,	5,17,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	7,19,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	3,0,	0,0,	4,0,	
0,0,	0,0,	3,15,	5,17,	
3,15,	105,117,	0,0,	3,15,	
5,17,	3,15,	5,17,	7,19,	
7,20,	5,17,	7,21,	5,17,	
7,19,	41,67,	7,19,	0,0,	
8,20,	7,19,	8,21,	7,22,	
0,0,	0,0,	3,15,	0,0,	
0,0,	0,0,	0,0,	0,0,	
5,17,	0,0,	9,27,	0,0,	
0,0,	0,0,	0,0,	0,0,	
7,23,	0,0,	11,29,	9,27,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	11,29,	
0,0,	3,16,	3,15,	4,16,	
3,15,	6,18,	3,15,	5,18,	
5,17,	32,63,	5,17,	53,75,	
5,17,	54,76,	55,77,	7,24,	
7,19,	9,27,	7,25,	49,71,	
7,26,	50,72,	9,27,	8,24,	
9,27,	11,29,	51,73,	9,27,	
52,74,	9,27,	11,29,	56,78,	
11,30,	57,79,	3,15,	11,29,	
69,80,	11,29,	48,69,	70,81,	
5,17,	32,64,	48,70,	71,82,	
72,83,	73,84,	9,27,	74,85,	
7,19,	75,87,	76,88,	77,89,	
13,31,	16,15,	11,29,	78,90,	
79,91,	80,92,	82,96,	83,97,	
74,86,	13,31,	16,15,	81,93,	
84,98,	85,99,	81,94,	86,100,	
18,17,	87,101,	88,102,	89,103,	
90,104,	81,95,	9,27,	91,105,	
9,27,	18,17,	9,27,	92,106,	
93,107,	94,108,	11,29,	95,109,	
11,29,	96,110,	11,29,	13,31,	
16,15,	97,111,	99,112,	100,113,	
13,31,	16,15,	13,31,	16,15,	
101,114,	13,31,	16,15,	13,31,	
16,15,	102,115,	104,116,	18,17,	
106,118,	107,119,	9,28,	108,120,	
18,34,	109,121,	18,17,	111,122,	
112,123,	18,17,	11,29,	18,17,	
13,31,	16,15,	113,124,	114,125,	
115,126,	20,35,	116,127,	119,128,	
120,129,	121,130,	122,131,	123,132,	
126,133,	127,134,	20,0,	128,135,	
18,17,	25,38,	25,38,	25,38,	
25,38,	25,38,	25,38,	25,38,	
25,38,	25,38,	25,38,	129,136,	
13,32,	16,33,	13,31,	16,15,	
13,31,	16,15,	130,137,	131,138,	
133,141,	132,139,	134,142,	136,143,	
20,35,	137,144,	138,145,	139,146,	
18,17,	20,35,	18,17,	20,35,	
18,17,	132,140,	20,35,	142,147,	
20,35,	143,148,	145,149,	146,150,	
147,151,	148,152,	149,153,	150,154,	
13,31,	16,15,	152,157,	153,158,	
151,155,	154,159,	157,160,	158,161,	
161,162,	20,35,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
18,17,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	22,36,	22,36,	
22,36,	22,36,	22,36,	22,36,	
22,36,	22,36,	22,36,	22,36,	
151,156,	20,35,	0,0,	20,35,	
161,163,	20,35,	22,37,	22,38,	
22,38,	22,38,	22,38,	22,38,	
22,38,	22,38,	22,38,	22,38,	
22,38,	22,38,	22,38,	22,38,	
22,38,	22,38,	22,38,	22,38,	
22,38,	22,38,	22,38,	22,38,	
22,38,	22,38,	22,38,	22,38,	
22,38,	20,35,	0,0,	0,0,	
0,0,	22,38,	0,0,	22,38,	
22,38,	22,38,	22,38,	22,38,	
22,38,	22,38,	22,38,	22,38,	
22,38,	22,38,	22,38,	22,38,	
22,38,	22,38,	22,38,	22,38,	
22,38,	22,38,	22,38,	22,38,	
22,38,	22,38,	22,38,	22,38,	
22,38,	23,39,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	23,38,	23,38,	
23,38,	23,38,	23,38,	23,38,	
23,38,	23,38,	23,38,	23,38,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	23,37,	23,40,	
23,40,	23,40,	23,40,	23,40,	
23,40,	23,40,	23,40,	23,40,	
23,40,	23,40,	23,40,	23,40,	
23,40,	23,40,	23,40,	23,40,	
23,40,	23,40,	23,40,	23,40,	
23,40,	23,40,	23,40,	23,40,	
23,40,	0,0,	23,41,	0,0,	
0,0,	23,38,	0,0,	23,42,	
23,42,	23,42,	23,42,	23,42,	
23,42,	23,42,	23,42,	23,42,	
23,42,	23,42,	23,42,	23,42,	
23,42,	23,42,	23,42,	23,42,	
23,42,	23,42,	23,42,	23,42,	
23,42,	23,42,	23,42,	23,42,	
23,42,	24,43,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	24,44,	0,0,	
0,0,	0,0,	0,0,	26,58,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
26,58,	38,38,	38,38,	38,38,	
38,38,	38,38,	38,38,	38,38,	
38,38,	38,38,	38,38,	0,0,	
24,43,	0,0,	0,0,	0,0,	
24,45,	24,43,	0,0,	24,43,	
0,0,	0,0,	24,43,	0,0,	
24,43,	0,0,	26,58,	0,0,	
0,0,	26,59,	0,0,	26,58,	
0,0,	26,58,	0,0,	0,0,	
26,58,	0,0,	26,60,	0,0,	
0,0,	24,46,	60,38,	60,38,	
60,38,	60,38,	60,38,	60,38,	
60,38,	60,38,	60,38,	60,38,	
0,0,	0,0,	26,61,	26,42,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	24,47,	
0,0,	24,43,	0,0,	24,43,	
0,0,	24,46,	24,48,	24,49,	
24,50,	24,51,	0,0,	0,0,	
0,0,	24,52,	26,62,	26,58,	
24,53,	26,60,	0,0,	26,42,	
24,54,	0,0,	24,55,	0,0,	
0,0,	24,56,	24,57,	0,0,	
0,0,	0,0,	0,0,	0,0,	
37,65,	24,43,	37,65,	37,65,	
37,65,	37,65,	37,65,	37,65,	
37,65,	37,65,	37,65,	37,65,	
0,0,	0,0,	0,0,	26,58,	
0,0,	0,0,	0,0,	37,65,	
37,65,	37,65,	37,65,	37,65,	
37,65,	37,65,	37,65,	37,65,	
37,65,	37,65,	37,65,	37,65,	
37,65,	37,65,	37,65,	37,65,	
37,65,	37,65,	37,65,	37,65,	
37,65,	37,65,	37,65,	37,65,	
37,65,	0,0,	0,0,	0,0,	
0,0,	37,65,	0,0,	37,65,	
37,65,	37,65,	37,65,	37,65,	
37,65,	37,65,	37,65,	37,65,	
37,65,	37,65,	37,65,	37,65,	
37,65,	37,65,	37,65,	37,65,	
37,65,	37,65,	37,65,	37,65,	
37,65,	37,65,	37,65,	37,65,	
37,65,	39,39,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	39,66,	
39,66,	39,66,	39,66,	39,66,	
39,66,	39,66,	39,66,	39,66,	
39,66,	39,66,	39,66,	39,66,	
39,66,	39,66,	39,66,	39,66,	
39,66,	39,66,	39,66,	39,66,	
39,66,	39,66,	39,66,	39,66,	
39,66,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	39,66,	
39,66,	39,66,	39,66,	39,66,	
39,66,	39,66,	39,66,	39,66,	
39,66,	39,66,	39,66,	39,66,	
39,66,	39,66,	39,66,	39,66,	
39,66,	39,66,	39,66,	39,66,	
39,66,	39,66,	39,66,	39,66,	
39,66,	42,42,	42,42,	42,42,	
42,42,	42,42,	42,42,	42,42,	
42,42,	42,42,	42,42,	42,42,	
42,42,	42,42,	42,42,	42,42,	
42,42,	42,42,	42,42,	42,42,	
42,42,	42,42,	42,42,	42,42,	
42,42,	42,42,	42,42,	46,68,	
46,68,	46,68,	46,68,	46,68,	
46,68,	46,68,	46,68,	46,68,	
46,68,	46,68,	46,68,	46,68,	
46,68,	46,68,	46,68,	46,68,	
46,68,	46,68,	46,68,	46,68,	
46,68,	46,68,	46,68,	46,68,	
46,68,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	46,68,	
46,68,	46,68,	46,68,	46,68,	
46,68,	46,68,	46,68,	46,68,	
46,68,	46,68,	46,68,	46,68,	
46,68,	46,68,	46,68,	46,68,	
46,68,	46,68,	46,68,	46,68,	
46,68,	46,68,	46,68,	46,68,	
46,68,	0,0,	0,0,	0,0,	
0,0};
struct yysvf yysvec[] = {
0,	0,	0,
yycrank+0,	0,		0,	
yycrank+0,	0,		0,	
yycrank+-1,	0,		0,	
yycrank+-3,	yysvec+3,	0,	
yycrank+-7,	0,		0,	
yycrank+-5,	yysvec+5,	0,	
yycrank+-15,	0,		0,	
yycrank+-23,	yysvec+7,	0,	
yycrank+-73,	0,		0,	
yycrank+0,	yysvec+9,	0,	
yycrank+-81,	0,		0,	
yycrank+0,	yysvec+11,	0,	
yycrank+-143,	0,		0,	
yycrank+0,	yysvec+13,	0,	
yycrank+0,	0,		yyvstop+1,
yycrank+-144,	0,		yyvstop+3,
yycrank+0,	0,		yyvstop+5,
yycrank+-159,	0,		yyvstop+7,
yycrank+0,	0,		yyvstop+9,
yycrank+-212,	0,		yyvstop+11,
yycrank+0,	0,		yyvstop+14,
yycrank+246,	0,		yyvstop+17,
yycrank+330,	0,		yyvstop+20,
yycrank+-452,	0,		yyvstop+23,
yycrank+177,	yysvec+22,	yyvstop+25,
yycrank+-466,	0,		yyvstop+27,
yycrank+0,	0,		yyvstop+30,
yycrank+0,	0,		yyvstop+32,
yycrank+0,	0,		yyvstop+34,
yycrank+0,	0,		yyvstop+36,
yycrank+0,	0,		yyvstop+38,
yycrank+10,	0,		yyvstop+40,
yycrank+0,	0,		yyvstop+42,
yycrank+0,	0,		yyvstop+44,
yycrank+-2,	yysvec+20,	yyvstop+46,
yycrank+0,	yysvec+22,	yyvstop+48,
yycrank+530,	0,		0,	
yycrank+429,	yysvec+22,	0,	
yycrank+614,	0,		0,	
yycrank+0,	yysvec+23,	yyvstop+50,
yycrank+12,	0,		0,	
yycrank+672,	yysvec+23,	yyvstop+53,
yycrank+0,	0,		yyvstop+55,
yycrank+0,	0,		yyvstop+57,
yycrank+0,	0,		yyvstop+59,
yycrank+698,	0,		yyvstop+62,
yycrank+0,	0,		yyvstop+65,
yycrank+29,	yysvec+46,	yyvstop+68,
yycrank+6,	yysvec+46,	yyvstop+71,
yycrank+2,	yysvec+46,	yyvstop+74,
yycrank+8,	yysvec+46,	yyvstop+77,
yycrank+10,	yysvec+46,	yyvstop+80,
yycrank+6,	yysvec+46,	yyvstop+83,
yycrank+8,	yysvec+46,	yyvstop+86,
yycrank+5,	yysvec+46,	yyvstop+89,
yycrank+8,	yysvec+46,	yyvstop+92,
yycrank+24,	yysvec+46,	yyvstop+95,
yycrank+0,	0,		yyvstop+98,
yycrank+0,	yysvec+39,	yyvstop+100,
yycrank+470,	yysvec+22,	yyvstop+102,
yycrank+0,	yysvec+37,	yyvstop+104,
yycrank+0,	yysvec+41,	yyvstop+106,
yycrank+0,	0,		yyvstop+108,
yycrank+0,	0,		yyvstop+110,
yycrank+0,	yysvec+37,	yyvstop+112,
yycrank+0,	yysvec+39,	yyvstop+114,
yycrank+0,	0,		yyvstop+116,
yycrank+0,	yysvec+46,	yyvstop+118,
yycrank+25,	yysvec+46,	yyvstop+120,
yycrank+33,	yysvec+46,	yyvstop+122,
yycrank+19,	yysvec+46,	yyvstop+124,
yycrank+37,	yysvec+46,	yyvstop+126,
yycrank+37,	yysvec+46,	yyvstop+128,
yycrank+40,	yysvec+46,	yyvstop+130,
yycrank+43,	yysvec+46,	yyvstop+132,
yycrank+39,	yysvec+46,	yyvstop+134,
yycrank+41,	yysvec+46,	yyvstop+136,
yycrank+46,	yysvec+46,	yyvstop+138,
yycrank+34,	yysvec+46,	yyvstop+140,
yycrank+44,	yysvec+46,	yyvstop+142,
yycrank+50,	yysvec+46,	yyvstop+144,
yycrank+49,	yysvec+46,	yyvstop+146,
yycrank+34,	yysvec+46,	yyvstop+148,
yycrank+33,	yysvec+46,	yyvstop+150,
yycrank+49,	yysvec+46,	yyvstop+152,
yycrank+42,	yysvec+46,	yyvstop+154,
yycrank+60,	yysvec+46,	yyvstop+156,
yycrank+61,	yysvec+46,	yyvstop+158,
yycrank+40,	yysvec+46,	yyvstop+160,
yycrank+52,	yysvec+46,	yyvstop+162,
yycrank+69,	yysvec+46,	yyvstop+164,
yycrank+61,	yysvec+46,	yyvstop+166,
yycrank+56,	yysvec+46,	yyvstop+168,
yycrank+68,	yysvec+46,	yyvstop+170,
yycrank+59,	yysvec+46,	yyvstop+172,
yycrank+54,	yysvec+46,	yyvstop+174,
yycrank+72,	yysvec+46,	yyvstop+176,
yycrank+0,	0,		yyvstop+178,
yycrank+65,	yysvec+46,	yyvstop+180,
yycrank+67,	yysvec+46,	yyvstop+182,
yycrank+80,	yysvec+46,	yyvstop+184,
yycrank+79,	yysvec+46,	yyvstop+186,
yycrank+0,	0,		yyvstop+188,
yycrank+97,	yysvec+46,	yyvstop+190,
yycrank+2,	yysvec+46,	yyvstop+192,
yycrank+73,	yysvec+46,	yyvstop+194,
yycrank+96,	yysvec+46,	yyvstop+196,
yycrank+88,	yysvec+46,	yyvstop+198,
yycrank+80,	yysvec+46,	yyvstop+200,
yycrank+0,	0,		yyvstop+202,
yycrank+102,	yysvec+46,	yyvstop+204,
yycrank+104,	yysvec+46,	yyvstop+206,
yycrank+87,	yysvec+46,	yyvstop+208,
yycrank+88,	yysvec+46,	yyvstop+210,
yycrank+111,	yysvec+46,	yyvstop+212,
yycrank+115,	yysvec+46,	yyvstop+214,
yycrank+0,	0,		yyvstop+216,
yycrank+0,	0,		yyvstop+218,
yycrank+106,	yysvec+46,	yyvstop+220,
yycrank+113,	yysvec+46,	yyvstop+222,
yycrank+109,	yysvec+46,	yyvstop+224,
yycrank+108,	yysvec+46,	yyvstop+226,
yycrank+118,	yysvec+46,	yyvstop+228,
yycrank+0,	0,		yyvstop+230,
yycrank+0,	0,		yyvstop+232,
yycrank+118,	yysvec+46,	yyvstop+234,
yycrank+114,	yysvec+46,	yyvstop+236,
yycrank+100,	yysvec+46,	yyvstop+238,
yycrank+121,	yysvec+46,	yyvstop+240,
yycrank+141,	yysvec+46,	yyvstop+242,
yycrank+127,	yysvec+46,	yyvstop+244,
yycrank+134,	yysvec+46,	yyvstop+246,
yycrank+121,	yysvec+46,	yyvstop+248,
yycrank+149,	yysvec+46,	yyvstop+250,
yycrank+0,	0,		yyvstop+252,
yycrank+150,	yysvec+46,	yyvstop+254,
yycrank+126,	yysvec+46,	yyvstop+256,
yycrank+151,	yysvec+46,	yyvstop+258,
yycrank+141,	yysvec+46,	yyvstop+260,
yycrank+0,	0,		yyvstop+262,
yycrank+0,	0,		yyvstop+264,
yycrank+156,	yysvec+46,	yyvstop+266,
yycrank+149,	yysvec+46,	yyvstop+268,
yycrank+0,	0,		yyvstop+270,
yycrank+154,	yysvec+46,	yyvstop+272,
yycrank+155,	yysvec+46,	yyvstop+274,
yycrank+163,	yysvec+46,	yyvstop+276,
yycrank+161,	yysvec+46,	yyvstop+278,
yycrank+169,	yysvec+46,	yyvstop+280,
yycrank+146,	yysvec+46,	yyvstop+282,
yycrank+181,	yysvec+46,	yyvstop+284,
yycrank+149,	yysvec+46,	yyvstop+286,
yycrank+156,	yysvec+46,	yyvstop+288,
yycrank+150,	yysvec+46,	yyvstop+290,
yycrank+0,	0,		yyvstop+292,
yycrank+0,	0,		yyvstop+294,
yycrank+151,	yysvec+46,	yyvstop+296,
yycrank+160,	yysvec+46,	yyvstop+298,
yycrank+0,	0,		yyvstop+300,
yycrank+0,	0,		yyvstop+302,
yycrank+185,	yysvec+46,	yyvstop+304,
yycrank+0,	0,		yyvstop+306,
yycrank+0,	0,		yyvstop+308,
0,	0,	0};
struct yywork *yytop = yycrank+820;
struct yysvf *yybgin = yysvec+1;
Uchar yymatch[] = {
00  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,012 ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,'$' ,01  ,01  ,01  ,
01  ,')' ,01  ,'+' ,01  ,01  ,'.' ,01  ,
'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,
'0' ,'0' ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,
'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,
'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,'A' ,
'A' ,'A' ,'A' ,01  ,01  ,']' ,01  ,'_' ,
01  ,'a' ,'a' ,'a' ,'a' ,'a' ,'a' ,'a' ,
'a' ,'a' ,'a' ,'a' ,'a' ,'a' ,'a' ,'a' ,
'a' ,'a' ,'a' ,'a' ,'a' ,'a' ,'a' ,'a' ,
'a' ,'a' ,'a' ,01  ,01  ,'}' ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
0};
Uchar yyextra[] = {
0,0,0,0,1,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0};
/* #pragma lib	"libl.a" */
int yylineno =1;
# define YYU(x) x
char yytext[YYLMAX];
struct yysvf *yylstate [YYLMAX], **yylsp, **yyolsp;
Uchar yysbuf[YYLMAX];
Uchar *yysptr = yysbuf;
int *yyfnd;
extern struct yysvf *yyestate;
int yyprevious = YYNEWLINE;
# ifdef LEXDEBUG
extern void allprint(char);
# endif
int
yylook(void){
	struct yysvf *yystate, **lsp;
	struct yywork *yyt;
	struct yysvf *yyz;
	int yych;
	struct yywork *yyr;
# ifdef LEXDEBUG
	int debug;
# endif
	Uchar *yylastch;
	/* start off machines */
# ifdef LEXDEBUG
	debug = 0;
# endif
	if (!yymorfg)
		yylastch = (Uchar*)yytext;
	else {
		yymorfg=0;
		yylastch = (Uchar*)yytext+yyleng;
		}
	for(;;){
		lsp = yylstate;
		yyestate = yystate = yybgin;
		if (yyprevious==YYNEWLINE) yystate++;
		for (;;){
# ifdef LEXDEBUG
			if(debug)fprintf(yyout,"state %d\n",yystate-yysvec-1);
# endif
			yyt = yystate->yystoff;
			if(yyt == yycrank){		/* may not be any transitions */
				yyz = yystate->yyother;
				if(yyz == 0)break;
				if(yyz->yystoff == yycrank)break;
				}
			*yylastch++ = yych = input();
		tryagain:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"char ");
				allprint(yych);
				putchar('\n');
				}
# endif
			yyr = yyt;
			if (yyt > yycrank){
				yyt = yyr + yych;
				if (yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
# ifdef YYOPTIM
			else if(yyt < yycrank) {		/* r < yycrank */
				yyt = yyr = yycrank+(yycrank-yyt);
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"compressed state\n");
# endif
				yyt = yyt + yych;
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				yyt = yyr + YYU(yymatch[yych]);
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"try fall back character ");
					allprint(YYU(yymatch[yych]));
					putchar('\n');
					}
# endif
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transition */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
			if ((yystate = yystate->yyother) && (yyt= yystate->yystoff) != yycrank){
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"fall back to state %d\n",yystate-yysvec-1);
# endif
				goto tryagain;
				}
# endif
			else
				{unput(*--yylastch);break;}
		contin:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"state %d char ",yystate-yysvec-1);
				allprint(yych);
				putchar('\n');
				}
# endif
			;
			}
# ifdef LEXDEBUG
		if(debug){
			fprintf(yyout,"stopped at %d with ",*(lsp-1)-yysvec-1);
			allprint(yych);
			putchar('\n');
			}
# endif
		while (lsp-- > yylstate){
			*yylastch-- = 0;
			if (*lsp != 0 && (yyfnd= (*lsp)->yystops) && *yyfnd > 0){
				yyolsp = lsp;
				if(yyextra[*yyfnd]){		/* must backup */
					while(yyback((*lsp)->yystops,-*yyfnd) != 1 && lsp > yylstate){
						lsp--;
						unput(*yylastch--);
						}
					}
				yyprevious = YYU(*yylastch);
				yylsp = lsp;
				yyleng = yylastch-(Uchar*)yytext+1;
				yytext[yyleng] = 0;
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"\nmatch '%s'", yytext);
					fprintf(yyout," action %d\n",*yyfnd);
					}
# endif
				return(*yyfnd++);
				}
			unput(*yylastch);
			}
		if (yytext[0] == 0  /* && feof(yyin) */)
			{
			yysptr=yysbuf;
			return(0);
			}
		yyprevious = input();
		yytext[0] = yyprevious;
		if (yyprevious>0)
			output(yyprevious);
		yylastch = (Uchar*)yytext;
# ifdef LEXDEBUG
		if(debug)putchar('\n');
# endif
		}
	return(0);	/* shut up the compiler; i have no idea what should be returned */
	}
int
yyback(int *p, int m)
{
if (p==0) return(0);
while (*p)
	{
	if (*p++ == m)
		return(1);
	}
return(0);
}
	/* the following are only used in the lex library */
int
yyinput(void){
	if(yyin == ((void*)0))
		yyin = stdin;
	return(input());
}
void
yyoutput(int c)
{
	if(yyout == ((void*)0))
		yyout = stdin;
	output(c);
}
void
yyunput(int c)
{
	unput(c);
}
