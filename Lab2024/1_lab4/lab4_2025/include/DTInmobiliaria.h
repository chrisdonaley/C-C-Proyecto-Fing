#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H
#include <string>
#include <set>
#include "TipoInmueble.h"
#include "TipoPublicacion.h"
#include "Usuario.h"
using namespace std;  

class DTInmobiliaria{
    private:
        string nicknameInmobiliaria;
        int codigo;
        TipoPublicacion* tipoPub;
        TipoInmueble* tipoInmueble;
        string direccion;
        string url;
        string telefono;
        set<Usuario*> suscriptores;
    public:
        /*Crea un datatype DTInmobiliaria con los datos proporcionados*/
        DTInmobiliaria(string nickname, int codigo, TipoPublicacion* tipoPub, TipoInmueble* tipoInmueble, string direccion, string url, string telefono, set<Usuario*> suscriptores);
        
        /*Crea un datatype DTInmobiliaria con los datos proporcionados*/
        DTInmobiliaria(string nickname, string direccion, string url, string telefono, set<Usuario*> suscriptores);

        /*Destructor de DTInmobiliaria*/
        ~DTInmobiliaria();

        /*Retorna el nickname de la inmobiliaria*/
        string getNicknameInmobiliaria();

        /*Retorna el codigo de la inmobiliaria*/
        int getCodigo();

        /*Retorna el tipo de publicacion de la inmobiliaria*/
        TipoPublicacion* getTipoPublicacion();

        /*Retorna el tipo de inmueble que el DTInmobiliaria tiene como atributo*/
        TipoInmueble* getTipoInmueble();

        /*Retorna la direccion de la inmobiliaria*/
        string getDireccion();

        /*Retorna la url de la inmobiliaria*/
        string getUrl();

        /*Retorna el telefono de la inmobiliaria*/
        string getTelefono();

        /*Retorna el conjunto de suscriptores de la inmobiliaria*/
        set<Usuario*> getSuscriptores();
};

#endif 