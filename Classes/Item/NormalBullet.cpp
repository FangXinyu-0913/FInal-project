
#include "NormalBullet.h"

void NormalBullet::attack(float direX, float direY, Point heroPoint, int curFacing, Node* sprite )
{
	float x = heroPoint.x; //+ (curFacing == 0 ? 25.0 : -25.0);
	float y = heroPoint.y + 15;// +(curFacing == 0 ? 25.0 : -25.0);// += 20.0;
	
	this->setPosition(x,y);
	//log("posAA x: %d  posAA y: %d", pos.x, pos.y);
	auto v = Vec2(direX, direY);
	//��λ��
	v.normalize();    
	//�ٶ�����
	v *= 400;          
	m_pBulletSprite->getPhysicsBody()->setVelocity(v);
}

bool NormalBullet::init()
{
    auto pNormalBullet = Sprite::create("NormalBullet.png");
	if (pNormalBullet == nullptr)
	{
		log("NormalBullet.png not found");
	}
	//�ӵ�����������ӵ���,�ұ�Ϊ����
	bindSprite(pNormalBullet, QS::Kind::kSelf, QS::BulletShape::kCircle);

	setBulletSpeed(3);

	return true;
}