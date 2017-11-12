
#pragma once

#ifndef BODY_H
#define BODY_H

#include <NDK/Application.hpp>
#include <NDK/Components.hpp>
#include <NDK/Systems.hpp>
#include <NDK/World.hpp>
#include <NDK/LuaAPI.hpp>
#include <Nazara/Core.hpp>
#include <Nazara/Lua.hpp>
#include <Nazara/Graphics.hpp>
#include <Nazara/Renderer.hpp>
#include <Nazara/Utility.hpp>

class Body
{
	public:
		Body(Ndk::EntityHandle entity, const Nz::String materialPath, Nz::LuaInstance& luaRef, const Nz::String luaFunc);
		~Body();
		void Update(const float delta);
	private:
		Nz::SpriteRef m_sprite;

		Ndk::EntityHandle m_entity;

		Ndk::GraphicsComponent& m_graphics;
		Ndk::NodeComponent& m_node;

		Nz::LuaInstance& lua;
		Nz::String m_luaFunc;
};

#endif
