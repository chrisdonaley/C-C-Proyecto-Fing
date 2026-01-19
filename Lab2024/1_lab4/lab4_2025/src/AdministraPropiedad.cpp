#include "../include/AdministraPropiedad.h"
#include "../include/Publicacion.h"
#include "../include/Inmueble.h"
#include "../include/Manejador.h"
#include "../include/ControladorFechaActual.h"

AdministraPropiedad::AdministraPropiedad(DTFecha* fecha, Inmueble* inmueble, Inmobiliaria* inmobiliaria) {
    this->fecha = fecha;
    this->inmueble = inmueble;
    this->inmobiliaria = inmobiliaria;
}

AdministraPropiedad::~AdministraPropiedad() {
    delete fecha;
    fecha = NULL;
    if (this->inmobiliaria != NULL)
    {
        this->inmobiliaria->eliminarLinkAdminPropiedad(this);
        this->inmobiliaria = NULL;
    }
    for (Publicacion* publicacion : coleccionPublicaciones) {
        publicacion->deleteAdminPropiedad();
        delete publicacion;
    }
}

Inmueble* AdministraPropiedad::getInmueble() {
    return inmueble;
}

DTInmuebleAdministrado* AdministraPropiedad::getDTInmuebleAdministrado(){
    return new DTInmuebleAdministrado(inmueble->getCodigo(), inmueble->getDireccion(), this->fecha);
}

void AdministraPropiedad::deletePublicacion(Publicacion* publicacion) {
    set<Publicacion*> ::iterator it;
    for(it = coleccionPublicaciones.begin(); it!= coleccionPublicaciones.end(); it++) {
        if (*it == publicacion) {
            coleccionPublicaciones.erase(it);
            break;
        }
    }
}

bool AdministraPropiedad::esIgual(DTFecha* fecha) {
    return (this->fecha == fecha);
}


bool AdministraPropiedad::tieneCodigoInmueble(int codigoInmueble) {
    return (inmueble->getCodigo() == codigoInmueble);
}

bool AdministraPropiedad::sePuedeCrear(TipoPublicacion tipoPublicacion, DTFecha* fecha) {
    set<Publicacion*>::iterator it = coleccionPublicaciones.begin();
    int cod = inmueble->getCodigo();
    bool res = true;
    if (tieneCodigoInmueble(cod)){
        while (res && it != coleccionPublicaciones.end()) {
            if ((*it)->getTipo() == tipoPublicacion && (*it)->getFecha() == fecha) {
                res = false;
            }
            it++;
        }
    }
    return res;
}

void AdministraPropiedad::crearPublicacion(TipoPublicacion tipoPublicacion, string texto, float precio, int nuevoCodigo, DTFecha *fechaPublicacion)
{
    bool activa;
    set<Publicacion *>::iterator it = coleccionPublicaciones.begin();
    while (it != coleccionPublicaciones.end() && ((*it)->getTipo() != tipoPublicacion || (*it)->getActiva() != true))
    {
        it++;
    }
    if (it != coleccionPublicaciones.end()){
        activa = (*it)->getFecha() < fechaPublicacion;    
        (*it)->setActiva(false);    
    }
    else {
        activa = true;
    }
    Publicacion* p = new Publicacion(nuevoCodigo, fechaPublicacion, tipoPublicacion, texto, precio, activa, this);
    coleccionPublicaciones.insert(p);
    Manejador* m = Manejador::getInstance();
    m->addPublicacion(p);
}

bool AdministraPropiedad::consultarTipo(TipoInmueble tipoInmueble) {
    return inmueble->consultarTipo(tipoInmueble);
}


bool AdministraPropiedad::inmobiliariaAsociada(Inmobiliaria *i){
    return i->getNickname() == inmobiliaria->getNickname();
}

void AdministraPropiedad::eliminarLinkInmobiliaria(){
    inmobiliaria = NULL;
}

Inmobiliaria* AdministraPropiedad::getInmobiliaria(){
    return inmobiliaria;
}