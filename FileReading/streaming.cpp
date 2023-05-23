#include <iostream>
#include <fstream>
#include <vector>
#include "Video.h"

using namespace std;

int main()
{
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile("movieDB.txt");

    // Create our video container...
    vector<Video> videosDB;
    
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText))
    {
        
        // myText = "1,Lord of the rings,200"
        int elId = std::stoi(myText.substr(0, myText.find(",")));

        // myText = "Lord of the rings,200"
        myText = myText.substr(myText.find(",")+1, myText.length());
        std::string elNombre = myText.substr(0, myText.find(","));

        // myText = "200"
        float laDuracion = std::stof(myText.substr(myText.find(",")+1, myText.length()));

        /*
        std::cout << "El id: " << elId << std::endl;
        std::cout << "El nombre: " << elNombre << std::endl;
        std::cout << "La duración: " << laDuracion << std::endl;
        std::cout << "*****************************"  << std::endl;
        */

       //Crear un objeto de tipo Video con los datos
       //obtenidos del txt y meterlo en el vector videosDB
       
       Video video_temp(elId, elNombre, laDuracion);
       videosDB.push_back(video_temp);
    }

    // Close the file
    MyReadFile.close();

    //Imprimir todos los videos dentro del vector videosDB:
    for(Video vid : videosDB){
        vid.toStr();
    };

}