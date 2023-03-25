#include "BSTNode.hpp"
#include "BST.hpp"

int main(void)
{

	//BST<string,char>(); // code builds fine without this but when i do call it, i get errors 
	fstream convert;
	convert.open("Convert.txt", std::ios::in);

	convert.close();

	return 0;
} 