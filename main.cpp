#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <sstream>

using namespace sf;

const int W = 1200;
const int H = 700;

class Bullet {

public:
	CircleShape shape;
	Vector2f maxVelocity;
	Vector2f CurrentVelocity;
	float maxSpeed;
	Bullet(float radius = 3.f) :CurrentVelocity(maxVelocity.x, maxVelocity.y), maxSpeed(15.f) {
		this->shape.setRadius(radius);
		this->shape.setFillColor(Color::Green);
	}
};



int main()
{
	int x, y;
	
	int puan = 0;
	srand(time(0));
	float a = 10.0f,b;
	float hiz = 0.01f;
	float maxHiz = 10.0f;
	RenderWindow app(VideoMode(W, H), "Fruit Hunter!");
	app.setFramerateLimit(60);

	Text yazi;
	yazi.setCharacterSize(25);	
	std::ostringstream ssEkran;
	

	Font digital;
	digital.loadFromFile("ERASDEMI.TTF");

	yazi.setFont(digital);
	Texture t1,t2,t3,t4;
	t1.loadFromFile("images/ship.png");
	t2.loadFromFile("images/background.png");
	t3.loadFromFile("images/f1.png");
	t4.loadFromFile("images/f3.png");
	t1.setSmooth(true);
	t2.setSmooth(true);

	int getpos;

	Sprite background(t2);
	Sprite ucak(t1);
	Sprite dusman(t3);
	Sprite meyve(t4);
	ucak.setScale(0.13f, 0.13f);
	//dusman.setScale(1.f, 1.f);
	dusman.setPosition(500, 300);	
	dusman.setScale(0.5f, 0.5f);
	meyve.setPosition(780, 350);
	meyve.setScale(0.5f, 0.5f);

	Bullet b1;

	std::vector<Bullet>bullets;
	bullets.push_back(Bullet(b1));



	/////main loop/////
	while (app.isOpen())
	{
		Event event;
		while (app.pollEvent(event))
		{
			if (event.type == Event::Closed)
				app.close();	
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			app.close();
		if (Keyboard::isKeyPressed(Keyboard::Right)|| Keyboard::isKeyPressed(Keyboard::D)) {
			ucak.move(a, 0.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
			ucak.move(0.0f, a);			
		}
		if (Keyboard::isKeyPressed(Keyboard::Space))  {
			std::cout<<"Ates \n";			
		}
			
		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
			ucak.move(0.0f, -a);			
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
			ucak.move(-a, 0.0f);
			
		}
		ssEkran.str("");
		ssEkran << "Puan : " << puan;
		yazi.setString(ssEkran.str());
		
		if (ucak.getGlobalBounds().intersects(dusman.getGlobalBounds())) {
						
			puan += 10;
			ssEkran.str("");
			ssEkran << "Puan : " << puan;
			yazi.setString(ssEkran.str());
			std::cout << puan<<"\n";
			dusman.setPosition(sf::Vector2f(x, y));
			
		}
		if (ucak.getGlobalBounds().intersects(meyve.getGlobalBounds())) {
			puan += 10;
			ssEkran.str("");
			ssEkran << "Puan : " << puan;
			yazi.setString(ssEkran.str());
			std::cout << puan << "\n";
			meyve.setPosition(Vector2f(x, y));
		}

		if (Mouse::isButtonPressed(Mouse::Left)) {
			b1.shape.setPosition(ucak.getPosition());
			
			bullets.push_back(Bullet(b1));
			
			
			std::cout << "mouse tiklandi\n";
			//getpos = b1.shape.getPosition().x;
			//std::cout << getpos;
		}
		
		for (size_t i = 0; i < bullets.size(); i++)
		{
			b1.maxVelocity = Vector2f(10.f, 0.f);
			bullets[i].shape.move(bullets[i].maxVelocity);
			//b1.maxVelocity.x *= 2.f;
			if (bullets[i].shape.getGlobalBounds().intersects(dusman.getGlobalBounds())) {
				puan += 10;
				ssEkran.str("");
				ssEkran << "Puan : " << puan;
				yazi.setString(ssEkran.str());
				std::cout << puan << "\n";
				dusman.setPosition(sf::Vector2f(x, y));
				
			}
			if (bullets[i].shape.getGlobalBounds().intersects(meyve.getGlobalBounds())) {
				puan += 10;
				ssEkran.str("");
				ssEkran << "Puan : " << puan;
				yazi.setString(ssEkran.str());
				std::cout << puan << "\n";
				meyve.setPosition(Vector2f(x, y));
				
			}
			
		}
		


		x = rand() % W-40;
		y = rand() % H-40;
		
		
		//std::cout << "poz : "<<ucak.getPosition().x <<" " << ucak.getPosition().y<<"\n";
		

		//////draw//////




		app.clear();


		
		
		app.draw(background);
		for (size_t i = 0; i < bullets.size(); i++)
		{
			app.draw(bullets[i].shape);
		}
		
		app.draw(dusman);
		app.draw(meyve);
		app.draw(ucak);		
		app.draw(yazi);
		app.display();
	}

	return 0;
}
