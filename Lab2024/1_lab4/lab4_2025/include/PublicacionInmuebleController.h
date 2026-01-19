#ifndef PUBLICACIONINMUEBLECONTROLLER_H
#define PUBLICACIONINMUEBLECONTROLLER_H

#include "IPublicacionInmuebleController.h"
#include "Manejador.h"

class PublicacionInmuebleController: public IPublicacionInmuebleController{
    private:
        static PublicacionInmuebleController* instance;
        PublicacionInmuebleController();

    public:
        virtual ~PublicacionInmuebleController();

        static PublicacionInmuebleController *getInstance();

        void destruirInstance();

        set<DTUsuario *> listarInmobiliarias();


        set<DTInmuebleAdministrado *> listarInmueblesAdministrados(string nicknameInmobiliaria);

        set<DTInmuebleListado *> listarInmueblesNoAdministradosInmobiliaria(string nicknameInmobiliaria);

        void altaAdministraPropiedad(string nicknameInmobiliaria, int codigoInmueble);


        bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio);
        
        
        set<DTPublicacion*> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble);
        
        
        DTInmueble *detalleInmueblePublicacion(int codigoPublicacion);
        
        
        set<DTInmuebleListado *> listarInmuebles();
        
        
        DTInmueble *detalleInmueble(int codigoInmueble);
        
        
        void eliminarInmueble(int codigoInmueble);
        
};

#endif