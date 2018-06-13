//LIBRERÍAS
#include <iostream>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
//ARCHIVOS
#include "Persona.h"
#include "Persona.cpp"


using namespace std;

/*
 * ESTE PROGRAMA USA COMANDOS LINUX ....  system("cls") --> system("clear") // system("pause") --> system("read var")
 * 
 * NOMBRES: ROLANDO SEMEHÍ SUMOZA RIVAS && DIEGO FABRICIO GÓMEZ GONZÁLEZ
 * REGISTROS: 17310315 &&
 * FECHA: 
 * PROGRAMACIÓN ORIENTADA A OBJETOS
 */
 
//alternativa fflush

void flush_in()
{
	int ch;
	while((ch=fgetc(stdin)) != EOF && ch != '\n'){}
}
//termina alternativa fflush






typedef struct Nodos//nodo
{
    //INFO PELI
    int ID;
    string pelicula;
    int sala;
    char asiento;
    //FECHA
    int dia;
    int mes;
    int anio;
    
    struct Nodos *next;//siguiente
} Nodos;



//CLASE PARA CREAR LISTA
class Lista:public Persona{
	private:
    Nodos * lista;//Estructura Nodo
    
    public:
    Lista(){      //Constructor
	lista = NULL;
	}



//CLASE PARA AGREGAR NUEVA PELÍCULA
public:void agregarNodo(int ID, string pelicula, char asiento, int sala, int dia, int mes, int anio){
	
        Nodos *NuevoNodo = (Nodos *)malloc(sizeof(Nodos));
        NuevoNodo-> ID = ID;
        NuevoNodo-> pelicula = pelicula;
        NuevoNodo-> asiento = asiento;
        NuevoNodo-> dia = dia;
        NuevoNodo-> mes = mes;
        NuevoNodo-> anio= anio;
        NuevoNodo->next = NULL;
        
        if (lista == NULL){
            lista = NuevoNodo;
		}
        else{
            Nodos *aux = lista;
            while (aux->next != NULL){
                aux = aux-> next;
            }
            aux->next = NuevoNodo;
        }
    }//final agregar
    
    //MOSTAR
public:void mostrarValores(){
        Nodos *aux = lista;
        if (lista == NULL){
			system("clear");
            cout << "--- No hay películas ---" << endl;
            system("read var");
		}
        else{
			system("clear");
			cout << "LISTA: " << endl;
            while (aux != NULL){
				cout << endl;
                cout << "Nombre de la película: " << aux->pelicula << endl;
                //cout << "Asiento: " << aux->asiento << endl;
                if(aux->ID == 1){
                cout << "Tipo: Normal" << endl;
				}
				else if(aux->ID == 2){
                cout << "Tipo: Matiné" << endl;
				}
				else{
                cout << "Tipo: Preventa" << endl;
				}
                cout << "Fecha de la película: " << aux->dia << "/" << aux->mes << "/" << aux->anio << endl;
				cout << endl;
                aux = aux->next;
            }
            system("read var");
        }
    }//final mostrar
    
    
    //ELIMINAR
	public:void eliminarNodo(string _pelicula){
		Nodos *aux = lista, *ant = NULL;
        while ((aux != NULL) && (aux->pelicula != _pelicula))
        {
            ant = aux;
            aux = aux->next;
        }
        if (aux != NULL)
        {
            if (ant != NULL)
                ant->next = NULL;
            else
                lista = aux->next;
            system("clear");
            cout << "---Película Borrada---" << endl;
            system("read var");
            free(aux);
        }
        else
            cout << "Película inexistente" << endl;
    }//final eliminar
    
    
    //MODIFICAR
    public:void insertarNodoOrd(string pelicula, char asiento, int sala, int dia, int mes, int anio){
        Nodos *NuevoNodo = (Nodos *)malloc(sizeof(Nodos));
        NuevoNodo-> asiento = asiento;
        NuevoNodo-> sala = sala;
        NuevoNodo-> dia = dia;
        NuevoNodo-> mes = mes;
        NuevoNodo-> anio= anio;
        NuevoNodo->	next = NULL;
        Nodos *aux = lista;
        Nodos *ant = NULL;
        while ((aux != NULL) && (aux->pelicula < NuevoNodo->pelicula)){
            ant = aux;
            aux = aux->next;
        }
        if (ant != NULL){
            ant->next = NuevoNodo;
            NuevoNodo->next = aux;
        }
        else{
            lista = NuevoNodo;
            NuevoNodo->next = aux;
        }
    }//final modificar
	
	
	
	//Comprar Boleto
	public: Nodos *ComprarBoleto(string pelicula){
		Nodos *aux = lista;
		while ((aux != NULL) && (aux->pelicula != pelicula))
        {
            aux = aux->next;
        }
        if (aux != NULL)
        {
			return aux;
		}
		else {
			return NULL;
		}	
	}
	
};//final clase lista






