#pragma once
#include "SceneBase.h"

// �Œ艻����t���[�����[�g�l
#define TARGET_FREAM_RATE (60)

//1�t���[��������̎���(�}�C�N���b)
#define DELTA_SECOND (1000000 / TARGET_FREAM_RATE)

class SceneManager
{
private:
	SceneBase* current_scene; //���݂̃V�[�����

public:
	SceneManager(); //�R���X�g���N�^
	~SceneManager();//�f�X�g���N�^

	void Initialize(); //����������
	void Update(); //�X�V����
	void Finalize(); //�I�����̏���

private:
	void Draw() const;// �`�揈��
	void ChangeScene(eSceneType scene_type);// �V�[���؂�ւ�����
	SceneBase* CreateScene(eSceneType scene_type);// �V�[����������
	
};

