#pragma once
#include <array>

#include "Enemy.h"
#include "EnemyType.h"

class EnemyFactory
{
public:
    EnemyFactory();
    ~EnemyFactory();
    
    void Init();
    Enemy CreateEnemy(enumEnemyType aEnemyType) const;

private:
    std::array<EnemyType, static_cast<int>(enumEnemyType::Count)> myEnemyTypes;
};
