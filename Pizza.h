#ifndef PIZZA_H
#define PIZZA_H
#include "funzioni.h"

constexpr float prezzoMargherita = 6.99;
constexpr float prezzoBoscaiola = 9.99;
constexpr float prezzoDiavola = 11.99;
constexpr float prezzoCrostino = 12.99;

class PizzaNonValida{
    public:
    string msg;
    PizzaNonValida(){};
    PizzaNonValida(string n_msg) : msg(n_msg){};
};

enum class Tipo{
    bianca, rossa
};

enum class Nome{
    boscaiola, margherita, crostino, diavola,
};

class Pizza{
    private:
    float prezzo;
    Nome nome;
    Tipo tipo;

    public:
    Nome getNome()const {return nome;}
    Tipo getTipo()const {return tipo;}
    float getPrezzo()const {return prezzo;}

    Pizza(){};
    Pizza (Nome n, Tipo t) : nome{n}, tipo {t}{
        switch (nome){
            case Nome::margherita :{
                prezzo = prezzoMargherita;
                if(t == Tipo::bianca){
                    throw PizzaNonValida{"Margherita non puo essere bainca"};
                }
                break;
            }
            case Nome::boscaiola :{
                prezzo = prezzoBoscaiola;
                break;
            }
            case Nome::diavola :{
                prezzo = prezzoDiavola;
                if(t == Tipo::bianca){
                    throw PizzaNonValida{"Diavola non puo essere bianca"};
                }
                break;
            }
            case Nome::crostino :{
                prezzo = prezzoCrostino;
                if(t == Tipo::rossa){
                    throw PizzaNonValida{"Crosino non puo essere rosso"};
                }
                break;
            }
        }
    };
    Pizza (Nome n) : nome{n}{
        switch (nome){
            case Nome::margherita :{
                prezzo = prezzoMargherita;
                tipo = Tipo::rossa;
                break;
            }
            case Nome::boscaiola :{
                prezzo = prezzoBoscaiola;
                tipo = Tipo::bianca;
                break;
            }
            case Nome::diavola :{
                prezzo = prezzoDiavola;
                tipo = Tipo::rossa;
                break;
            }
            case Nome::crostino :{
                prezzo = prezzoCrostino;
                tipo = Tipo::bianca;
                break;
            }
        }
    };

    void setNome (Nome nuovoNome){
        nome = nuovoNome;
        switch (nome){
            case Nome::margherita :{
                prezzo = prezzoMargherita;
                tipo = Tipo::rossa;
                break;
            }
            case Nome::boscaiola :{
                prezzo = prezzoBoscaiola;
                tipo = Tipo::bianca;
                break;
            }
            case Nome::diavola :{
                prezzo = prezzoDiavola;
                tipo = Tipo::rossa;
                break;
            }
            case Nome::crostino :{
                prezzo = prezzoCrostino;
                tipo = Tipo::bianca;
                break;
            }
        }
    }
    void setTipo (Tipo nuovoTipo){
        tipo = nuovoTipo;
        switch (tipo){
            case Tipo::rossa :{
                if(nome == Nome::crostino){
                    throw PizzaNonValida("Crostino non puo essere rosso");    
                }
                break;
            }
            case Tipo::bianca :{
                if(nome == Nome::margherita || nome == Nome::diavola){
                    throw PizzaNonValida("Margherita o diavola non possono essere bianche");
                }
                break;
            }
        }
    }

};

ostream& operator<<(ostream& out, Nome nome){
    switch (nome){
        case Nome::margherita :{
            out << "Margherita";
            break;
        }
        case Nome::boscaiola :{
            out << "Boscaiola";
            break;
        }
        case Nome::diavola :{
            out << "Diavola";
            break;
        }
        case Nome::crostino :{
            out << "Crostino";
            break;
        }
    };
    return out;
}

ostream& operator<<(ostream& out, Tipo tipo){
    switch(tipo){
        case Tipo::bianca :{
            out << "Bianca";
            break;
        }
        case Tipo::rossa :{
            out << "Rossa";
            break;
        }
    }
    return out;
}

ostream& operator<<(ostream& out, Pizza p){
    out << "Nome: " << p.getNome()
     <<"\nTipo: " << p.getTipo()
     << "\nPrezzo: " << p.getPrezzo() << " Euro" << endl;

     return out;
}

#endif