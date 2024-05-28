#ifndef HITOS_Y_CONDICIONES_H_INCLUDED
#define HITOS_Y_CONDICIONES_H_INCLUDED
#include "rlutil.h"
///ACA VAN LOS HITOS Y CONDICIONES PARA EL TERCER DADO, EL BARRO O LOS DOBLES PUNTOS Y LA REVISAR SI ENTRA EN LAS ESTADISTICAS

void Eveluar_Campeon_Actual(char Actual_Campeon[],int Puntos_Act_Campeon[],char NombreP1[],char NombreP2[],int PUNTOS_DE_VICTORIA[]){
    int nuevo_campeon;
    if(PUNTOS_DE_VICTORIA[0]>Puntos_Act_Campeon[0]){
        strcpy(Actual_Campeon,NombreP1);
        nuevo_campeon=PUNTOS_DE_VICTORIA[0];
        Puntos_Act_Campeon[0]=nuevo_campeon;
        return ;}
    if(PUNTOS_DE_VICTORIA[1]>Puntos_Act_Campeon[0]){
        strcpy(Actual_Campeon,NombreP2);
        nuevo_campeon=PUNTOS_DE_VICTORIA[1];
        Puntos_Act_Campeon[0]=nuevo_campeon;
        return ;}
    }
///BARRO
int Barros(int valorDeDadoJugador1[],int valorDeDadoJugador2[],int cantidadDeDados,int Barro[],int sumaDeDados,int Trufas_Totales_de_Jugador[]){
    int Cuenta_Unos1=0,Cuenta_Unos2=0,puntos=sumaDeDados;
    for (int i = 0; i < cantidadDeDados; ++i){
    if(valorDeDadoJugador1[i]==1){Cuenta_Unos1=Cuenta_Unos1+1;}}

    for (int i = 0; i < cantidadDeDados; ++i){
    if(valorDeDadoJugador2[i]==1){Cuenta_Unos2=Cuenta_Unos2+1;}}
    if(Cuenta_Unos1==cantidadDeDados){
        Barro[0]=1;
        Trufas_Totales_de_Jugador[0]=0;
        puntos=0;}
    if(Cuenta_Unos2==cantidadDeDados){
        Barro[1]=1;
        Trufas_Totales_de_Jugador[1]=0;
        puntos=0;
    }
    return puntos;
}
///DOBLES PUNTOS(OSEA OINKS)
int Oinkss(int valorDeDadoJugador1[],int valorDeDadoJugador2[],int cantidadDeDados,int sumaDeDados,int Oinks[]){
    int bandera1=1,bandera2=1,puntos=sumaDeDados;
    for (int i = 0; i < cantidadDeDados; ++i){
    if(valorDeDadoJugador1[i]==valorDeDadoJugador1[i+1]){bandera1++;}}
    for (int i = 0; i < cantidadDeDados; ++i){
    if(valorDeDadoJugador2[i]==valorDeDadoJugador2[i+1]){bandera2++;}}
    if(bandera1==cantidadDeDados){
    puntos=sumaDeDados*2;
    bandera1=1;
    Oinks[0]=Oinks[0]+1;
    return puntos;}
    if(bandera2==cantidadDeDados){
    puntos=sumaDeDados*2;
    bandera2=1;
    Oinks[1]=Oinks[1]+1;
    return puntos;}
    return sumaDeDados;
}
///TERCER DADO
int Tercer_Dado(int Trufas_Totales_de_Jugador[],int Barro[]){
    if(Trufas_Totales_de_Jugador[0]>=50 && Trufas_Totales_de_Jugador[1]>=50 || Barro[0]==1 && Barro[1]==1){
        return 3;}
    return 2;
}
///MAYOR CANTIDAD DE LANZAMIENTOS.
void Mayor_Cantidad_Lanzamientos(int Lanzamientos_x_Ronda[],int Mayor_Lanzamiento[]){
    if(Lanzamientos_x_Ronda[0]>Mayor_Lanzamiento[0]){
        Mayor_Lanzamiento[0]=Lanzamientos_x_Ronda[0];
    }
    if(Lanzamientos_x_Ronda[1]>Mayor_Lanzamiento[1]){
        Mayor_Lanzamiento[1]=Lanzamientos_x_Ronda[1];
    }
}

