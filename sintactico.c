#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#include "definiciones.h"
#include "tablaSimbolos.h"
#include "lexico.h"
#include "abb.h"

bool finAnalisis;

void sig_comp() {
    Nodo componente;
    printf("\n---------------------------------"
           "\n----------ANALIZADOR-------------\n"
           "---------------------------------\n");
    while (!finAnalisis) {
        componente = analisisLexico();  // Se piden componentes hasta que el componente recibido sea EOF
        if ((componente->identificador) == EOF) {
            finAnalisis = true;
        }
        printf("< %d, %s >\n", componente->identificador, componente->lexema);
    }
    printf("---------------------------------\n\n");
    free(componente);
}
