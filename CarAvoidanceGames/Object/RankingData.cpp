#include "RankingData.h"
#include <stdio.h>
#include <string.h>

RankingData::RankingData()
{
	for (int i = 0; i < 6; i++)
	{
		score[i] = NULL;
		rank[i] = NULL;
		for (int j = 0; j < 15; j++)
		{
			name[i][j] = '\0';
		}
	}
}


RankingData::~RankingData()
{

}


//����������
void RankingData::Initialize()
{
	//�����L���O�f�[�^�̓ǂݍ���
	FILE* fp = nullptr;

	//�t�@�C���I�[�v��
	errno_t result = fopen_s(&fp, "Resource/dat/ranking_data.csv", "r");

	//�G���[�`�F�b�N
	if (result != 0)
	{
		throw("Resource/dat/ranking_data.scv���J���܂���ł���\n");
	}

	//�Ώۃt�@�C������ǂݍ���
	for (int i = 0; i < 5; i++)
	{
		fscanf_s(fp, "%6d,%2d,%[^,],\n", &score[i], &rank[i], name[i], 15);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	//�����f�[�^�̐ݒ�
	score[5] = 0;
	rank[5] = 0;
	name[5][0] = '\0';
}


//�I������
void RankingData::Finalize()
{

}


//�f�[�^�ݒ菈��
void RankingData::SetRankingData(int score, const char* name)
{
	this->score[5] = score;
	strcpy_s(this->name[5], name);

	SortData();
}


//�X�R�A�擾����
int RankingData::GetScore(int value)const
{
	return score[value];
}


//�����N���擾����
int RankingData::GetRank(int value)const
{
	return rank[value];
}


//���O�擾����
const char* RankingData::GetName(int value)const
{
	return name[value];
}


//�f�[�^����ւ�����
void RankingData::SortData()
{
	//�I��@�\�[�g���g�p���A�~���œ���ւ���
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (score[i] <= score[j])
			{
				int tmp = score[i];
				score[i] = score[j];
				score[j] = tmp;

				char buf[15] = {};
				strcpy_s(buf, name[i]);
				strcpy_s(name[i], name[j]);
				strcpy_s(name[j],buf);
			}
		}
	}

	//���ʂ𐮗񂳂���
	for (int i = 0; i < 5; i++)
	{
		rank[i] = 1;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (score[i] > score[j])
			{
				rank[j]++;
			}
		}
	}
	//�����L���O�f�[�^�̏�������
	FILE* fp = nullptr;

	//�t�@�C���I�[�v��
	errno_t result = fopen_s(&fp, "Resource/dat/ranking_data.csv", "w");

	//�G���[�`�F�b�N
	if (result != 0)
	{
		throw("Resource/dat/ranking_data.csv���J���܂���ł���\n");
	}

	//�Ώۃt�@�C���ɏ�������
	for (int i = 0; i < 5; i++)
	{
		fprintf(fp, "%d,%d,%s,\n", score[i], rank[i], name[i]);
	}

	//�t�@�C���N���[�Y
	fclose(fp);
}

