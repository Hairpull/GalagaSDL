#include "Bullet.h"

Bullet::Bullet() {
	
	
	mTimer = Timer::Instance();
	
	mSpeed = 1000.0f;
	
	mTexture = new Texture("bullet.png");
	mTexture->Parent(this);
	mTexture->Pos(VEC2_ZERO);
	
	
	Reload();
}

Bullet::~Bullet() {
	
	
	mTimer = NULL;
	
	delete mTexture;
	mTexture = NULL;
}



void Bullet::Fire(Vector2 pos) {

	Pos(pos);
	Active(true);
};

void Bullet::Reload() {
	
	Active(false);
}

void Bullet::Update() {
	
	if(Active()) {
		
		Translate(-VEC2_UP * mSpeed * mTimer->DeltaTime(), local);
		
		Vector2 pos = Pos();
		
		if(pos.y < -OFFSCREEN_BUFFER || pos.y > Graphics::Instance()->SCREEN_HEIGHT + OFFSCREEN_BUFFER) {
			
			Reload();
		}
		
	}
}

void Bullet::Render() {
	
	if(Active()) {
		
		mTexture->Render();
	}
	
}
