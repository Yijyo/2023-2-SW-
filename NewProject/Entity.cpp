#include "const.h"
#include "Utility.h"
#include "Entity.h"

int Entity::PosX()
{
	return _posX;
}

void Entity::PosX(int value)
{
	_posX = value;
	std::cout << _posX;
	_posX = Utility::Clamp(_posX, 0, ConsoleSizeWidth - 1);
}

int Entity::PosY()
{
	return _posY;
}

void Entity::PosY(int value)
{
	_posY = value;
	std::cout << _posY;
	_posY = Utility::Clamp(_posY, 2, ConsoleSizeHeight - 1);
}

int Entity::CurrentHp()
{
	return _currentHp;
}

void Entity::CurrentHp(int value)
{
	_currentHp = value;
	_currentHp = Utility::Clamp(_currentHp, 0, maxHp);

	if (_currentHp <= 0) {
		isDead = true;
		Dead();
	}
}

