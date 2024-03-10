#include <stdio.h>
#define MAX_SIZE 100

void _sumaMatrices(int firstArray[MAX_SIZE][MAX_SIZE], int secondArray[MAX_SIZE][MAX_SIZE]);
void _llenarMatrices(int array[MAX_SIZE][MAX_SIZE], char Matriz[MAX_SIZE], int width, int heigt);

int main()
{
	int widthFirstArray, heightFirstArray, widthSecondArray, heightSecondArray;
	int width, height;
	printf("dame la anchura de la primera matriz");
	scanf("%d", &widthFirstArray);
	printf("dame la anchura de la primera matriz");
	scanf("%d", &heightFirstArray);
	printf("dame la anchura de la primera matriz");
	scanf("%d", &widthSecondArray);
	printf("dame la anchura de la primera matriz");
	scanf("%d", &heightSecondArray);

	if ((widthFirstArray <= MAX_SIZE) && (heightFirstArray <= MAX_SIZE))
	{
		if ((widthFirstArray == widthSecondArray) && (heightFirstArray == heightSecondArray))
		{

			int firstArray[widthFirstArray][heightFirstArray], secondArray[widthSecondArray][heightSecondArray];

			_llenarMatrices(firstArray, "primera matriz", );
			_sumaMatrices(firstArray, secondArray);
		}
		else
		{
			if (widthFirstArray == widthSecondArray)
			{
				printf("Tus matrices tienen diferente anchura, no se puede ejecutar la funcion,vuelve a dar los valores");
				return 1;
			}
			else
			{
				printf("Tus matrices tienen diferente altura, no se puede ejecutar la funcion,vuelve a dar los valores");
				return 1;
			}
		}
	}

	return 0;
}

void _sumaMatrices(int firstArray[MAX_SIZE][MAX_SIZE], int secondArray[MAX_SIZE][MAX_SIZE]) {}