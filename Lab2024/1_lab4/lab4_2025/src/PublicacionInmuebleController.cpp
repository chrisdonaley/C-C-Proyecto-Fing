#include "../include/PublicacionInmuebleController.h"

PublicacionInmuebleController *PublicacionInmuebleController::instance = NULL;

PublicacionInmuebleController::PublicacionInmuebleController()
{
}

PublicacionInmuebleController::~PublicacionInmuebleController()
{
    Manejador* m = Manejador::getInstance();
    m->destruirInstance();
    instance = NULL;
}

PublicacionInmuebleController *PublicacionInmuebleController::getInstance()
{
    if (instance == NULL)
    {
        instance = new PublicacionInmuebleController();
    }
    return instance;
}

void PublicacionInmuebleController::destruirInstance(){
    if(instance != NULL){
        delete instance;
        instance = NULL;
    }
}

set<DTUsuario *> PublicacionInmuebleController::listarInmobiliarias(){
    set<DTUsuario*> conjRetorno;
    Manejador* m = Manejador::getInstance();
    set<Inmobiliaria*> li = m->getInmobiliarias();
    for (set<Inmobiliaria*>::iterator it = li.begin(); it != li.end(); it++) {
        DTUsuario* dt = (*it)->getDTUsuario();
        conjRetorno.insert(dt);
    }
    return conjRetorno;
}

set<DTInmuebleAdministrado *> PublicacionInmuebleController::listarInmueblesAdministrados(string nicknameInmobiliaria){
    Manejador* m = Manejador::getInstance();
    Inmobiliaria* i = m->getInmobiliaria(nicknameInmobiliaria);
    set<DTInmuebleAdministrado*> conjRetorno = i->getDTInmuebleAdministrado();
    return conjRetorno;
}

set<DTInmuebleListado *> PublicacionInmuebleController::listarInmueblesNoAdministradosInmobiliaria(string nicknameInmobiliaria){
    Manejador* m = Manejador::getInstance();
    Inmobiliaria* ci = m->getInmobiliaria(nicknameInmobiliaria);
    set<DTInmuebleListado*> listInmuebles = ci->getInmueblesNoAdminPropietario();   
    return listInmuebles;
}

void PublicacionInmuebleController::altaAdministraPropiedad(string nicknameInmobiliaria, int codigoInmueble){
    Manejador* m = Manejador::getInstance();
    Inmobiliaria* ci = m->getInmobiliaria(nicknameInmobiliaria);
    Inmueble* cin = m->getInmueble(codigoInmueble);
    ControladorFechaActual* controladorFecha = ControladorFechaActual::getInstance();
    DTFecha* fecha = controladorFecha->getFechaActual();
    ci->altaAdministracionPropiedad(cin, fecha);
}

bool PublicacionInmuebleController::altaPublicacion(string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, string texto, float precio){

    Manejador* m = Manejador::getInstance();
    ControladorFechaActual* cFecha = ControladorFechaActual::getInstance();
    DTFecha* fecha = cFecha->getFechaActual();
    int ultimoCodigo = m->getUltimoCodigoPublicacion();
    Inmobiliaria* i = m->getInmobiliaria(nicknameInmobiliaria);
    bool ok = i->crearPublicacion(codigoInmueble, tipoPublicacion, texto, precio, fecha, ultimoCodigo + 1);
    if(ok) m->setUltimoCodigoPublicacion(ultimoCodigo + 1);
    
    return ok; 
}

set<DTPublicacion *> PublicacionInmuebleController::listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble){
    set<DTPublicacion*> conjRetorno;
    Manejador* m = Manejador::getInstance();
    set<Publicacion*> cPublicaciones = m->getPublicaciones();
    DTPublicacion* dtPublicacion;
    for(set<Publicacion*>::iterator it = cPublicaciones.begin(); it != cPublicaciones.end(); it++){
        if((*it)->cumpleTipoPrecio(tipoPublicacion, precioMinimo, precioMaximo)){
            if(tipoInmueble == Todos){
                dtPublicacion = (*it)->getDTP();
                conjRetorno.insert(dtPublicacion);
            }
            else if((*it)->consultarTipo(tipoInmueble)){
                dtPublicacion = (*it)->getDTP();
                conjRetorno.insert(dtPublicacion); 
            }
        }
    }
    cPublicaciones.clear();
    return conjRetorno;
}

DTInmueble *PublicacionInmuebleController::detalleInmueblePublicacion(int codigoPublicacion){

    Manejador* m = Manejador::getInstance();
    Publicacion* p = m->getPublicacion(codigoPublicacion);
    Inmueble* inmueble = p->getAdminPropiedad()->getInmueble();
    DTInmueble* dtInmueble = inmueble->getDTInmueble();
    return dtInmueble;
}

set<DTInmuebleListado *> PublicacionInmuebleController::listarInmuebles(){
    set<DTInmuebleListado*> conjRetorno;
    Manejador* m = Manejador::getInstance();
    set<Propietario*> propietarios = m->getPropietarios();
    int codigo;
    string direccion;
    string propietarioNombre;
    for(set<Propietario*>::iterator it = propietarios.begin(); it != propietarios.end(); it++){
        propietarioNombre = (*it)->getNickname();
        set<Inmueble*> inmuebles = (*it)->getInmuebles();
        for(set<Inmueble*>::iterator it2 = inmuebles.begin(); it2 != inmuebles.end(); it2++){
            codigo = (*it2)->getCodigo();
            direccion = (*it2)->getDireccion();
            DTInmuebleListado* dtInmuebleListado = new DTInmuebleListado(codigo, direccion, propietarioNombre);
            conjRetorno.insert(dtInmuebleListado);
        }
    }
    return conjRetorno;
}

DTInmueble *PublicacionInmuebleController::detalleInmueble(int codigoInmueble){
    DTInmueble* dtRetorno;
    Manejador* m = Manejador::getInstance();
    Inmueble* in = m->getInmueble(codigoInmueble);
    dtRetorno = in->getDTInmueble();
    return dtRetorno;
}
void PublicacionInmuebleController::eliminarInmueble(int codigoInmueble){
    Manejador* m = Manejador::getInstance();
    Inmueble* in = m->getInmueble(codigoInmueble);
    delete in;
}

