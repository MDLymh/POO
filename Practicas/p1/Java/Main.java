/*
    NickName SeisDos
    Practica 2
    Tiempo=0:25
*/
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
public class Main{
    public static void main(String[] args) throws IOException{
        final int IVA =16;
        final int RETENCION_ISR_INGRESOS = 10;
        final int RETENCION_ISR_GANANCIA_BRUTA = 11;
        final int RETENCION_IVA = 10;
        final int C_100 = 100;
        float ingreso,gasto, ivaIngreso, subtotalIngresos,retencionIsrIngresos,
              retencionivaIngreso,gananciaBruta,gananciaNeta,isrPendiente,
              ivaPendiente, totalIngresos,retencionIsrGananciaBruta,gastosIva;
        FileWriter archivoCalculoImpuestos = null;
        PrintWriter escritorArchivo =null;
        Scanner entrada = new Scanner(System.in);
        System.out.printf("CÁLCULO DE IMPUESTOS ANUAL%n%n");
        System.out.printf("Captura de ingresos%n");
        System.out.printf("Dame el ingreso: ");
        ingreso = entrada.nextFloat();
        entrada.nextLine();
        System.out.printf("%nCaptura de ingresos%n");
        System.out.printf("Dame el gasto: ");
        gasto = entrada.nextFloat();
        entrada.nextLine();
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
        System.out.printf("%n***Tabla de registro de Honorarios***%n%n"+
                          "Ingresos             %10.2f%n"+
                          "(+) IVA              %10.2f%n"+
                          "(=) Subtotal         %10.2f%n"+
                          "(-) Retencion ISR    %10.2f%n"+
                          "(-) Retencion IVA    %10.2f%n"+
                          "(=) Total            %10.2f%n",ingreso,ivaIngreso, subtotalIngresos, retencionIsrIngresos,
                                        retencionivaIngreso, totalIngresos);
        System.out.printf("***Tabla de ganancias***%n%n"+
                          "Ingreso              %10.2f%n"+
                          "(-) Gasto            %10.2f%n"+
                          "(=) Ganancia Bruta   %10.2f%n"+
                          "(-) ISR              %10.2f%n"+
                         "(=) Ganancia Neta    %10.2f%n", ingreso, gasto, gananciaBruta, retencionIsrGananciaBruta,
                                                gananciaNeta);
        System.out.printf("***Tabla ISR***%n"+
                          "ISR                   %10.2f%n"+
                          "(-) ISR Retenido      %10.2f%n"+
                          "(=) ISR a pagar       %10.2f%n", retencionIsrGananciaBruta,retencionIsrIngresos, isrPendiente);
        System.out.printf("***Tabla IVA***%n"+
                          "IVA                  %10.2f%n"+
                          "(-) Gastos IVA       %10.2f%n"+
                          "(-) Retencion IVA    %10.2f%n"+
                          "(=) IVA a pagar      %10.2f%n",ivaIngreso, gastosIva, retencionivaIngreso,ivaPendiente);
        try{
            archivoCalculoImpuestos = new FileWriter(".\\Calculo de Impuestos.txt");
            escritorArchivo= new PrintWriter(archivoCalculoImpuestos);
            escritorArchivo.printf("%n***Tabla de registro de Honorarios***%n%n"+
                                    "Ingresos             %10.2f%n"+
                                    "(+) IVA              %10.2f%n"+
                                    "(=) Subtotal         %10.2f%n"+
                                    "(-) Retencion ISR    %10.2f%n"+
                                    "(-) Retencion IVA    %10.2f%n"+
                                    "(=) Total            %10.2f%n",ingreso,ivaIngreso, subtotalIngresos, retencionIsrIngresos,
                                                                     retencionivaIngreso, totalIngresos);
            escritorArchivo.printf("***Tabla de ganancias***%n%n"+
                                    "Ingreso              %10.2f%n"+
                                    "(-) Gasto            %10.2f%n"+
                                    "(=) Ganancia Bruta   %10.2f%n"+
                                    "(-) ISR              %10.2f%n"+
                                    "(=) Ganancia Neta    %10.2f%n", ingreso, gasto, gananciaBruta, retencionIsrGananciaBruta,
                                             gananciaNeta);
            escritorArchivo.printf("***Tabla ISR***%n"+
                                    "ISR                   %10.2f%n"+
                                    "(-) ISR Retenido      %10.2f%n"+
                                    "(=) ISR a pagar       %10.2f%n", retencionIsrGananciaBruta,retencionIsrIngresos, isrPendiente);
            escritorArchivo.printf("***Tabla IVA***%n"+
                                    "IVA                  %10.2f%n"+
                                    "(-) Gastos IVA       %10.2f%n"+
                                    "(-) Retencion IVA    %10.2f%n"+
                                    "(=) IVA a pagar      %10.2f%n",ivaIngreso, gastosIva, retencionivaIngreso,ivaPendiente);

        }catch(Exception error){
            System.out.println("Error al guardar archivo: "+ error.getMessage());
        }finally{
            archivoCalculoImpuestos.close();
        }
        System.out.print("Presione entrar para terminar . . .");entrada.nextLine();
        entrada.close();
        return;
    }
}