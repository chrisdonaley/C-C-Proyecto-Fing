#include "../include/UsuarioController.h"
#include <map>

UsuarioController* UsuarioController::instance = NULL;

UsuarioController::UsuarioController(){}

UsuarioController::~UsuarioController(){
    Manejador *m = Manejador::getInstance();
    m->destruirInstance();
    instance = NULL;
}

UsuarioController* UsuarioController::getInstance(){
    if(instance == NULL)
        instance = new UsuarioController();
    return instance;
}

void UsuarioController::destruirInstance(){
    if (instance != NULL){
        delete instance;
        instance = NULL;
    }
}

bool UsuarioController::altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento) { 

    Manejador* manejador = Manejador::getInstance();
    Usuario* existe = manejador->getUsuario(nickname);
    if (existe != NULL) return false; 
    else{
        Cliente* nuevoCliente = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
        manejador->addCliente(nuevoCliente);
        return true;
   }    
}

bool UsuarioController::altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono) { 
    
    Manejador* manejador = Manejador::getInstance();
    Usuario* existe = manejador->getUsuario(nickname);
    if (existe != NULL) return false; 
    else{
        Propietario* nuevoPropietario = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        manejador->addPropietario(nuevoPropietario);    
        this->p = nuevoPropietario; 
        return true;
        }
    }

bool UsuarioController::altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono) { 
   
    Manejador* manejador = Manejador::getInstance();

    Usuario* existe = manejador->getUsuario(nickname);
    if (existe != NULL) return false; 
    else{
        Inmobiliaria* nuevaInmobiliaria = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
        manejador->addInmobiliaria(nuevaInmobiliaria);
        this->i = nuevaInmobiliaria;
        return true; 
    }
}

void UsuarioController::altaCasa(string direccion, int numeroPuerta, int superficie, int anoContruccion, bool esPH, TipoTecho techo) {

    Manejador* manejador = Manejador::getInstance();

    if (this->p != NULL) {

        int nuevoCodigo = manejador->getUltimoCodigoInmueble() + 1;
        manejador->setUltimoCodigoInmueble(nuevoCodigo);

        class Casa* nuevaCasa = new class Casa(nuevoCodigo, direccion, numeroPuerta, superficie, anoContruccion, esPH, techo);
        manejador->addCasa(nuevaCasa);
        nuevaCasa->Inmueble::addPropietario(p);
        p->añadirInmuebles(nuevaCasa);

    }

}

void UsuarioController::altaApartamento(string direccion, int numeroPuerta, int superficie, int anoContruccion, int piso, bool tieneAscensor, float gastosComunes) {
    
    Manejador* manejador = Manejador::getInstance();

    if (this->p != NULL) {

        int nuevoCodigo = manejador->getUltimoCodigoInmueble() + 1;
        manejador->setUltimoCodigoInmueble(nuevoCodigo);

        class Apartamento* nuevoApto = new class Apartamento(nuevoCodigo, direccion, numeroPuerta, superficie, anoContruccion, piso, tieneAscensor, gastosComunes);
        manejador->addApartamento(nuevoApto);
        nuevoApto->Inmueble::addPropietario(p);
        p->añadirInmuebles(nuevoApto);

    }
}

set<DTUsuario *> UsuarioController::listarPropietarios(){

    Manejador* manejador = Manejador::getInstance();

    set<DTUsuario*> conjRetorno;
    set<Propietario*> cPropietarios = manejador->getPropietarios();

    for (set<Propietario*>::iterator it = cPropietarios.begin(); it != cPropietarios.end(); it++) {
        
        DTUsuario* dtu = (*it)->getDTUsuario();
        conjRetorno.insert(dtu);
    } 

    return conjRetorno;
}

void UsuarioController::representarPropietario(string nicknamePropietario){

    Manejador* manejador = Manejador::getInstance();
    i->añadirPropietario(manejador->getPropietario(nicknamePropietario));
}

