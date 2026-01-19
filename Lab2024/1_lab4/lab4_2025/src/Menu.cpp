#include <iostream>
#include "../include/Menu.h"
#include "../include/CargaDatos.h"
#include "../include/TipoInmueble.h"
#include "../include/TipoPublicacion.h"
#include "../include/TipoTecho.h"
#include "../include/Factory.h"
#include "../include/DTApartamento.h"
#include "../include/DTCasa.h"
#include "../include/DTFecha.h"
#include "../include/DTInmueble.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTPublicacion.h"
#include "../include/DTUsuario.h"
#include <string>
#include <set>
using namespace std; 

void mostrarMenu() {
    std::cout << "=== Menu de Operaciones ===" << std::endl;
    std::cout << "1. Alta de Usuario" << std::endl;
    std::cout << "2. Alta de Publicacion" << std::endl;
    std::cout << "3. Consulta de Publicaciones" << std::endl;
    std::cout << "4. Eliminar Inmueble" << std::endl;
    std::cout << "5. Suscribirse a Notificaciones" << std::endl;
    std::cout << "6. Consulta de Notificaciones" << std::endl;
    std::cout << "7. Eliminar Suscripciones" << std::endl;
    std::cout << "8. Alta de Administracion de Propiedad" << std::endl;
    std::cout << "9. Cargar Datos" << std::endl;
    std::cout << "10. Ver fecha actual" << std::endl;
    std::cout << "11. Asignar fecha actual" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Ingrese el codigo de operacion: ";
}

int obtenerOpcion() {
    int opcion;
    std::cin >> opcion;
    std::cin.ignore();
    return opcion;
}

void ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            std::cout << " - ALTA DE USUARIO - " << std::endl;
            altaUsuario();
            break;
        case 2:
            std::cout << " - ALTA DE PUBLICACION - " << std::endl;
            altaPublicacion();
            break;
        case 3:
            std::cout << " - CONSULTA DE PUBLICACIONES - " << std::endl;
            consultaPublicaciones();
            break;
        case 4:
            std::cout << " - ELIMINAR INMUEBLE - " << std::endl;
            eliminarInmueble();
            break;
        case 5:
            std::cout << " - SUSCRIBIRSE A NOTIFICACIONES - " << std::endl;
            suscribirseNotificaciones();
            break;
        case 6:
            std::cout << " - CONSLTAR NOTIFICACIONES - " << std::endl;
            consultaNotificaciones();
            break;
        case 7:
            std::cout << " - ELIMINAR SUSCRIPCIONES - " << std::endl;
            eliminarSuscripciones();
            break;
        case 8:
            std::cout << " - ALTA ADMINISTRACION DE PROPIEDAD - " << std::endl;
            altaAdministracionPropiedad();
            break;
        case 9:
            std::cout << " - CARGAR DATOS - " << std::endl;
            cargarDatos();
            break;
        case 10:
            std::cout << " - VER FECHA ACTUAL - " << std::endl;
            verFechaActual();
            break;
        case 11:
            std::cout << " - ASIGNAR FECHA ACTUAL - " << std::endl;
            asignarFechaActual();
            break;
        case 0:
            std::cout << "Saliendo del programa..." << std::endl;
            liberarMemoria();
            exit(0);
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
    }
}

void liberarMemoria()
{
    Factory *f = Factory::getInstance();
    f->destruirInstance();
}