///PUNTOS DE LOS HITOS AL FINAL DE LA PARTIDA.
void Asignar_Hitos(char NombreP1[],char NombreP2[],int Trufas_Totales_de_Jugador[],int Oinks[],int Mayor_Lanzamiento[],int PUNTOS_DE_VICTORIA[],char Actual_Campeon[],int Puntos_Act_Campeon[]){
    int Cada50=0,MASOINK=0;
    rlutil::locate(30,1);
    cout<<"*******PUNTOS EXTRA*********"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------" << endl;
    cout<<"QUIEN TIENE MAS TRUFAS?"<<endl;

    if(Trufas_Totales_de_Jugador[0]>Trufas_Totales_de_Jugador[1]){
        PUNTOS_DE_VICTORIA[0]=PUNTOS_DE_VICTORIA[0]+5;
        cout<<NombreP1<<": "<<Trufas_Totales_de_Jugador[0]<<endl;
        cout<<NombreP2<<": "<<Trufas_Totales_de_Jugador[1]<<endl;
        cout<<"MAS 5 PV PARA "<<NombreP1<<endl;
        cout<<endl;
        }
    if(Trufas_Totales_de_Jugador[0]<Trufas_Totales_de_Jugador[1]){
        PUNTOS_DE_VICTORIA[1]=PUNTOS_DE_VICTORIA[1]+5;
        cout<<NombreP1<<": "<<Trufas_Totales_de_Jugador[0]<<endl;
        cout<<NombreP2<<": "<<Trufas_Totales_de_Jugador[1]<<endl;
        cout<<"MAS 5 PV PARA "<<NombreP2<<endl;
        cout<<endl;
        }
    if(Trufas_Totales_de_Jugador[0]==Trufas_Totales_de_Jugador[1]){
    PUNTOS_DE_VICTORIA[1]=PUNTOS_DE_VICTORIA[1]+5;
    PUNTOS_DE_VICTORIA[0]=PUNTOS_DE_VICTORIA[0]+5;
        cout<<NombreP1<<": "<<Trufas_Totales_de_Jugador[0]<<endl;
        cout<<NombreP2<<": "<<Trufas_Totales_de_Jugador[1]<<endl;
        cout<<"MAS 5 PV PARA AMBOS"<<endl;
        cout<<endl;
    }  rlutil::locate(40,3);
    cout<<"PUNTOS EXTRA POR CADA 50 TRUFAS."<<endl;
    cout<<endl;
    Cada50=Trufas_Totales_de_Jugador[0]/50;
    PUNTOS_DE_VICTORIA[0]=PUNTOS_DE_VICTORIA[0]+Cada50;
     rlutil::locate(40,4);
    cout<<NombreP1<<": MAS "<<Cada50<<" PV"<<endl;
    cout<<endl;
    Cada50=Trufas_Totales_de_Jugador[1]/50;
    PUNTOS_DE_VICTORIA[1]=PUNTOS_DE_VICTORIA[1]+Cada50;
    rlutil::locate(40,5);
    cout<<NombreP2<<": MAS "<<Cada50<<" PV"<<endl;
    rlutil::locate(1,6);
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "PUNTOS EXTRA POR OINK ECHO."<<endl;
    MASOINK=Oinks[0]*2;
    PUNTOS_DE_VICTORIA[0]=PUNTOS_DE_VICTORIA[0]+MASOINK;
    cout<<NombreP1<<" HIZO "<<Oinks[0]<<": MAS "<<MASOINK<<" PV"<<endl;
    MASOINK=Oinks[1]*2;
    PUNTOS_DE_VICTORIA[1]=PUNTOS_DE_VICTORIA[1]+MASOINK;
    cout<<NombreP2<<" HIZO "<<Oinks[1]<<": MAS "<<MASOINK<<" PV"<<endl;
    rlutil::locate(40,7);
    cout<<"PUNTOS EXTRA PARA EL CERDO MAS CODICIOSO."<<endl;

    if(Mayor_Lanzamiento[0]>Mayor_Lanzamiento[1]){
        PUNTOS_DE_VICTORIA[0]=PUNTOS_DE_VICTORIA[0]+2;
        rlutil::locate(40,8);
        cout<<NombreP1<<": "<<Mayor_Lanzamiento[0]<<endl;
        rlutil::locate(40,9);
        cout<<NombreP2<<": "<<Mayor_Lanzamiento[1]<<endl;
        rlutil::locate(40,10);
        cout<<"MAS 2 PV PARA "<<NombreP1<<endl;
        cout<<endl;
        }
    if(Mayor_Lanzamiento[0]<Mayor_Lanzamiento[1]){
        PUNTOS_DE_VICTORIA[1]=PUNTOS_DE_VICTORIA[1]+2;
        rlutil::locate(40,8);
        cout<<NombreP1<<": "<<Mayor_Lanzamiento[0]<<endl;
        rlutil::locate(40,9);
        cout<<NombreP2<<": "<<Mayor_Lanzamiento[1]<<endl;
        rlutil::locate(40,10);
        cout<<"MAS 2 PV PARA "<<NombreP2<<endl;
        cout<<endl;
        }
    if(Mayor_Lanzamiento[0]==Mayor_Lanzamiento[1]){
    PUNTOS_DE_VICTORIA[1]=PUNTOS_DE_VICTORIA[1]+2;
    PUNTOS_DE_VICTORIA[0]=PUNTOS_DE_VICTORIA[0]+2;
        rlutil::locate(40,8);
        cout<<NombreP1<<": "<<Mayor_Lanzamiento[0]<<endl;
        rlutil::locate(40,9);
        cout<<NombreP2<<": "<<Mayor_Lanzamiento[1]<<endl;
        rlutil::locate(40,10);
        cout<<"MAS 2 PV PARA AMBOS"<<endl;
        cout<<endl;
    }

    cout <<"---------------------------------------------------------------------------------------------------------------------" << endl;
    system("pause");
    system("cls");
cout<<"*******************************************************"<<endl;
cout<<endl;
    if(PUNTOS_DE_VICTORIA[0]>PUNTOS_DE_VICTORIA[1]){
        cout<<"**********************FELICIDADES**********************"<<endl;
        cout<<"            EL GRAN CERDO ES EL JUGADOR "<<NombreP1<<endl;
cout<<endl;
cout<<"*******************************************************"<<endl;
    Eveluar_Campeon_Actual(Actual_Campeon,Puntos_Act_Campeon,NombreP1,NombreP2,PUNTOS_DE_VICTORIA);

        return ;}
    if(PUNTOS_DE_VICTORIA[0]<PUNTOS_DE_VICTORIA[1]){
        cout<<"**********************FELICIDADES**********************"<<endl;
      cout<<"              EL GRAN CERDO ES EL JUGADOR "<<NombreP2<<endl;
cout<<endl;
cout<<"*******************************************************"<<endl;
    Eveluar_Campeon_Actual(Actual_Campeon,Puntos_Act_Campeon,NombreP1,NombreP2,PUNTOS_DE_VICTORIA);

    }else{cout<<"**AMBOS CERDOS TIENEN LA MISMA PUNTUACION ES UN EMPATE**"<<endl;
cout<<endl;
cout<<"*******************************************************"<<endl;
}}


#endif // HITOS_Y_CONDICIONES_H_INCLUDED
