#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

#define EPSILON1 (0.000000001)
#define EPSILON2 (0.00000001)


typedef double ftyp;
typedef const ftyp cftyp;
typedef int ityp;
typedef const ityp cityp;


struct Params {
    char name[256]; // Name of the rope material.
    ftyp strMat;    // Strength of the rope material [Gpa].
    ftyp destinity; // Destinity of the rope material [g/cm^3].
    ftyp massRop;   // Mass of rope [kg].
    ftyp lengthRop; // Lenght of rope (radius) [m].
    ftyp massProbe; // Masa of space probe (or cannonball) [kg].
    ftyp minRps;    // Min revolutions per second.
    ftyp maxRps;    // Max revolutions per second.
    ftyp step;      // The const step integration [m]
};


static const Params preDef[] = {
{
    "zylon",
    5.8,      // Strength of the rope material [Gpa].
    1.54,     // Destinity of the rope material [g/cm^3].
    10,
    100,
    1,
    1E-4,
    1E+4,
    0.001
},
{
    "colossal_carbon_tube",
    7.0,      // Strength of the rope material [Gpa].
    0.010,    // Destinity of the rope material [g/cm^3].
    10,
    100,
    1,
    1E-4,
    1E+4,
    0.001
},
{
    "spectra_2000",
    2.7,      // Strength of the rope material [Gpa].
    0.97,     // Destinity of the rope material [g/cm^3].
    10,
    100,
    1,
    1E-4,
    1E+4,
    0.001
}
};


#define cntElems( __tab__ ) ( (ityp) (sizeof(__tab__) / sizeof( __tab__[0] )) )


// Convert RPS to angular velocity
static ftyp angularVelocity(
    cftyp rps // revolutions per second.
) {
    return rps * 2 * M_PI;
}


// Compute centrifugal force [N]
static ftyp centrifugalForce(
    cftyp rps,   // The revolutions per second.
    cftyp mass,  // The mass of any finite element.
    cftyp r      // The radius.
) {
    cftyp aV = angularVelocity(rps);
    return aV * aV * mass * r;
}


//Compute mass of rope [kg].
static ftyp computeMassRope(
    ftyp mass,       // Initially mass of the space probe (or cannonball) [kg].
    ftyp r,          // Initially lenght of rope (radius) [m].
    cftyp rps,       // The revolutions per second.
    cftyp strMat,    // The strength of the rope material [Gpa].
    cftyp destinity, // The destinity of the rope material [g/cm^3].
    cftyp step,      // The const step integration [m].
    cftyp eMassRope, // The expected mass of rope[kg]
    bool &exectly
) {
    ftyp massRope = 0;                                     // The integrated mass of rope [kg].
    ftyp strength = centrifugalForce( rps , mass , r );    // The integrated centrifugal force [N].
    exectly = true;
    while( r > EPSILON1 ) {
        cftyp crossSection = strength / (strMat*1E9);      // The necessary cross section of the rope at the r distance [m^2].
        cftyp rStep = r >= step ? step : r;                // The real step [m].
        cftyp dVol = rStep * crossSection;                 // The change volumen [m^3].
        cftyp dMass = dVol * destinity * 1E3;              // The change of mass [kg]
        strength += centrifugalForce( rps , dMass , r - rStep/2 ); // rStep/2 => trapezoid method.
        mass += dMass;                                     // The whole mass [kg].
        massRope += dMass;                                 // The mass of rope [kg].
        r -= rStep;
        if( massRope > eMassRope + EPSILON2 ) {
            exectly = false;
            break;
        }
    }
    return massRope;
}

static char* extractArg( int argc , char *argv[] , const char *arg ) {
    for( int i=1 ; i<argc ; i++ ) {
        int off = 0;
        if( argv[i][0] == '-' )
            off++;
        if( off && argv[i][1] == '-' )
            off++;
        if( strncasecmp( argv[i]+off , arg , strlen(arg) ) == 0 ) {
            off += strlen(arg);
            return argv[i]+off;
        }
    }
    return NULL;
}

