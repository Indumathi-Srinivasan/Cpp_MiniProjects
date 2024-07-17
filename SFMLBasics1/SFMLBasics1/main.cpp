

#include<SFML/Graphics.hpp>
#include<iostream>

int main(int argc, char* argv[])
{

	const int wWidth = 1280;
	const int wHeight = 720;

	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML!");   

	window.setFramerateLimit(60);

	int r = 0;
	int g = 255;
	int b = 255;


	
	sf::CircleShape circle(50); 

	circle.setFillColor(sf::Color(r, g, b)); 
	circle.setPosition(300.0f, 300.0f);   
	float circleMoveSpeed = 0.5f;       







	sf::Vector2f rectSize(160.0f, 60.0f);
	sf::RectangleShape rect(rectSize);

	rect.setPosition(500, 200);
	rect.setFillColor(sf::Color::Magenta);
	rect.setOutlineColor(sf::Color::White);
	rect.setOutlineThickness(5);
	float rectMoveSpeed = 1.0f;




	sf::Font myfont;


	if (!myfont.loadFromFile("arial.ttf"))
	{
		std::cerr << "Could not load font!\n";
		exit(1);
	}

	sf::Text text("Moving Teal circle", myfont, 24);
	text.setPosition(1, wHeight - ((float)text.getCharacterSize()+8));

	//std::cout << text.getCharacterSize();

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
				std::cout << "Key pressed with code= " << event.key.code << "\n";
				if (event.key.code == sf::Keyboard::X)
				{
					std::cout << "Pressed close key" << std::endl;
					circleMoveSpeed *= -1.0f; //reverse the direction of circle on the screen
				}

			}
		}


		circle.setPosition(circle.getPosition().x - circleMoveSpeed, circle.getPosition().y - circleMoveSpeed);
		rect.setPosition(rect.getPosition().x + rectMoveSpeed, rect.getPosition().y + rectMoveSpeed);
		rect.rotate(0.5);


		//basic rendering function call

		window.clear(); //clear the window.
		window.draw(circle);//draw the circle
		window.draw(rect);
		window.draw(text);  //draw the text
		window.display(); //call the window display function



	}


	return 0;
}