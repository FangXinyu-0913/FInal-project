#include "SwordBullet.h"

bool SwordBullet::init()
{	
	unsigned short const actionStep = 4;
	//创建精灵帧动画  (也可考虑cache将动画缓存起来,可能效率更高)
	SpriteFrame* frame_r = nullptr;
	SpriteFrame* frame_l = nullptr;
	for (unsigned short i = 1; i <= actionStep; i++)
	{
		//格式化字符串，不用spintf
		frame_r = SpriteFrame::create(StringUtils::format("item/bullets/sword_action%d.png", i),
			Rect(0, 0, 60, 60));
		frame_l = SpriteFrame::create(StringUtils::format("item/bullets/sword_action%d.png", i),
			Rect(0, 0, 60, 60));
		if (frame_l == nullptr || frame_r == nullptr)
		{
			log("animate sword_action%d.png lost", i);
		}
		else
		{
			//重心选于左中部
			frame_r->setAnchorPoint(Vec2(0.f, 0.5f));
			m_rightActionVec.pushBack(frame_r);
			//重心选于右中部
			frame_l->setAnchorPoint(Vec2(1.f, 0.5f));
			m_leftActionVec.pushBack(frame_l);
		}
	}

	m_pBulletSprite = Sprite::create("item/sword1.png");
	if (m_pBulletSprite == nullptr)
	{
		log("item/sword1.png can't be shown");
	}
	bindSprite(m_pBulletSprite, QS::Kind::kSelf, QS::BulletShape::kCircle, QS::Name::kCloseDamage);
	return true;
}

void SwordBullet::attack(float mouseX, float mouseY, Point heroPoint, int curFacing, Node* sprite = nullptr)
{
	
}