#include "jfpch.h"
//#include "Scene.h"
//#include <glm/glm.hpp>
//
//namespace JF
//{
//	Scene::Scene()
//	{
//		struct MeshComponent
//		{
//
//		};
//
//		struct TransformComponent
//		{
//			glm::mat4 Transform;
//
//			TransformComponent() = default;
//			TransformComponent(const TransformComponent&) = default;
//			TransformComponent(const glm::mat4& tranform) :
//				Transform(tranform) {}
//		
//			operator const glm::mat4& () { return Transform; }
//		};
//
//
//		entt::entity entity = m_Registry.create();
//		auto& transform = m_Registry.emplace<TransformComponent>(entity,glm::mat4(1.0));
//
//		m_Registry.clear();
//		if(m_Registry.has<TransformComponent>(entity))
//		TransformComponent& tranform = m_Registry.get<TransformComponent>(entity);
//
//		auto& view = m_Registry.view<TransformComponent>();
//		for (auto entity : view)
//		{
//			TransformComponent& tranform = m_Registry.get<TransformComponent>(entity);
//		}
//
//		auto& group = m_Registry.group<TransformComponent>(entt::get<MeshComponent>);
//	}
//
//	Scene::~Scene()
//	{
//
//	}
//
//}
//
//
