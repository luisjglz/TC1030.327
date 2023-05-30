#include <iostream>
using namespace std;

class Envio
{
    string nombre;
    string direccion;
    string ciudad;
    string estado;
    string cp_remitente;
    string cp_destinatario;
    double costo_estandar;

public:
    Envio()
    {
        nombre = "";
        direccion = "";
        ciudad = "";
        estado = "";
        cp_remitente = "";
        cp_destinatario = "";
        costo_estandar = 1.25;
    }

    double calculaCosto()
    {
        return costo_estandar;
    }
};

class Paquete : public Envio
{
    double largo;
    double ancho;
    double profundidad;
    double peso;
    double costo_por_kg;

public:
    Paquete(double la, double an, double pr, double pe, double co)
    {

        // validar
        if (peso < 0)
        {
            cout << "El peso no puede ser negativo, se inicalizará en 1kg por default";
            peso = 1;
        };
        if (co < 0)
        {
            cout << "El costo por Kg no puede ser negativo, se inicalizará en $1.50 por default";
            costo_por_kg = 1.5;
        };

        largo = la; ancho = an; profundidad = pr; peso = pe; costo_por_kg = co;
    };

    // polimorfismo, function overriding:
    double calculaCosto()
    {
        // Calculamos el peso por el costo por kilogramo
        double n = peso * costo_por_kg;
        // Le sumamos el costo estándar que obtenemos de la clase base:
        n = n + Envio::calculaCosto();
        return n;
    };
};

int main(){
    //Creación de un objeto de tipo 'Envio' para pruebas:
    Envio envio;

    //Paquete(double la, double an, double pr, double pe, double co)
    Paquete paq(1, 2, 3, 4, 5);

    cout << "El costo del envío estándar es: " << envio.calculaCosto() << endl;
    cout << "El costo del envío del paquete es: " << paq.calculaCosto() << endl;
}