void altaUsuario(){

    Factory* factory = Factory::getInstance();

    // Solicito el controlador de Usuario
    IUsuarioController* controlador = factory->getUsuarioController();

    std::cout << "Ingrese el tipo de usuario (0: Cliente, 1: Inmobiliaria, 2: Propietario): ";
    int tipoUsuario;
    std::cin >> tipoUsuario;
    std::cin.ignore();
    if (tipoUsuario < 0 || tipoUsuario > 2){
        std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        return;
    }

    bool usuarioOk = false;
    
    std::string nickname;
    std::string contrasena;
    std::string nombre;
    std::string email;
    std::string apellido;
    std::string documento;
    std::string url;
    std::string telefono;
    std::string direccion;
    std::string cuentaBancaria;
    
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Contrasena: ";
    std::getline(std::cin, contrasena);
    while (contrasena.length() < 6)
    {
        std::cout << "La contrasena debe tener al menos 6 caracteres.\n" << "Contrasena: ";
        std::getline(std::cin, contrasena);
    }
    
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Email: ";
    std::getline(std::cin, email);

    if (tipoUsuario == 0){
        std::cout << "Apellido: ";
        std::getline(std::cin, apellido);
        std::cout << "Documento: ";
        std::getline(std::cin, documento);
        usuarioOk = controlador->altaCliente(nickname, contrasena, nombre, email, apellido, documento);

    }else if (tipoUsuario == 1){
        std::cout << "Direccion: ";
        std::getline(std::cin, direccion);
        std::cout << "URL: ";
        std::getline(std::cin, url);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        usuarioOk = controlador->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);

    }else if (tipoUsuario == 2){
        std::cout << "Cuenta Bancaria: ";
        std::getline(std::cin, cuentaBancaria);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        usuarioOk = controlador->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);

    }
    if (usuarioOk){
        if (tipoUsuario == 1 || tipoUsuario == 2){
            int salir = 1;
            std::cout << "¿Quiere ingresar los datos relacionados? (1: Si, 0: No): ";
            std::cin >> salir;
            std::cin.ignore();
            std::string inmuebleDireccion;
            int numeroPuerta;
            int superficie;
            int anoConstruccion;
            while (salir != 0){
                if (tipoUsuario == 1){
                    std::cout << "Lista de Propietarios:\n";
                    std::set<DTUsuario*> coleccionDTUsuarios = controlador->listarPropietarios();
                    //Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
                    for (std::set<DTUsuario*>::iterator it = coleccionDTUsuarios.begin(); it != coleccionDTUsuarios.end(); it++)
                    {
                        std::cout << "- Nickname: " << (*it)->getNickname() << ", Nombre: " << (*it)->getNombre() << std::endl;
                    }
                    std::cout << "Nickname propietario a representar: ";
                    std::string nicknamePropietario;
                    std::getline(std::cin, nicknamePropietario);
                    controlador->representarPropietario(nicknamePropietario);

                    // Liberamos memoria
                    for (std::set<DTUsuario *>::iterator it = coleccionDTUsuarios.begin(); it != coleccionDTUsuarios.end(); it++)
                    {
                        delete *it;
                    }
                    coleccionDTUsuarios.clear();

                }else if (tipoUsuario == 2){
                    int tipoInmueble;
                    std::cout << "Indique el tipo de inmueble (1: Casa, 0: Apartamento): ";
                    std::cin >> tipoInmueble;
                    std::cin.ignore();
    
                    std::cout << "Direccion: ";
                    std::getline(std::cin, inmuebleDireccion);
                    std::cout << "Numero de Puerta: ";
                    std::cin >> numeroPuerta;
                    std::cin.ignore(); 
                    std::cout << "Superficie: ";
                    std::cin >> superficie;
                    std::cin.ignore();
                    std::cout << "Ano de Construccion: ";
                    std::cin >> anoConstruccion;
                    std::cin.ignore();

                    if (tipoInmueble == 1){
                        std::cout << "Es PH (1 para si, 0 para no): ";
                        int inEsPH;
                        std::cin >> inEsPH;
                        bool esPH = (inEsPH == 1);
                        std::cin.ignore();
                        std::cout << "Tipo de Techo (0: Liviano 1: A dos aguas, 2: Plano): ";
                        int inTipoTecho;
                        std::cin >> inTipoTecho;
                        std::cin.ignore();
                        TipoTecho techo = Liviano;
                        if(inTipoTecho == 1){
                            techo = A_dos_aguas;
                        }else if (inTipoTecho == 2){
                            techo = Plano;
                        }
                        controlador->altaCasa(direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
                    }else{
                        int piso;
                        std::cout << "Piso: ";
                        std::cin >> piso;
                        std::cin.ignore();
                        std::cout << "Tiene Ascensor (1 para si, 0 para no): ";
                        int inTieneAscensor;
                        std::cin >> inTieneAscensor;
                        bool tieneAscensor = (inTieneAscensor == 1);
                        std::cin.ignore();
                        std::cout << "Gastos Comunes: ";
                        float gastosComunes;
                        std::cin >> gastosComunes;
                        std::cin.ignore();
                        controlador->altaApartamento(direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
                    }
                }
                std::cout << "¿Quiere seguir ingresando? (1: Si, 0: No): ";
                std::cin >> salir;
                std::cin.ignore();
            }
        }
        controlador->finalizarAltaUsuario();
    }else{
        std::cout << "Error al crear el usuario" << std::endl;
    }
}

void altaPublicacion(){

    Factory* factory = Factory::getInstance();

    // Solicito un cotrolador de Publicacion
    IPublicacionInmuebleController* controlador = factory->getPublicacionInmuebleController();

    std::cout << "Lista de Inmobiliarias:\n";
    std::set<DTUsuario*> coleccionDTUsuarios = controlador->listarInmobiliarias();
    //Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
    for (std::set<DTUsuario *>::iterator it = coleccionDTUsuarios.begin(); it != coleccionDTUsuarios.end(); it++)
    {
        std::cout << "- Nickname: " << (*it)->getNickname() << ", Nombre: " << (*it)->getNombre() << std::endl;
    }
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);

    // Liberamos la memoria
    for (std::set<DTUsuario *>::iterator it = coleccionDTUsuarios.begin(); it != coleccionDTUsuarios.end(); it++)
    {
        delete *it;
    }
    coleccionDTUsuarios.clear();

    std::set<DTInmuebleAdministrado*> coleccionDTInmueblesAdministrados = controlador->listarInmueblesAdministrados(nicknameInmobiliaria);
    //Recorrer la coleccion Mostrar "- Codigo: xx, Direccion: yy, Propietario: zzz"
    for (std::set<DTInmuebleAdministrado *>::iterator it = coleccionDTInmueblesAdministrados.begin(); it != coleccionDTInmueblesAdministrados.end(); it++)
    {
        std::cout << "- Codigo: " << (*it)->getCodigo() << ", Direccion: " << (*it)->getDireccion() << ", Fecha: " << (*it)->getFechaComienzo() << std::endl;
    }
    int codigoInmueble;
    std::cout << "Inmueble: ";
    std::cin >> codigoInmueble;
    std::cin.ignore();

    // Liberamos la memoria
    for (std::set<DTInmuebleAdministrado *>::iterator it = coleccionDTInmueblesAdministrados.begin(); it != coleccionDTInmueblesAdministrados.end(); it++)
    {
        delete *it;    
    }
    coleccionDTInmueblesAdministrados.clear();

    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Texto: ";
    std::string texto;
    std::getline(std::cin, texto);
    std::cout << "Precio: ";
    float precio;
    std::cin >> precio;
    std::cin.ignore();
    controlador->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio);
}

