#include<iostream>
#include<math.h>
#include<conio.h>

using namespace std;

//Prototipo de la derivada
double Deriva(double g);
//prototipo de la funcion
double Funcion(double h);
//Prototipo del margen de Error.
double Error(double u,double v);

int main(){
	double xi,fxi,fdxi,tol,error,r,fr,ra=0;
	int it=1;
	int a;
	do{
	system("color 1E");
	system("cls");
	cout<<"\n\n\n\n\t\TPROGRAMA QUE CALCULA LA RAIZ SOLUCION f(x) = x^3* e^(0.5x)+1.5x-10";
	cout<<"\n\n\n\t\t\tMETODO DE NEWTON-RAPHSON.";
	
	
	do{
	cout<<"\n\n\n\tDigita un valor para xi:  ";cin>>xi;
	fdxi=Deriva(xi);
		
	}while(fdxi==0);
	cout<<"\n\n\n\tIngresa el % de tolerancia:  ";cin>>tol;
	system("cls");
	do{
	fdxi=Deriva(xi);
	fxi=Funcion(xi);
	r=xi-(fxi/fdxi);
	fr=Funcion(r);
	error=Error(r,ra);

	cout<<"\n\n\n\n\t\tIteracion n"<<it;
	cout<<"\n\n\txi:  "<<xi;
	cout<<"\n\tf(xi): "<<fxi;
	cout<<"\n\tf`xi:"<<fdxi;
	cout<<"\n\tR:  "<<r;
	cout<<"\n\t|f(r)|: "<<fr;
	cout<<"\n\t% Error:  "<<error;
	ra=xi;
	if(fr!=0){
	xi=r;	
	}
	it++;
	}while(tol<error);
	
	cout<<"\n\n\n\tLa raiz solucion es "<<r<<" con "<<it-1<<" iteraciones.";
	cout<<"\n\tCon un margen de error de % "<<error;
	cout<<"\n\n\n\tDesea volver a calcular xi?";
	cout<<"\n\n\t 1- si.\n\n\t 2- no."<<endl;
	cout<<"\n\n\topcion: ";cin>>a;
	system("cls");
	}while(a==1||a<=1||a>2);
	
	
	getch();
	return 0;
}

double Deriva(double g){
	double y=((0.5*(pow(g,3)))*exp(0.5*g))+((3*(pow(g,2)))*exp(0.5*g))+1.5;
    return y;	
}

double Funcion(double h){
	double z=((pow(h,3))*exp(0.5*h))+(1.5*h)-10;
	return z;
}

double Error(double u,double v){
	double x=fabs((u-v)/u)*100;
	return x;
}

