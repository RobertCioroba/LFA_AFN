#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000

int main()
{
	int i, j, k,st, simb, stfin, viz[20], a[20][20],nr;
	char simbol[20];
	//citim numarul de stari
	printf("Numarul starilor: ");
	scanf("%d",&st);
	//citim numarul simbolurilor
	printf("Numarul simbolurilor : ");
	scanf("%d",&simb);
	printf("\n");

      //citim simbolurile
	for(i=0;i<simb;i++)
	{
		printf("Simbol %d: ", i);
		scanf(" %c",&simbol[i]);
	}
      //citim numarul de stari finale
	printf("Numarul starilor finale: ");
	scanf("%d",&stfin);
      //specificam care sunt starile finale
	printf("Ce stari sunt finale? ");
	printf("\n");
	for(i=0;i<stfin;i++)
	{
		int temp;
		scanf("%d",&temp);
		viz[temp]=1;
	}

	//citim relatiile
	printf("Relatiile stare-simbol ");
	printf("\n");
	for(i=0;i<st;i++)
		for(j=0;j<simb;j++)
            {
                //citim unde mergem cu caracterul simbol[j] din starea i
			    printf("delta(q%d,%c) = ",i, simbol[j]);
			    scanf(" %d",&a[i][simbol[j]]);
            }

	printf("Numarul de cuvinte pentru verificare: ");
	scanf("%d",&nr);
	for(k=0;k<nr;k++)
            {
		printf("Introduceti cuvantul: ");
		char str1[MAX];
		scanf("%s", &str1);
		int ok=0;
		for(i=0;i<strlen(str1);i++)
		{
			int ele=(int)(str1[i]);
			ok=a[ok][ele];
		}

		if(viz[ok]==1)
			printf("Ii bun!");
		else
			printf("Nu-i bun!");
		printf("\n");
            }
	return 0;
}