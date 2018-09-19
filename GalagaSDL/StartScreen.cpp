#include"StartScreen.h"

StartScreen::StartScreen() {
	
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	
	
		//Top bar entities
	
	mTopBar = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, 80.0f));
	mPlayerOne = new Texture("1UP", "emulogic.ttf", 32, {200, 0, 0 });
	mHiScore = new Texture("HI-SCORE", "emulogic.ttf", 32, {200, 0, 0 });
	mPlayerTwo = new Texture("2UP", "emulogic.ttf", 32, {200, 0, 0 });
	
	mPlayerOne->Parent(mTopBar);
	mHiScore->Parent(mTopBar);
	mPlayerTwo->Parent(mTopBar);
	
	mPlayerOne->Pos(Vector2(-Graphics::Instance()->SCREEN_WIDTH*0.35f, 0.0f));
	mHiScore->Pos(Vector2(-30.0f, 0.0f));
	mPlayerTwo->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.2f, 0.0f));
	
	mTopBar->Parent(this);
	
	
	
		// logo entities
	mLogo = new Texture("galagalogo.png", 0, 0, 360, 180);
	mAnimatedLogo = new AnimatedTexture("galagalogo.png", 0, 0, 360, 180, 3, 0.32f, AnimatedTexture::vertical);
	
	mLogo->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.32f));
	mAnimatedLogo->Pos(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, Graphics::Instance()->SCREEN_HEIGHT * 0.32f));


	mLogo->Parent(this);
	mAnimatedLogo->Parent(this);
	
	
	
	
	
		//Play mode entities
	mPlayModes = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, Graphics::Instance()->SCREEN_HEIGHT*0.55f));
	mOnePlayerMode = new Texture("1 Player", "emulogic.ttf", 32, { 230, 230, 230 });
	mTwoPlayerMode = new Texture("2 Players", "emulogic.ttf", 32, { 230, 230, 230 });
	mCursor = new Texture("Cursor.png");
	
	mOnePlayerMode->Parent(mPlayModes);
	mTwoPlayerMode->Parent(mPlayModes);
	mCursor->Parent(mPlayModes);
	
	mOnePlayerMode->Pos(Vector2( -18.0f, -35.0f));
	mTwoPlayerMode->Pos(Vector2(0.0f, 35.0f));
	mCursor->Pos(Vector2(-175.0f, -35.0f));
	
	mPlayModes->Parent(this);
	
	
	mCursorStartPos = Vector2(mCursor->Pos(local));
	mCursorOffset = Vector2(0.0f, 70.0f);
	mSelectedMode = 0;
	
	
		//Bottom bar entities
	

	mBotBar = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, Graphics::Instance()->SCREEN_HEIGHT*0.7f));
	mNamco = new Texture("namcot", "namco__.ttf", 36, { 200, 0, 0 });
	mDates = new Texture("1981 1985 NAMCO LTD.", "emulogic.ttf", 32, {230, 230, 230 });
	mRights = new Texture("ALL RIGHTS RESERVED", "emulogic.ttf", 32, { 230, 230, 230 });
	
	mNamco->Parent(mBotBar);
	mDates->Parent(mBotBar);
	mRights->Parent(mBotBar);
	
	mNamco->Pos(VEC2_ZERO);
	mDates->Pos(Vector2(0.0f, 90.0f));
	mRights->Pos(Vector2(0.0f, 170.0f));


	mBotBar->Parent(this);
	
		//Screen animation variables
	
	mAnimationStartPos = Vector2( 0.0f, Graphics::Instance()->SCREEN_HEIGHT);
	mAnimationEndPos = VEC2_ZERO;
	mAnimationTotalTime = 5.0f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;
	
	
	Pos(mAnimationStartPos);
	
}

StartScreen::~StartScreen() {
	
		//Freeing top bar entities
	delete mTopBar;
	mTopBar = NULL;
	delete mPlayerOne;
	mPlayerOne = NULL;
	delete mHiScore;
	mHiScore = NULL;
	delete mPlayerTwo;
	mPlayerTwo = NULL;

		//freeing logo entities
	
	delete mLogo;
	mLogo = NULL;
	
	delete mAnimatedLogo;
	mAnimatedLogo = NULL;
	
	
	
		//Freeing play mode entities
	
	delete mPlayModes;
	mPlayModes = NULL;
	delete mOnePlayerMode;
	mOnePlayerMode = NULL;
	delete mTwoPlayerMode;
	mTwoPlayerMode = NULL;
	delete mCursor;
	mCursor = NULL;
	
		//freeing bottom bar entities
	
	delete mBotBar;
	mBotBar = NULL;
	delete mNamco;
	mNamco = NULL;
	delete mDates;
	mDates = NULL;
	delete mRights;
	mRights = NULL;
	
}

void StartScreen::ChangeSelectedMode(int change) {
	
	mSelectedMode += change;
	
	if(mSelectedMode < 0)
		mSelectedMode = 1;
	else if(mSelectedMode > 1 )
		mSelectedMode = 0;
	
	mCursor->Pos(mCursorStartPos + mCursorOffset * mSelectedMode);
	
}

void StartScreen::Update() {
	
	
	if(!mAnimationDone) {
		
		mAnimationTimer += mTimer->DeltaTime();
		Pos(Lerp(mAnimationStartPos, mAnimationEndPos, mAnimationTimer / mAnimationTotalTime));
		
		if(mAnimationTimer >= mAnimationTotalTime)
			mAnimationDone = true;
		
		if(mInput->KeyPressed(SDL_SCANCODE_DOWN) || mInput->KeyPressed(SDL_SCANCODE_UP))
			mAnimationTimer = mAnimationTotalTime;
		
		
	} else {
		
		mAnimatedLogo->Update();
		
		if(mInput->KeyPressed(SDL_SCANCODE_DOWN))
			ChangeSelectedMode(1);
		else if(mInput->KeyPressed(SDL_SCANCODE_UP))
			ChangeSelectedMode(-1);
	}
	
}

void StartScreen::Render() {

	mPlayerOne->Render();
	mHiScore->Render();
	mPlayerTwo->Render();
	
	if(!mAnimationDone)
		mLogo->Render();
	else
		mAnimatedLogo->Render();
	
	mLogo->Render();
	
	mOnePlayerMode->Render();
	mTwoPlayerMode->Render();
	mCursor->Render();
	
	mNamco->Render();
	mDates->Render();
	mRights->Render();
	
	

}
