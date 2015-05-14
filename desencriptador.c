# include <stdio.h>
# include <stdlib.h>
# include <math.h>

#define euler 2.718281

int main(int argc, char const *argv[]){
	
	FILE *archivo_codificado, *errores;
	char nombre_archivo[13], caracteres_archivo[35858], resultado[35858];
	int llave, i, j, caracteres_binarios[35858], llaves_ganadoras[5], k;
	float porcentaje_vocales, porcentaje_espacios, porcentaje_consonantes, pivote;
	float probabilidad_vocales, probabilidad_espacios, probabilidad_consonantes, probabilidad_total[256];

	if((errores = fopen("error.log", "a+")) == 0){
		fprintf(errores, "No se puede iniciar el archivo de error, favor de validar permisos");
		exit(1);
	}


  	archivo_codificado = fopen("codificado.txt", "r");
    	if(archivo_codificado == 0){
        	fprintf(errores, "Archivo codificado no encontrado, favor de validar.");         
         	exit(1);
     	}else{     		
     		     		
     		while(!feof(archivo_codificado)){
     			caracteres_archivo[i] = fgetc(archivo_codificado);
     			i ++;
        	}
        }          

    for(i=0; i<35858; i++)
    	caracteres_binarios[i] = caracteres_archivo[i] - '0';     	
 	

     for(i=0; i<256; i++){
     	
     	llave = i;

     	porcentaje_vocales = 0;
     	porcentaje_espacios = 0;
     	porcentaje_consonantes = 0;

     	for(j=0; j<35858; j++){
     		resultado[j] = (char)llave ^ caracteres_binarios[j];
     		if(resultado[j] == 'a' || resultado[j] == 'e' || resultado[j] == 'i' || resultado[j] == 'o' || resultado[j] == 'u')
				porcentaje_vocales ++;
			else if(resultado[j] == ' ' || resultado[j] == '	')
				porcentaje_espacios ++;
			else if(resultado[j] == 's' || resultado[j] == 'S' || resultado[j] == 'r' || resultado[j] == 'R' || resultado[j] == 'n' || resultado[j] == 'N' || resultado[j] == 'L' || resultado[j] == 'l' || resultado[j] == 'd' || resultado[j] == 'D' || resultado[j] == 'c' || resultado[j] == 'C')
     			porcentaje_consonantes ++;
     	}     	

     	porcentaje_vocales = porcentaje_vocales * 100 / 35858;
     	porcentaje_espacios = porcentaje_espacios * 100 / 35858;
     	porcentaje_consonantes = porcentaje_consonantes * 100 / 35858;				     	     	     	

		pivote = pow(-(porcentaje_vocales + 45), 2);
		for(k=0; k<pivote; k++)
			probabilidad_vocales += euler*euler;
		probabilidad_vocales /= 2;				

		pivote = pow(-(porcentaje_espacios + 17),2);
		for(k=0; k<pivote; k++)
			probabilidad_espacios += euler*euler;
		probabilidad_espacios /= 2; 		
		
		pivote = pow(-(porcentaje_consonantes + 37),2);
		for(k=0; k<pivote; k++)
			probabilidad_consonantes = euler*euler;
		probabilidad_consonantes /= 2;

		probabilidad_total[i] = probabilidad_vocales + probabilidad_espacios + probabilidad_consonantes;
     }
    
    for(j=0; j<2; j++){
    	k=0;
    	for(i=0; i<255; i++){
    		if(probabilidad_total[i] >= probabilidad_total[i+1]){
    			llaves_ganadoras[k] = i+1;
    			k ++;
    		}
    	}
	}

	printf("Las llaves ganadoras son:\n");
	for(i=0; i<5; i++)
		printf(" %i.- Llave %d\n", i+1, llaves_ganadoras[i]);

	return 0;
 }
