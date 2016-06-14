#include <stdio.h>
#include <math.h>
#define ep 2.71828182845904523536028747135266249775724709369995;
//////////////PROTÓTIPOS DAS FUNÇÕES/////////////////
double qcf (double v1);
double qph (double v1);
double qdbo (double v1);
double qnt (double v1);
double qft (double v1);
double qvt (double v1);
double qtu (double v1);
double qst (double v1);
double qo2 (double v1);

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
	printf("Digite o valor de Nitrogênio Total: (mg/L)\n");
		scanf("%lf",&nt);
	printf("Digite o valor de Fósforo Total: (mg/L)\n");
		scanf("%lf",&ft);
	printf("Digite o valor de Turbidez:\n");
		scanf("%lf",&tu);
	printf("Digite o valor dos Sólidos Totais: (mg/L)\n");
		scanf("%lf",&st);
	printf("Digite o valor de Óxigênio Dissolvido: (mg/L)\n");
		scanf("%lf",&o2);

	q[1]=qcf(cf);
	q[2]=qph(ph);
	q[3]=qdbo(dbo);
	q[4]=qnt(nt);
	q[5]=qft(ft);
	q[6]=93;
	q[7]=qtu(tu);
	q[8]=qst(st);
	q[9]=qo2(o2);
	w[1]=0.15;
	w[2]=0.12;
	w[3]=0.10;
	w[4]=0.10;
	w[5]=0.10;
	w[6]=0.10;
	w[7]=0.08;
	w[8]=0.08;
	w[9]=0.17;
	///////////FAZENDO A MÉDIA PRODUTÓRIA///////////
	for(i=1;i<=9;i++){
		qt=qt*pow(q[i],w[i]);
	}
	

	printf ("q1=%f\n"
			"q2=%f\n"
			"q3=%f\n"
			"q4=%f\n"
			"q5=%f\n"
			"q6=%f\n"
			"q7=%f\n"
			"q8=%f\n"
			"q9=%f\n"
			"Qualidade Final=%f\n"
			,q[1],q[2],q[3],q[4],q[5],q[6],q[7],q[8],q[9],qt);

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
double qnt (double v1){
	double a=98.96,b=-0.2232,c=-0.006457;
	double resultado=0;
	if (v1<=10)
		resultado = -5.1*v1+100.17;
	if (v1>10 && v1<=60)
		resultado = -22.853*log(v1)+101.18;
	if (v1>60 && v1<=90)
		resultado = 10000000000*pow(v1,-5.1161);
	if (v1>90)
		resultado=1;
	return(resultado);
}
double qft (double v1){
	double a=79.7,b=0.821,c=-1.15;
	double resultado = a*pow(v1+b,c);
	if (v1>10)
		resultado=1;
	return (resultado);
}
double qvt (double v1){
	double a=0.0003869,b=0.1815,c=0.01081;
	double resultado = 1 / (a*pow(v1+b,2)+c);
	return (resultado);
}
double qtu (double v1){
	double a=97.34,b=-0.01139,c=-0.04917;
	double resultado = a*exp(b*v1+c*sqrt(v1));
	if (v1>100)
		resultado=5;
	return(resultado);
}
double qst (double v1){
	double a=80.26,b=-0.00107,c=0.03009,d=-0.1185,e=ep;
	double resultado = 133.17*pow(e,-0.0027*v1)-53.17*pow(e,-0.0141*v1)+((-6.2*pow(e,-0.00462*v1))*sin(0.0146*v1));
	if (v1>500)
		resultado=32;
	return(resultado);
}
double qo2 (double v1){
	double t=28,ccl=9.09,h=852,pi=3.1416,e=ep;
	double cs = (14.2*pow(e,-0.0212*t)-(0.0016*ccl*pow(e,-0.0264*t)))*(0.994-(0.0001042*h));
	double ps = (v1/cs)*100;
	double resultado = -1;
	if (ps<=100){
		double y[5];
		y[1] = 0.01396*ps+0.0873;
		y[2] = (pi/56) * (ps-27);
		y[3] = (pi/85) - (ps-15);
		y[4] = (ps-65)/10;
		y[5] = (65-ps)/10;
		resultado = 100*pow((sin(y[1])),2)-((2.5*sin(y[2])-0.018*ps+6.86)*sin(y[3]))+12/(pow(e,y[4])+pow(e,y[5]));
	}
	if (ps>100 && ps<=140){
		resultado = -0.00777142857142832*pow(ps,2)+1.27854285714278*ps+49.8817148572;
	}
	if (ps>140){
		resultado = 47;
	}
	return(resultado);
}