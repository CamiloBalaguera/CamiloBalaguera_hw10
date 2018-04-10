#include <iostream>
using namespace std;
//Se declara funcion que multiplique dos matrices que entran por parametro, además, se especifican las dimensiones de las matrices, en donde x1, y1 son las dimensiones x,y de la primera matriz, y x2,y2, seran las dimensiones de la segunda matriz.
double** matrix_product(double** mat1, int x1, int y1, double** mat2, int x2, int y2);
double** get_Matrix(int M, int N);

int main()
{
	int X1;
	int Y1;
	int X2;
	int Y2;
	cout << "Ingrese la dimensión X de A:" << endl;
	cin >> X1;
	cout << "Ingrese la dimensión Y de A:" << endl;
	cin >> Y1;
	cout << "Ingrese la dimensión X de B:" << endl;
	cin >> X2;
	cout << "Ingrese la dimensión Y de B:" << endl;
	cin >> Y2;
	if (X2 != Y1)
	{
		cout << "La segunda dimension de A no es igual a la primera dimension de B" << endl;
	}
	else
	{
		cout << "Se esta inicializando la matriz A " << endl;
		double** A = get_Matrix(X1, Y1);
		cout << "Se esta inicializando la matriz B " << endl;
		double** B = get_Matrix(X2, Y2);
		double** R = matrix_product(A, X1, Y1, B, X2, Y2);
		// Se imprime la matriz resultado.
		cout << "Esta es la matriz resultado" << endl;
		for (int i = 0; i < X1; i++)		
			{
				for (int j = 0; j < Y2; j++)
				{
					cout << R[i][j] << " ";
				}
			cout << endl;
			}
	}
	return 0;
}

double** matrix_product(double** mat1, int x1, int y1, double** mat2, int x2, int y2)
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

double** get_Matrix(int M, int N)
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
	cout << "Esta es la matriz resultante" << endl;
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
