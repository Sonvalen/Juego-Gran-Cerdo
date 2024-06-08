#ifndef HITOS_Y_CONDICIONES_H_INCLUDED
#define HITOS_Y_CONDICIONES_H_INCLUDED
#include "rlutil.h"
///ACA VAN LOS HITOS Y CONDICIONES PARA EL TERCER DADO, EL BARRO O LOS DOBLES PUNTOS Y LA REVISAR SI ENTRA EN LAS ESTADISTICAS

int Eveluar_Campeon_Actual(string Actual_Campeon,int Puntos_Act_Campeon[],string NombreP1,string NombreP2,int PUNTOS_DE_VICTORIA[]){
    int nuevo_campeon;
    int Campeon=0;
    if(PUNTOS_DE_VICTORIA[0]>PUNTOS_DE_VICTORIA[1]){
    if(PUNTOS_DE_VICTORIA[0]>Puntos_Act_Campeon[0]){
        Campeon = 1;
        nuevo_campeon=PUNTOS_DE_VICTORIA[0];
        Puntos_Act_Campeon[0]=nuevo_campeon;
        return Campeon;}}else{
    if(PUNTOS_DE_VICTORIA[1]>Puntos_Act_Campeon[0]){
        Campeon = 2;
        nuevo_campeon=PUNTOS_DE_VICTORIA[1];
        Puntos_Act_Campeon[0]=nuevo_campeon;
        return Campeon;}}
        return Campeon;
    }
