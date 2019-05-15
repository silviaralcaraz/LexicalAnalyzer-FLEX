%option yylineno
%{
	#include "definiciones.h"
	#include "errores.h"
	#include <string.h>
%}

/*/////////////////////////////////////// DEFINICIONES ///////////////////////////////////////*/

/* Identifiers */

identifier	[A-Za-z_]([A-Za-z|0-9|_])*

/* Keywords -> definiciones.h */

/* Spaces and line breaks */

space       [ \r]
tabs	    [ \t]
lineBreak   [ \n]

/* String literals */

stringliteral   \'{1}[^\n]*\'{1}|\"{1}[^\n]*\"{1}

/* Integer literals */

integer		(-?[0-9]+)

/* Floating point literals */

floatnumber	([0-9]*)\.([0-9]*)|([0-9]+)(e|E)(-?)(\+?)([0-9]+)

/* Hexadecimals */

hexinteger	(0[X|x])([0-9A-Fa-f]{1,8})

/* Comments */

simpleComment			#[^\n]*
multilineComment 		\"{3}[^\"]*\"{3}|\'{3}[^\']*\'{3}

/* Posible errors */

error_multiline_comment	\"{3}[^\"]*\"{1}|\"{3}[^\"]*\"{2}|\'{3}[^\"]*\'{1}|\'{3}[^\"]*\'{2}
error_string			\'{1}[^\n\']*[\n]|\"{1}[^\n\"]*[\n]|\'{1}[^\n\"]*(EOF)|\"{1}[^\n\"]*(EOF)
error_integer			(-?[0-9]+[A-Za-z]+)
error_hex				(0[X|x])([0-9A-Fa-f]{0,7}[g-zG-Z]{1,}[0-9A-Za-z]*)|(0[X|x])([0-9A-Fa-f]{9,})
error_float				([0-9]+)\.([0-9]*)([A-Za-z]{1,})([A-Za-z0-9]*)

%%

{identifier}	{return IDENTIFICADOR;}

{multilineComment}				{return COMENTARIO_MULTILINEA;}
{error_multiline_comment}		{ imprimirError(COMENTARIO_MULTILINEA_MALFORMADO, yylineno); return COMENTARIO_MULTILINEA; }

{stringliteral}		{return STRING;}
{error_string}		{ imprimirError(STRING_MALFORMADO, yylineno); return STRING; }

{space}				// ninguna accion
{tabs}				// ninguna accion
{simpleComment}		// ninguna accion

{lineBreak}    		{return SALTO_CARRO;}

"."					{return PUNTO;}

{integer}			{return INTEGER;}
{floatnumber}		{return FLOAT;}
{hexinteger}		{return HEXADECIMAL;}

{error_hex}			{imprimirError(HEXADECIMAL_MALFORMADO, yylineno); return HEXADECIMAL; }
{error_float}		{imprimirError(FLOAT_MALFORMADO, yylineno); return FLOAT; }
{error_integer}		{imprimirError(NUMERO_MALFORMADO, yylineno); return INTEGER; }

<<EOF>>				{return EOF;}

"{"		{return LLAVE_ABRIR;}
"}"		{return LLAVE_CERRAR;}
","		{return COMA;}
"("		{return PARENTESIS_ABRIR;}
")"		{return PARENTESIS_CERRAR;}
"["		{return CORCHETE_ABRIR;}
"]"		{return CORCHETE_CERRAR;}
":"		{return DOS_PUNTOS;}

"="		{return OP_IGUAL;}
"-"		{return OP_MENOS;}
"+"		{return OP_MAS;}
"*"		{return OP_PRODUCTO;}
"/"		{return OP_DIVISION;}
"<"		{return OP_MENOR;}
">"		{return OP_MAYOR;}
"+="	{return OP_MASIGUAL;}
"**"	{return OP_POTENCIA;}
"<="	{return OP_MENORIGUAL;}
"=="	{return OP_IGUALIGUAL;}

.		{imprimirError(COMPONENTE_NO_RECONOCIDO, yylineno);}
