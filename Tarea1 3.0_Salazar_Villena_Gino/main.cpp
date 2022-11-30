#include "miniwin.h"
#include "figure.h"

#include <iostream>

using namespace miniwin;
using namespace std;

void figuras(Forma f){

    if(f.nombre_forma=="Rectangulo"){
        Rectangulo r;

        int selec_rec;
        bool opc_rec = false;
        do{
            cout<<endl<<"Indica el número de la operación que desees realizar " <<endl;
            cout<<"(1) Calcular el Area" << endl;
            cout<<"(2) Calcular el Perimetro" << endl;
            cout<<"(3) Cambiar el tamaño del rectangulo" << endl;
            cout<<"(4) Imprimir la forma del Rectangulo" << endl;
            cout<<"(0) Volver" << endl;
            cin>>selec_rec;
            cin.ignore();
            switch(selec_rec){
                case 1:{
                    r.calcular_area(r.lado_mayor,r.lado_menor,r.factor);
                    break;
                }
                case 2:{
                    r.calcular_perimetro(r.lado_mayor,r.lado_menor,r.factor);
                    break;
                }
                case 3: {
                    r.change_rectangulo();
                    borra();
                    r.imprimir_rectangulo();
                    break;
                }
                case 4: {
                    f.imprimir_forma();
                    r.imprimir_rectangulo();
                    refresca();
                    break;
                }
                case 0: {
                    opc_rec = true;
                    borra();
                    break;
                }
                default: {
                    cout << "Opción no válida, vuelve a intentarlo" << endl;
                    break;
                }
            }
        }while(not opc_rec);
    }
    if(f.nombre_forma=="Circulo"){
        Circulo c;

        int selec_cir;
        bool opc_cir = false;
        do{
            cout<<endl<<"Indica el número de la operación que desees realizar " <<endl;
            cout<<"(1) Calcular el Area" << endl;
            cout<<"(2) Imprimir la forma del Circulo" << endl;
            cout<<"(0) Volver" << endl;
            cin>>selec_cir;
            cin.ignore();
            switch(selec_cir){
                case 1:{
                    c.calcular_area_circulo(c.radio,c.pi);
                    break;
                }
                case 2: {
                    c.imprimir_circulo();
                    refresca();
                    break;
                }
                case 0: {
                    opc_cir = true;
                    borra();
                    break;
                }
                default: {
                    cout << "Opción no válida, vuelve a intentarlo" << endl;
                    break;
                }
            }
        }while(not opc_cir);
    }
    if(f.nombre_forma=="Cuadrado"){
        Cuadrado q;

        int selec_q;
        bool opc_q = false;
        do{
            cout<<endl<<"Indica el número de la operación que desees realizar " <<endl;
            cout<<"(1) Calcular el Area" << endl;
            cout<<"(2) Imprimir la forma del Rectangulo" << endl;
            cout<<"(0) Volver" << endl;
            cin>>selec_q;
            cin.ignore();
            switch(selec_q){
                case 1:{
                    q.calcular_area_cuadrado(q.lado);
                    break;
                }
                case 2: {
                    q.imprimir_cuadrado();
                    refresca();
                    break;
                }
                case 0: {
                    opc_q = true;
                    borra();
                    break;
                }
                default: {
                    cout << "Opción no válida, vuelve a intentarlo" << endl;
                    break;
                }
            }
        }while(not opc_q);
    }
    if(f.nombre_forma=="Elipse"){
        Elipse e;

        int selec_elip;
        bool opc_elip = false;
        do{
            cout<<endl<<"Indica el número de la operación que desees realizar " <<endl;
            cout<<"(1) Calcular el Area" << endl;
            cout<<"(2) Imprimir la forma del Rectangulo" << endl;
            cout<<"(0) Volver" << endl;
            cin>>selec_elip;
            cin.ignore();
            switch(selec_elip){
                case 1:{
                    e.calcular_area_elipse(e.radio_mayor, e.radio_menor);
                    break;
                }
                case 2: {
                    e.imprimir_elipse();
                    refresca();
                    break;
                }
                case 0: {
                    opc_elip = true;
                    borra();
                    break;
                }
                default: {
                    cout << "Opción no válida, vuelve a intentarlo" << endl;
                    break;
                }
            }
        }while(not opc_elip);
    }

}
int main() {
    cout << "Inicio del programa" << endl;
    vredimensiona(1080, 920);

   //MENU/////////////////////////////////////////////////////////////////////////////////


    cout << "PROGRAMA DE CREACION DE FIGURAS GEOMETRICAS"<<"\n" << endl;
    cout<<" Creacion de figura Geometrica" << endl;
    int selec_form;
    bool opc_form = false;
    Forma f;
    do{
        cout<<endl<<"Indica el número de la operación que desees realizar " <<endl;
        cout<<"(1) Crear una nueva forma" << endl;
        cout<<"(2) Cambiar Color de la forma" << endl;
        cout<<"(3) Cambiar centro de la forma" << endl;
        cout<<"(4) Imprimir datos de la forma" << endl;
        cout<<"(0) Salir" << endl;
        cin>>selec_form;
        cin.ignore();
        switch(selec_form){
            case 1:{
                figuras(f);
                break;
            }
            case 2:{
                borra();
                f.func_color();
                refresca();
                break;
            }
            case 3: {
                borra();
                f.change_center();
                refresca();
                break;
            }
            case 4: {
                f.imprimir_forma();
                refresca();
                break;
            }
            case 0: {
                opc_form = true;
                break;
            }
            default: {
                cout << "Opción no válida, vuelve a intentarlo" << endl;
                break;
            }
        }
    }while(not opc_form);
    //MENU/////////////////////////////////////////////////////////////////////////////////
    refresca();
    cout << "Termino de programa"<< endl;
    return 0;
}
