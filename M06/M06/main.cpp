#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

std::string* textures;
//TITLE; Las Asombrosas Aventuras de Rafa
int loadTextures(std::ifstream& file, int num) {

	std::string word;

	textures = new std::string[num + 1];
	textures[0] = "none";

	int counter = 1;
	while (counter < num + 1) {
		std::getline(file, word, ';');
		std::getline(file, word, ';');
		textures[counter] = word;
		std::cout << word << '\n';
		std::getline(file, word, '\n');

		counter++;
	}

	return 0;
}

int main(int argc, char* argv[])
{
	//std::ifstream ip("../M06/personas.csv");
	//std::ofstream archivo;

	//archivo.open("datos.csv");

	//archivo << "a;b;c;\n";
	//archivo << "d;e;f;\n";
	//archivo << "1;2;3.456;\n";
	//archivo.close();
	////cargaremos el proyecto dentro de objeto llamado ip el archivo personas.csv
	//std::ifstream ip("../M06/personas.csv");
	//
	//if (!ip.is_open()) {
	//	//nos permite sacar por la salida standard sacar datos(strings, etc)
	//	std::cout << "ERROR: Error al abrir el archivo" << '\n';
	//	return 1;
	//}

	//std::string nombre;
	//std::string apellido;
	//std::string edad;
	//std::string peso;

	//int edadi;
	//float pesof;


	//while (ip.good()) {
	//	std::getline(ip, nombre, ';');
	//	std::getline(ip, apellido, ';');
	//	std::getline(ip, edad, ';');
	//	std::getline(ip, peso, '\n');

	//pasamos variables int y float a stringre
	//	edadi = std::stoi(edad);
	//	pesof = std::stof(peso);
	//	


	//	std::cout << "Nombre: " << nombre << " " << apellido << "\n";
	//	std::cout << "Edad: " << edad << '\n';
	//	std::cout << "Peso: " << peso << '\n';
	//	std::cout << "=========================" << '\n';				
	//}


	////cerramos archivo
	//ip.close();

	std::ifstream game_conf("../M06/game.csv");
	
	if (!game_conf.is_open()) {
		//nos permite sacar por la salida standard sacar datos(strings, etc)
		std::cout << "ERROR: Error al abrir el archivo" << '\n';
		return 1;
	}

	std::string word;
	std::string title;
	int textures_n = 0;

	while (game_conf.good())
	{
		

		//std::getline(game_conf, word, '\n');  si ponemos el \n cargará toda la frase hasta encontrar el salto de línea y saltara.
		std::getline(game_conf, word, ';');

		if (word.compare("TEXTURES") == 0) {
			std::getline(game_conf, word, ';');
			textures_n = std::stoi(word);
			std::getline(game_conf, word, '\n');

			loadTextures(game_conf, textures_n);
		}
		else if (word.compare("TITLE") == 0) {
			std::getline(game_conf, title, ';');
			std::getline(game_conf, word, '\n');
			
			std::cout << title << std::endl;
		}
		
	}
}
