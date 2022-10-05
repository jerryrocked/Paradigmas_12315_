#include "miniwin.h"
#include <iostream>
using namespace std;
using namespace miniwin;

class Forma {
public:
    int colorForma;
    float x, y;
	void obtener_form();
	void imp_f();
};
class rectangle : public Forma {
public:
	float lado_men, lado_may, per_rect, area_rect;
	void cal_per();
	void cal_area();
	void agreg_rect();
	void most_rect();
	void imp_r();
};
class elipse : public Forma {
public:
    float rad_min, rad_max, area_elip;
    void cal_area();
    void agreg_elip();
    void most_elip();
    void imp_e();
};
class square : public rectangle {
public:
    void agreg_cuadr();
    void most_cuadr();
};
class circle : public elipse {
public:
    void agreg_circ();
    void most_circ();
};

void Forma::obtener_form() {
    cout<<"Escriba un color del 1 al 7"<<endl;
    cout<<"(rojo, verde, azul, amarillo, magenta, cyan o blanco): ";
    cin>>colorForma;
    cout<<"Escriba la coordenada x: ";
    cin>>x;
    cout<<"Escriba la coordenada y: ";
    cin>>y;
}
void Forma::imp_f() {
    cout<<"Color:"<<colorForma<<endl;
    cout<<"Coordenada x:"<<x<<endl;
    cout<<"Coordenada y:"<<y<<endl;
}

void rectangle::imp_r(){
    system("cls");
    cout<<"--------- AGREGANDO A LA VENTANA ---------"<<endl;
    imp_f();
    cal_area();
    cal_per();
    cout<<"--- FINALIZAR PROGRAMA PARA VISUALIZAR ---"<<endl;
    cout<<""<<endl;
}
void rectangle::agreg_rect() {
    obtener_form();
    cout<<"Escriba el primer lado: ";
    cin>>lado_men;
    cout<<"Escriba el segundo lado: ";
    cin>>lado_may;
    imp_r();
}
void rectangle::most_rect() {
    linea(0,0,x,y);
    color(colorForma);
    rectangulo_lleno(x-(lado_men/2),y-(lado_may/2),x+(lado_men/2),y+(lado_may/2));
}
void rectangle::cal_per(){
    per_rect = (lado_may*2)+(lado_men*2);
    cout<<"Perimetro:"<<per_rect<<endl;

}
void rectangle::cal_area(){
    area_rect = (lado_may*lado_men);
    cout<<"Area:"<<area_rect<<endl;
}

void elipse::agreg_elip() {
    obtener_form();
    cout<<"Escriba el radio menor: ";
    cin>>rad_min;
    cout<<"Escriba el radio mayor: ";
    cin>>rad_max;
    imp_e();
}
void elipse::most_elip() {
    linea(0,0,x,y);
    color(colorForma);
    elipse_lleno(x,y, rad_min, rad_max);
}
void elipse::cal_area() {
    float pi = 3.1415;
    area_elip = pi*(rad_max*rad_min);
    cout<<"Area:"<<area_elip<<endl;
}
void elipse::imp_e() {
    system("cls");
    cout<<"--------- AGREGANDO A LA VENTANA ---------"<<endl;
    imp_f();
    cal_area();
    cout<<"--- FINALIZAR PROGRAMA PARA VISUALIZAR ---"<<endl;
    cout<<""<<endl;
}

void square::agreg_cuadr() {
    obtener_form();
    cout<<"Escriba el lado: ";
    cin>>lado_may;
    lado_men = lado_may;
    imp_r();
}
void square::most_cuadr() {
    linea(0,0,x,y);
    color(colorForma);
    rectangulo_lleno(x-(lado_men/2),y-(lado_may/2),x+(lado_men/2),y+(lado_may/2));
}

void circle::agreg_circ() {
    obtener_form();
    cout<<"Escriba el radio: ";
    cin>>rad_min;
    rad_max = rad_min;
    imp_e();
}
void circle::most_circ() {
    linea(0,0,x,y);
    color(colorForma);
    circulo_lleno(x,y,rad_max);
}
