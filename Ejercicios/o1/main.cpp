#include <iostream>
#include <cstring>
#define TAMANIO_MIN_NOMBRE 3
#define PROMEDIO_MAXIMO 100

using namespace std;
using std::strlen;

class Alumno{
    string nombre;
    int codigo;
    float promedio;
public:
    void fijaNombre(string n){
        if(n.length()>=TAMANIO_MIN_NOMBRE){
            nombre=n;
        }else{
            nombre ="";
        }
    }
    void fijaCodigo(int c){
        if(c>0){
            codigo = c;
        }else{
            codigo = '\0';
        }
    }
    void fijaPromedio(float p){
        if((p>=0)&&(p<=PROMEDIO_MAXIMO)){
            promedio = p;
        }else{
            promedio = '\0';
        }
    }
    string dameNombre(){
        return nombre;
    }
    int dameCodigo(){
        return codigo;
    }
    float damePromedio(){
        return promedio;
    }
};


int main(){
    Alumno alumno;
    string nombre;
    int codigo;
    float promedio;
    cout << "Ingrese su nombre : ";
    getline(cin, nombre);
    cout << "Ingrese su codigo : ";
    cin >> codigo;
    cout << "Ingrese su promedio: ";
    cin >> promedio;
    alumno.fijaNombre(nombre);
    alumno.fijaCodigo(codigo);
    alumno.fijaPromedio(promedio);
    cout << endl << "Datos ingresados " << endl;
    cout << "Nombre   : " << alumno.dameNombre() << endl;
    cout << "Codigo   : " << alumno.dameCodigo() << endl;
    cout << "Promedio : " << alumno.damePromedio() << endl;

    return 0;
}
