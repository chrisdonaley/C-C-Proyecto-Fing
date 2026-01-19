#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H
#include <string>
#include "TipoInmueble.h"
#include "TipoPublicacion.h"
using namespace std;  

class DTNotificacion {
    private:
        string nicknameInmobiliaria;
        int codigoPub;
        TipoPublicacion tipoPub;
        TipoInmueble tipoInmueble;
        string texto;
    public:
        /*Crea un datatype DTNotificacion con los datos proporcionados*/
        DTNotificacion(string nickname, int codigoPub, TipoPublicacion tipoPub, TipoInmueble tipoInmueble, string texto);

        /*Destructor de DTNotificacion*/
        ~DTNotificacion();

        /*Retorna el nickname de la inmobiliaria*/
        string getNicknameInmobiliaria();

        /*Retorna el codigo de la publicacion*/
        int getCodigoPub();

        /*Retorna el tipo de publicacion*/
        TipoPublicacion getTipoPublicacion();

        /*Retorna el tipo de inmueble*/
        TipoInmueble getTipoInmueble();

        /*Retorna el texto de la notificacion*/
        string getTexto();
};

#endif