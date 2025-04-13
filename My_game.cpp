#include <iostream>
#include <windows.h>
#include <cctype>
using namespace std;

pridejPredmet(string inventar[], int &pocet){
    char vyber;
    int o=0;
    if (pocet>=10){
        cout<<"Mate plny inventar, pokud chcete pridat predmet, tak musite nejdrive odebrat jiny predmet!"<<endl;
    } else {
        pocet = pocet + 1;
        cout<<"Predmety ktere lze pridat: "<<endl;
        cout<<"\t'Lekarna' - +10HP"<<endl;
        cout<<"\t'Elixir' - +5 utok"<<endl;
        cout<<"\t'Otrava' - -10HP"<<endl;
        cout<<"\t'Tajemny svitek' - nahodny efekt (+HP, -HP, +utok)"<<endl;
        do{
            cout<<"Vas vyber(podle prvniho pismene): ";
            cin>>vyber;
            vyber = tolower(vyber);
            switch(vyber){
            case 'l':
                cout<<"Lekarna(+10HP), pridan do inventaru na "<<pocet<<". misto!"<<endl;
                inventar[pocet-1]="Lekarna(+10 HP)";
                o=1;
                break;
            case 'e':
                cout<<"Elixir(+5 utok), pridan do inventaru na "<<pocet<<". misto!"<<endl;
                inventar[pocet-1]="Elixir(+5 utok)";
                o=1;
                break;
            case 'o':
                cout<<"Otrava(-10HP), pridan do inventaru na "<<pocet<<". misto!"<<endl;
                inventar[pocet-1]="Otrava(-10 HP)";
                o=1;
                break;
            case 't':
                cout<<"Tajemny svitek(???), pridan do inventaru na "<<pocet<<". misto!"<<endl;
                inventar[pocet-1]="Tajemny svitek(+HP, -HP, +utok)";
                o=1;
                break;
            default:
                cout<<"Zadali jste neplatne pismeno zkuste to znovu."<<endl;
            }
        } while (o==0);
    }
    cout<<endl;
}

odeberPredmet(string inventar[], int &pocet){
    int vyber;
    cout<<"Vyberte predmet ktery chcete odebrat: "<<endl;
    for(int i; i<=pocet-1; i++){
        cout<<"\t"<<i+1<<" - "<<inventar[i]<<endl;
    }
    cout<<"Vas vyber(cislo): ";
    cin>>vyber;
}

pouzijPredmet(string inventar[], int &pocet, int &zivoty, int &utok){}

vypisInventar(string inventar[], int pocet){
    int vyber;
    cout<<"Vas inventar: "<<endl;
    for(int i; i<=pocet-1; i++){
        cout<<"\t"<<i+1<<" - "<<inventar[i]<<endl;
    }
    cout<<"Pokracovat-znak_a_enter(cokoli): "<<endl;
    cin>>vyber;
}

inventarVyber(){
    int pocet = 10;
    string inventar[pocet];
    int zivoty = 100;
    int utok = 10;
    int o=1;
    int vyber;
    cout<<"\tFunkce-inventar: "<<endl;
    pocet = 0;
    while (o==1){
        cout<<"Co chcete provest s predmety: "<<endl;
        cout<<"\t1 - Pridat predmet"<<endl;
        cout<<"\t2 - Odebrat predmet"<<endl;
        cout<<"\t3 - Pouzit predmet"<<endl;
        cout<<"\t4 - Zobrazit inventar"<<endl;
        cout<<"\t5 - Ukoncit"<<endl;
        cout<<"Vas vyber: ";
        cin>>vyber;

        switch(vyber){
        case 1:
            pridejPredmet(inventar, pocet);
            break;
        case 2:
            odeberPredmet(inventar, pocet);
            break;
        case 3:
            pouzijPredmet(inventar, pocet, zivoty, utok);
            break;
        case 4:
            vypisInventar(inventar, pocet);
            break;
        case 5:
            o=0;
            break;
        default:
            cout<<"Zadali jste neplatnou hodnotu!"<<endl;
        }
    }
    cout<<"\tInventar uzavren!"<<endl;
}

vyberClassu(){
    int o;
    cout<<"\tTeď pro záchranu tohoto ostrova si musíte vybrat class!"<<endl;
    cout<<endl;
    do{
        cout<<"Zde jsou classy které si můžete vybrat:"<<endl;
        cout<<"\tPaladin"<<endl;
        cout<<"\tMág"<<endl;
        cout<<"\tLovec"<<endl;
    }while(o==0);
}


int main(){
    SetConsoleOutputCP(CP_UTF8);
    int zivoty, maxZivoty;
    int mana, maxMana;
    int utok;
    int gold;
    int level;
    int zkusenosti, potrebneZkusenosti;
    string schopnosti[10];

    char odpovedi1;
    int o;
    int rozvetveni = 0;

    cout<<"\tVítejte na ostrově který můžete zachránit!"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Chcete si poslechnout historii tohoto ostrova?(Ano-a, Ne-n)"<<endl;
    do {
        cout<<"Vaše odpověď: ";
        cin>>odpovedi1;
        odpovedi1 = tolower(odpovedi1);
        if (odpovedi1=='a'){
            o = 1;
            rozvetveni = 1;
        } else if (odpovedi1=='n'){
            o = 1;
            rozvetveni = 0;
        } else {
            cout<<"Zadali jste něco špatně, zkuste to znovu..."<<endl;
            o = 0;
        }
    } while (o==0);
    if (rozvetveni==1){
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
    } else if (rozvetveni==0){
        cout<<"Historii si poslechneme někdy jindy a teď jdeme na něco zajímavějšího..."<<endl;
    }

    cout<<endl;
    vyberClassu();

    cout<<"\tProgram ukončen!"<<endl;
}
