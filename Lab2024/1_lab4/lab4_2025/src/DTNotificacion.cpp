#include "../include/DTNotificacion.h"

DTNotificacion::DTNotificacion(string nickname, int codigoPub, TipoPublicacion tipoPub, TipoInmueble tipoInmueble, string texto) {
    this->nicknameInmobiliaria = nickname;
    this->codigoPub = codigoPub;
    this->tipoPub = tipoPub;
    this->tipoInmueble = tipoInmueble;
    this->texto = texto;
}

DTNotificacion::~DTNotificacion() {
}

string DTNotificacion::getNicknameInmobiliaria() {
    return nicknameInmobiliaria;
}

int DTNotificacion::getCodigoPub() {
    return codigoPub;
}

TipoPublicacion DTNotificacion::getTipoPublicacion() {
    return tipoPub;
}

TipoInmueble DTNotificacion::getTipoInmueble() {
    return tipoInmueble;
}

string DTNotificacion::getTexto(){
    return texto;
}