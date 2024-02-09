#include "RankingInputScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

RankingInputScene::RankingInputScene() :backgrouond_image(NULL),
ranking(nullptr), score(0),
                                                 name_num(0), cursor_x(0),
cursor_y(0)
{
    memset(name, NULL, (sizeof(char) * 15));
}


RankingInputScene::~RankingInputScene()
{

}


//����������
void RankingInputScene::Initialize()
{
    //�摜�̓ǂݍ���
    backgrouond_image = LoadGraph("Resource/images/Ranking.bmp");

    //�G���[�`�F�b�N
    if (backgrouond_image == -1)
    {
        throw("Resource/images/Ranking.bmp������܂���\n");
    }

    //�������̓��I�m��
    ranking = new RankingData;
    ranking->Initialize();

    //���U���g�f�[�^���擾����
    FILE* fp = nullptr;
    //�t�@�C���I�[�v��
    errno_t result = fopen_s(&fp, "Resource/dat/result_data.csv", "r");

    //�G���[�`�F�b�N
    if (result != 0)
    {
        throw("Resource/dat/result_data.csv���ǂݍ��߂܂���\n");
    }

    //���ʂ�ǂݍ���
    fscanf_s(fp, "%6d,\n", &score);

    //�t�@�C���N���[�Y
    fclose(fp);
}


//�X�V����
eSceneType RankingInputScene::Update()
{
    bool is_change = false;

    //���O���͏���
    is_change = InputName();

    //�V�[���ύX�͉\��?
    if (is_change)
    {
        //�����L���O�\���ɑJ��
        return eSceneType::E_RANKING_DISP;
    }
    else
    {
        return GetNowScene();
    }
}


//�`�揈��
void RankingInputScene::Draw()const
{
    //�w�i�摜�̕`��
    DrawGraph(0, 0, backgrouond_image, TRUE);

    //���O���͎w��������̕`��
    DrawString(150, 100, "�����L���O�ɓo�^���܂�", 0xffffff);
    DrawFormatString(100, 220, GetColor(255, 255, 255), ">%s", name);

    //�I��p������`��
    const int font_size = 25;
    for (int i = 0; i < 26; i++)
    {
        int x = (i % 13) * font_size + 15;
        int y = (i / 13) * font_size + 300;
        DrawFormatString(x, y, GetColor(255, 255, 255), "%-3c", 'a' + i);
        y = ((i / 13) + 2) * font_size + 300;
        DrawFormatString(x, y, GetColor(255, 255, 255), "%-3c", 'A' + i);
    }
    DrawString(40, 405, "����",GetColor(255, 255, 255));
    DrawString(40 + font_size * 2, 405, "����", GetColor(255, 255, 255));

    //�I�𕶎����t�H�[�J�X����
    if (cursor_y < 4)
    {
        int x = cursor_x * font_size + 10;
        int y = cursor_y * font_size + 295;
        DrawBox(x, y, x + font_size, y + font_size, GetColor(255, 255, 255), FALSE);
    }
    else
    {
        if (cursor_x == 0)
        {
            DrawBox(35, 400, 35 + font_size * 2, 400 + font_size, GetColor(255, 255, 255), FALSE);
        }
        else
        {
            DrawBox(80, 400, 80+font_size*2, 400+font_size, GetColor(255, 255, 255), FALSE);
        }
    }
}


//�I��������
void RankingInputScene::Finalize()
{
    //�����L���O�Ƀf�[�^���i�[
    ranking->SetRankingData(score, name);

    //�ǂݍ��񂾉摜���폜
    DeleteGraph(backgrouond_image);

    //���I�������̉��
    delete ranking;
}


//���݂̃V�[�������擾
eSceneType RankingInputScene::GetNowScene()const
{
    return eSceneType::E_RANKING_INPUT;
}


//���O�̓��͏���
bool RankingInputScene::InputName()
{
    //�J�[�\�����쏈��
    if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_LEFT))
    {
        if (cursor_x > 0)
        {
            if (cursor_y == 4)
            {
                cursor_x = 0;
            }
            else
            {
                cursor_x--;
            }
        }
        else
        {
            cursor_x = 12;
        }
    }
    if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_RIGHT))
    {
        if (cursor_y == 4)
        {
            if (cursor_x == 1)
            {
                cursor_x = 0;
            }
            else
            {
                cursor_x = 1;
            }
        }
        else
        {
            if (cursor_x < 12)
            {
                cursor_x++;
            }
            else
            {
                cursor_x = 0;
            }
        }
    }
    if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
    {
        if (cursor_y > 0)
        {
            cursor_y--;
        }
        else
        {
            cursor_y = 4;
        }
    }
    if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
    {
        if (cursor_y < 4)
        {
            cursor_y++;
        }
        else
        {
            cursor_y = 0;
        }
    }

    //�J�[�\���ʒu�̕��������肷��
    if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
    {
        if (cursor_y < 2)
        {
            name[name_num++] = 'a' + cursor_x + (cursor_y * 13);
            if (name_num == 14)
            {
                cursor_x = 0;
                cursor_y = 4;
            }
        }
        else if (cursor_y < 4)
        {
            name[name_num++] = 'A' + cursor_x + ((cursor_y - 2) * 13);
            if (name_num == 14)
            {
                cursor_x = 0;
                cursor_y = 4;
            }
        }
        else
        {
            if (cursor_x == 0)
            {
                name[name_num] = '\0';
                return true;
            }
            else
            {
                name[--name_num] = NULL;
            }
        }
    }

    return false;
}
