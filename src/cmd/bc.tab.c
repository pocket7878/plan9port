
#line	2	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
	#include	<u.h>
	#include	<libc.h>
	#include	<bio.h>

	#define	bsp_max	5000

	Biobuf	*in;
	Biobuf	bstdin;
	Biobuf	bstdout;
	char	cary[1000];
	char*	cp = { cary };
	char	string[1000];
	char*	str = { string };
	int	crs = 128;
	int	rcrs = 128;	/* reset crs */
	int	bindx = 0;
	int	lev = 0;
	int	ln;
	char*	ttp;
	char*	ss = "";
	int	bstack[10] = { 0 };
	char*	numb[15] =
	{
		" 0", " 1", " 2", " 3", " 4", " 5",
		" 6", " 7", " 8", " 9", " 10", " 11",
		" 12", " 13", " 14"
	};
	char*	pre;
	char*	post;

	long	peekc = -1;
	int	sargc;
	int	ifile;
	char**	sargv;

	char	*funtab[] =
	{
		"<1>","<2>","<3>","<4>","<5>",
		"<6>","<7>","<8>","<9>","<10>",
		"<11>","<12>","<13>","<14>","<15>",
		"<16>","<17>","<18>","<19>","<20>",
		"<21>","<22>","<23>","<24>","<25>",
		"<26>"
	};
	char	*atab[] =
	{
		"<221>","<222>","<223>","<224>","<225>",
		"<226>","<227>","<228>","<229>","<230>",
		"<231>","<232>","<233>","<234>","<235>",
		"<236>","<237>","<238>","<239>","<240>",
		"<241>","<242>","<243>","<244>","<245>",
		"<246>"
	};
	char*	letr[26] =
	{
		"a","b","c","d","e","f","g","h","i","j",
		"k","l","m","n","o","p","q","r","s","t",
		"u","v","w","x","y","z"
	};
	char*	dot = { "." };
	char*	bspace[bsp_max];
	char**	bsp_nxt = bspace;
	int	bdebug = 0;
	int	lflag;
	int	cflag;
	int	sflag;

	char*	bundle(int, ...);
	void	conout(char*, char*);
	int	cpeek(int, int, int);
	int	getch(void);
	char*	geta(char*);
	char*	getf(char*);
	void	getout(void);
	void	output(char*);
	void	pp(char*);
	void	routput(char*);
	void	tp(char*);
	void	yyerror(char*, ...);
	int	yyparse(void);

	typedef	void*	pointer;
	#pragma	varargck	type	"lx"	pointer


#line	87	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
typedef union 
{
	char*	cptr;
	int	cc;
} YYSTYPE;
extern	int	yyerrflag;
#ifndef	YYMAXDEPTH
#define	YYMAXDEPTH	150
#endif
YYSTYPE	yylval;
YYSTYPE	yyval;
#define	LETTER	57346
#define	EQOP	57347
#define	_AUTO	57348
#define	DOT	57349
#define	DIGIT	57350
#define	SQRT	57351
#define	LENGTH	57352
#define	_IF	57353
#define	FFF	57354
#define	EQ	57355
#define	_PRINT	57356
#define	_WHILE	57357
#define	_FOR	57358
#define	NE	57359
#define	LE	57360
#define	GE	57361
#define	INCR	57362
#define	DECR	57363
#define	_RETURN	57364
#define	_BREAK	57365
#define	_DEFINE	57366
#define	BASE	57367
#define	OBASE	57368
#define	SCALE	57369
#define	QSTR	57370
#define	ERROR	57371
#define	UMINUS	57372
#define YYEOFCODE 1
#define YYERRCODE 2

#line	587	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"


