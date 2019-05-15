#include <stdio.h>
#include "stdlib.h"
#include "definiciones.h"
#include "sintactico.h"
#include "tablaSimbolos.h"
#include "errores.h"
#include "lex.yy.h"
#include "lexico.h"

int main(int argc, char **argv) {
    char *rutaFichero;
    if (argc == 2) {
        rutaFichero = argv[1];
    } else if (argc > 2) {
        imprimirErrorFichero(ERROR_FICHERO, "se han recibido mas argumentos de los esperados.\n");
    } else {
        imprimirErrorFichero(ERROR_FICHERO, "se espera un argumento.\n");
    }
    /* Inicializacion */
    yyin = fopen(rutaFichero, "r");
    inicializarTablaSimbolos();
    /* Analisis */
    imprimirTablaSimbolos();
    sig_comp();
    imprimirTablaSimbolos();

    /* Finalizacion del programa */
    liberarTablaSimbolos();
    fclose(yyin);
    liberarAnalizador();

    return 0;
}
