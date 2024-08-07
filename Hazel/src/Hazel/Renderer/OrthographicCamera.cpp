#include "hzpch.h"
#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Hazel {
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top) 
		: m_ProjectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), //Set up orthographic projection matrix
		m_ViewMatrix(1.0f)
	{
		// ViewProject = Project * View
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OrthographicCamera::SetProjection(float left, float right, float bottom, float top)
	{
		//Reset orthographic projection matrix
		m_ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f); 
		// ViewProject = Project * View
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OrthographicCamera::RecalculateMatrix()
	{
		HZ_PROFILE_FUNCTION();

		// Position + Rotation = Transform
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position) *
			glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));
		// Inverse Transform = View
		m_ViewMatrix = glm::inverse(transform);
		// ViewProject = Project * View
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}
}