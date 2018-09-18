#include "GameEntity.h"
#include <stdio.h>

GameEntity::GameEntity(float x, float y) {
	
	mPos.x = x;
	mPos.y = y;
	
	mRotation = 0.0f;
	
	mActive = true;
	
	mParent = NULL;
	
	mScale = VEC2_ONE;
	
}


GameEntity::~GameEntity() {
	
	mParent = NULL;
	
}

void GameEntity::Pos(Vector2 pos) {
	
	mPos = pos;
	
}

Vector2 GameEntity::Pos(SPACE space) {
	
	if(space == local || mParent == NULL)
		return mPos;
	
	Vector2 parentScale = mParent->Scale(world);
	Vector2 rotPos = RotateVector(mPos, mParent->Rotation(local));
	
	
	return mParent->Pos(world) + Vector2(rotPos.x * parentScale.x, rotPos.y *parentScale.y);
}



void GameEntity::Rotation(float r) {
	
	mRotation = r;
	
	if(mRotation > 360.0f)
		mRotation -= 360;
	
	if(mRotation < 0.0f)
		mRotation += 360;
}



float GameEntity::Rotation(SPACE space) {
	if(space == local || mParent == NULL)
		return mRotation;
	
	return mParent->Rotation(world) + mRotation;
}


void GameEntity::Scale(Vector2 scale) {
	
	mScale = scale;
}

Vector2 GameEntity::Scale(SPACE space) {

	if(space == local || mParent == NULL)
		return mScale;
	
	Vector2 parentScale = mParent->Scale(world);
	
	return Vector2(parentScale.x * mScale.x, parentScale.y * mScale.y);
}


void GameEntity::Active(bool active) {
	
	mActive = active;
}



bool GameEntity::Active() {
	
	return mActive;
}


void GameEntity::Parent(GameEntity* parent) {

	
	mPos = Pos(world) - parent->Pos(world);
	
	
	mParent = parent;
}


GameEntity* GameEntity::Parent() {
	
	return mParent;
}


void GameEntity::Translate(Vector2 vec) {
	
	mPos += vec;
	
}

void GameEntity::Rotate(float amount) {
	
	mRotation += amount;
}


void GameEntity::Update() {
	
	
}

void GameEntity::Render() {
	
	
}




