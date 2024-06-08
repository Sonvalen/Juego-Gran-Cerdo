#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<ctime>
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
    string Actual_Campeon="-----------";
    string NombreP1,NombreP2;
    int Puntos_Act_Campeon[1]={0},nuevo_campeon;
    while(true){
        system("cls");
        cout<<"    GRAN CERDO     "<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"1. JUGAR"<<endl;
        cout<<"2. ESTADISTICAS"<<endl;
        cout<<"3. CERDITOS"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"0. SALIR"<<endl;
        cout<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                cout<<" INGRESE EL NOMBRE DEL JUGADOR 1: "<<endl;
                cin>>NombreP1;
                cout<<" INGRESE EL NOMBRE DEL JUGADOR 2: "<<endl;
                cin>>NombreP2;
                system("cls");
                nuevo_campeon=jugar(Actual_Campeon,Puntos_Act_Campeon,NombreP1,NombreP2);
                if(nuevo_campeon==1){Actual_Campeon=NombreP1;}
                if(nuevo_campeon==2){Actual_Campeon=NombreP2;}
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
