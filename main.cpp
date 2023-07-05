#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Listone.h"

/**
 * Testo dell'elaborato:
 *
 * Classi che rappresentano una lista della spesa (es. Listonic):
 * un utente deve avere diverse liste della spesa dove segnare oggetti
 * da acquistare che appartengono a diverse categorie ed eventualmente
 * con quantità da acquistare. Is usa Observer per aggiornare il numero
 * di oggetti da acquistare in una lista e quali questi siano.
 * Si possono o avere più utenti che condividono la stessa lista
 *
 * */

void experiment(){
    std::string line;
    std::ifstream file("../Files/Users.txt");
    if(!file.is_open()){
        throw std::exception();
    }
    bool found = false;
    while(std::getline(file,line) && !found){
        std::replace(line.begin(), line.end(), ';', ' ');  // replace ':' by ' '
        std::stringstream ss(line);
        std::string token;
        while (ss >> token && !found){
            if(token == "FrancescoTotti")
                found = true;
        }
    }
    if(!found) {
        throw std::exception();
    }
}


int main() {
    std::cout << std::to_string(false) << std::endl;
    /*
    Listone* listone = Listone::getInstance();
    listone->loginUser("FrancescoTotti","password");
    */
    return 0;
}
