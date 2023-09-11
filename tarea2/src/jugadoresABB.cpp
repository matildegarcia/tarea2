#include "../include/jugadoresABB.h"
void auxLiberaNodo(TJugadoresABB nodo);
void mayoresTJugadoresABBRecursivo(TJugadoresABB jugadoresABB, nat edad, TJugadoresABB &nuevosJugadoresABB);


struct rep_jugadoresABB {
  
TJugadoresABB left, right;
TJugador jugador;
nat cantidad;

};

TJugadoresABB crearTJugadoresABB() {

    return NULL;
}



bool esVacioTJugadoresABB(TJugadoresABB jugadoresABB) {
    return (jugadoresABB == NULL) ;
}

void insertarTJugadoresABB(TJugadoresABB &jugadoresABB, TJugador jugador) {
    if (jugadoresABB == NULL) {
        jugadoresABB = new rep_jugadoresABB;
        jugadoresABB->left = NULL;
        jugadoresABB->right = NULL;
        jugadoresABB->jugador = jugador;
        jugadoresABB->cantidad = 1; 
    } else {
        int idJugador = idTJugador(jugador);
        int idNodo = idTJugador(jugadoresABB->jugador);
        
        if (idJugador < idNodo) {
            insertarTJugadoresABB(jugadoresABB->left, jugador);
        } else if (idJugador > idNodo) {
            insertarTJugadoresABB(jugadoresABB->right, jugador);
        }
        
        
        jugadoresABB->cantidad = 1; 
        if (jugadoresABB->left != NULL) {
            jugadoresABB->cantidad += jugadoresABB->left->cantidad;
        }
        if (jugadoresABB->right != NULL) {
            jugadoresABB->cantidad += jugadoresABB->right->cantidad;
        }
    }
}




void auxLiberaNodo(TJugadoresABB nodo) {
  if (nodo != NULL) {
    auxLiberaNodo(nodo->left);
    auxLiberaNodo(nodo->right);
    liberarTJugador(nodo->jugador);
    delete nodo;
  }
}


void liberarTJugadoresABB(TJugadoresABB &jugadoresABB) {
    auxLiberaNodo(jugadoresABB);
    jugadoresABB = NULL;
}



void imprimirTJugadoresABB(TJugadoresABB jugadoresABB) {
    if (jugadoresABB != NULL) {
       
        imprimirTJugadoresABB(jugadoresABB->left);
      
        imprimirTJugador(jugadoresABB->jugador);
        
        imprimirTJugadoresABB(jugadoresABB->right);
    }
}

nat cantidadTJugadoresABB(TJugadoresABB jugadoresABB) {
    if (jugadoresABB != NULL) {
        return jugadoresABB->cantidad;
    } else {
        return 0;
    }
}

TJugador maxIdJugador(TJugadoresABB jugadoresABB) {
    if (jugadoresABB->right == NULL) {
        return jugadoresABB->jugador; 
    }
    return maxIdJugador(jugadoresABB->right); 
}


bool estaTJugadoresABB(TJugadoresABB jugadoresABB, nat id) {
    if (jugadoresABB == NULL) {
        return false; 
    }

    nat idNodo = idTJugador(jugadoresABB->jugador);

    if (id == idNodo) {
        return true; 
    } else if (id < idNodo) {
        return estaTJugadoresABB(jugadoresABB->left, id); 
    } else {
        return estaTJugadoresABB(jugadoresABB->right, id); 
    }
}

