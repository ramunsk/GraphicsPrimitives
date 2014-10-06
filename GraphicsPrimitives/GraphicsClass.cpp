////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
	m_Transform = 0;
	//m_Triangle = 0;
	m_Arrow = 0;
	m_TrivialShader = 0;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(HWND hwnd)
{
	bool result;

	// Create the Direct3D object.
	m_D3D = new D3DClass;
	if (!m_D3D)
	{
		MessageBox(hwnd, L"Could not create the D3DClass object!", L"Error", MB_OK);
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D->Initialize(hwnd, FULL_SCREEN);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D!", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	m_Transform = new TransformationClass;
	if (!m_Transform)
	{
		MessageBox(hwnd, L"Could not create the camera object.", L"Error", MB_OK);
		return false;
	}

	m_Transform->Initialize(hwnd);
	// Set the initial position of the camera.
	m_Transform->SetCameraPosition(D3DXVECTOR3(0.0f, 0.0f, -800.0f));
	m_Transform->SetCameraTarget(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	m_Transform->SetCameraUPV(D3DXVECTOR3(0.0f, 2.0f, 0.0f));

	// Create the model object.
	m_Arrow = new ArrowModelClass;
	if (!m_Arrow)
	{
		MessageBox(hwnd, L"Could not create the model object.", L"Error", MB_OK);
		return false;
	}

	// Initialize the model object.
	result = m_Arrow->Initialize(m_D3D->GetDevice());
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	// Create the color shader object.
	m_TrivialShader = new TrivialShaderClass;
	if (!m_TrivialShader)
	{
		MessageBox(hwnd, L"Could not create the color shader object.", L"Error", MB_OK);
		return false;
	}

	// Initialize the color shader object.
	result = m_TrivialShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the color shader object.", L"Error", MB_OK);
		return false;
	}

	return true;
}


void GraphicsClass::Shutdown()
{
	// Release the color shader object.
	if (m_TrivialShader)
	{
		m_TrivialShader->Shutdown();
		delete m_TrivialShader;
		m_TrivialShader = 0;
	}

	// Release the model object.
	if (m_Arrow)
	{
		m_Arrow->Shutdown();
		delete m_Arrow;
		m_Arrow = 0;
	}

	// Release the camera object.
	if (m_Transform)
	{
		delete m_Transform;
		m_Transform = 0;
	}

	// Release the D3D object.
	if (m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}

	return;
}

bool GraphicsClass::Frame()
{
	if (!Render())
	{
		return false;
	}
	else
		return true;
}


bool GraphicsClass::Render()
{
	bool result;

	D3DXMATRIX viewMatrix, projectionMatrix, worldMatrix;

	// Clear the buffers to begin the scene.
	m_D3D->BeginScene();

	// Generate the view matrix based on the camera's position.
	m_Transform->Render();
	// Get the world, view, and projection matrices from the camera and d3d objects.
	viewMatrix = m_Transform->GetViewMatrix();
	projectionMatrix = m_Transform->GetProjectionMatrix();

	// Get the world matrix of the triangle.
	worldMatrix = m_Arrow->GetModelWorldMatrix();
	// Update parameters of the trivial shader.
	result = m_TrivialShader->Render(m_D3D->GetDeviceContext(), worldMatrix, viewMatrix, projectionMatrix);
	if (!result)
	{
		return false;
	}
	// Put the model vertex and index buffers on the graphics pipeline and draw primitives.
	m_Arrow->Render(m_D3D->GetDeviceContext());

	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}