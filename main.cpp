#include "LeitorArquivos.h"
#include <iostream>
#include "Sculptor.h"
#include <fstream>
#include <sstream>
#include "putVoxel.h"
#include "cutVoxel.h"
#include "putBox.h"
#include "cutBox.h"
#include "putSphere.h"
#include "cutSphere.h"
#include "putEllipsoid.h"
#include "cutEllipsoid.h"


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


    return 0;
}
