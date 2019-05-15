#include <ctype.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "definiciones.h"
#include "tablaSimbolos.h"
#include "lex.yy.h"

Nodo nuevoComponente;

void liberarAnalizador(){
  free(nuevoComponente);
  yylex_destroy();
}

void crearLexema(Nodo *nodo, char *lexema, int id) {
    *nodo = malloc(sizeof(struct Elemento));
    (*nodo)->identificador = id;
    (*nodo)->lexema = lexema;
}

Nodo analisisLexico() {
    int id = yylex();
    char* var;
    if(id == SALTO_CARRO){  // Introduzco a mano los string para que se impriman correctamente
	     var = "\\n";
    }else if(id == EOF){
	     var = "EOF";
    }
    else{
    	var = strdup(yytext);
    }
    crearLexema(&nuevoComponente, var, id);

    if (nuevoComponente->identificador == IDENTIFICADOR) {  // Se almacena el id en la tabla de simbolos si no existe ya
        if (!existeElemento(nuevoComponente->lexema)) {
            insertarComponente(&nuevoComponente, nuevoComponente->lexema, nuevoComponente->identificador);
        }
    }

    return nuevoComponente;
}
