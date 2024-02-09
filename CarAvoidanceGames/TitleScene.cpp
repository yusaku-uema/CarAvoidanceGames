#include "TitleScene.h"

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	// 画像の読み込み
	background_image = LoadGraph("Resource/images/Title.bmp");
	menu_image = LoadGraph("Resource/images/menu.bmp");
	cursor_image = LoadGraph("Resource/images/cone.bmp");

	// エラーチェック
	if (background_image == -1)
	{
		throw("Resource/images/Title.bmpがありません\n");
	}
	if (menu_image == -1)
	{
		throw("Resource/images/cone.bmpがありません\n");
	}
	if (cursor_image == -1)
	{
		throw("Resource/images/menu.bmpがありません\n");
	}
	if (cursor_image == -1)
	{
		throw("Resource/images/cone.bmpがありません\n");
	}

}

eSceneType TitleScene::Update()
{
	//カーソル下移動
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		menu_cursor++;
		//1番下に到達したら、一番上にする
		if (menu_cursor > 3)
		{
			menu_cursor = 0;
		}
	}

	//カーソル上移動
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		menu_cursor--;
		//1番上に到達したら、一番下にする
		if (menu_cursor < 0)
		{
			menu_cursor = 3;
		}
	}

	//カーソル決定(決定した画面に遷移する)
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		switch (menu cursor)
		{
		case 0:
			return eSceneType :: E_MAIN;
		case 1:
			return eSceneType :: E_RANKING_DISP;
		case 2:
			return eSceneType :: E_HELP;
		default:
			return eSceneType :: E_END;
		}
	}
	return GetNowScene();
}

void TitleScene::Draw() const
{
	// タイトル画像の描画
	DrawGraph(0, 0, background_image, FALSE);

	// メニュー画像の描画
	DrawGraph(120, 200, menu_image, TRUE);

	// カーソル画像の描画
	DrawRotaGraph(90, 220 + menu_cursor * 40, 0.7, DX_PI / 2.0, cursor_image,
		TRUE);
}

void TitleScene::Finalize()
{
}

eSceneType TitleScene::GetNowScene() const
{
	return eSceneType();
}
