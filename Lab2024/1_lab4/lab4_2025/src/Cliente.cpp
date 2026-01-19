#include "../include/Cliente.h"

Cliente::Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento)
: Usuario(nickname,contrasena,nombre,email) {
    this->apellido = apellido;
    this->documento = documento;
}

Cliente::~Cliente(){
    if(notificaciones.size()!=0){
        for (list<DTNotificacion*>::iterator it = notificaciones.begin(); it != notificaciones.end(); it++){
            delete (*it);
        }
    }
    notificaciones.clear();
}

set<Inmobiliaria*> Cliente::getSuscripciones(){
    return suscripciones;
}

void Cliente::añadirSuscripcion(Inmobiliaria* i){
    suscripciones.insert(i);
}

void Cliente::eliminarSuscripcion(Inmobiliaria* i){
    suscripciones.erase(i);
}

void Cliente::notificarUsuario(string nickname, int codigoPub, TipoPublicacion tipoPub, TipoInmueble tipoInmueble, string texto){
    DTNotificacion* DTnot = new DTNotificacion(nickname, codigoPub, tipoPub, tipoInmueble, texto);
    notificaciones.insert(notificaciones.begin(), DTnot);
}

void Cliente::eliminarNotificaciones() {
    for (list<DTNotificacion*>::iterator it = notificaciones.begin(); it != notificaciones.end(); it++)
    {
        delete (*it);
    }
    notificaciones.clear();
}

list<DTNotificacion*> Cliente::getNotificaciones(){
    list<DTNotificacion *> conjRetorno;
    DTNotificacion *dtn;
    for (list<DTNotificacion *>::iterator it = notificaciones.begin(); it != notificaciones.end(); it++)
    {
        dtn = new DTNotificacion((*it)->getNicknameInmobiliaria(), (*it)->getCodigoPub(), (*it)->getTipoPublicacion(), (*it)->getTipoInmueble(), (*it)->getTexto());
        conjRetorno.insert(conjRetorno.begin(), dtn);
    }

    return conjRetorno;
}
