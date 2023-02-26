#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Engine.h"


void load()
{
	/*
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_shared<TextureObject>("background.tga");
	scene.Add(go->GameObject());

	go = std::make_shared<TextureObject>("logo.tga", glm::vec3{216, 180, 0});
	scene.Add(go->GameObject());
	
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = std::make_shared<dae::TextObject>("Programming 4 Assignment", font, glm::vec3{ 80, 20, 0 });

	scene.Add(to->GameObject());
	/*
	auto font2 = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
	auto fps = std::make_shared<dae::TextObject>("0", font2, glm::vec3{ 10, 5, 0 });
	//fps->SetText()
	//scene.Add(fps->GameObject());
	*/
}

int main(int, char*[]) {
	dae::Engine engine("../Data/");
	engine.Run(load);
    return 0;
}