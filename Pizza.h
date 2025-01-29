#ifndef PIZZA_H
#define PIZZA_H
#include "funzioni.h"

constexpr float prezzoMargherita = 6.99;
constexpr float prezzoBoscaiola = 9.99;
constexpr float prezzoDiavola = 11.99;
constexpr float prezzoCrostino = 12.99;

class PizzaNonValida{

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

    Pizza (Nome n, Tipo t) : nome{n}, tipo {t}{
        switch (nome){
            case Nome::margherita :{
                prezzo = prezzoMargherita;
                if(t == Tipo::bianca){
                    throw PizzaNonValida{};
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
                    throw PizzaNonValida{};
                }
                break;
            }
            case Nome::crostino :{
                prezzo = prezzoCrostino;
                if(t == Tipo::rossa){
                    throw PizzaNonValida{};
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
                    throw PizzaNonValida();    
                }
            }
            case Tipo::bianca :{
                if(nome == Nome::margherita || nome == Nome::diavola){
                    throw PizzaNonValida();
                }
            }
        }
    }

};

#endif