int
yylex(void)
{
	int c, ch;

restart:
	c = getch();
	peekc = -1;
	while(c == ' ' || c == '\t')
		c = getch();
	if(c == '\\') {
		getch();
		goto restart;
	}
	if(c >= 'a' && c <= 'z') {
		/* look ahead to look for reserved words */
		peekc = getch();
		if(peekc >= 'a' && peekc <= 'z') { /* must be reserved word */
			if(c=='p' && peekc=='r') {
				c = _PRINT;
				goto skip;
			}
			if(c=='i' && peekc=='f') {
				c = _IF;
				goto skip;
			}
			if(c=='w' && peekc=='h') {
				c = _WHILE;
				goto skip;
			}
			if(c=='f' && peekc=='o') {
				c = _FOR;
				goto skip;
			}
			if(c=='s' && peekc=='q') {
				c = SQRT;
				goto skip;
			}
			if(c=='r' && peekc=='e') {
				c = _RETURN;
				goto skip;
			}
			if(c=='b' && peekc=='r') {
				c = _BREAK;
				goto skip;
			}
			if(c=='d' && peekc=='e') {
				c = _DEFINE;
				goto skip;
			}
			if(c=='s' && peekc=='c') {
				c = SCALE;
				goto skip;
			}
			if(c=='b' && peekc=='a') {
				c = BASE;
				goto skip;
			}
			if(c=='i' && peekc=='b') {
				c = BASE;
				goto skip;
			}
			if(c=='o' && peekc=='b') {
				c = OBASE;
				goto skip;
			}
			if(c=='d' && peekc=='i') {
				c = FFF;
				goto skip;
			}
			if(c=='a' && peekc=='u') {
				c = _AUTO;
				goto skip;
			}
			if(c=='l' && peekc=='e') {
				c = LENGTH;
				goto skip;
			}
			if(c=='q' && peekc=='u')
				getout();
			/* could not be found */
			return ERROR;

		skip:	/* skip over rest of word */
			peekc = -1;
			for(;;) {
				ch = getch();
				if(ch < 'a' || ch > 'z')
					break;
			}
			peekc = ch;
			return c;
		}

		/* usual case; just one single letter */
		yylval.cptr = letr[c-'a'];
		return LETTER;
	}
	if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')) {
		yylval.cc = c;
		return DIGIT;
	}
	switch(c) {
	case '.':
		return DOT;
	case '*':
		yylval.cptr = "*";
		return cpeek('=', EQOP, c);
	case '%':
		yylval.cptr = "%%";
		return cpeek('=', EQOP, c);
	case '^':
		yylval.cptr = "^";
		return cpeek('=', EQOP, c);
	case '+':
		ch = cpeek('=', EQOP, c);
		if(ch == EQOP) {
			yylval.cptr = "+";
			return ch;
		}
		return cpeek('+', INCR, c);
	case '-':
		ch = cpeek('=', EQOP, c);
		if(ch == EQOP) {
			yylval.cptr = "-";
			return ch;
		}
		return cpeek('-', DECR, c);
	case '=':
		return cpeek('=', EQ, '=');
	case '<':
		return cpeek('=', LE, '<');
	case '>':
		return cpeek('=', GE, '>');
	case '!':
		return cpeek('=', NE, '!');
	case '/':
		ch = cpeek('=', EQOP, c);
		if(ch == EQOP) {
			yylval.cptr = "/";
			return ch;
		}
		if(peekc == '*') {
			peekc = -1;
			for(;;) {
				ch = getch();
				if(ch == '*') {
					peekc = getch();
					if(peekc == '/') {
						peekc = -1;
						goto restart;
					}
				}
			}
		}
		return c;
	case '"':
		yylval.cptr = str;
		while((c=getch()) != '"'){
			*str++ = c;
			if(str >= &string[999]){
				yyerror("string space exceeded");
				getout();
			}
		}
		*str++ = 0;
		return QSTR;
	default:
		return c;
	}
}

int
cpeek(int c, int yes, int no)
{

	peekc = getch();
	if(peekc == c) {
		peekc = -1;
		return yes;
	}
	return no;
}

int
getch(void)
{
	long ch;

loop:
	ch = peekc;
	if(ch < 0){
		if(in == 0)
			ch = -1;
		else
			ch = Bgetc(in);
	}
	peekc = -1;
	if(ch >= 0)
		return ch;

	ifile++;
	if(ifile >= sargc) {
		if(ifile >= sargc+1)
			getout();
		in = &bstdin;
		Binit(in, 0, OREAD);
		ln = 0;
		goto loop;
	}
	if(in)
		Bterm(in);
	if((in = Bopen(sargv[ifile], OREAD)) != 0){
		ln = 0;
		ss = sargv[ifile];
		goto loop;
	}
	fprint(2, "open %s: %r\n", sargv[ifile]);
	yyerror("cannot open input file");
	return 0;		/* shut up ken */
}

char*
bundle(int a, ...)
{
	int i;
	char **q;
	va_list arg;
	
	i = a;
	va_start(arg, a);
	q = bsp_nxt;
	if(bdebug)
		fprint(2, "bundle %d elements at %lx\n", i, q);
	while(i-- > 0) {
		if(bsp_nxt >= &bspace[bsp_max])
			yyerror("bundling space exceeded");
		*bsp_nxt++ = va_arg(arg, char*);
	}
	*bsp_nxt++ = 0;
	va_end(arg);
	yyval.cptr = (char*)q;
	return (char*)q;
}

void
routput(char *p)
{
	char **pp;
	
	if(bdebug)
		fprint(2, "routput(%lx)\n", p);
	if((char**)p >= &bspace[0] && (char**)p < &bspace[bsp_max]) {
		/* part of a bundle */
		pp = (char**)p;
		while(*pp != 0)
			routput(*pp++);
	} else
		Bprint(&bstdout, p);	/* character string */
}

void
output(char *p)
{
	routput(p);
	bsp_nxt = &bspace[0];
	Bprint(&bstdout, "\n");
	Bflush(&bstdout);
	cp = cary;
	crs = rcrs;
}

void
conout(char *p, char *s)
{
	Bprint(&bstdout, "[");
	routput(p);
	Bprint(&bstdout, "]s%s\n", s);
	Bflush(&bstdout);
	lev--;
}

void
yyerror(char *s, ...)
{
	if(ifile > sargc)
		ss = "teletype";
	Bprint(&bstdout, "c[%s:%d, %s]pc\n", s, ln+1, ss);
	Bflush(&bstdout);
	cp = cary;
	crs = rcrs;
	bindx = 0;
	lev = 0;
	bsp_nxt = &bspace[0];
}

void
pp(char *s)
{
	/* puts the relevant stuff on pre and post for the letter s */
	bundle(3, "S", s, pre);
	pre = yyval.cptr;
	bundle(4, post, "L", s, "s.");
	post = yyval.cptr;
}

void
tp(char *s)
{
	/* same as pp, but for temps */
	bundle(3, "0S", s, pre);
	pre = yyval.cptr;
	bundle(4, post, "L", s, "s.");
	post = yyval.cptr;
}

