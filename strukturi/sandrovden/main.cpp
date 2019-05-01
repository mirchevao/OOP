#include <iostream>
#include<cstring>

using namespace std;
struct rekviziti
{
    int baloni;
    float litrialkohol;
    float kgjadenje;
    int loncinja;
    int tanjircinja;
};
struct gosti
{
    char imeprezime[50];
}gost;
struct poganenje
{
    int parovi;
    char mestazapoganenje[50]; //primer: peralna, umivalnik..
    char poganiigri[50]; //flip the cup, kings cup..


}pog;
struct playlist
{
    int br;
    char pesni[1000];
    char zanr[30];
}play;


int main()
{
    struct rekviziti rek;
    cout<<"Hello Sandra."<<endl<<"Welcome to your birthday structure."<<endl<<"I hope you'll have fun playing with it, like I like playing with sticks :)."<<endl<<"Please follow the instructions carefully."<<endl<<"I wish you a happy birthday, let the fun begin."<<endl;
    cout<<"Please enter the following party supplies in the exact same order: number of balloons (int), liters of alcohol (float), kilograms of food (float), number of cups (LONCHINJA) (int) and number of plates (int)."<<endl;
    cin>>rek.baloni>>rek.litrialkohol>>rek.kgjadenje>>rek.loncinja>>rek.tanjircinja<<endl;
    cout<<"Excellent!. Take a look at your structure!"<<endl;
    cout<<rek.baloni<<endl<<rek.litrialkohol<<endl<<rek.kgjadenje<<endl<<rek.loncinja<<endl<<rek.tanjircinja<<endl;




    return 0;
}
