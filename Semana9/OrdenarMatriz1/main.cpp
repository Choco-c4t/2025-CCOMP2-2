// Hello World program
// ANSI Codes
// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

#include <cstdlib>
#include <ctime>
#include <iostream>

#ifdef _WIN32
    //#include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>

    #define CLEAR_COMMAND "clear"
#endif

void caratula()
{
	std::system(CLEAR_COMMAND);            // Comando para borrar todo el contenido de la pantalla
    std::cout << "\x1B[H";          // Codigo para colocar el cursor en el canto superior izquierdo

    std::cout << "\x1B[1;36;44m";         // Mostrar el siguiente texto en modo de letra italico "[3;" y color azul "[ ;34m"
	std::cout << "/***************************************************/" << std::endl;
	std::cout << "\x1B[m";             // Resetear color a valor por defecto
	std::cout << "\x1B[31;1m Universidad Catolica San Pablo \x1B[m" << std::endl;
	std::cout << "\x1B[33;1m Escuela Profesional de Ciencia de la Computacion \x1B[m" << std::endl;
	std::cout << "\x1B[37;1m Ciencia de la Computacion I - CCOMP 2.2 \x1B[m" << std::endl;
	std::cout << "\x1B[38;5;46m Prof. D.Sc. Manuel Eduardo Loaiza Fernandez \x1B[m" << std::endl;
	std::cout << "\x1B[3;38;5;160m Arequipa 2025 - II \x1B[m" << std::endl;
	std::cout << "\x1B[5;36;44m";         // Mostrar el siguiente texto en modo de letra italico "[3;" y color azul "[ ;34m"
	std::cout << "/***************************************************/" << std::endl;
	std::cout << "\x1B[m";             // Resetear color a valor por defecto
	std::cout << "\n !! Welcome to 2025 - II !! \n\n";
	return;
}

