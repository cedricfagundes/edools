
//**************************************
//* Trabalho 1 de Estrutura de Dados I
//* Curso de Sistemas da informacao
//* Aluno: Cedric Fagundes dos Santos - matricula: 0050008673
//* Pesquisa Eleitoral
//***************************************


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct {
 	char nomeCandidatos[6][100];
	int numVotos[6];
} TPesquisa;


TPesquisa *criaNovoReg()
{
	       TPesquisa *t = (TPesquisa *)malloc(sizeof(TPesquisa));

		if ( t== NULL)
		{
		   printf("Memoria Insuficiente");
		   exit(1);
		}

		strcpy(t->nomeCandidatos[0],"Dilma Roussef");
		strcpy(t->nomeCandidatos[1],"Marina Silva");
		strcpy(t->nomeCandidatos[2],"Aecio Neves");
		strcpy(t->nomeCandidatos[3],"Cedric Fagundes");
		strcpy(t->nomeCandidatos[4],"Nulos");
		strcpy(t->nomeCandidatos[5],"Indecisos");

		t->numVotos[0] = 0;
		t->numVotos[1] = 0;
		t->numVotos[2] = 0;
		t->numVotos[3] = 0;
		t->numVotos[4] = 0;
		t->numVotos[5] = 0;

	return t;
}

void computaVoto(int numCandidato, TPesquisa *pesquisa)
{
        pesquisa->numVotos[numCandidato-1]++;
}

void ordenarCandidatos(TPesquisa *pesquisa)
{

     int i, j, iMin, temp, tam = 6;
     char tempNome[100];

     for(i=0;i<tam-1;i++)
     {
         iMin = i;
         for (j=i+1; j<tam;j++)
         {
             if (pesquisa->numVotos[j] > pesquisa->numVotos[iMin])
             {
                 iMin = j;
             }

          }
          temp = pesquisa->numVotos[i];
          pesquisa->numVotos[i]=pesquisa->numVotos[iMin];
          pesquisa->numVotos[iMin] = temp;

          strcpy(tempNome, pesquisa->nomeCandidatos[i]);
          strcpy(pesquisa->nomeCandidatos[i],pesquisa->nomeCandidatos[iMin]);
          strcpy(pesquisa->nomeCandidatos[iMin],tempNome);
     }
}


void imprimirResultadoFinal(TPesquisa *pesquisa)
{

	printf("\n**********************************");
	printf("\n* Resultado da Pesquisa Eleitoral");
	printf("\n**********************************");

	int totVotos = 0,i;
	char a[2];

	strcpy(a,"%");

        for(i=0;i<6;i++)
                totVotos = totVotos + pesquisa->numVotos[i];


	for(i=0;i<6;i++)
        {
                printf("\n%d - %s - %.2lf%s ",i+1,pesquisa->nomeCandidatos[i],((float)pesquisa->numVotos[i]/(float)totVotos)*100,a);
        }

}

int main()
{
	int voto,saida;
	TPesquisa *pesquisa;

	pesquisa = criaNovoReg();

	do
	{
		printf("\n**************************************");
		printf("\n* Trabalho 1 de Estrutura de Dados I");
		printf("\n* Curso de Sistemas da informacao");
		printf("\n* Aluno: Cedric Fagundes - matricula: 0050008673");
		printf("\n* Pesquisa Eleitoral");
		printf("\n***************************************");

		printf("\n\n***************************************");
		printf("\n* Pesquisa Eleitoral 2014");
		printf("\n***************************************");
		printf("\n1- Dilma Roussef");
		printf("\n2- Marina Silva");
		printf("\n3- Aecio neves");
		printf("\n4- Cedric Fagundes 0050008673");
		printf("\n5- Nulo");
		printf("\n6- Indeciso");
		printf("\nEntre com seu voto ==> ");
	        scanf("%d",&voto);

		computaVoto(voto,pesquisa);

		printf("\nDeseja continuar 1-sim/2-nao?");
		scanf("%d",&saida);

		if(saida == 2)
		{
			break;
		}

		while(saida == 1)
		{
		        if(saida == 1)
                    break;

			printf("\nOpcao digitada invalida.\n Entre com 1-sim/2-nao.");
			scanf("%d",&saida);

		}
	}
	while(saida == 1);

	ordenarCandidatos(pesquisa);
	imprimirResultadoFinal(pesquisa);

	free(pesquisa);
return 0;
}
