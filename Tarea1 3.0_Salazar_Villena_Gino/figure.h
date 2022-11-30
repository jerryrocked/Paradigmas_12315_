#include "miniwin.h"
#include <iostream>
#include <string>

using namespace std;
using namespace miniwin;


class Forma{
public:
    string nombre_forma;
    int color_f;
    float x,y;//coordenadas del centro de la forma

    void imprimir_forma(); //Imprimir
    void func_color();//Obtener y cambiar el color
    void change_center(); //Mover la forma (o sea, su centro)
    Forma();
};
Forma::Forma(){

    cout<<"Ingrese el nombre de la forma a agregar: (Rectangulo, Circulo, Cuadrado, Elipse) "<<"\n";
    cin>>this->nombre_forma;
    cin.ignore();
    //getline(cin, this->nombre_forma);

    while(this->nombre_forma!="Rectangulo" && this->nombre_forma!="Circulo"&&this->nombre_forma!="Cuadrado"&&this->nombre_forma!="Elipse"){
        cout <<"Nombre no v�lido, vuelve a intentarlo" << endl;
        cout<<"Ingrese el nombre de la forma a agregar: (Rectangulo, Circulo, Cuadrado, Elipse) "<<"\n";
        getline(cin, this->nombre_forma);
    }

    cout<<"Ingrese el color de la forma a agregar: (0.-NEGRO,1.-ROJO,2.-VERDE,3.-AZUL,4.-AMARILLO,5.-MAGENTA,6.-CYAN,7.-BLANCO)"<<"\n";
    cin>>this->color_f;
    cin.ignore();
    while(this->color_f!= 0 && this->color_f!= 1 &&this->color_f!=2 &&this->color_f!=3 &&this->color_f!=4 &&this->color_f!=5 &&this->color_f!=6 &&this->color_f!=7){
        cout <<"Color no v�lido, vuelve a intentarlo" << endl;
        cout<<"Ingrese el color de la forma a agregar: (0.-NEGRO,1.-ROJO,2.-VERDE,3.-AZUL,4.-AMARILLO,5.-MAGENTA,6.-CYAN,7.-BLANCO) "<<"\n";
        cin>>this->color_f;
        cin.ignore();
    }

    cout<<"Ingrese el centro de la forma a agregar: (x ; y) "<<"\n";
    cout<<"Ingrese la coordenada x: ";
    cin>>this->x;
    cin.ignore();
    cout<<"Ingres la coordenada y: ";
    cin>>this->y;
    cin.ignore();
}
void Forma::imprimir_forma(){
    cout<<"Nombre de la forma: "<< this->nombre_forma <<"\n";
    cout<<"Color de la forma: "<< this->color_f <<"\n";
    cout<<"Coordenada del centro de la forma:"<<"\n";
    cout<<"Coordenada x:"<<this->x<<endl;
    cout<<"Coordenada y:"<<this->y<<endl;
    linea(0,0,this->x,this->y);
}

void Forma::func_color(){
    cout<<"Nuevo color para la forma: ";
    cin>>this->color_f;
    cin.ignore();
}

void Forma::change_center(){
    cout<<"Nueva coordenada del centro para la forma: ";
    cin>>this->x;
    cin.ignore();
    cout<<"Ingres la coordenada y: ";
    cin>>this->y;
    cin.ignore();
}

class Rectangulo:public Forma{
public:
    double lado_menor;
    double lado_mayor;

    double factor=1;

    void imprimir_rectangulo();
    double calcular_area(double lado_mayor,double lado_menor,double factor);
    void calcular_perimetro(double lado_mayor,double lado_menor,double factor);
    void change_rectangulo();

    Rectangulo(){
    cout<<"Ingrese el lado mayor del rectangulo a agregar: "<<"\n";
    cin>>this->lado_mayor;
    cin.ignore();
    cout<<"Ingrese el lado menor del rectangulo a agregar: "<<"\n";
    cin>>this->lado_menor;
    cin.ignore();
  }
};

