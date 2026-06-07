#include "LeitorArquivos.h"
#include <iostream>
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

    std::vector <FiguraGeometrica *> Leitorarquivos :: parse(std::string filename){
    std::vector <FiguraGeometrica *> figs;
    std::ifstream entrada;
    std::stringstream ss;
    std::string s, token;

    entrada.open(filename.c_str());

    std::cout << "Abrindo o arquivo " << filename << "..." << std::endl;
    if(!entrada.is_open()){
        std::cout << "Erro ao abrir o arquivo!\n";
        exit(0);
    }

    while(getline(entrada, s)){
        // Se a linha for vazia ou começar com comentário '#', pula para a próxima
        if(s.empty() || s[0] == '#') {
            continue;
        }

        ss.clear();
        ss.str(s);
        ss >> token;

        if(token.compare("dim") == 0){
            ss >> dimX >> dimY >> dimZ;
        }
        else if(token.compare("putVoxel") == 0){
            int x,y,z;
            ss >> x >> y >> z >> r >> g >> b >> a;
            figs.push_back(new putVoxel(x,y,z,r,g,b,a));
        }
        else if(token.compare("cutVoxel") == 0){
            int x,y,z;
            ss >> x >> y >> z;
            figs.push_back(new cutVoxel(x,y,z));
        }
        else if(token.compare("putBox") == 0){
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figs.push_back(new putBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        else if(token.compare("cutBox") == 0){
            int x0, x1, y0, y1, z0, z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figs.push_back(new cutBox(x0, x1, y0, y1, z0, z1));
        }
        else if(token.compare("putSphere") == 0){
            int xc, yc, zc, rad;
            ss >> xc >> yc >> zc >> rad >> r >> g >> b >> a;
            figs.push_back(new putSphere(xc, yc, zc, rad, r,g,b,a));
        }
        else if(token.compare("cutSphere") == 0){
            int xc, yc, zc, rad;
            ss >> xc >> yc >> zc >> rad;
            figs.push_back(new cutSphere(xc, yc, zc, rad));
        }
        else if(token.compare("putEllipsoid") == 0){
            int xc, yc, zc, rx, ry, rz; // Corrigido tipo de r,g,b,a que usam variáveis da classe
            ss >> xc >> yc >> zc >> rx >> ry >> rz >> r >> g >> b >> a;
            figs.push_back(new putEllipsoid(xc, yc, zc, rx, ry, rz, r,g,b,a));
        }
        else if(token.compare("cutEllipsoid") == 0){
            int xc, yc, zc, rx, ry, rz;
            ss >> xc >> yc >> zc >> rx >> ry >> rz;
            figs.push_back(new cutEllipsoid(xc, yc, zc, rx, ry, rz));
        }
    }

    //  AGORA SIM: Fecha o arquivo e retorna só depois de ler TODAS as linhas!
    entrada.close();
    return (figs);
}
int Leitorarquivos :: getDx(){
    return dimX;
}
int Leitorarquivos :: getDy(){
    return dimY;
}
int Leitorarquivos :: getDz(){
    return dimZ;
}