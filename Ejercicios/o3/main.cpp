#include <iostream>
#include <string>
#define TAMANIO_MIN_NOMBRE 3
#define PROMEDIO_MAXIMO 100
#define C_0 0
#define NOMBRE_BASE_CARRERA "Licenciatura"
#define LONG_MIN_NOMBRE_CARRERA 4

using namespace std;

class Alumno{
    string nombre;
    int codigo, idCarrera;
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
    void fijaIdCarrera(int idCarrera){
        if(idCarrera <= C_0){
            cout << "Id  invalido" << endl;
            return;
        }
        this->idCarrera = idCarrera;
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
    int dameIdCarrera(){
        return idCarrera;
    }
};
class Carrera{
private:
    int idCarrera;
    string nombre;
public:
    Carrera(){
        idCarrera =C_0;
        nombre = NOMBRE_BASE_CARRERA;
    }
    void fijaIdCarrera(int idCarrera){
        if(idCarrera <= C_0){
            cout << "Id  invalido" << endl;
            return;
        }
        this->idCarrera = idCarrera;
    }
    void fijaNombre(string nombre){
        if(nombre.empty()){
            cout << "No se recibio informacion del nombre de la carrera." <<endl;
        }else if(nombre.length() < LONG_MIN_NOMBRE_CARRERA){
            cout << "El nombre de la carrera es muy corto" << endl;
        }else{
            this->nombre = nombre;
        }
    }
    string dameNombre(){
        return nombre;
    }
    int dameIdCarrera(){
        return idCarrera;
    }
};


int main(){
    Alumno alumno;
    Carrera carrera;
    string nombreAlumno, nombreCarrera;
    int codigo,idCarrera;
    float promedio;
    cout << "Ingrese el nombre de la carrera: ";
    getline(cin, nombreCarrera);
    cout << "Ingrese el id de la carrera: ";
    cin >> idCarrera;
    cin.ignore();
    cout << "Ingrese su nombre : ";
    getline(cin, nombreAlumno);
    cout << "Ingrese su codigo : ";
    cin >> codigo;
    cin.ignore();
    cout << "Ingrese su promedio: ";
    cin >> promedio;
    cin.ignore();
    carrera.fijaNombre(nombreCarrera);
    carrera.fijaIdCarrera(idCarrera);
    alumno.fijaNombre(nombreAlumno);
    alumno.fijaCodigo(codigo);
    alumno.fijaPromedio(promedio);
    alumno.fijaIdCarrera(carrera.dameIdCarrera());
    cout << endl << "Datos ingresados " << endl;
    cout << endl <<"Carrera:"<< endl;
    cout <<"Nombre      : "<< carrera.dameNombre()<<endl;
    cout <<"ID          : "<< carrera.dameIdCarrera()<< endl; 
    cout << endl <<"Aumno:"<< endl;
    cout << "Nombre     : " << alumno.dameNombre() << endl;
    cout << "Codigo     : " << alumno.dameCodigo() << endl;
    cout << "Promedio   : " << alumno.damePromedio() << endl;
    cout << "ID Carrera : " << alumno.dameIdCarrera() << endl;

    return 0;
}
