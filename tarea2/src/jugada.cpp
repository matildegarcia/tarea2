#include "../include/jugada.h"

const char *obtenerNombreMovimiento(int numero);

// Define la estructura Jugada
struct rep_jugada
{
    int numero;
    Movimiento movimientos[4];
};

// Crea una jugada con los valores dados
TJugada crearTJugada(int numero, Movimiento mov1, Movimiento mov2, Movimiento mov3, Movimiento mov4)
{

    TJugada nuevaJugada = new rep_jugada; // Crear una nueva jugada en memoria dinámica

    nuevaJugada->numero = numero; // Asignar el número de la jugada

    // Asignar los movimientos a la jugada
    nuevaJugada->movimientos[0] = mov1;
    nuevaJugada->movimientos[1] = mov2;
    nuevaJugada->movimientos[2] = mov3;
    nuevaJugada->movimientos[3] = mov4;

    return nuevaJugada;
}

// Función que retorna el numero de la jugada
int numeroTJugada(TJugada jugada)
{
    int devuelve = 0;
    if (jugada != NULL)
    {
        devuelve = jugada->numero;
    }
    return devuelve;
}

// Función que retorna los movimientos de una jugada
Movimiento *movimientoTJugada(TJugada jugada)
{

    return jugada->movimientos;
}

// Devuelve true si y solo si la jugada tiene el movimiento mov en la posicion pos
bool tieneMovimientoEnPosTJugada(TJugada jugada, int pos, Movimiento mov)
{
    if (pos >= 0 && pos < 4)
    { // Asegurarse de que la posición esté en el rango del array
        return jugada->movimientos[pos] == mov;
    }
    return false; // Si la posición está fuera del rango, retornar false
}

const char *obtenerNombreMovimiento(int numero)
{ // const  char* porque devuelve un string
    switch (numero)
    {
    case 1:
        return "Derecha";
    case 2:
        return "Izquierda";
    case 3:
        return "Arriba";
    case 4:
        return "Abajo";
    default:
        return "Desconocido";
    }
}

void imprimirTJugada(TJugada jugada)
{
    printf("Jugada: %d \n", jugada->numero);
    printf("Movimientos: %s %s %s %s \n",
           obtenerNombreMovimiento(jugada->movimientos[0]),
           obtenerNombreMovimiento(jugada->movimientos[1]),
           obtenerNombreMovimiento(jugada->movimientos[2]),
           obtenerNombreMovimiento(jugada->movimientos[3]));
}

void liberarTJugada(TJugada &jugada)
{
    if (jugada != NULL)
    {
        delete jugada; // Liberar memoria del puntero a la estructura jugada
        jugada = NULL; // Establecer el puntero a NULL
    }
}

// Función que crea una copia de la jugada, incluyendo copias de los movimientos
TJugada copiarTJugada(TJugada jugada)
{
    if (jugada == NULL)
    {
        return NULL;
    }

    TJugada nuevaJugada = new rep_jugada; // Crear una nueva jugada en memoria dinámica

    nuevaJugada->numero = jugada->numero; // Copiar el número de la jugada

    // Copiar los movimientos a la nueva jugada
    for (int i = 0; i < 4; i++)
    {
        nuevaJugada->movimientos[i] = jugada->movimientos[i];
    }

    return nuevaJugada;
}
