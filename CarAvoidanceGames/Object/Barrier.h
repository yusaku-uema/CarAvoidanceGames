#pragma once

#include "../Utility/Vector2D.h"

class Barrier
{
private:
	int image;
	float life_span;

public:
	Barrier();    //�o���A�摜
	~Barrier();   //�o���A�̎���

	void Draw(const Vector2D& location);    //�`�揈��
	bool IsFinished(float speed);           //�������s�������H
};

