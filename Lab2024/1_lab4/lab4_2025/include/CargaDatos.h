#ifndef CARGADATOS_H
#define CARGADATOS_H

#include "IUsuarioController.h"
#include "Factory.h"
#include "Manejador.h"
#include "IPublicacionInmuebleController.h"
#include "IControladorFechaActual.h"

class CargaDatos {
    private:
        static CargaDatos* instance;
        CargaDatos();

    public:
        /*Carga todos los datos proporcionados*/
        static CargaDatos* getInstance();

        /*Destructor*/
        ~CargaDatos();

        /*Destruye y apunta la instancia a NULL*/
        void destruirInstance();
};

#endif