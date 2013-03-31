#include <Asteroids\Code\Blasteroids_Game\Levels\Worlds\MainWorld.h>
#include <Asteroids\Code\Blasteroids_Game\Components\TransformComponent.h>
#include <Asteroids\Code\Blasteroids_Game\Components\RenderComponent.h>

namespace Blasteroids
{

void MainWorld::Run()
{
}

void MainWorld::Initialize()
{
	m_pPlayerEntity = new EngineHigh::Entity();
	m_pEntityManager->AddEntity(m_pPlayerEntity);

	TransformComponent* transformComponent = new TransformComponent();
	transformComponent->SetPosition(0.0f, 0.0f);

	RenderComponent* renderComponent = new RenderComponent();

	m_pEntityManager->AddComponent<TransformComponent>(*m_pPlayerEntity, transformComponent);
	m_pEntityManager->AddComponent<RenderComponent>(*m_pPlayerEntity, renderComponent);
}

}