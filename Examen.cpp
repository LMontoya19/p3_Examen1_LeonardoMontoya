#include <iostream>

using std::cout;
using std::cin;
using std::endl;


char** creartablero(int);
void imprimirtablero(int,char**);
int cambiarletra(char);
int verificarmovimiento(char**&,int,int,int,int);
void comer(char**&,int,int,char);
int main(){
    bool ganador = false;
    char** tablero;
    char letra = 'z';
    int x = 20;
    int y = 20;
    int x2 = 20;
    int y2 = 20;
    tablero = creartablero(11);
    tablero[5][0] = '#';
    tablero[5][10] = '#';
    tablero[0][5] = '+';
    tablero[10][5] = '+';
    imprimirtablero(11,tablero);   
    while(ganador == false){
    	//Turno jugador_1
	bool movio = false;
	while(movio==false){
	cout<<"Jugador 1(+) ingrese coordenanda de pieza que quiere mover(ejemplo : j5 o b5)"<<endl;
	cin>> letra;
	cin>>x;
	y  = cambiarletra(letra);
			
	if((y<11&&y>=0)&&(x<11&&x>=0)){
	     if(tablero[x][y] == '+'){
	     cout<<"ingrese coordenanda adonde quiere mover(ejemplo : j5 o b5)"<<endl;	     
	     cin>>letra;
	     cin>>x2;
	     y2 = cambiarletra(letra);
	     if((y2<11&&y2>=0)&&(x2<11&&x2>=0)){
	     	int movimientoj1 = 3;
	        movimientoj1 = verificarmovimiento(tablero,x,y,x2,y2);
		if(movimientoj1 == 1){
		if(tablero[x2][y2]=='-'){
		tablero[x2][y2]='+';
		comer(tablero,x2,y2,'+');
		imprimirtablero(11,tablero);
		movio=true;
		}	
		}else if(movimientoj1 == 2){
		 if(tablero[x2][y2]=='-'){
		tablero[x][y]='-';
                tablero[x2][y2]='+';
                comer(tablero,x2,y2,'+');
                imprimirtablero(11,tablero);
		movio = true;	
		}
	     
	     }
	     }else{
	     cout<<"Coordenada no valida"<<endl;
	     }
	     }
	     else{
	     	cout<<"No hay una pieza suya ahi"<<endl;
	     }
	}else{
	     cout<<"Coordenada no valida"<<endl;
	}}

	int jugador1,jugador2,espacios;
        espacios=121;
        jugador1=0;
        jugador2=0;
        letra='z';
        x=20;
        y=20;
        x2=20;
        y2=20;
         for(int i = 0;i<11;i++){
          for(int j = 0;j<11;j++){
             if(tablero[i][j]=='+'){
             jugador1++;
             }if(tablero[i][j]=='#'){
             jugador2++;
             }if(tablero[i][j]!='-'){
             espacios--;
             }
          }
      }

	if(jugador2>0){	
	//Turn jugador_2
	movio = false;
	while(movio==false){
	letra='z';
	x=20;
	y=20;
	x2=20;
	y2=20;
	cout<<"Jugador 2(#) ingrese coordenanda de pieza que quiere mover(ejemplo : j5 o b5)"<<endl; 
	cin>> letra;
        cin>>x;
        y  = cambiarletra(letra);

        if((y<11&&y>=0)&&(x<11&&x>=0)){
             if(tablero[x][y] == '#'){
             cout<<"ingrese coordenanda adonde quiere mover(ejemplo : j5 o b5)"<<endl;
             cin>>letra;
             cin>>x2;
             y2 = cambiarletra(letra);
             if((y2<11&&y2>=0)&&(x2<11&&x2>=0)){
                int movimientoj2 = 3;
                movimientoj2 = verificarmovimiento(tablero,x,y,x2,y2);
                if(movimientoj2 == 1){
                if(tablero[x2][y2]=='-'){
                tablero[x2][y2]='#';
                comer(tablero,x2,y2,'#');
                imprimirtablero(11,tablero);
		movio= true;
		}
                }else if(movimientoj2 == 2){
                 if(tablero[x2][y2]=='-'){
		tablero[x][y]='-';
                tablero[x2][y2]='#';
                comer(tablero,x2,y2,'#');
                imprimirtablero(11,tablero);
		movio=true;
                }

             }
             }else{
             cout<<"Coordenada no valida"<<endl;
             }
             }
             else{
                cout<<"No hay una pieza suya ahi"<<endl;
             }
        }else{
             cout<<"Coordenada no valida"<<endl;
        }}}

	espacios=121;
	jugador1=0;
	jugador2=0;
	letra='z';
        x=20;
        y=20;
        x2=20;
        y2=20;
	 for(int i = 0;i<11;i++){
          for(int j = 0;j<11;j++){
             if(tablero[i][j]=='+'){
	     jugador1++;
	     } if(tablero[i][j]=='#'){
	     jugador2++;
	     }if(tablero[i][j]!='-'){
	     espacios--;
	     }
          }
      }
	if(espacios==0||jugador1==0||jugador2==0){
		if(jugador1>jugador2){
		cout<<"Gano el jugador 1"<<endl;
		}else{
		cout<<"Gano el jugador 2"<<endl;
		}
		ganador=true;
	}else{
	cout<<"**Puntaje**"<<endl;
	cout<<"Jugador 1: "<<jugador1<<endl;
	cout<<"Jugador 2: "<<jugador2<<endl;
	}

    }
    for(int j = 0;j<11;j++){
             delete[] tablero[j];
          }
	delete[] tablero;
    return 0;
}