void
yyinit(int argc, char **argv)
{
	Binit(&bstdout, 1, OWRITE);
	sargv = argv;
	sargc = argc;
	if(sargc == 0) {
		in = &bstdin;
		Binit(in, 0, OREAD);
	} else if((in = Bopen(sargv[0], OREAD)) == 0)
		yyerror("cannot open input file");
	ifile = 0;
	ln = 0;
	ss = sargv[0];
}

void
getout(void)
{
	Bprint(&bstdout, "q");
	Bflush(&bstdout);
	exits(0);
}

char*
getf(char *p)
{
	return funtab[*p - 'a'];
}

char*
geta(char *p)
{
	return atab[*p - 'a'];
}

void
main(int argc, char **argv)
{
	int p[2];

	ARGBEGIN{
	case 'd':
		bdebug++;
		break;
	case 'c':
		cflag++;
		break;
	case 'l':
		lflag++;
		break;
	case 's':
		sflag++;
		break;
	default:
		fprint(2, "Usage: bc [-l] [-c] [file ...]\n");
		exits("usage");
	}ARGEND
	
	if(lflag) {
		argc++;
		argv--;
		*argv = unsharp("#9/lib/bclib");
	}
	if(cflag) {
		yyinit(argc, argv);
		for(;;)
			yyparse();
		exits(0);
	}
	pipe(p);
	if(fork() == 0) {
		dup(p[1], 1);
		close(p[0]);
		close(p[1]);
		yyinit(argc, argv);
		for(;;)
			yyparse();
	}
	dup(p[0], 0);
	close(p[0]);
	close(p[1]);
	execl(unsharp("#9/bin/dc"), "dc", nil);
}
static	const	short	yyexca[] =
{-1, 1,
	1, -1,
	-2, 11,
-1, 6,
	42, 10,
	44, 10,
	-2, 93,
-1, 8,
	40, 12,
	42, 12,
	44, 12,
	-2, 92,
-1, 69,
	40, 8,
	42, 8,
	44, 8,
	-2, 93,
};
#define	YYNPROD	111
#define	YYPRIVATE 57344
#define	YYLAST	488
static	const	short	yyact[] =
{
  32,  42, 116, 115,  60,   6,   6,  38,  59,   8,
   8, 118,  66, 126,  67,  58,  65, 158,  23, 102,
  40,  69,  39,  74, 144,   8,  36, 132, 199, 159,
 131, 103,  93, 104, 149, 147,  94,  95,  96,  97,
  98,  99,  40,  76,  39, 117, 106, 107, 105, 100,
 108, 109, 110, 184,  92, 111, 112,  94,  95,  96,
  97,  98,  99,  94,  95,  96,  97,  98,  99,  35,
  47,  48,  91, 119, 183, 192, 142,  40, 123,  39,
 157, 127, 129, 130, 114, 187,  40,  46,  39, 169,
  99,  49, 133, 134, 122, 135, 136, 137, 138, 139,
 140, 141,  47,  48, 120, 143,  94,  95,  96,  97,
  98,  99,  45,  96,  97,  98,  99, 165, 119, 101,
  69, 156,  82,  49,   8,  56,  57,  52,  53, 148,
 146,  75, 161, 162,  43, 113,  73,  78,  79,  94,
  95,  96,  97,  98,  99,  44, 167,  81, 119, 166,
 170, 171, 172, 173, 174, 175, 176,  41,  80, 168,
 127, 123,  70,   1, 160,  94,  95,  96,  97,  98,
  99,  69, 189, 181,  69,   8,  34, 124,   8, 185,
 190, 191,  71,  72, 188,  68,   5,   5, 194,  20,
 193, 196,  69,   4,  69,  87,   8, 198,   8,   3,
 200, 201, 195,  25, 197, 186,  24,  36,  30,  28,
  18,  17,   0,  14,  19,  33,  89,  90,  88,  26,
  27,  15,  13,  83,  10,  11,   9,  12,   2,   0,
  37,  31,  94,  95,  96,  97,  98,  99,  16, 164,
  22,   0,  21,   0,  85,  86,  84,   0,  29,  25,
  35,   0,  24,  36,  30,  28,  18,  17,   0,  14,
  19,  33,   0,   0,   0,  26,  27,  15,  13,   7,
  10,  11,   9,  12,   0,   0,   0,  31,  94,  95,
  96,  97,  98,  99,  16, 163,  22,   0,  21,   0,
   0,   0,   0,   0,  29,  25,  35,   0,  24,  36,
  30,  28,  18,  17,   0,  14,  19,  33,   0,   0,
   0,  26,  27,  15,  13,   0,  10,  11,   9,  12,
   0,  82,  25,  31,   0,  24,  36,  30,  28,   0,
  16,   0,  22,   0,  21,   0,  78,  79,  26,  27,
  29,   0,  35,  62,  63,  61,  81,   0,   0,   0,
  31,  94,  95,  96,  97,  98,  99,  80, 145,  22,
   0,  64,   0,  77,   0,   0, 182,  29, 128,  35,
   0,  24,  36,  30,  28,  94,  95,  96,  97,  98,
  99,   0, 121,   0,  26,  27,   0,   0,   0,  62,
  63,  61,   0,   0, 180,  25,  31,   0,  24,  36,
  30,  28, 125,   0,   0,  22,   0,  64,   0, 177,
 178,  26,  27,  29,   0,  35,  62,  63,  61, 179,
   0,  55, 128,  31,   0,  24,  36,  30,  28,   0,
   0,   0,  22,   0,  64,   0,  56,  57,  26,  27,
  29,   0,  35,  62,  63,  61,  54,   0,   0,   0,
  31,   0, 150,   0,   0,   0, 153, 155, 154,  22,
   0,  64,  51,   0,   0,   0,   0,  29,   0,  35,
  94,  95,  96,  97,  98,  99,   0,  52,  53,   0,
   0,   0,   0,   0, 151, 152,   0,  50
};
static	const	short	yypact[] =
{
 245, 245,-1000,   0, 130,-1000,-1000, 141,-1000,  82,
 457, 416,-1000,-1000, 391, 391, 291,-1000,-1000,-1000,
-1000, 132, 391, 124,  18, 316, 219, 191,  31,-1000,
  13, 391, 108,   8, 111,-1000,-1000,-1000,-1000,-1000,
-1000, -19,-1000, -14,   7, 391, 391,-1000,-1000, 391,
 391, 391,-1000,-1000, 391, 391,-1000,-1000, 108,-1000,
-1000,  50, 107, 105, 131, 108,  44,-1000,-1000,-1000,
-1000,   4, 391,  74, 344,  18,-1000, 391,-1000,-1000,
 364, 391, 391, -17,-1000,-1000,-1000, -20,-1000,-1000,
-1000, 391, 391,  80, 391, 391, 391, 391, 391, 391,
 391,-1000,  37, 130, -24,-1000, 108, 108, 320, 108,
 108, 108, 108,-1000,-1000, 291,  -6, 391,  -8, 439,
 391,-1000,-1000,  32, -21,-1000,-1000, 108, 117, 108,
 108, 391, 391, 247, 201,  80,  80,  54,  54,  54,
  54,  75,   0,-1000,-1000,-1000,-1000, 391,  51, 391,
 391, 391, 391, 391, 391, 391, 108, 389,-1000, 418,
 318,  26,   5,-1000,-1000,-1000, 199,-1000,  47, 291,
 134, 108, 108, 108, 108, 108, 108,-1000,-1000, 391,
 391,-1000,-1000,-1000,-1000,  35, 130, 291,-1000, 291,
 108, 108,-1000, -22,-1000,-1000,-1000,-1000,-1000, 130,
-1000,-1000
};
static	const	short	yypgo[] =
{
   0, 199,  14, 185, 193,  12, 190,   0,   8,   4,
  11, 189, 177,  13,  18, 176,   1, 162, 163, 228,
   3, 157, 149,   2
};
static	const	short	yyr1[] =
{
   0,  18,  18,  19,  19,  22,  22,   2,   2,   1,
   1,   3,   3,   3,   3,   3,   3,   3,   3,   3,
   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,
  11,  23,   5,   5,  20,  20,  10,  10,  10,  10,
  10,  10,  10,   9,   9,   9,   9,   9,   9,   9,
   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,
   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,
   9,   9,   9,   9,   9,   9,   9,   9,   9,   9,
   9,   9,   9,   9,   9,   9,   9,   9,   8,   8,
   8,   8,   7,   7,  12,  12,  13,  13,  14,  15,
  15,  15,  17,   4,  21,  21,  21,   6,   6,  16,
  16
};
static	const	short	yyr2[] =
{
   0,   2,   1,   2,   7,   1,   4,   1,   1,   1,
   1,   0,   1,   3,   3,   3,   3,   3,   3,   1,
   1,   2,   2,   1,   3,   1,   7,   7,   8,   4,
   4,   0,   1,   3,   1,   1,   3,   3,   3,   3,
   3,   3,   1,   3,   1,   2,   3,   2,   1,   4,
   2,   2,   2,   2,   5,   5,   5,   5,   2,   2,
   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,
   4,   3,   1,   4,   4,   1,   4,   2,   1,   1,
   1,   2,   3,   3,   3,   3,   3,   3,   3,   6,
   3,   6,   1,   1,   1,   3,   1,   3,   1,   1,
   1,   2,   0,   3,   0,   1,   3,   1,   3,   1,
   3
};
static	const	short	yychk[] =
{
-1000, -18, -19,  -1,  -4,  -3,  -9,  24,  -8,  27,
  25,  26,  28,  23,  14,  22,  39,  12,  11,  15,
 -11,  43,  41, -14,   7,   4,  20,  21,  10,  49,
   9,  32,  -7,  16, -15,  51,   8, -19, -20,  44,
  42, -21, -16,   4,   4,  30,   5,  20,  21,  41,
  30,   5,  20,  21,  30,   5,  20,  21,  -7,  -8,
  -9,  27,  25,  26,  43,  -7,  -5,  -2,  -3,  -9,
 -17, -17, -17,   4,  -7,   7, -14,  47,  20,  21,
  41,  30,   5,   4,  27,  25,  26,   4,  27,  25,
  26,  41,  41,  -7,  31,  32,  33,  34,  35,  36,
  41,   8,  38,  50,  47,  41,  -7,  -7,  -7,  -7,
  -7,  -7,  -7,   4,  40, -20, -23,  41, -10,  -7,
  30,  38, -14,  -7, -12,  38, -13,  -7,   4,  -7,
  -7,  47,  47,  -7,  -7,  -7,  -7,  -7,  -7,  -7,
  -7,  -7,  39, -16,  48,  38,  -2,  41, -10,  42,
  13,  45,  46,  17,  19,  18,  -7,  48,  38,  50,
  47,  -7,  -7,  38,  38,  42, -22, -20, -10,  38,
  -7,  -7,  -7,  -7,  -7,  -7,  -7,  20,  21,  30,
   5, -13,  48,  48,  48,  -5,   6,  38,  -2,  38,
  -7,  -7,  40,  -6, -16,  -2, -23,  -2, -20,  50,
 -23, -16
};
static	const	short	yydef[] =
{
  11,  -2,   2,   0, 104,   9,  -2,   0,  -2,  78,
  79,  80,  19,  20,   0,  23,  11,  25, 102, 102,
 102,   0,   0,  44,  48,  72,   0,   0,   0,  75,
   0,   0,   0,   0,  98,  99, 100,   1,   3,  34,
  35,   0, 105, 109,   0,   0,   0,  58,  60,   0,
   0,   0,  62,  64,   0,   0,  66,  68,  21,  92,
  93,  78,  79,  80,   0,  22,   0,  32,   7,  -2,
  31,   0,   0,  77,   0,  47,  45,   0,  50,  53,
   0,   0,   0,  51,  59,  63,  67,  52,  61,  65,
  69,   0,   0,  81,   0,   0,   0,   0,   0,   0,
   0, 101,   0,   0,   0, 103,  13,  14,   0,  15,
  16,  17,  18,  77,  24,  11,   0,   0,   0,  42,
   0,  43,  46,   0,   0,  71,  94,  96,  72,  88,
  90,   0,   0,   0,   0,  82,  83,  84,  85,  86,
  87,   0,   0, 106, 110,  74,  33,   0,   0,   0,
   0,   0,   0,   0,   0,   0,  29,  49,  70,   0,
   0,   0,   0,  73,  76,  30,  11,   5,   0,  11,
   0,  36,  37,  38,  39,  40,  41,  54,  56,   0,
   0,  95,  97,  55,  57,   0,   0,  11,  31,  11,
  89,  91,   4,   0, 107,  26,  27,  31,   6,   0,
  28, 108
};
static	const	short	yytok1[] =
{
   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  44,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,  35,   0,   0,
  41,  38,  33,  31,  50,  32,   0,  34,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,  42,
  45,  30,  46,  49,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,  47,   0,  48,  36,  51,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,  39,   0,  40,  43
};
static	const	short	yytok2[] =
{
   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,
  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,
  22,  23,  24,  25,  26,  27,  28,  29,  37
};
static	const	long	yytok3[] =
{
   0
};
#define YYFLAG 		-1000
#define YYERROR		goto yyerrlab
#define YYACCEPT	return(0)
#define YYABORT		return(1)
#define	yyclearin	yychar = -1
#define	yyerrok		yyerrflag = 0

