#pragma once
#include "Vector2.h"
//#include "Player.h"

class Enemy;

	class Light {
	public:
		Light();
		void Update(int dir,Vector2 pos);
		void Draw(int dir);
		void Initialize();

		Vector2 GetLightPos() { return pos_; }
		int GetLightRadius() { return radius_; }

		/*Player* player = new Player();*/

		//float left;
		//float right;
		//float top;
		//float bottom;

	private:
		
		Vector2 pos_;
		float speed_;
		int radius_;
		bool shot = false;

		//float w;
		//float h;

	};


