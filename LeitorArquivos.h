#ifndef LEITORARQUIVOS_H
#define LEITORARQUIVOS_H
#include <vector>
#include "FiguraGeometrica.h"
#include <string>

class Leitorarquivos {
    int dimX, dimY, dimZ;
    float r, g, b, a;
public:
    Leitorarquivos() {}
    std::vector <FiguraGeometrica *> parse(std::string filename);
    int getDx();
    int getDy();
    int getDz();
};

#endif // LEITORARQUIVOS_H
