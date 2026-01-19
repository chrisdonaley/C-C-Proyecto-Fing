#ifndef DTFECHA
#define DTFECHA

#include <string>


class DTFecha {
    private:
        int dia;
        int mes;
        int anio;
    public:
        /*Construye una instancia de DTFecha*/
        DTFecha(int dia, int mes, int anio);

        /*Construye una instancia de DTFecha*/
        DTFecha(DTFecha* fecha);

        ~DTFecha();

        /*Sobrecarga del operador >= para DTFecha*/
        bool operator>=(DTFecha* fecha);

        /*Sobrecarga del operador < para DTFecha*/
        bool operator<(DTFecha* fecha);

        /*Sobrecarga del operador = para DTFecha*/
        bool operator==(DTFecha* fecha);

        /*Convierte la fecha a un String*/
        std::string toString();
};
std::ostream& operator<<(std::ostream& os, DTFecha* fecha);
#endif
