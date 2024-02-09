#pragma once
class RankingData
{
private:
	int score[6];       //�X�R�A�f�[�^
	int rank[6];        //�����N�f�[�^
	char name[6][15];   //���O�f�[�^


public:
	RankingData();
	~RankingData();

	void Initialize();   //����������
	void Finalize();    //�I������

public:
	//�����L���O�f�[�^�̐ݒ�
	void SetRankingData(int score, const char* name);
	//�X�R�A�擾����
	int GetScore(int value)const;
	//�����N�擾����
	int GetRank(int value)const;
	//���O�擾����
	const char* GetName(int value)const;

private:
	//�f�[�^����ւ�����
	void SortData();
};

