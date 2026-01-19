#include "../include/Casa.h"


Casa::Casa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo) : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion) {
    this->esPH = esPH;
    this->techo = techo;
}

Casa::~Casa(){
    
}
bool Casa::consultarTipo(TipoInmueble tipoInmueble) {
    return tipoInmueble == TipoInmueble::Casa;
}

DTInmueble* Casa::getDTInmueble() {
    DTInmueble *dtc = new DTCasa(getCodigo(), getDireccion(), getNumeroPuerta(), getSuperficie(), getAnoConstruccion(), esPH, techo);
    return dtc;
}