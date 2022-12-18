#include "Pen.h"

class Engine22Game : public Pen::PenApp
{
public:
	Engine22Game()
	{
		Pen::PenWindow::GetWindow()->SetKeyPressedCallback(
			[this](const Pen::KeyPressedEvent& event) {OnKeyPress(event); });

		Pen::PenWindow::GetWindow()->SetKeyReleasedCallback(
			[this](const Pen::KeyReleasedEvent& event) {OnKeyRelease(event); });

		Player.SetCoord(400, 0, 1);
		laser.SetCoord(Player.GetX() + (Player.GetWidth() / 2), Player.GetY() + Player.GetHeight(), 1);
		GOimage.SetCoord((Pen::PenWindow::GetWindow()->GetWidth() - GOimage.GetWidth()) / 2, 
			(Pen::PenWindow::GetWindow()->GetHeight() - GOimage.GetHeight()) / 2, 1);
		srand(time(NULL));
		frames = 0;
	}

	void OnUpdate() override
	{
		if (GameOver == true)
		{
			GOimage.Draw();
			return;
		}

		//value can be changed to determine how fast enemies spawn
		//higher means slower spawn rate
		if (frames % 10 == 0)
		{
			Pen::Unit enemy{ "Assets/Textures/enemy.png" };
			enemy.SetCoord(std::rand() % (Pen::PenWindow::GetWindow()->GetWidth() - enemy.GetWidth()), Pen::PenWindow::GetWindow()->GetHeight(), 1);
			enemy.SetID(UnitID);
			UnitID++;
			Enemies.emplace_back(enemy);
		}
		frames++;
		
		
		if (state == CharState::MOVE_RIGHT && Player.GetX() < Pen::PenWindow::GetWindow()->GetWidth() - Player.GetWidth())
		{
			Player.ChangeX(playerSpeed);
		}
		else if (state == CharState::MOVE_LEFT && Player.GetX() > 0)
		{
			Player.ChangeX(-playerSpeed);
		}
		else if (state == CharState::MOVE_UP && Player.GetY() < Pen::PenWindow::GetWindow()->GetHeight() - Player.GetHeight())
		{
			Player.ChangeY(playerSpeed);
		}
		else if (state == CharState::MOVE_DOWN && Player.GetY() > 0)
		{
			Player.ChangeY(-playerSpeed);
		}
		Player.Draw();
		
		//Enemy loop
		for (auto& Unit : Enemies)
		{
			if (shoot == true) //allows for laser movement
			{
				laser.ChangeY(enemySpeed);
				laser.Draw();
			}
			
			//game over if player touches enemy
			if (Player.OverlapWith(Unit))
			{
				GameOver = true;
			}

			Unit.ChangeY(-enemySpeed);
			Unit.Draw();

			if (Unit.GetY() < 0 - Unit.GetHeight()) //if enemy goes off screen, delete from vector
			{
				Enemies.erase(Enemies.begin());
			}
			
			//if laser goes off screen, redraw laser
			if (laser.GetY() > Pen::PenWindow::GetWindow()->GetHeight() - laser.GetHeight())
			{
				laser.Delete();
				laser.SetCoord(Player.GetX() + (Player.GetWidth() / 2), Player.GetY() + Player.GetHeight(), 1);
			}
			//deletes both enemy and laser if they collide
			if (laser.OverlapWith(Unit))
			{
				//for loop used to delete specific enemy that collided with laser, hence the use of Unit ID
				for (int i = 0; i < Enemies.size(); i++)
				{
					if (Enemies[i].GetID() == Unit.GetID())
					{
						Enemies.erase(Enemies.begin() + i);
					}
				}
				//redraw laser
				laser.Delete();
				laser.SetCoord(Player.GetX() + (Player.GetWidth() / 2), Player.GetY() + Player.GetHeight(), 1);
			}
		}
	}
private:
	Pen::Unit Player{ "Assets/Textures/player.png" };
	Pen::Unit laser{ "Assets/Textures/laser.png" };
	Pen::Unit GOimage{ "Assets/Textures/gameover.png" };
	std::vector<Pen::Unit> Enemies;
	int playerSpeed{ 20 };
	int enemySpeed{ 10 };
	bool GameOver = false;
	int frames;
	bool shoot = true;
	int UnitID = 0;

	enum class CharState {
		MOVE_LEFT,
		MOVE_RIGHT,
		MOVE_UP,
		MOVE_DOWN,
		STILL
	} state{ CharState::STILL };

	void OnKeyPress(const Pen::KeyPressedEvent& event)
	{
		switch (event.GetKeyCode())
		{
		case PEN_KEY_LEFT:
			state = CharState::MOVE_LEFT;
			break;
		case PEN_KEY_RIGHT:
			state = CharState::MOVE_RIGHT;
			break;
		case PEN_KEY_UP:
			state = CharState::MOVE_UP;
			break;
		case PEN_KEY_DOWN:
			state = CharState::MOVE_DOWN;
			break;
		}
	}

	void OnKeyRelease(const Pen::KeyReleasedEvent& event)
	{
		switch (event.GetKeyCode())
		{
		case PEN_KEY_LEFT:
			if (state == CharState::MOVE_LEFT)
				state = CharState::STILL;
			break;
		case PEN_KEY_RIGHT:
			if (state == CharState::MOVE_RIGHT)
				state = CharState::STILL;
			break;
		case PEN_KEY_UP:
			if (state == CharState::MOVE_UP)
				state = CharState::STILL;
			break;
		case PEN_KEY_DOWN:
			if (state == CharState::MOVE_DOWN)
				state = CharState::STILL;
			break;
		}
	}


};

START_PEN_GAME(Engine22Game)