static Params params( int argc , char *argv[] ) {
    Params prm = preDef[0];
    char *arg;

    if( arg = extractArg( argc , argv , "name=" ) ) {
        for( int i=0 ; i<cntElems(preDef) ; i++ ) {
            if( strcasecmp( arg , preDef[i].name ) == 0 ) {
                prm = preDef[i];
                break;
            }
        }
    }

    if( arg = extractArg( argc , argv , "strMat=" ) ) {
        prm.strMat = strtod( arg , NULL );
    }

    if( arg = extractArg( argc , argv , "destinity=" ) ) {
        prm.destinity = strtod( arg , NULL );
    }

    if( arg = extractArg( argc , argv , "massRop=" ) ) {
        prm.massRop = strtod( arg , NULL );
    }

    if( arg = extractArg( argc , argv , "lengthRop=" ) ) {
        prm.lengthRop = strtod( arg , NULL );
    }

    if( arg = extractArg( argc , argv , "massProbe=" ) ) {
        prm.massProbe = strtod( arg , NULL );
    }

    if( arg = extractArg( argc , argv , "minRps=" ) ) {
        prm.minRps = strtod( arg , NULL );
    }

    if( arg = extractArg( argc , argv , "maxRps=" ) ) {
        prm.maxRps = strtod( arg , NULL );
    }

    if( arg = extractArg( argc , argv , "step=" ) ) {
        prm.step = strtod( arg , NULL );
    }

    return prm;
}

int main(int argc, char *argv[])
{
    const Params prm = params( argc , argv );

    printf("Will be use material: [%s]\n"  , prm.name );
    printf(" - strMat:    %lf [Gpa]\n"     , (double)prm.strMat );
    printf(" - destinity: %lf [g/cm^3]\n"  , (double)prm.destinity );
    printf(" - massRop:   %lf [kg]\n"      , (double)prm.massRop );
    printf(" - lengthRop: %lf [m]\n"       , (double)prm.lengthRop );
    printf(" - massProbe: %lf [kg]\n"      , (double)prm.massProbe );
    printf(" - minRps:    %lf\n"           , (double)prm.minRps );
    printf(" - maxRps:    %lf\n"           , (double)prm.maxRps );
    printf(" - step:      %lf [m]\n"       , (double)prm.step );

    ftyp maxRps = prm.maxRps;
    ftyp minRps = prm.minRps;
    ftyp rps = (minRps + maxRps) / 2.0;
    bool exectly;
    ftyp massRope = computeMassRope( prm.massProbe , prm.lengthRop , rps , prm.strMat , prm.destinity , prm.step , prm.massRop , exectly );
    ftyp vProbe = prm.lengthRop * angularVelocity( rps );
    ityp loop = 0;
    printf("%4d rps=%lf vProbe=%lf[m/s] massRope=%lf%s\n",(int)loop,(double)rps,(double)vProbe,(double)massRope, exectly?"[kg]":"[fail]" );

    while(
        rps < prm.maxRps - EPSILON2 &&
        rps > prm.minRps + EPSILON2 &&
        fabs( massRope - prm.massRop ) > EPSILON2 &&
        loop < 1000000
    ) {
        loop ++ ;
        if( massRope > prm.massRop  ) {
            maxRps = rps;
        } else {
            minRps = rps;
        }
        rps = (minRps + maxRps) / 2;
        massRope = computeMassRope( prm.massProbe , prm.lengthRop , rps , prm.strMat , prm.destinity , prm.step  , prm.massRop , exectly );
        vProbe = prm.lengthRop * angularVelocity( rps );
        printf("%4d rps=%lf vProbe=%lf[m/s] massRope=%lf%s\n",(int)loop,(double)rps,(double)vProbe,(double)massRope, exectly?"[kg]":"[fail]" );
        fflush(stdout);
    }

    return 0;
}

