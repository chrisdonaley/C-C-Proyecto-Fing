#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include <string>

class DTUsuario {
    private:
        std::string nickname;
        std::string nombre;

    public:
        /*Crea instancia de DTUsuario con todos los datos propoprcionados*/
        DTUsuario(std::string nickname, std::string nombre);
        
        /*Devuelve el Nickname del DTUsuario*/
        std::string getNickname();
        
        /*Devuelve el Nombre de DTUsuario*/
        std::string getNombre();

        /*Comparar directamente los campos*/
        bool operator<(DTUsuario& other);
};
#endif