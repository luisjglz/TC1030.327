#include <iostream>
class Video{
    int id;
    std::string nombre;
    float duracion;
    public:
    Video(int elId, std::string elNombre, float laDuracion){
        id = elId;
        nombre = elNombre;
        duracion = laDuracion;
    };
    void toStr(){
        std::cout << "*****************************"  << std::endl;
        std::cout << "El id: " << id << std::endl;
        std::cout << "El nombre: " << nombre << std::endl;
        std::cout << "La duración: " << duracion << std::endl;
    };
};