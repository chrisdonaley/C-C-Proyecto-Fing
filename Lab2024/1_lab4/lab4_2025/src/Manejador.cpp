#include "../include/Manejador.h"

Manejador* Manejador::instance = NULL;

Manejador::Manejador() {
    ultimoCodigoPublicacion = 0;
    ultimoCodigoInmueble = 0;
}

Manejador::~Manejador()
{
    for (set<Inmobiliaria*>::iterator it = cInmobiliarias.begin(); it != cInmobiliarias.end(); it++)
    {
        delete (*it);
    }

    for (set<Propietario *>::iterator it = cPropietarios.begin(); it != cPropietarios.end(); it++)
    {
        delete (*it);
    }

    for (set<Cliente*>::iterator it = cClientes.begin(); it != cClientes.end(); it++)
    {
        delete (*it);
    }
    cInmobiliarias.clear();
    cPropietarios.clear();
    cClientes.clear();
    cCasa.clear();
    cApartamento.clear();
    cPublicaciones.clear();
    instance = NULL;
}

Manejador *Manejador::getInstance()
{
    if (instance == NULL)
    {
        instance = new Manejador();
    }
    return instance;
}

void Manejador::destruirInstance(){
    if (instance != NULL)
    {
        delete instance;
        instance = NULL;
    }
    
}

Inmobiliaria* Manejador::getInmobiliaria(string nickname){
    set<Inmobiliaria*>::iterator it = cInmobiliarias.begin();
    while (it != cInmobiliarias.end() && (*it)->getNickname() != nickname) {
        it++;
    }
    return it == cInmobiliarias.end() ? NULL: (*it);
} 

Propietario* Manejador::getPropietario(string nickname){
    set<Propietario *>::iterator it = cPropietarios.begin();
    while (it != cPropietarios.end() && (*it)->getNickname() != nickname)
    {
        it++;
    }
    return it == cPropietarios.end() ? NULL : (*it);
}

Cliente* Manejador::getCliente(string nickname){
    set<Cliente *>::iterator it = cClientes.begin();
    while (it != cClientes.end() && (*it)->getNickname() != nickname)
    {
        it++;
    }
    return it == cClientes.end() ? NULL : (*it);
}

Usuario* Manejador::getUsuario(string nickname) {

    Usuario* uRetorno = NULL;
    set<Usuario*> cUsuarios;
    cUsuarios.insert(cClientes.begin(), cClientes.end());
    cUsuarios.insert(cPropietarios.begin(), cPropietarios.end());
    cUsuarios.insert(cInmobiliarias.begin(), cInmobiliarias.end());
    // Itera sobre el conjunto de todos usuarios
    set<Usuario*>::iterator it = cUsuarios.begin();
    while (it != cUsuarios.end() && (*it)->getNickname()!=nickname) {
        it++;
    }
    if (it != cUsuarios.end()) uRetorno = (*it);
    // Limpia el conjunto temporal no se si es necesario y podria ocacionar falla
    cUsuarios.clear();
    return uRetorno;
}

// Añadir Apartamento
void Manejador::addApartamento(class Apartamento *a) {
    cApartamento.insert(a);
}

Inmueble *Manejador::getInmueble(int codigo){
    Inmueble* iRetorno = NULL;
    set<Inmueble*> inmueble;
    inmueble.insert(cCasa.begin(), cCasa.end());
    inmueble.insert(cApartamento.begin(), cApartamento.end());
    set<Inmueble*>::iterator it = inmueble.begin();
    while ((*it)->getCodigo() != codigo)
    {
        it++;
    }
    iRetorno = (*it);
    inmueble.clear();
    return iRetorno;
}

// Añadir Cliente
void Manejador::addCliente(Cliente *c) {
    cClientes.insert(c);
}

// Añadir Propietario
void Manejador::addPropietario(Propietario* p){
    cPropietarios.insert(p);
}

// Añadir Inmobiliaria
void Manejador::addInmobiliaria(Inmobiliaria *i) {
    cInmobiliarias.insert(i);
}

// Añadir Casa
void Manejador::addCasa(class Casa* c){
    cCasa.insert(c);
}

// Obtener el codigo del ultimo inmueble
int Manejador::getUltimoCodigoInmueble() {
    return ultimoCodigoInmueble;
}

void Manejador::setUltimoCodigoInmueble(int codigo) {
    ultimoCodigoInmueble = codigo;
}

// Obtener Publicacion por código
Publicacion* Manejador::getPublicacion(int codigo) {
    Publicacion* pRetorno = NULL;
    for (set<Publicacion*>::iterator it = cPublicaciones.begin(); it != cPublicaciones.end(); it++) {
        if ((*it)->getCodigo() == codigo) {
            pRetorno = *it;
        }
    }
    return pRetorno;
}

// Obtener el codigo del ultimo publicacion
int Manejador::getUltimoCodigoPublicacion() {
    return ultimoCodigoPublicacion;
}

void Manejador::setUltimoCodigoPublicacion(int codigo){
    ultimoCodigoPublicacion = codigo;
}

// Añadir Publicación
void Manejador::addPublicacion(Publicacion *p) {
    cPublicaciones.insert(p);
}  

set<Inmobiliaria*> Manejador::getInmobiliarias() {
    return cInmobiliarias;
}

set<Propietario*> Manejador::getPropietarios(){
    return cPropietarios;
}

set<Publicacion*> Manejador::getPublicaciones(){
    return cPublicaciones;
}