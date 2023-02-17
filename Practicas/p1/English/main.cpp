/*
    NickName SeisDos
    Practica 2
    Time=0:45
*/
#include <iostream>
#include <iomanip>
#include <fstream>
//a) Declaration and definition of constants
#define IVA 16
#define RETENCION_ISR_earningS 10
#define RETENCION_ISR_GANANCIA_BRUTA 11
#define RETENCION_IVA 10
#define C_0 0
#define C_1 1
#define C_100 100

using namespace std;
int main(){
    //b) Variable declaration
    float earning,expense, ivaIEarning, subtotalEarning,isrEarningsWithholding,
          Withholding,grossProfit,netProfit,pendingIsr,
          pendingIva, totalEarnings,IsrGrossProfitWithholding,ivaExpenses;
    ofstream taxFile;
    cout<<"TAX CALCULATOR"<<endl;
    //c) Data input
    cout<<endl<<"Earnings"<<endl;
    cout<<"Register your earnings: ";
    cin>>earning;
    cin.ignore();
    cout<<endl<<"Expenses"<<endl;
    cout<<"Register your Expenses: ";
    cin>>expense;
    cin.ignore();
    //d) C�lculo de impuestos
    ivaIEarning=earning*((float)IVA/C_100);
    subtotalEarning=  ivaIEarning+earning;
    isrEarningsWithholding= earning*((float)RETENCION_ISR_earningS/C_100);
    Withholding = earning*((float)RETENCION_IVA/C_100);
    totalEarnings = subtotalEarning -isrEarningsWithholding-Withholding;
    grossProfit = earning-expense;
    IsrGrossProfitWithholding= grossProfit*((float)RETENCION_ISR_GANANCIA_BRUTA/C_100);
    netProfit =grossProfit-IsrGrossProfitWithholding;
    pendingIsr = IsrGrossProfitWithholding - isrEarningsWithholding;
    ivaExpenses = expense*((float)IVA/C_100);
    pendingIva = ivaIEarning-ivaExpenses-Withholding;
    //e) Salida de datos
    cout<<endl<<"***Fee table***"<< endl<<endl
        <<"Earning                " << setw(10)<<fixed<< setprecision(2) << earning <<endl
        <<"(+) IVA                " << setw(10)<<fixed<< setprecision(2) << ivaIEarning<<endl
        <<"(=) Subtotal           " << setw(10)<<fixed<< setprecision(2) << subtotalEarning<<endl
        <<"(-) ISR withholding    " << setw(10)<<fixed<< setprecision(2)<<isrEarningsWithholding<<endl
        <<"(-) IVA  withholding   " << setw(10)<<fixed<< setprecision(2)<<Withholding<<endl
        <<"(=) Total              " << setw(10)<<fixed<< setprecision(2)<<totalEarnings<<endl;
    cout<<endl<<"***Earninngs Table***"<<endl<<endl
        <<"Earning              " <<setw(10)<< fixed << setprecision(2) << earning <<endl
        <<"(-) Expense          " << setw(10)<<fixed<< setprecision(2)<< expense <<endl
        <<"(=) Gross Profit     " << setw(10)<<fixed<< setprecision(2)<< grossProfit <<endl
        <<"(-) ISR              " << setw(10)<<fixed<< setprecision(2)<<IsrGrossProfitWithholding<<endl
        <<"(=) Net Profit       " << setw(10)<<fixed<< setprecision(2)<<netProfit<<endl;
    cout<<endl<<"***ISR TABLE***" <<endl
        <<"ISR                   " <<setw(10)<< fixed << setprecision(2)<<IsrGrossProfitWithholding
        <<endl<<"(-) ISR withholding   "<< setw(10)<<fixed<< setprecision(2)<<isrEarningsWithholding
        <<endl<<"(=) ISR payable       " << setw(10)<<fixed<< setprecision(2)<< pendingIsr<<endl;
    cout<<endl<<"***IVA TABLE***"<<endl
        <<"IVA                   " <<setw(10)<<fixed<<setprecision(2)<<ivaIEarning<<endl
        <<"(-) IVA expense       " << setw(10)<<fixed<< setprecision(2)<<ivaExpenses<<endl
        <<"(-) IVA withholding   " << setw(10)<<fixed<< setprecision(2)<<Withholding<<endl
        <<"(=) IVA payable       " << setw(10)<<fixed<< setprecision(2)<<pendingIva<<endl;
    cout<<"Press ENTER to finish . . .";
    taxFile.open("Tax Calculator.txt");
    taxFile<<endl<<"***Fee table***"<< endl<<endl
        <<"Earning              " << setw(10)<<fixed<< setprecision(2) << earning <<endl
        <<"(+) IVA              " << setw(10)<<fixed<< setprecision(2) << ivaIEarning<<endl
        <<"(=) Subtotal         " << setw(10)<<fixed<< setprecision(2) << subtotalEarning<<endl
        <<"(-) ISR withholding  " << setw(10)<<fixed<< setprecision(2)<<isrEarningsWithholding<<endl
        <<"(-) Retencion IVA    " << setw(10)<<fixed<< setprecision(2)<<Withholding<<endl
        <<"(=) Total            " << setw(10)<<fixed<< setprecision(2)<<totalEarnings<<endl
        <<endl<<"***Earninngs Table***"<<endl<<endl
        <<"Earning              " <<setw(10)<< fixed << setprecision(2) << earning <<endl
        <<"(-) Expense          " << setw(10)<<fixed<< setprecision(2)<< expense <<endl
        <<"(=) Gross Profit     " << setw(10)<<fixed<< setprecision(2)<< grossProfit <<endl
        <<"(-) ISR              " << setw(10)<<fixed<< setprecision(2)<<IsrGrossProfitWithholding<<endl
        <<"(=) Net Profit       " << setw(10)<<fixed<< setprecision(2)<<netProfit<<endl
        <<endl<<"***ISR TABLE***" <<endl
        <<"ISR                  "<<setw(10)<< fixed << setprecision(2)<<IsrGrossProfitWithholding
        <<endl<<"(-) ISR withholding  "<< setw(10)<<fixed<< setprecision(2)<<isrEarningsWithholding
        <<endl<<"(=) ISR payable      " << setw(10)<<fixed<< setprecision(2)<< pendingIsr<<endl
        <<endl<<"***IVA TABLE***"<<endl
        <<"IVA                  " <<setw(10)<<fixed<<setprecision(2)<<ivaIEarning<<endl
        <<"(-) IVA expense      " << setw(10)<<fixed<< setprecision(2)<<ivaExpenses<<endl
        <<"(-) IVA withholding  " << setw(10)<<fixed<< setprecision(2)<<Withholding<<endl
        <<"(=) IVA payable      " << setw(10)<<fixed<< setprecision(2)<<pendingIva<<endl;
    cin.get();
        return 0;
}


