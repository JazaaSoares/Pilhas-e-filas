#include <stdio.h>
#include <stdlib.h>
#include "pilhaDeNumerosInteiros.h"
#include "filaDePilhas.h"

int main() {
    FilaDePilhas* fila = criaFila();
    menuFilaDePilhas(fila);
    return 0;
}
