#include "jfpch.h"
#include "Entity.h"

namespace JF {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}