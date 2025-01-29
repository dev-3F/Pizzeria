#include "funzioni.h"
#include "Pizza.h"
/*
fare una classe pizza con il nome,prezzo e tipo se bianca o rossa.
l'applicazione deve far poter scegliere all' utente uno o più prodotti specificando la quantità.
in ogni momento il cliente deve poter chiedere l'importo o lo scontrino.
*/
int main(){

    Pizza cerlini {Nome::margherita, Tipo::rossa};
    Pizza russo {Nome::boscaiola, Tipo::bianca};
    // cout << cerlini.getNome() << " " <<  cerlini.getTipo() << " " << cerlini.getPrezzo() << endl;
    cout << cerlini.getPrezzo() << endl;
}