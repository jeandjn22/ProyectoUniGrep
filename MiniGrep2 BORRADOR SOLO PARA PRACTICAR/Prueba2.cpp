#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Archivo{
    string linea1;
    string linea2;
    string linea3;
    string linea4;
};

int main(){

    Archivo archivo [4];
    
    int count = 0;
    int nline = 0;
    string line, word;

    ifstream infile("Pruebagreptarea.txt",ifstream::in);
    ofstream outfile("Pruebagreptarea.txt",ofstream::out|ios_base::app);
    if(!outfile.is_open()||!infile.is_open()){
        cout<<"No se pudo abrir el archivo."<<endl;
        return 0;
    }

    while(getline(infile,line)){
        stringstream str(line);
        while(getline(str,word,',')){
            switch(count){
                case 0:
                    archivo[nline].linea1=word;
                    break;

                case 1:
                    archivo[nline].linea2=word;
                    break;  

                case 2:
                    archivo[nline].linea3=word;
                    break;

                case 3:
                    archivo[nline].linea4=word;
                    break;          
            }
            count++;
        }
        nline++;
        count=0;
    }

    for(int i=0; i<4; i++){
            cout<<"\033[1;32m"<<archivo[i].linea1<<"\033[0m"<<endl;
            cout<<"\033[1;32m"<<archivo[i].linea2<<"\033[0m"<<endl;
            cout<<"\033[1;32m"<<archivo[i].linea3<<"\033[0m"<<endl;
            cout<<"\033[1;32m"<<archivo[i].linea4<<"\033[0m"<<endl;  
    }
    cout<<"4 Concidencias en 4 lineas"<<endl;

    infile.close();
    outfile.close();

}
