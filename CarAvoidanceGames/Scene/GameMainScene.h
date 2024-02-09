#pragma once

#include "SceneBase.h"
#include "../Object/Player.h"
#include "../Object/Enemy.h"

class GameMainScene:public SceneBase
{
private:
	int high_score;      //�n�C�X�R�A
	int back_ground;     //�w�i�摜
	int barrier_image;   //�o���A�f��
	int mileage;         //���s����
	int enemy_image[3];  //�G�摜
	int enemy_count[3];  //�ʂ�߂����G�J�E���g
	Player* player;      //�v���C���[
	Enemy** enemy;       //�G

public:
	GameMainScene();
	virtual ~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

private:
	//�n�C�X�R�A�ǂݍ��ݏ���
	void ReadHighScore();
	//�����蔻��
	bool IsHitCheck(Player* p, Enemy* e);
};