void consultaPublicaciones(){

    Factory* factory = Factory::getInstance();

    // Solicitamos instancia de controlador de Publicacion
    IPublicacionInmuebleController* controlador = factory->getPublicacionInmuebleController();

    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Precio (Min): ";
    float precioMinimo;
    std::cin >> precioMinimo;
    std::cin.ignore();
    std::cout << "Precio (Max): ";
    float precioMaximo;
    std::cin >> precioMaximo;
    std::cin.ignore();
    int inTipoInmueble;
    std::cout << "Tipo de Inmueble: (1: Casa, 2: Apartamento, 0: Todos)";
    std::cin >> inTipoInmueble;
    std::cin.ignore();
    TipoInmueble tipoInmueble = Todos;
    if(inTipoInmueble == 1){
        tipoInmueble = Casa;
    }else if(inTipoInmueble == 2){
        tipoInmueble = Apartamento;
    }
    std::cout << "Publicaciones encontradas:\n";
    std::set<DTPublicacion*> cooleccionDTPublicaciones = controlador->listarPublicacion(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble);
    //Recorrer la coleccion Mostrar "- Codigo: xx, fecha: dd/mm/yyyy, texto: zzz, precio: aaa, inmobiliaria: bbb";
    for (std::set<DTPublicacion *>::iterator it = cooleccionDTPublicaciones.begin(); it != cooleccionDTPublicaciones.end(); it++)
    {
        std::cout << "- Codigo: " << (*it)->getCodigo() << ", fecha: " << (*it)->getFecha()->toString() << ", texto: " << (*it)->getTexto() << ", precio: " << (*it)->getPrecio() << ", inmobiliaria: " << (*it)->getInmobiliaria() << std::endl;
    }
    int verDetalle;
    std::cout << "Ver detalle de la publicacion: (1: Si, 0: No)";
    std::cin >> verDetalle;
    std::cin.ignore();

    if (verDetalle == 1){
        std::cout << "Codigo de publicacion: ";
        int codigoPublicacion;
        std::cin >> codigoPublicacion;
        std::cin.ignore();
        std::cout << "Detalle del inmueble:\n";
        DTInmueble* dtInmueble = controlador->detalleInmueblePublicacion(codigoPublicacion);
        //Mostrarlo:
        // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
        // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
        DTCasa* dtCasa = dynamic_cast<DTCasa*>(dtInmueble);
        if (dtCasa != NULL)
        {
            std::cout << "Codigo: " << dtCasa->getCodigo() << "\nDireccion: " << dtCasa->getDireccion() << "\nNro. puerta: " << dtCasa->getNumeroPuerta() << "\nSuperficie: " << dtCasa->getSuperficie() << " m2\nContruccion: " << dtCasa->getAnioConstruccion() << "\nPH: " << (dtCasa->getEsPH() ? "Si":"No") << "\nTipo de techo: " << dtCasa->getTecho() << std::endl;
            // Liberamos la memoria
            delete dtCasa; 
            dtCasa = NULL;          
        }else{
            DTApartamento *dtApartamento = dynamic_cast<DTApartamento *>(dtInmueble);
            std::cout << "Codigo: " << dtApartamento->getCodigo() << "\nDireccion: " << dtApartamento->getDireccion() << "\nNro. puerta: " << dtApartamento->getNumeroPuerta() << "\nSuperficie: " << dtApartamento->getSuperficie() << " m2\nConstruccion: " << dtApartamento->getAnioConstruccion() << "\nPiso: " << dtApartamento->getPiso() << "\nTiene ascensor: " << (dtApartamento->getTieneAscensor() ? "Si" : "No") << "\nGastos comunes: " << dtApartamento->getGastosComunes() << std::endl;
            // Liberamos la memoria
            delete dtApartamento;
            dtApartamento = NULL;
        }
        dtInmueble = NULL;
    }

    // Liberamos la memoria
    for (std::set<DTPublicacion *>::iterator it = cooleccionDTPublicaciones.begin(); it != cooleccionDTPublicaciones.end(); it++)
    {
        delete *it;    
    }
    cooleccionDTPublicaciones.clear();
}

