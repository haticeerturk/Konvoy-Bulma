#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sablonEslestirme(char arazi[25][80], char konvoylar[100][15][15], int konvoySayisi, int konvoyKodu[100]) {
	int i,j,k,m,l,n,p; //Donguler icin degiskenler.
  	int esitMi = 1;
  	int konvoyBosUstSatirSayisi = 0; //Konvoyun basindaki bos satir sayisi.
  	int konvoyBosAltSatirSayisi = 0; //Konvoyun sonundaki bos satir sayisi.
  	int konvoyBosSolSutunSayisi = 0; //Konvoyun solundaki bos sutun sayisi.
  	int konvoyBosSagSutunSayisi = 0; //Konvoyun sagindaki bos sutun sayisi.
  	int konvoyBosSatirMi = 1; //Bool degisken.

    /*for (i = 0; i < konvoySayisi; i++)
    {
    	printf("[%d] kodlu konvoy \n", konvoyKodu[i]);
    	for (j = 0; j < 15; j++)
    	{
    		for (k = 0; k < 15; k++)
    		{
    			//printf("(%d%d%d) -> %c/",i,j,k,konvoylar[i][j][k]);
    			printf("%c", konvoylar[i][j][k]);
    		}
    		printf("\n");
    	}
    }*/

    for(i=0; i<konvoySayisi; i++) {
        for(j=0; j<25; j++) {
            for(k=0; k<80; k++) {
              	konvoyBosUstSatirSayisi = 0;
              	konvoyBosAltSatirSayisi = 0;
              	konvoyBosSolSutunSayisi = 0;
              	konvoyBosSagSutunSayisi = 0;

              	/* Konvoyun basindaki bos satirlari dikkate almamasi icin. */
          		konvoyBosSatirMi = 1;
                for(n=0; n<15; n++) {
                  	for(p=0; p<15; p++) {
                        if(konvoylar[i][n][p] == '*' || konvoylar[i][n][p] == '+') { //Konvoy bos satir degilse buraya girecek.
                            konvoyBosSatirMi = 0; //False anlami tasiyor.
                            break;
                        }
                  	}
                  	if(konvoyBosSatirMi == 1)
                    	konvoyBosUstSatirSayisi++;
                	else if(konvoyBosSatirMi == 0)
                      	break;
                }
                /* Konvoyun sonundaki bos satirlari dikkate almamasi icin. */
				konvoyBosSatirMi = 1;
                for(n=14; n>=0; n--) {
                  	for(p=14; p>=0; p--) {
                        if(konvoylar[i][n][p] == '*' || konvoylar[i][n][p] == '+') { //Konvoy bos satir degilse buraya girecek.
                            konvoyBosSatirMi = 0; //False anlami tasiyor.
                            break;
                        }
                  	}
                  	if(konvoyBosSatirMi == 1)
                    	konvoyBosAltSatirSayisi++;
                	else if(konvoyBosSatirMi == 0)
                      	break;
                }
                /* Konvoyun solundaki bos sutunlari dikkate almamasi icin. */
          		konvoyBosSatirMi = 1;
                for(n=0; n<15; n++) {
                  	for(p=0; p<15; p++) {
                        if(konvoylar[i][p][n] == '*' || konvoylar[i][p][n] == '+') { //Konvoy bos satir degilse buraya girecek.
                            konvoyBosSatirMi = 0; //False anlami tasiyor.
                            break;
                        }
                  	}
                  	if(konvoyBosSatirMi == 1)
                    	konvoyBosSolSutunSayisi++;
                	else if(konvoyBosSatirMi == 0)
                      	break;
                }
                /* Konvoyun sagindaki bos sutunlari dikkate almamasi icin. */
				konvoyBosSatirMi = 1;
                for(n=14; n>=0; n--) {
                  	for(p=14; p>=0; p--) {
                        if(konvoylar[i][p][n] == '*' || konvoylar[i][p][n] == '+') { //Konvoy bos sutun degilse buraya girecek.
                            konvoyBosSatirMi = 0; //False anlami tasiyor.
                            break;
                        }
                  	}
                  	if(konvoyBosSatirMi == 1)
                    	konvoyBosSagSutunSayisi++;
                	else if(konvoyBosSatirMi == 0)
                      	break;
                }

                for(l=0; l<15-konvoyBosUstSatirSayisi-konvoyBosAltSatirSayisi; l++) {
                    for(m=0; m<15-konvoyBosSolSutunSayisi-konvoyBosSagSutunSayisi; m++) {
                      	if(j+l >= 25 || m+k >=80) {
                        	esitMi = 0;
	                    	break; //Dizinin boyutu tasirildigi an hata vermemesi icin.
                        }
                        if(arazi[j+l][k+m] != konvoylar[i][l+konvoyBosUstSatirSayisi+konvoyBosAltSatirSayisi][m+konvoyBosSolSutunSayisi+konvoyBosSagSutunSayisi]) {
                            if(arazi[j+l][k+m] == '*') //Arazide fazla asker varsa yanlis kabul edilmeyecektir.
                              	continue;
                          	esitMi = 0;
                          	break;
                        }
                    }
                  	if(esitMi == 0) {
                    	break;
                    }
                }

              	if(esitMi == 1) { //Konvoy arazideki bir alanla eslestirildiyse buraya girecek.
                  	for(l=0; l<15; l++) {
                    	for(m=0;m<15; m++) {
                          	if(konvoylar[i][l][m] == '+') {
								printf("%d (%d,%d)\n", konvoyKodu[i], j+l+1-konvoyBosUstSatirSayisi-konvoyBosAltSatirSayisi, k+m+1-konvoyBosSolSutunSayisi-konvoyBosSagSutunSayisi);
                          	}
                    	}
                  	}
                }
              	esitMi = 1;
            }
        }
    }
}


