#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct bmi{
    char desc[12];
    float value;
};

static char *Calcola(float h, float w){
    char* msg[50];
    bmi b{};

    b.value=(float) w/(h*h);
    //cout<<b.value<<endl;

    if(b.value<18.5) strcpy(b.desc," Sottopeso");
    else if(b.value>25) strcpy(b.desc," Sovrappeso");
    else strcpy(b.desc," Normale");

    snprintf(*msg, sizeof msg, "%.1f", b.value);
    //cout<<msg<<endl;
    //value=(b.value);
    strcat(*msg, b.desc);
   /*
    cout<<"Sono nella funzione e il tuo BMI e' "<<endl;
    cout<<msg<<endl;
    */
   //cout<<*msg;

    return *msg;
}

int main() {

    fstream h,w,out;
    float hd[10],wd[10];
    int i=0;
    char *line;

    h.open(R"(C:\Users\Thinkpad User\CLionProjects\bmi\altezza.txt)",ios::in);
    if(!h.is_open()) cout<<"Errore apertura altezze."<<endl;

    w.open(R"(C:\Users\Thinkpad User\CLionProjects\bmi\peso.txt)",ios::in);
    if(!w.is_open()) cout<<"Errore apertura peso."<<endl;

    out.open(R"(C:\Users\Thinkpad User\CLionProjects\bmi\BMI.txt)",ios::out);
    if(!out.is_open()) cout<<"Errore apertura BMI."<<endl;

    out<<"BMI"<<endl;
    //cout<<Calcola(2.3,4.5)<<endl;
    while(w&&h){
        //cout<<"Hola\t"<<i<<endl;
        h>>hd[i];
        w>>wd[i];
        line=Calcola(hd[i],wd[i]);
        out<<line<<endl;
        cout<<line<<endl;
        i++;
    }
    return 0;
}
