#include "../include/fecha.h"

// Estructura para almacenar una fecha con día, mes y año
struct rep_fecha
{
    nat dia, mes, anio;
};

// Función para crear un nuevo objeto de tipo TFecha con una fecha dada
TFecha crearTFecha(nat dia, nat mes, nat anio)
{

    TFecha nuevaFecha = new rep_fecha;
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;

    return nuevaFecha;
}

// Función para liberar un objeto de tipo TFecha previamente creado
void liberarTFecha(TFecha &fecha)
{
    delete fecha;
    fecha = NULL;
}

// Función para imprimir una fecha representada por un objeto de tipo TFecha
void imprimirTFecha(TFecha fecha)
{
    if (fecha != NULL)
    {
        printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);
    }
}

// Función para aumentar una fecha en una cantidad dada de días
void aumentarTFecha(TFecha &fecha, nat dias)
{
    while (dias > 0)
    {
        nat diasEnMes;

        switch (fecha->mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            diasEnMes = 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            diasEnMes = 30;
            break;

        case 2:
            if ((fecha->anio % 4 == 0 && fecha->anio % 100 != 0) || fecha->anio % 400 == 0)
            {
                diasEnMes = 29;
            }
            else
            {
                diasEnMes = 28;
            }
            break;

        default:
            break;
        }

        if (fecha->dia + dias <= diasEnMes)
        {
            fecha->dia += dias;
            break;
        }
        else
        {
            dias -= (diasEnMes - fecha->dia + 1);
            fecha->dia = 1;
            fecha->mes++;

            if (fecha->mes > 12)
            {
                fecha->mes = 1;
                fecha->anio++;
            }
        }
    }
}

// Función para comparar dos fechas representadas por objetos de tipo TFecha
int compararTFechas(TFecha fecha1, TFecha fecha2)
{
    int res = 0;

    if (fecha1->anio > fecha2->anio)
    {
        res = 1; // fecha1 es mayor que fecha2
    }
    else if (fecha1->anio < fecha2->anio)
    {
        res = -1; // fecha1 es menor que fecha2
    }
    else
    {
        if (fecha1->mes > fecha2->mes)
        {
            res = 1; // fecha1 es mayor que fecha2
        }
        else if (fecha1->mes < fecha2->mes)
        {
            res = -1; // fecha1 es menor que fecha2
        }
        else
        {
            if (fecha1->dia > fecha2->dia)
            {
                res = 1; // fecha1 es mayor que fecha2
            }
            else if (fecha1->dia < fecha2->dia)
            {
                res = -1; // fecha1 es menor que fecha2
            }
        }
    }

    return res;
}

// Retorna una copia de la fecha
TFecha copiarTFecha(TFecha fecha)
{
  
    TFecha nuevaFecha = crearTFecha(fecha->dia, fecha->mes, fecha->anio);
    return nuevaFecha;
}
