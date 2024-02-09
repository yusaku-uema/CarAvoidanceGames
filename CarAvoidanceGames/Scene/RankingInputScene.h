#pragma once

#include "SceneBase.h"
#include "../Object/RankingData.h"

class RankingInputScene:public SceneBase
{
private:
	int backgrouond_image;   //�w�i�摜
	RankingData* ranking;    //�����L���O���
	int score;               //�X�R�A
	char name[15];           //���O
	int name_num;            //���O���͐�
	int cursor_x;            //�J�[�\��x���W
	int cursor_y;            //�J�[�\��y���W

public:
	RankingInputScene();
	virtual ~RankingInputScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

private:
	//���O���͏���
	bool InputName();
};

