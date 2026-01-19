#include "../include/Propietario.h"

Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono)
: Usuario(nickname,contrasena,nombre,email) {
    this->cuentaBancaria = cuentaBancaria;
    this->telefono = telefono;
}

Propietario::~Propietario() {
    for (set<Inmueble*>::iterator it = coleccionInmuebles.begin(); it != coleccionInmuebles.end(); it++)
    {
        (*it)->eliminarLinkPropietario();
        delete (*it);
    }
    if (notificaciones.size()!=0)
    {
        for (list<DTNotificacion*>::iterator it = notificaciones.begin(); it != notificaciones.end(); it++)
        {
            delete (*it);
        }
    }
    coleccionInmuebles.clear();
    notificaciones.clear();
    suscripciones.clear();
}

std::set<DTInmuebleListado *> Propietario::getInmueblesNoAdmin(Inmobiliaria *i) {
    std::set<DTInmuebleListado*> conjRetorno;
    for (std::set<Inmueble*>::iterator it = coleccionInmuebles.begin(); it != coleccionInmuebles.end(); it++)
    {
        DTInmuebleListado* dtil;
        int codigo;
        string direccion;
        bool administrado = (*it)->esAdministrado(i);
        if(!administrado){
            codigo = (*it)->getCodigo();
            direccion = (*it)->getDireccion();
            dtil = new DTInmuebleListado(codigo, direccion, this->getNickname());
            conjRetorno.insert(dtil);
        }
    }
    return conjRetorno;
}

void Propietario::añadirInmuebles(Inmueble* i) {
    coleccionInmuebles.insert(i);
}

void Propietario::eliminarLinkInmueble(Inmueble *i){
    coleccionInmuebles.erase(i);
}

    DTUsuario *Propietario::getDTUsuario()
{
    return new DTUsuario(Usuario::getNickname(), Usuario::getNombre());
}

std::set<Inmobiliaria*> Propietario::getSuscripciones(){
    return suscripciones;
}

void Propietario::añadirSuscripcion(Inmobiliaria* i){
    suscripciones.insert(i);
}

void Propietario::eliminarSuscripcion(Inmobiliaria* i){
    suscripciones.erase(i);
}

void Propietario::notificarUsuario(string nickname, int codigoPub, TipoPublicacion tipoPub, TipoInmueble tipoInmueble, string texto){
    DTNotificacion* DTnot = new DTNotificacion(nickname, codigoPub, tipoPub, tipoInmueble, texto);
    notificaciones.insert(notificaciones.begin(),DTnot);
}

std::set<Inmueble*> Propietario::getInmuebles() {
    return coleccionInmuebles;
}

list<DTNotificacion*> Propietario::getNotificaciones(){
    list<DTNotificacion*> conjRetorno;
    DTNotificacion* dtn;
    for (list<DTNotificacion*>::iterator it = notificaciones.begin(); it != notificaciones.end(); it++)
    {
        dtn = new DTNotificacion((*it)->getNicknameInmobiliaria(), (*it)->getCodigoPub(), (*it)->getTipoPublicacion(), (*it)->getTipoInmueble(), (*it)->getTexto());
        conjRetorno.insert(conjRetorno.begin(),dtn);
    }
    dtn = NULL;
    return conjRetorno;
}

void Propietario::eliminarNotificaciones() {
    for (list<DTNotificacion *>::iterator it = notificaciones.begin(); it != notificaciones.end(); it++)
    {
        delete (*it);
    }
    notificaciones.clear();
}