#include <iostream>
using namespace std;
//Se declara funcion que multiplique dos matrices que entran por parametro, además, se especifican las dimensiones de las matrices, en donde x1, y1 son las dimensiones x,y de la primera matriz, y x2,y2, seran las dimensiones de la segunda matriz.
double** matrix_product(double** mat1 int x1 int y1 double** mat2 int x2 int y2);
double** get_Matrix(int M int N);

int main()
{
	// Esto es un vector de 10 componentes
	double *a = new double[10];
	
	double **mat = new double*[4];

	for (int i = 0; i < 4; i++)
	{
		mat[i] = new double[5];
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
			{	
				mat[i][j] = i*j;
				cout << mat[i][j] << " ";
			}
		cout << endl;
	}
	return 0;
}

double** matrix_product(double** mat1 int x1 int y1 double** mat2 int x2 int y2)
{ 
	// Matriz de y2,x1 componentes
	double **mat = new double*[x1];
	// Se inicializan los componetes de la matriz
	for (int i = 0; i < x1; i++)
	{
		mat[i] = new double[y2];
	}

	//Se realiza el producto matricial
	for (int i = 0; i < x1; i++)		
		{
			for (int j = 0; j < y2; j++)
			{
				for (int k = 0; k < y2 ; k++)
				{
					mat[i][j] += mat1[j][k] * mat2[k][j];
				}
			}
		}
	return mat;
}

double** get_Matrix(int M int N)
{
	// Variable de entrada por medio de la consola
	double elemento;
	// Se declara una matriz de MxN
	double **mat = new double*[M];
	// Se inicializa una matrix de MxN
	for (int i = 0; i < M; i++)
	{
		mat[i] = new double[N];
	}

	for (int i = 0; i < M; i++)		
		{
			for (int j = 0; j < N; j++)
			{
				cout << "Ingrese el elemento en la posición" << i << "," << j << endl;
				cin >> elemento;
				mat[i][j] = elemento;
			}
		}

	// Se imprime la matriz resultante.
	for (int i = 0; i < M; i++)		
		{
			for (int j = 0; j < N; j++)
			{
				cout << mat[i][j] << " ";
			}
		cout << endl;
		}

	return mat;
}
