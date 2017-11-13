#include "Skill.h"



Skill::Skill(Nz::LuaInstance & luaRef, const Nz::String luaFunc, Ndk::EntityHandle entity, Ndk::EntityHandle parent, Skill::Type type, int level)
	:
	m_type{ type },
	m_level{ level },

	m_entity{ entity },
	m_parent{ parent },

	m_graphics{ m_entity->AddComponent<Ndk::GraphicsComponent>() },
	m_node{ m_entity->AddComponent<Ndk::NodeComponent>() },

	lua{ luaRef },
	m_luaFunc{ luaFunc }
{
}

Skill::~Skill()
{
}


void Skill::Update(float delta)
{
	lua.GetGlobal(m_luaFunc);
	lua.Push(delta);
	lua.Push(m_level);
	lua.Push(m_entity);
	lua.Push(m_parent);
	lua.Call(4, 0);
}

SkillList::SkillList(Nz::LuaInstance & luaRef)
	:
	std::vector<Skill>{},

	lua{ luaRef }
{
}

void SkillList::AddSkill(const Nz::String luaFunc, const Ndk::EntityHandle entity, const Ndk::EntityHandle parent, Skill::Type type, int level)
{
	push_back(Skill(lua, luaFunc, entity, parent, type, level));
}


void SkillList::Init(Nz::LuaInstance& luaRef)
{
	Nz::LuaClass<SkillListHandle> luaClass{ "SkillList" };

	//luaClass.BindDefaultConstructor();

	luaClass.BindMethod("AddSkill", &SkillList::AddSkill);

	luaClass.Register(luaRef);
}

void SkillList::Update(const float delta)
{
	for (auto i = begin(); i < end(); i++)
	{
		i->Update(delta);
	}
}
