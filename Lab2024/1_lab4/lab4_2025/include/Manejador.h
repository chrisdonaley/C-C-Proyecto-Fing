#ifndef MANEJADOR_H
#define MANEJADOR_H

#include <set>
#include <string>
#include "Usuario.h"
#include "Inmueble.h"
#include "Publicacion.h"
#include "Inmobiliaria.h"
#include "Casa.h"
#include "Apartamento.h"
#include "DTUsuario.h"
#include "Cliente.h"
#include "Propietario.h"
using namespace std;

class Casa;
class Apartamento;

class Manejador{
    private:
        // Colecciones de Usuarios
        set<class Propietario *> cPropietarios;
        set<class Cliente *> cClientes;
        set<class Inmobiliaria *> cInmobiliarias;

        // Colecciones de Inmuebles
        set<class Casa*> cCasa;
        set<class Apartamento*> cApartamento;

        // Valor del codigo de la ultima instancia de Inmueble añadida a la colección
        int ultimoCodigoInmueble;
        // Valor del codigo de la ultima instancia de Publicacion añadida a la colección
        int ultimoCodigoPublicacion;

        // Coleccion de Publicaciones
        set<Publicacion*> cPublicaciones;

        Manejador();
        static Manejador* instance;
        
    public:
    
        ~Manejador();
        
        static Manejador* getInstance();

        // Destruye la instancia de Manejador
        void destruirInstance();

        // Anade la instancia de Inmobiliria pasada por parametro a la coleccion de Inmobiliarias
        void addInmobiliaria(Inmobiliaria *i);

        // Devuelve la instancia de Inmobiliaria cuyo nickname coincide con nickname
        // Si la instancia con tal nickanme no pertenece al conjunto, retorna NULL
        Inmobiliaria* getInmobiliaria(string nickname);

        // Devuelve la instancia de Propietario cuyo nickname coincide con nickname
        // Si la instancia con tal nickanme no pertenece al conjunto, retorna NULL
        Propietario* getPropietario(string nickname);

        // Devuelve la instancia de CLiente cuyo nickname coincide con nickname
        // Si la instancia con tal nickanme no pertenece al conjunto, retorna NULL
        Cliente* getCliente(string nickname);

        Usuario *getUsuario(string nickname);

        // Anade la instancia de Casa pasada por parametro a la coleccion de Casas
        void addCasa(class Casa *c);

        // Anade la instancia de Apartamento pasada por parametro a la coleccion de Apartamentos
        void addApartamento(class Apartamento *a);

        // Devuelve la instancia de Inmueble cuyo codigo coincide con codigo
        Inmueble* getInmueble(int codigo);

        //Devuelve el codigo de el ultimo inmueble anadido a la coleccion de Publicaciones
        int getUltimoCodigoInmueble();

        // Le otorga a ultimoCodigoInmueble el valor codigo
        void setUltimoCodigoInmueble(int codigo);

        // Anade la instancia de Publicacion pasada por parametro a la coleccion de Publicaciones
        void addPublicacion(Publicacion *p);

        // Devuelve la instancia de Publicacion cuyo codigo coincide con codigo
        Publicacion* getPublicacion(int codigo);

        set<Publicacion*> getPublicaciones();

        //Devuelve el codigo de la ultima publicacion anadida a la coleccion de Publicaciones
        int getUltimoCodigoPublicacion();

        void setUltimoCodigoPublicacion(int codigo);
        
        // Devuelve un set con los Datatypes de inmobiliarias registrados en el sistema
        set<DTUsuario*> listarInmobiliarias();

        // Devuelve la coleccion de instancias de Inmobiliaria
        set<Inmobiliaria*> getInmobiliarias();

        // Devuelve la coleccion de instancias de Propietario
        set<Propietario*> getPropietarios();

        // Anade la instancia de Cliente pasada por parametro a la coleccion de Clientes
        void addCliente(Cliente* c);

        // Anade la instancia de Propietarios pasada por parametro a la coleccion de Propietarios
        void addPropietario(Propietario* p);
};
#endif