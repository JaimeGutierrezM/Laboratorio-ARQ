//Jaime Mateo Gutierrez Muñoz
//Laboratorio 02b: Aritmética de Punto Flotante


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
    
    //Float
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

    

    //Double
    
    
    string bstringb;
    
    double numero1b;
    cout << "Ingresa su valor double: " << "\n";
    cin >> numero1b;
    
    int numero2b = numero1b;
    double numero3b = numero1b - numero2b;
    

    cout << "Parte entera: " << numero2b << "\n";
    cout << "Parte decimal: " << numero3b << "\n";
    cout << "Numero 3 : "<<  numero3b << "\n";

    int exponenteb;
    int significandob;

    

    string cadenab = "";
    

    {//Bit 1
    if (numero1b > 0)
    {
        cadenab = "0 ";
    }

    if (numero1b < 0)
    {
        cadenab = "1 ";
    }
    

    if ( numero1b < 1){
        numero1b = numero1b *-1;
    }

    }

    if (numero1b > 0 && numero1b < 2048 ){
        bitset<11> exponente1b(numero2b);
        bstringb = exponente1b.to_string();
        significandob = 52;
        exponenteb = getexponente(bstringb,10);
        bstringb = bstringb.substr(11-exponenteb);
        

        if (exponenteb !=0){
            exponenteb = exponenteb + 1023;
        }

        exponente1b = exponenteb;
        
        cadenab = cadenab + exponente1b.to_string();

    }

    cout << cadenab << "\n";
   

    
    cadenab = cadenab + " ";
    cadenab = cadenab + bstringb;
    
    significandob = significandob - bstringb.length();

    for(int i=0; i < significandob;i++)
    {
        numero3b = numero3b*2.0;
        
        if (numero3b >= 1.0)
        {
            cadenab = cadenab + "1";
            numero3b = numero3b - 1.0;
            
        }
        else
        {
            cadenab = cadenab + "0";
            
        }
    }
    cout << cadenab << "\n";

    
    
    
}
