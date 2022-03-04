#include "MainStream.h"

void MainStream::ChapterOne(int _progress)
{
	if (_progress == 0)
	{

	}

	else
	{
		std::cout << "ERROR: WRONG ACCESS: MAIN STREAM CHAPTER 1" << std::endl;
		return;
	}
}
void MainStream::FinalChapter(int _progress)
{

}

// get
int MainStream::GetProgress()
{
	return this->progress;
}

// set
void MainStream::SetProgress(int _progress)
{
	this->progress = _progress;
}