#ifdef	yydebug
#include	"y.debug"
#else
#define	yydebug		0
static	const	char*	yytoknames[1];		/* for debugging */
static	const	char*	yystates[1];		/* for debugging */
#endif

/*	parser for yacc output	*/
#ifdef YYARG
#define	yynerrs		yyarg->yynerrs
#define	yyerrflag	yyarg->yyerrflag
#define yyval		yyarg->yyval
#define yylval		yyarg->yylval
#else
int	yynerrs = 0;		/* number of errors */
int	yyerrflag = 0;		/* error recovery flag */
#endif

extern	int	fprint(int, char*, ...);
extern	int	sprint(char*, char*, ...);

static const char*
yytokname(int yyc)
{
	static char x[10];

	if(yyc > 0 && yyc <= sizeof(yytoknames)/sizeof(yytoknames[0]))
	if(yytoknames[yyc-1])
		return yytoknames[yyc-1];
	sprint(x, "<%d>", yyc);
	return x;
}

static const char*
yystatname(int yys)
{
	static char x[10];

	if(yys >= 0 && yys < sizeof(yystates)/sizeof(yystates[0]))
	if(yystates[yys])
		return yystates[yys];
	sprint(x, "<%d>\n", yys);
	return x;
}

static long
#ifdef YYARG
yylex1(struct Yyarg *yyarg)
#else
yylex1(void)
#endif
{
	long yychar;
	const long *t3p;
	int c;

#ifdef YYARG	
	yychar = yylex(yyarg);
#else
	yychar = yylex();
#endif
	if(yychar <= 0) {
		c = yytok1[0];
		goto out;
	}
	if(yychar < sizeof(yytok1)/sizeof(yytok1[0])) {
		c = yytok1[yychar];
		goto out;
	}
	if(yychar >= YYPRIVATE)
		if(yychar < YYPRIVATE+sizeof(yytok2)/sizeof(yytok2[0])) {
			c = yytok2[yychar-YYPRIVATE];
			goto out;
		}
	for(t3p=yytok3;; t3p+=2) {
		c = t3p[0];
		if(c == yychar) {
			c = t3p[1];
			goto out;
		}
		if(c == 0)
			break;
	}
	c = 0;

out:
	if(c == 0)
		c = yytok2[1];	/* unknown char */
	if(yydebug >= 3)
		fprint(2, "lex %.4lux %s\n", yychar, yytokname(c));
	return c;
}

