
//Shapes Properties from Users

#include<iostream>
#include<SFML/Graphics.hpp>

int main()
{

	int circle, rect;
	std::cout << "Enter no of circle:\t" << std::endl;
	std::cin >> circle;
	std::cout << "Enter no of rectangle:\t" << std::endl;
	std::cin >> rect;
	std::cout << std::endl << std::endl << std::endl;
	system("cls");



	std::vector<sf::Shape*> Shapevector;


	for (int i = 0; i < circle; i++) 
	{
		int rad, r, g, b;
		float pos_x, pos_y;

		std::cout << "\n\nEnter the properties for circle " << i + 1 << " :\n";

		std::cout << "\nEnter the rad:\n";
		std::cin >> rad;

		std::cout << "\nEnter the position x and y:\n";
		std::cin >> pos_x >> pos_y;

		std::cout << "\nEnter the rgb value:\n";
		std::cin >> r >> g >> b;


		sf::Shape* ptr = new sf::CircleShape(rad);
		ptr->setPosition(pos_x, pos_y);
		ptr->setFillColor(sf::Color(r, g, b));
		Shapevector.push_back(ptr);


	}


	for (int i = 0; i < rect; i++)  
	{
		int r, g, b;
		float size_x, size_y, pos_x, pos_y;

		std::cout << "\n\nEnter the properties for rectangle " << i + 1 << " :\n";

		std::cout << "\nEnter the size w & h:\n";
		std::cin >> size_x >> size_y;

		std::cout << "\nEnter the position x and y:\n";
		std::cin >> pos_x >> pos_y;

		std::cout << "\nEnter the rgb value:\n";
		std::cin >> r >> g >> b;


		sf::Vector2f size(size_x, size_y);
		sf::Shape* ptr = new sf::RectangleShape(size);
		ptr->setPosition(pos_x, pos_y);
		ptr->setFillColor(sf::Color(r, g, b));
		Shapevector.push_back(ptr);


	}


	int wWidth = 1280, wHeight = 880;
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Frame"); 
	window.setFramerateLimit(60);



	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}


		window.clear();

		for (auto i : Shapevector)
		{
			window.draw(*i);
			i->setPosition(i->getPosition().x + 0.5, i->getPosition().y - 0.5);
			i->rotate(0.5);
		}
		window.display();





	}


	return 0;
}