#include "Wasp.h"

std::vector<std::vector<Vector2>> Wasp::sDivePaths;

void Wasp::CreateDivePaths(){
	
	int currentPath = 0;
	BezierPath* path = new BezierPath();
	
	path->AddCurve({ Vector2(0.0f, 0.0f), Vector2(0.0f, -45.0f), Vector2(-60.0f, -45.0f), Vector2(-60.0f, 0.0f) }, 15);
	path->AddCurve({ Vector2(-60.0f, 0.0f), Vector2(-60.0f, 80.0f), Vector2(0.0f, 150.0f), Vector2(100.0f, 150.0f) }, 15);
	path->AddCurve({ Vector2(100.0f, 150.0f), Vector2(250.0f, 150.0f), Vector2(350.0f, 200.0f), Vector2(350.0f, 350.0f) }, 15);
	path->AddCurve({ Vector2(350.0f, 350.0f), Vector2(350.0f, 575.0f), Vector2(100.0f, 575.0f), Vector2(100.0f, 350.0f) }, 15);


	
	
	
	sDivePaths.push_back(std::vector<Vector2>());
	path->Sample(&sDivePaths[currentPath]);
	delete path;
	
	
	currentPath = 1;
	path = new BezierPath();
	

	path->AddCurve({ Vector2(0.0f, 0.0f), Vector2(0.0f, -45.0f), Vector2(60.0f, -45.0f), Vector2(60.0f, 0.0f) }, 15);
	path->AddCurve({ Vector2(60.0f, 0.0f), Vector2(60.0f, 80.0f), Vector2(0.0f, 150.0f), Vector2(-100.0f, 150.0f) }, 15);
	path->AddCurve({ Vector2(-100.0f, 150.0f), Vector2(-250.0f, 150.0f), Vector2(-350.0f, 200.0f), Vector2(-350.0f, 350.0f) }, 15);
	path->AddCurve({ Vector2(-350.0f, 350.0f), Vector2(-350.0f, 575.0f), Vector2(-100.0f, 575.0f), Vector2(-100.0f, 350.0f) }, 15);



	
	
	sDivePaths.push_back(std::vector<Vector2>());
	path->Sample(&sDivePaths[currentPath]);
	
	
	delete path;
	
}

Wasp::Wasp(int index, int path, bool challengeStage, bool diver)
	: Enemy(index, path, challengeStage)
{

	
	mDiver = diver;
	
	mTextures[0] = new Texture("wasp1.png");
	mTextures[0]->Parent(this);
	mTextures[0]->Pos(VEC2_ZERO);

	mTextures[1] = new Texture("wasp2.png");
	mTextures[1]->Parent(this);
	mTextures[1]->Pos(VEC2_ZERO);
	
	mType = wasp;
	
	
}

Wasp::~Wasp() {
	
	
}


void Wasp::PathComplete() {
	
	Enemy::PathComplete();
	
}

void Wasp::FlyInComplete() {
	
	if(mDiver)
		mCurrentState = dead;
	else
		JoinFormation();
	
}


Vector2 Wasp::LocalFormationPosition() {
	
	Vector2 retVal;
	
	retVal.x = (sFormation->GridSize().x + sFormation->GridSize().x * 2 * (mIndex / 4)) * pow(-1, mIndex % 2 +1);
	retVal.y = sFormation->GridSize().y * 2 + sFormation->GridSize().y * ((mIndex % 4) / 2 );
	
	return retVal;
	
}

void Wasp::HandleDiveState() {
	
	int currentPath = mIndex % 2;
	
	if(mCurrentWaypoint < sDivePaths[currentPath].size()) {
		
		Vector2 waypointPos = mDiveStartPosition + sDivePaths[currentPath][mCurrentWaypoint];
		
		Vector2 dist = waypointPos - Pos();
		Translate(dist.Normalized() * mTimer->DeltaTime() * mSpeed, world);
		
		Rotation(atan2(dist.y, dist.x) * RAD_TO_DEG + 90.0f);
		
		if((waypointPos -Pos()).MagnitudeSqr() < EPSILON)
			mCurrentWaypoint++;
	} else {
		
		Vector2 dist = WorldFormationPosition() - Pos();
		Translate(dist.Normalized() * mTimer->DeltaTime() * mSpeed, world);
		
		Rotation(atan2(dist.y, dist.x) * RAD_TO_DEG + 90.0f);
		
		if(dist.MagnitudeSqr() < EPSILON)
			JoinFormation();
		
	}
	
	
}


void Wasp::HandleDeadState() {
	
	
	
}

void Wasp::RenderDiveState() {
	
	mTextures[0]->Render();

	int currentPath = mIndex % 2;
	
	for(int i = 0; i < sDivePaths[currentPath].size() - 1; i++) {
		
		Graphics::Instance()->DrawLine(mDiveStartPosition.x + sDivePaths[currentPath][i].x, mDiveStartPosition.y + sDivePaths[currentPath][i].y,
									   mDiveStartPosition.x + sDivePaths[currentPath][i + 1].x, mDiveStartPosition.y + sDivePaths[currentPath][i + 1].y);
	}
	
	Vector2 finalPos = WorldFormationPosition();
	
	Vector2 pathEndPos = mDiveStartPosition + sDivePaths[currentPath][sDivePaths[currentPath].size() - 1];
	
	Graphics::Instance()->DrawLine(pathEndPos.x, pathEndPos.y, finalPos.x, finalPos.y);
	
}

void Wasp::RenderDeadState() {
	
	
}
