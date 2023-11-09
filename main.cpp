#include <iostream>

using namespace std;

#include "Kiosco.h"

int main()
{
    Kiosco kiosco;
    string nombreKiosco,codigoKiosco;
    int opcion;

    do
    {

        cout << "MENU" << endl;
        cout << "----" << endl;
        cout << "1-Agregar Kiosco" << endl;
        cout << "2-Mostrar Kioscos" << endl;
        cout << "3-Listar kiosco por nombre" << endl;
        cout << "4-Modificar Kiosco" << endl;
        cout << "5-Eliminar Kiosco" << endl;
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
            cout << "Ingrese codigo de kiosco a modificar: " << endl;
            cin.ignore();
            getline(cin, codigoKiosco);
            if (kiosco.modificar(codigoKiosco.c_str())) {
                cout << "Kiosco modificado correctamente." << endl;
            } else {
                cout << "Error al modificar el kiosco." << endl;
            }
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "Ingrese codigo de kiosco a eliminar: " << endl;
            cin.ignore();
            getline(cin, codigoKiosco);
            kiosco.eliminar(codigoKiosco.c_str());
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




