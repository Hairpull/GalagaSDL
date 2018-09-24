#include "Enemy.h"

std::vector<std::vector<Vector2>> Enemy::sPaths;
Formation* Enemy::sFormation = NULL;

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

void Enemy::SetFormation(Formation* f) {
	
	sFormation = f;
}


Enemy::Enemy(int index, int path, bool challengeStage) {
	
	mTimer = Timer::Instance();
	
	mCurrentPath = path;
	
	mCurrentState = flyIn;
	
	mCurrentWaypoint = 1;
	Pos(sPaths[mCurrentPath][0]);
	
	
	mTexture = NULL;
	
	mSpeed = 400.0f;
	
	mIndex = index;
	
	mChallengeStage = challengeStage;
	
}

Enemy::~Enemy() {
	
	mTimer = NULL;
	
	delete mTexture;
	mTexture = NULL;
}

void Enemy::PathComplete() {
	
	
	if(mChallengeStage)
		mCurrentState = dead;
}

Vector2 Enemy::FlyInTargetPosition() {
	
	return sFormation->Pos() + mTargetPosition;
}

void Enemy::FlyInComplete() {
	
	Pos(FlyInTargetPosition());
	Rotation(0);
	Parent(sFormation);
	mCurrentState = formation;
	
}


void Enemy::HandleFlyInState() {
	
	
	if(mCurrentWaypoint < sPaths[mCurrentPath].size()) {
		
		Vector2 dist = sPaths[mCurrentPath][mCurrentWaypoint] - Pos();
		Translate(dist.Normalized() * mTimer->DeltaTime() * mSpeed, world);
		
		Rotation(atan2(dist.y, dist.x) * RAD_TO_DEG + 90.0f);

		
		if((sPaths[mCurrentPath][mCurrentWaypoint] - Pos()).MagnitudeSqr() < EPSILON)
			mCurrentWaypoint++;
		
		if(mCurrentWaypoint >= sPaths[mCurrentPath].size())
			PathComplete();
		
	} else {
		
		Vector2 dist = FlyInTargetPosition() - Pos();
		Translate (dist.Normalized() * mTimer->DeltaTime() * mSpeed, world);
		
		Rotation(atan2(dist.y, dist.x) * RAD_TO_DEG + 90.0f);
		

		if(dist.MagnitudeSqr() < EPSILON)
			FlyInComplete();
	}
	
}



void Enemy::HandleFormationState() {
	
	Pos(FormationPosition());
	
	
	
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


Enemy::STATES Enemy::CurrentState() {
	
	return mCurrentState;
}

void Enemy::Update() {
	
	if(Active())
		HandleStates();
	
}

void Enemy::Render() {
	
	if(Active()) {
		
		mTexture->Render();
		
	}
	
}