int
#ifdef YYARG
yyparse(struct Yyarg *yyarg)
#else
yyparse(void)
#endif
{
	struct
	{
		YYSTYPE	yyv;
		int	yys;
	} yys[YYMAXDEPTH], *yyp, *yypt;
	const short *yyxi;
	int yyj, yym, yystate, yyn, yyg;
	long yychar;
#ifndef YYARG
	YYSTYPE save1, save2;
	int save3, save4;

	save1 = yylval;
	save2 = yyval;
	save3 = yynerrs;
	save4 = yyerrflag;
#endif

	yystate = 0;
	yychar = -1;
	yynerrs = 0;
	yyerrflag = 0;
	yyp = &yys[0];
	yyp--;
	goto yystack;

ret0:
	yyn = 0;
	goto ret;

ret1:
	yyn = 1;
	goto ret;

ret:
#ifndef YYARG
	yylval = save1;
	yyval = save2;
	yynerrs = save3;
	yyerrflag = save4;
#endif
	return yyn;

yystack:
	/* put a state and value onto the stack */
	if(yydebug >= 4)
		fprint(2, "char %s in %s", yytokname(yychar), yystatname(yystate));

	yyp++;
	if(yyp >= &yys[YYMAXDEPTH]) {
		yyerror("yacc stack overflow");
		goto ret1;
	}
	yyp->yys = yystate;
	yyp->yyv = yyval;

yynewstate:
	yyn = yypact[yystate];
	if(yyn <= YYFLAG)
		goto yydefault; /* simple state */
	if(yychar < 0)
#ifdef YYARG
		yychar = yylex1(yyarg);
#else
		yychar = yylex1();
#endif
	yyn += yychar;
	if(yyn < 0 || yyn >= YYLAST)
		goto yydefault;
	yyn = yyact[yyn];
	if(yychk[yyn] == yychar) { /* valid shift */
		yychar = -1;
		yyval = yylval;
		yystate = yyn;
		if(yyerrflag > 0)
			yyerrflag--;
		goto yystack;
	}

yydefault:
	/* default state action */
	yyn = yydef[yystate];
	if(yyn == -2) {
		if(yychar < 0)
#ifdef YYARG
		yychar = yylex1(yyarg);
#else
		yychar = yylex1();
#endif

		/* look through exception table */
		for(yyxi=yyexca;; yyxi+=2)
			if(yyxi[0] == -1 && yyxi[1] == yystate)
				break;
		for(yyxi += 2;; yyxi += 2) {
			yyn = yyxi[0];
			if(yyn < 0 || yyn == yychar)
				break;
		}
		yyn = yyxi[1];
		if(yyn < 0)
			goto ret0;
	}
	if(yyn == 0) {
		/* error ... attempt to resume parsing */
		switch(yyerrflag) {
		case 0:   /* brand new error */
			yyerror("syntax error");
			if(yydebug >= 1) {
				fprint(2, "%s", yystatname(yystate));
				fprint(2, "saw %s\n", yytokname(yychar));
			}
			goto yyerrlab;
		yyerrlab:
			yynerrs++;

		case 1:
		case 2: /* incompletely recovered error ... try again */
			yyerrflag = 3;

			/* find a state where "error" is a legal shift action */
			while(yyp >= yys) {
				yyn = yypact[yyp->yys] + YYERRCODE;
				if(yyn >= 0 && yyn < YYLAST) {
					yystate = yyact[yyn];  /* simulate a shift of "error" */
					if(yychk[yystate] == YYERRCODE)
						goto yystack;
				}

				/* the current yyp has no shift onn "error", pop stack */
				if(yydebug >= 2)
					fprint(2, "error recovery pops state %d, uncovers %d\n",
						yyp->yys, (yyp-1)->yys );
				yyp--;
			}
			/* there is no state on the stack with an error shift ... abort */
			goto ret1;

		case 3:  /* no shift yet; clobber input char */
			if(yydebug >= 2)
				fprint(2, "error recovery discards %s\n", yytokname(yychar));
			if(yychar == YYEOFCODE)
				goto ret1;
			yychar = -1;
			goto yynewstate;   /* try again in the same state */
		}
	}

	/* reduction by production yyn */
	if(yydebug >= 2)
		fprint(2, "reduce %d in:\n\t%s", yyn, yystatname(yystate));

	yypt = yyp;
	yyp -= yyr2[yyn];
	yyval = (yyp+1)->yyv;
	yym = yyn;

	/* consult goto table to find next state */
	yyn = yyr1[yyn];
	yyg = yypgo[yyn];
	yyj = yyg + yyp->yys + 1;

	if(yyj >= YYLAST || yychk[yystate=yyact[yyj]] != -yyn)
		yystate = yyact[yyg];
	switch(yym) {
		
case 3:
#line	116	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		output(yypt[-1].yyv.cptr);
	} break;
case 4:
#line	120	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		ttp = bundle(6, pre, yypt[-1].yyv.cptr, post , "0", numb[lev], "Q");
		conout(ttp, (char*)yypt[-6].yyv.cptr);
		rcrs = crs;
		output("");
		lev = bindx = 0;
	} break;
