#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct bmi{
    char desc[30];
    float value;
};

char *Calcola(float h, float w){
    char out[50];
    bmi b{};

    b.value=(float) w/(h*h);
    //TODO restituisce inf
    cout<<b.value<<endl;

    if(b.value<18.5) strcpy(b.desc,"\tSottopeso");
    else if(b.value>25) strcpy(b.desc,"\tSovrappeso");
    else strcpy(b.desc,"\tNormale");

    snprintf(out, 50, "%f", b.value);
    cout<<out<<endl;
    //value=(b.value);
    strcat(out,b.desc);
    cout<<"Sono nella funzione e il tuo BMI e' "<<endl;
    cout<<out;

    return out;
}

int main() {

    fstream h,w,out;
    float hd[10],wd[10];

    h.open("C:\\Users\\Thinkpad User\\CLionProjects\\bmi\\altezza.txt",ios::in);
    if(!h.is_open()) cout<<"Errore apertura altezze."<<endl;

    w.open("C:\\Users\\Thinkpad User\\CLionProjects\\bmi\\peso.txt",ios::in);
    if(!w.is_open()) cout<<"Errore apertura peso."<<endl;

    out.open("BMI.txt",ios::out);
    if(!out.is_open()) cout<<"Errore apertura BMI."<<endl;
//TODO non stampa
    out<<"\tBMI\t"<<endl;

    int i=0;
    while(h.good() && w.good()){
        h<<hd[i];
        if(hd[i]==0) cout<<"ehi che fai";
        w<<wd[i];
        if(wd[i]==0) cout<<"ehi che fai pesa poco";
        //TODO non fa nulla
        cout<<Calcola(hd[i],wd[i]);
        out<<Calcola(hd[i],wd[i]);
        i++;
    }
    return 0;
}
