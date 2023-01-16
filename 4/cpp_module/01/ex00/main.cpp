#include "Zombie.hpp"

#include <iostream>

void leaks(void) { system("leaks BraiiiiiiinnnzzzZ"); }

int main(){
	Zombie *z = Zombie::newZombie("dude");
	z->announce();
	delete(z);

	Zombie a("guy");
	Zombie::randomChump("man");
}