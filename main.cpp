#include "funzioni.h"
#include "Pizza.h"
/*
fare una classe pizza con il nome,prezzo e tipo se bianca o rossa.
l'applicazione deve far poter scegliere all' utente uno o più prodotti specificando la quantità.
in ogni momento il cliente deve poter chiedere l'importo o lo scontrino.
*/
int main(){

    //Pizza cerlini {Nome::margherita, Tipo::rossa};
    //Pizza russo {Nome::boscaiola, Tipo::bianca};
    // cout << cerlini.getNome() << " " <<  cerlini.getTipo() << " " << cerlini.getPrezzo() << endl;
    //cout << russo << endl;

    int nOrdine = 0;
    Pizza ordine[100];

    char choice;
    while(choice != 'q'){
        cout << "Benvenuto nella pizzeria Vincy!" << endl
        << "1. Ordina una pizza" << endl
        << "2. Richiedi lo scontrino" << endl
        << "q. Esci" << endl;
        cin >> choice;
        switch(choice){
            case '1':{
                cout << "Tipi di pizze disponibili:" << endl
                << "1. " << Nome::boscaiola << endl
                << "2. " << Nome::crostino << endl
                << "3. " << Nome::diavola << endl
                << "4. " << Nome::margherita << endl
                << "5. Torna Indietro" << endl;
                cin >> choice;
                switch(choice){
                    case '1':{
                        ordine[nOrdine].setNome(Nome::boscaiola);
                        cout << "Selezionate il tipo: " << endl
                             << "1. " << Tipo::bianca << endl
                             << "2. " << Tipo::rossa << endl;
                        cin >> choice;
                        switch(choice){
                            case '1':{
                                ordine[nOrdine].setTipo(Tipo::bianca);
                                break;
                            }
                            case '2':{
                                ordine[nOrdine].setTipo(Tipo::rossa);
                                break;
                            }
                        }
                        ++nOrdine;
                    }
                    case '2':{
                        ordine[nOrdine].setNome(Nome::crostino);
                        ordine[nOrdine].setTipo(Tipo::bianca);
                        break;
                    }
                    }
                }
            }
        }
    }

}