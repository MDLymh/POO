#include <stdio.h>
#include <stdlib.h>
/*
    NickName SeisDos
    Practica 2
    TiempoTraduccion=0:15
*/

//a) Declaración y definición de constantes
#define IVA 16
#define RETENCION_ISR_INGRESOS 10
#define RETENCION_ISR_GANANCIA_BRUTA 11
#define RETENCION_IVA 10
#define C_0 0
#define C_1 1
#define C_100 100

int main(){
    //b) Declaración de variables
    float ingreso,gasto, ivaIngreso, subtotalIngresos,retencionIsrIngresos,
          retencionivaIngreso,gananciaBruta,gananciaNeta,isrPendiente,
          ivaPendiente, totalIngresos,retencionIsrGananciaBruta,gastosIva;
    FILE* archivoImpuestos;
    printf("CÁLCULO DE IMPUESTOS ANUAL\n");
    //c) Entrada de datos
    printf("\nCaptura de ingresos\n");
    printf("Dame el ingreso: ");
    scanf("%f",&ingreso);
    getchar();
    printf("\nCaptura de gasto\n");
    printf("Dame el gasto: ");
    scanf("%f",&gasto);
    getchar();
    //d) Cálculo de impuestos
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
    printf("\n***Tabla de registro de Honorarios***\n\n"
        "Ingresos             %10.2f\n"
        "(+) IVA              %10.2f\n"
        "(=) Subtotal         %10.2f\n"
        "(-) Retencion ISR    %10.2f\n"
        "(-) Retencion IVA    %10.2f\n"
        "(=) Total            %10.2f\n",ingreso,ivaIngreso, subtotalIngresos, retencionIsrIngresos,
                                        retencionivaIngreso, totalIngresos);
    printf("***Tabla de ganancias***\n\n"
           "Ingreso              %10.2f\n"
           "(-) Gasto            %10.2f\n"
           "(=) Ganancia Bruta   %10.2f\n"
           "(-) ISR              %10.2f\n"
           "(=) Ganancia Neta    %10.2f\n", ingreso, gasto, gananciaBruta, retencionIsrGananciaBruta,
                                        gananciaNeta);
    printf("***Tabla ISR***\n"
        "ISR                  %10.2f\n"
       "(-) ISR Retenido      %10.2f\n"
       "(=) ISR a pagar       %10.2f\n", retencionIsrGananciaBruta,retencionIsrIngresos, isrPendiente);
    printf("***Tabla IVA***\n"
        "IVA                  %10.2f\n"
        "(-) Gastos IVA       %10.2f\n"
        "(-) Retencion IVA    %10.2f\n"
        "(=) IVA a pagar      %10.2f\n",ivaIngreso, gastosIva, retencionivaIngreso,ivaPendiente);
    archivoImpuestos = fopen("Calculo de impuestos.txt", "wt");
    fprintf(archivoImpuestos ,"\n***Tabla de registro de Honorarios***\n\n"
            "Ingresos             %10.2f\n"
            "(+) IVA              %10.2f\n"
            "(=) Subtotal         %10.2f\n"
            "(-) Retencion ISR    %10.2f\n"
            "(-) Retencion IVA    %10.2f\n"
            "(=) Total            %10.2f\n",ingreso,ivaIngreso, subtotalIngresos, retencionIsrIngresos,
                                        retencionivaIngreso, totalIngresos);
    fprintf(archivoImpuestos ,"***Tabla de ganancias***\n\n"
           "Ingreso              %10.2f\n"
           "(-) Gasto            %10.2f\n"
           "(=) Ganancia Bruta   %10.2f\n"
           "(-) ISR              %10.2f\n"
           "(=) Ganancia Neta    %10.2f\n", ingreso, gasto, gananciaBruta, retencionIsrGananciaBruta,
                                        gananciaNeta);
    fprintf(archivoImpuestos ,"***Tabla ISR***\n"
        "ISR                  %10.2f\n"
       "(-) ISR Retenido      %10.2f\n"
       "(=) ISR a pagar       %10.2f\n", retencionIsrGananciaBruta,retencionIsrIngresos, isrPendiente);
    fprintf(archivoImpuestos ,"***Tabla IVA***\n"
        "IVA                  %10.2f\n"
        "(-) Gastos IVA       %10.2f\n"
        "(-) Retencion IVA    %10.2f\n"
        "(=) IVA a pagar      %10.2f\n",ivaIngreso, gastosIva, retencionivaIngreso,ivaPendiente);
        fclose(archivoImpuestos);
    printf("Presione entrar para terminar . . .");
    getchar();
        return 0;
}


