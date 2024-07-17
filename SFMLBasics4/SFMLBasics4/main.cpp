
//Reading shape properties from text file

#include<SFML/Graphics.hpp>        
#include<iostream>
#include<fstream>

int main()
{
	
	std::ifstream fin("shapeProperty.txt");
	std::vector<sf::Shape*> Circlevector;                              
	std::vector<sf::Shape*> Recvector;


	if (!fin.is_open())
	{
		std::cerr << "could not open file" << std::endl;
	}


	int rad, pos_x, pos_y, c1, c2, c3;
	float size_x, size_y;


	for (int i = 0; i < 3; i++)          //For Circles
	{

		fin >> rad >> pos_x >> pos_y >> c1 >> c2 >> c3;                        
		sf::Shape* circ = new sf::CircleShape(rad);                             
		circ->setPosition(pos_x, pos_y);                                          
		circ->setFillColor(sf::Color(c1, c2, c3));                                 
		Circlevector.push_back(circ);                                                


	}

	for (int j = 0; j < 4; j++)      //For rectangles
	{

		fin >> size_x >> size_y >> pos_x >> pos_y >> c1 >> c2 >> c3;
		sf::Vector2f size(size_x, size_y);
		sf::Shape* rec = new sf::RectangleShape(size);
		rec->setPosition(pos_x, pos_y);
		rec->setFillColor(sf::Color(c1, c2, c3));
		Recvector.push_back(rec);
	}








	const int wWidth = 1300;
	const int wHeight = 800;
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML");           
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

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::X)
				{
					window.close();
				}

			}
		}


		window.clear();


		for (auto i : Circlevector)
		{
			window.draw(*i);
			i->rotate(0.15);
			i->setPosition(i->getPosition().x + 1, i->getPosition().y + 0.2);


		}
		for (auto i : Recvector)
		{
			window.draw(*i);
			i->rotate(0.15);
			i->setPosition(i->getPosition().x - 0.10, i->getPosition().y - 0.2);

		}
		window.display();





	}


	for (auto& i : Circlevector)
	{
		delete i;
	}
	for (auto& i : Recvector)
	{
		delete i;
	}



	return 0;
}