void UsuarioController::finalizarAltaUsuario(){
        p = NULL;
        i = NULL;
        cs = NULL;
        ps = NULL;
}

set<DTInmobiliaria *> UsuarioController::listarNoSuscritas(string nickName) {
    set<DTInmobiliaria*> conjRetorno;
    Manejador* m = Manejador::getInstance();
    set<Inmobiliaria*> ci = m->getInmobiliarias();
    Propietario* p = m->getPropietario(nickName);
    Cliente* c = m->getCliente(nickName);

    set<Inmobiliaria*> suscripciones;
    if (c!=NULL) {
        suscripciones = c->getSuscripciones();
        this->cs = c;
    }
    if (p!=NULL) {
        suscripciones = p->getSuscripciones();
        this->ps = p;
    }

    for(set<Inmobiliaria*>::iterator it=ci.begin(); it!=ci.end();it++){
        if (suscripciones.find((*it))==suscripciones.end()){
            DTInmobiliaria* i = new DTInmobiliaria((*it)->getNickname(),(*it)->getDireccion(),(*it)->getUrl(),(*it)->getTelefono(),(*it)->getSuscriptores());
            conjRetorno.insert(i);
        }
    }
    suscripciones.clear();
    return conjRetorno;
}   

void UsuarioController::generarSuscripcion(string nicknameInmobiliaria) {
    Manejador* m = Manejador::getInstance();
    Inmobiliaria* i = m->getInmobiliaria(nicknameInmobiliaria);

    if (cs!=NULL){
        i->anadirObservadores(cs);
        cs->añadirSuscripcion(i);
    } else if (ps!=NULL){
        i->anadirObservadores(ps);
        ps->añadirSuscripcion(i);
    }
}   

list<DTNotificacion *> UsuarioController::consultarNotificaciones(string nickName) {
    Manejador* m = Manejador::getInstance();
    list<DTNotificacion*> copiaLista;
    Propietario* p = m->getPropietario(nickName);
    Cliente* c = m->getCliente(nickName);

    if (c!=NULL) {
        copiaLista = c->getNotificaciones();
        c->eliminarNotificaciones();
    }
    if (p!=NULL) {
        copiaLista = p->getNotificaciones();
        p->eliminarNotificaciones();
    }
    c = NULL;
    p = NULL;
    return copiaLista;
}   

set<DTInmobiliaria *> UsuarioController::listarSuscripciones(string nickName) {
    set<DTInmobiliaria*> conjRetorno;
    Manejador* m = Manejador::getInstance();
    set<Inmobiliaria*> ci = m->getInmobiliarias();
    Propietario* p = m->getPropietario(nickName);
    Cliente* c = m->getCliente(nickName);

    set<Inmobiliaria*> suscripciones;
    if (c!=NULL) {
        suscripciones = c->getSuscripciones();
        this->cs = c;
    }
    if (p!=NULL) {
        suscripciones = p->getSuscripciones();
        this->ps = p;
    }
    
    for(set<Inmobiliaria*>::iterator it=ci.begin(); it!=ci.end();it++){
        if (suscripciones.find((*it))!=suscripciones.end()){
            DTInmobiliaria* i = new DTInmobiliaria((*it)->getNickname(),(*it)->getDireccion(),(*it)->getUrl(),(*it)->getTelefono(),(*it)->getSuscriptores());
            conjRetorno.insert(i);
        }
    }
    suscripciones.clear();
    return conjRetorno;
}

void UsuarioController::eliminarSuscripcion(string nicknameInmobiliaria) {
    
    Manejador* m = Manejador::getInstance();
    Inmobiliaria* i = m->getInmobiliaria(nicknameInmobiliaria);
    if (cs!=NULL){
        i->eliminarObservadores(cs);
        cs->eliminarSuscripcion(i);
    } else if (ps!=NULL){
        i->eliminarObservadores(ps);
        ps->eliminarSuscripcion(i);
    }
}