char** creartablero(int size){
      char** retval = new char*[size];
      for(int i = 0;i<size;i++){
          retval[i]= new char[size]; 
      }
      for(int i = 0;i<size;i++){
          for(int j = 0;j<size;j++){
             retval[i][j] = '-';
          }
      }

      return retval;
}


void imprimirtablero(int size,char** tablero){
      cout<<" ABCDEFGHIJK"<<endl;
      for(int i = 0;i<size;i++){
  	  cout<<i;
          for(int j = 0;j<size;j++){
	     cout<< tablero[i][j];
	  }
	  cout<<endl;
      }

}

 int cambiarletra(char letra){
	 int ret = 20;
 	 switch(letra){
                case 'a'  : {ret = 0;
                            break;
                             }           
                case 'b'  : {ret = 1;
                            break;
                             }
                case 'c'  : {ret = 2;
                            break;
                             }
                case 'd'  : {ret = 3;
                            break;
                             }
                case 'e'  : {ret = 4;
                            break;
                             }
                case 'f'  : {ret = 5;
                            break;
                             }
                 case 'g'  : {ret = 6;
                            break;
                             }
                 case 'h'  : {ret = 7;
                            break;
                             }
                 case 'i'  : {ret = 8;
                            break;
                             }
                 case 'j'  : {ret = 9;
                            break;
                             }
                 case 'k'  : {ret = 10;
                            break;
                             }
		}
	 return ret;
 
 }

 int verificarmovimiento(char**& mesa,int xvieja,int yvieja,int xnueva,int ynueva){
	int retnum = 3;
	if(ynueva==yvieja&&xnueva-1==xvieja){
	retnum  =1;
	}//abajo
	if(ynueva==yvieja&&xnueva+1==xvieja){
        retnum =1;
        }//arriba
	if(ynueva+1==yvieja&&xnueva==xvieja){
        retnum =1;
        }//izquierda
	if(ynueva-1==yvieja&&xnueva==xvieja){
        retnum  =1;
        }//derecha
	if(ynueva-1==yvieja&&xnueva-1==xvieja){
        retnum  =1;
        }//diagonal derecha inferior
	if(ynueva+1==yvieja&&xnueva-1==xvieja){
        retnum  =1;
        }//diagonal izquierda inferior
	if(ynueva+1==yvieja&&xnueva+1==xvieja){
        retnum =1;
        }//diagonal izquierda superior
	if(ynueva-1==yvieja&&xnueva+1==xvieja){
        retnum  =1;
        }//diagonal derecha superior
	

	//dos pasos
	if(xnueva-2>=0){
	 if(mesa[xnueva-1][ynueva]=='-'){
	 if(ynueva==yvieja&&xnueva-2==xvieja){
        retnum  =2;
        }}}//abajo

	if(xnueva+2<11){
	if(mesa[xnueva+1][ynueva]=='-'){
        if(ynueva==yvieja&&xnueva+2==xvieja){
        retnum =2;
        }}}//arriba

	if(ynueva+2<11){
	if(mesa[xnueva][ynueva+1]=='-'){
        if(ynueva+2==yvieja&&xnueva==xvieja){
        retnum =2;
        }}}//izquierda

	if(ynueva-2>=0){
	if(mesa[xnueva][ynueva-1]=='-'){
        if(ynueva-2==yvieja&&xnueva==xvieja){
        retnum  =2;
        }}}//derecha

	if(ynueva-2>=0&&xnueva-2>=0){
	if(mesa[xnueva-1][ynueva-1]=='-'){
        if(ynueva-2==yvieja&&xnueva-2==xvieja){
        retnum  =2;
        }}}//diagonal derecha inferior

	if(ynueva+2<11&&xnueva-2>=0){
	if(mesa[xnueva-1][ynueva+1]=='-'){
        if(ynueva+2==yvieja&&xnueva-2==xvieja){
        retnum  =2;
        }}}//diagonal izquierda inferior

	if(ynueva+2<11&&xnueva+2<11){
	if(mesa[xnueva+1][ynueva+1]=='-'){
        if(ynueva+2==yvieja&&xnueva+2==xvieja){
        retnum =2;
        }}}//diagonal izquierda superior

	if(ynueva-2>=0&&xnueva+2<11){
	if(mesa[xnueva+1][ynueva-1]=='-'){
        if(ynueva-2==yvieja&&xnueva+2==xvieja){
        retnum  =2;
        }}}//diagonal derecha superior


	return retnum;
 }