int main()
{
	caratula();

	const int tamMatriz = 8;
	const int tamVectorMayusMinus = 22;
	const int tamVectorNumeros = 20;

	// Crear una matriz 4x4 con letras mayusculas, minusculas y numeros
	char LetrasNumeros[tamMatriz][tamMatriz];
	char tmpMayusculas[tamVectorMayusMinus];
	char tmpMinusculas[tamVectorMayusMinus];
	char tmpNumeros[tamVectorNumeros];

	// semilla aleatoria
	std::srand(std::time({})); // use current time as seed for random generator


	for(int i{0}; i < tamVectorMayusMinus; i++)
	{
		int random_value = std::rand() % 26;

		if( random_value < 26 && random_value >= 0 )
		{	// Llenar array de letras mayusculas
			tmpMayusculas[i] = 65 + random_value; // A - Z -> ASCII : 65-90
			std::cout<<" Letra mayuscula: " << tmpMayusculas[i] << std::endl;
		}
		else
		{
			std::cout<<" NUNCA DEBIO PASAR MAYUSCULA" << std::endl;
		}

		random_value = std::rand() % 26;

		if( random_value < 26 && random_value >= 0 )
		{	// Llenar array de letras minusculas
			tmpMinusculas[i] = 97 + random_value; // a - z -> ASCII : 97-122
			std::cout<<" Letra minuscula: " << tmpMinusculas[i] << std::endl;
		}
		else
		{
			std::cout<<" NUNCA DEBIO PASAR MINUSCULA" << std::endl;
		}
	}

	for(int i{0}; i < tamVectorNumeros; i++)
	{
		int random_value = std::rand() % 10;

		if( random_value < 10 && random_value >= 0 )
		{	// Llenar array con numeros
			tmpNumeros[i] = 48 + random_value; // A - Z -> ASCII : 65-90
			std::cout<<" Numeros: " << tmpNumeros[i] << std::endl;
		}
		else
		{
			std::cout<<" NUNCA DEBIO PASAR NUMEROS" << std::endl;
		}
	}

	int idxMayus{0}, idxMinus{0}, idxNum{0};
	for(int i{0};i<tamMatriz;i++)
	{
		for(int j{0};j<tamMatriz;j++)
		{
			bool fueAsignadoIndice{true};
			do
			{
				// aleatoriamente descubrir de cual de los 3 arrays saco informacion
				int option{0};
				option = std::rand() % 3;

				switch (option)
				{
					case 0:
						if(idxMayus < tamVectorMayusMinus )
						{
							LetrasNumeros[i][j] = tmpMayusculas[idxMayus];
							idxMayus++;
							fueAsignadoIndice = false;
						}
						else
						{
							fueAsignadoIndice = true;
						}

						break;
					case 1:
						if(idxMinus < tamVectorMayusMinus )
						{
							LetrasNumeros[i][j] = tmpMinusculas[idxMinus];
							idxMinus++;
							fueAsignadoIndice = false;
						}
						else
						{
							fueAsignadoIndice = true;
						}
						break;
					case 2:
						if(idxNum < tamVectorNumeros )
						{
							LetrasNumeros[i][j] = tmpNumeros[idxNum];
							idxNum++;
							fueAsignadoIndice = false;
						}
						else
						{
							fueAsignadoIndice = true;
						}
						break;
					default:
						std::cout<<" NUNCA DEBIO PASAR SWITCH" << std::endl;
				}
			}while(fueAsignadoIndice); // salgo cuando el no fue asignado aun el indice escojido de forma aleatoria entre los
			// arrays que guardan las letras mayusculas, minusculas y numeros

		}
	}

	std::cout<<"Indices :" << idxMayus <<" - "<< idxMinus<<" - "<<idxNum<< std::endl;
	for(int i{0};i<tamMatriz;i++)
	{
		for(int j{0};j<tamMatriz;j++)
		{
			std::cout<< LetrasNumeros[i][j] << " | " ;
		}

		std::cout<<std::endl;
	}

	char LetrasNumerosOrdenado[tamMatriz][tamMatriz];
	for(int i{0};i<tamMatriz;i++)
	{
		for(int j{0};j<tamMatriz;j++)
		{
			LetrasNumerosOrdenado[i][j] = '-';
		}
	}
	idxMayus=0; idxMinus=0; idxNum=0;

	std::cout<<"\n Antes de ordenar: "<<std::endl;
	for(int i{0};i<tamVectorMayusMinus;i++)
	{
		std::cout<< tmpMayusculas[i] << " , ";
	}

	// Colocar ordenado nuestros caracteres en la matriz
	for(int i{0};i<tamVectorMayusMinus;i++)
	{
		for(int j=i;j<tamVectorMayusMinus;j++)
		{
			if(tmpMayusculas[i] < tmpMayusculas[j])
			{
				char tmp = tmpMayusculas[i];
				tmpMayusculas[i] = tmpMayusculas[j];
				tmpMayusculas[j] = tmp;
			}
		}
	}

	std::cout<<"\n Despues de ordenar: "<<std::endl;
	for(int i{0};i<tamVectorMayusMinus;i++)
	{
		std::cout<< tmpMayusculas[i] << " , ";
	}

	std::cout<<"\n Antes de ordenar: "<<std::endl;
	for(int i{0};i<tamVectorMayusMinus;i++)
	{
		std::cout<< tmpMinusculas[i] << " , ";
	}

	// Colocar ordenado nuestros caracteres en la matriz
	for(int i{0};i<tamVectorMayusMinus;i++)
	{
		for(int j=i;j<tamVectorMayusMinus;j++)
		{
			if(tmpMinusculas[i] > tmpMinusculas[j])
			{
				char tmp = tmpMinusculas[i];
				tmpMinusculas[i] = tmpMinusculas[j];
				tmpMinusculas[j] = tmp;
			}
		}
	}

	std::cout<<"\n Despues de ordenar: "<<std::endl;
	for(int i{0};i<tamVectorMayusMinus;i++)
	{
		std::cout<< tmpMinusculas[i] << " , ";
	}

	std::cout<<"\n Antes de ordenar: "<<std::endl;
	for(int i{0};i<tamVectorNumeros;i++)
	{
		std::cout<< tmpNumeros[i] << " , ";
	}

	// Colocar ordenado nuestros caracteres en la matriz
	for(int i{0};i<tamVectorNumeros;i++)
	{
		for(int j=i;j<tamVectorNumeros;j++)
		{
			if(tmpNumeros[i] > tmpNumeros[j])
			{
				char tmp = tmpNumeros[i];
				tmpNumeros[i] = tmpNumeros[j];
				tmpNumeros[j] = tmp;
			}
		}
	}

	std::cout<<"\n Despues de ordenar: "<<std::endl;
	for(int i{0};i<tamVectorNumeros;i++)
	{
		std::cout<< tmpNumeros[i] << " , ";
	}

	idxMayus = 0, idxMinus = 0, idxNum = 0;
	for(int i{0};i<tamMatriz;i++)
	{
		for(int j{0};j<tamMatriz;j++)
		{
			char tmp{'@'};
			if(idxMinus < tamVectorMayusMinus)
			{
				 LetrasNumerosOrdenado[i][j] = tmpMinusculas[idxMinus];
				 idxMinus++;
			}
			else if(idxMayus < tamVectorMayusMinus)
			{
				 LetrasNumerosOrdenado[i][j] = tmpMayusculas[idxMayus];
				 idxMayus++;
			}
			else if(idxNum < tamVectorNumeros)
			{
				 LetrasNumerosOrdenado[i][j] = tmpNumeros[idxNum];
				 idxNum++;
			}
			else
			{
				std::cout<<" NUNCA DEBIO PASAR SWITCH" << std::endl;
			}
		}

	}

	std::cout<<"\nDespues de reordenar matriz Indices :" << idxMayus <<" - "<< idxMinus<<" - "<<idxNum<< std::endl;
	for(int i{0};i<tamMatriz;i++)
	{
		for(int j{0};j<tamMatriz;j++)
		{
			std::cout<< LetrasNumerosOrdenado[i][j] << " | " ;
		}

		std::cout<<std::endl;
	}

	return 0;
}
