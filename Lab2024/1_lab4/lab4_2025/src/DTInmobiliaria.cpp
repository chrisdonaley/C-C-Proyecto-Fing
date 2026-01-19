#include "../include/DTInmobiliaria.h"

DTInmobiliaria::DTInmobiliaria(string nickname, int codigo, TipoPublicacion* tipoPub, TipoInmueble* tipoInmueble, string direccion, string url, string telefono, set<Usuario*> suscriptores) {
    this->nicknameInmobiliaria = nickname;
    this->codigo = codigo;
    this->tipoPub = tipoPub;
    this->tipoInmueble = tipoInmueble;
    this->direccion = direccion;
    this->url = url;
    this->telefono = telefono;
    this->suscriptores = suscriptores;
}

DTInmobiliaria::DTInmobiliaria(string nickname, string direccion, string url, string telefono, set<Usuario*> suscriptores) {
    this->nicknameInmobiliaria = nickname;
    this->direccion = direccion;
    this->url = url;
    this->telefono = telefono;
    this->suscriptores = suscriptores;
    this->tipoPub = NULL;
    this->tipoInmueble = NULL;
}

DTInmobiliaria::~DTInmobiliaria() {
    if (tipoInmueble != NULL)
    {
        delete tipoInmueble;
        delete tipoPub;
    }
    
}

string DTInmobiliaria::getNicknameInmobiliaria() {
    return nicknameInmobiliaria;
}

int DTInmobiliaria::getCodigo() {
    return codigo;
}

TipoPublicacion* DTInmobiliaria::getTipoPublicacion() {
    return tipoPub;
}

TipoInmueble* DTInmobiliaria::getTipoInmueble() {
    return tipoInmueble;
}

string DTInmobiliaria::getDireccion() {
    return direccion;
}

string DTInmobiliaria::getUrl() {
    return url;
}

string DTInmobiliaria::getTelefono() {
    return telefono;
}

set<Usuario*> DTInmobiliaria::getSuscriptores() {
    return suscriptores;
}
