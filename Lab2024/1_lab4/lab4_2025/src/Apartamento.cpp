#include "../include/Apartamento.h"
#include "../include/TipoInmueble.h"
#include "../include/TipoTecho.h"

Apartamento::Apartamento(int codigo,string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes) : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion)
{
    this->piso = piso;
    this->tieneAscensor = tieneAscensor;
    this->gastosComunes = gastosComunes; 
}

Apartamento::~Apartamento() {
}

bool Apartamento::consultarTipo(TipoInmueble tipoInmueble) {
    return tipoInmueble == TipoInmueble::Apartamento;
}

DTInmueble* Apartamento::getDTInmueble(){
    DTInmueble* dta = new DTApartamento(getCodigo(), getDireccion(), getNumeroPuerta(), getSuperficie(), getAnoConstruccion(), piso, tieneAscensor, gastosComunes);
    return dta;
}