#pragma once
#include <iostream>

class MainStream
{
private:
	int progress = 0;

public:
	
	void ChapterOne(int _progress);
	void FinalChapter(int _progress);

	// get
	int GetProgress();

	// set
	void SetProgress(int _progress);
};