case 8:
#line	135	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		if(sflag)
			bundle(2, yypt[-0].yyv.cptr, "s.");
	} break;
case 9:
#line	142	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		if(sflag)
			bundle(2, yypt[-0].yyv.cptr, "0");
	} break;
case 10:
#line	147	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		if(!sflag)
			bundle(2, yypt[-0].yyv.cptr, "ps.");
	} break;
case 11:
#line	153	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "");
	} break;
case 12:
#line	157	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(2, yypt[-0].yyv.cptr, "s.");
	} break;
case 13:
#line	161	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(2, yypt[-0].yyv.cptr, "k");
	} break;
case 14:
#line	165	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(4, "K", yypt[-0].yyv.cptr, yypt[-1].yyv.cptr, "k");
	} break;
case 15:
#line	169	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(2, yypt[-0].yyv.cptr, "i");
	} break;
case 16:
#line	173	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(4, "I", yypt[-0].yyv.cptr, yypt[-1].yyv.cptr, "i");
	} break;
case 17:
#line	177	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(2, yypt[-0].yyv.cptr, "o");
	} break;
case 18:
#line	181	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(4, "O", yypt[-0].yyv.cptr, yypt[-1].yyv.cptr, "o");
	} break;
case 19:
#line	185	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, "[", yypt[-0].yyv.cc, "]P");
	} break;
