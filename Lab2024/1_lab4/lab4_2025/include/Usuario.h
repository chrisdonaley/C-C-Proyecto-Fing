#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "DTNotificacion.h"
using namespace std;

class DTNotificacion;

class Usuario {
    private:
        string nickname;
        string contrasena;
        string nombre;
        string email;
        
    public:
        /*Crea una instancia de Usuario con los datos proporcionados*/
        Usuario(string nickname, string contrasena, string nombre, string email);
        
        /*Destruye la instancia de Usuario*/
        virtual ~Usuario();
        
        /*Devuelve el Nickname de la instancia Usuario*/
        string getNickname();

        /*Devuelve la Contrasena de la instancia Usuario*/
        string getContrasena();

        /*Devuelve el Nombre de la instancia Usuario*/
        string getNombre();

        /*Devuelve el Email de la instancia Usuario*/
        string getEmail(); 

        /*Funcion polimorfica*/
        virtual void notificarUsuario(string nickname, int codigoPub, TipoPublicacion tipoPub, TipoInmueble tipoInmueble, string texto) = 0;
};

#endif