void Rectangulo::imprimir_rectangulo(){
    cout<<"El factor de escala es de 1:100 "<<"\n";
    cout<<"Lado mayor del rectangulo (cm): "<< this->lado_mayor <<"\n";
    cout<<"Lado menor del rectangulo (cm): "<< this->lado_menor <<"\n";
    color(color_f);
    rectangulo_lleno(this->x-(this->lado_mayor/2),this->y-(this->lado_menor/2),this->x+(this->lado_mayor/2),this->y+(this->lado_menor/2));
    //rectangulo((100*this->factor), (100*this->factor), (this->lado_mayor*100), (this->lado_menor*100));
}
void Rectangulo::calcular_perimetro(double mayor, double menor,double factor){
    //(2 * lado menor + 2 * lado mayor)
    double perimetro= (2 * (lado_mayor*factor))+(2 * (lado_menor*factor));
    cout<<"El perimetro del rectangulo es:"<< perimetro <<"mts"<<"\n";
}

double Rectangulo::calcular_area(double mayor, double menor,double factor){
    //lado menor * lado mayor
    this->lado_mayor=(mayor*factor);
    this->lado_menor=(menor*factor);
    double area= this->lado_mayor * this->lado_menor;
    cout<<"El area del rectangulo es:"<< area <<"m2"<<"\n";
    return area;
}
void Rectangulo::change_rectangulo(){

    //Cambia el tamaño del rectangulo
    //si el factor vale 2, el rectángulo duplicará su tamaño y
    //si es 0,5 se reducirá a la mitad
    cout<<"Ingrese el factor de cambio del tamaño del rectangulo: "<<"\n";
    cin >>this->factor;
    Rectangulo::calcular_area(this->lado_mayor, this->lado_menor,this->factor);
    Rectangulo::calcular_perimetro(this->lado_mayor, this->lado_menor,this->factor);
}

class Elipse:public Forma{
public:

    float radio_mayor;//(R)
    float radio_menor;//(r)
    float pi= 3.141592;

    void imprimir_elipse();
    void calcular_area_elipse(float radio_mayor,float radio_menor);

    Elipse(){
    cout<<"Ingrese el radio mayor del elipse a agregar: "<<"\n";
    cin>>this->radio_mayor;
    cin.ignore();
    cout<<"Ingrese el radio menor del elipse a agregar: "<<"\n";
    cin>>this->radio_menor;
    cin.ignore();

    }
};

void Elipse::imprimir_elipse(){
    cout<<"Radio mayor del Elipse: "<< this->radio_mayor <<"\n";
    cout<<"Radio menor del Elipse: "<< this->radio_menor <<"\n";
    color(color_f);
    elipse_lleno(this->x,this->y,this->radio_mayor, this->radio_menor);
}

void Elipse::calcular_area_elipse(float mayor, float menor){
    //area= pi * (R*r)
    float area= pi * (mayor*menor);
    cout<<"El area del rectangulo es:"<< area <<"m2"<<"\n";
}

class Circulo: public Elipse{
public:
    float radio;//(r)
    float pi= 3.141592;
    void imprimir_circulo();
    void calcular_area_circulo(float radio, float pi);

    Circulo(){
    cout<<"Ingrese el radio del circulo a agregar: "<<"\n";
    cin>>this->radio;
    cin.ignore();
    }
};

void Circulo::imprimir_circulo(){
    cout<<"Radio del circulo: "<< this->radio <<"\n";
    color(color_f);
    circulo_lleno(this->x, this->y,this->radio);
}

void Circulo::calcular_area_circulo(float radio, float pi){
    //area=pi * (radio elevado al cuadrado)
    float area= pi*(radio*radio);
    cout<<"El area del circulo es:"<< area <<"m2"<<"\n";
}

class Cuadrado: public Rectangulo{
  public:

    float lado;//

    void imprimir_cuadrado();
    void calcular_area_cuadrado(float lado);

    Cuadrado(){

    cout<<"Ingrese el lado del cuadrado  a agregar: "<<"\n";
    cin>>this->lado;
    cin.ignore();
    }
};

void Cuadrado::imprimir_cuadrado(){

    cout<<"Lado del cuadrado: "<< this->lado <<"\n";
    color(color_f);
    rectangulo_lleno(this->x-(this->lado/2),this->y-(this->lado/2),this->x+(this->lado/2),this->y+(this->lado/2));
}

void Cuadrado::calcular_area_cuadrado(float lado){
    //lado menor * lado mayor
    float area= lado * lado;
    cout<<"El area del cuadrado es:"<< area <<"m2"<<"\n";
}
