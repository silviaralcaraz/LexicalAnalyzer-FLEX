#include "stdlib.h"
#include "stdio.h"
#include "errores.h"

void imprimirError(int tipo, int linea){
    switch (tipo){
        case OVERFLOW_MAXTAMLEX:   // errores de desbordamiento de tam max de lexema
            printf(ANSI_COLOR_RED "> ERROR: max tam de lexema excedido. [Linea: %d ]\n" ANSI_COLOR_RESET, linea);
            break;
        case COMPONENTE_NO_RECONOCIDO:   // error del analizador lexico reconociendo el componente lexico
            printf(ANSI_COLOR_RED "> ERROR: componente no reconocido. [Linea: %d ]\n" ANSI_COLOR_RESET, linea);
            break;
        case STRING_MALFORMADO:   // error reconociendo string
            printf(ANSI_COLOR_RED "> ERROR: no se ha encontrado el cierre del string. [Linea: %d ]\n" ANSI_COLOR_RESET, linea);
            break;
        case COMENTARIO_MULTILINEA_MALFORMADO:   // error reconociendo comentario multilinea
            printf(ANSI_COLOR_RED "> ERROR: comentario multilinea malformado. [Linea: %d ]\n" ANSI_COLOR_RESET, linea);
            break;
        case ID_MALFORMADO:     // error reconociendo un id malformado
            printf(ANSI_COLOR_RED "> ERROR: identificador malformado. [Linea: %d ]\n" ANSI_COLOR_RESET, linea);
            break;
        case NUMERO_MALFORMADO: // error reconociendo un numero malformado
            printf(ANSI_COLOR_RED "> ERROR: numero malformado. [Linea: %d ]\n" ANSI_COLOR_RESET, linea);
            break;
        case FLOAT_MALFORMADO: // error reconociendo un float malformado
            printf(ANSI_COLOR_RED "> ERROR: numero en punto flotante malformado. [Linea: %d ]\n" ANSI_COLOR_RESET, linea);
            break;
        case HEXADECIMAL_MALFORMADO: // error reconociendo un hexadecimal malformado
            printf(ANSI_COLOR_RED "> ERROR: numero hexadecimal malformado. [Linea: %d ]\n" ANSI_COLOR_RESET, linea);
            break;
    }
}

void imprimirErrorFichero(int tipo, char* msg){
    printf(ANSI_COLOR_RED "> ERROR: %s \n" ANSI_COLOR_RESET, msg);
    exit(0);
}
