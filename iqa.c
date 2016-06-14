#include <stdio.h>
#include <math.h>
#define ep 2.71828182845904523536028747135266249775724709369995;
//////////////PROTÓTIPOS DAS FUNÇÕES/////////////////
double qcf (double v1);
double qph (double v1);
double qdbo (double v1);
double qnt (double v1);
double qft (double v1);

int main(){
	double q[9],w[9],cf,ph,dbo,nt,ft,vt,tu,st,o2,qt=1;
	int i;
	////////////OBTENDO VALOR DAS VARIÁVEIS////////////////
	printf("Digite o valor dos Coliformes Termotolerantes: (mg/L)\n");
		scanf("%lf",&cf);
	printf("Digite o valor do pH:\n");
		scanf("%lf",&ph);
	printf("Digite o valor da Demanda Bioquímica de Oxigênio: (mg/L)\n");
		scanf("%lf",&dbo);

	q[1]=qcf(cf);
	q[2]=qph(ph);
	q[3]=qdbo(dbo);

	w[1]=0.15;
	w[2]=0.12;
	w[3]=0.10;

	///////////FAZENDO A MÉDIA PRODUTÓRIA///////////
	for(i=1;i<=9;i++){
		qt=qt*pow(q[i],w[i]);
	}
	

	printf ("q1=%f\n"
			"q2=%f\n"
			"q3=%f\n"
			"Qualidade Final=%f\n"
			,q[1],q[2],q[3],qt);

	if (qt<20)
		printf("Qualidade Péssima\n");
	if (qt>=20 && qt<=36)
		printf("Qualidade Ruim\n");
	if (qt>=37 && qt<=50)
		printf("Qualidade Aceitável\n");
	if (qt>=51 && qt<=79)
		printf("Qualidade Boa\n");
	if (qt>=80)
		printf("Qualidade Ótima\n");
	return 0;
}
////////////////////FUNÇOES///////////////////////
double qcf (double v1){
	double a=98.03,b=-36.45,c=3.138,d=0.06776;
	double resultado = (v1<=100000) ? a+b*log10(v1)+c*pow(log10(v1),2)+d*pow(log10(v1),3) : 3;
	return(resultado);
}
double qph (double v1){
	double a = 0.05421, b = 1.23, c = -0.09873;
	double resultado = a*pow(v1,b*v1+c*pow(v1,2))+5.213;
	if (v1<2)
		resultado = 2.0;
	if (v1>12)
		resultado = 3.0;
	return (resultado);
}
double qdbo (double v1){
	double a=100.9571,b=10.7121,c=0.49544,d=-0.011167,e=0.0001;
	double resultado = (v1<=30) ? a-b*v1+c*pow(v1,2)+d*pow(v1,3)+e*pow(v1,4) : 2;
	return (resultado);
}
