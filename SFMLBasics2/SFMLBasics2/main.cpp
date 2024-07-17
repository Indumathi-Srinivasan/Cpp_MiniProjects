

#include<SFML/Graphics.hpp>


int main(int argc, char* argv[])
{

	const int wWidth = 1280;
	const int wHeight = 780;
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Window");
	window.setFramerateLimit(60);
	float rectMovingSpeed = 0.5f;


	std::vector<sf::RectangleShape>Rect;
	sf::Vector2f size(10, 10);

	for (int x = 0; x <= 51; x++)
	{
		for (int y = 0; y <= 25; y++)
		{

			sf::RectangleShape rect;
			rect.setSize(size);
			rect.setPosition(x * 15, y * 15);
			rect.setFillColor(sf::Color(0, y * 10, x * 5));
			Rect.push_back(rect);

		}

	}



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







		for (auto& rec : Rect)
		{
			rec.setPosition(rec.getPosition().x + rectMovingSpeed, rec.getPosition().y + rectMovingSpeed);
		}



		/*
			

				rectMovingSpeed += 0.5;
				Rect.clear(); 

				for (int x = 0; x <= 51; x++)
				{
					for (int y = 0; y <= 25; y++)
					{

						sf::RectangleShape rect;
						rect.setSize(size);
						rect.setPosition(x * 15 + rectMovingSpeed, y * 15 + rectMovingSpeed);
						rect.setFillColor(sf::Color(0, y * 10, x * 5));
						Rect.push_back(rect);

					}

				}
		*/







		window.clear();

		for (auto& rect : Rect)
		{
			//rect.rotate(5);
			window.draw(rect);

		}
		window.display();



	}

	return 0;
}