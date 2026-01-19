#include "../include/Inmobiliaria.h"

Inmobiliaria::Inmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono) : Usuario(nickname,contrasena,nombre,email) {
    this->direccion = direccion;
    this->url = url;
    this->telefono = telefono;
}

//Se retorna el conjunto de los datavalue dtia del tipo
//DTInmuebleAdministrado correspondientes a las instancias
//AdministraPropiedad ap que estén relacionadas con la Inmobiliaria i tal
//que dtia.fechaComienzo = ap.fecha, dtia.codigo =
//in.codigo y dtia.codigo = in.direccion donde in es el
//Inmueble relacionado a ap
set<DTInmuebleAdministrado *> Inmobiliaria::getDTInmuebleAdministrado()
{   
    set<DTInmuebleAdministrado*> conjuntoRetorno;
    for (set<AdministraPropiedad*>::iterator it = coleccionAdministraPropiedad.begin(); it != coleccionAdministraPropiedad.end(); it++){
        conjuntoRetorno.insert((*it)->getDTInmuebleAdministrado());
    }
    return conjuntoRetorno;
}

string Inmobiliaria::getNickname() {
    return Usuario::getNickname();
}

set<Usuario*> Inmobiliaria::getSuscriptores(){
    return suscriptores;
}

bool Inmobiliaria::crearPublicacion(int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio, DTFecha* fecha, int nuevoCodigo)
{
    set<AdministraPropiedad*>::iterator it = coleccionAdministraPropiedad.begin();
    bool si = false;
    bool ok = true;
    while ((it != coleccionAdministraPropiedad.end()) && (!si))
    {
        si = (*it)->tieneCodigoInmueble(codigoInmueble);
        if(!si){ 
            it++;
        }
    }
    if (si)
    {
        ok = (*it)->sePuedeCrear(tipoPublicacion, fecha);
    }
    if (ok)
    {
        (*it)->crearPublicacion(tipoPublicacion, texto, precio, nuevoCodigo, fecha);
        TipoInmueble tipoin;
        if ((*it)->getInmueble()->consultarTipo(Casa))
        {
            tipoin = Casa;
        }
        else
        {
            tipoin = Apartamento;
        }
        this->notificarObservadores(this->getNickname(), nuevoCodigo, tipoPublicacion, tipoin, texto);
    }

    return ok;
}

Inmobiliaria::~Inmobiliaria() {
    coleccionAdministraPropiedad.clear();
    coleccionPropietarios.clear();
    suscriptores.clear();
}

DTUsuario* Inmobiliaria::getDTUsuario() {
    return new DTUsuario(Usuario::getNickname(), Usuario::getNombre());
}

set<DTInmuebleListado *> Inmobiliaria::getInmueblesNoAdminPropietario()
{
    set<DTInmuebleListado *> conjRetorno;
    for (set<Propietario*>::iterator it = coleccionPropietarios.begin(); it != coleccionPropietarios.end(); it++)
    {
        set<DTInmuebleListado *> listInmueblesPropietario = (*it)->getInmueblesNoAdmin(this);
        conjRetorno.insert(listInmueblesPropietario.begin(), listInmueblesPropietario.end());
    }
    return conjRetorno;
}

void Inmobiliaria::eliminarLinkAdminPropiedad(AdministraPropiedad *ap){
    coleccionAdministraPropiedad.erase(ap);
}

    void Inmobiliaria::añadirPropietario(Propietario *p)
{
    coleccionPropietarios.insert(p);
}

void Inmobiliaria::altaAdministracionPropiedad(Inmueble* inmueble, DTFecha* fecha){
    AdministraPropiedad* ap = new AdministraPropiedad(fecha, inmueble, this); 
    coleccionAdministraPropiedad.insert(ap);
    inmueble->asociarAdministracionPropiedad(ap);
}

void Inmobiliaria::notificarUsuario(string nickname, int codigoPub, TipoPublicacion tipoPub, TipoInmueble tipoInmueble, string texto){
    return;
    // Este método es implementado para cumplir con la interfaz de Usuario
    // aunque en este caso no se usa directamente.
    // La notificación se maneja a través de notificarObservadores.
}

void Inmobiliaria::notificarObservadores(string nickname, int codigoPub, TipoPublicacion tipoPub, TipoInmueble tipoInmueble, string texto){
    for (set<Usuario*>::iterator it = suscriptores.begin(); it != suscriptores.end(); it++) {
        (*it)->notificarUsuario(nickname,codigoPub,tipoPub,tipoInmueble,texto);
    }
}

void Inmobiliaria::anadirObservadores(Usuario* o) {
    suscriptores.insert(o);
}

void Inmobiliaria::eliminarObservadores(Usuario* o) {
    suscriptores.erase(o);
}

string Inmobiliaria::getDireccion(){
    return direccion;
}

string Inmobiliaria::getUrl(){
    return url;
}

string Inmobiliaria::getTelefono(){
    return telefono;
}