#pragma once
#include "Vector2.h"
//#include "Player.h"

class Enemy;

	class Light {
	public:
		Light();
		void Update(int dir,Vector2 pos);
		void Draw(int dir);
		Enemy* enemy_ = nullptr;
		void Initialize();

		Vector2 GetLightPos() { return pos_; }
		Vector2 GetLightSize() { return size_; }
		bool GetIsHit() { return isHit_; }
		bool SetIsHit(bool isHit) { return isHit_ = isHit; }

		/*Player* player = new Player();*/

		//float left;
		//float right;
		//float top;
		//float bottom;

	private:
		
		Vector2 pos_;
		float speed_;
		Vector2 size_;
		bool shot = false;
		bool isHit_ = false;

		//float w;
		//float h;

	};


