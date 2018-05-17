El formato del archivo .txt es el siguiente:

======================
===== f#.txt =====

	NUM
	M
	x_1	x_2	...	x_Z
	x_1	x_2	...	x_Z
	.	.
	.		.
	.			.
	x_1	x_2	...	x_Z	(Ejemplo NUM)

donde
NUM : es el número de ejemplos de entrenamiento
M   : es el número de características de cada ejemplo 

Nota:
En el archivo seed.txt, las 7 características corresponden a:
	1. area A,
	2. perimeter P,
	3. compactness C = 4*pi*A/P^2,
	4. length of kernel,
	5. width of kernel,
	6. asymmetry coefficient
	7. length of kernel groove.  
En el archivo f1.txt, se usaron las características 2,3,4,5,7
En el archivo f2.txt, se usaron las características 3,4,5
