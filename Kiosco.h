#ifndef KIOSCO_H
#define KIOSCO_H


class Kiosco
{
    public:
        Kiosco();
        bool crear();
        bool modificar(Kiosco kiosco, int pos);
        bool listar();
        bool listarPorNombre(const char* nombre);
        void eliminar();
        void cargar();
        void mostrar();
        void cargarCadena(char *palabra, int tam);
        int buscarNombre(const char* nombre);

        char _nombre[30];
        char _direccion[30];

    protected:

    private:
};

#endif // KIOSCO_H
