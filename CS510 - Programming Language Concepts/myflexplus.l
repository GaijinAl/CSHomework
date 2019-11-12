%{

   // NAME: Alexander Van Maren  -  J527E389
   //
   // A simple Lexical Analyzer for C++ like expressions/assignment statements
   // (identifies and splits tokens in input file, separated by whitespace)
   
   // Ran with Linux commands:
   //  > flex myflexplus.l
   //  > g++ lex.yy.c
   //  > ./a.out
   
   // The following C++ code snippet will appear as-is in the lex.yy.c file
   // (it can be used for global declarations)

    #include <iostream>      // for I/O
    using namespace std;      

    int x;   
    
%}

underscore	"_"
dollar		"$"
letter		[a-zA-Z]
digit		[0-9]
decimal		"."
id		{letter}({letter}|{digit}|{underscore}|{dollar})*

number		({digit}+)({decimal}({digit}+))?

operator1	"+"
operator2	"-"
operator3	"<"
operator4	">"
operator5	"="
operator6	"!="
operator7	"<="
operator8	">="
operator9	"&&"
operator10	"||"

special1	";"
special2	","
special3	":="
special4	":"
special5	"?"
special6	"^"

reserved1	"PROGRAM"
reserved2	"BEGIN"
reserved3	"END"
reserved4	"IF"
reserved5	"THEN"
reserved6	"ELSE"
reserved7	"WHILE"
reserved8	"INTEGER"
reserved9	"REAL"
reserved10	"FOR"

%%

[ \t\n]+	;	// EMPTY ACTION - IGNORE WHITESPACE
 
exit|quit	return 0;					// GRACEFUL EXIT

{number}	cout << "200" << '\t' << yytext << endl;	// PRINT NUMBER


{operator1}	cout << "301" << '\t' << yytext << endl;	// PRINT OPERATORS	
{operator2}	cout << "302" << '\t' << yytext << endl;	
{operator3}	cout << "303" << '\t' << yytext << endl;	
{operator4}	cout << "304" << '\t' << yytext << endl;	
{operator5}	cout << "305" << '\t' << yytext << endl;	
{operator6}	cout << "306" << '\t' << yytext << endl;	
{operator7}	cout << "307" << '\t' << yytext << endl;	
{operator8}	cout << "308" << '\t' << yytext << endl;	
{operator9}	cout << "309" << '\t' << yytext << endl;	
{operator10}	cout << "310" << '\t' << yytext << endl;	

{special1}	cout << "401" << '\t' << yytext << endl;	// PRINT SPECIAL SEQUENCES
{special2}	cout << "402" << '\t' << yytext << endl;	
{special3}	cout << "403" << '\t' << yytext << endl;	
{special4}	cout << "404" << '\t' << yytext << endl;	
{special5}	cout << "405" << '\t' << yytext << endl;	
{special6}	cout << "406" << '\t' << yytext << endl;	

{reserved1}	cout << "501" << '\t' << yytext << endl;	// PRINT RESERVED WORDS
{reserved2}	cout << "502" << '\t' << yytext << endl;	
{reserved3}	cout << "503" << '\t' << yytext << endl;	
{reserved4}	cout << "504" << '\t' << yytext << endl;	
{reserved5}	cout << "505" << '\t' << yytext << endl;	
{reserved6}	cout << "506" << '\t' << yytext << endl;	
{reserved7}	cout << "507" << '\t' << yytext << endl;	
{reserved8}	cout << "508" << '\t' << yytext << endl;	
{reserved9}	cout << "509" << '\t' << yytext << endl;	
{reserved10}	cout << "510" << '\t' << yytext << endl;
   
{id}		cout << "100 " << '\t' << yytext << endl;	// PRINT ID

.		cout << "600" << '\t' << yytext << endl;	// EMPTY ACTION - EAT UP ANY OTHER CHAR


  
%%
   
int main() {
	cout << "A simple Lexical Analyzer" << endl
	     << "(enter any text, terminated by exit or quit)" << endl;

	yylex();	// SPLIT ALL TOKENS IN INPUT
	return 0;
}

int yywrap() {
	return 1;
}
