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

    int nOrdini = 0;
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
                int quantita = 1;
                cout << "Tipi di pizze disponibili:" << endl
                << "1. " << Nome::boscaiola << endl
                << "2. " << Nome::crostino << endl
                << "3. " << Nome::diavola << endl
                << "4. " << Nome::margherita << endl
                << "5. Torna Indietro" << endl;
                cin >> choice;
                try{
                    switch(choice){
                        case '1':{
                            int tipo;
                            ordine[nOrdini].setNome(Nome::boscaiola);
                            cout << "Selezionate il tipo: " << endl
                                    << "1. " << Tipo::bianca << endl
                                    << "2. " << Tipo::rossa << endl;
                            cin >> choice;
                            switch (choice){
                            case '1':{
                                tipo = 1;
                                break;
                            }
                            case '2':{
                                tipo = 2;
                                break;
                            }
                            }
                            cout << "Quantita? ";
                            cin >> quantita;
                            for(int i = 0; i < quantita; ++i){
                                if(tipo == 1){
                                    ordine[nOrdini].setTipo(Tipo::bianca);
                                }else {
                                    ordine[nOrdini].setTipo(Tipo::rossa);
                                }
                                ++nOrdini;
                            }
                            break;
                        }
                        case '2':{
                            cout << "Quantita? ";
                            cin >> quantita;
                            for(int i = 0; i < quantita; ++i){
                                ordine[nOrdini].setNome(Nome::crostino);
                                ordine[nOrdini].setTipo(Tipo::bianca);
                                ++nOrdini;
                            }
                            break;
                        }
                        case '3':{
                            cout << "Quantita? ";
                            cin >> quantita;
                            for(int i = 0; i < quantita; ++i){
                                ordine[nOrdini].setNome(Nome::diavola);
                                ordine[nOrdini].setTipo(Tipo::rossa);
                                ++nOrdini;
                            }
                            break;
                        }
                        case '4':{
                            cout << "Quantita? ";
                            cin >> quantita;
                            for(int i = 0; i < quantita; ++i){
                                ordine[nOrdini].setNome(Nome::margherita);
                                ordine[nOrdini].setTipo(Tipo::rossa);
                                ++nOrdini;
                            }
                            break;
                        }
                    }
                }catch(PizzaNonValida(err)){
                    cout << err.msg << endl;
                }
                break;
            }
            case '2':{
                float conto = 0;
                for(int i = 0; i < nOrdini; ++i){
                    conto += ordine[i].getPrezzo();
                }
                cout << "Il conto e' di: " << conto << " Euro" << endl;
                break;
            }
        case 'q':{
            cout << "Arrivederci!" << endl;
            return 0;
            break;
        }
        default :{
            cout << "Numero non valido" << endl;
        }
        }
    }

    return 0;
}