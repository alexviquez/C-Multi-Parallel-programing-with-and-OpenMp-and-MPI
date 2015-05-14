# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main(){
        
   FILE *inicializador, *lectura, *encriptado; //apuntadores a los archivos que se utilizaran
   char nombre_archivo[13],  hexadecimal[3], palabra1, palabra2, palabra, bufer1[15], bufer2[2]; //cadenas y caracteres que se utilizaran
   int i, j, indice1, indice2, indice; //enteros para el control de ciclos y asignacion de operaciones
   
   inicializador = fopen("inicializador.txt", "r"); //Se abre el archivo de inicializacion en modo lectura
   if(inicializador == 0){
       printf("nombre_archivo de inicializacion no encontrado, favor de validar."); //Si no se tienen permisos para accesar al archivo termina la ejecucion
       getch();
   }else{
        		
        if(fgets(bufer1, 15, (FILE*)inicializador) != 0){ //Se le la linea del archivo inicializador en donde se encontrara el nombre del archivo a leer y la llave
                         sscanf(bufer1, "%s" "%s", nombre_archivo, hexadecimal); //Se asigna la lectura a nuestras variables de tipo char
        }else{ //Si no se tienen permisos para accesar al archivo termina la ejecucion
              printf("No se pudo leer linea de archivo inicializador, favor de validar existencia de archivo.");      
              getch();
              exit(0);
        }

        lectura = fopen(nombre_archivo, "r"); //Se abre el archivo a leer en modo de lectura
      	if(lectura == 0){ //Si no se tienen permisos para accesar al archivo termina la ejecucion
        	printf("No se pudo abrir el archivo a leer, revise permisos.");
        	getch();
      	}else{
			
			encriptado = fopen("chiper.txt", "w+"); //Se crea el archivo en donde se escribira lo leido encriptado
			if(encriptado == 0){ //Si no se tienen permisos para accesar al archivo termina la ejecucion
				printf("No se pudo crear el archivo a escribir, revise permisos.");
				getch();
			}else{
				
				while(fgets(bufer2, 2, (FILE*)lectura) != 0){ //Se leen 16 bits 
					for(i=0; i<2; i++){ //Se asignan los bits a operar a nuestras variables 						
                        palabra1 = hexadecimal[i+1];
						palabra2 = bufer2[i];                        						
						
						for(j=8; j>0; j--){ //Se opera bit a bit
							indice1 = palabra1 % 2;
							palabra1 = palabra1 / 2;
							indice2 = palabra2 % 2;
							palabra2 = palabra2 / 2;							
							
							indice += indice1 ^ indice2; //Se aplica XOR bit a bit y se guarda							
						}						
                        fprintf(encriptado, "%c", indice); //Se escribe en el archivo 								
                        indice = 0; //Se reinicia nuestra variable
					}					
				} 	 
                      			
            printf("\nSe realizo el encriptado del archivo exitosamente!");
            
            fclose(inicializador); //Se cierran archivos
            fclose(lectura);
			fclose(encriptado);
			}
			
			getch();
		}
	}
}
