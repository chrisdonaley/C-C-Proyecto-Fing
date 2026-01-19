#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include "../include/UsuarioController.h"
#include "../include/PublicacionInmuebleController.h"
#include <cstddef>

Factory* Factory::instance = NULL;

Factory::Factory() {
}

Factory* Factory::getInstance() {
    if (instance == NULL) {
        instance = new Factory();
    }
    return instance;
}

void Factory::destruirInstance(){
    if (instance != NULL)
    {
        delete instance;
    }
    
}

    IControladorFechaActual *Factory::getControladorFechaActual()
{
    return ControladorFechaActual::getInstance();
}

IUsuarioController* Factory::getUsuarioController(){
    return UsuarioController::getInstance();
}

IPublicacionInmuebleController *Factory::getPublicacionInmuebleController(){
    return PublicacionInmuebleController::getInstance();
}

Factory::~Factory()
{
    UsuarioController* u = UsuarioController::getInstance();
    u->destruirInstance();
    PublicacionInmuebleController* p = PublicacionInmuebleController::getInstance();
    p->destruirInstance();
    ControladorFechaActual* f = ControladorFechaActual::getInstance();
    delete f;
    instance = NULL;
}