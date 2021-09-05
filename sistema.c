#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <windows.h>


	void preco(int *linha, int *coluna, int *valoringresso, int *tvaloringressos, int *idioma){
		
			int opcingressos;
	
					if((*coluna>=11 && *coluna<=17) && ((*linha>=0  && *linha<=5) || (*linha>=14 && *linha<=19))){
            		*valoringresso=100;	
							}
					if((*coluna>=0 && *coluna<=10 &&  (*linha>=0 && *linha<=5 || *linha>=14 && *linha<=19)) || (*coluna>=18 && *coluna<=29 &&  (*linha>=0 && *linha<=5 || *linha>=14 && *linha<=19))){   
					*valoringresso=30;	    	
					}
					if(((*coluna>=0 && *coluna<=8) || (*coluna>=20 && *coluna<=29)) && *linha>=6 && *linha<=13){
					*valoringresso=20;	
					}
				if(*idioma==1){
					printf("Este Ingresso �, 1 = inteiro ou 2 = meia entrada: ");
					scanf("%d",&opcingressos);
					
						if(opcingressos<1 || opcingressos>2){
					printf("op��o inv�lida, insira um n�mero v�lido: ");
					scanf("%d",&opcingressos);
					}
					if (opcingressos==1){
					*valoringresso=*valoringresso;
					}
					if (opcingressos==2){
					*valoringresso=*valoringresso/2;
					}					
					printf("Valor do ingresso:R$ %d.\n", *valoringresso);	
				}
				if(*idioma==2){
					printf("This ticket is, 1 = integer or 2 = half entry:");
				scanf("%d",&opcingressos);	
				
						if(opcingressos<1 || opcingressos>2){
					printf("invalid option, enter a valid number: ");
					scanf("%d",&opcingressos);	
					}
					if (opcingressos==1){
					*valoringresso=*valoringresso;
					}
					if (opcingressos==2){
					*valoringresso=*valoringresso/2;
					}
					printf("Ticket amount:US$ %d.\n", *valoringresso);
				}
					*tvaloringressos= *tvaloringressos +*valoringresso;
					*valoringresso=0;						
	}


    int main(){
        setlocale(LC_ALL,"portuguese");

        int idioma,opc,i=0,j=0,k=0,infotitulo,infoestadio,opcjogo,opcingressos=0,qtdingresso,valoringresso,tvaloringressos=0;

        system("color F");
    while(i<1){
    	printf("------------------------------------------");
    	printf("\n-------------IDIOMA/LANGUAGE--------------\n\n");
    	printf("--- 1-PORTUGU�S / PORTUGUESE ------------ \n");
    	printf("--- 2-INGL�S / ENGLISH ------------------\n\n");
        printf("Insira o n�mero correspondente / Enter the corresponding number: ");
        scanf("%d",&idioma);
		j=0;

        if(idioma==1){
    while(j<1){
        		printf("\n-----------------------------------------\n");
        		printf("Est�dio C�cero Pompeu de Toledo (Morumbi)");
        		printf("\n-----------------------------------------\n");
        		printf("Menu Principal:\n");
        		printf("\n1-Pr�ximos jogos, com possibilidade de comprar ingressos.");
        		printf("\n2-Jogos anteriores, com placares e p�blico.");
        		printf("\n3-T�tulos J� conquistados pelo S�o Paulo F.C.");
        		printf("\n4-Informa��es sobre o est�dio.");
        		printf("\n5-Voltar a escolha do idioma.");
        		printf("\n6-Encerrar programa.");
        		printf("\n\nInsira o n�mero que corresponde a op��o que voc� desejar: ");
        		scanf("%d", &opc);
        		printf("===========================================================\n");

        		switch(opc){
        			case 1:
        			printf("\nDivis�o do est�dio Por setores:\n\n");
        			printf("_____________________________\n");
        			printf("|        |         |        |\n");
        			printf("|   A    |   VIP   |   B    |\n");
        			printf("|________|_________|________|\n");
          			printf("|    |                |     |\n");
          			printf("|    |                |     |\n");
          			printf("|   E|      CAMPO     |F    |\n");
          			printf("|    |                |     |\n");
          			printf("|    |                |     |\n");
        			printf("|____|________________|_____|\n");
        			printf("|        |         |        |\n");
        			printf("|   D    |   VIP   |    C   |\n");
        			printf("|________|_________|________|\n");
        			
        			printf("\nSetor VIP: R$ 100 (AZUL).\n");
        			printf("Setores A,B,C,D: R$ 30 (VERMELHO).\n");
        			printf("Setores E,F: R$ 20 (BRANCO).\n");
        			
        			printf("\nPR�XIMOS JOGOS: \n");
        			printf("\n1-S�o Paulo vs Sport Recife   24/11  16:00h.");
        			printf("\n2-S�o Paulo vs Santos         27/11  21:00h.");
        			printf("\n3-S�o Paulo vs Chapecoense    02/12  17:00h.");
        			printf("\n4-Voltar ao Menu.\n");
        			printf("\nInsira o n�mero da op��o desejada: ");
        			scanf("%d", &opcjogo);
        			
        		if(opcjogo<1 || opcjogo>4){
        			printf("\nop��o inexistente, tente de novo: ");
        			scanf("%d",&opcjogo);	
        		}

        		if(opcjogo==1){
        			printf("\n---------------------------------------------------\n");
        			printf("Venda de ingressos jogo 1: S�o Paulo x Sport Recife");
        			printf("\n---------------------------------------------------\n");
        			printf("ARQUIBANCADA, 1 s�o as cadeiras ocupadas, e 0 s�o as cadeiras livres. \n\n");
        		do{
        			for(j=0;j<30;j++){
								if(j+1<10)
								printf("%d  ",j+1);
								if(j+1>=10)
								printf("%d ",j+1);
								}
							printf("\n\n");
        			
        				FILE *arq;
    						int i,j,coluna,linha;
    						int mat[20][30];
    						
    						arq = fopen("jogo1.txt","r");
    						if(arq == NULL){
        					printf("Erro na abertura do arquivo!!\n");
        					system("pause");
        					exit(1);
        					
    						}
    						for(i=0;i<20;i++){
        						for(j=0;j<30;j++){
            				fscanf(arq,"%d",&mat[i][j]);
            				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    						CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    						WORD saved_attributes;
   							GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    						saved_attributes = consoleInfo.wAttributes;
            							if((j>=11 && j<=17) && ((i>=0  && i<=5) || (i>=14 && i<=19))){
            					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);	
										}
										if(j>=9 && j<=19 &&  (i>=6 && i<=13)){
								SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);	
									    }
									    if((j>=0 && j<=10 &&  (i>=0 && i<=5 || i>=14 && i<=19)) || (j>=18 && j<=29 &&  (i>=0 && i<=5 || i>=14 && i<=19))){  
								SetConsoleTextAttribute(hConsole, FOREGROUND_RED);	    	
										}
										if(j>=6 && j<=15 && (i>=0 && i<=10  || i>=18 && i<=29)){
										}
            				printf("%d  ",mat[i][j]);
            				SetConsoleTextAttribute(hConsole, saved_attributes);
        					}
								if(i+1<10)	
        					printf("  %d\n",i+1);
        						if(i+1>=10)
        					printf(" %d\n",i+1);
    						}
    					fclose(arq);;
    						printf("\nInsira a quantidade de ingressos que voce ir� comprar: ");
    						scanf("%d",&qtdingresso);
    					if(qtdingresso<=0){
    							printf("Imposs�vel comprar esse quantidade! Insira denovo: ");
    							scanf("%d",&qtdingresso);
						}
					if(qtdingresso>0){
    						printf("\nInsira os Lugares pretendidos:\n");
    					for(k=0;k<qtdingresso;k++){
    						arq = fopen("jogo1.txt","w");
    						printf("\nColuna da %d� cadeira: ",k+1);
    						scanf("%d",&coluna);
    						coluna=coluna-1;
    						printf("Linha da %d� cadeira: ",k+1);
    						scanf("%d",&linha);
   						    linha= linha-1;
   						if(linha>19 || linha<0 || coluna>29 || coluna<0 || (coluna>=9 && coluna<=19 && (linha>=6 && linha<=13))){
   							printf("Esta cadeira n�o existe!! Tente de novo:\n");
   							printf("\nColuna da %d� cadeira: ",k+1);
    						scanf("%d",&coluna);
    						coluna=coluna-1;
    						printf("Linha da %d� cadeira: ",k+1);
    						scanf("%d",&linha);
   						    linha= linha-1;
						   }    
   						
   						    if(mat[linha][coluna]==1){
   						    	printf("Cadeira j� ocupada!! Escolha uma livre:\n ");
   						    	printf("\nColuna da %d� cadeira: ",k+1);
    							scanf("%d",&coluna);
    							coluna=coluna-1;
    							printf("Linha da %d� cadeira: ",k+1);
    							scanf("%d",&linha);
   						    	linha= linha-1;	
							}
							if(mat[linha][coluna]==0){
								
								preco(&linha, &coluna, &valoringresso, &tvaloringressos, &idioma);
								
    							mat[linha][coluna] = 1;
    						for(i=0;i<20;i++){
        						for(j=0;j<30;j++){
            						fprintf(arq,"%d  ",mat[i][j]);
       							 }
        							fprintf(arq,"\n");
    						}
    						}
    					
    					}
    						printf("\n-----------------------------\n");
    						printf("Valor da compra: %d Reais", tvaloringressos);
    						printf("\n-----------------------------\n\n");
    						tvaloringressos=0;	
    				}
    					fclose(arq);
    					
    				printf("Digite 0 para voltar ao menu principal, ou um n�mero maior para realiza��o de outra compra: ");
    				scanf("%d",&opcingressos);
    				printf("\n");

    			}while(opcingressos!=0);
    			j=0;
				}
			
				if(opcjogo==2){
						printf("\n---------------------------------------------------\n");
        				printf("Venda de ingressos jogo 2: S�o Paulo x Santos");
        				printf("\n---------------------------------------------------\n");
        				printf("ARQUIBANCADA, 1 s�o as cadeiras ocupadas, e 0 s�o as cadeiras livres. \n\n");
        		do{
        			for(j=0;j<30;j++){
								if(j+1<10)
								printf("%d  ",j+1);
								if(j+1>=10)
								printf("%d ",j+1);
								}
							printf("\n\n");
        			
        				FILE *arq;
    						int i,j,coluna,linha;
    						int mat[20][30];
    						
    						arq = fopen("jogo2.txt","r");
    						if(arq == NULL){
        					printf("Erro na abertura do arquivo!!\n");
        					system("pause");
        					exit(1);
        					
    						}
    						for(i=0;i<20;i++){
        						for(j=0;j<30;j++){
            				fscanf(arq,"%d",&mat[i][j]);
            				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    						CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    						WORD saved_attributes;
   							GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    						saved_attributes = consoleInfo.wAttributes;
            							if((j>=11 && j<=17) && ((i>=0  && i<=5) || (i>=14 && i<=19))){
            					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);	
										}
										if(j>=9 && j<=19 &&  (i>=6 && i<=13)){
								SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);	
									    }
									    if((j>=0 && j<=10 &&  (i>=0 && i<=5 || i>=14 && i<=19)) || (j>=18 && j<=29 &&  (i>=0 && i<=5 || i>=14 && i<=19))){  
								SetConsoleTextAttribute(hConsole, FOREGROUND_RED);	    	
										}
										if(j>=6 && j<=15 && (i>=0 && i<=10  || i>=18 && i<=29)){
										}
            				printf("%d  ",mat[i][j]);
            				SetConsoleTextAttribute(hConsole, saved_attributes);
        					}
								if(i+1<10)	
        					printf("  %d\n",i+1);
        						if(i+1>=10)
        					printf(" %d\n",i+1);
    						}
    					fclose(arq);;
    						printf("\nInsira a quantidade de ingressos que voce ir� comprar: ");
    						scanf("%d",&qtdingresso);
    					if(qtdingresso<=0){
    							printf("Imposs�vel comprar esse quantidade! Insira denovo: ");
    							scanf("%d",&qtdingresso);
						}
					if(qtdingresso>0){
    						printf("\nInsira os Lugares pretendidos:\n");
    					for(k=0;k<qtdingresso;k++){
    						arq = fopen("jogo2.txt","w");
    						printf("\nColuna da %d� cadeira: ",k+1);
    						scanf("%d",&coluna);
    						coluna=coluna-1;
    						printf("Linha da %d� cadeira: ",k+1);
    						scanf("%d",&linha);
   						    linha= linha-1;
   						if(linha>19 || linha<0 || coluna>29 || coluna<0 || (coluna>=9 && coluna<=19 && (linha>=6 && linha<=13))){
   							printf("Esta cadeira n�o existe!! Tente de novo:\n");
   							printf("\nColuna da %d� cadeira: ",k+1);
    						scanf("%d",&coluna);
    						coluna=coluna-1;
    						printf("Linha da %d� cadeira: ",k+1);
    						scanf("%d",&linha);
   						    linha= linha-1;
						   }    
   						
   						    if(mat[linha][coluna]==1){
   						    	printf("Cadeira j� ocupada!! Escolha uma livre: ");
   						    	printf("\nColuna da %d� cadeira: ",k+1);
    							scanf("%d",&coluna);
    							coluna=coluna-1;
    							printf("Linha da %d� cadeira: ",k+1);
    							scanf("%d",&linha);
   						    	linha= linha-1;	
							}
							if(mat[linha][coluna]==0){
								
								preco(&linha, &coluna, &valoringresso, &tvaloringressos, &idioma);
								
    							mat[linha][coluna] = 1;
    						for(i=0;i<20;i++){
        						for(j=0;j<30;j++){
            						fprintf(arq,"%d  ",mat[i][j]);
       							 }
        							fprintf(arq,"\n");
    						}
    						}
    					
    					}
    						printf("\n-----------------------------\n");
    						printf("Valor da compra: %d Reais", tvaloringressos);
    						printf("\n-----------------------------\n\n");
    						tvaloringressos=0;	
    				}
    					fclose(arq);
    					
    				printf("Digite 0 para voltar ao menu principal, ou um n�mero maior para realiza��o de outra compra: ");
    				scanf("%d",&opcingressos);
    				printf("\n");

    			}while(opcingressos!=0);
    			j=0;
				}
				
				if(opcjogo==3){
					printf("\n---------------------------------------------------\n");
        				printf("Venda de ingressos jogo 3: S�o Paulo x Chapecoense");
        				printf("\n---------------------------------------------------\n");
        				printf("ARQUIBANCADA, 1 s�o as cadeiras ocupadas, e 0 s�o as cadeiras livres. \n\n");
        		do{
        			for(j=0;j<30;j++){
								if(j+1<10)
								printf("%d  ",j+1);
								if(j+1>=10)
								printf("%d ",j+1);
								}
							printf("\n\n");
        			
        				FILE *arq;
    						int i,j,coluna,linha;
    						int mat[20][30];
    						
    						arq = fopen("jogo3.txt","r");
    						if(arq == NULL){
        					printf("Erro na abertura do arquivo!!\n");
        					system("pause");
        					exit(1);
        					
    						}
    						for(i=0;i<20;i++){
        						for(j=0;j<30;j++){
            				fscanf(arq,"%d",&mat[i][j]);
            				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    						CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    						WORD saved_attributes;
   							GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    						saved_attributes = consoleInfo.wAttributes;
            							if((j>=11 && j<=17) && ((i>=0  && i<=5) || (i>=14 && i<=19))){
            					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);	
										}
										if(j>=9 && j<=19 &&  (i>=6 && i<=13)){
								SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);	
									    }
									    if((j>=0 && j<=10 &&  (i>=0 && i<=5 || i>=14 && i<=19)) || (j>=18 && j<=29 &&  (i>=0 && i<=5 || i>=14 && i<=19))){  
								SetConsoleTextAttribute(hConsole, FOREGROUND_RED);	    	
										}
										if(j>=6 && j<=15 && (i>=0 && i<=10  || i>=18 && i<=29)){
										}
            				printf("%d  ",mat[i][j]);
            				SetConsoleTextAttribute(hConsole, saved_attributes);
        					}
								if(i+1<10)	
        					printf("  %d\n",i+1);
        						if(i+1>=10)
        					printf(" %d\n",i+1);
    						}
    					fclose(arq);;
    						printf("\nInsira a quantidade de ingressos que voce ir� comprar: ");
    						scanf("%d",&qtdingresso);
    					if(qtdingresso<=0){
    							printf("Imposs�vel comprar esse quantidade! Insira denovo: ");
    							scanf("%d",&qtdingresso);
						}
					if(qtdingresso>0){
    						printf("\nInsira os Lugares pretendidos:\n");
    					for(k=0;k<qtdingresso;k++){
    						arq = fopen("jogo3.txt","w");
    						printf("\nColuna da %d� cadeira: ",k+1);
    						scanf("%d",&coluna);
    						coluna=coluna-1;
    						printf("Linha da %d� cadeira: ",k+1);
    						scanf("%d",&linha);
   						    linha= linha-1;
   						if(linha>19 || linha<0 || coluna>29 || coluna<0 || (coluna>=9 && coluna<=19 && (linha>=6 && linha<=13))){
   							printf("Esta cadeira n�o existe!! Tente de novo:\n");
   							printf("\nColuna da %d� cadeira: ",k+1);
    						scanf("%d",&coluna);
    						coluna=coluna-1;
    						printf("Linha da %d� cadeira: ",k+1);
    						scanf("%d",&linha);
   						    linha= linha-1;
						   }    
   						
   						    if(mat[linha][coluna]==1){
   						    	printf("Cadeira j� ocupada!! Escolha uma livre:\n");
   						    	printf("\nColuna da %d� cadeira: ",k+1);
    							scanf("%d",&coluna);
    							coluna=coluna-1;
    							printf("Linha da %d� cadeira: ",k+1);
    							scanf("%d",&linha);
   						    	linha= linha-1;	
							}
							if(mat[linha][coluna]==0){
								
								preco(&linha, &coluna, &valoringresso, &tvaloringressos, &idioma);
								
    							mat[linha][coluna] = 1;
    						for(i=0;i<20;i++){
        						for(j=0;j<30;j++){
            						fprintf(arq,"%d  ",mat[i][j]);
       							 }
        							fprintf(arq,"\n");
    						}
    						}
    					
    					}
    						printf("\n-----------------------------\n");
    						printf("Valor da compra: %d Reais", tvaloringressos);
    						printf("\n-----------------------------\n\n");
    						tvaloringressos=0;	
    				}
    					fclose(arq);
    					
    				printf("Digite 0 para voltar ao menu principal, ou um n�mero maior para realiza��o de outra compra: ");
    				scanf("%d",&opcingressos);
    				printf("\n");

    			}while(opcingressos!=0);
    			j=0;
				}
        		
				if(opcjogo==4){
        			printf("\n");
        			j=0;
				}
				break;

        			case 2: 
        			printf("\nJOGOS ANTERIORES: \n");
        			printf("\nS�o paulo vs Flamengo 4/nov/2018.");
        			printf("\nResultado: S�o Paulo: 3 X 1 Flamengo.");
        			printf("\nP�blico: 46.184 Pessoas.");

        			printf("\n\n");

        			printf("\nS�o paulo vs Gr�mio 14/nov/2018.");
        			printf("\nResultado: S�o Paulo: 2 x 2 Gr�mio.");
        			printf("\nP�blico: 48.260 pessoas.");

        			printf("\n\n");

        			printf("\nS�o paulo vs Cruzeiro 17/nov/2018.");
        			printf("\nResultado: S�o Paulo: 3 X 1 Cruzeiro.");
        			printf("\nP�blico: 46.530 Pessoas.");

					printf("\nINSIRA 0 PARA VOLTAR AO MENU, OU UM N�MERO MAIOR MAIOR PARA ENCERRAR: ");
        			scanf("%d", &j);
        			i=j;

        			break;

					case 3:
					printf("\nT�TULOS CONQUISTADOS PELO S�O PAULO F.C:\n");
					printf("\n1-T�tulos nacionais.");
					printf("\n2-T�tulos internacionais.");
					printf("\n\ninsira o n�mero que corresponde a op��o que voc� desejar: ");
					scanf("%d", &infotitulo);
					printf("===========================================================\n");

						if(infotitulo<1 || infotitulo>2){
						printf("\nOP��O INV�LIDA!! Digite uma op��o V�lida:");
						scanf("%d",&infotitulo);
						}
						if(infotitulo==1){
							printf("\nT�TULOS NACIONAIS:\n");
							printf("\n-Campeonato Brasileiro: 1977, 1986, 1991, 2006, 2007, 2008.");
							printf("\n-Torneio Rio-S�o Paulo: 2001.");
							printf("\n-Torneio Governador Nunes Freire, Maranh�o: 1976.");
							printf("\n-Ta�a Independ�ncia do Brasil: 1971.");
							printf("\n-Ta�a dos Campe�es Estaduais Rio de Janeiro-S�o Paulo: 1931, 1943, 1946, 1948, 1953, 1957, 1975, 1980, 1985, 1987.\n");
						}
						if(infotitulo==2){
							printf("\nT�TULOS INTERNACIONAIS:\n");
							printf("\n-Mundial de Clubes: 1992, 1993, 2005.");
							printf("\n-Copa Libertadores da Am�rica: 1992, 1993, 2005.");
							printf("\n-Copa Sul-Americana: 2012.");
							printf("\n-Supercopa da Libertadores da Am�rica: 1993.");
							printf("\n-Recopa Sul-Americana: 1993, 1994.");
							printf("\n-Copa Conmebol: 1994.");
							printf("\n-Copa Master da Conmebol: 1996.\n");
						}

					printf("\nINSIRA 0 PARA VOLTAR AO MENU, OU UM N�MERO MAIOR MAIOR PARA ENCERRAR: ");
        			scanf("%d", &j);
        			i=j;

					break;

					case 4:
					printf("\nINFORMA��ES SOBRE O EST�DIO:\n");
        			printf("\n1-Capacidade do est�dio.");
        			printf("\n2-Maior p�blico.");
        			printf("\n3-Inagura��o.");
        			printf("\n4-Endere�o.");
        			printf("\n\nInsira o n�mero que corresponde a op��o que voc� desejar: ");
        			scanf("%d", &infoestadio);
        			printf("===========================================================\n");

        				if(infoestadio<1 || infoestadio>4){
        				printf("\nOP��O INV�LIDA!! Digite uma op��o V�lida:");
        				scanf("%d",&infoestadio);
						}

        				if(infoestadio==1){
        					printf("\nCapacidade de p�blico total: 72.809 pessoas.");
        					printf("\nCapacidade de p�blico por ingressos comercializ�veis: 66.435 pessoas.");
        					printf("\nCapacidade de p�blico quando inaugurado finalizado: 149.408 pessoas.\n\n");
						}
						if(infoestadio==2){
        					printf("\nMaior p�blico: 146 082 pessoas.\n\n");
						}
						if(infoestadio==3){
        					printf("\nInaugura��o parcial: 02 de outubro de 1960, S�o Paulo 1 x 0 Sporting (Portugal).");
        					printf("\nInaugura��o final: 25 de janeiro de 1970.\n\n");
						}
						if(infoestadio==4){
							printf("\nEndere�o:");
        					printf("\nPra�a Roberto Gomes Pedrosa, 1.");
        					printf("\nMorumbi, S�o Paulo - SP.");
        					printf("\n05653-070.\n\n");
						}

					printf("\nINSIRA 0 PARA VOLTAR AO MENU, OU UM N�MERO MAIOR MAIOR PARA ENCERRAR: ");
        			scanf("%d", &j);
        			i=j;
					break;

					case 5:
						j++;
						printf("\n");
					break;
					
					case 6:
						i++;
						j++;
						printf("\nPrograma encerrado com sucesso. OBRIGADO PELA ATEN��O!.");
					break;
					
					default:
        					printf("\nOP��O INV�LIDA!! Tente novamente.\n");
        			break;
  				}
	}
		}
		if(idioma==2){
		while(j<1){
        		printf("\n-----------------------------------------\n");
        		printf("Stadium C�cero Pompeu de Toledo (Morumbi)");
        		printf("\n-----------------------------------------\n");
        		printf("Main Menu:\n");
        		printf("\n1-Next games, with possibility of ticket buy.");
        		printf("\n2-Previous games, with leaderboards and public.");
        		printf("\n3-Titles already won by S�o Paulo F.C.");
        		printf("\n4-information about stadium.");
        		printf("\n5-Return to Language choice.");
        		printf("\n6-Close the program.");
        		printf("\n\nEnter the number that matches the option you want: ");
        		scanf("%d", &opc);
        		printf("===========================================================\n");

        		switch(opc){
        			case 1:
        			printf("\nDivision of the stadium By sectors:\n\n");
        			printf("_____________________________\n");
        			printf("|        |         |        |\n");
        			printf("|   A    |   VIP   |   B    |\n");
        			printf("|________|_________|________|\n");
          			printf("|    |                |     |\n");
          			printf("|    |                |     |\n");
          			printf("|   E|      FIELD     |F    |\n");
          			printf("|    |                |     |\n");
          			printf("|    |                |     |\n");
        			printf("|____|________________|_____|\n");
        			printf("|        |         |        |\n");
        			printf("|   D    |   VIP   |    C   |\n");
        			printf("|________|_________|________|\n");
        			
        			printf("\nSector VIP: US$ 100 (BLUE).\n");
        			printf("Sectors A,B,C,D: US$ 30 (RED).\n");
        			printf("Sectors E,F: US$ 20 (WHITE).\n");
        			
        			printf("\nNEXT GAMES: \n");
        			printf("\n1-S�o Paulo vs Sport Recife   24/11  16:00h.");
        			printf("\n2-S�o Paulo vs Santos         27/11  21:00h.");
        			printf("\n3-S�o Paulo vs Chapecoense    02/12  17:00h.");
        			printf("\n4-Back to Menu.\n");
        			printf("\nEnter the number of the desired option: ");
        			scanf("%d", &opcjogo);
        		
        		if(opcjogo<1 || opcjogo>4){
        			printf("\nOption does not exist, try again: ");
        			scanf("%d",&opcjogo);	
        		}
        			
        		if(opcjogo==1){
        			printf("\n---------------------------------------------------\n");
        			printf("Sale of tickets game 1: S�o Paulo x Sport Recife");
        			printf("\n---------------------------------------------------\n");
        			printf("ASSENTIS, 1 is the occupied chairs, and 0 are the free chairs. \n\n");
        		do{
        			for(j=0;j<30;j++){
								if(j+1<10)
								printf("%d  ",j+1);
								if(j+1>=10)
								printf("%d ",j+1);
								}
							printf("\n\n");
        			
        				FILE *arq;
    						int i,j,coluna,linha;
    						int mat[20][30];
    						
    						arq = fopen("jogo1.txt","r");
    						if(arq == NULL){
        					printf("Error opening file!!\n");
        					system("pause");
        					exit(1);
        					
    						}
    						for(i=0;i<20;i++){
        						for(j=0;j<30;j++){
            				fscanf(arq,"%d",&mat[i][j]);
            				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    						CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    						WORD saved_attributes;
   							GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    						saved_attributes = consoleInfo.wAttributes;
            							if((j>=11 && j<=17) && ((i>=0  && i<=5) || (i>=14 && i<=19))){
            					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);	
										}
										if(j>=9 && j<=19 &&  (i>=6 && i<=13)){
								SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);	
									    }
									    if((j>=0 && j<=10 &&  (i>=0 && i<=5 || i>=14 && i<=19)) || (j>=18 && j<=29 &&  (i>=0 && i<=5 || i>=14 && i<=19))){  
								SetConsoleTextAttribute(hConsole, FOREGROUND_RED);	    	
										}
										if(j>=6 && j<=15 && (i>=0 && i<=10  || i>=18 && i<=29)){
										}
            				printf("%d  ",mat[i][j]);
            				SetConsoleTextAttribute(hConsole, saved_attributes);
        					}
								if(i+1<10)	
        					printf("  %d\n",i+1);
        						if(i+1>=10)
        					printf(" %d\n",i+1);
    						}
    					fclose(arq);;
    						printf("\nEnter the amount of tickets you will buy: ");
    						scanf("%d",&qtdingresso);
    					if(qtdingresso<=0){
    							printf("Impossible to buy that amount! Enter again:");
    							scanf("%d",&qtdingresso);
						}
					if(qtdingresso>0){
    						printf("\nEnter the desired places:\n");
    					for(k=0;k<qtdingresso;k++){
    						arq = fopen("jogo1.txt","w");
    						printf("\nColumn of the %d chair: ",k+1);
    						scanf("%d",&coluna);
    						coluna=coluna-1;
    						printf("line of the %d chair: ",k+1);
    						scanf("%d",&linha);
   						    linha= linha-1;
						if(linha>19 || linha<0 || coluna>29 || coluna<0 || (coluna>=9 && coluna<=19 && (linha>=6 && linha<=13))){
   							printf("This chair does not exist !! Try again:\n");
   							printf("\nColumn of the %d chair: ",k+1);
    						scanf("%d",&coluna);
    						coluna=coluna-1;
    						printf("line of the %d chair: ",k+1);
    						scanf("%d",&linha);
   						    linha= linha-1;
						   }    
   						
   						    if(mat[linha][coluna]==1){
   						    	printf("Chair already occupied !! Choose a free:\n ");
   						    	printf("\nColumn of the %d chair: ",k+1);
    							scanf("%d",&coluna);
    							coluna=coluna-1;
    							printf("line of the %d chair: ",k+1);
    							scanf("%d",&linha);
   						    	linha= linha-1;	
							}
								if(mat[linha][coluna]==0){
								
								preco(&linha, &coluna, &valoringresso, &tvaloringressos, &idioma);
								
    							mat[linha][coluna] = 1;
    						for(i=0;i<20;i++){
        						for(j=0;j<30;j++){
            						fprintf(arq,"%d  ",mat[i][j]);
       							 }
        							fprintf(arq,"\n");
    						}
    						}
    					
    					}
    						printf("\n-----------------------------\n");
    						printf("Total purchase value:US$ %d", tvaloringressos);
    						printf("\n---------------------------\n");
    						tvaloringressos=0;
    				}
    					fclose(arq);
    					
    				printf("Enter 0 to return to the main menu, or a higher number to make another purchase:");
    				scanf("%d",&opcingressos);
    				printf("\n");

    			}while(opcingressos!=0);
    			j=0;
			}
			
				if(opcjogo==2){
						printf("\n---------------------------------------------------\n");
        			printf("Sale of tickets game 2: S�o Paulo vs Santos");
        			printf("\n---------------------------------------------------\n");
        			printf("ASSENTIS, 1 is the occupied chairs, and 0 are the free chairs. \n\n");
        		do{
        			for(j=0;j<30;j++){
								if(j+1<10)
								printf("%d  ",j+1);
								if(j+1>=10)
								printf("%d ",j+1);
								}
							printf("\n\n");
        			
        				FILE *arq;
    						int i,j,coluna,linha;
    						int mat[20][30];
    						
    						arq = fopen("jogo2.txt","r");
    						if(arq == NULL){
        					printf("Error opening file!!\n");
        					system("pause");
        					exit(1);
        					
    						}
    						for(i=0;i<20;i++){
        						for(j=0;j<30;j++){
            				fscanf(arq,"%d",&mat[i][j]);
            				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    						CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    						WORD saved_attributes;
   							GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    						saved_attributes = consoleInfo.wAttributes;
            							if((j>=11 && j<=17) && ((i>=0  && i<=5) || (i>=14 && i<=19))){
            					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);	
										}
										if(j>=9 && j<=19 &&  (i>=6 && i<=13)){
								SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);	
									    }
									    if((j>=0 && j<=10 &&  (i>=0 && i<=5 || i>=14 && i<=19)) || (j>=18 && j<=29 &&  (i>=0 && i<=5 || i>=14 && i<=19))){  
								SetConsoleTextAttribute(hConsole, FOREGROUND_RED);	    	
										}
										if(j>=6 && j<=15 && (i>=0 && i<=10  || i>=18 && i<=29)){
										}
            				printf("%d  ",mat[i][j]);
            				SetConsoleTextAttribute(hConsole, saved_attributes);
        					}
								if(i+1<10)	
        					printf("  %d\n",i+1);
        						if(i+1>=10)
        					printf(" %d\n",i+1);
    						}
    					fclose(arq);;
    						printf("\nEnter the amount of tickets you will buy: ");
    						scanf("%d",&qtdingresso);
    					if(qtdingresso<=0){
    							printf("Impossible to buy that amount! Enter again:");
    							scanf("%d",&qtdingresso);
						}
					if(qtdingresso>0){
    						printf("\nEnter the desired places:\n");
    					for(k=0;k<qtdingresso;k++){
    						arq = fopen("jogo2.txt","w");
    						printf("\nColumn of the %d chair: ",k+1);
    						scanf("%d",&coluna);
    						coluna=coluna-1;
    						printf("line of the %d chair: ",k+1);
    						scanf("%d",&linha);
   						    linha= linha-1;
   						if(linha>19 || linha<0 || coluna>29 || coluna<0 || (coluna>=9 && coluna<=19 && (linha>=6 && linha<=13))){
   							printf("This chair does not exist !! Try again:\n");
   							printf("\nColumn of the %d chair: ",k+1);
    						scanf("%d",&coluna);
    						coluna=coluna-1;
    						printf("line of the %d chair: ",k+1);
    						scanf("%d",&linha);
   						    linha= linha-1;
						   }    
   						
   						    if(mat[linha][coluna]==1){
   						    	printf("Chair already occupied !! Choose a free:\n ");
   						    	printf("\nColumn of the %d chair: ",k+1);
    							scanf("%d",&coluna);
    							coluna=coluna-1;
    							printf("line of the %d chair: ",k+1);
    							scanf("%d",&linha);
   						    	linha= linha-1;	
							}
								if(mat[linha][coluna]==0){
								
								preco(&linha, &coluna, &valoringresso, &tvaloringressos, &idioma);
								
    							mat[linha][coluna] = 1;
    						for(i=0;i<20;i++){
        						for(j=0;j<30;j++){
            						fprintf(arq,"%d  ",mat[i][j]);
       							 }
        							fprintf(arq,"\n");
    						}
    						}
    					
    					}
    						printf("\n-----------------------------\n");
    						printf("Total purchase value: US$ %d", tvaloringressos);
    						printf("\n---------------------------\n");
    						tvaloringressos=0;
    				}
    					fclose(arq);
    					
    				printf("Enter 0 to return to the main menu, or a higher number to make another purchase:");
    				scanf("%d",&opcingressos);
    				printf("\n");

    			}while(opcingressos!=0);
    			j=0;
    			
				}
				if(opcjogo==3){
					printf("\n---------------------------------------------------\n");
        			printf("Sale of tickets game 3: S�o Paulo vs Chapecoense");
        			printf("\n---------------------------------------------------\n");
        			printf("ASSENTIS, 1 is the occupied chairs, and 0 are the free chairs. \n\n");
        		do{
        			for(j=0;j<30;j++){
								if(j+1<10)
								printf("%d  ",j+1);
								if(j+1>=10)
								printf("%d ",j+1);
								}
							printf("\n\n");
        			
        				FILE *arq;
    						int i,j,coluna,linha;
    						int mat[20][30];
    						
    						arq = fopen("jogo3.txt","r");
    						if(arq == NULL){
        					printf("Error opening file!!\n");
        					system("pause");
        					exit(1);
        					
    						}
    						for(i=0;i<20;i++){
        						for(j=0;j<30;j++){
            				fscanf(arq,"%d",&mat[i][j]);
            				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    						CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    						WORD saved_attributes;
   							GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    						saved_attributes = consoleInfo.wAttributes;
            							if((j>=11 && j<=17) && ((i>=0  && i<=5) || (i>=14 && i<=19))){
            					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);	
										}
										if(j>=9 && j<=19 &&  (i>=6 && i<=13)){
								SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);	
									    }
									    if((j>=0 && j<=10 &&  (i>=0 && i<=5 || i>=14 && i<=19)) || (j>=18 && j<=29 &&  (i>=0 && i<=5 || i>=14 && i<=19))){  
								SetConsoleTextAttribute(hConsole, FOREGROUND_RED);	    	
										}
										if(j>=6 && j<=15 && (i>=0 && i<=10  || i>=18 && i<=29)){
										}
            				printf("%d  ",mat[i][j]);
            				SetConsoleTextAttribute(hConsole, saved_attributes);
        					}
								if(i+1<10)	
        					printf("  %d\n",i+1);
        						if(i+1>=10)
        					printf(" %d\n",i+1);
    						}
    					fclose(arq);;
    						printf("\nEnter the amount of tickets you will buy: ");
    						scanf("%d",&qtdingresso);
    					if(qtdingresso<=0){
    							printf("Impossible to buy that amount! Enter again:");
    							scanf("%d",&qtdingresso);
						}
					if(qtdingresso>0){
    						printf("\nEnter the desired places:\n");
    					for(k=0;k<qtdingresso;k++){
    						arq = fopen("jogo3.txt","w");
    						printf("\nColumn of the %d chair: ",k+1);
    						scanf("%d",&coluna);
    						coluna=coluna-1;
    						printf("line of the %d chair: ",k+1);
    						scanf("%d",&linha);
   						    linha= linha-1;
   						if(linha>19 || linha<0 || coluna>29 || coluna<0 || (coluna>=9 && coluna<=19 && (linha>=6 && linha<=13))){
   							printf("This chair does not exist !! Try again:\n");
   							printf("\nColumn of the %d chair: ",k+1);
    						scanf("%d",&coluna);
    						coluna=coluna-1;
    						printf("line of the %d chair: ",k+1);
    						scanf("%d",&linha);
   						    linha= linha-1;
						   }    
   						
   						    if(mat[linha][coluna]==1){
   						    	printf("Chair already occupied !! Choose a free: \n");
   						    	printf("\nColumn of the %d chair: ",k+1);
    							scanf("%d",&coluna);
    							coluna=coluna-1;
    							printf("line of the %d chair: ",k+1);
    							scanf("%d",&linha);
   						    	linha= linha-1;	
							}
								if(mat[linha][coluna]==0){
								
								preco(&linha, &coluna, &valoringresso, &tvaloringressos, &idioma);
								
    							mat[linha][coluna] = 1;
    						for(i=0;i<20;i++){
        						for(j=0;j<30;j++){
            						fprintf(arq,"%d  ",mat[i][j]);
       							 }
        							fprintf(arq,"\n");
    						}
    						}
    					
    					}
    						printf("\n-----------------------------\n");
    						printf("Total purchase value:US$ %d.", tvaloringressos);
    						printf("\n---------------------------\n");
    						tvaloringressos=0;
    				}
    					fclose(arq);
    					
    				printf("Enter 0 to return to the main menu, or a higher number to make another purchase:");
    				scanf("%d",&opcingressos);
    				printf("\n");

    			}while(opcingressos!=0);
    			j=0;
    			}
    			
        		if(opcjogo==4){
        			printf("\n");
        			j=0;
				}
					break;

        			case 2:
        			printf("\nPREVIOUS GAMES: \n");
        			printf("\nS�o paulo vs Flamengo 4/november/2018.");
        			printf("\nResult: S�o Paulo: 3 X 1 Flamengo.");
        			printf("\nPublic: 46.184 people.");

        			printf("\n\n");

        			printf("\nS�o paulo vs Gr�mio 14/november/2018.");
        			printf("\nResult: S�o Paulo: 2 x 2 Gr�mio.");
        			printf("\nPublic: 48.260 people.");

        			printf("\n\n");

        			printf("\nS�o paulo vs Cruzeiro 17/november/2018.");
        			printf("\nResult: S�o Paulo: 3 X 1 Cruzeiro.");
        			printf("\nPublic: 46.530 people.");

        			printf("\n\nENTER 0 TO CONTINUE IN THE PROGRAM, OR A LARGER NUMBER TO CLOSE: ");
        			scanf("%d", &j);
        			i=j;

        			break;

					case 3:
					printf("\nTITLE WON BY THE S�O PAULO F.C:\n");
					printf("\n1-National Titles.");
					printf("\n2-International Titles.");
					printf("\n\nEnter the number that matches the option you want: ");
					scanf("%d", &infotitulo);
					printf("===========================================================\n");

						if(infotitulo<1 || infotitulo>2){
						printf("\nInvalid option!! Enter a valid option:");
						scanf("%d",&infotitulo);
						}
						if(infotitulo==1){
							printf("\nNATIONAL TITLES:\n");
							printf("\n-Championship Brazilian: 1977, 1986, 1991, 2006, 2007, 2008.");
							printf("\n-Tournament  Rio-S�o Paulo: 2001.");
							printf("\n-Tournament Governador Nunes Freire, Maranh�o: 1976.");
							printf("\n-Cup Independence of Brazil: 1971.");
							printf("\n-Cup of State Champions Rio de Janeiro-S�o Paulo: 1931, 1943, 1946, 1948, 1953, 1957, 1975, 1980, 1985, 1987.\n");
						}
						if(infotitulo==2){
							printf("\nINTERNATIONAL TITLES:\n");
							printf("\n-Club World: 1992, 1993, 2005.");
							printf("\n-CupLibertadores da Am�rica: 1992, 1993, 2005.");
							printf("\n-Cup Sul-Americana: 2012.");
							printf("\n-Supercup da Libertadores da Am�rica: 1993.");
							printf("\n-Recopa Sul-Americana: 1993, 1994.");
							printf("\n-Cup Conmebol: 1994");
							printf("\n-Cup Master da Conmebol: 1996.\n");
						}

                    printf("\nENTER 0 TO CONTINUE IN THE PROGRAM, OR A LARGER NUMBER TO CLOSE: ");
        			scanf("%d", &j);
        			i=j;

					break;

					case 4:
					printf("\nSTADIUM INFORMATION:\n");
        			printf("\n1-Stadium capacity.");
        			printf("\n2-Largest audience.");
        			printf("\n3-Inauguration.");
        			printf("\n4-Address.");
        			printf("\n\nEnter the number that matches the option you want: ");
        			scanf("%d", &infoestadio);
        			printf("===========================================================\n");

        				if(infoestadio<1 || infoestadio>4){
        				printf("\nInvalid option!! Enter a valid option:");
        				scanf("%d",&infoestadio);
						}

        				if(infoestadio==1){
        					printf("\nTotal audience capacity: 72.809 pessoas.");
        					printf("\nPublic capacity for marketable tickets: 66.435 people.");
        					printf("\nPublic capacity when opened terminated: 149.408 people.\n\n");
						}
						if(infoestadio==2){
        					printf("\nLargest audience: 146 082 people.\n\n");
						}
						if(infoestadio==3){
        					printf("\nIPartial Naugura��o: 02 of october of 1960, S�o Paulo 1 x 0 Sporting (Portugal).");
        					printf("\nFinal inauguration: 25 of january of 1970.\n\n");
						}
						if(infoestadio==4){
							printf("\nAdress:");
        					printf("\nPra�a Roberto Gomes Pedrosa, 1");
        					printf("\nMorumbi, S�o Paulo - SP");
        					printf("\n05653-070.\n\n");
						}

					printf("\nENTER 0 TO CONTINUE IN THE PROGRAM, OR A LARGER NUMBER TO CLOSE: ");
        			scanf("%d", &j);
        			i=j;
					break;

					case 5:
						j++;
						printf("\n");
					break;
					
					case 6:
						i++;
						j++;
					    printf("\nProgram ended successfully. THANKS FOR ATTENTION!.");
					break;

					default:
        					printf("\nInvalid option!! Try again.\n");
        			break;
  				}
	}
		}

		if(idioma<1 || idioma>2){
        printf("\nOp��o Inv�lida!! Tente novamente / Invalid option!! Try again.\n\n");
		}
	}
}


