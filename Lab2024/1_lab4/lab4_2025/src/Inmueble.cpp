#include "../include/Inmueble.h"

Inmueble::Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->numeroPuerta = numeroPuerta;
    this->superficie = superficie;
    this->anoConstruccion = anoConstruccion;
    this->propietario = NULL;
}

Inmueble::~Inmueble() {
    set<AdministraPropiedad*>::iterator it = administraciones.begin();
    while (it != administraciones.end()) {
        (*it)->eliminarLinkInmobiliaria();
        delete *it;
        it++;
    }
    if (propietario != NULL)
    {
        propietario->eliminarLinkInmueble(this);
        propietario = NULL;
    }
    administraciones.clear();
}

int Inmueble::getCodigo() {
    return codigo;
}
std::string Inmueble::getDireccion() {
    return direccion;
}
int Inmueble::getNumeroPuerta() {
    return numeroPuerta;
}
int Inmueble::getSuperficie() {
    return superficie;
}
int Inmueble::getAnoConstruccion() {
    return anoConstruccion;
}

void Inmueble::addPropietario(Propietario* p){
    this->propietario = p;
}

void Inmueble::eliminarLinkPropietario(){
    propietario = NULL;
}

bool Inmueble::esAdministrado(Inmobiliaria* i){
    bool administra = false;
    set<AdministraPropiedad*>::iterator it = administraciones.begin();
    while (it != administraciones.end() && !administra){
        administra = (*it)->inmobiliariaAsociada(i);
        it++;
    }
    return administra;
}

void Inmueble::asociarAdministracionPropiedad(AdministraPropiedad* adminPropiedad){
    administraciones.insert(adminPropiedad);
}

DTInmueble* Inmueble::getDTInmueble(){
    DTInmueble* dti = new DTInmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion);
    return dti;
}