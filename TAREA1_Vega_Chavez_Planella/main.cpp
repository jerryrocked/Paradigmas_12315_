#include "miniwin.h"
#include "forma.h"
using namespace miniwin;
using namespace std;

int main() {
    rectangle r;
    elipse e;
    circle c;
    square s;
    int dim_a, dim_b, form = 1;

    cout<<"Ingrese las dimensiones de la pantalla: "<<endl;
    cout<<"Horizontal: ";
    cin>>dim_a;
    cout<<"Vertical: ";
    cin>>dim_b;
    system("cls");

    vredimensiona(dim_a,dim_b);

    while(form>=1 && form<=4){

        string response = "y";
        cout<<"------OPCIONES DISPONIBLES------"<<endl;
        cout<<"Crear rectangulo -------- 1"<<endl;
        cout<<"Crear circulo ----------- 2"<<endl;
        cout<<"Crear cuadrado ---------- 3"<<endl;
        cout<<"Crear elipse ------------ 4"<<endl;
        cout<<"Finalizar e imprimir ---- 5"<<endl;
        cout<<"Ingrese seleccion: ";
        cin>>form;
        system("cls");

        switch(form){
        case 1:
            while(response == "y") {
                cout<<"/////MENU DE RECTANGULO/////"<<endl;
                r.agreg_rect();
                r.most_rect();
                cout<<"Continuar en rectangulo? y/n: ";
                cin>>response;
                system("cls");
            }
            break;
        case 2:
            while(response=="y") {
                cout<<"/////MENU DE CIRCULO/////"<<endl;
                c.agreg_circ();
                c.most_circ();
                cout<<"Continuar en circulo? y/n: ";
                cin>>response;
                system("cls");
            }
            break;
        case 3:
            while(response=="y") {
                cout<<"/////MENU DE CUADRADO/////"<<endl;
                s.agreg_cuadr();
                s.most_cuadr();
                cout<<"Continuar en cuadrado? y/n: ";
                cin>>response;
                system("cls");
            }
        case 4:
            while(response=="y") {
                cout<<"/////MENU DE ELIPSE/////"<<endl;
                e.agreg_elip();
                e.most_elip();
                cout<<"Continuar en elipse? y/n: ";
                cin>>response;
                system("cls");
            }
        }
        system("cls");
    }

    refresca();
    return 0;
}
