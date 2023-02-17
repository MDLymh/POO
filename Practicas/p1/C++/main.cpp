#include <iostream>
#include <iomanip>
#include <fstream>
/*
    NickName NueveCero
    Practica 2
    Tiempo=0:45
*/
//a) Declaraci�n y definici�n de constantes
#define IVA 16
#define RETENCION_ISR_INGRESOS 10
#define RETENCION_ISR_GANANCIA_BRUTA 11
#define RETENCION_IVA 10
#define C_0 0
#define C_1 1
#define C_100 100

using namespace std;
int main(){
    //b) Declaraci�n de variables
    float ingreso,gasto, ivaIngreso, subtotalIngresos,retencionIsrIngresos,
          retencionivaIngreso,gananciaBruta,gananciaNeta,isrPendiente,
          ivaPendiente, totalIngresos,retencionIsrGananciaBruta,gastosIva;
    ofstream archivoImpuestos;
    cout<<"C�LCULO DE IMPUESTOS ANUAL"<<endl;
    //c) Entrada de datos
    cout<<endl<<"Captura de ingresos"<<endl;
    cout<<"Dame el ingreso: ";
    cin>>ingreso;
    cin.ignore();
    cout<<endl<<"Captura de gasto"<<endl;
    cout<<"Dame el gasto: ";
    cin>>gasto;
    cin.ignore();
    //d) C�lculo de impuestos
    ivaIngreso=ingreso*((float)IVA/C_100);
    subtotalIngresos= ivaIngreso +ingreso;
    retencionIsrIngresos= ingreso*((float)RETENCION_ISR_INGRESOS/C_100);
    retencionivaIngreso = ingreso*((float)RETENCION_IVA/C_100);
    totalIngresos = subtotalIngresos -retencionIsrIngresos-retencionivaIngreso;
    gananciaBruta = ingreso-gasto;
    retencionIsrGananciaBruta= gananciaBruta*((float)RETENCION_ISR_GANANCIA_BRUTA/C_100);
    gananciaNeta =gananciaBruta-retencionIsrGananciaBruta;
    isrPendiente = retencionIsrGananciaBruta - retencionIsrIngresos;
    gastosIva = gasto*((float)IVA/C_100);
    ivaPendiente = ivaIngreso-gastosIva-retencionivaIngreso;
    //e) Salida de datos
    cout<<endl<<"***Tabla de registro de Honorarios***"<< endl<<endl
        <<"Ingresos             " << setw(10)<<fixed<< setprecision(2) << ingreso <<endl
        <<"(+) IVA              " << setw(10)<<fixed<< setprecision(2) << ivaIngreso<<endl
        <<"(=) Subtotal         " << setw(10)<<fixed<< setprecision(2) << subtotalIngresos<<endl
        <<"(-) Retencion ISR    " << setw(10)<<fixed<< setprecision(2)<<retencionIsrIngresos<<endl
        <<"(-) Retencion IVA    " << setw(10)<<fixed<< setprecision(2)<<retencionivaIngreso<<endl
        <<"(=) Total            " << setw(10)<<fixed<< setprecision(2)<<totalIngresos<<endl;
    cout<<endl<<"***Tabla de ganancias***"<<endl<<endl
        <<"Ingreso              " <<setw(10)<< fixed << setprecision(2) << ingreso <<endl
        <<"(-) Gasto            " << setw(10)<<fixed<< setprecision(2)<< gasto <<endl
        <<"(=) Ganancia Bruta   " << setw(10)<<fixed<< setprecision(2)<< gananciaBruta <<endl
        <<"(-) ISR              " << setw(10)<<fixed<< setprecision(2)<<retencionIsrGananciaBruta<<endl
        <<"(=) Ganancia Neta    " << setw(10)<<fixed<< setprecision(2)<<gananciaNeta<<endl;
    cout<<endl<<"***Tabla ISR***" <<endl
        <<"ISR                  " <<setw(10)<< fixed << setprecision(2)<<retencionIsrGananciaBruta
        <<endl<<"(-) ISR Retenido     "<< setw(10)<<fixed<< setprecision(2)<<retencionIsrIngresos
        <<endl<<"(=) ISR a pagar      " << setw(10)<<fixed<< setprecision(2)<< isrPendiente<<endl;
    cout<<endl<<"***Tabla IVA***"<<endl
        <<"IVA                  " <<setw(10)<<fixed<<setprecision(2)<<ivaIngreso<<endl
        <<"(-) Gastos IVA       " << setw(10)<<fixed<< setprecision(2)<<gastosIva<<endl
        <<"(-) Retencion IVA    " << setw(10)<<fixed<< setprecision(2)<<retencionivaIngreso<<endl
        <<"(=) IVA a pagar      " << setw(10)<<fixed<< setprecision(2)<<ivaPendiente<<endl;
    cout<<"Presione entrar para terminar . . .";
    archivoImpuestos.open("Calculo de impuestos.txt");
    archivoImpuestos<<endl<<"***Tabla de registro de Honorarios***"<< endl<<endl
        <<"Ingresos             " << setw(10)<<fixed<< setprecision(2) << ingreso <<endl
        <<"(+) IVA              " << setw(10)<<fixed<< setprecision(2) << ivaIngreso<<endl
        <<"(=) Subtotal         " << setw(10)<<fixed<< setprecision(2) << subtotalIngresos<<endl
        <<"(-) Retencion ISR    " << setw(10)<<fixed<< setprecision(2)<<retencionIsrIngresos<<endl
        <<"(-) Retencion IVA    " << setw(10)<<fixed<< setprecision(2)<<retencionivaIngreso<<endl
        <<"(=) Total            " << setw(10)<<fixed<< setprecision(2)<<totalIngresos<<endl
        <<endl<<"***Tabla de ganancias***"<<endl<<endl
        <<"Ingreso              " <<setw(10)<< fixed << setprecision(2) << ingreso <<endl
        <<"(-) Gasto            " << setw(10)<<fixed<< setprecision(2)<< gasto <<endl
        <<"(=) Ganancia Bruta   " << setw(10)<<fixed<< setprecision(2)<< gananciaBruta <<endl
        <<"(-) ISR              " << setw(10)<<fixed<< setprecision(2)<<retencionIsrGananciaBruta<<endl
        <<"(=) Ganancia Neta    " << setw(10)<<fixed<< setprecision(2)<<gananciaNeta<<endl
        <<endl<<"***Tabla ISR***" <<endl
        <<"ISR                  " <<setw(10)<< fixed << setprecision(2)<<retencionIsrGananciaBruta
        <<endl<<"(-) ISR Retenido     "<< setw(10)<<fixed<< setprecision(2)<<retencionIsrIngresos
        <<endl<<"(=) ISR a pagar      " << setw(10)<<fixed<< setprecision(2)<< isrPendiente<<endl
        <<endl<<"***Tabla IVA***"<<endl
        <<"IVA                  " <<setw(10)<<fixed<<setprecision(2)<<ivaIngreso<<endl
        <<"(-) Gastos IVA       " << setw(10)<<fixed<< setprecision(2)<<gastosIva<<endl
        <<"(-) Retencion IVA    " << setw(10)<<fixed<< setprecision(2)<<retencionivaIngreso<<endl
        <<"(=) IVA a pagar      " << setw(10)<<fixed<< setprecision(2)<<ivaPendiente<<endl;
    cin.get();
        return 0;
}