void comer(char**& tablero,int x,int y ,char sign){
	if(sign=='+'){
	if(x-1>=0){
	if(tablero[x-1][y]=='#'){
        tablero[x-1][y]='+';
        }}//abajo
	if(x+1<11){
        if(tablero[x+1][y]=='#'){
        tablero[x+1][y]='+';
        }}//arriba
	if(y+1<11){
        if(tablero[x][y+1]=='#'){
        tablero[x][y+1]= '+';
        }}//izquierda
	if(y-1>=0){
        if(tablero[x][y-1]=='#'){
        tablero[x][y-1]='+';
        }}//derecha
	if(y-1>=0&&x-1>=0){
        if(tablero[x-1][y-1]=='#'){
        tablero[x-1][y-1]= '+';
        }}//diagonal derecha inferior
	if(y+1<11&&x-1>=0){
        if(tablero[x-1][y+1]=='#'){
        tablero[x-1][y+1]='+';
        }}//diagonal izquierda inferior
	if(y+1<11&&x+1<11){
        if(tablero[x+1][y+1]=='#'){
        tablero[x+1][y+1]='+';
        }}//diagonal izquierda superior
	if(y-1>=0&&x+1<11){
        if(tablero[x+1][y-1]=='#'){
        tablero[x+1][y-1]='+';
        }}//diagonal derecha superior
	}

	if(sign=='#'){
        if(x-1>=0){
        if(tablero[x-1][y]=='+'){
        tablero[x-1][y]='#';
        }}//abajo
        if(x+1<11){
        if(tablero[x+1][y]=='+'){
        tablero[x+1][y]='#';
        }}//arriba
        if(y+1<11){
        if(tablero[x][y+1]=='+'){
        tablero[x][y+1]='#';
        }}//izquierda
        if(y-1>=0){
        if(tablero[x][y-1]=='+'){
        tablero[x][y-1]='#';
        }}//derecha
        if(y-1>=0&&x-1>=0){
        if(tablero[x-1][y-1]=='+'){
        tablero[x-1][y-1]= '#';
        }}//diagonal derecha inferior
        if(y+1<11&&x-1>=0){
        if(tablero[x-1][y+1]=='+'){
        tablero[x-1][y+1]='#';
        }}//diagonal izquierda inferior
        if(y+1<11&&x+1<11){
        if(tablero[x+1][y+1]=='+'){
        tablero[x+1][y+1]='#';
        }}//diagonal izquierda superior
        if(y-1>=0&&x+1<11){
        if(tablero[x+1][y-1]=='+'){
        tablero[x+1][y-1]='#';
        }}//diagonal derecha superior
        }

	
}


