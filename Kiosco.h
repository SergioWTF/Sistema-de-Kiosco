#ifndef KIOSCO_H
#define KIOSCO_H


class Kiosco
{
    public:
        Kiosco();
        bool crear();
        bool modificar(const char* codigoKiosco);
        bool listar();
        bool listarPorNombre(const char* nombre);
        bool eliminar(const char* codigoKiosco);
        void cargar();
        void mostrar();
        void cargarCadena(char *palabra, int tam);
        int buscarCodigo(const char* codigo);

        char _nombre[30];
        char _direccion[30];
        char _codigo[30];

    protected:

    private:
};

#endif // KIOSCO_H
