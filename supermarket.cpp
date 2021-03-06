#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Product {
	const char* name;
	float price;
	float totalPartial;
};
	
void showMenu(){
	printf("Bem-vinda, Beatriz!");
	printf("\n\n1 - INICIAR COMPRAS");
	printf("\n2 - DESLIGAR");
}

void listProducts(){	
	printf("\nProduto   |   C�digo    |   Pre�o(R$)\n");
	printf("\n");
	printf("ARROZ     |     11      |     4,52\n");
	printf("FEIJ�O    |     12      |     5,45\n");
	printf("LEITE     |     13      |     5,20\n");
	printf("CAF�      |     14      |     3,78\n");
	printf("A�UCAR    |     15      |     2,45\n");
	printf("�LEO      |     16      |     8,51\n");
	printf("TRIGO     |     17      |     3,20\n");
	printf("BISCOITO  |     18      |     3,59\n");
	printf("MARGARINA |     19      |     4,76\n");
	printf("SAL       |     20      |     0,85\n");
}

const char* returnProductNameByCode(int code){
	switch(code){
		case 11:
			return "ARROZ";
			break;
		case 12:
			return "FEIJ�O";
			break;
		case 13:
			return "LEITE";
			break;
		case 14:
			return "CAF�";
			break;
		case 15:
			return "A�UCAR";
			break;
		case 16:
			return "�LEO";
			break;
		case 17:
			return "TRIGO";
			break;
		case 18:
			return "BISCOITO";
			break;
		case 19:
			return "MARGARINA";
			break;
		case 20:
			return "SAL";
			break;
		default:			
			break;
	}
}


float returnProductPriceByCode(int code){
	switch(code){
		case 11:
			return 4.52;
			break;
		case 12:
			return 5.45;
			break;
		case 13:
			return 4.20;
			break;
		case 14:
			return 3.78;
			break;
		case 15:
			return 2.45;
			break;
		case 16:
			return 8.51;
			break;
		case 17:
			return 3.20;
			break;
		case 18:
			return 3.59;
			break;
		case 19:
			return 4.76;
			break;
		case 20:
			return 0.85;
			break;
		default:
			break;
	}
}

float calculateTotalPartial(float amount, float price){ // Calcula o valor parcial da compra
	float result = amount * price;
	return result;
}

float calculateChange(float payment, float total){ // Calcula o troco
	float result;
	if(payment > total){
		result = payment - total;
	}
	return result;	
}

int main()
{
	setlocale(LC_ALL,"Portuguese");
	
    int userOption, productCode;
    float total = 0;
    float paymentAmount, amount, change;
    struct Product product;
    showMenu();
    printf("\nQuero: ");
	scanf("%d", &userOption);
	do{    	
//		system("cls");
		if(userOption == 1){
			listProducts();
			printf("\nC�digo do produto (digite 0 para sair): ");
	  		scanf("%d", &productCode);
	  		if(productCode == 0)
	  			break;
			while(productCode < 11 || productCode > 20){
				printf("\nInsira um c�digo v�lido!");
				printf("\nC�digo do produto (digite 0 para sair): ");
	  			scanf("%d", &productCode);
	  			if(productCode == 0)
	  				break;
			}
				  		
			product.name = returnProductNameByCode(productCode);
	  		product.price = returnProductPriceByCode(productCode);
	  		
	  		printf("\n=======================================================================================");
	  		printf("\nNome do produto: %s", product.name);
	  		
	  		printf("\nQuantidade: ");
	  		scanf("%f", &amount);
	  			  		
	  		product.totalPartial = calculateTotalPartial(amount, product.price);
	  		printf("Total parcial: R$ %.2f", product.totalPartial);
	  		printf("\n=======================================================================================");
	  		total += product.totalPartial;
		}		
		else{
			break;
		}	
	}while(1);
	
	if(userOption != 2 && total != 0.00){
		printf("\nTotal a pagar: %.2f", total);
		printf("\nPagamento: (digite um ponto para separar os centavos, exemplo: 1.99) R$ ");
		scanf("%f", &paymentAmount);		

		while(paymentAmount < total){
			printf("\nFiado somente para quem ganha 5000 sal�rios m�nimos.");
			printf("\nPagamento: (digite um ponto para separar os centavos, exemplo: 1.99) R$ ");
			scanf("%f", &paymentAmount);
			if(paymentAmount >= total)
				break;
		}
		
		change = calculateChange(paymentAmount, total);
		printf("\nSeu troco: %.2f", change);
		printf("\nCompra finalizada com sucesso, volte sempre!");
	}
	printf("\nFinalizado!");
    return 0;
}

