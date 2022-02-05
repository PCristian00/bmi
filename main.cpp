#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_M = 60;

struct bmi {
    char *desc;
    float value;
};

static char *Calcola(float h, float w) {
    char *msg[MAX_M];
    bmi b{};
    b.value = (float) w / (h * h);

    if (b.value < 18.5) b.desc = " Sottopeso";
    else if (b.value > 25) b.desc = " Sovrappeso";
    else b.desc = " Normale";

    snprintf(*msg, MAX_M, "%.2f", b.value);
    strcat(*msg, b.desc);

    return *msg;
}

int main() {

    fstream h, w, out;
    float hd[10], wd[10];
    int i = 0;
    char *line;

    h.open(R"(C:\Users\Thinkpad User\CLionProjects\bmi\altezza.txt)", ios::in);
    if (!h.is_open()) cout << "Errore apertura altezze." << endl;

    w.open(R"(C:\Users\Thinkpad User\CLionProjects\bmi\peso.txt)", ios::in);
    if (!w.is_open()) cout << "Errore apertura peso." << endl;

    out.open(R"(C:\Users\Thinkpad User\CLionProjects\bmi\BMI.txt)", ios::out);
    if (!out.is_open()) cout << "Errore apertura BMI." << endl;

    out << "BMI" << endl;
    cout << "BMI" << endl;

    while (h.good() && w.good()) {

        h >> hd[i];
        w >> wd[i];

        if (hd[i] == 0 || wd[i] == 0) {
            cout << endl << "Nessun'altra coppia di valori trovata. Chiusura." << endl;
            break;
        }

        line = Calcola(hd[i], wd[i]);

        out << "[" << i + 1 << "] ";
        out << line << endl;

        cout << "[" << i + 1 << "] ";
        cout << line << endl;

        i++;
    }
    return 0;
}
