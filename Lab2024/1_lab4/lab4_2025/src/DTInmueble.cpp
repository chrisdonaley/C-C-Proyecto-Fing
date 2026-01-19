#include "../include/DTInmueble.h"
using namespace std;

//DTInmueble(int codigo, string direccion, int numeroPuerta, int superficie, int anioConstruccion)
DTInmueble::DTInmueble(int codigo, string direccion, int numeroPuerta, int superficie, int anioConstruccion) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->numeroPuerta = numeroPuerta;
    this->superficie = superficie;
    this->anioConstruccion = anioConstruccion;
}

int DTInmueble::getCodigo() {
    return codigo;
}

std::string DTInmueble::getDireccion() {
    return direccion;
}

int DTInmueble::getNumeroPuerta() {
    return numeroPuerta;
}

int DTInmueble::getSuperficie() {
    return superficie;
}

int DTInmueble::getAnioConstruccion() {
    return anioConstruccion;
}

DTInmueble::~DTInmueble(){
    
}

