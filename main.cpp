#include <iostream>

using namespace std;

#include "Kiosco.h"

int main()
{
    Kiosco kiosco;
    string nombreKiosco;
    int opcion;

    do
    {

        cout << "MENU" << endl;
        cout << "----" << endl;
        cout << "1-Agregar Kiosco" << endl;
        cout << "2-Mostrar Kioscos" << endl;
        cout << "3-Listar kiosco por nombre" << endl;
        cout << "4-Modificar Kiosco" << endl;
        cout << "0-Terminar programa" << endl;
        cout << "----" << endl;
        cout << "Seleccionar una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            system("cls");
            kiosco.crear();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            kiosco.listar();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            cout<<"Ingrese nombre de kiosco: "<<endl;
            cin.ignore();
            getline(cin, nombreKiosco);
            system("cls");
            kiosco.listarPorNombre(nombreKiosco.c_str());
            system("pause");
            system("cls");
            break;
         case 4:
            system("cls");
            cout<<"Ingrese nombre de kiosco a modificar: "<<endl;
            cin.ignore();
            getline(cin, nombreKiosco);
            //kiosco.modificar();
            system("pause");
            system("cls");
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta. Seleccione una nueva" << endl;
            break;
        }

    }
    while(opcion != 0);

        return 0;
}




