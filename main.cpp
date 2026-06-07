#include "LeitorArquivos.h"
#include <iostream>
#include <cstdlib>
#include "Sculptor.h"


int main(){
    Sculptor *t1;
    Leitorarquivos dg;

    std :: vector <FiguraGeometrica *> figs;
    figs = dg.parse("entrada.txt");
    t1 = new Sculptor(dg.getDx(), dg.getDy(), dg.getDz());

    for(int i = 0; (int) i < figs.size(); i++){
        std::cout << "desenhando" << std::endl;
        figs[i] ->draw(*t1);
    }

    t1 -> writeOFF("Desenho.off");
    for(int i = 0; (int) i < figs.size(); i++){
        delete figs[i];
    }

    delete t1;

    std::cout << "Abrindo no meshlab..." << std::endl;

    system("start Desenho.off");

    return 0;
}
