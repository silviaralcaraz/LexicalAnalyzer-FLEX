#ifndef P1COMPILADORES_DEFINICIONES_H
#define P1COMPILADORES_DEFINICIONES_H

/* Palabras reservadas */
#define IMPORT 200
#define AS 201
#define DEF 202
#define FOR 203
#define IN 204
#define IF 205
#define ELIF 206
#define ELSE 207
#define RETURN 208
#define NOT 209
#define PRINT 210

/* Componentes lexicos */
#define IDENTIFICADOR 250
#define INTEGER 251
#define FLOAT 252
#define HEXADECIMAL 253
#define STRING 254
#define OP_IGUAL 255
#define OP_MENOS 256
#define OP_MAS 257
#define OP_PRODUCTO 258
#define OP_DIVISION 259
#define OP_MENOR 260
#define OP_MASIGUAL 261
#define OP_MAYOR 262
#define OP_POTENCIA 263
#define OP_MENORIGUAL 264
#define OP_IGUALIGUAL 265
#define COMENTARIO_MULTILINEA 266

#define PUNTO '.'
#define LLAVE_ABRIR '{'
#define LLAVE_CERRAR '}'
#define COMA ','
#define PARENTESIS_ABRIR '('
#define PARENTESIS_CERRAR ')'
#define CORCHETE_ABRIR '['
#define CORCHETE_CERRAR ']'
#define DOS_PUNTOS ':'

#define SALTO_CARRO '\n'

// Arrays utilizados para inicializar la tabla de simbolos:
static char *palabrasReservadas[] = {"import", "as", "def", "for", "in", "if", "elif", "else", "return", "not",
                                     "print"};
static int componentesLexicos[] = {IMPORT, AS, DEF, FOR, IN, IF, ELIF, ELSE, RETURN, NOT, PRINT, -1};

#endif //P1COMPILADORES_DEFINICIONES_H