///BARRO
int Barros(int valorDeDadoJugador1[],int valorDeDadoJugador2[],int cantidadDeDados,int Barro[],int sumaDeDados,int Trufas_Totales_de_Jugador[],int Dirccion_de_trufas){
    int Cuenta_Unos=0,puntos=sumaDeDados;
    if(Dirccion_de_trufas==1){
    for (int i = 0; i < cantidadDeDados; ++i){
    if(valorDeDadoJugador1[i]==1){Cuenta_Unos=Cuenta_Unos+1;}}
    if(Cuenta_Unos==cantidadDeDados){
        cout<<"---|CAISTE AL BARRO PIERDES TODAS TUS TRUFAS|---"<<endl;
        Barro[0]=1;
        Trufas_Totales_de_Jugador[0]=0;
        puntos=0;}
        }else{
    for (int i = 0; i < cantidadDeDados; ++i){
    if(valorDeDadoJugador2[i]==1){Cuenta_Unos=Cuenta_Unos+1;}}
    if(Cuenta_Unos==cantidadDeDados){
        cout<<"---|CAISTE AL BARRO PIERDES TODAS TUS TRUFAS|---"<<endl;
        Barro[1]=1;
        Trufas_Totales_de_Jugador[1]=0;
        puntos=0;}}
    return puntos;
}
///UN AS(1)
int AS(int Trufas_acumuladas_en_ronda[],int Trufas_Totales_de_Jugador[],int Dirccion_de_trufas){
    if(Dirccion_de_trufas==1){
    cout<<"---|SACASTE AS(1) PIERDES TODAS LAS TRUFAS QUE ACUMULASTE EN EL TURNO|---"<<endl;
    Trufas_Totales_de_Jugador[0]=Trufas_Totales_de_Jugador[0]-Trufas_acumuladas_en_ronda[0];
    return 0;}
    else{cout<<"---|SACASTE AS(1) PIERDES TODAS LAS TRUFAS QUE ACUMULASTE EN EL TURNO|---"<<endl;
    Trufas_Totales_de_Jugador[1]=Trufas_Totales_de_Jugador[1]-Trufas_acumuladas_en_ronda[1];
    return 0;}
}
///DOBLES PUNTOS(OSEA OINKS)
int Oinkss(int valorDeDadoJugador1[],int valorDeDadoJugador2[],int cantidadDeDados,int sumaDeDados,int Oinks[],int Dirccion_de_trufas){
    int bandera=1,puntos=sumaDeDados;
    if(Dirccion_de_trufas==1){
         for (int i = 0; i < cantidadDeDados; ++i){
    if(valorDeDadoJugador1[i]==valorDeDadoJugador1[i+1]){
        if(valorDeDadoJugador1[i]!=1){bandera++;}}}
    if(bandera==cantidadDeDados){
    cout<<"***SACASTE OINK SE TE DUPLICAN ESTAS TRUFAS***"<<endl;
    puntos=sumaDeDados*2;
    Oinks[0]=Oinks[0]+1;
    return puntos;}
    }else{
    for (int i = 0; i < cantidadDeDados; ++i){
    if(valorDeDadoJugador2[i]==valorDeDadoJugador2[i+1]){
        if(valorDeDadoJugador2[i]!=1){bandera++;}}}
    if(bandera==cantidadDeDados){
    cout<<"***SACASTE OINK SE TE DUPLICAN ESTAS TRUFAS***"<<endl;
    puntos=sumaDeDados*2;
    Oinks[1]=Oinks[1]+1;
    return puntos;}}
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
int Asignar_Hitos(string NombreP1,string NombreP2,int Trufas_Totales_de_Jugador[],int Oinks[],int Mayor_Lanzamiento[],int PUNTOS_DE_VICTORIA[],string Actual_Campeon,int Puntos_Act_Campeon[]){
    int Cada50=0,MASOINK=0,campeon;
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
    rlutil::locate(1,7);
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "PUNTOS EXTRA POR OINK ECHO."<<endl;
    cout<<NombreP1<<" HIZO "<<Oinks[0]<<": MAS ";
    MASOINK=Oinks[0]*2;
    cout<<MASOINK<<" PV"<<endl;
    PUNTOS_DE_VICTORIA[0]=PUNTOS_DE_VICTORIA[0]+MASOINK;
    cout<<NombreP2<<" HIZO "<<Oinks[1]<<": MAS ";
    MASOINK=Oinks[1]*2;
    cout<<MASOINK<<" PV"<<endl;
    PUNTOS_DE_VICTORIA[1]=PUNTOS_DE_VICTORIA[1]+MASOINK;
    rlutil::locate(40,8);
    cout<<"PUNTOS EXTRA PARA EL CERDO MAS CODICIOSO."<<endl;

    if(Mayor_Lanzamiento[0]>Mayor_Lanzamiento[1]){
        PUNTOS_DE_VICTORIA[0]=PUNTOS_DE_VICTORIA[0]+2;
        rlutil::locate(40,9);
        cout<<NombreP1<<": "<<Mayor_Lanzamiento[0]<<endl;
        rlutil::locate(40,10);
        cout<<NombreP2<<": "<<Mayor_Lanzamiento[1]<<endl;
        rlutil::locate(40,11);
        cout<<"MAS 2 PV PARA "<<NombreP1<<endl;
        cout<<endl;
        }
    if(Mayor_Lanzamiento[0]<Mayor_Lanzamiento[1]){
        PUNTOS_DE_VICTORIA[1]=PUNTOS_DE_VICTORIA[1]+2;
        rlutil::locate(40,9);
        cout<<NombreP1<<": "<<Mayor_Lanzamiento[0]<<endl;
        rlutil::locate(40,10);
        cout<<NombreP2<<": "<<Mayor_Lanzamiento[1]<<endl;
        rlutil::locate(40,11);
        cout<<"MAS 2 PV PARA "<<NombreP2<<endl;
        cout<<endl;
        }
    if(Mayor_Lanzamiento[0]==Mayor_Lanzamiento[1]){
    PUNTOS_DE_VICTORIA[1]=PUNTOS_DE_VICTORIA[1]+2;
    PUNTOS_DE_VICTORIA[0]=PUNTOS_DE_VICTORIA[0]+2;
        rlutil::locate(40,9);
        cout<<NombreP1<<": "<<Mayor_Lanzamiento[0]<<endl;
        rlutil::locate(40,10);
        cout<<NombreP2<<": "<<Mayor_Lanzamiento[1]<<endl;
        rlutil::locate(40,11);
        cout<<"MAS 2 PV PARA AMBOS"<<endl;
        cout<<endl;
    }

    cout <<"---------------------------------------------------------------------------------------------------------------------" << endl;
    cout<<"PV TOTALES DE "<<NombreP1<<": "<<PUNTOS_DE_VICTORIA[0]<<endl;
    cout<<"PV TOTALES DE "<<NombreP2<<": "<<PUNTOS_DE_VICTORIA[1]<<endl;
    system("pause");
    system("cls");
cout<<"*******************************************************"<<endl;
cout<<endl;
    if(PUNTOS_DE_VICTORIA[0]>PUNTOS_DE_VICTORIA[1]){
        cout<<"**********************FELICIDADES**********************"<<endl;
        cout<<"      EL GRAN CERDO ES EL JUGADOR "<<NombreP1<<endl;
cout<<endl;
cout<<"*******************************************************"<<endl;
    campeon=Eveluar_Campeon_Actual(Actual_Campeon,Puntos_Act_Campeon,NombreP1,NombreP2,PUNTOS_DE_VICTORIA);
    system("pause");
    return campeon;}
    if(PUNTOS_DE_VICTORIA[0]<PUNTOS_DE_VICTORIA[1]){
        cout<<"**********************FELICIDADES**********************"<<endl;
      cout<<"        EL GRAN CERDO ES EL JUGADOR "<<NombreP2<<endl;
cout<<endl;
cout<<"*******************************************************"<<endl;
    campeon=Eveluar_Campeon_Actual(Actual_Campeon,Puntos_Act_Campeon,NombreP1,NombreP2,PUNTOS_DE_VICTORIA);
    system("pause");
    return campeon;
    }else{cout<<"**AMBOS CERDOS TIENEN LA MISMA PUNTUACION ES UN EMPATE**"<<endl;
cout<<endl;
cout<<"*******************************************************"<<endl;
system("pause");
return 0;
}}


#endif // HITOS_Y_CONDICIONES_H_INCLUDED
