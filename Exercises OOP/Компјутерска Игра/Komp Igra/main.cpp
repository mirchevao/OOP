#include <iostream>
#include <cstring>
using namespace std;

struct Igrac {
    char name[15];
    int level;
    int points;
};

struct KompjuterskaIgra {
    char gName[20];
    Igrac ig[30];
    int playersCount;
};

void najdobarIgrac(KompjuterskaIgra *lista, int n) {
    KompjuterskaIgra mostPlayed;
    mostPlayed.playersCount = 0;

    for(int i = 0; i < n; i++) {
        if(lista[i].playersCount > mostPlayed.playersCount) {
            mostPlayed = lista[i];
        }
    }

    Igrac bestPlayer;
    bestPlayer.points = 0;  bestPlayer.level = 0;

    for(int i = 0; i < mostPlayed.playersCount; i++) {
        if(mostPlayed.ig[i].points > bestPlayer.points) {
            bestPlayer = mostPlayed.ig[i];
        }
    }

    cout << "Najdobar igrac e igracot so korisnicko ime " << bestPlayer.name << " koj ja igra igrata " << mostPlayed.gName << endl;
}

int main(){

    int n;
    cin>>n; //se cita brojot na igri

    KompjuterskaIgra igri[100];
    for (int i=0;i<n;i++){
        char gameName[20];  int gamePlayers;
        cin >> gameName;    cin >> gamePlayers;

        strcpy(igri[i].gName, gameName);
        igri[i].playersCount = gamePlayers;

        for(int j = 0; j < gamePlayers; j++) {
            char playerName[15];    int playerLevel;    int playerPoints;
            cin >> playerName;      cin >> playerLevel; cin >> playerPoints;

            strcpy(igri[i].ig[j].name, playerName);
            igri[i].ig[j].level = playerLevel;
            igri[i].ig[j].points = playerPoints;
        }
    }

    najdobarIgrac(igri,n);
    return 0;
}
