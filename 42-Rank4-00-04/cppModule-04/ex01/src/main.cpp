/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-fari <rde-fari@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:32:34 by rde-fari          #+#    #+#             */
/*   Updated: 2025/12/21 17:27:26 by rde-fari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
	std::cout << "=============================================================| SCOPE 1 (What is a 'Shallow Copy')" << std::endl;
	{
		std::cout
			<< "\n\nFor simplicity, I'll only work with the ideas index '0'.\n"
			<< "This can be changed later during the evaluation if\n"
			<< "the evaluator think it's needed.\n\n";

		msg("Creating shallowCat");
		Cat *shallowCat = new Cat;

		msg("Setting shallowCat Ideas");
		// for (int i = 0; i < 10; i++) {
		// 	shallowCat->getBrain()->setIdea(i, "Main cat ideas.");
		// }
		shallowCat->getBrain()->setIdea(0, "Main cat ideas.");
		std::cout << "Idea set successfully\n";

		msg("Checking shallowCat Ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< shallowCat->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: 0 ] = "
				  << shallowCat->getBrain()->getIdea(0)
				  << "\n";

		msg("Creating shallowCatTest");
		Cat *shallowCatTest;
		shallowCatTest = shallowCat;

		msg("Checking shallowCatTest ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< shallowCatTest->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
				  << shallowCatTest->getBrain()->getIdea(0)
				  << "\n";

		msg("Changing shallowCatTest ideas");
		// for (int i = 0; i < 10; i++) {
		// 	shallowCatTest->getBrain()->setIdea(i, "Main cat ideas.");
		// }
		shallowCatTest->getBrain()->setIdea(0, "New cat ideas.");
		std::cout << "Idea changed successfully\n";

		msg("Checking new shallowCatTest ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< shallowCatTest->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
				  << shallowCatTest->getBrain()->getIdea(0)
				  << "\n";

		msg("Checking original shallowCat Ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< shallowCat->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
				  << shallowCat->getBrain()->getIdea(0)
				  << "\n";

		msg("Shallow cats go to sleep");
		delete shallowCat;
		// delete shallowCatTest; // <-- No need to free once they share the same pointer reference.
	}

	std::cout << "=============================================================| SCOPE 2 (Make sure that every copy is a deep copy)" << std::endl;
	{
		std::cout
			<< "\n\nFor simplicity, I'll only work with the ideas index '0'.\n"
			<< "This can be changed later during the evaluation if\n"
			<< "the evaluator think it's needed.\n\n";

		msg("Creating deepCat");
		Cat *deepCat = new Cat;

		msg("Setting deepCat Ideas");
		// for (int i = 0; i < 10; i++) {
		// 	deepCat->getBrain()->setIdea(i, "Main cat ideas.");
		// }
		deepCat->getBrain()->setIdea(0, "Main cat ideas.");
		std::cout << "Idea set successfully\n";

		msg("Checking deepCat Ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< deepCat->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
				  << deepCat->getBrain()->getIdea(0)
				  << "\n";

		msg("Creating deepCatTest");
		Cat *deepCatTest = new Cat(*deepCat);

		msg("Checking deepCatTest ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< deepCatTest->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
				  << deepCatTest->getBrain()->getIdea(0)
				  << "\n";

		msg("Changing deepCatTest ideas");
		// for (int i = 0; i < 10; i++) {
		// 	deepCatTest->getBrain()->setIdea(i, "Main cat ideas.");
		// }
		deepCatTest->getBrain()->setIdea(0, "New cat ideas.");
		std::cout << "Idea changed successfully.\n";

		msg("Checking new deepCatTest ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< deepCatTest->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
				  << deepCatTest->getBrain()->getIdea(0)
				  << "\n";

		msg("Checking original deepCat Ideas");
		// for (int i = 0; i < 10; i++) {
		// 	std::cout << "[Index: " << i << " ] = "
		// 	<< deepCat->getBrain()->getIdea(i)
		// 	<< "\n";
		// }
		std::cout << "[Index: " << 0 << " ] = "
				  << deepCat->getBrain()->getIdea(0)
				  << "\n";

		msg("Deep cats go to sleep.");
		delete deepCat;
		delete deepCatTest;

		msg("End of Scope");
	}

	std::cout << "=============================================================| SCOPE 3 (Subject requirements...)" << std::endl;
	{
		const Animal* animalArray[100];

		msg("Creating 50 Dogs, then 50 Cats");
		for (int i = 0; i < 100; i++) {
			if (i < 50) {
				std::cout << "[ Animal index: " << i + 1 << " ]\n";
				animalArray[i] = new Cat;
			} else {
				std::cout << "[ Animal index: " << i + 1 << " ]\n";
				animalArray[i] = new Dog;
			}
		}

		msg("Now putting all those animals to sleep");
		for (int i = 0; i < 100; i++) {
			std::cout << "[ Animal index: " << i + 1 << " ]\n";
			delete animalArray[i];
			std::cout << "\n";
		}
	}
	return (0);
}
