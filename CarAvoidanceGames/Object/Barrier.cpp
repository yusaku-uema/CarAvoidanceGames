#include "Barrier.h"
#include "DxLib.h"

Barrier::Barrier() :image(NULL), life_span(1000)
{
	//�摜�̓ǂݍ���
	image = LoadGraph("Resource/images/barrier.png");

	//�G���[�`�F�b�N
	if (image == -1)
	{
		throw("Resource/images/barrier.png������܂���\n");
	}
}


Barrier::~Barrier()
{
	//�ǂݍ��񂾉摜���폜
	DeleteGraph(image);
}


//�`�揈��
void Barrier::Draw(const Vector2D& location)
{
	DrawRotaGraphF(location.x, location.y, 1.0f, 0.0, image, TRUE);
}


//�������s�������H
bool Barrier::IsFinished(float speed)
{
	life_span -= speed;
	return (life_span <= 0);
}