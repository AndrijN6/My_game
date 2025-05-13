#include <iostream>
#include <windows.h>
#include <cctype>
#include <cstdlib>
#include <ctime>
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
                cout<<"Lekarna(+10HP), pridana do inventaru na "<<pocet<<". misto!"<<endl;
                inventar[pocet-1]="Lekarna(+10 HP)";
                o=1;
                break;
            case 'e':
                cout<<"Elixir(+5 utok), pridan do inventaru na "<<pocet<<". misto!"<<endl;
                inventar[pocet-1]="Elixir(+5 utok)";
                o=1;
                break;
            case 'o':
                cout<<"Otrava(-10HP), pridana do inventaru na "<<pocet<<". misto!"<<endl;
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
    int vyber1;
    cout<<"Vyberte predmet ktery chcete odebrat: "<<endl;
    for(int i=0; i<pocet; i++){
        cout<<"\t"<<i+1<<" - "<<inventar[i]<<endl;
    }
    do{
        cout<<"Vas vyber(cislo): ";
        cin>>vyber1;
    } while (vyber1<0&&vyber1>pocet);
    for(int i=0; i<pocet; i++){
        if (vyber1<i+1){
            inventar[i-1]=inventar[i];
        }
    }
    cout<<"Predmet c."<<vyber1<<" byl uspesne odebran z inventaru!"<<endl;
    cout<<endl;
    pocet = pocet - 1;
}

pouzijPredmet(string inventar[], int &pocet, int &zivoty, int &utok){
    int vyber1;
    cout<<"Vyberte predmet ktery chcete vyuzit: "<<endl;
    for(int i=0; i<pocet; i++){
        cout<<"\t"<<i+1<<" - "<<inventar[i]<<endl;
    }
    do{
        cout<<"Vas vyber(cislo): ";
        cin>>vyber1;
    } while (vyber1<0&&vyber1>pocet);

    cout<<"Predmet c."<<vyber1<<" byl uspesne vyuzit!"<<endl;
    if(inventar[vyber1-1]=="Lekarna(+10 HP)"){
        zivoty=zivoty+10;
        cout<<"Zivoty zvetseny o 10, prave ted mate "<<zivoty<<"HP."<<endl;
    } else if(inventar[vyber1-1]=="Elixir(+5 utok)"){
        utok=utok+5;
        cout<<"Utok zvetsen o 5, prave ted mate "<<utok<<" utoku."<<endl;
    } else if(inventar[vyber1-1]=="Otrava(-10 HP)"){
        zivoty=zivoty-10;
        cout<<"Zivoty zmenseny o 10, prave ted mate "<<zivoty<<"HP."<<endl;
    } else if(inventar[vyber1-1]=="Tajemny svitek(+HP, -HP, +utok)"){
        srand(static_cast<unsigned>(time(0)));
        int R = rand() % 3 + 1;
        if (R==1){
            zivoty=zivoty+10;
            cout<<"Zivoty zvetseny o 10, prave ted mate "<<zivoty<<"HP."<<endl;
        } else if (R==2){
            zivoty=zivoty-10;
            cout<<"Zivoty zmenseny o 10, prave ted mate "<<zivoty<<"HP."<<endl;
        } else if (R==3){
            utok=utok+10;
            cout<<"Utok zvetsen o 10, prave ted mate "<<utok<<" utoku."<<endl;
        }
    }

    for(int i=0; i<pocet; i++){
        if (vyber1<i+1){
            inventar[i-1]=inventar[i];
        }
    }
    cout<<endl;
    pocet = pocet - 1;
}

