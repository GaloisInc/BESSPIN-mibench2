#include "../bareBench.h"

extern unsigned short ult ( unsigned short a, unsigned short b);
extern unsigned short slt ( short a, short b);

extern unsigned short ulte ( unsigned short a, unsigned short b);
extern unsigned short slte ( short a, short b);

extern unsigned short ugt ( unsigned short a, unsigned short b);
extern unsigned short sgt ( short a, short b);

extern unsigned short ugte ( unsigned short a, unsigned short b);
extern unsigned short sgte ( short a, short b);


unsigned short limit_test ( void )
{
    unsigned short ra;
    short sa;

    for(ra=0;;ra++) if(ult(ra,7)==0) break;
    if(ra!=7) return(1);

    for(ra=0xF000;;ra++) if(ult(ra,0xF007)==0) break;
    if(ra!=0xF007) return(1);

    for(sa=-7;;sa++) if(slt(sa,7)==0) break;
    if(sa!=7) return(1);

    for(sa=-17;;sa++) if(slt(sa,-7)==0) break;
    if(sa!=-7) return(1);

    for(ra=0;;ra++) if(ulte(ra,7)==0) break;
    if(ra!=8) return(1);

    for(ra=0xF000;;ra++) if(ulte(ra,0xF007)==0) break;
    if(ra!=0xF008) return(1);

    for(ra=0xF000;;ra++) if(ulte(ra,7)==0) break;
    if(ra!=0xF000) return(1);

    for(sa=-7;;sa++) if(slte(sa,7)==0) break;
    if(sa!=8) return(1);

    for(sa=-17;;sa++) if(slte(sa,-7)==0) break;
    if(sa!=-6) return(1);

    for(ra=0;;ra++) if(ugt(ra,7)) break;
    if(ra!=8) return(1);

    for(ra=0xF000;;ra++) if(ugt(ra,0xF007)) break;
    if(ra!=0xF008) return(1);

    for(ra=0;;ra++) if(ugte(ra,7)) break;
    if(ra!=7) return(1);

    for(ra=0xF000;;ra++) if(ugte(ra,0xF007)) break;
    if(ra!=0xF007) return(1);

    return(0);

}
int main ( void )
{
    return(limit_test());
}


