#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Usage: ./btc [file]" << std::endl;
		return 1;
	}

	if(!BitcoinExchange::init()){
		std::cout << "Error: could not open database." << std::endl;
		return 1;
	}

	if (!BitcoinExchange::run(argv[1])){
		std::cout << "Error: could not open input file." << std::endl;
		return 1;
	}

	return 0;
}