#include "Enemy.h"

std::vector<std::vector<Vector2>> Enemy::sPaths;

void Enemy::CreatePaths() {
	
	int screenMidPoint = Graphics::Instance()->SCREEN_WIDTH * 0.4f;
	
	
	
	int currentPath = 0;
	BezierPath* path = new BezierPath();
	path->AddCurve({Vector2(screenMidPoint + 50.0f, -10.0f), Vector2(screenMidPoint + 50.0f, -20.0f), Vector2(screenMidPoint + 50.0f, 30.0f), Vector2(screenMidPoint + 50.0f, 20.0f) }, 1);
	path->AddCurve({Vector2(screenMidPoint + 50.0f, 20.0f), Vector2(screenMidPoint + 50.0f, 100.0f), Vector2(75.0f, 325.0f), Vector2(75.0f, 425.0f) }, 25);
	path->AddCurve({Vector2(75.0f, 425.0f), Vector2(75.0f, 650.0f), Vector2(325.0f, 650.0f), Vector2(350.0f, 425.0f) }, 25);


	
	sPaths.push_back(std::vector<Vector2>());
	path->Sample(&sPaths[currentPath]);
	
	delete path;
	
}

Enemy::Enemy(int path) {
	
	mTimer = Timer::Instance();
	
	mCurrentPath = path;
	
	mCurrentState = flyIn;
	
	mCurrentWaypoint = 0;
	Pos(sPaths[mCurrentPath][mCurrentWaypoint]);
	
	
	mTexture = new Texture("butterfly.png");
	mTexture->Parent(this);
	mTexture->Pos(VEC2_ZERO);
	
	mSpeed = 400.0f;
	
}

Enemy::~Enemy() {
	
	mTimer = NULL;
	
	delete mTexture;
	mTexture = NULL;
}


void Enemy::HandleFlyInState() {
	
	if((sPaths[mCurrentPath][mCurrentWaypoint] - Pos()).MagnitudeSqr() < EPSILON)
		mCurrentWaypoint++;
	
	if(mCurrentWaypoint < sPaths[mCurrentPath].size()) {
		
		Vector2 dist = sPaths[mCurrentPath][mCurrentWaypoint] - Pos();
		Translate(dist.Normalized() * mTimer->DeltaTime() * mSpeed, world);
		
		
			Rotation(atan2(dist.y, dist.x) * RAD_TO_DEG + 90.0f);
		
	} else {
		
		mCurrentState = formation;
	}
	
}



void Enemy::HandleFormationState() {
	
	
	
	
	
}


void Enemy::HandleDiveState() {
	
	
	
}


void Enemy::HandleDeadState() {
	
	
	
}




void Enemy::HandleStates() {
	
	
	switch(mCurrentState) {
		
	case flyIn:
			
		HandleFlyInState();
		break;
		
	case formation:
		
		HandleFormationState();
		break;
		
	case dive:
		
		HandleDiveState();
		break;
		
	case dead:
		
		HandleDeadState();
		break;
	}
}


void Enemy::Update() {
	
if(Active())
	HandleStates();
	
}

void Enemy::Render() {
	
	if(Active()) {
		
		mTexture->Render();
		
		for(int i = 0; i < sPaths[mCurrentPath].size() - 1; i++) {
			
			Graphics::Instance()->DrawLine(sPaths[mCurrentPath][i].x, sPaths[mCurrentPath][i].y, sPaths[mCurrentPath][i + 1].x, sPaths[mCurrentPath][i + 1].y);
		}
	}
	
}


