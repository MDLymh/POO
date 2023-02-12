#include <iostream>
#include <string>
#include <iomanip>
#define LONGITUD_MIN_ESPECIE_ARBOL 3
#define VALOR_BASE_ESPECIE_ARBOL "Olmo"
#define ALTURA_MAX_ARBOL 116
#define EDAD_MAXIMA_ARBOL 3500
#define LONGITUD_MIN_TITULO_LIBRO 4
#define TITULO_BASE_LIBRO "Sin titulo"
#define C_0 0
#define C_1 1
using namespace std;
class Arbol{
private:
    string especie;
    short int edad;
    float altura;
public:
    Arbol();
    void fijaEspecie(string);
    void fijaEdad(short int);
    void fijaAltura(float);
    string dameEspecie();
    short int dameEdad();
    float dameAltura();
    
};
Arbol::Arbol(){
    especie = VALOR_BASE_ESPECIE_ARBOL;
    edad = C_0;
    altura = (float)C_0;
}
void Arbol::fijaEspecie(string especie){
    if(especie.empty()){
        cout << "No se recibio informacion de la especie, Valor por defecto \"" << this->especie << "\"."<< endl;
        return;
    }else if(especie.length()<LONGITUD_MIN_ESPECIE_ARBOL){
        cout << "Especie invalida, Valor por defecto \"" << this->especie << "\"." << endl;
        return;
    }
    this->especie = especie;
}
void Arbol::fijaEdad(short int edad){
    if((edad>C_0) && (edad < EDAD_MAXIMA_ARBOL)){
        this->edad = edad;
    }else{
        cout <<"Se ingreso una edad invalida"<< endl;
    }
}
void Arbol::fijaAltura(float altura){
    if((altura>C_0)&&(altura<ALTURA_MAX_ARBOL)){
        this->altura = altura;
    }else{
        cout <<"Se ingreso una altura invalida"<< endl;
    }
}
string Arbol::dameEspecie(){
    return especie;
}
short int Arbol::dameEdad(){
    return edad;
}
float Arbol::dameAltura(){
    return altura;
}
class Libro{
private:
    string titulo;
    int numPaginas;
    float precio;
public:
    Libro();
    void fijaTitulo(string);
    void fijaNumPaginas(int);
    void fijaPrecio(float);
    string dameTitulo();
    int dameNumPaginas();
    float damePrecio();
};
Libro::Libro(){
    titulo = TITULO_BASE_LIBRO;
    numPaginas =C_1;
    precio = C_0;
}
void Libro::fijaTitulo(string titulo){
    if(titulo.empty()){
        cout << "No se recibio informacion del titulo, Valor por defecto \"" << this->titulo << "\"."<< endl;
        return;
    }else if(titulo.length()< LONGITUD_MIN_TITULO_LIBRO){
        cout << "Titulo invalido, Valor por defecto \"" << this->titulo<< "\"." << endl;
        return;
    }
    this->titulo = titulo;
}
void Libro::fijaNumPaginas(int numPaginas){
    if(numPaginas<C_1){
        cout <<"Numero de paginas Invalido"<< endl;
        return;
    }
    this->numPaginas=numPaginas;
}
void Libro::fijaPrecio(float precio){
    if(precio<0){
        cout <<"Precio Invalido"<< endl;
        return;
    }
    this->precio = precio;
}
string Libro::dameTitulo(){
    return titulo;
}
int Libro::dameNumPaginas(){
    return numPaginas;
}
float Libro::damePrecio(){
    return precio;
}
void defineArbol(string especie, int edad, float altura);
int main(){
    Libro libro;
    string especieArbol, tituloLibro;
    short int edadArbol;
    float alturaArbol, precioLibro;
    int paginasLibro;
    cout <<endl << "Ingrese la especie del arbol: ";
    getline(cin,especieArbol);
    cout << "Ingrese la edad del arbol: ";
    cin >> edadArbol;
    cin.ignore();
    cout << "Ingrese la altura del arbol: ";
    cin >> alturaArbol;
    cin.ignore();
    cout << endl << "Ingrese el titulo del libro: ";
    getline(cin,tituloLibro);
    libro.fijaTitulo(tituloLibro);
    cout << "Ingrese el numero de paginas del libro: ";
    cin >> paginasLibro;
    cin.ignore();
    libro.fijaNumPaginas(paginasLibro);
    cout << "Ingrese el precio del libro: ";
    cin >> precioLibro;
    cin.ignore();
    libro.fijaPrecio(precioLibro);
    defineArbol(especieArbol,edadArbol,alturaArbol);
    cout << "Estos son los datos del Libro: "<<endl<<endl;
    cout <<"Titulo:  "<< libro.dameTitulo()<< endl;
    cout <<"Paginas: "<< setprecision(5) << libro.dameNumPaginas()<< endl;
    cout <<"Precio:  $"<< setprecision(5) << libro.damePrecio()<<endl<<endl;
    return 0;
}
void defineArbol(string especie, int edad, float altura){
    Arbol arbol;
    arbol.fijaEspecie(especie);
    arbol.fijaEdad(edad);
    arbol.fijaAltura(altura);
    cout << "Estos son los datos del Arbol: "<<endl<<endl;
    cout <<"Especie: "<< arbol.dameEspecie()<< endl;
    cout <<"Edad:    "<< setprecision(5) << arbol.dameEdad()<< " años."<< endl;
    cout <<"Altura:  "<< setprecision(5) << arbol.dameAltura()<< " mtrs."<<endl<<endl;

}