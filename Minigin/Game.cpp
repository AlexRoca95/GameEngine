#include "Game.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "TextComponent.h"
#include "FPSComponent.h"
#include "RotatorComponent.h"
#include "GameObject.h"
#include <iostream>
using namespace dae;

Game::Game()
{
	m_pRenderer = &Renderer::GetInstance();
	m_pSceneManager = &SceneManager::GetInstance();

	if (m_pSceneManager != nullptr)
	{
		m_pScene = &m_pSceneManager->CreateScene("Demo");
	}
	
	// Background 
	auto go_Background = std::make_shared<GameObject>(nullptr);
	go_Background->AddComponent<RenderComponent>(go_Background.get(), "background.tga");
	go_Background->AddComponent<TransformComponent>(go_Background.get());
	m_pScene->Add(go_Background);

	// LOGO
	GameObject* go_Logo = new GameObject(go_Background.get(), glm::vec3{ 216, 180, 0 });
	go_Logo->AddComponent<RenderComponent>(go_Logo, "logo.tga");
	//m_pScene->Add(go_Logo);

	//go_Background->MarkAsDead();
	//go_Logo->MarkAsDead();
	//go_Logo->SetParent(nullptr);
	
	
	// TEXT TITLE TEXTURE
	GameObject* go_Title = new GameObject(go_Logo, glm::vec3{ 80, 20, 0 });
	//auto go_Title = std::make_shared<GameObject>(glm::vec3{ 80, 20, 0 });
	go_Title->AddComponent<RenderComponent>(go_Title);
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	go_Title->AddComponent<TextComponent>(go_Title, "Programming 4 Assignment", font);
	//m_pScene->Add(go_Title);
	//go_Title->SetParent(go_Logo);
	

	//go_Title->MarkAsDead();

	// FPS TEXT 
	//auto go_FPS = std::make_shared<GameObject>(glm::vec3{ 10, 20, 0 });
	GameObject* go_FPS = new GameObject(go_Logo, glm::vec3{ 10, 20, 0 });
	go_FPS->AddComponent<RenderComponent>(go_FPS);
	font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 15);
	go_FPS->AddComponent<TextComponent>(go_FPS, "Calculating FPS ...", font, SDL_Color{ 0, 255, 0 });
	go_FPS->AddComponent<FPSComponent>(go_FPS);
	//m_pScene->Add(go_FPS);

	//go_FPS->SetParent(go_Logo);

	
	//go_FPS->MarkAsDead();
	
	
	// PLayer ship sprite
	//GameObject* go_Player = new GameObject(go_Logo, glm::vec3{ 330, 300, 0 });
	auto go_Player = std::make_shared<GameObject>(nullptr, glm::vec3{ 300, 300, 0 });
	go_Player->AddComponent<RenderComponent>(go_Player.get(), "Player.png");
	go_Player->AddComponent<RotatorComponent>(go_Player.get(), 50.f, 3.f);
	m_pScene->Add(go_Player);

	// Enemy ship sprite
	//auto go_Enemy = std::make_shared<GameObject>(nullptr, glm::vec3{ 330, 300, 0 });
	
	GameObject* go_Enemy = new GameObject(go_Player.get(), glm::vec3{330, 300, 0});
	go_Enemy->AddComponent<RenderComponent>(go_Enemy, "Enemy.png");
	go_Enemy->AddComponent<RotatorComponent>(go_Enemy, 20.f, 1.f);
	//m_pScene->Add(go_Enemy);
	
	//go_Enemy->MarkAsDead();
	//go_Enemy->SetParent(nullptr);
}

Game::~Game()
{
	std::cout << "Game destructor" << std::endl;
}

void Game::Update(const float deltaTime)
{
	// Update all gameObjects from the scenes
	m_pSceneManager->Update(deltaTime);

}


void Game::Render() const
{
	// Render all the scenes
	m_pRenderer->Render();
}

