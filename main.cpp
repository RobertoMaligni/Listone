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


int main() {
    Listone *listone = Listone::getInstance();
    while(listone->isRunning()){
        listone->draw();
        std::string line;
        std::getline( std::cin, line );
        listone->handleInput(line);
    }
    return 0;
}
