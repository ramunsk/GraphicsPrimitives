#include "ArrowModelClass.h"
#include <vector>

ArrowModelClass::ArrowModelClass() :IndexModelClass()
{
}

ArrowModelClass::~ArrowModelClass()
{
}

bool ArrowModelClass::InitializeBuffers(ID3D11Device* device)
{
	HRESULT result;

	///
	/// VERTICES
	///
	D3DXVECTOR4 COLOR_WHITE =      { 1.00f, 1.00f, 1.00f, 1.0f };
	D3DXVECTOR4 COLOR_LIGHT_GRAY = { 0.60f, 0.60f, 0.60f, 1.0f };
	D3DXVECTOR4 COLOR_BLUE =       { 0.15f, 0.02f, 0.94f, 1.0f };
	

	std::vector<VertexType> vertices = {
		// Antgalis
		{ -378.0f,   0.0f, 378.0f, COLOR_WHITE },       // 0
		{ -343.0f, -15.0f, 343.0f, COLOR_LIGHT_GRAY },	// 1
		{ -342.0f,  -2.0f, 344.0f, COLOR_LIGHT_GRAY },	// 2
		{ -332.0f,  -0.0f, 354.0f, COLOR_LIGHT_GRAY },	// 3
		{ -341.0f,   2.0f, 344.0f, COLOR_LIGHT_GRAY },	// 4
		{ -343.0f,  15.0f, 343.0f, COLOR_LIGHT_GRAY },	// 5
		{ -344.0f,   2.0f, 342.0f, COLOR_LIGHT_GRAY },	// 6
		{ -354.0f,   0.0f, 332.0f, COLOR_LIGHT_GRAY },	// 7
		{ -344.0f,  -2.0f, 341.0f, COLOR_LIGHT_GRAY },	// 8
		// Laikiklis
		{ -343.0f, -6.0f, 343.0f, COLOR_BLUE }, // 9
		{ -329.0f, -6.0f, 329.0f, COLOR_BLUE },	// 10
		{ -340.0f, -4.0f, 346.0f, COLOR_BLUE },	// 11
		{ -326.0f, -4.0f, 332.0f, COLOR_BLUE },	// 12
		{ -339.0f,  0.0f, 347.0f, COLOR_BLUE },	// 13
		{ -325.0f,  0.0f, 333.0f, COLOR_BLUE },	// 14
		{ -340.0f,  4.0f, 346.0f, COLOR_BLUE },	// 15
		{ -326.0f,  4.0f, 332.0f, COLOR_BLUE },	// 16
		{ -343.0f,  6.0f, 343.0f, COLOR_BLUE },	// 17
		{ -329.0f,  6.0f, 329.0f, COLOR_BLUE },	// 18
		{ -346.0f,  4.0f, 340.0f, COLOR_BLUE },	// 19
		{ -332.0f,  4.0f, 326.0f, COLOR_BLUE },	// 20
		{ -347.0f,  0.0f, 339.0f, COLOR_BLUE },	// 21
		{ -333.0f,  0.0f, 325.0f, COLOR_BLUE },	// 22
		{ -346.0f, -4.0f, 340.0f, COLOR_BLUE },	// 23
		{ -332.0f, -4.0f, 326.0f, COLOR_BLUE },	// 24






	};

	int vertexCount = vertices.size();
	SetVertexCount(vertexCount);

	D3D11_BUFFER_DESC vertexBufferDesc;
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA vertexData;
	ZeroMemory(&vertexData, sizeof(vertexData));
	vertexData.pSysMem = &vertices[0];
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	///
	/// INDICES
	///
	std::vector<unsigned long> indices = {
		// Antaglis
		0, 1, 2,
		0, 2, 3,
		0, 3, 4,
		0, 4, 5,
		0, 5, 6,
		0, 6, 7, 
		0, 7, 8,
		0, 8, 1,
		1, 8, 2,
		3, 2, 4,
		5, 4, 6,
		7, 6, 8,
		4, 8, 6,
		4, 2, 8,
		// Laikiklis
		 9, 10, 11,
		11, 10, 12,
		11, 12, 13,
		13, 12, 14,
		13, 14, 15,
		15, 14, 16,
		15, 16, 17,
		17, 16, 18,
		17, 18, 19,
		19, 18, 20,
		19, 20, 21,
		21, 20, 22,
		21, 22, 23,
		23, 22, 24,
		23, 24,  9,
		 9, 24, 10,
		 9, 11, 13, //
		13, 15, 17,
		17, 19, 21,
		21, 23,  9,
		 9, 13, 17,
		 9, 17, 21,
		10, 14, 12,
		14, 18, 16,
		18, 22, 20,
		22, 10, 24,
		10, 22, 18,
		10, 18, 14,

		



	};

	int indexCount = indices.size();
	SetIndexCount(indexCount);

	D3D11_BUFFER_DESC indexBufferDesc;
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA indexData;
	indexData.pSysMem = &indices[0];
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	return true;
}

void ArrowModelClass::RenderBuffers(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;

	// Set vertex buffer stride and offset.
	stride = sizeof(VertexType);
	offset = 0;

	// Set the vertex buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

	// Set the index buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// render primitives
	deviceContext->DrawIndexed(GetIndexCount(), 0, 0);

	return;
}

void ArrowModelClass::Render(ID3D11DeviceContext* deviceContext)
{
	//Update the world transformations
	UINT  iTime = timeGetTime() % 8000;
	float fAngle = iTime * 2 * D3DX_PI / 8000.0f;
	D3DXMATRIX rotMatrix;
	//D3DXMatrixRotationY(&rotMatrix, fAngle);
	D3DXMatrixRotationY(&rotMatrix, fAngle);
	//D3DXMatrixRotationAxis(&rotMatrix, 1.0f, 1.0f,1.0f, fAngle );
	SetModelWorldMatrix(rotMatrix);
	//SetModelWorldMatrix(XMMatrixIdentity());

	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(deviceContext);

	return;
}