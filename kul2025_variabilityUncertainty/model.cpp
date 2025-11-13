$PROB 2cmtModel
$PLUGIN autodec nm-vars

$CMT CENT PERI

$PARAM
TVCL = 3
TVV1 = 5
TVQ = 1
TVV2 = 8

$OMEGA @block @correlation @annotated
ECL : 0.4 : Random effect on CL
EV1 : 0.67 0.4 : Random effect on V
EKA : 0.25 0.87 0.2 : Random effect on KA

$PK
capture CL = TVCL * exp(ECL);
capture V1 = TVV1 * exp(EV1);

Q = TVQ;
V2 = TVV2;

KE = CL/V1;
K12 = Q/V1;
K21 = Q / V2;

$DES
DADT(1) = -KE*A(1) - K12*A(1) + K21*A(2);
DADT(2) = K12 * A(1) - K21*A(2);

$TABLE
capture CP = A(1) / V1;