int main(){
	//Variables
	int x = 0;
	int opc;
	char exit;
	
	//valores a mandar
	int dia, mes, anio, ID, sala;
	string pelicula, _pelicula;
	char asiento;
	
	//Objeto lista con memoria dinámica
	Lista *i = new Lista();
	
	
	//Menú
	while(x==0){
	system("clear");
	cout << "---- BIENVENIDO AL SISTEMA DE CINE ----" << endl;
	cout << " Elija una opción del menú: " << endl << endl;
	cout << "---OPERACIONES DE LISTA---" << endl << endl;
	cout << "1.- Agregar una película" << endl;
	cout << "2.- Ver Cartelera" << endl;
	cout << "3.- Eliminar Película" << endl;
	cout << "4.- Modificar película" << endl;
	cout << "5.- Salir del sistema" << endl << endl;
	cout << "---OPERACIONES DE USUARIO---" << endl;
	cout << "6.- Comprar un boleto" << endl;
	cout << "7.- Ver mis boletos" << endl;
	
	
	cin >> opc;
	//Switch
	switch(opc){
		
		case 1:{
			
			ofstream file;

			file.open("/home/rolukas/Escritorio/datos.txt", ios::out|ios::binary);

			system("clear");
			cout << "¿Qué tipo de película desea anexar?" << endl;
			cout << "1.- Normal" << endl;
			cout << "2.- Matiné" << endl;
			cout << "3.- Preventa" << endl;
			cin >> ID;
			system("clear");
			cout << "Nombre de la pelicula: " << endl;
			cin >> pelicula;
			flush_in();
			//Persona
			cout << "Asiento: (CHAR) " << endl;
			cin >> asiento;
			flush_in();
			cout << "Sala: (ENTERO)" << endl;
			cin >> sala;
			flush_in();
			
			//Fin Persona
			cout << "Fecha: " << endl << endl;
			cout << "DÍA: " << endl;
			cin >> dia;
			cout << "MES: " << endl;
			cin >> mes;
			cout << "AÑO: " << endl;
			cin >> anio;

			i->agregarNodo(ID, pelicula, asiento, sala, dia, mes, anio);//Guarda en la lista
			i->Persona::Capturar(asiento, sala);//Guarda en la clase Persona (HERENCIA)
			
			if (file.fail()){
			cout << "NO SE HA CREADO EL ARCHIVO";
			system("read var");
			return 0;//exit(1);
			}
				//meter información
				file << "Película: " << pelicula << endl;
				file << "Asiento: " << asiento << endl;
				file << "Sala: " << sala << endl;
				file << "Fecha: " << endl;
				file << dia << "/";
				file << mes << "/";
				file << anio << endl;
				file << "\r";
				file.close();
				
			break;
		}//fin case1
		
			case 2:{
				//i->mostrarValores();
				ifstream filein("/home/rolukas/Escritorio/datos.txt", ios::in);
				if (filein.fail()){
				cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
				return 0;
				}
				else{
			    char cad[100];
			    cout << " ---- CARTELERA ---- " << endl << endl;
				while (!filein.eof()){
				filein.getline(cad,100);
				cout << cad << endl;
				}
				system("read var");
				}
				filein.close();
				cin.get();
				break;
			}//fin case2
			
				case 3:{
				
				cout << "¿Qué película desea eliminar de la lista?" << endl;
				cin >> _pelicula;
				i->eliminarNodo(_pelicula);
				
				break;
				}//fin case3
				
					case 4:{
					cout << "Ingrese el NOMBRE de la película a modificar: " << endl;
					cin >> pelicula;
					cout << "Sala: (ENTERO)" << endl;
					cin >> sala;
					cout << "Asiento: (CHAR) " << endl;
					cin >> asiento;
					cout << "Fecha de compra del boleto: " << endl << endl;
					cout << "---Día: ---" << endl;
					cin >> dia;
					cout << "---Mes: ---" << endl;
					cin >> mes;
					cout << "---Año: ---" << endl;
					cin >> anio;

					i->insertarNodoOrd(pelicula,sala,asiento,dia,mes,anio);
            break;
					
					break;	
					}
					
						case 5:{
							system("clear");
							cout << "¿Está seguro que desea salir del sistema? (y/n)" << endl;
							cin >> exit;
						
									if(exit =='y'){
										x=1;
									}
									else if(exit =='n'){
										x=0;
									}
									break;
								}//fin case5
							
							case 6:{
								system("clear");
								
								cout << "¿Para qué película desea comprar un boleto?" << endl;
								cin >> pelicula;
								i->ComprarBoleto(pelicula);

								if ( i->ComprarBoleto(pelicula) == NULL ){
									cout << "No se encontró la película " << endl;
								}
								else{
									
									//Crear archivo con mis boletos
									ofstream file;
									file.open("/home/rolukas/Escritorio/boletos.txt", ios::out|ios::binary);
									file << "Película: " << pelicula << endl;
									file << "Asiento: " << asiento << endl;
									file << "Sala: " << sala << endl;
									file << "Fecha: " << endl;
									file << dia << "/";
									file << mes << "/";
									file << anio << endl;
									file << "\r";
									file.close();
									cout << "Boleto comprado exitosamente" << endl;
									system("read var");
								}
								
									break;
								}//fin case 6
								
								
				
					
									case 7:{
										ifstream filein("/home/rolukas/Escritorio/boletos.txt", ios::in);
										if (filein.fail()){
										cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
										return 0;
										}
										else{
										char cad[100];
										cout << " ---- BOLETOS COMPRADOS ---- " << endl << endl;
										while (!filein.eof()){
										filein.getline(cad,100);
										cout << cad << endl;
										}
										system("read var");
										}
										filein.close();
										cin.get();
										break;
									}
									
									
									
						default:{
							system("clear");
							cout << "No se encontró la opción" << endl;
							system("read var");
							break;
						}
			
			
		}
	}//llave final de switch
	return 0;
}//llave final de while	
	
	
	


