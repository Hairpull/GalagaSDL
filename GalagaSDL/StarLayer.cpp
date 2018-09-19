#include "StarLayer.h"

StarLayer::StarLayer(int layer) {
	
	for(int i = 0; i < STAR_COUNT; i++)
		mStars[i] = new Star(layer);
	
}

StarLayer::~StarLayer() {
	
	
	for(int i = 0; i < STAR_COUNT; i++) {
	
		delete mStars[i];
		mStars[i] = NULL;
	}
}

void StarLayer::Update() {
	
	for(int i = 0; i < STAR_COUNT; i++)
		mStars[i]->Update();
}

void StarLayer::Render() {
	
	for(int i = 0; i < STAR_COUNT; i++)
		mStars[i]->Render();
	  
}
