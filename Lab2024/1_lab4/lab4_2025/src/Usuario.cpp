#include "../include/Usuario.h"
using namespace std;

Usuario::Usuario(string nickname, string contrasena, string nombre, string email) {
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->nombre = nombre;
    this->email = email;
}
Usuario::~Usuario() {
    // Destructor vacio, ya que no hay recursos que liberar
}
string Usuario::getNickname(){
    return nickname;
}
string Usuario::getContrasena(){
    return contrasena;
}
string Usuario::getNombre(){
    return nombre;
}
string Usuario::getEmail(){
    return email;
}

