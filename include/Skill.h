#pragma once

#ifndef SKILL_H
#define SKILL_H

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

class Skill;
class SkillList;

using SkillHandle = Nz::ObjectHandle<Skill>;
using SkillListHandle = Nz::ObjectHandle<SkillList>;

class Skill : public Nz::HandledObject<Skill>
{
	public:
		Skill(Nz::LuaInstance& luaRef, const Nz::String luaFunc, Ndk::EntityHandle entity, Ndk::EntityHandle parent);
		~Skill();

		void Update(const float delta);
	private:
		Ndk::EntityHandle m_parent;

		Ndk::EntityHandle m_entity;

		Ndk::GraphicsComponent& m_graphics;
		Ndk::NodeComponent& m_node;

		Nz::String m_luaFunc;

		Nz::LuaInstance& lua;
};

class SkillList : public std::vector<Skill>, public Nz::HandledObject<SkillList>
{
	public:
		SkillList(Nz::LuaInstance & luaRef);

		void AddSkill(const Nz::String luaFunc, const Ndk::EntityHandle entity, const Ndk::EntityHandle parent);

		void Update(float delta);

		static void Init(Nz::LuaInstance& luaRef);
	private:
		Nz::LuaInstance& lua;
};
#endif
