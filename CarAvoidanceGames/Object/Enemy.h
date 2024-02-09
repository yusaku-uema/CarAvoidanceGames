#pragma once

#include "../Utility/Vector2D.h"

class Enemy
{private:
	int type;             //�^�C�v
	int image;            //�摜
	float speed;          //����
	Vector2D location;    //�ʒu���
	Vector2D box_size;    //�����蔻��̑傫��

public:
	Enemy(int ytpe, int handle);
	~Enemy();

	void Initialize();            //����������
	void Updata(float speed);     //�X�V����
	void Draw()const;             //�`�揈��
	void Finalize();              //�I��������

	int GetType()const;           //�^�C�v�擾
	Vector2D GetLocation()const;  //�ʒu���̎擾
	Vector2D GetBoxSize()const;   //�����蔻��̑傫�����擾
};

