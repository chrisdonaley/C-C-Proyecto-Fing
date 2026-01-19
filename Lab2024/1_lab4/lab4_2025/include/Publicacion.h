#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "DTFecha.h"
#include "TipoInmueble.h"
#include "TipoPublicacion.h"
#include "DTPublicacion.h"
#include <string>
using namespace std;
// #include "AdministraPropiedad.h"

//Cumple la función del include para que no haya un ciclo de inclusión
class AdministraPropiedad; // "Declaración adelanta de clases" 

class Publicacion {
private:
    int codigo;
    DTFecha* fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;
    AdministraPropiedad* adminPropiedad; 

public:
    /*Crea una instancia Publicacion con los datos proporcionados*/
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, string texto, float precio, bool activa, AdministraPropiedad* adminPropiedad);
    
    /*Destructor de Publicacion*/
    ~Publicacion();
    
    /*Retorna el codigo de la Publicacion*/
    int getCodigo();

    /*Retona la fecha de la Publicacion*/
    DTFecha* getFecha();
    
    /*Devuelve true si y solo si la Publicacion este activa*/
    bool getActiva();
    
    /*Setea la instancia Publicacion como activa*/
    void setActiva(bool activa);
    
    /*Devuelve true si y solo si el tipopublicacion de la Publicacion es igual a tipo, el precio minimo es mayor al precio minimo y el maximo es menor al precio maximo*/
    bool cumpleTipoPrecio(TipoPublicacion tipo, float precioMinimo, float precioMaximo);
    
    /*Devuelve el tipo de la Publicacion*/
    TipoPublicacion getTipo();
    
    /*Devuelve true si o si el Inmueble relacionado con la Publicacion, es del mismo tipo que tipoInmueble*/
    bool consultarTipo(TipoInmueble tipoInmueble);
    
    /*Devuelve un DTPublicacion con todos los datos*/
    DTPublicacion* getDTP();
    
    /*Devuelve instancia de AdministraPropiedad*/
    AdministraPropiedad* getAdminPropiedad();
    
    /*Borra el link de Publicacion a Administra Propiedad*/
    void deleteAdminPropiedad();
    
    /*Setea el link de Publicacion a Administra Propiedad*/
    void setAdminPropiedad(AdministraPropiedad* adminPropiedad);
};

#endif