#include "Physics\PhysicsModule.h"

/***************************************

#PhysicsModule.cpp

@(#)Author: Alexander Thoma

▄████▄  ▒█████  ▓█████▄ ▓█████ ▒██   ██▒
▒██▀ ▀█ ▒██▒  ██▒▒██▀ ██▌▓█   ▀ ▒▒ █ █ ▒░
▒▓█    ▄▒██░  ██▒░██   █▌▒███   ░░  █   ░
▒▓▓▄ ▄██▒██   ██░░▓█▄   ▌▒▓█  ▄  ░ █ █ ▒
▒ ▓███▀ ░ ████▓▒░░▒████▓ ░▒████▒▒██▒ ▒██▒
░ ░▒ ▒  ░ ▒░▒░▒░  ▒▒▓  ▒ ░░ ▒░ ░▒▒ ░ ░▓ ░
░  ▒    ░ ▒ ▒░  ░ ▒  ▒  ░ ░  ░░░   ░▒ ░
░       ░ ░ ░ ▒   ░ ░  ░    ░    ░    ░
░ ░         ░ ░     ░       ░  ░ ░    ░
░
****************************************/

PhysicsModule::PhysicsModule() : EngineModule()
{
	m_physics = phyX::CPhysiX::GetInstance();
}

PhysicsModule::~PhysicsModule()
{
	m_physics->Destroy();
}

void PhysicsModule::postUpdate(float deltaTime, float time)
{
	m_physics->PostRenderUpdate(deltaTime);
}

void PhysicsModule::PostRenderUpdate(float fTimeDelta)
{
	m_physics->PostRenderUpdate(fTimeDelta);
}

void PhysicsModule::RefreshPhysiX()
{
	m_physics->RefreshPhysiX();
}

int PhysicsModule::AddPhysiXLayer(std::string layer)
{
	return m_physics->AddPhysiXLayer(layer);
}

std::string PhysicsModule::TranslateLayer(unsigned int LayerNumber)
{
	return m_physics->TranslateLayer(LayerNumber);
}

int PhysicsModule::GetLayerNumber(std::string layerName)
{
	return m_physics->GetLayerNumber(layerName);
}

bool PhysicsModule::SetLayerProperty(std::string layer, std::string layer1, bool collision)
{
	return m_physics->SetLayerProperty(layer, layer1, collision);
}

void PhysicsModule::PrintLayerMatrix()
{
	m_physics->PrintLayerMatrix();
}