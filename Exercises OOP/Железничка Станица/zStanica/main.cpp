#include<iostream>
#include <cstring>
using namespace std;

struct Voz {
    char relation[50];
    int km;
    int passengers;
};

struct ZeleznickaStanica {
    char cityName[20];
    Voz trains[30];
    int numberOfTrains;
};

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad) {
    int swapped;
    int TEMP = 0;
    for(int i = 0; i < n; i++) {
        if(strcmp(zs[i].cityName, grad) == 0) {
            TEMP = i;
            while(1) {
                swapped = 0;

                for(int j = 0; j < zs[i].numberOfTrains - 1; j++) {
                    if(zs[i].trains[j].km < zs[i].trains[j + 1].km) {

                        int temp = zs[i].trains[j].km;  // BEGIN SWAPPING KILOMETERS
                        zs[i].trains[j].km = zs[i].trains[j + 1].km;
                        zs[i].trains[j + 1].km = temp;  //  END SWAPPING KILOMETERS

                        char tempo[50]; // BEGIN SWAPPING RELATION
                        strcpy(tempo, zs[i].trains[j].relation);
                        strcpy(zs[i].trains[j].relation, zs[i].trains[j + 1].relation);
                        strcpy(zs[i].trains[j + 1].relation, tempo);    // END SWAPPING RELATION

                        int temporary = zs[i].trains[j].passengers; // BEGIN SWAPPING PASSENGERS
                        zs[i].trains[j].passengers = zs[i].trains[j + 1].passengers;
                        zs[i].trains[j + 1].passengers = temp;  // END SWAPPING PASSENGERS
                        swapped = 1;
                    }


                }

                if(swapped == 0) {
                    break;
                }
            }

        }
    }
    cout << "Najkratka relacija: " << zs[TEMP].trains[zs[TEMP].numberOfTrains - 1].relation << " (" << zs[TEMP].trains[zs[TEMP].numberOfTrains - 1].km << " km)" << endl;
}

int main(){

    int n;
    cin>>n; //se cita brojot na zelezlnichki stanici

    ZeleznickaStanica zStanica[100];
    for (int i=0;i<n;i++){
        char nameCity[20];  int trainsNumber;
        cin >> nameCity;    cin >> trainsNumber;
        strcpy(zStanica[i].cityName, nameCity);
        zStanica[i].numberOfTrains = trainsNumber;

        for(int j = 0; j < zStanica[i].numberOfTrains; j++) {
            char rel[50];   int kilom;  int passenger;
            cin >> rel;     cin >> kilom;   cin >> passenger;
            strcpy(zStanica[i].trains[j].relation, rel);
            zStanica[i].trains[j].km = kilom;
            zStanica[i].trains[j].passengers = passenger;
        }
    }

    char grad[25];
    cin>>grad;

    najkratkaRelacija(zStanica,n,grad);
    return 0;
}
