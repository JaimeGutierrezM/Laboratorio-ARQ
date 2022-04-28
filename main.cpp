//Jaime Mateo Gutierrez Muñoz
//Laboratorio 02b: Aritmética de Punto Flotante


#include <iostream>
using namespace std;
#include <bitset>  

    
int getexponente(string bstring, int exponente1){
       for(int i=0; i<bstring.length();i++)
       {
           if (bstring[i]=='1'){
               return exponente1;
               }
            exponente1--;
       }
       return 0;
    } 
    
int main (){
    
    
    string bstring;
    
       
    float numero1;
    cout << "Ingresa su valor float: " << "\n";
    cin >> numero1;
    
    int numero2 = numero1;
    float numero3 = numero1 - numero2;

    cout << "Parte entera: " << numero2 << "\n";
    cout << "Parte decimal: " << numero3 << "\n";

    int exponente;
    int significando;



    string cadena = "";


    {//Bit 1
    if (numero1 > 0)
    {
        cadena = "0 ";
    }

    if (numero1 < 0)
    {
        cadena = "1 ";
    }
    }

    if ( numero1 < 1){
        numero1 = numero1 *-1;
    }

    if (numero1 > 0 && numero1 < 255 ){
        bitset<8> exponente1(numero2);
        bstring = exponente1.to_string();
        significando = 23;
        exponente = getexponente(bstring,7);
        bstring = bstring.substr(8-exponente);
        

        if (exponente !=0){
            exponente = exponente + 127;
        }

        exponente1 = exponente;
        
        cadena = cadena + exponente1.to_string();

    }

    

    if (numero1 > 255 && numero1 < 2048 ){
        bitset<11> exponente1(numero2);
        bstring = exponente1.to_string();
        significando = 52;
        exponente = getexponente(bstring,10);
        bstring = bstring.substr(11-exponente);
        

        if (exponente !=0){
            exponente = exponente + 127;
        }

        exponente1 = exponente;
        
        cadena = cadena + exponente1.to_string();

    }

    if (numero1 > 2048 && numero1 < 32768 ){
        bitset<15> exponente1(numero2);
        bstring = exponente1.to_string();
        significando = 112;
        exponente = getexponente(bstring,14);
        bstring = bstring.substr(15-exponente);
        

        if (exponente !=0){
            exponente = exponente + 127;
        }

        exponente1 = exponente;
        
        cadena = cadena + exponente1.to_string();

    }


    cout << cadena << "\n";
    //subset

    
    cadena = cadena + " ";
    cadena = cadena + bstring;
    
    significando = significando - bstring.length();

    for(int i=0; i < significando;i++)
    {
        numero3 = numero3*2.0;
        
        if (numero3 >= 1.0)
        {
            cadena = cadena + "1";
            numero3 = numero3 - 1.0;
            
        }
        else
        {
            cadena = cadena + "0";
            
        }
    }
    cout << cadena << "\n";

  

    



   


    
}
