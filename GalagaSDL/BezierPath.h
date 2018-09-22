#ifndef BezierPath_h
#define BezierPath_h
#include "MathHelper.h"
#include <vector>


using namespace QuickSDL;


class BezierPath {
	
	
private:
	
	std::vector<BezierCurve> mCurves;
	std::vector<int> mSamples;
	
public:
	
	BezierPath();
	~BezierPath();
	
	void AddCurve(BezierCurve curve, int samples);
	
	void Sample(std::vector<Vector2>* sampledPath);
	
};

#endif /* BezierPath_h */
