#include "Body.h"


Body::Body(Ndk::EntityHandle entity, const Nz::String texturePath, Nz::LuaInstance& luaRef, const Nz::String luaFunc)
	:
	m_entity{entity},
	m_graphics{ m_entity->AddComponent<Ndk::GraphicsComponent>() },
	m_node{ m_entity->AddComponent<Ndk::NodeComponent>() },

	m_sprite{ Nz::Sprite::New() },

	lua { luaRef },
	m_luaFunc{ luaFunc }
{
	m_sprite->SetTexture(texturePath);
	m_graphics.Attach(m_sprite);
}


Body::~Body()
{
}

void Body::Update(const float delta)
{
	lua.GetGlobal(m_luaFunc);
	lua.Push(delta);
	lua.Push(m_node.CreateHandle());
	lua.Call(2, 0);
}
