#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_M=50;

struct bmi{
    char desc[11];
    float value;
};

static char *Calcola(float h, float w){
    char* msg[MAX_M];
    bmi b{};

    b.value=(float) w/(h*h);
    //cout<<b.value<<endl;

    if(b.value<18.5) strcpy(b.desc," SOTTO");
    else if(b.value>25) strcpy(b.desc," SOVRA");
    else strcpy(b.desc," NORMO");

    snprintf(*msg,MAX_M, "%.1f", b.value);
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
    while(hd[i]!=EOF && wd[i]!=EOF){
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