void eliminarInmueble(){

    Factory* factory = Factory::getInstance();

    // Solicito controlador para Inmuebles
    IPublicacionInmuebleController* controlador = factory->getPublicacionInmuebleController();

    std::cout << "Listado de inmuebles:\n";
    std::set<DTInmuebleListado*> coleccionDTInmueblesListados = controlador->listarInmuebles();
    //Recorrer la coleccion Mostrar "- Codigo: xx, direccion: xxxx, propietario: bbbbb";
    for (std::set<DTInmuebleListado *>::iterator it = coleccionDTInmueblesListados.begin(); it != coleccionDTInmueblesListados.end(); it++)
    {
        std::cout << "- Codigo: " << (*it)->getCodigo() << ", direccion: " << (*it)->getDireccion() << ", propietario: " << (*it)->getPropietario() << std::endl;
    }
    std::cout << "Codigo del inmueble a eliminar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();

    //Liberamos memoria
    for (std::set<DTInmuebleListado *>::iterator it = coleccionDTInmueblesListados.begin(); it != coleccionDTInmueblesListados.end(); it++)
    {
        delete *it;
    }
    coleccionDTInmueblesListados.clear();

    std::cout << "Detalle del inmueble:\n";
    DTInmueble *dtInmueble = controlador->detalleInmueble(codigoInmueble);
    //Mostrarlo:
    // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
    // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
    DTCasa* dtCasa = dynamic_cast<DTCasa*>(dtInmueble);
    if (dtCasa != NULL)
    {
        std::cout << "Codigo: " << dtCasa->getCodigo() << "direccion: " << dtCasa->getDireccion() << "nro. puerta: " << dtCasa->getNumeroPuerta() << "superficie: " << dtCasa->getSuperficie() << " m2, contruccion: " << dtCasa->getAnioConstruccion() << ", PH: " << (dtCasa->getEsPH() ? "Si" : "No") << ", Tipo de techo: " << dtCasa->getTecho() << std::endl;
        // Liberamos la memoria
        delete dtCasa;
        dtCasa = NULL;
    }
    else
    {
        DTApartamento *dtApartamento = dynamic_cast<DTApartamento *>(dtInmueble);
        std::cout << "Codigo: " << dtApartamento->getCodigo() << ", direccion: " << dtApartamento->getDireccion() << ", nro. puerta: " << dtApartamento->getNumeroPuerta() << ", superficie: " << dtApartamento->getSuperficie() << " m2, construccion: " << dtApartamento->getAnioConstruccion() << ", piso: " << dtApartamento->getPiso() << (dtApartamento->getTieneAscensor() ? "Si" : "No") << ", gastos comunes: " << dtApartamento->getGastosComunes() << std::endl;
        // Liberamos la memoria
        delete dtApartamento;
        dtApartamento = NULL; 
    }
    dtInmueble = NULL;
    int deseaEliminar;
    std::cout << "¿Desea eliminar?: (1: Si, 0: No)";
    std::cin >> deseaEliminar;
    std::cin.ignore();
    if (deseaEliminar == 1){
        controlador->eliminarInmueble(codigoInmueble);
    }
}

