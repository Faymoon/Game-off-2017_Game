
#include <Nazara/Core.hpp>
#include <Nazara/Lua.hpp>
#include <Nazara/Graphics.hpp>
#include <Nazara/Renderer.hpp>
#include <Nazara/Utility.hpp>
#include <NDK/Application.hpp>
#include <NDK/Components.hpp>
#include <NDK/Systems.hpp>
#include <NDK/World.hpp>
#include <NDK/LuaAPI.hpp>
#include <iostream>
#include "Body.h"
#include "Skill.h"

int main()
{
	Ndk::Application app;

	Nz::RenderWindow& win = app.AddWindow<Nz::RenderWindow>();
	win.Create(Nz::VideoMode(800, 600, 32), "Test");

	Ndk::World& world = app.AddWorld();
	world.GetSystem<Ndk::RenderSystem>().SetGlobalUp(Nz::Vector3f::Down());

	Ndk::EntityHandle camEntity = world.CreateEntity();
	Ndk::NodeComponent& cam = camEntity->AddComponent<Ndk::NodeComponent>();
	
	Ndk::CameraComponent& camComp = camEntity->AddComponent<Ndk::CameraComponent>();
	camComp.SetTarget(&win);
	camComp.SetProjectionType(Nz::ProjectionType_Orthogonal);

	Nz::LuaInstance lua;

	SkillList::Init(lua);
	SkillList skills{ lua };

	lua.PushGlobal("world", world.CreateHandle());
	lua.PushGlobal("skills", skills.CreateHandle());

	lua.ExecuteFromFile("./main.lua");

	Body player = Body(world.CreateEntity(), Nz::String("resources/1.png"), lua, Nz::String("player_update"));

	while (app.Run())
	{
		player.Update(app.GetUpdateTime());
		skills.Update(app.GetUpdateTime());
		win.Display();
	}

	return EXIT_SUCCESS;
}
