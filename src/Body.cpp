#include "Body.h"


Body::Body(Ndk::EntityHandle entity, const Nz::String& texturePath, Nz::LuaInstance& luaRef, const Nz::String& luaFunc)
	:
	m_entity{entity},

	m_graphics{ m_entity->AddComponent<Ndk::GraphicsComponent>() },
	m_node{ m_entity->AddComponent<Ndk::NodeComponent>() },
	m_physics{ m_entity->AddComponent<Ndk::PhysicsComponent2D>() },
	m_collision{ m_entity->AddComponent<Ndk::CollisionComponent2D>() },

	m_sprite{ Nz::Sprite::New() },

	m_collider{ Nz::BoxCollider2D::New(Nz::Vector2f(100, 500)) },

	lua { luaRef },
	m_luaFunc{ luaFunc }
{
	m_physics.SetMass(1);
	m_sprite->SetTexture(texturePath);
	m_graphics.Attach(m_sprite);
	m_collision.SetGeom(m_collider);
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

