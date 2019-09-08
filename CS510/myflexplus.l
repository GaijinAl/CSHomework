%{

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
   
{id}		cout << "100 " << '\t' << yytext << endl;	// PRINT ID

{number}	cout << "200" << '\t' << yytext << endl;	// PRINT NUMBER

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
