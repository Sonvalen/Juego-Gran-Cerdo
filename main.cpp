#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<windows.h>
#include<clocale>

using namespace std;
#include "Funciones_Generales.h"
#include "Creditos_y_Estadisticas.h"
#include "Hitos_y_Condiciones.h"
#include "Ronda.h"
#include "Orden_de_juego.h"
#include "Jugar.h"
#include "Salir.h"
#include "rlutil.h"


int main(){
    rlutil ::setBackgroundColor (rlutil::MAGENTA);
    rlutil ::setColor(rlutil::WHITE);
	setlocale(LC_ALL,"spanish");
	srand(time(NULL));
    int opc;
    char Actual_Campeon[20]={'-','-','-','-','-'};
    int Puntos_Act_Campeon[1]={0};
    while(true){
        system("cls");
        rlutil::locate(15,1); cout<<"    GRAN CERDO     "<<endl;
        rlutil::locate(15,2); cout<<"-----------------------"<<endl;
        rlutil::locate(15,3); cout<<"1. JUGAR"<<endl;
        rlutil::locate(15,4); cout<<"2. ESTADISTICAS"<<endl;
        rlutil::locate(15,5); cout<<"3. CERDITOS"<<endl;
        rlutil::locate(15,6); cout<<"-----------------------"<<endl;
        rlutil::locate(15,7); cout<<"0. SALIR"<<endl;
        cout<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: jugar(Actual_Campeon,Puntos_Act_Campeon);
                    break;
            case 2: Estadisticas(Actual_Campeon,Puntos_Act_Campeon);
                    break;
            case 3: Creditos();
                    break;
            case 0: if(Salir(opc)==0){cout << "NOS VEMOS ;)" << endl; return 0;}
                    break;
            default: rlutil::setColor(rlutil::LIGHTRED);
                    cout<<"OPCION INCORRECTA "<<endl;
                    rlutil::msleep(700);
                    rlutil::setColor(rlutil::WHITE);
                    break;
        }
	cout<<endl;
    }
}
