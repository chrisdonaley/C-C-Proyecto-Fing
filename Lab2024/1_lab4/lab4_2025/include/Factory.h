#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IUsuarioController.h"
#include "IPublicacionInmuebleController.h"

class Factory{
    private:
        static Factory *instance;
        Factory();

    public:

        //Retorna la instancia de Factory
        static Factory *getInstance();

        //Destruye dicha instancia
        void destruirInstance();

        //Retorna una instancia de IControladorFechaActual
        IControladorFechaActual *getControladorFechaActual();

        //Retorna una instancia de IUsuarioController
        IUsuarioController *getUsuarioController();

        //Retorna una instancia de IPublicacionInmuebleController
        IPublicacionInmuebleController *getPublicacionInmuebleController();

        ~Factory();
};

#endif