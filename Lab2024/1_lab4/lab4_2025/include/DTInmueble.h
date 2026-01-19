#ifndef DTINMUEBLE_H
#define DTINMUEBLE_H
#include <string>
using namespace std;

class DTInmueble {
    private:
        int codigo;
        string direccion;
        int numeroPuerta;
        int superficie;
        int anioConstruccion;

    public:
        /*Construye instancia de DTInmueble*/
        DTInmueble(int codigo, string direccion, int numeroPuerta, int superficie, int anioConstruccion);
        
        /*Devuelve el codigo asociado al DTInmueble*/
        int getCodigo();
        
        /*Devuelve la direccion asociado al DTInmueble*/
        std::string getDireccion();
       
        /*Devuelve el numero de puerta asociado al DTInmueble*/
        int getNumeroPuerta();
        
        /*Devuelve el valor de superficie asociado al DTInmueble*/
        int getSuperficie();
        
        /*Devuelve el anio de construccion asociado al DTInmueble*/
        int getAnioConstruccion();
        
        /*Destruye la instancia de DTInmueble*/
        virtual ~DTInmueble();
};

#endif