vypisInventar(string inventar[], int pocet){
    int vyber;
    cout<<"Vas inventar: "<<endl;
    for(int i=0; i<pocet; i++){
        cout<<"\t"<<i+1<<" - "<<inventar[i]<<endl;
    }
    cout<<endl;
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

vyberClassu(string classa[], int &maxZivoty, int &maxMana, int &utok, string schopnosti[]){
    int o=0, oo=0, ooo=0;
    char vyber, vyber2;
    cout<<"\tTeď pro záchranu tohoto ostrova si musíte vybrat classu!"<<endl;
    cout<<endl;
    do{
        cout<<"Zde jsou classy které si můžete vybrat: "<<endl;
        cout<<"\tP-Paladin"<<endl;
        cout<<"\tM-Mág"<<endl;
        cout<<"\tL-Lovec"<<endl;
        cout<<"\tZ-Zloděj"<<endl;
        do{
            cout<<"Váš výběr: ";
            cin>>vyber;
            vyber = tolower(vyber);
            switch(vyber){
            case 'p':
                cout<<"Class: Paladin"<<endl;
                cout<<endl;
                cout<<"Statistika: "<<endl;
                cout<<"\tŽivoty - 15/15"<<endl;
                cout<<"\tÚtok - 15"<<endl;
                cout<<"\tMana - 10/10"<<endl;
                cout<<endl;
                cout<<"Schopnosti: "<<endl;
                cout<<"\tAura - 200% poškození 1 nepřáteli za 2 many"<<endl;
                cout<<"\tSvatý útok - 50% poškození všem nepřátelům za 3 many"<<endl;
                cout<<"\tOživení - vyléčíš si 20% životů za 2 many"<<endl;
                cout<<endl;
                cout<<endl;
                do{
                    cout<<"Chcete si zvolit tuto classu nebo se vrátit k výběru mezi všemi classami?"<<endl;
                    cout<<"A - ano, zvolit tuto / N - ne, pokračovat ve výběru"<<endl;
                    cout<<"Váš výběr: ";
                    cin>>vyber2;
                    vyber2 = tolower(vyber2);
                    if (vyber2 == 'a'){
                        classa[0] = "Paladin";
                        maxZivoty = 15;
                        utok = 15;
                        maxMana = 10;
                        schopnosti[0] = "Aura - 200% poškození 1 nepřáteli za 2 many";
                        schopnosti[1] = "Svatý útok - 50% poškození všem nepřátelům za 3 many";
                        schopnosti[2] = "Oživení - vyléčíš si 20% životů za 2 many";
                        cout<<"Class je úspěšně vybrán, váš class: "<<classa[0]<<endl;
                        o=1;
                        oo=1;
                        ooo=1;
                    } else if(vyber2 == 'n'){
                        cout<<"Jistě, zde je výběr: "<<endl;
                        oo=1;
                        ooo=1;
                    } else{
                        cout<<"Toto písmeno tu není, vyberte 1. písmeno, tedy A nebo N."<<endl;
                        ooo=0;
                    }
                }while(ooo==0);
                break;
            case 'm':
                cout<<"Class: Mág"<<endl;
                cout<<endl;
                cout<<"Statistika: "<<endl;
                cout<<"\tŽivoty - 10/10"<<endl;
                cout<<"\tÚtok - 15"<<endl;
                cout<<"\tMana - 15/15"<<endl;
                cout<<endl;
                cout<<"Schopnosti: "<<endl;
                cout<<"\tOhnivá koule - 300% poškození 1 nepřáteli za 4 many"<<endl;
                cout<<"\tOhnivé pole - 100% poškození všem nepřátelům za 5 many"<<endl;
                cout<<"\tProkletí - příští poškození od nepřítele je o 50% slabší za 3 many"<<endl;
                cout<<endl;
                do{
                    cout<<"Chcete si zvolit tuto classu nebo se vrátit k výběru mezi všemi classami?"<<endl;
                    cout<<"A - ano, zvolit tuto / N - ne, pokračovat ve výběru"<<endl;
                    cout<<"Váš výběr: ";
                    cin>>vyber2;
                    vyber2 = tolower(vyber2);
                    if (vyber2 == 'a'){
                        classa[0] = "Mág";
                        maxZivoty = 10;
                        utok = 15;
                        maxMana = 15;
                        schopnosti[0] = "Ohnivá koule - 300% poškození 1 nepřáteli za 4 many";
                        schopnosti[1] = "Ohnivé pole - 100% poškození všem nepřátelům za 5 many";
                        schopnosti[2] = "Prokletí - příští poškození od nepřítele je o 50% slabší za 3 many";
                        cout<<"Class je úspěšně vybrán, váš class: "<<classa[0]<<endl;
                        o=1;
                        oo=1;
                        ooo=1;
                    } else if(vyber2 == 'n'){
                        cout<<"Jistě, zde je výběr: "<<endl;
                        oo=1;
                        ooo=1;
                    } else{
                        cout<<"Toto písmeno tu není, vyberte 1. písmeno, tedy A nebo N."<<endl;
                        ooo=0;
                    }
                }while(ooo==0);
                break;
            case 'l':
                cout<<"Class: Lovec"<<endl;
                cout<<endl;
                cout<<"Statistika: "<<endl;
                cout<<"\tŽivoty - 18/18"<<endl;
                cout<<"\tÚtok - 12"<<endl;
                cout<<"\tMana - 10/10"<<endl;
                cout<<endl;
                cout<<"Schopnosti: "<<endl;
                cout<<"\tVýstřel - na střelu naneseš přírodní element a naneseš nepříteli 200% poškození za 3 many"<<endl;
                cout<<"\tLéčení - vyléčíš si 10% životů přírodním elementem za 2 many"<<endl;
                cout<<"\tPast - každý příští útok nepřítel s šancí 33% stoupne do pasti dostane 10 poškození a jeho útok se sníží o 33%"<<endl;
                cout<<endl;
                do{
                    cout<<"Chcete si zvolit tuto classu nebo se vrátit k výběru mezi všemi classami?"<<endl;
                    cout<<"A - ano, zvolit tuto / N - ne, pokračovat ve výběru"<<endl;
                    cout<<"Váš výběr: ";
                    cin>>vyber2;
                    vyber2 = tolower(vyber2);
                    if (vyber2 == 'a'){
                        classa[0] = "Lovec";
                        maxZivoty = 18;
                        utok = 12;
                        maxMana = 10;
                        schopnosti[0] = "Výstřel - na střelu naneseš přírodní element a naneseš nepříteli 200% poškození za 3 many";
                        schopnosti[1] = "Léčení - vyléčíš si 10% životů přírodním elementem za 2 many";
                        schopnosti[2] = "Past - každý příští útok nepřítel s šancí 33% stoupne do pasti dostane 10 poškození a jeho útok se sníží o 33%";
                        cout<<"Class je úspěšně vybrán, váš class: "<<classa[0]<<endl;
                        o=1;
                        oo=1;
                        ooo=1;
                    } else if(vyber2 == 'n'){
                        cout<<"Jistě, zde je výběr: "<<endl;
                        oo=1;
                        ooo=1;
                    } else{
                        cout<<"Toto písmeno tu není, vyberte 1. písmeno, tedy A nebo N."<<endl;
                        ooo=0;
                    }
                }while(ooo==0);
                break;
            case 'z':
                cout<<"Class: Zloděj"<<endl;
                cout<<endl;
                cout<<"Statistika: "<<endl;
                cout<<"\tŽivoty - 12/12"<<endl;
                cout<<"\tÚtok - 18"<<endl;
                cout<<"\tMana - 10/10"<<endl;
                cout<<endl;
                cout<<"Schopnosti: "<<endl;
                cout<<"\tSkrytí- s 50% šancí nepřítel na vás nezaútočí za 3 many"<<endl;
                cout<<"\tRychlý útok- s 80% šancí provedete 2. útok a s 10% šancí i 3. útok za 3 many"<<endl;
                cout<<"\tKritický útok - nanesete 200% poškození a s šancí v 25% nanesete 300% poškození za 2 many"<<endl;
                cout<<endl;
                do{
                    cout<<"Chcete si zvolit tuto classu nebo se vrátit k výběru mezi všemi classami?"<<endl;
                    cout<<"A - ano, zvolit tuto / N - ne, pokračovat ve výběru"<<endl;
                    cout<<"Váš výběr: ";
                    cin>>vyber2;
                    vyber2 = tolower(vyber2);
                    if (vyber2 == 'a'){
                        classa[0] = "Zloděj";
                        maxZivoty = 12;
                        utok = 18;
                        maxMana = 10;
                        schopnosti[0] = "Skrytí- s 50% šancí nepřítel na vás nezaútočí za 3 many";
                        schopnosti[1] = "Rychlý útok- s 80% šancí provedete 2. útok a s 10% šancí i 3. útok za 3 many";
                        schopnosti[2] = "Kritický útok - nanesete 200% poškození a s šancí v 25% nanesete 300% poškození za 2 many";
                        cout<<"Class je úspěšně vybrán, váš class: "<<classa[0]<<endl;
                        o=1;
                        oo=1;
                        ooo=1;
                    } else if(vyber2 == 'n'){
                        cout<<"Jistě, zde je výběr: "<<endl;
                        oo=1;
                        ooo=1;
                    } else{
                        cout<<"Toto písmeno tu není, vyberte 1. písmeno, tedy A nebo N."<<endl;
                        ooo=0;
                    }
                }while(ooo==0);
                break;
            default:
                cout<<"Toto písmeno tu není, vyberte 1. písmeno od názvu classy."<<endl;
                oo=0;
            }
        } while (oo==0);
    }while(o==0);
}

statistika(string jmeno[], string classa[], int &zivoty, int &maxZivoty, int &mana, int &maxMana, int &utok, int &gold, int &level, int &zkusenosti, int &potrebneZkusenosti, string schopnosti[], int &pocetSchopnosti, int &bonusStaty, int &bonusUzite){
    int o, oo = 1, ooo;
    char odpovedi1, odpovedi4;
    int odpovedi2, odpovedi3;
    while(zkusenosti>=potrebneZkusenosti){
        level = level + 1;
        zkusenosti = zkusenosti - potrebneZkusenosti;
        bonusStaty = bonusStaty + 10;
        bonusUzite = bonusUzite + 1;
        if(bonusUzite==1){
            potrebneZkusenosti = 10;
        }else if(bonusUzite==2){
            potrebneZkusenosti = 20;
        }else if(bonusUzite==3){
            potrebneZkusenosti = 40;
        }else if(bonusUzite==4){
            potrebneZkusenosti = 70;
        }else if(bonusUzite==5){
            potrebneZkusenosti = 150;
        }else if(bonusUzite==6){
            potrebneZkusenosti = 250;
        }else if(bonusUzite==7){
            potrebneZkusenosti = 400;
        }else if(bonusUzite==8){
            potrebneZkusenosti = 750;
        }
    }


    cout<<"\t---STATUS---"<<endl;
    cout<<endl;
    cout<<"Jméno: "<<jmeno[0]<<"\tClass: "<<classa[0]<<endl;
    cout<<"Level: "<<level<<"\tZkušenosti: "<<zkusenosti<<"/"<<potrebneZkusenosti<<endl;
    cout<<"Statistiky: "<<endl;
    cout<<"\tŽivoty: "<<zivoty<<"/"<<maxZivoty<<endl;
    cout<<"\tÚtok: "<<utok<<endl;
    cout<<"\tMana: "<<mana<<"/"<<maxMana<<endl;
    cout<<"Schopnosti: "<<endl;
    for(int i=0; i<pocetSchopnosti; i++){
        cout<<"\t"<<schopnosti[i]<<endl;
    }
    cout<<"Zlato: "<<gold<<endl;
    cout<<endl;
    cout<<endl;


    cout<<"Staty k využití: "<<bonusStaty<<endl;
    cout<<"Chcete využít neužité staty?(Ano-a, Ne-n)"<<endl;
    do {
        cout<<"Vaše odpověď: ";
        cin>>odpovedi1;
        odpovedi1 = tolower(odpovedi1);
        if (odpovedi1=='a'){
            while (oo==1){
            cout<<"Kam chcete převést neužité staty?("<<bonusStaty<<")"<<endl;
            cout<<"\t1 - Životy"<<endl;
            cout<<"\t2 - Útok"<<endl;
            cout<<"\t3 - Mana"<<endl;
            cout<<"Váš výběr: ";
            cin>>odpovedi2;

            switch(odpovedi2){
            case 1:
                cout<<"O kolik chcete zvednout životy?"<<endl;
                cout<<"Váše odpověď: ";
                cin>>odpovedi3;
                if(odpovedi3<=bonusStaty){
                    bonusStaty = bonusStaty - odpovedi3;
                    maxZivoty = maxZivoty + odpovedi3;
                    zivoty = maxZivoty;
                    cout<<"Stat Životy byl úspěšně zvětšen o "<<odpovedi3<<"!"<<endl;
                    cout<<endl;
                    cout<<"Chcete pokračovat ve výběru?(Ano-a, Ne-n)"<<endl;
                    do{
                        cout<<"Vaše odpověď: ";
                        cin>>odpovedi4;
                        odpovedi4 = tolower(odpovedi4);
                        if(odpovedi4=='a'){
                            cout<<"Zde je výběr..."<<endl;
                            ooo = 0;
                        }else if(odpovedi4=='n'){
                            cout<<"Výběr ukončen."<<endl;
                            oo = 0;
                            ooo = 0;
                        }else{
                            ooo = 1;
                            cout<<"Zadali jste něco špatně..."<<endl;
                        }
                    }while(ooo==1);
                }else{
                    cout<<"Přesáhli jste hodnotu neužitých statů!"<<endl;
                    cout<<"Zkuste to znovu..."<<endl;
                }
                break;
            case 2:
                cout<<"O kolik chcete zvednout útok?"<<endl;
                cout<<"Váše odpověď: ";
                cin>>odpovedi3;
                if(odpovedi3<=bonusStaty){
                    bonusStaty = bonusStaty - odpovedi3;
                    maxZivoty = maxZivoty + odpovedi3;
                    zivoty = maxZivoty;
                    cout<<"Stat Útok byl úspěšně zvětšen o "<<odpovedi3<<"!"<<endl;
                    cout<<endl;
                    cout<<"Chcete pokračovat ve výběru?(Ano-a, Ne-n)"<<endl;
                    do{
                        cout<<"Vaše odpověď: ";
                        cin>>odpovedi4;
                        odpovedi4 = tolower(odpovedi4);
                        if(odpovedi4=='a'){
                            cout<<"Zde je výběr..."<<endl;
                            ooo = 0;
                        }else if(odpovedi4=='n'){
                            cout<<"Výběr ukončen."<<endl;
                            oo = 0;
                            ooo = 0;
                        }else{
                            ooo = 1;
                            cout<<"Zadali jste něco špatně..."<<endl;
                        }
                    }while(ooo==1);
                }else{
                    cout<<"Přesáhli jste hodnotu neužitých statů!"<<endl;
                    cout<<"Zkuste to znovu..."<<endl;
                }
                break;
            case 3:
                cout<<"O kolik chcete zvednout manu?"<<endl;
                cout<<"Váše odpověď: ";
                cin>>odpovedi3;
                if(odpovedi3<=bonusStaty){
                    bonusStaty = bonusStaty - odpovedi3;
                    maxZivoty = maxZivoty + odpovedi3;
                    zivoty = maxZivoty;
                    cout<<"Stat Mana byl úspěšně zvětšen o "<<odpovedi3<<"!"<<endl;
                    cout<<endl;
                    cout<<"Chcete pokračovat ve výběru?(Ano-a, Ne-n)"<<endl;
                    do{
                        cout<<"Vaše odpověď: ";
                        cin>>odpovedi4;
                        odpovedi4 = tolower(odpovedi4);
                        if(odpovedi4=='a'){
                            cout<<"Zde je výběr..."<<endl;
                            ooo = 0;
                        }else if(odpovedi4=='n'){
                            cout<<"Výběr ukončen."<<endl;
                            oo = 0;
                            ooo = 0;
                        }else{
                            ooo = 1;
                            cout<<"Zadali jste něco špatně..."<<endl;
                        }
                    }while(ooo==1);
                }else{
                    cout<<"Přesáhli jste hodnotu neužitých statů!"<<endl;
                    cout<<"Zkuste to znovu..."<<endl;
                }
                break;
            default:
                cout<<"Zadali jste neplatnou hodnotu!"<<endl;
            }
            }
            o = 1;
        } else if (odpovedi1=='n'){
            cout<<"Tak příště..."<<bonusStaty<<endl;
            o = 1;
        } else {
            cout<<"Zadali jste něco špatně..."<<endl;
            o = 0;
        }
    } while (o==0);
    cout<<endl;
    cout<<endl;
}

nejjlehciPriklad(){
    srand(time(0));
    int t = rand()%2+1;
    int a = rand()%10+1;
    int b = rand()%10+1;
    int c, odpoved, o = 1;

    cout<<"Nejjlehčí příklad: "<<endl;
    do{
        if(t==1){
            cout<<"\t"<<a<<" + "<<b<<" = ";
            cin>>odpoved;
            c = a+b;
            if(odpoved==c){
                cout<<"Správně!"<<endl;
                o = 0;
            } else{
                cout<<"Chyba, zkuste to znouvu!"<<endl;
                o = 1;
            }
        }else if(t==2){
            cout<<"\t"<<a<<" - "<<b<<" = ";
            cin>>odpoved;
            c = a-b;
            if(odpoved==c){
                cout<<"Správně!"<<endl;
                o = 0;
            } else{
                cout<<"Chyba, zkuste to znouvu!"<<endl;
                o = 1;
            }
        }
    }while(o==1);
}

lehkyPriklad(){
    srand(time(0));
    int t = rand()%4+1;
    int a = rand()%20+1;
    int b = rand()%20+1;
    int c, odpoved, o = 1, oo = 1;

    cout<<"Lehký příklad: "<<endl;
    do{
        if(t==1){
            cout<<"\t"<<a<<" + "<<b<<" = ";
            cin>>odpoved;
            c = a+b;
            if(odpoved==c){
                cout<<"Správně!"<<endl;
                o = 0;
            } else{
                cout<<"Chyba, zkuste to znouvu!"<<endl;
                o = 1;
            }
        }else if(t==2){
            cout<<"\t"<<a<<" - "<<b<<" = ";
            cin>>odpoved;
            c = a-b;
            if(odpoved==c){
                cout<<"Správně!"<<endl;
                o = 0;
            } else{
                cout<<"Chyba, zkuste to znouvu!"<<endl;
                o = 1;
            }
        }else if(t==3){
            cout<<"\t"<<a<<" * "<<b<<" = ";
            cin>>odpoved;
            c = a*b;
            if(odpoved==c){
                cout<<"Správně!"<<endl;
                o = 0;
            } else{
                cout<<"Chyba, zkuste to znouvu!"<<endl;
                o = 1;
            }
        }else if(t==4){
            do{
                if(a%b==0){
                    cout<<"\t"<<a<<" / "<<b<<" = ";
                    cin>>odpoved;
                    c = a/b;
                    if(odpoved==c){
                        cout<<"Správně!"<<endl;
                        o = 0;
                        oo = 0;
                    } else{
                        cout<<"Chyba, zkuste to znouvu!"<<endl;
                        o = 1;
                    }
                }else{
                    int a = rand()%20+1;
                    int b = rand()%20+1;
                    o = 1;
                }
            }while(oo==1);
        }
    }while(o==1);
}

stredniPriklad(){
    srand(time(0));
}

tezkyPriklad(){
    srand(time(0));
}

spani(int &zivoty, int &maxZivoty, int &mana, int &maxMana, int &gold){
    int o = 0, oo = 0, odpoved1, mezivypocet;
    char odpoved2;

    cout<<"Ahoj, vyber si kde se chceš vyspat!"<<endl;
    do {
        cout<<"Možnosti: "<<endl;
        cout<<"\t1 - Bar, regenerace 25% životů a many/za 5 zlaťáků a nejjlehčí příklad"<<endl;
        cout<<"\t2 - Hostinec, regenerace 50% životů a many/za 10 zlaťáků a lehký příklad"<<endl;
        cout<<"\t3 - Malý hotel, regenerace 75% životů a many/za 20 zlaťáků a střední příklad"<<endl;
        cout<<"\t4 - Velký hotel, regenerace 100% životů a many + 1 náhodná bonusová charakteristika/za 50 zlaťáků a těžký příklad"<<endl;
        cout<<"\t5 - Tentokrát ne, někdy jindy..."<<endl;

        cout<<"Vaše odpověď: ";
        cin>>odpoved1;

        switch(odpoved1){
        case 1:
            if(gold>=5){
                nejjlehciPriklad();
                cout<<endl;
                gold = gold-5;

                mezivypocet = zivoty/4;
                if(zivoty+mezivypocet<=maxZivoty){
                    zivoty = zivoty + mezivypocet;
                }else{
                    zivoty = maxZivoty;
                }

                mezivypocet = mana/4;
                if(mana+mezivypocet<=maxMana){
                    mana = mana + mezivypocet;
                }else{
                    mana = maxMana;
                }

                cout<<"...o 8 hodin později..."<<endl;
                cout<<"Vyspaly jste se za 5 zlaťáků, vaše životy a mana se vyregenerovaly na 25%!"<<endl;

                cout<<"Chcete jít spát ještě jednou?(Ano-a, Ne-n)"<<endl;
                do{
                    cout<<"Vaše odpověď: ";
                    cin>>odpoved2;
                    odpoved2 = tolower(odpoved2);
                    if (odpoved2=='a'){
                        o = 0;
                        oo = 1;
                    } else if (odpoved2=='n'){
                        cout<<"Spánek ukončen."<<endl;
                        o = 1;
                        oo = 1;
                    } else {
                        cout<<"Zadali jste něco špatně, zkuste to znovu..."<<endl;
                        oo = 0;
                    }
                }while(oo==0);
            }else{
                cout<<"Nemáte dost zlata, dnes se nevyspíte..."<<endl;
                o = 1;
            }
            break;
        case 2:
            if(gold>=10){
                lehkyPriklad();
                cout<<endl;
                gold = gold-10;

                mezivypocet = zivoty/2;
                if(zivoty+mezivypocet<=maxZivoty){
                    zivoty = zivoty + mezivypocet;
                }else{
                    zivoty = maxZivoty;
                }

                mezivypocet = mana/2;
                if(mana+mezivypocet<=maxMana){
                    mana = mana + mezivypocet;
                }else{
                    mana = maxMana;
                }

                cout<<"...o 8 hodin později..."<<endl;
                cout<<"Vyspaly jste se za 10 zlaťáků, vaše životy a mana se vyregenerovaly na 50%!"<<endl;

                cout<<"Chcete jít spát ještě jednou?(Ano-a, Ne-n)"<<endl;
                do{
                    cout<<"Vaše odpověď: ";
                    cin>>odpoved2;
                    odpoved2 = tolower(odpoved2);
                    if (odpoved2=='a'){
                        o = 0;
                        oo = 1;
                    } else if (odpoved2=='n'){
                        cout<<"Spánek ukončen."<<endl;
                        o = 1;
                        oo = 1;
                    } else {
                        cout<<"Zadali jste něco špatně, zkuste to znovu..."<<endl;
                        oo = 0;
                    }
                }while(oo==0);
            }else{
                cout<<"Nemáte dost zlata, dnes se nevyspíte..."<<endl;
                o = 1;
            }
            break;
        case 3:
            stredniPriklad();
            break;
        case 4:
            tezkyPriklad();
            break;
        case 5:
            break;
        default:
            cout<<"Zadal jsi něco špatně, zkus to znovu..."<<endl;
            o = 0;
        }
    } while (o==0);
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    string jmeno[1];
    string classa[1];
    int zivoty, maxZivoty;
    int mana, maxMana;
    int utok;
    int gold;
    int level;
    int zkusenosti, potrebneZkusenosti;
    string schopnosti[10];
    int pocetSchopnosti;
    int bonusStaty, bonusUzite=0;

    char odpovedi1;
    int o, oo;
    int rozvetveni = 0;

    int vyber;

    cout<<"\tVítejte na ostrově který můžete zachránit!"<<endl;
    cout<<endl;
    cout<<"Jaké je vaše jméno?"<<endl;
    cout<<"Jméno: ";
    cin>>jmeno[0];
    cout<<endl;
    cout<<"Chcete si poslechnout historii tohoto ostrova?(Ano-a, Ne-n)"<<endl;
    do {
        cout<<"Váš výběr: ";
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
        cout<<"Kdysi dávno před tisíselitími na tomto místě bylo čiré moře."<<endl;
        cout<<"Jednou však království Ardante zaútočilo na krále draků, "<<endl;
        cout<<"tím se započala kontinentální vláka lidstva proti králi draků."<<endl;
        cout<<"Válka pokračovala roky..., až z lidstva nezbyly skoro jen ruiny, "<<endl;
        cout<<"půlka draků zemřela a zraněný král draků vytvořil tento ostrov pro své vyzdravení."<<endl;
        cout<<"Tehdejší lidstvo bylo mnohemkrát pokročilejší, "<<endl;
        cout<<"a po té skáze jsme neměli na krále draků, který se tu léčí."<<endl;
        cout<<"Jak minuly ty tisíceletí, tak nikdo neví jestli je král draků stále živ, "<<endl;
        cout<<"ale jisté je, že jeho moc a aura napomáhá vznikat novým a silnějším monstrům, "<<endl;
        cout<<"a právě proto tu žijí nejčastěji zdatní bojovat nebo vojenské síly."<<endl;
        cout<<"No a jak je asi zřejmé, čím blíže se přiblížíte k centru ostrova, tím silnější nestvůry tam budou."<<endl;
        cout<<endl;
    } else if (rozvetveni==0){
        cout<<"Historii si poslechneme někdy jindy a teď jdeme na něco zajímavějšího..."<<endl;
    }

    cout<<endl;
    vyberClassu(classa, maxZivoty, maxMana, utok, schopnosti);
    zivoty = maxZivoty;
    mana = maxMana;
    level = 1;
    zkusenosti = 0;
    potrebneZkusenosti = 5;
    gold = 50;
    pocetSchopnosti = 3;

    o = 1;
    while(o==1){
        cout<<endl;
        cout<<"\t---VESTNICE---"<<endl;
        cout<<endl;
        cout<<""<<endl;

        oo = 1;
        while (oo==1){
            cout<<"Jak chcete pokračovat?"<<endl;
            cout<<"\t1 - Otevřít inventář"<<endl;
            cout<<"\t2 - Otevřít statistiku"<<endl;
            cout<<"\t3 - Jít nakoupit"<<endl;
            cout<<"\t4 - Vyspat se"<<endl;
            cout<<"\t5 - Jít do boje"<<endl;
            cout<<"Váš výběr: ";
            cin>>vyber;

            switch(vyber){
            case 1:
                inventarVyber();
                break;
            case 2:
                statistika(jmeno, classa, zivoty, maxZivoty, mana, maxMana, utok, gold, level, zkusenosti, potrebneZkusenosti, schopnosti, pocetSchopnosti, bonusStaty, bonusUzite);
                break;
            case 3:
                break;
            case 4:
                spani(zivoty, maxZivoty, mana, maxMana, gold);
                break;
            case 5:
                break;
            default:
                cout<<"Zadali jste neplatnou hodnotu!"<<endl;
            }
        }
    }


    cout<<"\tProgram ukončen!"<<endl;
}
