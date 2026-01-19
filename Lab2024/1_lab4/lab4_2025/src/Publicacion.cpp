#include "../include/Publicacion.h"
#include "../include/AdministraPropiedad.h"

Publicacion::Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, string texto, float precio, bool activa, AdministraPropiedad* adminPropiedad) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->tipo = tipo;
    this->texto = texto;
    this->precio = precio;
    this->activa = activa;
    this->adminPropiedad = adminPropiedad; 
}
Publicacion::~Publicacion() {
    delete this->fecha;
    this->fecha = NULL;
}
int Publicacion::getCodigo() {
    return codigo;
}
DTFecha* Publicacion::getFecha() {
    return fecha;
}

bool Publicacion::cumpleTipoPrecio(TipoPublicacion tipo, float precioMinimo, float precioMaximo) {
    if (this->tipo == tipo && this->precio >= precioMinimo && this->precio <= precioMaximo) {
        return true;
    } else return false;
}

TipoPublicacion Publicacion::getTipo() {
    return tipo;
}

bool Publicacion::getActiva(){
    return activa;
}

void Publicacion::setActiva(bool activa){
    this->activa = activa;
}

bool Publicacion::consultarTipo(TipoInmueble tipoInmueble) {
    return adminPropiedad->consultarTipo(tipoInmueble);
}

DTPublicacion* Publicacion::getDTP() {
    DTPublicacion* dtPublicacion = new DTPublicacion(codigo, fecha, texto, to_string(precio), adminPropiedad->getInmobiliaria()->getNickname());
    return dtPublicacion;
}

AdministraPropiedad* Publicacion::getAdminPropiedad() {
    AdministraPropiedad* a = adminPropiedad;
    return a;
}
void Publicacion::deleteAdminPropiedad() {
    this->adminPropiedad = NULL;
}
void Publicacion::setAdminPropiedad(AdministraPropiedad* adminPropiedad) {
    delete adminPropiedad;
    this->adminPropiedad = adminPropiedad;
}