case 20:
#line	189	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(2, numb[lev-bstack[bindx-1]], "Q");
	} break;
case 21:
#line	193	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(2, yypt[-0].yyv.cptr, "ps.");
	} break;
case 22:
#line	197	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(4, yypt[-0].yyv.cptr, post, numb[lev], "Q");
	} break;
case 23:
#line	201	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(4, "0", post, numb[lev], "Q");
	} break;
case 24:
#line	205	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		yyval.cptr = yypt[-1].yyv.cptr;
	} break;
case 25:
#line	209	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "fY");
	} break;
case 26:
#line	213	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		conout(yypt[-0].yyv.cptr, yypt[-5].yyv.cptr);
		bundle(3, yypt[-2].yyv.cptr, yypt[-5].yyv.cptr, " ");
	} break;
case 27:
#line	218	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-1].yyv.cptr, yypt[-3].yyv.cptr, yypt[-5].yyv.cptr);
		conout(yyval.cptr, yypt[-5].yyv.cptr);
		bundle(3, yypt[-3].yyv.cptr, yypt[-5].yyv.cptr, " ");
	} break;
case 28:
#line	224	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(5, yypt[-1].yyv.cptr, yypt[-3].yyv.cptr, "s.", yypt[-5].yyv.cptr, yypt[-6].yyv.cptr);
		conout(yyval.cptr, yypt[-6].yyv.cptr);
		bundle(5, yypt[-7].yyv.cptr, "s.", yypt[-5].yyv.cptr, yypt[-6].yyv.cptr, " ");
	} break;
case 29:
#line	230	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-0].yyv.cptr, "S", yypt[-2].yyv.cptr);
	} break;
case 30:
#line	236	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		yyval.cptr = yypt[-1].yyv.cptr;
	} break;
case 31:
#line	241	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"

	{
		--bindx;
	} break;
case 33:
#line	249	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(2, yypt[-2].yyv.cptr, yypt[-0].yyv.cptr);
	} break;
case 34:
#line	255	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		ln++;
	} break;
case 36:
#line	262	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		yyval.cptr = bundle(3, yypt[-2].yyv.cptr, yypt[-0].yyv.cptr, "=");
	} break;
case 37:
#line	266	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-2].yyv.cptr, yypt[-0].yyv.cptr, ">");
	} break;
case 38:
#line	270	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-2].yyv.cptr, yypt[-0].yyv.cptr, "<");
	} break;
case 39:
#line	274	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-2].yyv.cptr, yypt[-0].yyv.cptr, "!=");
	} break;
case 40:
#line	278	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-2].yyv.cptr, yypt[-0].yyv.cptr, "!>");
	} break;
case 41:
#line	282	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-2].yyv.cptr, yypt[-0].yyv.cptr, "!<");
	} break;
case 42:
#line	286	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(2, yypt[-0].yyv.cptr, " 0!=");
	} break;
case 43:
#line	292	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		yyval.cptr = yypt[-1].yyv.cptr;
	} break;
case 44:
#line	296	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, " ", yypt[-0].yyv.cptr, " ");
	} break;
case 45:
#line	300	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, " .", yypt[-0].yyv.cptr, " ");
	} break;
case 46:
#line	304	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(5, " ", yypt[-2].yyv.cptr, ".", yypt[-0].yyv.cptr, " ");
	} break;
case 47:
#line	308	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(4, " ", yypt[-1].yyv.cptr, ".", " ");
	} break;
case 48:
#line	312	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		yyval.cptr = "l.";
	} break;
case 49:
#line	316	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-1].yyv.cptr, ";", geta(yypt[-3].yyv.cptr));
	} break;
case 50:
#line	320	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(4, "l", yypt[-1].yyv.cptr, "d1+s", yypt[-1].yyv.cptr);
	} break;
case 51:
#line	324	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(4, "l", yypt[-0].yyv.cptr, "1+ds", yypt[-0].yyv.cptr);
	} break;
case 52:
#line	328	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(4, "l", yypt[-0].yyv.cptr, "1-ds", yypt[-0].yyv.cptr);
	} break;
case 53:
#line	332	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(4, "l", yypt[-1].yyv.cptr, "d1-s", yypt[-1].yyv.cptr);
	} break;
case 54:
#line	336	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(7, yypt[-2].yyv.cptr, ";", geta(yypt[-4].yyv.cptr), "d1+" ,yypt[-2].yyv.cptr, ":" ,geta(yypt[-4].yyv.cptr));
	} break;
case 55:
#line	340	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(7, yypt[-1].yyv.cptr, ";", geta(yypt[-3].yyv.cptr), "1+d", yypt[-1].yyv.cptr, ":", geta(yypt[-3].yyv.cptr));
	} break;
case 56:
#line	344	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(7, yypt[-2].yyv.cptr, ";", geta(yypt[-4].yyv.cptr), "d1-", yypt[-2].yyv.cptr, ":", geta(yypt[-4].yyv.cptr));
	} break;
case 57:
#line	348	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(7, yypt[-1].yyv.cptr, ";", geta(yypt[-3].yyv.cptr), "1-d", yypt[-1].yyv.cptr, ":" ,geta(yypt[-3].yyv.cptr));
	} break;
