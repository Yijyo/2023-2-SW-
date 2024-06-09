#ifndef BASESCENE_H
#define BASESCENE_H

class BaseScene 
{
public:
	void Start();
	void End();
	void Update();
	static class BaseScene* CurrentScene;
};
#endif