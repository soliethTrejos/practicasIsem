#include <iostream>
#include <string.h>
#include "variables.h"

using namespace std;

CIUDAD ciudades[MAX_REG];

int pos = 0;

// crud
void agregar(CIUDAD *c);
void editar(CIUDAD *c, int od);
void eliminar(CIUDAD *c);
void buscar(CIUDAD *c);
void menu(int op);
void principal();
void pedirDatos();

void agregarc(CIUDAD *c)
{
    ciudades[pos] = *c;
    pos++;
}

CIUDAD buscar(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (id == ciudades[i].id)
        {
            return ciudades[i];
        }
    }
    CIUDAD c;
    return c;
}

int obtPos(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (ciudades[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void editar(CIUDAD *c, int id)
{
    int posi = obtPos(id);
    strcpy(ciudades[posi].nombre, c->nombre);
    strcpy(ciudades[posi].descripcion, c->descripcion);
}

void eliminar(int id)
{
    int posi = obtPos(id);
    for (int i = 0; i < pos; i++)
    {
        ciudades[i] = ciudades[i + 1];
    }
    pos--;
}

int menu()
{
    int op;
    cout << " Menu\n";
    cout << " 1. agregar\n";
    cout << "2. editar\n";
    cout << "3. eliminar\n";
    cout << "4. buscar\n";
    cout << "5. Mostrar todo\n";
    cout << "6. sarli\n";
    cout << " Dijite su opcion";
    cin >> op;
    return op;
}
void principal()
{
    int op;
    do
    {
        op = menu();
        switch (op)
        {
        case1:
            pedirDatos();
            break;
        case6:
            cout << "adios, mi tierno\n";
            break;
        default:
            cout << "no seas neofito si solo hay 6\n";
            break;
        }
    } while (op != 6);
}

void pedirDatos()
{
    CIUDAD ciudad;
    cout << "datos de ciudad\n";
    cout << "ID:  ";
    cin >> ciudad.id;
    cout << "nombre:";
    cin >> ciudad.nombre;
    cout << "descripcion:";
    cin >> ciudad.descripcion;
    agregar(&ciudad);
    cout << "registro agregado....\n";
}