int main()
{
	FILE *dArazi;
  	FILE *dKonvoy;
	char arazi[25][80];
  	char konvoy_formasyonu[15][15];
	int c;
  	int i = 0;
	int j = 0;

	dArazi = fopen("arazi.txt","r");
	if (dArazi == NULL)
   		printf("404 - arazi.txt Not Found.\n");
	else {
		do {
			c = getc(dArazi); //Dosyadan tek bir karakter okunur.
				if (c != '\n') { //Okunan karakter \n ise yoksayilir. (\n degilse girilir.)
					arazi[j][i] = c; //Okunan karakter arazi matrisine atanir.
					i++;
				}
     		if(i==80) { //80'e ulasildiginda
     			i = 0; //i sifirlanir. (Yani sutun sifirlanir.)
     			j++; //y 1 arttirilir. (Yani ikinci satira gecilir.)
     		}
		} while (c != EOF);
   	}
   	fclose(dArazi);

   	/*for(i=0;i<25;i++){
        for(j=0;j<80;j++){
        	printf("%c", arazi[i][j]); //Elemanlar tek tek diziden cekilerek ekrana basilir. (Test amacli)
        }
        printf("\n"); //Her satirin bitiminden sonra bir \n koyulur.
    }*/

  	dKonvoy = fopen("konvoy_formasyonu.txt","r");
  	int lineSize = 0;
  	int konvoySayisi;
	char line[15];
  	int konvoyKodu[100];
  	int satirSayisi = 0; //Okunan satir sayisini tutar.
  	int konvoyKoduSayisi = 0; //konvoyKodu dizisi icin kullanilacak.
  	int kacinciKonvoy = 0;//Kaçıncı konvoya ulaşacağımızı bulmak için.
  	char konvoylar[100][15][15]; //Ornegin: konvoylar[1][5][6] ise; "1. konvoyun 5. satir ve 6. sutunundaki hucre" anlami tasiyor.
  	int konvoySatirSayisi = 1;
  	int konvoylarMatrisSatirSayisi = 0;
  	if(dKonvoy == NULL){
    	printf("404 - konvoy_formasyonu.txt Not Found \n");
    }
  	else{
    	while(fgets(line, 16, dKonvoy)!=NULL) {
          	if(line[0] != '\n') {
				lineSize = strlen(line);
                if(satirSayisi == 0) { //Konvoy sayisi cekilir.
                    konvoySayisi = atoi(line); //Konvoy sayisi int'e donusturulur.
                }
              	else if(((satirSayisi-1) % 16) == 0) { //Konvoy numarasi ise buraya girecek.
                	konvoyKodu[konvoyKoduSayisi] = atoi(line);
                  	konvoyKoduSayisi++;
                }
              	else {
                  	if(konvoySatirSayisi == 16) {
                    	konvoySatirSayisi = 0;
						kacinciKonvoy++;
						konvoylarMatrisSatirSayisi = 0;
                    }
                  	for(i=0; i<15; i++) {
                    	konvoylar[kacinciKonvoy][konvoylarMatrisSatirSayisi][i] = line[i];
                    }
                  	konvoylarMatrisSatirSayisi++;
                    konvoySatirSayisi++;
                }
              	satirSayisi++;
            }
        }
    }
    printf("Kod Koordinatlar\n");
    printf("--- ------------\n");
    sablonEslestirme(arazi, konvoylar, konvoySayisi, konvoyKodu); //Sablon eslestirme fonksiyonu cagirilir.
}
