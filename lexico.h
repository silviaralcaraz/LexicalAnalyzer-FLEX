#ifndef P1COMPILADORES_LEXICO_H
#define P1COMPILADORES_LEXICO_H

#include "abb.h"

/* Funcion que inicia el analisis lexico y envia componentes lexicos
 * al Analizador Sintactico */
Nodo analisisLexico();
/* Funcion que crea un componente con la estructura adecuada */
void crearLexema(Nodo *nodo, char* lexema, int id);
/* Funcion que libera los recursos usados por el analizador lexico */
void liberarAnalizador();

#endif //P1COMPILADORES_LEXICO_H
