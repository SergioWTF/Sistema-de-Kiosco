///Ejercicio:

///Autor: SergioWTF

///Fecha:

///Comentario:


#include<iostream>

#include<cstdlib>

#include<ctime>

#include <cstring>

using namespace std;

#include "Kiosco.h"


void Kiosco::cargar()
{
    cout<<"Ingrese nombre del kiosco: ";
    cargarCadena(_nombre,29);
    cout<<"Ingrese direccion del kiosco: ";
    cargarCadena(_direccion,29);
    cout<<"Ingrese codigo de kiosco: ";
    cargarCadena(_codigo,29);
}

void Kiosco::mostrar()
{
    cout<<"Kiosco: "<<_nombre<<endl;
    cout<<"Direccion: "<<_direccion<<endl;
    cout<<"Codigo: "<<_codigo<<endl;
}

bool Kiosco::crear(){
    Kiosco kiosco;
    FILE *pKiosco;
    pKiosco=fopen("kiosco.dat","ab");
    if(pKiosco==NULL){
        return false;
    }
    kiosco.cargar();
    fwrite(&kiosco,sizeof kiosco,1,pKiosco);
	fclose(pKiosco);
	return true;
}

bool Kiosco::modificar(const char* codigoKiosco) {
    FILE* pKiosco;
    pKiosco = fopen("kiosco.dat", "rb+");
    if (pKiosco == NULL) {
        return false;
    }

    int pos = buscarCodigo(codigoKiosco);

    if (pos == -1) {
        cout << "Kiosco no encontrado." << endl;
        fclose(pKiosco);
        return false;
    }

    Kiosco kiosco;
    fseek(pKiosco, pos * sizeof(Kiosco), 0);
    kiosco.cargar();

    bool kioscoModificado = fwrite(&kiosco, sizeof(Kiosco), 1, pKiosco);
    fclose(pKiosco);
    return kioscoModificado;
}

bool Kiosco::listar(){
    Kiosco kiosco;
    FILE *pKiosco;
    pKiosco=fopen("kiosco.dat", "rb");
    if(pKiosco==NULL){
        return false;
    }
    while(fread(&kiosco,sizeof kiosco,1,pKiosco)==1){
        kiosco.mostrar();
        cout<<endl;
    }
    fclose(pKiosco);
    return true;
}

bool Kiosco::listarPorNombre(const char* nombre) {
    Kiosco kiosco;
    FILE *pKiosco;
    pKiosco = fopen("kiosco.dat", "rb");
    if (pKiosco == NULL) {
        cout << "No se pudo abrir el archivo kiosco.dat" << endl;
        return false;
    }

    bool encontrado = false;

    while (fread(&kiosco, sizeof(Kiosco), 1, pKiosco) == 1) {
        if (strstr(kiosco._nombre, nombre) != NULL) {
            kiosco.mostrar();
            cout << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se ha encontrado un kiosco que contenga ese nombre" << endl;
    }

    fclose(pKiosco);

    return encontrado;
}

bool Kiosco::eliminar(const char* codigoKiosco) {
    FILE* pKiosco;
    pKiosco = fopen("kiosco.dat", "rb+");
    if (pKiosco == NULL) {
        return false;
    }

    int pos = buscarCodigo(codigoKiosco);

    if (pos == -1) {
        cout << "Kiosco no encontrado." << endl;
        fclose(pKiosco);
        return false;
    }

    fseek(pKiosco, pos * sizeof(Kiosco), 0);

    Kiosco kiosco;

    bool kioscoEliminado = fwrite(&kiosco, sizeof(Kiosco), 1, pKiosco);
    fclose(pKiosco);

    if (kioscoEliminado) {
        cout << "Kiosco eliminado correctamente." << endl;
        return true;
    } else {
        cout << "Error al eliminar el kiosco." << endl;
        return false;
    }
}

Kiosco::Kiosco(){
}

void Kiosco::cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

int Kiosco::buscarCodigo(const char* codigo) {
    Kiosco kiosco;
    FILE* pKiosco;
    pKiosco = fopen("kiosco.dat", "rb");
    int pos = 0;
    if (pKiosco == NULL) {
        return -2;
    }
    while (fread(&kiosco, sizeof(Kiosco), 1, pKiosco) == 1) {
        if (strcmp(codigo, kiosco._codigo) == 0) {
            fclose(pKiosco);
            return pos;
        }
        pos++;
    }
    fclose(pKiosco);
    return -1;
}