void suscribirseNotificaciones(){
    Factory* factory = Factory::getInstance();

    // Solicito un controlador de Usuario
    IUsuarioController* controlador = factory->getUsuarioController();
    std::string nicknameUsuario;
    std::cout << "Ingrese el nickname del Usuario: ";
    cin >> nicknameUsuario;
    std::cin.ignore();
    std::set<DTInmobiliaria*> listaNoSus = controlador->listarNoSuscritas(nicknameUsuario);
    cout << "Lista de Inmobiliarias a las que puede suscribirse:\n";
    for (std::set<DTInmobiliaria *>::iterator it = listaNoSus.begin(); it != listaNoSus.end(); it++)
    {
        std::cout << "Nickname de la Inmobiliaria: " << (*it)->getNicknameInmobiliaria() << ", Direccion: " << (*it)->getDireccion() << ", URL: " << (*it)->getUrl() << ", Telefono: " << (*it)->getTelefono() << std::endl;
    }
    int deseaSuscribirse = 1;
    std::string nicknameInmobiliaria;

    // Liberamos la memoria
    for (std::set<DTInmobiliaria *>::iterator it = listaNoSus.begin(); it != listaNoSus.end(); it++)
    {
        delete *it;
    }
    listaNoSus.clear();
    
    while (deseaSuscribirse != 0){
        cout << "Desea suscribirse a alguna inmobiliaria? (1: Si, 0: No): ";
        std::cin >> deseaSuscribirse;
            switch(deseaSuscribirse){
                case 1: {
                    std::cout << "Ingrese el nickname de la inmobiliaria a la que desea suscribirse: ";
                    std::cin >> nicknameInmobiliaria;
                    std::cin.ignore();
                    controlador->generarSuscripcion(nicknameInmobiliaria);
                    std::cout << "Suscripcion exitosa!" << std::endl;
                    break;
                }
                case 0:
                    std::cout << "No se realizo ninguna suscripcion." << std::endl;
                    break;
                default:
                std::cout << "Opcion no valida." << std::endl;
        }
    }
}

void consultaNotificaciones(){
    Factory *factory = Factory::getInstance();

    // Solicito un controlador de Usuario
    IUsuarioController *controlador = factory->getUsuarioController();

    std::string nickname;
    std::cout << "Ver notificaciones del usuario con nickname: ";
    std::cin >> nickname;
    std::cin.ignore();
    std::list<DTNotificacion*> listaNotificaciones = controlador->consultarNotificaciones(nickname);
    for (std::list<DTNotificacion *>::iterator it = listaNotificaciones.begin(); it != listaNotificaciones.end(); it++)
    {
        std::cout << "Nickname de la Inmobiliaria: " << (*it)->getNicknameInmobiliaria() << ", codigo de la publicacion: " << (*it)->getCodigoPub() << ", tipo: " << (*it)->getTipoPublicacion() << ", tipo del inmueble: " << (*it)->getTipoInmueble() << ", texto: " << (*it)->getTexto() << std::endl;
        // Liberamos la memoria
        delete (*it);
    }
    listaNotificaciones.clear();
}