case 58:
#line	352	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "Kd1+k");
	} break;
case 59:
#line	356	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "K1+dk");
	} break;
case 60:
#line	360	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "Kd1-k");
	} break;
case 61:
#line	364	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "K1-dk");
	} break;
case 62:
#line	368	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "Id1+i");
	} break;
case 63:
#line	372	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "I1+di");
	} break;
case 64:
#line	376	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "Id1-i");
	} break;
case 65:
#line	380	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "I1-di");
	} break;
case 66:
#line	384	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "Od1+o");
	} break;
case 67:
#line	388	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "O1+do");
	} break;
case 68:
#line	392	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "Od1-o");
	} break;
case 69:
#line	396	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "O1-do");
	} break;
case 70:
#line	400	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(4, yypt[-1].yyv.cptr, "l", getf(yypt[-3].yyv.cptr), "x");
	} break;
case 71:
#line	404	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, "l", getf(yypt[-2].yyv.cptr), "x");
	} break;
case 72:
#line	407	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
 {
		bundle(2, "l", yypt[-0].yyv.cptr);
	} break;
case 73:
#line	411	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(2, yypt[-1].yyv.cptr, "Z");
	} break;
case 74:
#line	415	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(2, yypt[-1].yyv.cptr, "X");
	} break;
case 75:
#line	419	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "?");
	} break;
case 76:
#line	423	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(2, yypt[-1].yyv.cptr, "v");
	} break;
case 77:
#line	427	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(2, "L", yypt[-0].yyv.cptr);
	} break;
case 78:
#line	431	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "K");
	} break;
case 79:
#line	435	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "I");
	} break;
case 80:
#line	439	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(1, "O");
	} break;
case 81:
#line	443	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, " 0", yypt[-0].yyv.cptr, "-");
	} break;
case 82:
#line	447	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-2].yyv.cptr, yypt[-0].yyv.cptr, "+");
	} break;
case 83:
#line	451	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-2].yyv.cptr, yypt[-0].yyv.cptr, "-");
	} break;
case 84:
#line	455	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-2].yyv.cptr, yypt[-0].yyv.cptr, "*");
	} break;
case 85:
#line	459	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-2].yyv.cptr, yypt[-0].yyv.cptr, "/");
	} break;
case 86:
#line	463	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-2].yyv.cptr, yypt[-0].yyv.cptr, "%%");
	} break;
case 87:
#line	467	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-2].yyv.cptr, yypt[-0].yyv.cptr, "^");
	} break;
case 88:
#line	473	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(3, yypt[-0].yyv.cptr, "ds", yypt[-2].yyv.cptr);
	} break;
case 89:
#line	477	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(5, yypt[-0].yyv.cptr, "d", yypt[-3].yyv.cptr, ":", geta(yypt[-5].yyv.cptr));
	} break;
case 90:
#line	481	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(6, "l", yypt[-2].yyv.cptr, yypt[-0].yyv.cptr, yypt[-1].yyv.cptr, "ds", yypt[-2].yyv.cptr);
	} break;
case 91:
#line	485	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(9, yypt[-3].yyv.cptr, ";", geta(yypt[-5].yyv.cptr), yypt[-0].yyv.cptr, yypt[-1].yyv.cptr, "d", yypt[-3].yyv.cptr, ":", geta(yypt[-5].yyv.cptr));
	} break;
case 95:
#line	496	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(2, yypt[-2].yyv.cptr, yypt[-0].yyv.cptr);
	} break;
case 97:
#line	503	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		bundle(2, "l", geta(yypt[-2].yyv.cptr));
	} break;
case 98:
#line	509	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		*cp++ = 0;
	} break;
case 99:
#line	515	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		yyval.cptr = cp;
		*cp++ = '_';
	} break;
case 100:
#line	520	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		yyval.cptr = cp;
		*cp++ = yypt[-0].yyv.cc;
	} break;
case 101:
#line	525	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		*cp++ = yypt[-0].yyv.cc;
	} break;
case 102:
#line	530	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"

	{
		yyval.cptr = cp;
		*cp++ = '<';
		*cp++ = crs/100+'0';
		*cp++ = (crs%100)/10+'0';
		*cp++ = crs%10+'0';
		*cp++ = '>';
		*cp++ = '\0';
		if(crs++ >= 220) {
			yyerror("program too big");
			getout();
		}
		bstack[bindx++] = lev++;
	} break;
case 103:
#line	548	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		yyval.cptr = getf(yypt[-1].yyv.cptr);
		pre = (char*)"";
		post = (char*)"";
		lev = 1;
		bindx = 0;
		bstack[bindx] = 0;
	} break;
case 105:
#line	559	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		pp((char*)yypt[-0].yyv.cptr);
	} break;
case 106:
#line	563	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		pp((char*)yypt[-0].yyv.cptr);
	} break;
case 107:
#line	569	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		tp((char*)yypt[-0].yyv.cptr);
	} break;
case 108:
#line	573	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		tp((char*)yypt[-0].yyv.cptr);
	} break;
case 109:
#line	579	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		yyval.cptr=yypt[-0].yyv.cptr;
	} break;
case 110:
#line	583	"/Users/masato/Documents/Pocket7878/plan9port/src/cmd/bc.y"
{
		yyval.cptr = geta(yypt[-2].yyv.cptr);
	} break;
	}
	goto yystack;  /* stack new state and value */
}
