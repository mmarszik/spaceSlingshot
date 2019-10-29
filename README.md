# spaceSlingshot

This program calculates the speed of the micro probe in the space cosmic.

# compilation

g++ -O3 main.cpp -o spaceSlingshot

# Example 1

./spaceSlingshot name=zylon

Will be use material: [zylon]
 - strMat:    5.800000 [Gpa]
 - destinity: 1.540000 [g/cm^3]
 - massRop:   10.000000 [kg]
 - lengthRop: 100.000000 [m]
 - massProbe: 1.000000 [kg]
 - minRps:    0.000100
 - maxRps:    10000.000000
 - step:      0.001000 [m]<br />
   0 rps=5000.000050 vProbe=3141592.685006[m/s] massRope=26.205502[fail]<br />
   1 rps=2500.000075 vProbe=1570796.373919[m/s] massRope=56.023061[fail]<br />
   2 rps=1250.000088 vProbe=785398.218375[m/s] massRope=17.354548[fail]<br />
   ...................................................................<br />
   38 rps=5.490557 vProbe=3449.818551[m/s] massRope=10.000000[fail]<br />
   39 rps=5.490557 vProbe=3449.818545[m/s] massRope=10.000000[kg]<br />
   40 rps=5.490557 vProbe=3449.818548[m/s] massRope=10.000000[kg]<br />


# Example 2
./spaceSlingshot name=spectra_2000

Will be use material: [spectra_2000]
 - strMat:    2.700000 [Gpa]
 - destinity: 0.970000 [g/cm^3]
 - massRop:   10.000000 [kg]
 - lengthRop: 100.000000 [m]
 - massProbe: 1.000000 [kg]
 - minRps:    0.000100
 - maxRps:    10000.000000
 - step:      0.001000 [m]<br />
   0 rps=5000.000050 vProbe=3141592.685006[m/s] massRope=35.457468[fail]<br />
   1 rps=2500.000075 vProbe=1570796.373919[m/s] massRope=96.305352[fail]<br />
   2 rps=1250.000088 vProbe=785398.218375[m/s] massRope=32.264497[fail]<br />
   ...................................................................<br />
   39 rps=4.720182 vProbe=2965.777942[m/s] massRope=10.000000[kg]<br />
   40 rps=4.720182 vProbe=2965.777945[m/s] massRope=10.000000[kg]<br />
   41 rps=4.720182 vProbe=2965.777946[m/s] massRope=10.000000[kg]<br />


# Example 3

./spaceSlingshot name=colossal_carbon_tube

Will be use material: [colossal_carbon_tube]
 - strMat:    7.000000 [Gpa]
 - destinity: 0.010000 [g/cm^3]
 - massRop:   10.000000 [kg]
 - lengthRop: 100.000000 [m]
 - massProbe: 1.000000 [kg]
 - minRps:    0.000100
 - maxRps:    10000.000000
 - step:      0.001000 [m]<br />
   0 rps=5000.000050 vProbe=3141592.685006[m/s] massRope=11.255803[fail]<br />
   1 rps=2500.000075 vProbe=1570796.373919[m/s] massRope=10.296730[fail]<br />
   2 rps=1250.000088 vProbe=785398.218375[m/s] massRope=10.049407[fail]<br />
   ...................................................................<br />
   31 rps=74.853440 vProbe=47031.803365[m/s] massRope=9.999999[kg]<br />
   32 rps=74.853441 vProbe=47031.804097[m/s] massRope=10.000000[fail]<br />
   33 rps=74.853440 vProbe=47031.803731[m/s] massRope=10.000000[kg]<br />
   34 rps=74.853441 vProbe=47031.803914[m/s] massRope=10.000000[kg]<br />


# Example 4 (mass of rope = 1000kg!!!)

./spaceSlingshot name=zylon massRop=1000

Will be use material: [zylon]
 - strMat:    5.800000 [Gpa]
 - destinity: 1.540000 [g/cm^3]
 - massRop:   1000.000000 [kg]
 - lengthRop: 100.000000 [m]
 - massProbe: 1.000000 [kg]
 - minRps:    0.000100
 - maxRps:    10000.000000
 - step:      0.001000 [m]<br />
   0 rps=5000.000050 vProbe=3141592.685006[m/s] massRope=20134.484881[fail]<br />
   1 rps=2500.000075 vProbe=1570796.373919[m/s] massRope=3250.537105[fail]<br />
   2 rps=1250.000088 vProbe=785398.218375[m/s] massRope=2342.886517[fail]<br />
   3 rps=625.000094 vProbe=392699.140604[m/s] massRope=1347.699179[fail]<br />
   ...................................................................<br />
  46 rps=10.230472 vProbe=6427.995426[m/s] massRope=1000.000000[fail]<br />
  47 rps=10.230472 vProbe=6427.995426[m/s] massRope=1000.000000[kg]<br />
  48 rps=10.230472 vProbe=6427.995426[m/s] massRope=1000.000000[kg]<br />
  49 rps=10.230472 vProbe=6427.995426[m/s] massRope=1000.000000[kg]<br />


# Example 5 (mass of rope = 1000kg!!!)

./spaceSlingshot name=colossal_carbon_tube massRop=1000

Will be use material: [colossal_carbon_tube]
 - strMat:    7.000000 [Gpa]
 - destinity: 0.010000 [g/cm^3]
 - massRop:   1000.000000 [kg]
 - lengthRop: 100.000000 [m]
 - massProbe: 1.000000 [kg]
 - minRps:    0.000100
 - maxRps:    10000.000000
 - step:      0.001000 [m]<br />
   0 rps=5000.000050 vProbe=3141592.685006[m/s] massRope=1084.097364[fail]<br />
   1 rps=2500.000075 vProbe=1570796.373919[m/s] massRope=1014.583857[fail]<br />
   2 rps=1250.000088 vProbe=785398.218375[m/s] massRope=1001.870591[fail]<br />
   ...................................................................<br />
   40 rps=139.473299 vProbe=87633.658472[m/s] massRope=1000.000000[kg]<br />
   41 rps=139.473299 vProbe=87633.658474[m/s] massRope=1000.000000[kg]<br />
   42 rps=139.473299 vProbe=87633.658474[m/s] massRope=1000.000000[fail]<br />
   43 rps=139.473299 vProbe=87633.658474[m/s] massRope=1000.000000[kg]<br />