void eliminarSuscripciones(){
    Factory *factory = Factory::getInstance();

    // Solicito un controlador de Usuario
    IUsuarioController *controlador = factory->getUsuarioController();

    std::string nickname;
    std::cout << "Eliminar suscripciones del usuario con nickname: ";
    std::cin >> nickname;
    std::cin.ignore();
    std::set<DTInmobiliaria*> coleccionInmobiliarias = controlador->listarSuscripciones(nickname);
    if(coleccionInmobiliarias.size()==0){
        std::cout << "No hay inmobiliarias a las que el usuario este suscrito\n";
    } else {
        
        for (std::set<DTInmobiliaria *>::iterator it = coleccionInmobiliarias.begin(); it != coleccionInmobiliarias.end(); it++)
        {
            std::cout << "Nickname de la Inmobiliaria: " << (*it)->getNicknameInmobiliaria() << ", Direccion: " << (*it)->getDireccion() << ", URL: " << (*it)->getUrl() << ", Telefono: " << (*it)->getTelefono() << std::endl;

            // Liberamos la memoria
            delete (*it);
        }
        int eliminarSuscripcion=1;
        std::string nicknameInmobiliaria;
        while(eliminarSuscripcion==1){
            if (coleccionInmobiliarias.size()==0){
                std::cout << "No hay inmobiliarias a las que el usuario este suscrito\n";
                break;
            }else{
            }
                std::cout << "Escriba nickname de la inmobiliaria que desee seleccionar: ";
                std::cin >> nicknameInmobiliaria;
                std::cin.ignore();
                controlador->eliminarSuscripcion(nicknameInmobiliaria);
                std::cout << "Desea eliminar otra suscripcion?: 1: Si / 2: No: ";
                std::cin >> eliminarSuscripcion;
                std::cin.ignore();
                coleccionInmobiliarias = controlador->listarSuscripciones(nickname);
                for (std::set<DTInmobiliaria *>::iterator it = coleccionInmobiliarias.begin(); it != coleccionInmobiliarias.end(); it++)
                {
                    // Liberamos la memoria
                    delete (*it);
                }
        }
    }   
    coleccionInmobiliarias.clear();
}

void altaAdministracionPropiedad(){
    Factory* factory = Factory::getInstance();

    // Solicito un controlador de PublicacionInmueble
    IPublicacionInmuebleController *controlador = factory->getPublicacionInmuebleController();
    
    std::cout << "Lista de Inmobiliarias:\n";
    std::set<DTUsuario*> listaInmobiliarias = controlador->listarInmobiliarias();
    for(std::set<DTUsuario *>::iterator it = listaInmobiliarias.begin(); it != listaInmobiliarias.end(); it++)
    {
        std::cout << "- Nickname: " << (*it)->getNickname() << ", Nombre: " << (*it)->getNombre() << std::endl;
    }
    std::cout << "Ingrese el nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);

    // Liberamos la memoria
    for (std::set<DTUsuario *>::iterator it = listaInmobiliarias.begin(); it != listaInmobiliarias.end(); it++)
    {
        delete *it;
    }
    listaInmobiliarias.clear();

    std::set<DTInmuebleListado*> InmueblesNoAdministrados = controlador->listarInmueblesNoAdministradosInmobiliaria(nicknameInmobiliaria);
    for(std::set<DTInmuebleListado *>::iterator it = InmueblesNoAdministrados.begin(); it != InmueblesNoAdministrados.end(); it++)
    {
        std::cout << "- Codigo: " << (*it)->getCodigo() << ", direccion: " << (*it)->getDireccion() << ", propietario: " << (*it)->getPropietario() << std::endl;
    }
    std::cout << "Ingresar el codigo del inmueble a administrar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    //Se da de alta la administracion de la propiedad para la inmobiliaria y el inmueble ingresados
    controlador->altaAdministraPropiedad(nicknameInmobiliaria, codigoInmueble); 
    std::cout << "Administracion de propiedad creada exitosamente." << std::endl;

    // Liberamos la memoria
    for (std::set<DTInmuebleListado *>::iterator it = InmueblesNoAdministrados.begin(); it != InmueblesNoAdministrados.end(); it++)
    {
        delete *it;
    }
    InmueblesNoAdministrados.clear();
}   

void cargarDatos(){
    CargaDatos* cD = CargaDatos::getInstance();
    cD->destruirInstance();
}

 void verFechaActual(){
    Factory* factory = Factory::getInstance();
    IControladorFechaActual* cfecha = factory->getControladorFechaActual();
    DTFecha* fechaActual = cfecha->getFechaActual();
    std::cout << "fecha actual: " << fechaActual;
    delete fechaActual;
 }

 void asignarFechaActual(){
    Factory* factory = Factory::getInstance();
    IControladorFechaActual* cfecha = factory->getControladorFechaActual();
    std::cout << "dia: ";
    int dia;
    std::cin >> dia;
    std::cin.ignore();
    std::cout << "mes: ";
    int mes;
    std::cin >> mes;
    std::cin.ignore();
    std::cout << "ano: ";
    int ano;
    std::cin >> ano;
    std::cin.ignore();
    cfecha->setNewFechaActual(dia, mes, ano);
 }