void removerTJugadoresABB(TJugadoresABB &jugadoresABB, nat id) {
    if (jugadoresABB == NULL) {
        return;
    }

    if (id < idTJugador(jugadoresABB->jugador)) {
        removerTJugadoresABB(jugadoresABB->left, id);
    } else if (id > idTJugador(jugadoresABB->jugador)) {  
        removerTJugadoresABB(jugadoresABB->right, id);
    } else {
        if (jugadoresABB->left == NULL && jugadoresABB->right == NULL) {

            liberarTJugador(jugadoresABB->jugador); 
            delete jugadoresABB;
            jugadoresABB = NULL;
        } else if (jugadoresABB->right == NULL) {

            TJugadoresABB temp = jugadoresABB;
            jugadoresABB = jugadoresABB->left;
            liberarTJugador(temp->jugador); 
            delete temp;
        } else if (jugadoresABB->left == NULL) {

            TJugadoresABB temp = jugadoresABB;
            jugadoresABB = jugadoresABB->right;
            liberarTJugador(temp->jugador); 
            delete temp;
        } else {
            TJugador temp = copiarTJugador(maxIdJugador(jugadoresABB->left));
            liberarTJugador(jugadoresABB->jugador); 
            jugadoresABB->jugador = temp; 
            removerTJugadoresABB(jugadoresABB->left, idTJugador(temp));
        }
    }
    
    if (jugadoresABB != NULL) {
        jugadoresABB->cantidad = 1; 
        if (jugadoresABB->left != NULL) {
            jugadoresABB->cantidad += jugadoresABB->left->cantidad;
        }
        if (jugadoresABB->right != NULL) {
            jugadoresABB->cantidad += jugadoresABB->right->cantidad;
        }
    }
}



TJugador obtenerDeTJugadoresABB(TJugadoresABB jugadoresABB, nat id) {
    if (jugadoresABB == NULL) {
        return NULL; 
    }

    nat idNodo = idTJugador(jugadoresABB->jugador);

    if (id == idNodo) {
        return jugadoresABB->jugador; 
    } else if (id < idNodo) {
        return obtenerDeTJugadoresABB(jugadoresABB->left, id); 
    } else {
        return obtenerDeTJugadoresABB(jugadoresABB->right, id); 
    }
}


nat alturaTJugadoresABB(TJugadoresABB jugadoresABB) {
    nat resultado;
    if (jugadoresABB == NULL) {
        return 0; 
    }

    nat alturaIzquierdo = alturaTJugadoresABB(jugadoresABB->left);
    nat alturaDerecho = alturaTJugadoresABB(jugadoresABB->right);

    if (alturaIzquierdo < alturaDerecho ){
        resultado = 1 + alturaDerecho ;
    
    } else{
        resultado= 1 + alturaIzquierdo;
    }
    return resultado;
}

bool esPerfectoTJugadoresABB(TJugadoresABB jugadoresABB) {
    if (jugadoresABB == NULL) {
        return true; 
    }

    nat alturaIzquierdo = alturaTJugadoresABB(jugadoresABB->left);
    nat alturaDerecho = alturaTJugadoresABB(jugadoresABB->right);

    if (alturaIzquierdo != alturaDerecho) {
        return false; 
    }

    return esPerfectoTJugadoresABB(jugadoresABB->left) && esPerfectoTJugadoresABB(jugadoresABB->right);
}

TJugadoresABB mayoresTJugadoresABB(TJugadoresABB jugadoresABB, nat edad) {
    TJugadoresABB nuevosJugadoresABB = crearTJugadoresABB();
    mayoresTJugadoresABBRecursivo(jugadoresABB, edad, nuevosJugadoresABB);
    return nuevosJugadoresABB;
}

void mayoresTJugadoresABBRecursivo(TJugadoresABB jugadoresABB, nat edad, TJugadoresABB &nuevosJugadoresABB) {
    if (jugadoresABB == NULL) {
        return;
    }

    mayoresTJugadoresABBRecursivo(jugadoresABB->left, edad, nuevosJugadoresABB);

    if (edadTJugador(jugadoresABB->jugador) > edad) {
        insertarTJugadoresABB(nuevosJugadoresABB, copiarTJugador(jugadoresABB->jugador));
    }

    mayoresTJugadoresABBRecursivo(jugadoresABB->right, edad, nuevosJugadoresABB);
}






