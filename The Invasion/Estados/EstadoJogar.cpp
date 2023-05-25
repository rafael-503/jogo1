#include "EstadoJogar.h"
using namespace Estados;

EstadoJogar::EstadoJogar(): fase1(){

}
EstadoJogar::~EstadoJogar(){

}
void EstadoJogar::executar(){
    fase1.executar();
}
